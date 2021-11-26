import sqlite3
from text2ipa import get_IPAs
from .constant import INSERT_IPA, CREATE_TABLE, WORD_IN_ENGLISH_4IPA
from typing import Any

# Copyright Library https://github.com/ssut/py-googletrans
# from googletrans import Translator


class TypeError(Exception):
    ...


def mergeList(l1, l2):
    return list(map(lambda x, y: (x, y), l1, l2))


# ------------------- Class ----------------------
# Name: _Data_
# Input: (filename)
# Type: Pravite Class
# Methods:
# - `init_database()` : Initialize database
# - `_update(CMD,Data)` : CMD is SQL Query statement and Data is List or Tuple type
# - `update_ipa()` : Auto update English IPA in Database
# - `close()` : Close the database file
# -------------------------------------------------


class _Data_:
    """Class manage all actions as insert, update, and delete DATABASE"""

    def __init__(self, db: str) -> None:
        self.conn = self.__connect_database(db)
        self.cur = self.conn.cursor()

    # Function regard to Access Database
    def __connect_database(self, db):
        """Connect to database, intialization"""
        __conn = sqlite3.Connection(db)
        return __conn

    def init_database(self):
        """Create all necessary tables in Database"""
        self.cur.executescript(CREATE_TABLE)
        self.conn.commit()

    # Helping update database with CMD and List Records or Record
    def _update(self, cmd, data: Any):
        # Most implementation is bytes (char*) must be convert to str
        # Handle datatype input
        if isinstance(data, tuple):
            self.cur.execute(cmd, data)
        elif isinstance(data, list):
            for record in data:
                self.cur.execute(cmd, record)
            self.conn.commit()
        else:
            raise TypeError("Data type must be RECORD or the list of RECORDs")

    def update_ipa(self):
        """Update IPA auto"""
        # Get all English words with records
        # (WordID, Word, Language)
        self.cur.execute(WORD_IN_ENGLISH_4IPA)
        records = self.cur.fetchall()
        ipas = []
        ids = []
        for record in records:
            ids.append(record[0])
            ipas.append(record[1])
        ipa = get_IPAs(ipas, records[0][2])
        retL = mergeList(ipa, ids)
        self._update(INSERT_IPA, retL)

    def close(self):
        """1. Commit change
        2. Close the cursor
        3. Close the connection"""
        self.conn.commit()
        self.cur.close()
        self.conn.close()