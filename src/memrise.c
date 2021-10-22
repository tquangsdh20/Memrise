/*Cython Language*/
#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif /* PY_SSIZE_T_CLEAN */
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_24"
#define CYTHON_HEX_VERSION 0x001D18F0
#define CYTHON_FUTURE_DIVISION 0
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #include "longintrepr.h"
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#if PY_VERSION_HEX >= 0x030800A4 && PY_VERSION_HEX < 0x030800B2
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, 0, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #if defined(PyUnicode_IS_READY)
  #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                              0 : _PyUnicode_Ready((PyObject *)(op)))
  #else
  #define __Pyx_PyUnicode_READY(op)       (0)
  #endif
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #if defined(PyUnicode_IS_READY) && defined(PyUnicode_GET_SIZE)
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03090000
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : ((PyCompactUnicodeObject *)(u))->wstr_length))
  #else
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
  #endif
  #else
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_LENGTH(u))
  #endif
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   PyInt_AsLong
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   PyInt_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? ((void)(klass), PyMethod_New(func, self)) : __Pyx_NewRef(func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index, lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__memrise
#define __PYX_HAVE_API__memrise
/* Early includes */
#ifdef _OPENMP
#include <omp.h>
#endif /* _OPENMP */

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif


/* Test for GCC > 2.95 */
#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else /* !__GNUC__ or GCC < 2.95 */
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif /* __GNUC__ */
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "src\\memrise.pyx",
  "stringsource",
};

/*--- Type declarations ---*/
struct __pyx_obj_7memrise_Level;
struct __pyx_obj_7memrise_Course;
struct __pyx_obj_7memrise_Data;

/* "memrise.pxd":5
 * cdef object get_words(object soup,int course_id, int level_id)
 * 
 * cdef class Level:             # <<<<<<<<<<<<<<
 *     cdef int course_id
 *     cdef int level_id
 */
struct __pyx_obj_7memrise_Level {
  PyObject_HEAD
  int course_id;
  int level_id;
  PyObject *__pyx___words;
  char *__pyx___name;
  char *__pyx___page;
  PyObject *__pyx___soup;
  PyObject *__pyx___record;
};


/* "memrise.pxd":14
 *     cdef object __record
 * 
 * cdef class Course:             # <<<<<<<<<<<<<<
 *     cdef int course_id
 *     cdef list __levels
 */
struct __pyx_obj_7memrise_Course {
  PyObject_HEAD
  int course_id;
  PyObject *__pyx___levels;
  char *__pyx___name;
  char *__pyx___page;
  PyObject *__pyx___soup;
  PyObject *__pyx___record;
};


/* "memrise.pxd":22
 *     cdef object __record
 * 
 * cdef class Data:             # <<<<<<<<<<<<<<
 *     cdef object conn
 *     cdef object cur
 */
struct __pyx_obj_7memrise_Data {
  PyObject_HEAD
  PyObject *conn;
  PyObject *cur;
};


/* --- Runtime support code (head) --- */
/* Refnanny.proto */
#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)

/* PyObjectGetAttrStr.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif

/* GetBuiltinName.proto */
static PyObject *__Pyx_GetBuiltinName(PyObject *name);

/* PyDictVersioning.proto */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif

/* GetModuleGlobalName.proto */
#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
#define __Pyx_GetModuleGlobalNameUncached(var, name)  {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif

/* PyCFunctionFastCall.proto */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif

/* PyFunctionFastCall.proto */
#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif

/* PyObjectCall.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif

/* PyObjectCall2Args.proto */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);

/* PyObjectCallMethO.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif

/* PyObjectCallOneArg.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);

/* PyObjectCallNoArg.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif

/* PyThreadStateGet.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif

/* PyErrFetchRestore.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif

/* WriteUnraisableException.proto */
static void __Pyx_WriteUnraisable(const char *name, int clineno,
                                  int lineno, const char *filename,
                                  int full_traceback, int nogil);

/* PySequenceContains.proto */
static CYTHON_INLINE int __Pyx_PySequence_ContainsTF(PyObject* item, PyObject* seq, int eq) {
    int result = PySequence_Contains(seq, item);
    return unlikely(result < 0) ? result : (result == (eq == Py_EQ));
}

/* ListAppend.proto */
#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_PyList_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len) & likely(len > (L->allocated >> 1))) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_PyList_Append(L,x) PyList_Append(L,x)
#endif

/* PyObjectGetMethod.proto */
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);

/* PyObjectCallMethod1.proto */
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);

/* append.proto */
static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x);

/* GetItemInt.proto */
#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);

/* RaiseArgTupleInvalid.proto */
static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);

/* RaiseDoubleKeywords.proto */
static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);

/* ParseKeywords.proto */
static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);

/* IncludeStringH.proto */
#include <string.h>

/* decode_c_string_utf16.proto */
static CYTHON_INLINE PyObject *__Pyx_PyUnicode_DecodeUTF16(const char *s, Py_ssize_t size, const char *errors) {
    int byteorder = 0;
    return PyUnicode_DecodeUTF16(s, size, errors, &byteorder);
}
static CYTHON_INLINE PyObject *__Pyx_PyUnicode_DecodeUTF16LE(const char *s, Py_ssize_t size, const char *errors) {
    int byteorder = -1;
    return PyUnicode_DecodeUTF16(s, size, errors, &byteorder);
}
static CYTHON_INLINE PyObject *__Pyx_PyUnicode_DecodeUTF16BE(const char *s, Py_ssize_t size, const char *errors) {
    int byteorder = 1;
    return PyUnicode_DecodeUTF16(s, size, errors, &byteorder);
}

/* decode_c_string.proto */
static CYTHON_INLINE PyObject* __Pyx_decode_c_string(
         const char* cstring, Py_ssize_t start, Py_ssize_t stop,
         const char* encoding, const char* errors,
         PyObject* (*decode_func)(const char *s, Py_ssize_t size, const char *errors));

/* RaiseException.proto */
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause);

/* PyIntBinop.proto */
#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_AddObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceAdd(op1, op2) : PyNumber_Add(op1, op2))
#endif

/* ArgTypeTest.proto */
#define __Pyx_ArgTypeTest(obj, type, none_allowed, name, exact)\
    ((likely((Py_TYPE(obj) == type) | (none_allowed && (obj == Py_None)))) ? 1 :\
        __Pyx__ArgTypeTest(obj, type, name, exact))
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact);

/* Import.proto */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);

/* ImportFrom.proto */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name);

/* GetTopmostException.proto */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif

/* SaveResetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif

/* GetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif

/* SwapException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSwap(type, value, tb)  __Pyx__ExceptionSwap(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb);
#endif

/* PyErrExceptionMatches.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_ExceptionMatches(err) __Pyx_PyErr_ExceptionMatchesInState(__pyx_tstate, err)
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err);
#else
#define __Pyx_PyErr_ExceptionMatches(err)  PyErr_ExceptionMatches(err)
#endif

/* GetAttr.proto */
static CYTHON_INLINE PyObject *__Pyx_GetAttr(PyObject *, PyObject *);

/* GetAttr3.proto */
static CYTHON_INLINE PyObject *__Pyx_GetAttr3(PyObject *, PyObject *, PyObject *);

/* HasAttr.proto */
static CYTHON_INLINE int __Pyx_HasAttr(PyObject *, PyObject *);

/* PyObject_GenericGetAttrNoDict.proto */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GenericGetAttrNoDict PyObject_GenericGetAttr
#endif

/* PyObject_GenericGetAttr.proto */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject* __Pyx_PyObject_GenericGetAttr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GenericGetAttr PyObject_GenericGetAttr
#endif

/* PyObjectGetAttrStrNoError.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStrNoError(PyObject* obj, PyObject* attr_name);

/* SetupReduce.proto */
static int __Pyx_setup_reduce(PyObject* type_obj);

/* CLineInTraceback.proto */
#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif

/* CodeObjectCache.proto */
typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);

/* AddTraceback.proto */
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);

/* GCCDiagnostics.proto */
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define __Pyx_HAS_GCC_DIAGNOSTIC
#endif

/* Print.proto */
static int __Pyx_Print(PyObject*, PyObject *, int);
#if CYTHON_COMPILING_IN_PYPY || PY_MAJOR_VERSION >= 3
static PyObject* __pyx_print = 0;
static PyObject* __pyx_print_kwargs = 0;
#endif

/* CIntFromPy.proto */
static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);

/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_int(int value);

/* CIntFromPy.proto */
static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);

/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);

/* PrintOne.proto */
static int __Pyx_PrintOne(PyObject* stream, PyObject *o);

/* FastTypeChecks.proto */
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)

/* CheckBinaryVersion.proto */
static int __Pyx_check_binary_version(void);

/* FunctionExport.proto */
static int __Pyx_ExportFunction(const char *name, void (*f)(void), const char *sig);

/* InitStrings.proto */
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);


/* Module declarations from 'memrise' */
static PyTypeObject *__pyx_ptype_7memrise_Level = 0;
static PyTypeObject *__pyx_ptype_7memrise_Course = 0;
static PyTypeObject *__pyx_ptype_7memrise_Data = 0;
static char const *__pyx_v_7memrise_PAGE;
static PyObject *__pyx_v_7memrise_CREATE_TABLE = 0;
static char const *__pyx_v_7memrise_INSERT_COURSE;
static char const *__pyx_v_7memrise_INSERT_LEVEL;
static char const *__pyx_v_7memrise_INSERT_WORD;
static PyObject *__pyx_f_7memrise_open_soup(char *); /*proto*/
static char *__pyx_f_7memrise_get_name(char *, PyObject *); /*proto*/
static PyObject *__pyx_f_7memrise_get_words(PyObject *, int, int); /*proto*/
static PyObject *__pyx_f_7memrise___pyx_unpickle_Data__set_state(struct __pyx_obj_7memrise_Data *, PyObject *); /*proto*/
#define __Pyx_MODULE_NAME "memrise"
extern int __pyx_module_is_main_memrise;
int __pyx_module_is_main_memrise = 0;

/* Implementation of 'memrise' */
static PyObject *__pyx_builtin_range;
static PyObject *__pyx_builtin_TypeError;
static const char __pyx_k_a[] = "a";
static const char __pyx_k_d[] = "/(\\d)+/$";
static const char __pyx_k_db[] = "db";
static const char __pyx_k_re[] = "re";
static const char __pyx_k_Any[] = "Any";
static const char __pyx_k_bs4[] = "bs4";
static const char __pyx_k_cmd[] = "cmd";
static const char __pyx_k_div[] = "div";
static const char __pyx_k_end[] = "end";
static const char __pyx_k_get[] = "get";
static const char __pyx_k_new[] = "__new__";
static const char __pyx_k_sys[] = "sys";
static const char __pyx_k_Data[] = "Data";
static const char __pyx_k_data[] = "data";
static const char __pyx_k_dict[] = "__dict__";
static const char __pyx_k_exit[] = "exit";
static const char __pyx_k_file[] = "file";
static const char __pyx_k_find[] = "find";
static const char __pyx_k_href[] = "href";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_path[] = "path";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_text[] = "text";
static const char __pyx_k_Level[] = "Level";
static const char __pyx_k_class[] = "class";
static const char __pyx_k_close[] = "close";
static const char __pyx_k_col_a[] = "col_a";
static const char __pyx_k_col_b[] = "col_b";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_strip[] = "strip";
static const char __pyx_k_Course[] = "Course";
static const char __pyx_k_append[] = "append";
static const char __pyx_k_commit[] = "commit";
static const char __pyx_k_course[] = "/course/";
static const char __pyx_k_cursor[] = "cursor";
static const char __pyx_k_decode[] = "decode";
static const char __pyx_k_encode[] = "encode";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_pickle[] = "pickle";
static const char __pyx_k_reduce[] = "__reduce__";
static const char __pyx_k_search[] = "search";
static const char __pyx_k_typing[] = "typing";
static const char __pyx_k_update[] = "__update";
static const char __pyx_k_LevelID[] = "LevelID";
static const char __pyx_k_execute[] = "execute";
static const char __pyx_k_memrise[] = "memrise";
static const char __pyx_k_speaker[] = "speaker";
static const char __pyx_k_sqlite3[] = "sqlite3";
static const char __pyx_k_CourseID[] = "CourseID";
static const char __pyx_k_getstate[] = "__getstate__";
static const char __pyx_k_pyx_type[] = "__pyx_type";
static const char __pyx_k_requests[] = "requests";
static const char __pyx_k_setstate[] = "__setstate__";
static const char __pyx_k_update_2[] = "update";
static const char __pyx_k_TypeError[] = "TypeError";
static const char __pyx_k_course_id[] = "course_id";
static const char __pyx_k_get_words[] = "get_words";
static const char __pyx_k_pyx_state[] = "__pyx_state";
static const char __pyx_k_reduce_ex[] = "__reduce_ex__";
static const char __pyx_k_Connection[] = "Connection";
static const char __pyx_k_get_levels[] = "__get_levels";
static const char __pyx_k_get_record[] = "get_record";
static const char __pyx_k_pyx_result[] = "__pyx_result";
static const char __pyx_k_PickleError[] = "PickleError";
static const char __pyx_k_html_parser[] = "html.parser";
static const char __pyx_k_language_id[] = "language_id";
static const char __pyx_k_get_levels_2[] = "get_levels";
static const char __pyx_k_pyx_checksum[] = "__pyx_checksum";
static const char __pyx_k_stringsource[] = "stringsource";
static const char __pyx_k_update_level[] = "update_level";
static const char __pyx_k_BeautifulSoup[] = "BeautifulSoup";
static const char __pyx_k_reduce_cython[] = "__reduce_cython__";
static const char __pyx_k_pyx_PickleError[] = "__pyx_PickleError";
static const char __pyx_k_setstate_cython[] = "__setstate_cython__";
static const char __pyx_k_connect_database[] = "__connect_database";
static const char __pyx_k_pyx_unpickle_Data[] = "__pyx_unpickle_Data";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_DROP_TABLE_IF_EXISTS_words[] = "DROP TABLE IF EXISTS words ;";
static const char __pyx_k_DROP_TABLE_IF_EXISTS_levels[] = "DROP TABLE IF EXISTS levels ;";
static const char __pyx_k_DROP_TABLE_IF_EXISTS_courses[] = "DROP TABLE IF EXISTS courses ;";
static const char __pyx_k_DROP_TABLE_IF_EXISTS_languages[] = "DROP TABLE IF EXISTS languages ;";
static const char __pyx_k_CREATE_TABLE_courses_id_INTEGER[] = "CREATE TABLE courses (\n\t\"id\"\tINTEGER NOT NULL UNIQUE,\n\t\"name\"  TEXT NOT NULL,\n\t\"language_id\" INTEGER NOT NULL,\n\tPRIMARY KEY(\"id\")\n\tFOREIGN KEY(\"language_id\") REFERENCES \"languages\"(\"id\")\n);";
static const char __pyx_k_CREATE_TABLE_languages_id_INTEGE[] = "CREATE TABLE languages(\n\t\"id\"\tINTEGER NOT NULL UNIQUE,\n\t\"name\"\tTEXT NOT NULL UNIQUE,\n\tPRIMARY KEY(\"id\" AUTOINCREMENT) )\n\t";
static const char __pyx_k_CREATE_TABLE_levels_course_id_IN[] = "CREATE TABLE \"levels\" (\n\t\"course_id\"\tINTEGER NOT NULL,\n\t\"id\"\tINTEGER NOT NULL,\n\t\"name\"\tTEXT NOT NULL,\n\tFOREIGN KEY(\"course_id\") REFERENCES \"courses\"(\"id\"),\n\tPRIMARY KEY(\"course_id\",\"id\")\n);";
static const char __pyx_k_CREATE_TABLE_words_id_INTEGER_NO[] = "CREATE TABLE \"words\" (\n\t\"id\"\tINTEGER NOT NULL,\n\t\"word\"\tTEXT NOT NULL,\n\t\"meaning\"\tTEXT DEFAULT NULL,\n\t\"IPA\"\tTEXT DEFAULT NULL,\n\t\"sub\"\tTEXT DEFAULT NULL,\n\t\"audio\"\tTEXT DEFAULT '{}',\n\t\"course_id\"\tINTEGER,\n\t\"level_id\"\tINTEGER,\n\tPRIMARY KEY(\"id\" AUTOINCREMENT),\n\tFOREIGN KEY(\"course_id\", \"level_id\") REFERENCES \"levels\"(\"course_id\", \"id\")\n);";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (0,'Unknown');";
static const char __pyx_k_Incompatible_checksums_s_vs_0x3b[] = "Incompatible checksums (%s vs 0x3b5338f = (conn, cur))";
static const char __pyx_k_RecordError_Fail_to_update_recor[] = "RecordError: Fail to update record";
static const char __pyx_k_This_function_will_be_implemente[] = "This function will be implemented in next release.";
static const char __pyx_k_TypeError_Data_type_must_be_RECO[] = "TypeError: Data type must be RECORD or the list of RECORDs";
static const char __pyx_k_no_default___reduce___due_to_non[] = "no default __reduce__ due to non-trivial __cinit__";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_2[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (1,'English UK');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_3[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (2,'English US');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_4[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (3,'Chinese');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_5[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (4,'Janpanese');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_6[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (5,'French');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_7[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (6,'Spanish Mexico');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_8[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (7,'Italian');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_9[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (8,'German');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_10[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (9,'Russian');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_11[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (10,'Dutch');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_12[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (11,'Korean');";
static const char __pyx_k_INSERT_INTO_languages_id_name_VA_13[] = "INSERT INTO \"languages\" (\"id\",\"name\") VALUES (12,'Arabic');";
static PyObject *__pyx_n_s_Any;
static PyObject *__pyx_n_s_BeautifulSoup;
static PyObject *__pyx_kp_s_CREATE_TABLE_courses_id_INTEGER;
static PyObject *__pyx_kp_s_CREATE_TABLE_languages_id_INTEGE;
static PyObject *__pyx_kp_s_CREATE_TABLE_levels_course_id_IN;
static PyObject *__pyx_kp_s_CREATE_TABLE_words_id_INTEGER_NO;
static PyObject *__pyx_n_s_Connection;
static PyObject *__pyx_n_s_Course;
static PyObject *__pyx_n_s_CourseID;
static PyObject *__pyx_kp_s_DROP_TABLE_IF_EXISTS_courses;
static PyObject *__pyx_kp_s_DROP_TABLE_IF_EXISTS_languages;
static PyObject *__pyx_kp_s_DROP_TABLE_IF_EXISTS_levels;
static PyObject *__pyx_kp_s_DROP_TABLE_IF_EXISTS_words;
static PyObject *__pyx_n_s_Data;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_10;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_11;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_12;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_13;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_2;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_3;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_4;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_5;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_6;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_7;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_8;
static PyObject *__pyx_kp_s_INSERT_INTO_languages_id_name_VA_9;
static PyObject *__pyx_kp_s_Incompatible_checksums_s_vs_0x3b;
static PyObject *__pyx_n_s_Level;
static PyObject *__pyx_n_s_LevelID;
static PyObject *__pyx_n_s_PickleError;
static PyObject *__pyx_kp_s_RecordError_Fail_to_update_recor;
static PyObject *__pyx_kp_s_This_function_will_be_implemente;
static PyObject *__pyx_n_s_TypeError;
static PyObject *__pyx_kp_s_TypeError_Data_type_must_be_RECO;
static PyObject *__pyx_n_s_a;
static PyObject *__pyx_n_s_append;
static PyObject *__pyx_n_s_bs4;
static PyObject *__pyx_n_s_class;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_close;
static PyObject *__pyx_n_s_cmd;
static PyObject *__pyx_n_s_col_a;
static PyObject *__pyx_n_s_col_b;
static PyObject *__pyx_n_s_commit;
static PyObject *__pyx_n_s_connect_database;
static PyObject *__pyx_kp_b_course;
static PyObject *__pyx_n_s_course_id;
static PyObject *__pyx_n_s_cursor;
static PyObject *__pyx_kp_s_d;
static PyObject *__pyx_n_s_data;
static PyObject *__pyx_n_s_db;
static PyObject *__pyx_n_s_decode;
static PyObject *__pyx_n_s_dict;
static PyObject *__pyx_n_s_div;
static PyObject *__pyx_n_s_encode;
static PyObject *__pyx_n_s_end;
static PyObject *__pyx_n_s_execute;
static PyObject *__pyx_n_s_exit;
static PyObject *__pyx_n_s_file;
static PyObject *__pyx_n_s_find;
static PyObject *__pyx_n_s_get;
static PyObject *__pyx_n_s_get_levels;
static PyObject *__pyx_n_s_get_levels_2;
static PyObject *__pyx_n_s_get_record;
static PyObject *__pyx_n_s_get_words;
static PyObject *__pyx_n_s_getstate;
static PyObject *__pyx_n_s_href;
static PyObject *__pyx_kp_s_html_parser;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_language_id;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_s_memrise;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_new;
static PyObject *__pyx_kp_s_no_default___reduce___due_to_non;
static PyObject *__pyx_n_s_path;
static PyObject *__pyx_n_s_pickle;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_n_s_pyx_PickleError;
static PyObject *__pyx_n_s_pyx_checksum;
static PyObject *__pyx_n_s_pyx_result;
static PyObject *__pyx_n_s_pyx_state;
static PyObject *__pyx_n_s_pyx_type;
static PyObject *__pyx_n_s_pyx_unpickle_Data;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_re;
static PyObject *__pyx_n_s_reduce;
static PyObject *__pyx_n_s_reduce_cython;
static PyObject *__pyx_n_s_reduce_ex;
static PyObject *__pyx_n_s_requests;
static PyObject *__pyx_n_s_search;
static PyObject *__pyx_n_s_setstate;
static PyObject *__pyx_n_s_setstate_cython;
static PyObject *__pyx_n_s_speaker;
static PyObject *__pyx_n_s_sqlite3;
static PyObject *__pyx_kp_s_stringsource;
static PyObject *__pyx_n_s_strip;
static PyObject *__pyx_n_s_sys;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_text;
static PyObject *__pyx_n_s_typing;
static PyObject *__pyx_n_s_update;
static PyObject *__pyx_n_s_update_2;
static PyObject *__pyx_n_s_update_level;
static int __pyx_pf_7memrise_5Level___cinit__(struct __pyx_obj_7memrise_Level *__pyx_v_self, PyObject *__pyx_v_path, PyObject *__pyx_v_LevelID, PyObject *__pyx_v_CourseID); /* proto */
static PyObject *__pyx_pf_7memrise_5Level_2get_words(struct __pyx_obj_7memrise_Level *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_5Level_4get_record(struct __pyx_obj_7memrise_Level *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_5Level_6__reduce_cython__(CYTHON_UNUSED struct __pyx_obj_7memrise_Level *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_5Level_8__setstate_cython__(CYTHON_UNUSED struct __pyx_obj_7memrise_Level *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v___pyx_state); /* proto */
static int __pyx_pf_7memrise_6Course___cinit__(struct __pyx_obj_7memrise_Course *__pyx_v_self, PyObject *__pyx_v_course_id, PyObject *__pyx_v_language_id); /* proto */
static PyObject *__pyx_pf_7memrise_6Course_2get_levels(struct __pyx_obj_7memrise_Course *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_6Course_4__get_levels(struct __pyx_obj_7memrise_Course *__pyx_v_self, PyObject *__pyx_v_soup); /* proto */
static PyObject *__pyx_pf_7memrise_6Course_6get_record(struct __pyx_obj_7memrise_Course *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_6Course_8__reduce_cython__(CYTHON_UNUSED struct __pyx_obj_7memrise_Course *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_6Course_10__setstate_cython__(CYTHON_UNUSED struct __pyx_obj_7memrise_Course *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v___pyx_state); /* proto */
static int __pyx_pf_7memrise_4Data___init__(struct __pyx_obj_7memrise_Data *__pyx_v_self, PyObject *__pyx_v_db); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_2__connect_database(CYTHON_UNUSED struct __pyx_obj_7memrise_Data *__pyx_v_self, PyObject *__pyx_v_db); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_4init_database(struct __pyx_obj_7memrise_Data *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_6__update(struct __pyx_obj_7memrise_Data *__pyx_v_self, PyObject *__pyx_v_cmd, PyObject *__pyx_v_data); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_8update_level(struct __pyx_obj_7memrise_Data *__pyx_v_self, struct __pyx_obj_7memrise_Level *__pyx_v_level); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_10update_course(struct __pyx_obj_7memrise_Data *__pyx_v_self, struct __pyx_obj_7memrise_Course *__pyx_v_course); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_12update_db(CYTHON_UNUSED struct __pyx_obj_7memrise_Data *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_speaker); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_14update_db_en(CYTHON_UNUSED struct __pyx_obj_7memrise_Data *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_course_id, CYTHON_UNUSED PyObject *__pyx_v_speaker); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_16close(struct __pyx_obj_7memrise_Data *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_18__reduce_cython__(struct __pyx_obj_7memrise_Data *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_7memrise_4Data_20__setstate_cython__(struct __pyx_obj_7memrise_Data *__pyx_v_self, PyObject *__pyx_v___pyx_state); /* proto */
static PyObject *__pyx_pf_7memrise___pyx_unpickle_Data(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v___pyx_type, long __pyx_v___pyx_checksum, PyObject *__pyx_v___pyx_state); /* proto */
static PyObject *__pyx_tp_new_7memrise_Level(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_7memrise_Course(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_7memrise_Data(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_62206863;
static PyObject *__pyx_tuple_;
static PyObject *__pyx_tuple__2;
static PyObject *__pyx_tuple__3;
static PyObject *__pyx_tuple__4;
static PyObject *__pyx_tuple__5;
static PyObject *__pyx_tuple__6;
static PyObject *__pyx_codeobj__7;
/* Late includes */

/* "memrise.pyx":74
 * 
 * #******* Function Define ********
 * cdef object open_soup(char* url):             # <<<<<<<<<<<<<<
 *     html = requests.get(url)
 *     soup = BeautifulSoup(html.text,'html.parser')
 */

static PyObject *__pyx_f_7memrise_open_soup(char *__pyx_v_url) {
  PyObject *__pyx_v_html = NULL;
  PyObject *__pyx_v_soup = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("open_soup", 0);

  /* "memrise.pyx":75
 * #******* Function Define ********
 * cdef object open_soup(char* url):
 *     html = requests.get(url)             # <<<<<<<<<<<<<<
 *     soup = BeautifulSoup(html.text,'html.parser')
 *     return soup
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_requests); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_get); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyBytes_FromString(__pyx_v_url); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_4, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_html = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":76
 * cdef object open_soup(char* url):
 *     html = requests.get(url)
 *     soup = BeautifulSoup(html.text,'html.parser')             # <<<<<<<<<<<<<<
 *     return soup
 * 
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BeautifulSoup); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_html, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = NULL;
  __pyx_t_5 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
      __pyx_t_5 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_2, __pyx_kp_s_html_parser};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 76, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_2, __pyx_kp_s_html_parser};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 76, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  {
    __pyx_t_6 = PyTuple_New(2+__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 76, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    if (__pyx_t_4) {
      __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_4); __pyx_t_4 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_5, __pyx_t_2);
    __Pyx_INCREF(__pyx_kp_s_html_parser);
    __Pyx_GIVEREF(__pyx_kp_s_html_parser);
    PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_5, __pyx_kp_s_html_parser);
    __pyx_t_2 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_6, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 76, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_soup = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":77
 *     html = requests.get(url)
 *     soup = BeautifulSoup(html.text,'html.parser')
 *     return soup             # <<<<<<<<<<<<<<
 * 
 * cdef char* get_name(char* tag_chr, object soup):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_soup);
  __pyx_r = __pyx_v_soup;
  goto __pyx_L0;

  /* "memrise.pyx":74
 * 
 * #******* Function Define ********
 * cdef object open_soup(char* url):             # <<<<<<<<<<<<<<
 *     html = requests.get(url)
 *     soup = BeautifulSoup(html.text,'html.parser')
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("memrise.open_soup", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_html);
  __Pyx_XDECREF(__pyx_v_soup);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}


static char *__pyx_f_7memrise_get_name(char *__pyx_v_tag_chr, PyObject *__pyx_v_soup) {
  PyObject *__pyx_v_tag = NULL;
  PyObject *__pyx_v_name = NULL;
  char *__pyx_r;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  char *__pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("get_name", 0);


  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_soup, __pyx_n_s_find); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyBytes_FromString(__pyx_v_tag_chr); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_tag = __pyx_t_1;
  __pyx_t_1 = 0;


  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_tag, __pyx_n_s_text); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_strip); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_encode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_name = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":83
 *     #Must be encoded cause tag.text -> return str (UNICODE Python 3)
 *     name = tag.text.strip().encode()
 *     return name             # <<<<<<<<<<<<<<
 * 
 * cdef object get_words(object soup,int course_id, int level_id):
 */
  __pyx_t_5 = __Pyx_PyObject_AsWritableString(__pyx_v_name); if (unlikely((!__pyx_t_5) && PyErr_Occurred())) __PYX_ERR(0, 83, __pyx_L1_error)
  __pyx_r = __pyx_t_5;
  goto __pyx_L0;


  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_WriteUnraisable("memrise.get_name", __pyx_clineno, __pyx_lineno, __pyx_filename, 1, 0);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_tag);
  __Pyx_XDECREF(__pyx_v_name);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_f_7memrise_get_words(PyObject *__pyx_v_soup, int __pyx_v_course_id, int __pyx_v_level_id) {
  int __pyx_v_i;
  int __pyx_v_count;
  PyObject *__pyx_v_words = 0;
  PyObject *__pyx_v_records = 0;
  PyObject *__pyx_v_tags = 0;
  PyObject *__pyx_v_record = 0;
  PyObject *__pyx_v_meanings = NULL;
  PyObject *__pyx_v_tag = NULL;
  PyObject *__pyx_v_item = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  PyObject *(*__pyx_t_5)(PyObject *);
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  int __pyx_t_8;
  int __pyx_t_9;
  int __pyx_t_10;
  int __pyx_t_11;
  int __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("get_words", 0);


  __pyx_v_count = 0;


  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 91, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_words = __pyx_t_1;
  __pyx_t_1 = 0;


  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 92, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_meanings = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;


  __Pyx_INCREF(__pyx_v_soup);
  __pyx_t_2 = __pyx_v_soup; __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_n_s_div) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_n_s_div);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 93, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_tags = __pyx_t_1;
  __pyx_t_1 = 0;


  if (likely(PyList_CheckExact(__pyx_v_tags)) || PyTuple_CheckExact(__pyx_v_tags)) {
    __pyx_t_1 = __pyx_v_tags; __Pyx_INCREF(__pyx_t_1); __pyx_t_4 = 0;
    __pyx_t_5 = NULL;
  } else {
    __pyx_t_4 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_tags); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 95, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_5 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 95, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_5)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 95, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 95, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      } else {
        if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 95, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 95, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      }
    } else {
      __pyx_t_2 = __pyx_t_5(__pyx_t_1);
      if (unlikely(!__pyx_t_2)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 95, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_2);
    }
    __Pyx_XDECREF_SET(__pyx_v_tag, __pyx_t_2);
    __pyx_t_2 = 0;


    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_tag, __pyx_n_s_get); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 96, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_6 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_6, __pyx_n_s_class) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_n_s_class);
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 96, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF_SET(__pyx_v_item, __pyx_t_2);
    __pyx_t_2 = 0;


    __pyx_t_7 = (__pyx_v_item == Py_None);
    __pyx_t_8 = (__pyx_t_7 != 0);
    if (__pyx_t_8) {
      goto __pyx_L3_continue;
    }


    __pyx_t_8 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_col_a, __pyx_v_item, Py_EQ)); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 98, __pyx_L1_error)
    __pyx_t_7 = (__pyx_t_8 != 0);
    if (__pyx_t_7) {


      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_tag, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 99, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_9 = __Pyx_PyObject_Append(__pyx_v_words, __pyx_t_2); if (unlikely(__pyx_t_9 == ((int)-1))) __PYX_ERR(0, 99, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;


    }


    __pyx_t_7 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_col_b, __pyx_v_item, Py_EQ)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 100, __pyx_L1_error)
    __pyx_t_8 = (__pyx_t_7 != 0);
    if (__pyx_t_8) {


      __pyx_v_count = (__pyx_v_count + 1);


      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_tag, __pyx_n_s_text); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 102, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_9 = __Pyx_PyList_Append(__pyx_v_meanings, __pyx_t_2); if (unlikely(__pyx_t_9 == ((int)-1))) __PYX_ERR(0, 102, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;


    }


    __pyx_L3_continue:;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;


  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_records = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":105
 *     records = list()
 *     #Get make words in records list: word | meaning | courseID | LevelID
 *     for i in range(count):             # <<<<<<<<<<<<<<
 *         record =  ( words[i]
 *                 ,meanings[i]
 */
  __pyx_t_10 = __pyx_v_count;
  __pyx_t_11 = __pyx_t_10;
  for (__pyx_t_12 = 0; __pyx_t_12 < __pyx_t_11; __pyx_t_12+=1) {
    __pyx_v_i = __pyx_t_12;


    __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_words, __pyx_v_i, int, 1, __Pyx_PyInt_From_int, 0, 1, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 106, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);

    /* "memrise.pyx":107
 *     for i in range(count):
 *         record =  ( words[i]
 *                 ,meanings[i]             # <<<<<<<<<<<<<<
 *                 ,course_id
 *                 ,level_id )
 */
    __pyx_t_2 = __Pyx_GetItemInt_List(__pyx_v_meanings, __pyx_v_i, int, 1, __Pyx_PyInt_From_int, 1, 1, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 107, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);

    /* "memrise.pyx":108
 *         record =  ( words[i]
 *                 ,meanings[i]
 *                 ,course_id             # <<<<<<<<<<<<<<
 *                 ,level_id )
 *         records.append(record)
 */
    __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_course_id); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 108, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);

    /* "memrise.pyx":109
 *                 ,meanings[i]
 *                 ,course_id
 *                 ,level_id )             # <<<<<<<<<<<<<<
 *         records.append(record)
 *     return records
 */
    __pyx_t_6 = __Pyx_PyInt_From_int(__pyx_v_level_id); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 109, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);

    /* "memrise.pyx":106
 *     #Get make words in records list: word | meaning | courseID | LevelID
 *     for i in range(count):
 *         record =  ( words[i]             # <<<<<<<<<<<<<<
 *                 ,meanings[i]
 *                 ,course_id
 */
    __pyx_t_13 = PyTuple_New(4); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 106, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_13);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_13, 0, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_13, 1, __pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_13, 2, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_13, 3, __pyx_t_6);
    __pyx_t_1 = 0;
    __pyx_t_2 = 0;
    __pyx_t_3 = 0;
    __pyx_t_6 = 0;
    __Pyx_XDECREF_SET(__pyx_v_record, __pyx_t_13);
    __pyx_t_13 = 0;

    /* "memrise.pyx":110
 *                 ,course_id
 *                 ,level_id )
 *         records.append(record)             # <<<<<<<<<<<<<<
 *     return records
 * 
 */
    __pyx_t_9 = __Pyx_PyObject_Append(__pyx_v_records, __pyx_v_record); if (unlikely(__pyx_t_9 == ((int)-1))) __PYX_ERR(0, 110, __pyx_L1_error)
  }

  /* "memrise.pyx":111
 *                 ,level_id )
 *         records.append(record)
 *     return records             # <<<<<<<<<<<<<<
 * 
 * # ******* Class Define **********
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_records);
  __pyx_r = __pyx_v_records;
  goto __pyx_L0;

  /* "memrise.pyx":85
 *     return name
 * 
 * cdef object get_words(object soup,int course_id, int level_id):             # <<<<<<<<<<<<<<
 *     cdef int i,count=0
 *     cdef object words,subs
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_AddTraceback("memrise.get_words", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_words);
  __Pyx_XDECREF(__pyx_v_records);
  __Pyx_XDECREF(__pyx_v_tags);
  __Pyx_XDECREF(__pyx_v_record);
  __Pyx_XDECREF(__pyx_v_meanings);
  __Pyx_XDECREF(__pyx_v_tag);
  __Pyx_XDECREF(__pyx_v_item);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":116
 * 
 * cdef class Level:
 *     def __cinit__(self,path,LevelID,CourseID):             # <<<<<<<<<<<<<<
 *         cdef object __name_tmp
 *         cdef object __page_tmp
 */

/* Python wrapper */
static int __pyx_pw_7memrise_5Level_1__cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_pw_7memrise_5Level_1__cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_path = 0;
  PyObject *__pyx_v_LevelID = 0;
  PyObject *__pyx_v_CourseID = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__cinit__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_path,&__pyx_n_s_LevelID,&__pyx_n_s_CourseID,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_path)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_LevelID)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__cinit__", 1, 3, 3, 1); __PYX_ERR(0, 116, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_CourseID)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__cinit__", 1, 3, 3, 2); __PYX_ERR(0, 116, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__cinit__") < 0)) __PYX_ERR(0, 116, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_path = values[0];
    __pyx_v_LevelID = values[1];
    __pyx_v_CourseID = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__cinit__", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 116, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("memrise.Level.__cinit__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return -1;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_7memrise_5Level___cinit__(((struct __pyx_obj_7memrise_Level *)__pyx_v_self), __pyx_v_path, __pyx_v_LevelID, __pyx_v_CourseID);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static int __pyx_pf_7memrise_5Level___cinit__(struct __pyx_obj_7memrise_Level *__pyx_v_self, PyObject *__pyx_v_path, PyObject *__pyx_v_LevelID, PyObject *__pyx_v_CourseID) {
  PyObject *__pyx_v___name_tmp = 0;
  PyObject *__pyx_v___page_tmp = 0;
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  char *__pyx_t_5;
  int __pyx_t_6;
  int __pyx_t_7;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__cinit__", 0);

  /* "memrise.pyx":119
 *         cdef object __name_tmp
 *         cdef object __page_tmp
 *         __page_tmp = PAGE + path.encode()             # <<<<<<<<<<<<<<
 *         self.__page = __page_tmp
 *         self.__soup = open_soup(self.__page)
 */
  __pyx_t_1 = __Pyx_PyBytes_FromString(__pyx_v_7memrise_PAGE); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_path, __pyx_n_s_encode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v___page_tmp = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "memrise.pyx":120
 *         cdef object __page_tmp
 *         __page_tmp = PAGE + path.encode()
 *         self.__page = __page_tmp             # <<<<<<<<<<<<<<
 *         self.__soup = open_soup(self.__page)
 *         __name_tmp = get_name(b'h3',self.__soup)
 */
  __pyx_t_5 = __Pyx_PyObject_AsWritableString(__pyx_v___page_tmp); if (unlikely((!__pyx_t_5) && PyErr_Occurred())) __PYX_ERR(0, 120, __pyx_L1_error)
  __pyx_v_self->__pyx___page = __pyx_t_5;

  /* "memrise.pyx":121
 *         __page_tmp = PAGE + path.encode()
 *         self.__page = __page_tmp
 *         self.__soup = open_soup(self.__page)             # <<<<<<<<<<<<<<
 *         __name_tmp = get_name(b'h3',self.__soup)
 *         self.__name = __name_tmp
 */
  __pyx_t_3 = __pyx_f_7memrise_open_soup(__pyx_v_self->__pyx___page); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  __Pyx_GOTREF(__pyx_v_self->__pyx___soup);
  __Pyx_DECREF(__pyx_v_self->__pyx___soup);
  __pyx_v_self->__pyx___soup = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "memrise.pyx":122
 *         self.__page = __page_tmp
 *         self.__soup = open_soup(self.__page)
 *         __name_tmp = get_name(b'h3',self.__soup)             # <<<<<<<<<<<<<<
 *         self.__name = __name_tmp
 *         self.__words = get_words(self.__soup,CourseID,LevelID)
 */
  __pyx_t_3 = __pyx_v_self->__pyx___soup;
  __Pyx_INCREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyBytes_FromString(__pyx_f_7memrise_get_name(((char *)"h3"), __pyx_t_3)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v___name_tmp = __pyx_t_2;
  __pyx_t_2 = 0;

  /* "memrise.pyx":123
 *         self.__soup = open_soup(self.__page)
 *         __name_tmp = get_name(b'h3',self.__soup)
 *         self.__name = __name_tmp             # <<<<<<<<<<<<<<
 *         self.__words = get_words(self.__soup,CourseID,LevelID)
 *         self.__record = tuple([CourseID,LevelID,self.__name.decode()])
 */
  __pyx_t_5 = __Pyx_PyObject_AsWritableString(__pyx_v___name_tmp); if (unlikely((!__pyx_t_5) && PyErr_Occurred())) __PYX_ERR(0, 123, __pyx_L1_error)
  __pyx_v_self->__pyx___name = __pyx_t_5;

  /* "memrise.pyx":124
 *         __name_tmp = get_name(b'h3',self.__soup)
 *         self.__name = __name_tmp
 *         self.__words = get_words(self.__soup,CourseID,LevelID)             # <<<<<<<<<<<<<<
 *         self.__record = tuple([CourseID,LevelID,self.__name.decode()])
 * 
 */
  __pyx_t_2 = __pyx_v_self->__pyx___soup;
  __Pyx_INCREF(__pyx_t_2);
  __pyx_t_6 = __Pyx_PyInt_As_int(__pyx_v_CourseID); if (unlikely((__pyx_t_6 == (int)-1) && PyErr_Occurred())) __PYX_ERR(0, 124, __pyx_L1_error)
  __pyx_t_7 = __Pyx_PyInt_As_int(__pyx_v_LevelID); if (unlikely((__pyx_t_7 == (int)-1) && PyErr_Occurred())) __PYX_ERR(0, 124, __pyx_L1_error)
  __pyx_t_3 = __pyx_f_7memrise_get_words(__pyx_t_2, __pyx_t_6, __pyx_t_7); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 124, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (!(likely(PyList_CheckExact(__pyx_t_3))||((__pyx_t_3) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "list", Py_TYPE(__pyx_t_3)->tp_name), 0))) __PYX_ERR(0, 124, __pyx_L1_error)
  __Pyx_GIVEREF(__pyx_t_3);
  __Pyx_GOTREF(__pyx_v_self->__pyx___words);
  __Pyx_DECREF(__pyx_v_self->__pyx___words);
  __pyx_v_self->__pyx___words = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;

  /* "memrise.pyx":125
 *         self.__name = __name_tmp
 *         self.__words = get_words(self.__soup,CourseID,LevelID)
 *         self.__record = tuple([CourseID,LevelID,self.__name.decode()])             # <<<<<<<<<<<<<<
 * 
 *     def get_words(self)->list:
 */
  __pyx_t_5 = __pyx_v_self->__pyx___name;
  __pyx_t_3 = __Pyx_decode_c_string(__pyx_t_5, 0, strlen(__pyx_t_5), NULL, NULL, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_v_CourseID);
  __Pyx_GIVEREF(__pyx_v_CourseID);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_v_CourseID);
  __Pyx_INCREF(__pyx_v_LevelID);
  __Pyx_GIVEREF(__pyx_v_LevelID);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_v_LevelID);
  __Pyx_INCREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyList_AsTuple(((PyObject*)__pyx_t_2)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GIVEREF(__pyx_t_3);
  __Pyx_GOTREF(__pyx_v_self->__pyx___record);
  __Pyx_DECREF(__pyx_v_self->__pyx___record);
  __pyx_v_self->__pyx___record = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "memrise.pyx":116
 * 
 * cdef class Level:
 *     def __cinit__(self,path,LevelID,CourseID):             # <<<<<<<<<<<<<<
 *         cdef object __name_tmp
 *         cdef object __page_tmp
 */

  /* function exit code */
  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("memrise.Level.__cinit__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = -1;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v___name_tmp);
  __Pyx_XDECREF(__pyx_v___page_tmp);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":127
 *         self.__record = tuple([CourseID,LevelID,self.__name.decode()])
 * 
 *     def get_words(self)->list:             # <<<<<<<<<<<<<<
 *         return self.__words
 * 
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_5Level_3get_words(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyObject *__pyx_pw_7memrise_5Level_3get_words(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get_words (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_5Level_2get_words(((struct __pyx_obj_7memrise_Level *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_5Level_2get_words(struct __pyx_obj_7memrise_Level *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get_words", 0);

  /* "memrise.pyx":128
 * 
 *     def get_words(self)->list:
 *         return self.__words             # <<<<<<<<<<<<<<
 * 
 *     def get_record(self)->tuple:
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self->__pyx___words);
  __pyx_r = __pyx_v_self->__pyx___words;
  goto __pyx_L0;

  /* "memrise.pyx":127
 *         self.__record = tuple([CourseID,LevelID,self.__name.decode()])
 * 
 *     def get_words(self)->list:             # <<<<<<<<<<<<<<
 *         return self.__words
 * 
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":130
 *         return self.__words
 * 
 *     def get_record(self)->tuple:             # <<<<<<<<<<<<<<
 *         return self.__record
 * 
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_5Level_5get_record(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyObject *__pyx_pw_7memrise_5Level_5get_record(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get_record (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_5Level_4get_record(((struct __pyx_obj_7memrise_Level *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_5Level_4get_record(struct __pyx_obj_7memrise_Level *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("get_record", 0);

  /* "memrise.pyx":131
 * 
 *     def get_record(self)->tuple:
 *         return self.__record             # <<<<<<<<<<<<<<
 * 
 * cdef class Course:
 */
  __Pyx_XDECREF(__pyx_r);
  if (!(likely(PyTuple_CheckExact(__pyx_v_self->__pyx___record))||((__pyx_v_self->__pyx___record) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "tuple", Py_TYPE(__pyx_v_self->__pyx___record)->tp_name), 0))) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_INCREF(__pyx_v_self->__pyx___record);
  __pyx_r = ((PyObject*)__pyx_v_self->__pyx___record);
  goto __pyx_L0;

  /* "memrise.pyx":130
 *         return self.__words
 * 
 *     def get_record(self)->tuple:             # <<<<<<<<<<<<<<
 *         return self.__record
 * 
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_AddTraceback("memrise.Level.get_record", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "(tree fragment)":1
 * def __reduce_cython__(self):             # <<<<<<<<<<<<<<
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_5Level_7__reduce_cython__(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyObject *__pyx_pw_7memrise_5Level_7__reduce_cython__(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__reduce_cython__ (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_5Level_6__reduce_cython__(((struct __pyx_obj_7memrise_Level *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_5Level_6__reduce_cython__(CYTHON_UNUSED struct __pyx_obj_7memrise_Level *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__reduce_cython__", 0);

  /* "(tree fragment)":2
 * def __reduce_cython__(self):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")             # <<<<<<<<<<<<<<
 * def __setstate_cython__(self, __pyx_state):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_TypeError, __pyx_tuple_, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_Raise(__pyx_t_1, 0, 0, 0);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __PYX_ERR(1, 2, __pyx_L1_error)

  /* "(tree fragment)":1
 * def __reduce_cython__(self):             # <<<<<<<<<<<<<<
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("memrise.Level.__reduce_cython__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "(tree fragment)":3
 * def __reduce_cython__(self):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):             # <<<<<<<<<<<<<<
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_5Level_9__setstate_cython__(PyObject *__pyx_v_self, PyObject *__pyx_v___pyx_state); /*proto*/
static PyObject *__pyx_pw_7memrise_5Level_9__setstate_cython__(PyObject *__pyx_v_self, PyObject *__pyx_v___pyx_state) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__setstate_cython__ (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_5Level_8__setstate_cython__(((struct __pyx_obj_7memrise_Level *)__pyx_v_self), ((PyObject *)__pyx_v___pyx_state));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_5Level_8__setstate_cython__(CYTHON_UNUSED struct __pyx_obj_7memrise_Level *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v___pyx_state) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__setstate_cython__", 0);

  /* "(tree fragment)":4
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")             # <<<<<<<<<<<<<<
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_TypeError, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_Raise(__pyx_t_1, 0, 0, 0);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __PYX_ERR(1, 4, __pyx_L1_error)

  /* "(tree fragment)":3
 * def __reduce_cython__(self):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):             # <<<<<<<<<<<<<<
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("memrise.Level.__setstate_cython__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":134
 * 
 * cdef class Course:
 *     def __cinit__(self,course_id:int,language_id:int):             # <<<<<<<<<<<<<<
 *         cdef object __name_tmp
 *         cdef object __page_tmp
 */

/* Python wrapper */
static int __pyx_pw_7memrise_6Course_1__cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_pw_7memrise_6Course_1__cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_course_id = 0;
  PyObject *__pyx_v_language_id = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__cinit__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_course_id,&__pyx_n_s_language_id,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_course_id)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_language_id)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__cinit__", 1, 2, 2, 1); __PYX_ERR(0, 134, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__cinit__") < 0)) __PYX_ERR(0, 134, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_course_id = values[0];
    __pyx_v_language_id = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__cinit__", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 134, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("memrise.Course.__cinit__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return -1;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_7memrise_6Course___cinit__(((struct __pyx_obj_7memrise_Course *)__pyx_v_self), __pyx_v_course_id, __pyx_v_language_id);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static int __pyx_pf_7memrise_6Course___cinit__(struct __pyx_obj_7memrise_Course *__pyx_v_self, PyObject *__pyx_v_course_id, PyObject *__pyx_v_language_id) {
  PyObject *__pyx_v___name_tmp = 0;
  PyObject *__pyx_v___page_tmp = 0;
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  char *__pyx_t_5;
  int __pyx_t_6;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__cinit__", 0);

  /* "memrise.pyx":137
 *         cdef object __name_tmp
 *         cdef object __page_tmp
 *         __page_tmp = PAGE + b'/course/' +  str(course_id).encode()             # <<<<<<<<<<<<<<
 *         self.__page = __page_tmp
 *         self.__soup = open_soup(self.__page)
 */
  __pyx_t_1 = __Pyx_PyBytes_FromString(__pyx_v_7memrise_PAGE); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 137, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_b_course); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 137, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_v_course_id); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 137, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_encode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 137, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 137, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Add(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 137, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v___page_tmp = __pyx_t_4;
  __pyx_t_4 = 0;

  /* "memrise.pyx":138
 *         cdef object __page_tmp
 *         __page_tmp = PAGE + b'/course/' +  str(course_id).encode()
 *         self.__page = __page_tmp             # <<<<<<<<<<<<<<
 *         self.__soup = open_soup(self.__page)
 *         self.course_id = course_id
 */
  __pyx_t_5 = __Pyx_PyObject_AsWritableString(__pyx_v___page_tmp); if (unlikely((!__pyx_t_5) && PyErr_Occurred())) __PYX_ERR(0, 138, __pyx_L1_error)
  __pyx_v_self->__pyx___page = __pyx_t_5;

  /* "memrise.pyx":139
 *         __page_tmp = PAGE + b'/course/' +  str(course_id).encode()
 *         self.__page = __page_tmp
 *         self.__soup = open_soup(self.__page)             # <<<<<<<<<<<<<<
 *         self.course_id = course_id
 *         #Get name data type is char* ~ bytes
 */
  __pyx_t_4 = __pyx_f_7memrise_open_soup(__pyx_v_self->__pyx___page); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  __Pyx_GOTREF(__pyx_v_self->__pyx___soup);
  __Pyx_DECREF(__pyx_v_self->__pyx___soup);
  __pyx_v_self->__pyx___soup = __pyx_t_4;
  __pyx_t_4 = 0;

  /* "memrise.pyx":140
 *         self.__page = __page_tmp
 *         self.__soup = open_soup(self.__page)
 *         self.course_id = course_id             # <<<<<<<<<<<<<<
 *         #Get name data type is char* ~ bytes
 *         __name_tmp = get_name(b'h1',self.__soup)
 */
  __pyx_t_6 = __Pyx_PyInt_As_int(__pyx_v_course_id); if (unlikely((__pyx_t_6 == (int)-1) && PyErr_Occurred())) __PYX_ERR(0, 140, __pyx_L1_error)
  __pyx_v_self->course_id = __pyx_t_6;

  /* "memrise.pyx":142
 *         self.course_id = course_id
 *         #Get name data type is char* ~ bytes
 *         __name_tmp = get_name(b'h1',self.__soup)             # <<<<<<<<<<<<<<
 *         self.__name = __name_tmp
 *         self.__record = tuple([course_id,self.__name.decode(),language_id])
 */
  __pyx_t_4 = __pyx_v_self->__pyx___soup;
  __Pyx_INCREF(__pyx_t_4);
  __pyx_t_1 = __Pyx_PyBytes_FromString(__pyx_f_7memrise_get_name(((char *)"h1"), __pyx_t_4)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v___name_tmp = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":143
 *         #Get name data type is char* ~ bytes
 *         __name_tmp = get_name(b'h1',self.__soup)
 *         self.__name = __name_tmp             # <<<<<<<<<<<<<<
 *         self.__record = tuple([course_id,self.__name.decode(),language_id])
 *         self.__levels = self.__get_levels(self.__soup)
 */
  __pyx_t_5 = __Pyx_PyObject_AsWritableString(__pyx_v___name_tmp); if (unlikely((!__pyx_t_5) && PyErr_Occurred())) __PYX_ERR(0, 143, __pyx_L1_error)
  __pyx_v_self->__pyx___name = __pyx_t_5;

  /* "memrise.pyx":144
 *         __name_tmp = get_name(b'h1',self.__soup)
 *         self.__name = __name_tmp
 *         self.__record = tuple([course_id,self.__name.decode(),language_id])             # <<<<<<<<<<<<<<
 *         self.__levels = self.__get_levels(self.__soup)
 * 
 */
  __pyx_t_5 = __pyx_v_self->__pyx___name;
  __pyx_t_1 = __Pyx_decode_c_string(__pyx_t_5, 0, strlen(__pyx_t_5), NULL, NULL, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyList_New(3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_v_course_id);
  __Pyx_GIVEREF(__pyx_v_course_id);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_v_course_id);
  __Pyx_INCREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_4, 1, __pyx_t_1);
  __Pyx_INCREF(__pyx_v_language_id);
  __Pyx_GIVEREF(__pyx_v_language_id);
  PyList_SET_ITEM(__pyx_t_4, 2, __pyx_v_language_id);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyList_AsTuple(((PyObject*)__pyx_t_4)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 144, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GIVEREF(__pyx_t_1);
  __Pyx_GOTREF(__pyx_v_self->__pyx___record);
  __Pyx_DECREF(__pyx_v_self->__pyx___record);
  __pyx_v_self->__pyx___record = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":145
 *         self.__name = __name_tmp
 *         self.__record = tuple([course_id,self.__name.decode(),language_id])
 *         self.__levels = self.__get_levels(self.__soup)             # <<<<<<<<<<<<<<
 * 
 *     def get_levels(self) -> list:
 */
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_self), __pyx_n_s_get_levels); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 145, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_v_self->__pyx___soup) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_v_self->__pyx___soup);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 145, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (!(likely(PyList_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "list", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 145, __pyx_L1_error)
  __Pyx_GIVEREF(__pyx_t_1);
  __Pyx_GOTREF(__pyx_v_self->__pyx___levels);
  __Pyx_DECREF(__pyx_v_self->__pyx___levels);
  __pyx_v_self->__pyx___levels = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "memrise.pyx":134
 * 
 * cdef class Course:
 *     def __cinit__(self,course_id:int,language_id:int):             # <<<<<<<<<<<<<<
 *         cdef object __name_tmp
 *         cdef object __page_tmp
 */

  /* function exit code */
  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("memrise.Course.__cinit__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = -1;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v___name_tmp);
  __Pyx_XDECREF(__pyx_v___page_tmp);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":147
 *         self.__levels = self.__get_levels(self.__soup)
 * 
 *     def get_levels(self) -> list:             # <<<<<<<<<<<<<<
 *         return self.__levels
 * 
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_6Course_3get_levels(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyObject *__pyx_pw_7memrise_6Course_3get_levels(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get_levels (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_6Course_2get_levels(((struct __pyx_obj_7memrise_Course *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_6Course_2get_levels(struct __pyx_obj_7memrise_Course *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get_levels", 0);

  /* "memrise.pyx":148
 * 
 *     def get_levels(self) -> list:
 *         return self.__levels             # <<<<<<<<<<<<<<
 * 
 *     def __get_levels(self,soup) -> list:
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self->__pyx___levels);
  __pyx_r = __pyx_v_self->__pyx___levels;
  goto __pyx_L0;

  /* "memrise.pyx":147
 *         self.__levels = self.__get_levels(self.__soup)
 * 
 *     def get_levels(self) -> list:             # <<<<<<<<<<<<<<
 *         return self.__levels
 * 
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



/* Python wrapper */
static PyObject *__pyx_pw_7memrise_6Course_5__get_levels(PyObject *__pyx_v_self, PyObject *__pyx_v_soup); /*proto*/
static PyObject *__pyx_pw_7memrise_6Course_5__get_levels(PyObject *__pyx_v_self, PyObject *__pyx_v_soup) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__get_levels (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_6Course_4__get_levels(((struct __pyx_obj_7memrise_Course *)__pyx_v_self), ((PyObject *)__pyx_v_soup));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_6Course_4__get_levels(struct __pyx_obj_7memrise_Course *__pyx_v_self, PyObject *__pyx_v_soup) {
  PyObject *__pyx_v_tags = NULL;
  PyObject *__pyx_v_levels = NULL;
  PyObject *__pyx_v_expr = NULL;
  PyObject *__pyx_v_count = NULL;
  PyObject *__pyx_v_tag = NULL;
  PyObject *__pyx_v_item = NULL;
  struct __pyx_obj_7memrise_Level *__pyx_v_level = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  PyObject *(*__pyx_t_5)(PyObject *);
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_t_9;
  int __pyx_t_10;
  int __pyx_t_11;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__get_levels", 0);


  __Pyx_INCREF(__pyx_v_soup);
  __pyx_t_2 = __pyx_v_soup; __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_n_s_a) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_n_s_a);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_tags = __pyx_t_1;
  __pyx_t_1 = 0;


  __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 153, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_levels = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;


  __Pyx_INCREF(__pyx_kp_s_d);
  __pyx_v_expr = __pyx_kp_s_d;


  __Pyx_INCREF(__pyx_int_1);
  __pyx_v_count = __pyx_int_1;


  if (likely(PyList_CheckExact(__pyx_v_tags)) || PyTuple_CheckExact(__pyx_v_tags)) {
    __pyx_t_1 = __pyx_v_tags; __Pyx_INCREF(__pyx_t_1); __pyx_t_4 = 0;
    __pyx_t_5 = NULL;
  } else {
    __pyx_t_4 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_tags); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_5 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 156, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_5)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 156, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 156, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      } else {
        if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 156, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 156, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      }
    } else {
      __pyx_t_2 = __pyx_t_5(__pyx_t_1);
      if (unlikely(!__pyx_t_2)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 156, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_2);
    }
    __Pyx_XDECREF_SET(__pyx_v_tag, __pyx_t_2);
    __pyx_t_2 = 0;


    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_tag, __pyx_n_s_get); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 157, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__3, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 157, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF_SET(__pyx_v_item, __pyx_t_3);
    __pyx_t_3 = 0;


    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_re); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 158, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_search); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 158, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = NULL;
    __pyx_t_7 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_6);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_6, function);
        __pyx_t_7 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_6)) {
      PyObject *__pyx_temp[3] = {__pyx_t_2, __pyx_v_expr, __pyx_v_item};
      __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 158, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
      PyObject *__pyx_temp[3] = {__pyx_t_2, __pyx_v_expr, __pyx_v_item};
      __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 158, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_GOTREF(__pyx_t_3);
    } else
    #endif
    {
      __pyx_t_8 = PyTuple_New(2+__pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 158, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (__pyx_t_2) {
        __Pyx_GIVEREF(__pyx_t_2); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_2); __pyx_t_2 = NULL;
      }
      __Pyx_INCREF(__pyx_v_expr);
      __Pyx_GIVEREF(__pyx_v_expr);
      PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_7, __pyx_v_expr);
      __Pyx_INCREF(__pyx_v_item);
      __Pyx_GIVEREF(__pyx_v_item);
      PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_7, __pyx_v_item);
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_8, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 158, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    }
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_9 = (__pyx_t_3 != Py_None);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_10 = (__pyx_t_9 != 0);
    if (__pyx_t_10) {


      __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_self->course_id); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 159, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_6 = PyTuple_New(3); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 159, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_INCREF(__pyx_v_item);
      __Pyx_GIVEREF(__pyx_v_item);
      PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_v_item);
      __Pyx_INCREF(__pyx_v_count);
      __Pyx_GIVEREF(__pyx_v_count);
      PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_v_count);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_t_3);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_Call(((PyObject *)__pyx_ptype_7memrise_Level), __pyx_t_6, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 159, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF_SET(__pyx_v_level, ((struct __pyx_obj_7memrise_Level *)__pyx_t_3));
      __pyx_t_3 = 0;

      /* "memrise.pyx":160
 *             if re.search(expr,item) is not None:
 *                 level = Level(item,count,self.course_id)
 *                 levels.append(level)             # <<<<<<<<<<<<<<
 *                 count += 1
 *         return levels
 */
      __pyx_t_11 = __Pyx_PyList_Append(__pyx_v_levels, ((PyObject *)__pyx_v_level)); if (unlikely(__pyx_t_11 == ((int)-1))) __PYX_ERR(0, 160, __pyx_L1_error)

      /* "memrise.pyx":161
 *                 level = Level(item,count,self.course_id)
 *                 levels.append(level)
 *                 count += 1             # <<<<<<<<<<<<<<
 *         return levels
 * 
 */
      __pyx_t_3 = __Pyx_PyInt_AddObjC(__pyx_v_count, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 161, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF_SET(__pyx_v_count, __pyx_t_3);
      __pyx_t_3 = 0;


    }


  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;


  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_levels);
  __pyx_r = __pyx_v_levels;
  goto __pyx_L0;


  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("memrise.Course.__get_levels", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_tags);
  __Pyx_XDECREF(__pyx_v_levels);
  __Pyx_XDECREF(__pyx_v_expr);
  __Pyx_XDECREF(__pyx_v_count);
  __Pyx_XDECREF(__pyx_v_tag);
  __Pyx_XDECREF(__pyx_v_item);
  __Pyx_XDECREF((PyObject *)__pyx_v_level);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":164
 *         return levels
 * 
 *     def get_record(self) -> tuple:             # <<<<<<<<<<<<<<
 *         return self.__record
 * 
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_6Course_7get_record(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyObject *__pyx_pw_7memrise_6Course_7get_record(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get_record (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_6Course_6get_record(((struct __pyx_obj_7memrise_Course *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_6Course_6get_record(struct __pyx_obj_7memrise_Course *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("get_record", 0);

  /* "memrise.pyx":165
 * 
 *     def get_record(self) -> tuple:
 *         return self.__record             # <<<<<<<<<<<<<<
 * 
 * cdef class Data:
 */
  __Pyx_XDECREF(__pyx_r);
  if (!(likely(PyTuple_CheckExact(__pyx_v_self->__pyx___record))||((__pyx_v_self->__pyx___record) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "tuple", Py_TYPE(__pyx_v_self->__pyx___record)->tp_name), 0))) __PYX_ERR(0, 165, __pyx_L1_error)
  __Pyx_INCREF(__pyx_v_self->__pyx___record);
  __pyx_r = ((PyObject*)__pyx_v_self->__pyx___record);
  goto __pyx_L0;

  /* "memrise.pyx":164
 *         return levels
 * 
 *     def get_record(self) -> tuple:             # <<<<<<<<<<<<<<
 *         return self.__record
 * 
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_AddTraceback("memrise.Course.get_record", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "(tree fragment)":1
 * def __reduce_cython__(self):             # <<<<<<<<<<<<<<
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_6Course_9__reduce_cython__(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyObject *__pyx_pw_7memrise_6Course_9__reduce_cython__(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__reduce_cython__ (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_6Course_8__reduce_cython__(((struct __pyx_obj_7memrise_Course *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_6Course_8__reduce_cython__(CYTHON_UNUSED struct __pyx_obj_7memrise_Course *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__reduce_cython__", 0);

  /* "(tree fragment)":2
 * def __reduce_cython__(self):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")             # <<<<<<<<<<<<<<
 * def __setstate_cython__(self, __pyx_state):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_TypeError, __pyx_tuple__4, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_Raise(__pyx_t_1, 0, 0, 0);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __PYX_ERR(1, 2, __pyx_L1_error)

  /* "(tree fragment)":1
 * def __reduce_cython__(self):             # <<<<<<<<<<<<<<
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("memrise.Course.__reduce_cython__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "(tree fragment)":3
 * def __reduce_cython__(self):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):             # <<<<<<<<<<<<<<
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_6Course_11__setstate_cython__(PyObject *__pyx_v_self, PyObject *__pyx_v___pyx_state); /*proto*/
static PyObject *__pyx_pw_7memrise_6Course_11__setstate_cython__(PyObject *__pyx_v_self, PyObject *__pyx_v___pyx_state) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__setstate_cython__ (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_6Course_10__setstate_cython__(((struct __pyx_obj_7memrise_Course *)__pyx_v_self), ((PyObject *)__pyx_v___pyx_state));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_6Course_10__setstate_cython__(CYTHON_UNUSED struct __pyx_obj_7memrise_Course *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v___pyx_state) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__setstate_cython__", 0);

  /* "(tree fragment)":4
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")             # <<<<<<<<<<<<<<
 */
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_TypeError, __pyx_tuple__5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_Raise(__pyx_t_1, 0, 0, 0);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __PYX_ERR(1, 4, __pyx_L1_error)

  /* "(tree fragment)":3
 * def __reduce_cython__(self):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):             # <<<<<<<<<<<<<<
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("memrise.Course.__setstate_cython__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":169
 * cdef class Data:
 *     '''Class manage all actions as insert, update, and delete DATABASE'''
 *     def __init__(self,db:str)->None:             # <<<<<<<<<<<<<<
 *         self.conn = self.__connect_database(db)
 *         self.cur = self.conn.cursor()
 */

/* Python wrapper */
static int __pyx_pw_7memrise_4Data_1__init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_pw_7memrise_4Data_1__init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_db = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_db,0};
    PyObject* values[1] = {0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_db)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 169, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 1) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
    }
    __pyx_v_db = ((PyObject*)values[0]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 1, 1, 1, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 169, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("memrise.Data.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return -1;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_db), (&PyString_Type), 1, "db", 1))) __PYX_ERR(0, 169, __pyx_L1_error)
  __pyx_r = __pyx_pf_7memrise_4Data___init__(((struct __pyx_obj_7memrise_Data *)__pyx_v_self), __pyx_v_db);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = -1;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static int __pyx_pf_7memrise_4Data___init__(struct __pyx_obj_7memrise_Data *__pyx_v_self, PyObject *__pyx_v_db) {
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "memrise.pyx":170
 *     '''Class manage all actions as insert, update, and delete DATABASE'''
 *     def __init__(self,db:str)->None:
 *         self.conn = self.__connect_database(db)             # <<<<<<<<<<<<<<
 *         self.cur = self.conn.cursor()
 * 
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_self), __pyx_n_s_connect_database); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 170, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_db) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_db);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 170, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GIVEREF(__pyx_t_1);
  __Pyx_GOTREF(__pyx_v_self->conn);
  __Pyx_DECREF(__pyx_v_self->conn);
  __pyx_v_self->conn = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":171
 *     def __init__(self,db:str)->None:
 *         self.conn = self.__connect_database(db)
 *         self.cur = self.conn.cursor()             # <<<<<<<<<<<<<<
 * 
 *     #Function regard to Access Database
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->conn, __pyx_n_s_cursor); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GIVEREF(__pyx_t_1);
  __Pyx_GOTREF(__pyx_v_self->cur);
  __Pyx_DECREF(__pyx_v_self->cur);
  __pyx_v_self->cur = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":169
 * cdef class Data:
 *     '''Class manage all actions as insert, update, and delete DATABASE'''
 *     def __init__(self,db:str)->None:             # <<<<<<<<<<<<<<
 *         self.conn = self.__connect_database(db)
 *         self.cur = self.conn.cursor()
 */

  /* function exit code */
  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("memrise.Data.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = -1;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":174
 * 
 *     #Function regard to Access Database
 *     def __connect_database(self,db):             # <<<<<<<<<<<<<<
 *         '''Connect to database, intialization'''
 *         conn = sqlite3.Connection(db)
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_3__connect_database(PyObject *__pyx_v_self, PyObject *__pyx_v_db); /*proto*/
static char __pyx_doc_7memrise_4Data_2__connect_database[] = "Connect to database, intialization";
static PyObject *__pyx_pw_7memrise_4Data_3__connect_database(PyObject *__pyx_v_self, PyObject *__pyx_v_db) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__connect_database (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_4Data_2__connect_database(((struct __pyx_obj_7memrise_Data *)__pyx_v_self), ((PyObject *)__pyx_v_db));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_2__connect_database(CYTHON_UNUSED struct __pyx_obj_7memrise_Data *__pyx_v_self, PyObject *__pyx_v_db) {
  PyObject *__pyx_v_conn = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__connect_database", 0);

  /* "memrise.pyx":176
 *     def __connect_database(self,db):
 *         '''Connect to database, intialization'''
 *         conn = sqlite3.Connection(db)             # <<<<<<<<<<<<<<
 *         return conn
 * 
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sqlite3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 176, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_Connection); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 176, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_v_db) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_db);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 176, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_conn = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":177
 *         '''Connect to database, intialization'''
 *         conn = sqlite3.Connection(db)
 *         return conn             # <<<<<<<<<<<<<<
 * 
 *     def init_database(self):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_conn);
  __pyx_r = __pyx_v_conn;
  goto __pyx_L0;

  /* "memrise.pyx":174
 * 
 *     #Function regard to Access Database
 *     def __connect_database(self,db):             # <<<<<<<<<<<<<<
 *         '''Connect to database, intialization'''
 *         conn = sqlite3.Connection(db)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("memrise.Data.__connect_database", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_conn);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":179
 *         return conn
 * 
 *     def init_database(self):             # <<<<<<<<<<<<<<
 *         '''Create all necessary tables in Database'''
 *         for cmd in CREATE_TABLE:
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_5init_database(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static char __pyx_doc_7memrise_4Data_4init_database[] = "Create all necessary tables in Database";
static PyObject *__pyx_pw_7memrise_4Data_5init_database(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("init_database (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_4Data_4init_database(((struct __pyx_obj_7memrise_Data *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_4init_database(struct __pyx_obj_7memrise_Data *__pyx_v_self) {
  PyObject *__pyx_v_cmd = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("init_database", 0);

  /* "memrise.pyx":181
 *     def init_database(self):
 *         '''Create all necessary tables in Database'''
 *         for cmd in CREATE_TABLE:             # <<<<<<<<<<<<<<
 *             self.cur.execute(cmd)
 *         self.conn.commit()
 */
  if (unlikely(__pyx_v_7memrise_CREATE_TABLE == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 181, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_v_7memrise_CREATE_TABLE; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 181, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 181, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XDECREF_SET(__pyx_v_cmd, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "memrise.pyx":182
 *         '''Create all necessary tables in Database'''
 *         for cmd in CREATE_TABLE:
 *             self.cur.execute(cmd)             # <<<<<<<<<<<<<<
 *         self.conn.commit()
 * 
 */
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->cur, __pyx_n_s_execute); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 182, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
      }
    }
    __pyx_t_3 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_5, __pyx_v_cmd) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_v_cmd);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 182, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    /* "memrise.pyx":181
 *     def init_database(self):
 *         '''Create all necessary tables in Database'''
 *         for cmd in CREATE_TABLE:             # <<<<<<<<<<<<<<
 *             self.cur.execute(cmd)
 *         self.conn.commit()
 */
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "memrise.pyx":183
 *         for cmd in CREATE_TABLE:
 *             self.cur.execute(cmd)
 *         self.conn.commit()             # <<<<<<<<<<<<<<
 * 
 *     def __update(self,cmd,data:Any):
 */
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->conn, __pyx_n_s_commit); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "memrise.pyx":179
 *         return conn
 * 
 *     def init_database(self):             # <<<<<<<<<<<<<<
 *         '''Create all necessary tables in Database'''
 *         for cmd in CREATE_TABLE:
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("memrise.Data.init_database", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_cmd);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":185
 *         self.conn.commit()
 * 
 *     def __update(self,cmd,data:Any):             # <<<<<<<<<<<<<<
 *         #Most implementation is bytes (char*) must be convert to str
 *         CMD = cmd.decode()
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_7__update(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_pw_7memrise_4Data_7__update(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_cmd = 0;
  PyObject *__pyx_v_data = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__update (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_cmd,&__pyx_n_s_data,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_cmd)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_data)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__update", 1, 2, 2, 1); __PYX_ERR(0, 185, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__update") < 0)) __PYX_ERR(0, 185, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_cmd = values[0];
    __pyx_v_data = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__update", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 185, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("memrise.Data.__update", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_7memrise_4Data_6__update(((struct __pyx_obj_7memrise_Data *)__pyx_v_self), __pyx_v_cmd, __pyx_v_data);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_6__update(struct __pyx_obj_7memrise_Data *__pyx_v_self, PyObject *__pyx_v_cmd, PyObject *__pyx_v_data) {
  PyObject *__pyx_v_CMD = NULL;
  PyObject *__pyx_v_record = NULL;
  PyObject *__pyx_v_exit = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  Py_ssize_t __pyx_t_7;
  PyObject *(*__pyx_t_8)(PyObject *);
  PyObject *__pyx_t_9 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__update", 0);

  /* "memrise.pyx":187
 *     def __update(self,cmd,data:Any):
 *         #Most implementation is bytes (char*) must be convert to str
 *         CMD = cmd.decode()             # <<<<<<<<<<<<<<
 *         #Handle datatype input
 *         if type(data)==type(tuple()):
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_cmd, __pyx_n_s_decode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_CMD = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":189
 *         CMD = cmd.decode()
 *         #Handle datatype input
 *         if type(data)==type(tuple()):             # <<<<<<<<<<<<<<
 *             self.cur.execute(CMD,data)
 *         elif type(data)==type(list()):
 */
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(((PyObject *)(&PyTuple_Type))); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_data)), ((PyObject *)Py_TYPE(__pyx_t_1)), Py_EQ); __Pyx_XGOTREF(__pyx_t_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_4) {

    /* "memrise.pyx":190
 *         #Handle datatype input
 *         if type(data)==type(tuple()):
 *             self.cur.execute(CMD,data)             # <<<<<<<<<<<<<<
 *         elif type(data)==type(list()):
 *             for record in data:
 */
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->cur, __pyx_n_s_execute); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 190, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = NULL;
    __pyx_t_5 = 0;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
        __pyx_t_5 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_1)) {
      PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_CMD, __pyx_v_data};
      __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 190, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_GOTREF(__pyx_t_2);
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
      PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_CMD, __pyx_v_data};
      __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 190, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_GOTREF(__pyx_t_2);
    } else
    #endif
    {
      __pyx_t_6 = PyTuple_New(2+__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 190, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      if (__pyx_t_3) {
        __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_3); __pyx_t_3 = NULL;
      }
      __Pyx_INCREF(__pyx_v_CMD);
      __Pyx_GIVEREF(__pyx_v_CMD);
      PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_5, __pyx_v_CMD);
      __Pyx_INCREF(__pyx_v_data);
      __Pyx_GIVEREF(__pyx_v_data);
      PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_5, __pyx_v_data);
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_6, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 190, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    }
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    /* "memrise.pyx":189
 *         CMD = cmd.decode()
 *         #Handle datatype input
 *         if type(data)==type(tuple()):             # <<<<<<<<<<<<<<
 *             self.cur.execute(CMD,data)
 *         elif type(data)==type(list()):
 */
    goto __pyx_L3;
  }

  /* "memrise.pyx":191
 *         if type(data)==type(tuple()):
 *             self.cur.execute(CMD,data)
 *         elif type(data)==type(list()):             # <<<<<<<<<<<<<<
 *             for record in data:
 *                 self.cur.execute(CMD,record)
 */
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 191, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_data)), ((PyObject *)Py_TYPE(__pyx_t_2)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 191, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 191, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_4) {

    /* "memrise.pyx":192
 *             self.cur.execute(CMD,data)
 *         elif type(data)==type(list()):
 *             for record in data:             # <<<<<<<<<<<<<<
 *                 self.cur.execute(CMD,record)
 *         else:
 */
    if (likely(PyList_CheckExact(__pyx_v_data)) || PyTuple_CheckExact(__pyx_v_data)) {
      __pyx_t_1 = __pyx_v_data; __Pyx_INCREF(__pyx_t_1); __pyx_t_7 = 0;
      __pyx_t_8 = NULL;
    } else {
      __pyx_t_7 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_data); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 192, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_8 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 192, __pyx_L1_error)
    }
    for (;;) {
      if (likely(!__pyx_t_8)) {
        if (likely(PyList_CheckExact(__pyx_t_1))) {
          if (__pyx_t_7 >= PyList_GET_SIZE(__pyx_t_1)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_2 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_7); __Pyx_INCREF(__pyx_t_2); __pyx_t_7++; if (unlikely(0 < 0)) __PYX_ERR(0, 192, __pyx_L1_error)
          #else
          __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_7); __pyx_t_7++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 192, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          #endif
        } else {
          if (__pyx_t_7 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_7); __Pyx_INCREF(__pyx_t_2); __pyx_t_7++; if (unlikely(0 < 0)) __PYX_ERR(0, 192, __pyx_L1_error)
          #else
          __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_7); __pyx_t_7++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 192, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          #endif
        }
      } else {
        __pyx_t_2 = __pyx_t_8(__pyx_t_1);
        if (unlikely(!__pyx_t_2)) {
          PyObject* exc_type = PyErr_Occurred();
          if (exc_type) {
            if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
            else __PYX_ERR(0, 192, __pyx_L1_error)
          }
          break;
        }
        __Pyx_GOTREF(__pyx_t_2);
      }
      __Pyx_XDECREF_SET(__pyx_v_record, __pyx_t_2);
      __pyx_t_2 = 0;

      /* "memrise.pyx":193
 *         elif type(data)==type(list()):
 *             for record in data:
 *                 self.cur.execute(CMD,record)             # <<<<<<<<<<<<<<
 *         else:
 *             from sys import exit
 */
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->cur, __pyx_n_s_execute); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 193, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_3 = NULL;
      __pyx_t_5 = 0;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
        __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
        if (likely(__pyx_t_3)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
          __Pyx_INCREF(__pyx_t_3);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_6, function);
          __pyx_t_5 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_6)) {
        PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_CMD, __pyx_v_record};
        __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 193, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_GOTREF(__pyx_t_2);
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
        PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_CMD, __pyx_v_record};
        __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 193, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_GOTREF(__pyx_t_2);
      } else
      #endif
      {
        __pyx_t_9 = PyTuple_New(2+__pyx_t_5); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 193, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_9);
        if (__pyx_t_3) {
          __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_3); __pyx_t_3 = NULL;
        }
        __Pyx_INCREF(__pyx_v_CMD);
        __Pyx_GIVEREF(__pyx_v_CMD);
        PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_5, __pyx_v_CMD);
        __Pyx_INCREF(__pyx_v_record);
        __Pyx_GIVEREF(__pyx_v_record);
        PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_5, __pyx_v_record);
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_9, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 193, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      }
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      /* "memrise.pyx":192
 *             self.cur.execute(CMD,data)
 *         elif type(data)==type(list()):
 *             for record in data:             # <<<<<<<<<<<<<<
 *                 self.cur.execute(CMD,record)
 *         else:
 */
    }
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    /* "memrise.pyx":191
 *         if type(data)==type(tuple()):
 *             self.cur.execute(CMD,data)
 *         elif type(data)==type(list()):             # <<<<<<<<<<<<<<
 *             for record in data:
 *                 self.cur.execute(CMD,record)
 */
    goto __pyx_L3;
  }

  /* "memrise.pyx":195
 *                 self.cur.execute(CMD,record)
 *         else:
 *             from sys import exit             # <<<<<<<<<<<<<<
 *             print('TypeError: Data type must be RECORD or the list of RECORDs')
 *             exit()
 */
  /*else*/ {
    __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 195, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_n_s_exit);
    __Pyx_GIVEREF(__pyx_n_s_exit);
    PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_exit);
    __pyx_t_2 = __Pyx_Import(__pyx_n_s_sys, __pyx_t_1, -1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 195, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_exit); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 195, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_t_1);
    __pyx_v_exit = __pyx_t_1;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    /* "memrise.pyx":196
 *         else:
 *             from sys import exit
 *             print('TypeError: Data type must be RECORD or the list of RECORDs')             # <<<<<<<<<<<<<<
 *             exit()
 * 
 */
    if (__Pyx_PrintOne(0, __pyx_kp_s_TypeError_Data_type_must_be_RECO) < 0) __PYX_ERR(0, 196, __pyx_L1_error)

    /* "memrise.pyx":197
 *             from sys import exit
 *             print('TypeError: Data type must be RECORD or the list of RECORDs')
 *             exit()             # <<<<<<<<<<<<<<
 * 
 *     def update_level(self,level:Level)-> None:
 */
    __Pyx_INCREF(__pyx_v_exit);
    __pyx_t_1 = __pyx_v_exit; __pyx_t_6 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_1, function);
      }
    }
    __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 197, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  }
  __pyx_L3:;

  /* "memrise.pyx":185
 *         self.conn.commit()
 * 
 *     def __update(self,cmd,data:Any):             # <<<<<<<<<<<<<<
 *         #Most implementation is bytes (char*) must be convert to str
 *         CMD = cmd.decode()
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("memrise.Data.__update", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_CMD);
  __Pyx_XDECREF(__pyx_v_record);
  __Pyx_XDECREF(__pyx_v_exit);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":199
 *             exit()
 * 
 *     def update_level(self,level:Level)-> None:             # <<<<<<<<<<<<<<
 *         __level = level.get_record()
 *         try:
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_9update_level(PyObject *__pyx_v_self, PyObject *__pyx_v_level); /*proto*/
static PyObject *__pyx_pw_7memrise_4Data_9update_level(PyObject *__pyx_v_self, PyObject *__pyx_v_level) {
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("update_level (wrapper)", 0);
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_level), __pyx_ptype_7memrise_Level, 1, "level", 0))) __PYX_ERR(0, 199, __pyx_L1_error)
  __pyx_r = __pyx_pf_7memrise_4Data_8update_level(((struct __pyx_obj_7memrise_Data *)__pyx_v_self), ((struct __pyx_obj_7memrise_Level *)__pyx_v_level));

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_8update_level(struct __pyx_obj_7memrise_Data *__pyx_v_self, struct __pyx_obj_7memrise_Level *__pyx_v_level) {
  PyObject *__pyx_v___level = NULL;
  CYTHON_UNUSED PyObject *__pyx_v___words = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  char const *__pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  int __pyx_t_16;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("update_level", 0);

  /* "memrise.pyx":200
 * 
 *     def update_level(self,level:Level)-> None:
 *         __level = level.get_record()             # <<<<<<<<<<<<<<
 *         try:
 *             self.__update(INSERT_LEVEL,__level)
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_level), __pyx_n_s_get_record); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v___level = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "memrise.pyx":201
 *     def update_level(self,level:Level)-> None:
 *         __level = level.get_record()
 *         try:             # <<<<<<<<<<<<<<
 *             self.__update(INSERT_LEVEL,__level)
 *         except:
 */
  /*try:*/ {
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_4, &__pyx_t_5, &__pyx_t_6);
      __Pyx_XGOTREF(__pyx_t_4);
      __Pyx_XGOTREF(__pyx_t_5);
      __Pyx_XGOTREF(__pyx_t_6);
      /*try:*/ {

        /* "memrise.pyx":202
 *         __level = level.get_record()
 *         try:
 *             self.__update(INSERT_LEVEL,__level)             # <<<<<<<<<<<<<<
 *         except:
 *             print('RecordError: Fail to update record',__level)
 */
        __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_self), __pyx_n_s_update); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 202, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = __Pyx_PyBytes_FromString(__pyx_v_7memrise_INSERT_LEVEL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 202, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_7 = NULL;
        __pyx_t_8 = 0;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
            __pyx_t_8 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_2)) {
          PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_3, __pyx_v___level};
          __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 202, __pyx_L6_error)
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
          PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_3, __pyx_v___level};
          __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 202, __pyx_L6_error)
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        } else
        #endif
        {
          __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 202, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_9);
          if (__pyx_t_7) {
            __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7); __pyx_t_7 = NULL;
          }
          __Pyx_GIVEREF(__pyx_t_3);
          PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_3);
          __Pyx_INCREF(__pyx_v___level);
          __Pyx_GIVEREF(__pyx_v___level);
          PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_v___level);
          __pyx_t_3 = 0;
          __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_9, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 202, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        }
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

        /* "memrise.pyx":201
 *     def update_level(self,level:Level)-> None:
 *         __level = level.get_record()
 *         try:             # <<<<<<<<<<<<<<
 *             self.__update(INSERT_LEVEL,__level)
 *         except:
 */
      }

      /* "memrise.pyx":206
 *             print('RecordError: Fail to update record',__level)
 *         else:
 *             self.conn.commit()             # <<<<<<<<<<<<<<
 *         finally:
 *             __words = level.get_words()
 */
      /*else:*/ {
        __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->conn, __pyx_n_s_commit); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 206, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_9 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_9)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_9);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_1 = (__pyx_t_9) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_9) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 206, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      }
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      goto __pyx_L11_try_end;
      __pyx_L6_error:;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

      /* "memrise.pyx":203
 *         try:
 *             self.__update(INSERT_LEVEL,__level)
 *         except:             # <<<<<<<<<<<<<<
 *             print('RecordError: Fail to update record',__level)
 *         else:
 */
      /*except:*/ {
        __Pyx_AddTraceback("memrise.Data.update_level", __pyx_clineno, __pyx_lineno, __pyx_filename);
        if (__Pyx_GetException(&__pyx_t_1, &__pyx_t_2, &__pyx_t_9) < 0) __PYX_ERR(0, 203, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_GOTREF(__pyx_t_9);

        /* "memrise.pyx":204
 *             self.__update(INSERT_LEVEL,__level)
 *         except:
 *             print('RecordError: Fail to update record',__level)             # <<<<<<<<<<<<<<
 *         else:
 *             self.conn.commit()
 */
        __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 204, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_INCREF(__pyx_kp_s_RecordError_Fail_to_update_recor);
        __Pyx_GIVEREF(__pyx_kp_s_RecordError_Fail_to_update_recor);
        PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_s_RecordError_Fail_to_update_recor);
        __Pyx_INCREF(__pyx_v___level);
        __Pyx_GIVEREF(__pyx_v___level);
        PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_v___level);
        if (__Pyx_PrintOne(0, __pyx_t_3) < 0) __PYX_ERR(0, 204, __pyx_L8_except_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        goto __pyx_L7_exception_handled;
      }
      __pyx_L8_except_error:;

      /* "memrise.pyx":201
 *     def update_level(self,level:Level)-> None:
 *         __level = level.get_record()
 *         try:             # <<<<<<<<<<<<<<
 *             self.__update(INSERT_LEVEL,__level)
 *         except:
 */
      __Pyx_XGIVEREF(__pyx_t_4);
      __Pyx_XGIVEREF(__pyx_t_5);
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
      goto __pyx_L4_error;
      __pyx_L7_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_4);
      __Pyx_XGIVEREF(__pyx_t_5);
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_ExceptionReset(__pyx_t_4, __pyx_t_5, __pyx_t_6);
      __pyx_L11_try_end:;
    }
  }

  /* "memrise.pyx":208
 *             self.conn.commit()
 *         finally:
 *             __words = level.get_words()             # <<<<<<<<<<<<<<
 *             self.__update(INSERT_WORD,level.get_words())
 * 
 */
  /*finally:*/ {
    /*normal exit:*/{
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_level), __pyx_n_s_get_words); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 208, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_1 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
        __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
        if (likely(__pyx_t_1)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
          __Pyx_INCREF(__pyx_t_1);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_2, function);
        }
      }
      __pyx_t_9 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 208, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_v___words = __pyx_t_9;
      __pyx_t_9 = 0;

      /* "memrise.pyx":209
 *         finally:
 *             __words = level.get_words()
 *             self.__update(INSERT_WORD,level.get_words())             # <<<<<<<<<<<<<<
 * 
 *     def update_course(self,course:Course)->None:
 */
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_self), __pyx_n_s_update); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 209, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_1 = __Pyx_PyBytes_FromString(__pyx_v_7memrise_INSERT_WORD); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 209, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_7 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_level), __pyx_n_s_get_words); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 209, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_10 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
        __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_7);
        if (likely(__pyx_t_10)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
          __Pyx_INCREF(__pyx_t_10);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_7, function);
        }
      }
      __pyx_t_3 = (__pyx_t_10) ? __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_10) : __Pyx_PyObject_CallNoArg(__pyx_t_7);
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 209, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __pyx_t_7 = NULL;
      __pyx_t_8 = 0;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
        __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_2);
        if (likely(__pyx_t_7)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
          __Pyx_INCREF(__pyx_t_7);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_2, function);
          __pyx_t_8 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_2)) {
        PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_1, __pyx_t_3};
        __pyx_t_9 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 209, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
        PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_1, __pyx_t_3};
        __pyx_t_9 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 209, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      } else
      #endif
      {
        __pyx_t_10 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 209, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_10);
        if (__pyx_t_7) {
          __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_7); __pyx_t_7 = NULL;
        }
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_8, __pyx_t_1);
        __Pyx_GIVEREF(__pyx_t_3);
        PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_8, __pyx_t_3);
        __pyx_t_1 = 0;
        __pyx_t_3 = 0;
        __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_10, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 209, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      }
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      goto __pyx_L5;
    }
    __pyx_L4_error:;
    /*exception exit:*/{
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __pyx_t_6 = 0; __pyx_t_5 = 0; __pyx_t_4 = 0; __pyx_t_13 = 0; __pyx_t_14 = 0; __pyx_t_15 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_13, &__pyx_t_14, &__pyx_t_15);
      if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_6, &__pyx_t_5, &__pyx_t_4) < 0)) __Pyx_ErrFetch(&__pyx_t_6, &__pyx_t_5, &__pyx_t_4);
      __Pyx_XGOTREF(__pyx_t_6);
      __Pyx_XGOTREF(__pyx_t_5);
      __Pyx_XGOTREF(__pyx_t_4);
      __Pyx_XGOTREF(__pyx_t_13);
      __Pyx_XGOTREF(__pyx_t_14);
      __Pyx_XGOTREF(__pyx_t_15);
      __pyx_t_8 = __pyx_lineno; __pyx_t_11 = __pyx_clineno; __pyx_t_12 = __pyx_filename;
      {

        /* "memrise.pyx":208
 *             self.conn.commit()
 *         finally:
 *             __words = level.get_words()             # <<<<<<<<<<<<<<
 *             self.__update(INSERT_WORD,level.get_words())
 * 
 */
        __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_level), __pyx_n_s_get_words); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 208, __pyx_L15_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_10)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_10);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_9 = (__pyx_t_10) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_10) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 208, __pyx_L15_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_v___words = __pyx_t_9;
        __pyx_t_9 = 0;

        /* "memrise.pyx":209
 *         finally:
 *             __words = level.get_words()
 *             self.__update(INSERT_WORD,level.get_words())             # <<<<<<<<<<<<<<
 * 
 *     def update_course(self,course:Course)->None:
 */
        __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_self), __pyx_n_s_update); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 209, __pyx_L15_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_10 = __Pyx_PyBytes_FromString(__pyx_v_7memrise_INSERT_WORD); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 209, __pyx_L15_error)
        __Pyx_GOTREF(__pyx_t_10);
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_level), __pyx_n_s_get_words); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 209, __pyx_L15_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_7 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_1, function);
          }
        }
        __pyx_t_3 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 209, __pyx_L15_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = NULL;
        __pyx_t_16 = 0;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_1)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_1);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
            __pyx_t_16 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_2)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_t_10, __pyx_t_3};
          __pyx_t_9 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_16, 2+__pyx_t_16); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 209, __pyx_L15_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
          PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_t_10, __pyx_t_3};
          __pyx_t_9 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_16, 2+__pyx_t_16); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 209, __pyx_L15_error)
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        } else
        #endif
        {
          __pyx_t_7 = PyTuple_New(2+__pyx_t_16); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 209, __pyx_L15_error)
          __Pyx_GOTREF(__pyx_t_7);
          if (__pyx_t_1) {
            __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_1); __pyx_t_1 = NULL;
          }
          __Pyx_GIVEREF(__pyx_t_10);
          PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_16, __pyx_t_10);
          __Pyx_GIVEREF(__pyx_t_3);
          PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_16, __pyx_t_3);
          __pyx_t_10 = 0;
          __pyx_t_3 = 0;
          __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_7, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 209, __pyx_L15_error)
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        }
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      }
      if (PY_MAJOR_VERSION >= 3) {
        __Pyx_XGIVEREF(__pyx_t_13);
        __Pyx_XGIVEREF(__pyx_t_14);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_ExceptionReset(__pyx_t_13, __pyx_t_14, __pyx_t_15);
      }
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_XGIVEREF(__pyx_t_5);
      __Pyx_XGIVEREF(__pyx_t_4);
      __Pyx_ErrRestore(__pyx_t_6, __pyx_t_5, __pyx_t_4);
      __pyx_t_6 = 0; __pyx_t_5 = 0; __pyx_t_4 = 0; __pyx_t_13 = 0; __pyx_t_14 = 0; __pyx_t_15 = 0;
      __pyx_lineno = __pyx_t_8; __pyx_clineno = __pyx_t_11; __pyx_filename = __pyx_t_12;
      goto __pyx_L1_error;
      __pyx_L15_error:;
      if (PY_MAJOR_VERSION >= 3) {
        __Pyx_XGIVEREF(__pyx_t_13);
        __Pyx_XGIVEREF(__pyx_t_14);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_ExceptionReset(__pyx_t_13, __pyx_t_14, __pyx_t_15);
      }
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_13 = 0; __pyx_t_14 = 0; __pyx_t_15 = 0;
      goto __pyx_L1_error;
    }
    __pyx_L5:;
  }

  /* "memrise.pyx":199
 *             exit()
 * 
 *     def update_level(self,level:Level)-> None:             # <<<<<<<<<<<<<<
 *         __level = level.get_record()
 *         try:
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_AddTraceback("memrise.Data.update_level", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v___level);
  __Pyx_XDECREF(__pyx_v___words);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":211
 *             self.__update(INSERT_WORD,level.get_words())
 * 
 *     def update_course(self,course:Course)->None:             # <<<<<<<<<<<<<<
 *         try:
 *             __course = course.get_record()
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_11update_course(PyObject *__pyx_v_self, PyObject *__pyx_v_course); /*proto*/
static PyObject *__pyx_pw_7memrise_4Data_11update_course(PyObject *__pyx_v_self, PyObject *__pyx_v_course) {
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("update_course (wrapper)", 0);
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_course), __pyx_ptype_7memrise_Course, 1, "course", 0))) __PYX_ERR(0, 211, __pyx_L1_error)
  __pyx_r = __pyx_pf_7memrise_4Data_10update_course(((struct __pyx_obj_7memrise_Data *)__pyx_v_self), ((struct __pyx_obj_7memrise_Course *)__pyx_v_course));

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_10update_course(struct __pyx_obj_7memrise_Data *__pyx_v_self, struct __pyx_obj_7memrise_Course *__pyx_v_course) {
  PyObject *__pyx_v___course = NULL;
  PyObject *__pyx_v_levels = NULL;
  PyObject *__pyx_v_level = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  Py_ssize_t __pyx_t_11;
  PyObject *(*__pyx_t_12)(PyObject *);
  int __pyx_t_13;
  char const *__pyx_t_14;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("update_course", 0);

  /* "memrise.pyx":212
 * 
 *     def update_course(self,course:Course)->None:
 *         try:             # <<<<<<<<<<<<<<
 *             __course = course.get_record()
 *             self.__update(INSERT_COURSE,__course)
 */
  /*try:*/ {
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
      __Pyx_XGOTREF(__pyx_t_1);
      __Pyx_XGOTREF(__pyx_t_2);
      __Pyx_XGOTREF(__pyx_t_3);
      /*try:*/ {

        /* "memrise.pyx":213
 *     def update_course(self,course:Course)->None:
 *         try:
 *             __course = course.get_record()             # <<<<<<<<<<<<<<
 *             self.__update(INSERT_COURSE,__course)
 *         except:
 */
        __pyx_t_5 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_course), __pyx_n_s_get_record); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 213, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_6 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
          __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
          if (likely(__pyx_t_6)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
            __Pyx_INCREF(__pyx_t_6);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_5, function);
          }
        }
        __pyx_t_4 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
        if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 213, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __pyx_v___course = __pyx_t_4;
        __pyx_t_4 = 0;

        /* "memrise.pyx":214
 *         try:
 *             __course = course.get_record()
 *             self.__update(INSERT_COURSE,__course)             # <<<<<<<<<<<<<<
 *         except:
 *             print('RecordError: Fail to update record',course.get_record())
 */
        __pyx_t_5 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_self), __pyx_n_s_update); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 214, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_6 = __Pyx_PyBytes_FromString(__pyx_v_7memrise_INSERT_COURSE); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 214, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_7 = NULL;
        __pyx_t_8 = 0;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_5);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_5, function);
            __pyx_t_8 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_5)) {
          PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_6, __pyx_v___course};
          __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 214, __pyx_L6_error)
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
          PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_6, __pyx_v___course};
          __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 214, __pyx_L6_error)
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        } else
        #endif
        {
          __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 214, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_9);
          if (__pyx_t_7) {
            __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7); __pyx_t_7 = NULL;
          }
          __Pyx_GIVEREF(__pyx_t_6);
          PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_6);
          __Pyx_INCREF(__pyx_v___course);
          __Pyx_GIVEREF(__pyx_v___course);
          PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_v___course);
          __pyx_t_6 = 0;
          __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_9, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 214, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        }
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

        /* "memrise.pyx":212
 * 
 *     def update_course(self,course:Course)->None:
 *         try:             # <<<<<<<<<<<<<<
 *             __course = course.get_record()
 *             self.__update(INSERT_COURSE,__course)
 */
      }

      /* "memrise.pyx":218
 *             print('RecordError: Fail to update record',course.get_record())
 *         else:
 *             self.conn.commit()             # <<<<<<<<<<<<<<
 *         finally:
 *             levels = course.get_levels()
 */
      /*else:*/ {
        __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->conn, __pyx_n_s_commit); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 218, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_9 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
          __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_5);
          if (likely(__pyx_t_9)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
            __Pyx_INCREF(__pyx_t_9);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_5, function);
          }
        }
        __pyx_t_4 = (__pyx_t_9) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_9) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 218, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      }
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      goto __pyx_L11_try_end;
      __pyx_L6_error:;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

      /* "memrise.pyx":215
 *             __course = course.get_record()
 *             self.__update(INSERT_COURSE,__course)
 *         except:             # <<<<<<<<<<<<<<
 *             print('RecordError: Fail to update record',course.get_record())
 *         else:
 */
      /*except:*/ {
        __Pyx_AddTraceback("memrise.Data.update_course", __pyx_clineno, __pyx_lineno, __pyx_filename);
        if (__Pyx_GetException(&__pyx_t_4, &__pyx_t_5, &__pyx_t_9) < 0) __PYX_ERR(0, 215, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_GOTREF(__pyx_t_9);

        /* "memrise.pyx":216
 *             self.__update(INSERT_COURSE,__course)
 *         except:
 *             print('RecordError: Fail to update record',course.get_record())             # <<<<<<<<<<<<<<
 *         else:
 *             self.conn.commit()
 */
        __pyx_t_7 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_course), __pyx_n_s_get_record); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 216, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_10 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
          __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_7);
          if (likely(__pyx_t_10)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
            __Pyx_INCREF(__pyx_t_10);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_7, function);
          }
        }
        __pyx_t_6 = (__pyx_t_10) ? __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_10) : __Pyx_PyObject_CallNoArg(__pyx_t_7);
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 216, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __pyx_t_7 = PyTuple_New(2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 216, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_INCREF(__pyx_kp_s_RecordError_Fail_to_update_recor);
        __Pyx_GIVEREF(__pyx_kp_s_RecordError_Fail_to_update_recor);
        PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_kp_s_RecordError_Fail_to_update_recor);
        __Pyx_GIVEREF(__pyx_t_6);
        PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_6);
        __pyx_t_6 = 0;
        if (__Pyx_PrintOne(0, __pyx_t_7) < 0) __PYX_ERR(0, 216, __pyx_L8_except_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        goto __pyx_L7_exception_handled;
      }
      __pyx_L8_except_error:;

      /* "memrise.pyx":212
 * 
 *     def update_course(self,course:Course)->None:
 *         try:             # <<<<<<<<<<<<<<
 *             __course = course.get_record()
 *             self.__update(INSERT_COURSE,__course)
 */
      __Pyx_XGIVEREF(__pyx_t_1);
      __Pyx_XGIVEREF(__pyx_t_2);
      __Pyx_XGIVEREF(__pyx_t_3);
      __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
      goto __pyx_L4_error;
      __pyx_L7_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_1);
      __Pyx_XGIVEREF(__pyx_t_2);
      __Pyx_XGIVEREF(__pyx_t_3);
      __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
      __pyx_L11_try_end:;
    }
  }

  /* "memrise.pyx":220
 *             self.conn.commit()
 *         finally:
 *             levels = course.get_levels()             # <<<<<<<<<<<<<<
 *             for level in levels:
 *                 self.update_level(level)
 */
  /*finally:*/ {
    /*normal exit:*/{
      __pyx_t_5 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_course), __pyx_n_s_get_levels_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 220, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_4 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
        __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_5);
        if (likely(__pyx_t_4)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
          __Pyx_INCREF(__pyx_t_4);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_5, function);
        }
      }
      __pyx_t_9 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 220, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_v_levels = __pyx_t_9;
      __pyx_t_9 = 0;

      /* "memrise.pyx":221
 *         finally:
 *             levels = course.get_levels()
 *             for level in levels:             # <<<<<<<<<<<<<<
 *                 self.update_level(level)
 *                 self.conn.commit()
 */
      if (likely(PyList_CheckExact(__pyx_v_levels)) || PyTuple_CheckExact(__pyx_v_levels)) {
        __pyx_t_9 = __pyx_v_levels; __Pyx_INCREF(__pyx_t_9); __pyx_t_11 = 0;
        __pyx_t_12 = NULL;
      } else {
        __pyx_t_11 = -1; __pyx_t_9 = PyObject_GetIter(__pyx_v_levels); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 221, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_9);
        __pyx_t_12 = Py_TYPE(__pyx_t_9)->tp_iternext; if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 221, __pyx_L1_error)
      }
      for (;;) {
        if (likely(!__pyx_t_12)) {
          if (likely(PyList_CheckExact(__pyx_t_9))) {
            if (__pyx_t_11 >= PyList_GET_SIZE(__pyx_t_9)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_5 = PyList_GET_ITEM(__pyx_t_9, __pyx_t_11); __Pyx_INCREF(__pyx_t_5); __pyx_t_11++; if (unlikely(0 < 0)) __PYX_ERR(0, 221, __pyx_L1_error)
            #else
            __pyx_t_5 = PySequence_ITEM(__pyx_t_9, __pyx_t_11); __pyx_t_11++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 221, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            #endif
          } else {
            if (__pyx_t_11 >= PyTuple_GET_SIZE(__pyx_t_9)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_5 = PyTuple_GET_ITEM(__pyx_t_9, __pyx_t_11); __Pyx_INCREF(__pyx_t_5); __pyx_t_11++; if (unlikely(0 < 0)) __PYX_ERR(0, 221, __pyx_L1_error)
            #else
            __pyx_t_5 = PySequence_ITEM(__pyx_t_9, __pyx_t_11); __pyx_t_11++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 221, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            #endif
          }
        } else {
          __pyx_t_5 = __pyx_t_12(__pyx_t_9);
          if (unlikely(!__pyx_t_5)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 221, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_5);
        }
        __Pyx_XDECREF_SET(__pyx_v_level, __pyx_t_5);
        __pyx_t_5 = 0;

        /* "memrise.pyx":222
 *             levels = course.get_levels()
 *             for level in levels:
 *                 self.update_level(level)             # <<<<<<<<<<<<<<
 *                 self.conn.commit()
 * 
 */
        __pyx_t_4 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_self), __pyx_n_s_update_level); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 222, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        __pyx_t_7 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_4);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_4, function);
          }
        }
        __pyx_t_5 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_7, __pyx_v_level) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_v_level);
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 222, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

        /* "memrise.pyx":223
 *             for level in levels:
 *                 self.update_level(level)
 *                 self.conn.commit()             # <<<<<<<<<<<<<<
 * 
 *     def update_db(self,speaker):
 */
        __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->conn, __pyx_n_s_commit); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 223, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        __pyx_t_7 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_4);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_4, function);
          }
        }
        __pyx_t_5 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 223, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

        /* "memrise.pyx":221
 *         finally:
 *             levels = course.get_levels()
 *             for level in levels:             # <<<<<<<<<<<<<<
 *                 self.update_level(level)
 *                 self.conn.commit()
 */
      }
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      goto __pyx_L5;
    }
    __pyx_L4_error:;
    /*exception exit:*/{
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __pyx_t_3 = 0; __pyx_t_2 = 0; __pyx_t_1 = 0; __pyx_t_15 = 0; __pyx_t_16 = 0; __pyx_t_17 = 0;
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17);
      if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_3, &__pyx_t_2, &__pyx_t_1) < 0)) __Pyx_ErrFetch(&__pyx_t_3, &__pyx_t_2, &__pyx_t_1);
      __Pyx_XGOTREF(__pyx_t_3);
      __Pyx_XGOTREF(__pyx_t_2);
      __Pyx_XGOTREF(__pyx_t_1);
      __Pyx_XGOTREF(__pyx_t_15);
      __Pyx_XGOTREF(__pyx_t_16);
      __Pyx_XGOTREF(__pyx_t_17);
      __pyx_t_8 = __pyx_lineno; __pyx_t_13 = __pyx_clineno; __pyx_t_14 = __pyx_filename;
      {

        /* "memrise.pyx":220
 *             self.conn.commit()
 *         finally:
 *             levels = course.get_levels()             # <<<<<<<<<<<<<<
 *             for level in levels:
 *                 self.update_level(level)
 */
        __pyx_t_5 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_course), __pyx_n_s_get_levels_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 220, __pyx_L17_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_4 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
          __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_5);
          if (likely(__pyx_t_4)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
            __Pyx_INCREF(__pyx_t_4);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_5, function);
          }
        }
        __pyx_t_9 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 220, __pyx_L17_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __pyx_v_levels = __pyx_t_9;
        __pyx_t_9 = 0;

        /* "memrise.pyx":221
 *         finally:
 *             levels = course.get_levels()
 *             for level in levels:             # <<<<<<<<<<<<<<
 *                 self.update_level(level)
 *                 self.conn.commit()
 */
        if (likely(PyList_CheckExact(__pyx_v_levels)) || PyTuple_CheckExact(__pyx_v_levels)) {
          __pyx_t_9 = __pyx_v_levels; __Pyx_INCREF(__pyx_t_9); __pyx_t_11 = 0;
          __pyx_t_12 = NULL;
        } else {
          __pyx_t_11 = -1; __pyx_t_9 = PyObject_GetIter(__pyx_v_levels); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 221, __pyx_L17_error)
          __Pyx_GOTREF(__pyx_t_9);
          __pyx_t_12 = Py_TYPE(__pyx_t_9)->tp_iternext; if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 221, __pyx_L17_error)
        }
        for (;;) {
          if (likely(!__pyx_t_12)) {
            if (likely(PyList_CheckExact(__pyx_t_9))) {
              if (__pyx_t_11 >= PyList_GET_SIZE(__pyx_t_9)) break;
              #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
              __pyx_t_5 = PyList_GET_ITEM(__pyx_t_9, __pyx_t_11); __Pyx_INCREF(__pyx_t_5); __pyx_t_11++; if (unlikely(0 < 0)) __PYX_ERR(0, 221, __pyx_L17_error)
              #else
              __pyx_t_5 = PySequence_ITEM(__pyx_t_9, __pyx_t_11); __pyx_t_11++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 221, __pyx_L17_error)
              __Pyx_GOTREF(__pyx_t_5);
              #endif
            } else {
              if (__pyx_t_11 >= PyTuple_GET_SIZE(__pyx_t_9)) break;
              #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
              __pyx_t_5 = PyTuple_GET_ITEM(__pyx_t_9, __pyx_t_11); __Pyx_INCREF(__pyx_t_5); __pyx_t_11++; if (unlikely(0 < 0)) __PYX_ERR(0, 221, __pyx_L17_error)
              #else
              __pyx_t_5 = PySequence_ITEM(__pyx_t_9, __pyx_t_11); __pyx_t_11++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 221, __pyx_L17_error)
              __Pyx_GOTREF(__pyx_t_5);
              #endif
            }
          } else {
            __pyx_t_5 = __pyx_t_12(__pyx_t_9);
            if (unlikely(!__pyx_t_5)) {
              PyObject* exc_type = PyErr_Occurred();
              if (exc_type) {
                if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                else __PYX_ERR(0, 221, __pyx_L17_error)
              }
              break;
            }
            __Pyx_GOTREF(__pyx_t_5);
          }
          __Pyx_XDECREF_SET(__pyx_v_level, __pyx_t_5);
          __pyx_t_5 = 0;

          /* "memrise.pyx":222
 *             levels = course.get_levels()
 *             for level in levels:
 *                 self.update_level(level)             # <<<<<<<<<<<<<<
 *                 self.conn.commit()
 * 
 */
          __pyx_t_4 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_self), __pyx_n_s_update_level); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 222, __pyx_L17_error)
          __Pyx_GOTREF(__pyx_t_4);
          __pyx_t_7 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_4);
            if (likely(__pyx_t_7)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
              __Pyx_INCREF(__pyx_t_7);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_4, function);
            }
          }
          __pyx_t_5 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_7, __pyx_v_level) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_v_level);
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 222, __pyx_L17_error)
          __Pyx_GOTREF(__pyx_t_5);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

          /* "memrise.pyx":223
 *             for level in levels:
 *                 self.update_level(level)
 *                 self.conn.commit()             # <<<<<<<<<<<<<<
 * 
 *     def update_db(self,speaker):
 */
          __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->conn, __pyx_n_s_commit); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 223, __pyx_L17_error)
          __Pyx_GOTREF(__pyx_t_4);
          __pyx_t_7 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_4);
            if (likely(__pyx_t_7)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
              __Pyx_INCREF(__pyx_t_7);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_4, function);
            }
          }
          __pyx_t_5 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 223, __pyx_L17_error)
          __Pyx_GOTREF(__pyx_t_5);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

          /* "memrise.pyx":221
 *         finally:
 *             levels = course.get_levels()
 *             for level in levels:             # <<<<<<<<<<<<<<
 *                 self.update_level(level)
 *                 self.conn.commit()
 */
        }
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      }
      if (PY_MAJOR_VERSION >= 3) {
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_XGIVEREF(__pyx_t_17);
        __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
      }
      __Pyx_XGIVEREF(__pyx_t_3);
      __Pyx_XGIVEREF(__pyx_t_2);
      __Pyx_XGIVEREF(__pyx_t_1);
      __Pyx_ErrRestore(__pyx_t_3, __pyx_t_2, __pyx_t_1);
      __pyx_t_3 = 0; __pyx_t_2 = 0; __pyx_t_1 = 0; __pyx_t_15 = 0; __pyx_t_16 = 0; __pyx_t_17 = 0;
      __pyx_lineno = __pyx_t_8; __pyx_clineno = __pyx_t_13; __pyx_filename = __pyx_t_14;
      goto __pyx_L1_error;
      __pyx_L17_error:;
      if (PY_MAJOR_VERSION >= 3) {
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_XGIVEREF(__pyx_t_17);
        __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
      }
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_15 = 0; __pyx_t_16 = 0; __pyx_t_17 = 0;
      goto __pyx_L1_error;
    }
    __pyx_L5:;
  }

  /* "memrise.pyx":211
 *             self.__update(INSERT_WORD,level.get_words())
 * 
 *     def update_course(self,course:Course)->None:             # <<<<<<<<<<<<<<
 *         try:
 *             __course = course.get_record()
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_AddTraceback("memrise.Data.update_course", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v___course);
  __Pyx_XDECREF(__pyx_v_levels);
  __Pyx_XDECREF(__pyx_v_level);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":225
 *                 self.conn.commit()
 * 
 *     def update_db(self,speaker):             # <<<<<<<<<<<<<<
 *         '''This function will be implemented in next release'''
 *         print('This function will be implemented in next release.')
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_13update_db(PyObject *__pyx_v_self, PyObject *__pyx_v_speaker); /*proto*/
static char __pyx_doc_7memrise_4Data_12update_db[] = "This function will be implemented in next release";
static PyObject *__pyx_pw_7memrise_4Data_13update_db(PyObject *__pyx_v_self, PyObject *__pyx_v_speaker) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("update_db (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_4Data_12update_db(((struct __pyx_obj_7memrise_Data *)__pyx_v_self), ((PyObject *)__pyx_v_speaker));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_12update_db(CYTHON_UNUSED struct __pyx_obj_7memrise_Data *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_speaker) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("update_db", 0);

  /* "memrise.pyx":227
 *     def update_db(self,speaker):
 *         '''This function will be implemented in next release'''
 *         print('This function will be implemented in next release.')             # <<<<<<<<<<<<<<
 *         ...
 * 
 */
  if (__Pyx_PrintOne(0, __pyx_kp_s_This_function_will_be_implemente) < 0) __PYX_ERR(0, 227, __pyx_L1_error)

  /* "memrise.pyx":225
 *                 self.conn.commit()
 * 
 *     def update_db(self,speaker):             # <<<<<<<<<<<<<<
 *         '''This function will be implemented in next release'''
 *         print('This function will be implemented in next release.')
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("memrise.Data.update_db", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":230
 *         ...
 * 
 *     def update_db_en(self,course_id,speaker):             # <<<<<<<<<<<<<<
 *         '''This function will be implemeted in next release'''
 *         print('This function will be implemented in next release.')
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_15update_db_en(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_7memrise_4Data_14update_db_en[] = "This function will be implemeted in next release";
static PyObject *__pyx_pw_7memrise_4Data_15update_db_en(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_course_id = 0;
  CYTHON_UNUSED PyObject *__pyx_v_speaker = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("update_db_en (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_course_id,&__pyx_n_s_speaker,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_course_id)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_speaker)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("update_db_en", 1, 2, 2, 1); __PYX_ERR(0, 230, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "update_db_en") < 0)) __PYX_ERR(0, 230, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_course_id = values[0];
    __pyx_v_speaker = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("update_db_en", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 230, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("memrise.Data.update_db_en", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_7memrise_4Data_14update_db_en(((struct __pyx_obj_7memrise_Data *)__pyx_v_self), __pyx_v_course_id, __pyx_v_speaker);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_14update_db_en(CYTHON_UNUSED struct __pyx_obj_7memrise_Data *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_course_id, CYTHON_UNUSED PyObject *__pyx_v_speaker) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("update_db_en", 0);

  /* "memrise.pyx":232
 *     def update_db_en(self,course_id,speaker):
 *         '''This function will be implemeted in next release'''
 *         print('This function will be implemented in next release.')             # <<<<<<<<<<<<<<
 *         ...
 * 
 */
  if (__Pyx_PrintOne(0, __pyx_kp_s_This_function_will_be_implemente) < 0) __PYX_ERR(0, 232, __pyx_L1_error)

  /* "memrise.pyx":230
 *         ...
 * 
 *     def update_db_en(self,course_id,speaker):             # <<<<<<<<<<<<<<
 *         '''This function will be implemeted in next release'''
 *         print('This function will be implemented in next release.')
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("memrise.Data.update_db_en", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "memrise.pyx":235
 *         ...
 * 
 *     def close(self):             # <<<<<<<<<<<<<<
 *         ''''''
 *         self.conn.commit()
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_17close(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyObject *__pyx_pw_7memrise_4Data_17close(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("close (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_4Data_16close(((struct __pyx_obj_7memrise_Data *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_16close(struct __pyx_obj_7memrise_Data *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("close", 0);

  /* "memrise.pyx":237
 *     def close(self):
 *         ''''''
 *         self.conn.commit()             # <<<<<<<<<<<<<<
 *         self.cur.close()
 *         self.conn.close()
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->conn, __pyx_n_s_commit); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "memrise.pyx":238
 *         ''''''
 *         self.conn.commit()
 *         self.cur.close()             # <<<<<<<<<<<<<<
 *         self.conn.close()
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->cur, __pyx_n_s_close); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "memrise.pyx":239
 *         self.conn.commit()
 *         self.cur.close()
 *         self.conn.close()             # <<<<<<<<<<<<<<
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self->conn, __pyx_n_s_close); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "memrise.pyx":235
 *         ...
 * 
 *     def close(self):             # <<<<<<<<<<<<<<
 *         ''''''
 *         self.conn.commit()
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("memrise.Data.close", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "(tree fragment)":1
 * def __reduce_cython__(self):             # <<<<<<<<<<<<<<
 *     cdef tuple state
 *     cdef object _dict
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_19__reduce_cython__(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyObject *__pyx_pw_7memrise_4Data_19__reduce_cython__(PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__reduce_cython__ (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_4Data_18__reduce_cython__(((struct __pyx_obj_7memrise_Data *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_18__reduce_cython__(struct __pyx_obj_7memrise_Data *__pyx_v_self) {
  PyObject *__pyx_v_state = 0;
  PyObject *__pyx_v__dict = 0;
  int __pyx_v_use_setstate;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  int __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__reduce_cython__", 0);

  /* "(tree fragment)":5
 *     cdef object _dict
 *     cdef bint use_setstate
 *     state = (self.conn, self.cur)             # <<<<<<<<<<<<<<
 *     _dict = getattr(self, '__dict__', None)
 *     if _dict is not None:
 */
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_self->conn);
  __Pyx_GIVEREF(__pyx_v_self->conn);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_self->conn);
  __Pyx_INCREF(__pyx_v_self->cur);
  __Pyx_GIVEREF(__pyx_v_self->cur);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_v_self->cur);
  __pyx_v_state = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "(tree fragment)":6
 *     cdef bint use_setstate
 *     state = (self.conn, self.cur)
 *     _dict = getattr(self, '__dict__', None)             # <<<<<<<<<<<<<<
 *     if _dict is not None:
 *         state += (_dict,)
 */
  __pyx_t_1 = __Pyx_GetAttr3(((PyObject *)__pyx_v_self), __pyx_n_s_dict, Py_None); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v__dict = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "(tree fragment)":7
 *     state = (self.conn, self.cur)
 *     _dict = getattr(self, '__dict__', None)
 *     if _dict is not None:             # <<<<<<<<<<<<<<
 *         state += (_dict,)
 *         use_setstate = True
 */
  __pyx_t_2 = (__pyx_v__dict != Py_None);
  __pyx_t_3 = (__pyx_t_2 != 0);
  if (__pyx_t_3) {

    /* "(tree fragment)":8
 *     _dict = getattr(self, '__dict__', None)
 *     if _dict is not None:
 *         state += (_dict,)             # <<<<<<<<<<<<<<
 *         use_setstate = True
 *     else:
 */
    __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 8, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v__dict);
    __Pyx_GIVEREF(__pyx_v__dict);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v__dict);
    __pyx_t_4 = PyNumber_InPlaceAdd(__pyx_v_state, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 8, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF_SET(__pyx_v_state, ((PyObject*)__pyx_t_4));
    __pyx_t_4 = 0;

    /* "(tree fragment)":9
 *     if _dict is not None:
 *         state += (_dict,)
 *         use_setstate = True             # <<<<<<<<<<<<<<
 *     else:
 *         use_setstate = self.conn is not None or self.cur is not None
 */
    __pyx_v_use_setstate = 1;

    /* "(tree fragment)":7
 *     state = (self.conn, self.cur)
 *     _dict = getattr(self, '__dict__', None)
 *     if _dict is not None:             # <<<<<<<<<<<<<<
 *         state += (_dict,)
 *         use_setstate = True
 */
    goto __pyx_L3;
  }

  /* "(tree fragment)":11
 *         use_setstate = True
 *     else:
 *         use_setstate = self.conn is not None or self.cur is not None             # <<<<<<<<<<<<<<
 *     if use_setstate:
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, None), state
 */
  /*else*/ {
    __pyx_t_2 = (__pyx_v_self->conn != Py_None);
    __pyx_t_5 = (__pyx_t_2 != 0);
    if (!__pyx_t_5) {
    } else {
      __pyx_t_3 = __pyx_t_5;
      goto __pyx_L4_bool_binop_done;
    }
    __pyx_t_5 = (__pyx_v_self->cur != Py_None);
    __pyx_t_2 = (__pyx_t_5 != 0);
    __pyx_t_3 = __pyx_t_2;
    __pyx_L4_bool_binop_done:;
    __pyx_v_use_setstate = __pyx_t_3;
  }
  __pyx_L3:;

  /* "(tree fragment)":12
 *     else:
 *         use_setstate = self.conn is not None or self.cur is not None
 *     if use_setstate:             # <<<<<<<<<<<<<<
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, None), state
 *     else:
 */
  __pyx_t_3 = (__pyx_v_use_setstate != 0);
  if (__pyx_t_3) {

    /* "(tree fragment)":13
 *         use_setstate = self.conn is not None or self.cur is not None
 *     if use_setstate:
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, None), state             # <<<<<<<<<<<<<<
 *     else:
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, state)
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_pyx_unpickle_Data); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 13, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 13, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(((PyObject *)Py_TYPE(((PyObject *)__pyx_v_self))));
    __Pyx_GIVEREF(((PyObject *)Py_TYPE(((PyObject *)__pyx_v_self))));
    PyTuple_SET_ITEM(__pyx_t_1, 0, ((PyObject *)Py_TYPE(((PyObject *)__pyx_v_self))));
    __Pyx_INCREF(__pyx_int_62206863);
    __Pyx_GIVEREF(__pyx_int_62206863);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_62206863);
    __Pyx_INCREF(Py_None);
    __Pyx_GIVEREF(Py_None);
    PyTuple_SET_ITEM(__pyx_t_1, 2, Py_None);
    __pyx_t_6 = PyTuple_New(3); if (unlikely(!__pyx_t_6)) __PYX_ERR(1, 13, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_1);
    __Pyx_INCREF(__pyx_v_state);
    __Pyx_GIVEREF(__pyx_v_state);
    PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_v_state);
    __pyx_t_4 = 0;
    __pyx_t_1 = 0;
    __pyx_r = __pyx_t_6;
    __pyx_t_6 = 0;
    goto __pyx_L0;

    /* "(tree fragment)":12
 *     else:
 *         use_setstate = self.conn is not None or self.cur is not None
 *     if use_setstate:             # <<<<<<<<<<<<<<
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, None), state
 *     else:
 */
  }

  /* "(tree fragment)":15
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, None), state
 *     else:
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, state)             # <<<<<<<<<<<<<<
 * def __setstate_cython__(self, __pyx_state):
 *     __pyx_unpickle_Data__set_state(self, __pyx_state)
 */
  /*else*/ {
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_pyx_unpickle_Data); if (unlikely(!__pyx_t_6)) __PYX_ERR(1, 15, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 15, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(((PyObject *)Py_TYPE(((PyObject *)__pyx_v_self))));
    __Pyx_GIVEREF(((PyObject *)Py_TYPE(((PyObject *)__pyx_v_self))));
    PyTuple_SET_ITEM(__pyx_t_1, 0, ((PyObject *)Py_TYPE(((PyObject *)__pyx_v_self))));
    __Pyx_INCREF(__pyx_int_62206863);
    __Pyx_GIVEREF(__pyx_int_62206863);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_62206863);
    __Pyx_INCREF(__pyx_v_state);
    __Pyx_GIVEREF(__pyx_v_state);
    PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_v_state);
    __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 15, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_1);
    __pyx_t_6 = 0;
    __pyx_t_1 = 0;
    __pyx_r = __pyx_t_4;
    __pyx_t_4 = 0;
    goto __pyx_L0;
  }

  /* "(tree fragment)":1
 * def __reduce_cython__(self):             # <<<<<<<<<<<<<<
 *     cdef tuple state
 *     cdef object _dict
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("memrise.Data.__reduce_cython__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_state);
  __Pyx_XDECREF(__pyx_v__dict);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "(tree fragment)":16
 *     else:
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, state)
 * def __setstate_cython__(self, __pyx_state):             # <<<<<<<<<<<<<<
 *     __pyx_unpickle_Data__set_state(self, __pyx_state)
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_4Data_21__setstate_cython__(PyObject *__pyx_v_self, PyObject *__pyx_v___pyx_state); /*proto*/
static PyObject *__pyx_pw_7memrise_4Data_21__setstate_cython__(PyObject *__pyx_v_self, PyObject *__pyx_v___pyx_state) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__setstate_cython__ (wrapper)", 0);
  __pyx_r = __pyx_pf_7memrise_4Data_20__setstate_cython__(((struct __pyx_obj_7memrise_Data *)__pyx_v_self), ((PyObject *)__pyx_v___pyx_state));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise_4Data_20__setstate_cython__(struct __pyx_obj_7memrise_Data *__pyx_v_self, PyObject *__pyx_v___pyx_state) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__setstate_cython__", 0);

  /* "(tree fragment)":17
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, state)
 * def __setstate_cython__(self, __pyx_state):
 *     __pyx_unpickle_Data__set_state(self, __pyx_state)             # <<<<<<<<<<<<<<
 */
  if (!(likely(PyTuple_CheckExact(__pyx_v___pyx_state))||((__pyx_v___pyx_state) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "tuple", Py_TYPE(__pyx_v___pyx_state)->tp_name), 0))) __PYX_ERR(1, 17, __pyx_L1_error)
  __pyx_t_1 = __pyx_f_7memrise___pyx_unpickle_Data__set_state(__pyx_v_self, ((PyObject*)__pyx_v___pyx_state)); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "(tree fragment)":16
 *     else:
 *         return __pyx_unpickle_Data, (type(self), 0x3b5338f, state)
 * def __setstate_cython__(self, __pyx_state):             # <<<<<<<<<<<<<<
 *     __pyx_unpickle_Data__set_state(self, __pyx_state)
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("memrise.Data.__setstate_cython__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "(tree fragment)":1
 * def __pyx_unpickle_Data(__pyx_type, long __pyx_checksum, __pyx_state):             # <<<<<<<<<<<<<<
 *     cdef object __pyx_PickleError
 *     cdef object __pyx_result
 */

/* Python wrapper */
static PyObject *__pyx_pw_7memrise_1__pyx_unpickle_Data(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_7memrise_1__pyx_unpickle_Data = {"__pyx_unpickle_Data", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_7memrise_1__pyx_unpickle_Data, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_7memrise_1__pyx_unpickle_Data(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v___pyx_type = 0;
  long __pyx_v___pyx_checksum;
  PyObject *__pyx_v___pyx_state = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__pyx_unpickle_Data (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_pyx_type,&__pyx_n_s_pyx_checksum,&__pyx_n_s_pyx_state,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pyx_type)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pyx_checksum)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__pyx_unpickle_Data", 1, 3, 3, 1); __PYX_ERR(1, 1, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pyx_state)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__pyx_unpickle_Data", 1, 3, 3, 2); __PYX_ERR(1, 1, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__pyx_unpickle_Data") < 0)) __PYX_ERR(1, 1, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v___pyx_type = values[0];
    __pyx_v___pyx_checksum = __Pyx_PyInt_As_long(values[1]); if (unlikely((__pyx_v___pyx_checksum == (long)-1) && PyErr_Occurred())) __PYX_ERR(1, 1, __pyx_L3_error)
    __pyx_v___pyx_state = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__pyx_unpickle_Data", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(1, 1, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("memrise.__pyx_unpickle_Data", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_7memrise___pyx_unpickle_Data(__pyx_self, __pyx_v___pyx_type, __pyx_v___pyx_checksum, __pyx_v___pyx_state);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7memrise___pyx_unpickle_Data(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v___pyx_type, long __pyx_v___pyx_checksum, PyObject *__pyx_v___pyx_state) {
  PyObject *__pyx_v___pyx_PickleError = 0;
  PyObject *__pyx_v___pyx_result = 0;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__pyx_unpickle_Data", 0);

  /* "(tree fragment)":4
 *     cdef object __pyx_PickleError
 *     cdef object __pyx_result
 *     if __pyx_checksum != 0x3b5338f:             # <<<<<<<<<<<<<<
 *         from pickle import PickleError as __pyx_PickleError
 *         raise __pyx_PickleError("Incompatible checksums (%s vs 0x3b5338f = (conn, cur))" % __pyx_checksum)
 */
  __pyx_t_1 = ((__pyx_v___pyx_checksum != 0x3b5338f) != 0);
  if (__pyx_t_1) {

    /* "(tree fragment)":5
 *     cdef object __pyx_result
 *     if __pyx_checksum != 0x3b5338f:
 *         from pickle import PickleError as __pyx_PickleError             # <<<<<<<<<<<<<<
 *         raise __pyx_PickleError("Incompatible checksums (%s vs 0x3b5338f = (conn, cur))" % __pyx_checksum)
 *     __pyx_result = Data.__new__(__pyx_type)
 */
    __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(1, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_n_s_PickleError);
    __Pyx_GIVEREF(__pyx_n_s_PickleError);
    PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_PickleError);
    __pyx_t_3 = __Pyx_Import(__pyx_n_s_pickle, __pyx_t_2, -1); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_3, __pyx_n_s_PickleError); if (unlikely(!__pyx_t_2)) __PYX_ERR(1, 5, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_INCREF(__pyx_t_2);
    __pyx_v___pyx_PickleError = __pyx_t_2;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    /* "(tree fragment)":6
 *     if __pyx_checksum != 0x3b5338f:
 *         from pickle import PickleError as __pyx_PickleError
 *         raise __pyx_PickleError("Incompatible checksums (%s vs 0x3b5338f = (conn, cur))" % __pyx_checksum)             # <<<<<<<<<<<<<<
 *     __pyx_result = Data.__new__(__pyx_type)
 *     if __pyx_state is not None:
 */
    __pyx_t_2 = __Pyx_PyInt_From_long(__pyx_v___pyx_checksum); if (unlikely(!__pyx_t_2)) __PYX_ERR(1, 6, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = __Pyx_PyString_Format(__pyx_kp_s_Incompatible_checksums_s_vs_0x3b, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 6, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_INCREF(__pyx_v___pyx_PickleError);
    __pyx_t_2 = __pyx_v___pyx_PickleError; __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_3 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_4);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 6, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_Raise(__pyx_t_3, 0, 0, 0);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __PYX_ERR(1, 6, __pyx_L1_error)

    /* "(tree fragment)":4
 *     cdef object __pyx_PickleError
 *     cdef object __pyx_result
 *     if __pyx_checksum != 0x3b5338f:             # <<<<<<<<<<<<<<
 *         from pickle import PickleError as __pyx_PickleError
 *         raise __pyx_PickleError("Incompatible checksums (%s vs 0x3b5338f = (conn, cur))" % __pyx_checksum)
 */
  }

  /* "(tree fragment)":7
 *         from pickle import PickleError as __pyx_PickleError
 *         raise __pyx_PickleError("Incompatible checksums (%s vs 0x3b5338f = (conn, cur))" % __pyx_checksum)
 *     __pyx_result = Data.__new__(__pyx_type)             # <<<<<<<<<<<<<<
 *     if __pyx_state is not None:
 *         __pyx_unpickle_Data__set_state(<Data> __pyx_result, __pyx_state)
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_ptype_7memrise_Data), __pyx_n_s_new); if (unlikely(!__pyx_t_2)) __PYX_ERR(1, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_3 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_v___pyx_type) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v___pyx_type);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v___pyx_result = __pyx_t_3;
  __pyx_t_3 = 0;

  /* "(tree fragment)":8
 *         raise __pyx_PickleError("Incompatible checksums (%s vs 0x3b5338f = (conn, cur))" % __pyx_checksum)
 *     __pyx_result = Data.__new__(__pyx_type)
 *     if __pyx_state is not None:             # <<<<<<<<<<<<<<
 *         __pyx_unpickle_Data__set_state(<Data> __pyx_result, __pyx_state)
 *     return __pyx_result
 */
  __pyx_t_1 = (__pyx_v___pyx_state != Py_None);
  __pyx_t_6 = (__pyx_t_1 != 0);
  if (__pyx_t_6) {

    /* "(tree fragment)":9
 *     __pyx_result = Data.__new__(__pyx_type)
 *     if __pyx_state is not None:
 *         __pyx_unpickle_Data__set_state(<Data> __pyx_result, __pyx_state)             # <<<<<<<<<<<<<<
 *     return __pyx_result
 * cdef __pyx_unpickle_Data__set_state(Data __pyx_result, tuple __pyx_state):
 */
    if (!(likely(PyTuple_CheckExact(__pyx_v___pyx_state))||((__pyx_v___pyx_state) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "tuple", Py_TYPE(__pyx_v___pyx_state)->tp_name), 0))) __PYX_ERR(1, 9, __pyx_L1_error)
    __pyx_t_3 = __pyx_f_7memrise___pyx_unpickle_Data__set_state(((struct __pyx_obj_7memrise_Data *)__pyx_v___pyx_result), ((PyObject*)__pyx_v___pyx_state)); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 9, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    /* "(tree fragment)":8
 *         raise __pyx_PickleError("Incompatible checksums (%s vs 0x3b5338f = (conn, cur))" % __pyx_checksum)
 *     __pyx_result = Data.__new__(__pyx_type)
 *     if __pyx_state is not None:             # <<<<<<<<<<<<<<
 *         __pyx_unpickle_Data__set_state(<Data> __pyx_result, __pyx_state)
 *     return __pyx_result
 */
  }

  /* "(tree fragment)":10
 *     if __pyx_state is not None:
 *         __pyx_unpickle_Data__set_state(<Data> __pyx_result, __pyx_state)
 *     return __pyx_result             # <<<<<<<<<<<<<<
 * cdef __pyx_unpickle_Data__set_state(Data __pyx_result, tuple __pyx_state):
 *     __pyx_result.conn = __pyx_state[0]; __pyx_result.cur = __pyx_state[1]
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v___pyx_result);
  __pyx_r = __pyx_v___pyx_result;
  goto __pyx_L0;

  /* "(tree fragment)":1
 * def __pyx_unpickle_Data(__pyx_type, long __pyx_checksum, __pyx_state):             # <<<<<<<<<<<<<<
 *     cdef object __pyx_PickleError
 *     cdef object __pyx_result
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("memrise.__pyx_unpickle_Data", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v___pyx_PickleError);
  __Pyx_XDECREF(__pyx_v___pyx_result);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "(tree fragment)":11
 *         __pyx_unpickle_Data__set_state(<Data> __pyx_result, __pyx_state)
 *     return __pyx_result
 * cdef __pyx_unpickle_Data__set_state(Data __pyx_result, tuple __pyx_state):             # <<<<<<<<<<<<<<
 *     __pyx_result.conn = __pyx_state[0]; __pyx_result.cur = __pyx_state[1]
 *     if len(__pyx_state) > 2 and hasattr(__pyx_result, '__dict__'):
 */

static PyObject *__pyx_f_7memrise___pyx_unpickle_Data__set_state(struct __pyx_obj_7memrise_Data *__pyx_v___pyx_result, PyObject *__pyx_v___pyx_state) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  Py_ssize_t __pyx_t_3;
  int __pyx_t_4;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__pyx_unpickle_Data__set_state", 0);

  /* "(tree fragment)":12
 *     return __pyx_result
 * cdef __pyx_unpickle_Data__set_state(Data __pyx_result, tuple __pyx_state):
 *     __pyx_result.conn = __pyx_state[0]; __pyx_result.cur = __pyx_state[1]             # <<<<<<<<<<<<<<
 *     if len(__pyx_state) > 2 and hasattr(__pyx_result, '__dict__'):
 *         __pyx_result.__dict__.update(__pyx_state[2])
 */
  if (unlikely(__pyx_v___pyx_state == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
    __PYX_ERR(1, 12, __pyx_L1_error)
  }
  __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v___pyx_state, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  __Pyx_GOTREF(__pyx_v___pyx_result->conn);
  __Pyx_DECREF(__pyx_v___pyx_result->conn);
  __pyx_v___pyx_result->conn = __pyx_t_1;
  __pyx_t_1 = 0;
  if (unlikely(__pyx_v___pyx_state == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
    __PYX_ERR(1, 12, __pyx_L1_error)
  }
  __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v___pyx_state, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  __Pyx_GOTREF(__pyx_v___pyx_result->cur);
  __Pyx_DECREF(__pyx_v___pyx_result->cur);
  __pyx_v___pyx_result->cur = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "(tree fragment)":13
 * cdef __pyx_unpickle_Data__set_state(Data __pyx_result, tuple __pyx_state):
 *     __pyx_result.conn = __pyx_state[0]; __pyx_result.cur = __pyx_state[1]
 *     if len(__pyx_state) > 2 and hasattr(__pyx_result, '__dict__'):             # <<<<<<<<<<<<<<
 *         __pyx_result.__dict__.update(__pyx_state[2])
 */
  if (unlikely(__pyx_v___pyx_state == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "object of type 'NoneType' has no len()");
    __PYX_ERR(1, 13, __pyx_L1_error)
  }
  __pyx_t_3 = PyTuple_GET_SIZE(__pyx_v___pyx_state); if (unlikely(__pyx_t_3 == ((Py_ssize_t)-1))) __PYX_ERR(1, 13, __pyx_L1_error)
  __pyx_t_4 = ((__pyx_t_3 > 2) != 0);
  if (__pyx_t_4) {
  } else {
    __pyx_t_2 = __pyx_t_4;
    goto __pyx_L4_bool_binop_done;
  }
  __pyx_t_4 = __Pyx_HasAttr(((PyObject *)__pyx_v___pyx_result), __pyx_n_s_dict); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(1, 13, __pyx_L1_error)
  __pyx_t_5 = (__pyx_t_4 != 0);
  __pyx_t_2 = __pyx_t_5;
  __pyx_L4_bool_binop_done:;
  if (__pyx_t_2) {

    /* "(tree fragment)":14
 *     __pyx_result.conn = __pyx_state[0]; __pyx_result.cur = __pyx_state[1]
 *     if len(__pyx_state) > 2 and hasattr(__pyx_result, '__dict__'):
 *         __pyx_result.__dict__.update(__pyx_state[2])             # <<<<<<<<<<<<<<
 */
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v___pyx_result), __pyx_n_s_dict); if (unlikely(!__pyx_t_6)) __PYX_ERR(1, 14, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_update_2); if (unlikely(!__pyx_t_7)) __PYX_ERR(1, 14, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(__pyx_v___pyx_state == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
      __PYX_ERR(1, 14, __pyx_L1_error)
    }
    __pyx_t_6 = __Pyx_GetItemInt_Tuple(__pyx_v___pyx_state, 2, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(1, 14, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
      }
    }
    __pyx_t_1 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_8, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_6);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 14, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    /* "(tree fragment)":13
 * cdef __pyx_unpickle_Data__set_state(Data __pyx_result, tuple __pyx_state):
 *     __pyx_result.conn = __pyx_state[0]; __pyx_result.cur = __pyx_state[1]
 *     if len(__pyx_state) > 2 and hasattr(__pyx_result, '__dict__'):             # <<<<<<<<<<<<<<
 *         __pyx_result.__dict__.update(__pyx_state[2])
 */
  }

  /* "(tree fragment)":11
 *         __pyx_unpickle_Data__set_state(<Data> __pyx_result, __pyx_state)
 *     return __pyx_result
 * cdef __pyx_unpickle_Data__set_state(Data __pyx_result, tuple __pyx_state):             # <<<<<<<<<<<<<<
 *     __pyx_result.conn = __pyx_state[0]; __pyx_result.cur = __pyx_state[1]
 *     if len(__pyx_state) > 2 and hasattr(__pyx_result, '__dict__'):
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("memrise.__pyx_unpickle_Data__set_state", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_tp_new_7memrise_Level(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_7memrise_Level *p;
  PyObject *o;
  if (likely((t->tp_flags & Py_TPFLAGS_IS_ABSTRACT) == 0)) {
    o = (*t->tp_alloc)(t, 0);
  } else {
    o = (PyObject *) PyBaseObject_Type.tp_new(t, __pyx_empty_tuple, 0);
  }
  if (unlikely(!o)) return 0;
  p = ((struct __pyx_obj_7memrise_Level *)o);
  p->__pyx___words = ((PyObject*)Py_None); Py_INCREF(Py_None);
  p->__pyx___soup = Py_None; Py_INCREF(Py_None);
  p->__pyx___record = Py_None; Py_INCREF(Py_None);
  if (unlikely(__pyx_pw_7memrise_5Level_1__cinit__(o, a, k) < 0)) goto bad;
  return o;
  bad:
  Py_DECREF(o); o = 0;
  return NULL;
}

static void __pyx_tp_dealloc_7memrise_Level(PyObject *o) {
  struct __pyx_obj_7memrise_Level *p = (struct __pyx_obj_7memrise_Level *)o;
  #if CYTHON_USE_TP_FINALIZE
  if (unlikely(PyType_HasFeature(Py_TYPE(o), Py_TPFLAGS_HAVE_FINALIZE) && Py_TYPE(o)->tp_finalize) && !_PyGC_FINALIZED(o)) {
    if (PyObject_CallFinalizerFromDealloc(o)) return;
  }
  #endif
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx___words);
  Py_CLEAR(p->__pyx___soup);
  Py_CLEAR(p->__pyx___record);
  (*Py_TYPE(o)->tp_free)(o);
}

static int __pyx_tp_traverse_7memrise_Level(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_7memrise_Level *p = (struct __pyx_obj_7memrise_Level *)o;
  if (p->__pyx___words) {
    e = (*v)(p->__pyx___words, a); if (e) return e;
  }
  if (p->__pyx___soup) {
    e = (*v)(p->__pyx___soup, a); if (e) return e;
  }
  if (p->__pyx___record) {
    e = (*v)(p->__pyx___record, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_7memrise_Level(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_7memrise_Level *p = (struct __pyx_obj_7memrise_Level *)o;
  tmp = ((PyObject*)p->__pyx___words);
  p->__pyx___words = ((PyObject*)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx___soup);
  p->__pyx___soup = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx___record);
  p->__pyx___record = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyMethodDef __pyx_methods_7memrise_Level[] = {
  {"get_words", (PyCFunction)__pyx_pw_7memrise_5Level_3get_words, METH_NOARGS, 0},
  {"get_record", (PyCFunction)__pyx_pw_7memrise_5Level_5get_record, METH_NOARGS, 0},
  {"__reduce_cython__", (PyCFunction)__pyx_pw_7memrise_5Level_7__reduce_cython__, METH_NOARGS, 0},
  {"__setstate_cython__", (PyCFunction)__pyx_pw_7memrise_5Level_9__setstate_cython__, METH_O, 0},
  {0, 0, 0, 0}
};

static PyTypeObject __pyx_type_7memrise_Level = {
  PyVarObject_HEAD_INIT(0, 0)
  "memrise.Level", /*tp_name*/
  sizeof(struct __pyx_obj_7memrise_Level), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_7memrise_Level, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_7memrise_Level, /*tp_traverse*/
  __pyx_tp_clear_7memrise_Level, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_7memrise_Level, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_7memrise_Level, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static PyObject *__pyx_tp_new_7memrise_Course(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_7memrise_Course *p;
  PyObject *o;
  if (likely((t->tp_flags & Py_TPFLAGS_IS_ABSTRACT) == 0)) {
    o = (*t->tp_alloc)(t, 0);
  } else {
    o = (PyObject *) PyBaseObject_Type.tp_new(t, __pyx_empty_tuple, 0);
  }
  if (unlikely(!o)) return 0;
  p = ((struct __pyx_obj_7memrise_Course *)o);
  p->__pyx___levels = ((PyObject*)Py_None); Py_INCREF(Py_None);
  p->__pyx___soup = Py_None; Py_INCREF(Py_None);
  p->__pyx___record = Py_None; Py_INCREF(Py_None);
  if (unlikely(__pyx_pw_7memrise_6Course_1__cinit__(o, a, k) < 0)) goto bad;
  return o;
  bad:
  Py_DECREF(o); o = 0;
  return NULL;
}

static void __pyx_tp_dealloc_7memrise_Course(PyObject *o) {
  struct __pyx_obj_7memrise_Course *p = (struct __pyx_obj_7memrise_Course *)o;
  #if CYTHON_USE_TP_FINALIZE
  if (unlikely(PyType_HasFeature(Py_TYPE(o), Py_TPFLAGS_HAVE_FINALIZE) && Py_TYPE(o)->tp_finalize) && !_PyGC_FINALIZED(o)) {
    if (PyObject_CallFinalizerFromDealloc(o)) return;
  }
  #endif
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx___levels);
  Py_CLEAR(p->__pyx___soup);
  Py_CLEAR(p->__pyx___record);
  (*Py_TYPE(o)->tp_free)(o);
}

static int __pyx_tp_traverse_7memrise_Course(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_7memrise_Course *p = (struct __pyx_obj_7memrise_Course *)o;
  if (p->__pyx___levels) {
    e = (*v)(p->__pyx___levels, a); if (e) return e;
  }
  if (p->__pyx___soup) {
    e = (*v)(p->__pyx___soup, a); if (e) return e;
  }
  if (p->__pyx___record) {
    e = (*v)(p->__pyx___record, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_7memrise_Course(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_7memrise_Course *p = (struct __pyx_obj_7memrise_Course *)o;
  tmp = ((PyObject*)p->__pyx___levels);
  p->__pyx___levels = ((PyObject*)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx___soup);
  p->__pyx___soup = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx___record);
  p->__pyx___record = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyMethodDef __pyx_methods_7memrise_Course[] = {
  {"get_levels", (PyCFunction)__pyx_pw_7memrise_6Course_3get_levels, METH_NOARGS, 0},
  {"__get_levels", (PyCFunction)__pyx_pw_7memrise_6Course_5__get_levels, METH_O, 0},
  {"get_record", (PyCFunction)__pyx_pw_7memrise_6Course_7get_record, METH_NOARGS, 0},
  {"__reduce_cython__", (PyCFunction)__pyx_pw_7memrise_6Course_9__reduce_cython__, METH_NOARGS, 0},
  {"__setstate_cython__", (PyCFunction)__pyx_pw_7memrise_6Course_11__setstate_cython__, METH_O, 0},
  {0, 0, 0, 0}
};

static PyTypeObject __pyx_type_7memrise_Course = {
  PyVarObject_HEAD_INIT(0, 0)
  "memrise.Course", /*tp_name*/
  sizeof(struct __pyx_obj_7memrise_Course), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_7memrise_Course, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_7memrise_Course, /*tp_traverse*/
  __pyx_tp_clear_7memrise_Course, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_7memrise_Course, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_7memrise_Course, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static PyObject *__pyx_tp_new_7memrise_Data(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  struct __pyx_obj_7memrise_Data *p;
  PyObject *o;
  if (likely((t->tp_flags & Py_TPFLAGS_IS_ABSTRACT) == 0)) {
    o = (*t->tp_alloc)(t, 0);
  } else {
    o = (PyObject *) PyBaseObject_Type.tp_new(t, __pyx_empty_tuple, 0);
  }
  if (unlikely(!o)) return 0;
  p = ((struct __pyx_obj_7memrise_Data *)o);
  p->conn = Py_None; Py_INCREF(Py_None);
  p->cur = Py_None; Py_INCREF(Py_None);
  return o;
}

static void __pyx_tp_dealloc_7memrise_Data(PyObject *o) {
  struct __pyx_obj_7memrise_Data *p = (struct __pyx_obj_7memrise_Data *)o;
  #if CYTHON_USE_TP_FINALIZE
  if (unlikely(PyType_HasFeature(Py_TYPE(o), Py_TPFLAGS_HAVE_FINALIZE) && Py_TYPE(o)->tp_finalize) && !_PyGC_FINALIZED(o)) {
    if (PyObject_CallFinalizerFromDealloc(o)) return;
  }
  #endif
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->conn);
  Py_CLEAR(p->cur);
  (*Py_TYPE(o)->tp_free)(o);
}

static int __pyx_tp_traverse_7memrise_Data(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_7memrise_Data *p = (struct __pyx_obj_7memrise_Data *)o;
  if (p->conn) {
    e = (*v)(p->conn, a); if (e) return e;
  }
  if (p->cur) {
    e = (*v)(p->cur, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_7memrise_Data(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_7memrise_Data *p = (struct __pyx_obj_7memrise_Data *)o;
  tmp = ((PyObject*)p->conn);
  p->conn = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->cur);
  p->cur = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyMethodDef __pyx_methods_7memrise_Data[] = {
  {"__connect_database", (PyCFunction)__pyx_pw_7memrise_4Data_3__connect_database, METH_O, __pyx_doc_7memrise_4Data_2__connect_database},
  {"init_database", (PyCFunction)__pyx_pw_7memrise_4Data_5init_database, METH_NOARGS, __pyx_doc_7memrise_4Data_4init_database},
  {"__update", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_7memrise_4Data_7__update, METH_VARARGS|METH_KEYWORDS, 0},
  {"update_level", (PyCFunction)__pyx_pw_7memrise_4Data_9update_level, METH_O, 0},
  {"update_course", (PyCFunction)__pyx_pw_7memrise_4Data_11update_course, METH_O, 0},
  {"update_db", (PyCFunction)__pyx_pw_7memrise_4Data_13update_db, METH_O, __pyx_doc_7memrise_4Data_12update_db},
  {"update_db_en", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_7memrise_4Data_15update_db_en, METH_VARARGS|METH_KEYWORDS, __pyx_doc_7memrise_4Data_14update_db_en},
  {"close", (PyCFunction)__pyx_pw_7memrise_4Data_17close, METH_NOARGS, 0},
  {"__reduce_cython__", (PyCFunction)__pyx_pw_7memrise_4Data_19__reduce_cython__, METH_NOARGS, 0},
  {"__setstate_cython__", (PyCFunction)__pyx_pw_7memrise_4Data_21__setstate_cython__, METH_O, 0},
  {0, 0, 0, 0}
};

static PyTypeObject __pyx_type_7memrise_Data = {
  PyVarObject_HEAD_INIT(0, 0)
  "memrise.Data", /*tp_name*/
  sizeof(struct __pyx_obj_7memrise_Data), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_7memrise_Data, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  "Class manage all actions as insert, update, and delete DATABASE", /*tp_doc*/
  __pyx_tp_traverse_7memrise_Data, /*tp_traverse*/
  __pyx_tp_clear_7memrise_Data, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_7memrise_Data, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_pw_7memrise_4Data_1__init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_7memrise_Data, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); /*proto*/
static int __pyx_pymod_exec_memrise(PyObject* module); /*proto*/
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_memrise},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "memrise",
    0, /* m_doc */
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, /* m_size */
  #else
    -1, /* m_size */
  #endif
    __pyx_methods /* m_methods */,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, /* m_slots */
  #else
    NULL, /* m_reload */
  #endif
    NULL, /* m_traverse */
    NULL, /* m_clear */
    NULL /* m_free */
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_n_s_Any, __pyx_k_Any, sizeof(__pyx_k_Any), 0, 0, 1, 1},
  {&__pyx_n_s_BeautifulSoup, __pyx_k_BeautifulSoup, sizeof(__pyx_k_BeautifulSoup), 0, 0, 1, 1},
  {&__pyx_kp_s_CREATE_TABLE_courses_id_INTEGER, __pyx_k_CREATE_TABLE_courses_id_INTEGER, sizeof(__pyx_k_CREATE_TABLE_courses_id_INTEGER), 0, 0, 1, 0},
  {&__pyx_kp_s_CREATE_TABLE_languages_id_INTEGE, __pyx_k_CREATE_TABLE_languages_id_INTEGE, sizeof(__pyx_k_CREATE_TABLE_languages_id_INTEGE), 0, 0, 1, 0},
  {&__pyx_kp_s_CREATE_TABLE_levels_course_id_IN, __pyx_k_CREATE_TABLE_levels_course_id_IN, sizeof(__pyx_k_CREATE_TABLE_levels_course_id_IN), 0, 0, 1, 0},
  {&__pyx_kp_s_CREATE_TABLE_words_id_INTEGER_NO, __pyx_k_CREATE_TABLE_words_id_INTEGER_NO, sizeof(__pyx_k_CREATE_TABLE_words_id_INTEGER_NO), 0, 0, 1, 0},
  {&__pyx_n_s_Connection, __pyx_k_Connection, sizeof(__pyx_k_Connection), 0, 0, 1, 1},
  {&__pyx_n_s_Course, __pyx_k_Course, sizeof(__pyx_k_Course), 0, 0, 1, 1},
  {&__pyx_n_s_CourseID, __pyx_k_CourseID, sizeof(__pyx_k_CourseID), 0, 0, 1, 1},
  {&__pyx_kp_s_DROP_TABLE_IF_EXISTS_courses, __pyx_k_DROP_TABLE_IF_EXISTS_courses, sizeof(__pyx_k_DROP_TABLE_IF_EXISTS_courses), 0, 0, 1, 0},
  {&__pyx_kp_s_DROP_TABLE_IF_EXISTS_languages, __pyx_k_DROP_TABLE_IF_EXISTS_languages, sizeof(__pyx_k_DROP_TABLE_IF_EXISTS_languages), 0, 0, 1, 0},
  {&__pyx_kp_s_DROP_TABLE_IF_EXISTS_levels, __pyx_k_DROP_TABLE_IF_EXISTS_levels, sizeof(__pyx_k_DROP_TABLE_IF_EXISTS_levels), 0, 0, 1, 0},
  {&__pyx_kp_s_DROP_TABLE_IF_EXISTS_words, __pyx_k_DROP_TABLE_IF_EXISTS_words, sizeof(__pyx_k_DROP_TABLE_IF_EXISTS_words), 0, 0, 1, 0},
  {&__pyx_n_s_Data, __pyx_k_Data, sizeof(__pyx_k_Data), 0, 0, 1, 1},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA, __pyx_k_INSERT_INTO_languages_id_name_VA, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_10, __pyx_k_INSERT_INTO_languages_id_name_VA_10, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_10), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_11, __pyx_k_INSERT_INTO_languages_id_name_VA_11, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_11), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_12, __pyx_k_INSERT_INTO_languages_id_name_VA_12, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_12), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_13, __pyx_k_INSERT_INTO_languages_id_name_VA_13, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_13), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_2, __pyx_k_INSERT_INTO_languages_id_name_VA_2, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_2), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_3, __pyx_k_INSERT_INTO_languages_id_name_VA_3, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_3), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_4, __pyx_k_INSERT_INTO_languages_id_name_VA_4, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_4), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_5, __pyx_k_INSERT_INTO_languages_id_name_VA_5, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_5), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_6, __pyx_k_INSERT_INTO_languages_id_name_VA_6, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_6), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_7, __pyx_k_INSERT_INTO_languages_id_name_VA_7, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_7), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_8, __pyx_k_INSERT_INTO_languages_id_name_VA_8, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_8), 0, 0, 1, 0},
  {&__pyx_kp_s_INSERT_INTO_languages_id_name_VA_9, __pyx_k_INSERT_INTO_languages_id_name_VA_9, sizeof(__pyx_k_INSERT_INTO_languages_id_name_VA_9), 0, 0, 1, 0},
  {&__pyx_kp_s_Incompatible_checksums_s_vs_0x3b, __pyx_k_Incompatible_checksums_s_vs_0x3b, sizeof(__pyx_k_Incompatible_checksums_s_vs_0x3b), 0, 0, 1, 0},
  {&__pyx_n_s_Level, __pyx_k_Level, sizeof(__pyx_k_Level), 0, 0, 1, 1},
  {&__pyx_n_s_LevelID, __pyx_k_LevelID, sizeof(__pyx_k_LevelID), 0, 0, 1, 1},
  {&__pyx_n_s_PickleError, __pyx_k_PickleError, sizeof(__pyx_k_PickleError), 0, 0, 1, 1},
  {&__pyx_kp_s_RecordError_Fail_to_update_recor, __pyx_k_RecordError_Fail_to_update_recor, sizeof(__pyx_k_RecordError_Fail_to_update_recor), 0, 0, 1, 0},
  {&__pyx_kp_s_This_function_will_be_implemente, __pyx_k_This_function_will_be_implemente, sizeof(__pyx_k_This_function_will_be_implemente), 0, 0, 1, 0},
  {&__pyx_n_s_TypeError, __pyx_k_TypeError, sizeof(__pyx_k_TypeError), 0, 0, 1, 1},
  {&__pyx_kp_s_TypeError_Data_type_must_be_RECO, __pyx_k_TypeError_Data_type_must_be_RECO, sizeof(__pyx_k_TypeError_Data_type_must_be_RECO), 0, 0, 1, 0},
  {&__pyx_n_s_a, __pyx_k_a, sizeof(__pyx_k_a), 0, 0, 1, 1},
  {&__pyx_n_s_append, __pyx_k_append, sizeof(__pyx_k_append), 0, 0, 1, 1},
  {&__pyx_n_s_bs4, __pyx_k_bs4, sizeof(__pyx_k_bs4), 0, 0, 1, 1},
  {&__pyx_n_s_class, __pyx_k_class, sizeof(__pyx_k_class), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_close, __pyx_k_close, sizeof(__pyx_k_close), 0, 0, 1, 1},
  {&__pyx_n_s_cmd, __pyx_k_cmd, sizeof(__pyx_k_cmd), 0, 0, 1, 1},
  {&__pyx_n_s_col_a, __pyx_k_col_a, sizeof(__pyx_k_col_a), 0, 0, 1, 1},
  {&__pyx_n_s_col_b, __pyx_k_col_b, sizeof(__pyx_k_col_b), 0, 0, 1, 1},
  {&__pyx_n_s_commit, __pyx_k_commit, sizeof(__pyx_k_commit), 0, 0, 1, 1},
  {&__pyx_n_s_connect_database, __pyx_k_connect_database, sizeof(__pyx_k_connect_database), 0, 0, 1, 1},
  {&__pyx_kp_b_course, __pyx_k_course, sizeof(__pyx_k_course), 0, 0, 0, 0},
  {&__pyx_n_s_course_id, __pyx_k_course_id, sizeof(__pyx_k_course_id), 0, 0, 1, 1},
  {&__pyx_n_s_cursor, __pyx_k_cursor, sizeof(__pyx_k_cursor), 0, 0, 1, 1},
  {&__pyx_kp_s_d, __pyx_k_d, sizeof(__pyx_k_d), 0, 0, 1, 0},
  {&__pyx_n_s_data, __pyx_k_data, sizeof(__pyx_k_data), 0, 0, 1, 1},
  {&__pyx_n_s_db, __pyx_k_db, sizeof(__pyx_k_db), 0, 0, 1, 1},
  {&__pyx_n_s_decode, __pyx_k_decode, sizeof(__pyx_k_decode), 0, 0, 1, 1},
  {&__pyx_n_s_dict, __pyx_k_dict, sizeof(__pyx_k_dict), 0, 0, 1, 1},
  {&__pyx_n_s_div, __pyx_k_div, sizeof(__pyx_k_div), 0, 0, 1, 1},
  {&__pyx_n_s_encode, __pyx_k_encode, sizeof(__pyx_k_encode), 0, 0, 1, 1},
  {&__pyx_n_s_end, __pyx_k_end, sizeof(__pyx_k_end), 0, 0, 1, 1},
  {&__pyx_n_s_execute, __pyx_k_execute, sizeof(__pyx_k_execute), 0, 0, 1, 1},
  {&__pyx_n_s_exit, __pyx_k_exit, sizeof(__pyx_k_exit), 0, 0, 1, 1},
  {&__pyx_n_s_file, __pyx_k_file, sizeof(__pyx_k_file), 0, 0, 1, 1},
  {&__pyx_n_s_find, __pyx_k_find, sizeof(__pyx_k_find), 0, 0, 1, 1},
  {&__pyx_n_s_get, __pyx_k_get, sizeof(__pyx_k_get), 0, 0, 1, 1},
  {&__pyx_n_s_get_levels, __pyx_k_get_levels, sizeof(__pyx_k_get_levels), 0, 0, 1, 1},
  {&__pyx_n_s_get_levels_2, __pyx_k_get_levels_2, sizeof(__pyx_k_get_levels_2), 0, 0, 1, 1},
  {&__pyx_n_s_get_record, __pyx_k_get_record, sizeof(__pyx_k_get_record), 0, 0, 1, 1},
  {&__pyx_n_s_get_words, __pyx_k_get_words, sizeof(__pyx_k_get_words), 0, 0, 1, 1},
  {&__pyx_n_s_getstate, __pyx_k_getstate, sizeof(__pyx_k_getstate), 0, 0, 1, 1},
  {&__pyx_n_s_href, __pyx_k_href, sizeof(__pyx_k_href), 0, 0, 1, 1},
  {&__pyx_kp_s_html_parser, __pyx_k_html_parser, sizeof(__pyx_k_html_parser), 0, 0, 1, 0},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_language_id, __pyx_k_language_id, sizeof(__pyx_k_language_id), 0, 0, 1, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_s_memrise, __pyx_k_memrise, sizeof(__pyx_k_memrise), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_new, __pyx_k_new, sizeof(__pyx_k_new), 0, 0, 1, 1},
  {&__pyx_kp_s_no_default___reduce___due_to_non, __pyx_k_no_default___reduce___due_to_non, sizeof(__pyx_k_no_default___reduce___due_to_non), 0, 0, 1, 0},
  {&__pyx_n_s_path, __pyx_k_path, sizeof(__pyx_k_path), 0, 0, 1, 1},
  {&__pyx_n_s_pickle, __pyx_k_pickle, sizeof(__pyx_k_pickle), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_n_s_pyx_PickleError, __pyx_k_pyx_PickleError, sizeof(__pyx_k_pyx_PickleError), 0, 0, 1, 1},
  {&__pyx_n_s_pyx_checksum, __pyx_k_pyx_checksum, sizeof(__pyx_k_pyx_checksum), 0, 0, 1, 1},
  {&__pyx_n_s_pyx_result, __pyx_k_pyx_result, sizeof(__pyx_k_pyx_result), 0, 0, 1, 1},
  {&__pyx_n_s_pyx_state, __pyx_k_pyx_state, sizeof(__pyx_k_pyx_state), 0, 0, 1, 1},
  {&__pyx_n_s_pyx_type, __pyx_k_pyx_type, sizeof(__pyx_k_pyx_type), 0, 0, 1, 1},
  {&__pyx_n_s_pyx_unpickle_Data, __pyx_k_pyx_unpickle_Data, sizeof(__pyx_k_pyx_unpickle_Data), 0, 0, 1, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_re, __pyx_k_re, sizeof(__pyx_k_re), 0, 0, 1, 1},
  {&__pyx_n_s_reduce, __pyx_k_reduce, sizeof(__pyx_k_reduce), 0, 0, 1, 1},
  {&__pyx_n_s_reduce_cython, __pyx_k_reduce_cython, sizeof(__pyx_k_reduce_cython), 0, 0, 1, 1},
  {&__pyx_n_s_reduce_ex, __pyx_k_reduce_ex, sizeof(__pyx_k_reduce_ex), 0, 0, 1, 1},
  {&__pyx_n_s_requests, __pyx_k_requests, sizeof(__pyx_k_requests), 0, 0, 1, 1},
  {&__pyx_n_s_search, __pyx_k_search, sizeof(__pyx_k_search), 0, 0, 1, 1},
  {&__pyx_n_s_setstate, __pyx_k_setstate, sizeof(__pyx_k_setstate), 0, 0, 1, 1},
  {&__pyx_n_s_setstate_cython, __pyx_k_setstate_cython, sizeof(__pyx_k_setstate_cython), 0, 0, 1, 1},
  {&__pyx_n_s_speaker, __pyx_k_speaker, sizeof(__pyx_k_speaker), 0, 0, 1, 1},
  {&__pyx_n_s_sqlite3, __pyx_k_sqlite3, sizeof(__pyx_k_sqlite3), 0, 0, 1, 1},
  {&__pyx_kp_s_stringsource, __pyx_k_stringsource, sizeof(__pyx_k_stringsource), 0, 0, 1, 0},
  {&__pyx_n_s_strip, __pyx_k_strip, sizeof(__pyx_k_strip), 0, 0, 1, 1},
  {&__pyx_n_s_sys, __pyx_k_sys, sizeof(__pyx_k_sys), 0, 0, 1, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_text, __pyx_k_text, sizeof(__pyx_k_text), 0, 0, 1, 1},
  {&__pyx_n_s_typing, __pyx_k_typing, sizeof(__pyx_k_typing), 0, 0, 1, 1},
  {&__pyx_n_s_update, __pyx_k_update, sizeof(__pyx_k_update), 0, 0, 1, 1},
  {&__pyx_n_s_update_2, __pyx_k_update_2, sizeof(__pyx_k_update_2), 0, 0, 1, 1},
  {&__pyx_n_s_update_level, __pyx_k_update_level, sizeof(__pyx_k_update_level), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 105, __pyx_L1_error)
  __pyx_builtin_TypeError = __Pyx_GetBuiltinName(__pyx_n_s_TypeError); if (!__pyx_builtin_TypeError) __PYX_ERR(1, 2, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  /* "(tree fragment)":2
 * def __reduce_cython__(self):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")             # <<<<<<<<<<<<<<
 * def __setstate_cython__(self, __pyx_state):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 */
  __pyx_tuple_ = PyTuple_Pack(1, __pyx_kp_s_no_default___reduce___due_to_non); if (unlikely(!__pyx_tuple_)) __PYX_ERR(1, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple_);
  __Pyx_GIVEREF(__pyx_tuple_);

  /* "(tree fragment)":4
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")             # <<<<<<<<<<<<<<
 */
  __pyx_tuple__2 = PyTuple_Pack(1, __pyx_kp_s_no_default___reduce___due_to_non); if (unlikely(!__pyx_tuple__2)) __PYX_ERR(1, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__2);
  __Pyx_GIVEREF(__pyx_tuple__2);


  __pyx_tuple__3 = PyTuple_Pack(2, __pyx_n_s_href, Py_None); if (unlikely(!__pyx_tuple__3)) __PYX_ERR(0, 157, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__3);
  __Pyx_GIVEREF(__pyx_tuple__3);


  __pyx_tuple__4 = PyTuple_Pack(1, __pyx_kp_s_no_default___reduce___due_to_non); if (unlikely(!__pyx_tuple__4)) __PYX_ERR(1, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__4);
  __Pyx_GIVEREF(__pyx_tuple__4);

  /* "(tree fragment)":4
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")
 * def __setstate_cython__(self, __pyx_state):
 *     raise TypeError("no default __reduce__ due to non-trivial __cinit__")             # <<<<<<<<<<<<<<
 */
  __pyx_tuple__5 = PyTuple_Pack(1, __pyx_kp_s_no_default___reduce___due_to_non); if (unlikely(!__pyx_tuple__5)) __PYX_ERR(1, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__5);
  __Pyx_GIVEREF(__pyx_tuple__5);

  /* "(tree fragment)":1
 * def __pyx_unpickle_Data(__pyx_type, long __pyx_checksum, __pyx_state):             # <<<<<<<<<<<<<<
 *     cdef object __pyx_PickleError
 *     cdef object __pyx_result
 */
  __pyx_tuple__6 = PyTuple_Pack(5, __pyx_n_s_pyx_type, __pyx_n_s_pyx_checksum, __pyx_n_s_pyx_state, __pyx_n_s_pyx_PickleError, __pyx_n_s_pyx_result); if (unlikely(!__pyx_tuple__6)) __PYX_ERR(1, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__6);
  __Pyx_GIVEREF(__pyx_tuple__6);
  __pyx_codeobj__7 = (PyObject*)__Pyx_PyCode_New(3, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__6, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_stringsource, __pyx_n_s_pyx_unpickle_Data, 1, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__7)) __PYX_ERR(1, 1, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_62206863 = PyInt_FromLong(62206863L); if (unlikely(!__pyx_int_62206863)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); /*proto*/

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  /*--- Global init code ---*/
  __pyx_v_7memrise_CREATE_TABLE = ((PyObject*)Py_None); Py_INCREF(Py_None);
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  /*--- Variable export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  /*--- Function export code ---*/
  if (__Pyx_ExportFunction("open_soup", (void (*)(void))__pyx_f_7memrise_open_soup, "PyObject *(char *)") < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  if (__Pyx_ExportFunction("get_name", (void (*)(void))__pyx_f_7memrise_get_name, "char *(char *, PyObject *)") < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  if (__Pyx_ExportFunction("get_words", (void (*)(void))__pyx_f_7memrise_get_words, "PyObject *(PyObject *, int, int)") < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  /*--- Type init code ---*/
  if (PyType_Ready(&__pyx_type_7memrise_Level) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_7memrise_Level.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_7memrise_Level.tp_dictoffset && __pyx_type_7memrise_Level.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_7memrise_Level.tp_getattro = __Pyx_PyObject_GenericGetAttr;
  }
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s_Level, (PyObject *)&__pyx_type_7memrise_Level) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  if (__Pyx_setup_reduce((PyObject*)&__pyx_type_7memrise_Level) < 0) __PYX_ERR(0, 115, __pyx_L1_error)
  __pyx_ptype_7memrise_Level = &__pyx_type_7memrise_Level;
  if (PyType_Ready(&__pyx_type_7memrise_Course) < 0) __PYX_ERR(0, 133, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_7memrise_Course.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_7memrise_Course.tp_dictoffset && __pyx_type_7memrise_Course.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_7memrise_Course.tp_getattro = __Pyx_PyObject_GenericGetAttr;
  }
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s_Course, (PyObject *)&__pyx_type_7memrise_Course) < 0) __PYX_ERR(0, 133, __pyx_L1_error)
  if (__Pyx_setup_reduce((PyObject*)&__pyx_type_7memrise_Course) < 0) __PYX_ERR(0, 133, __pyx_L1_error)
  __pyx_ptype_7memrise_Course = &__pyx_type_7memrise_Course;
  if (PyType_Ready(&__pyx_type_7memrise_Data) < 0) __PYX_ERR(0, 167, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_7memrise_Data.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_7memrise_Data.tp_dictoffset && __pyx_type_7memrise_Data.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_7memrise_Data.tp_getattro = __Pyx_PyObject_GenericGetAttr;
  }
  if (PyObject_SetAttr(__pyx_m, __pyx_n_s_Data, (PyObject *)&__pyx_type_7memrise_Data) < 0) __PYX_ERR(0, 167, __pyx_L1_error)
  if (__Pyx_setup_reduce((PyObject*)&__pyx_type_7memrise_Data) < 0) __PYX_ERR(0, 167, __pyx_L1_error)
  __pyx_ptype_7memrise_Data = &__pyx_type_7memrise_Data;
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  /*--- Type import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  /*--- Variable import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  /*--- Function import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initmemrise(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC initmemrise(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_memrise(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC PyInit_memrise(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_memrise(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'memrise' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_memrise(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  /*--- Library function declarations ---*/
  /*--- Threads initialization code ---*/
  #if defined(WITH_THREAD) && PY_VERSION_HEX < 0x030700F0 && defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  PyEval_InitThreads();
  #endif
  /*--- Module creation code ---*/
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("memrise", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  /*--- Initialize various global constants etc. ---*/
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_memrise) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "memrise")) {
      if (unlikely(PyDict_SetItemString(modules, "memrise", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  /*--- Builtin init code ---*/
  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  /*--- Constants init code ---*/
  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  /*--- Global type/function init code ---*/
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  if (unlikely(__Pyx_modinit_function_export_code() < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
  if (unlikely(__Pyx_modinit_type_init_code() < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  /*--- Execution code ---*/
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif


  __pyx_t_1 = __Pyx_Import(__pyx_n_s_re, 0, -1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_re, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;


  __pyx_t_1 = __Pyx_Import(__pyx_n_s_requests, 0, -1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_requests, __pyx_t_1) < 0) __PYX_ERR(0, 2, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;


  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sqlite3, 0, -1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sqlite3, __pyx_t_1) < 0) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;


  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_BeautifulSoup);
  __Pyx_GIVEREF(__pyx_n_s_BeautifulSoup);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_BeautifulSoup);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_bs4, __pyx_t_1, -1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_BeautifulSoup); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_BeautifulSoup, __pyx_t_1) < 0) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_Any);
  __Pyx_GIVEREF(__pyx_n_s_Any);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_Any);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_typing, __pyx_t_2, -1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_Any); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Any, __pyx_t_2) < 0) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;


  __pyx_v_7memrise_PAGE = ((char const *)"https://app.memrise.com");


  __pyx_t_1 = PyList_New(21); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_kp_s_DROP_TABLE_IF_EXISTS_languages);
  __Pyx_GIVEREF(__pyx_kp_s_DROP_TABLE_IF_EXISTS_languages);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_kp_s_DROP_TABLE_IF_EXISTS_languages);
  __Pyx_INCREF(__pyx_kp_s_CREATE_TABLE_languages_id_INTEGE);
  __Pyx_GIVEREF(__pyx_kp_s_CREATE_TABLE_languages_id_INTEGE);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_kp_s_CREATE_TABLE_languages_id_INTEGE);
  __Pyx_INCREF(__pyx_kp_s_DROP_TABLE_IF_EXISTS_courses);
  __Pyx_GIVEREF(__pyx_kp_s_DROP_TABLE_IF_EXISTS_courses);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_kp_s_DROP_TABLE_IF_EXISTS_courses);
  __Pyx_INCREF(__pyx_kp_s_CREATE_TABLE_courses_id_INTEGER);
  __Pyx_GIVEREF(__pyx_kp_s_CREATE_TABLE_courses_id_INTEGER);
  PyList_SET_ITEM(__pyx_t_1, 3, __pyx_kp_s_CREATE_TABLE_courses_id_INTEGER);
  __Pyx_INCREF(__pyx_kp_s_DROP_TABLE_IF_EXISTS_levels);
  __Pyx_GIVEREF(__pyx_kp_s_DROP_TABLE_IF_EXISTS_levels);
  PyList_SET_ITEM(__pyx_t_1, 4, __pyx_kp_s_DROP_TABLE_IF_EXISTS_levels);
  __Pyx_INCREF(__pyx_kp_s_CREATE_TABLE_levels_course_id_IN);
  __Pyx_GIVEREF(__pyx_kp_s_CREATE_TABLE_levels_course_id_IN);
  PyList_SET_ITEM(__pyx_t_1, 5, __pyx_kp_s_CREATE_TABLE_levels_course_id_IN);
  __Pyx_INCREF(__pyx_kp_s_DROP_TABLE_IF_EXISTS_words);
  __Pyx_GIVEREF(__pyx_kp_s_DROP_TABLE_IF_EXISTS_words);
  PyList_SET_ITEM(__pyx_t_1, 6, __pyx_kp_s_DROP_TABLE_IF_EXISTS_words);
  __Pyx_INCREF(__pyx_kp_s_CREATE_TABLE_words_id_INTEGER_NO);
  __Pyx_GIVEREF(__pyx_kp_s_CREATE_TABLE_words_id_INTEGER_NO);
  PyList_SET_ITEM(__pyx_t_1, 7, __pyx_kp_s_CREATE_TABLE_words_id_INTEGER_NO);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA);
  PyList_SET_ITEM(__pyx_t_1, 8, __pyx_kp_s_INSERT_INTO_languages_id_name_VA);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_2);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_2);
  PyList_SET_ITEM(__pyx_t_1, 9, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_2);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_3);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_3);
  PyList_SET_ITEM(__pyx_t_1, 10, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_3);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_4);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_4);
  PyList_SET_ITEM(__pyx_t_1, 11, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_4);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_5);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_5);
  PyList_SET_ITEM(__pyx_t_1, 12, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_5);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_6);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_6);
  PyList_SET_ITEM(__pyx_t_1, 13, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_6);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_7);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_7);
  PyList_SET_ITEM(__pyx_t_1, 14, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_7);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_8);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_8);
  PyList_SET_ITEM(__pyx_t_1, 15, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_8);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_9);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_9);
  PyList_SET_ITEM(__pyx_t_1, 16, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_9);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_10);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_10);
  PyList_SET_ITEM(__pyx_t_1, 17, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_10);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_11);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_11);
  PyList_SET_ITEM(__pyx_t_1, 18, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_11);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_12);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_12);
  PyList_SET_ITEM(__pyx_t_1, 19, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_12);
  __Pyx_INCREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_13);
  __Pyx_GIVEREF(__pyx_kp_s_INSERT_INTO_languages_id_name_VA_13);
  PyList_SET_ITEM(__pyx_t_1, 20, __pyx_kp_s_INSERT_INTO_languages_id_name_VA_13);
  __Pyx_XGOTREF(__pyx_v_7memrise_CREATE_TABLE);
  __Pyx_DECREF_SET(__pyx_v_7memrise_CREATE_TABLE, ((PyObject*)__pyx_t_1));
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_t_1 = 0;

  __pyx_v_7memrise_INSERT_COURSE = ((char const *)"INSERT INTO \"courses\" (\"id\", \"name\", \"language_id\") VALUES (?,?,?);");

  __pyx_v_7memrise_INSERT_LEVEL = ((char const *)"INSERT INTO \"levels\" (\"course_id\",\"id\",\"name\") VALUES (?,?,?)");

  __pyx_v_7memrise_INSERT_WORD = ((char const *)"INSERT INTO \n\"words\" (\n\t\"word\"\n\t,\"meaning\"\n\t,\"course_id\"\n\t,\"level_id\" ) \nVALUES (?,?,?,?);");

  __pyx_t_1 = PyCFunction_NewEx(&__pyx_mdef_7memrise_1__pyx_unpickle_Data, NULL, __pyx_n_s_memrise); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_pyx_unpickle_Data, __pyx_t_1) < 0) __PYX_ERR(1, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  __pyx_t_1 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /*--- Wrapped vars code ---*/

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init memrise", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init memrise");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}

/* --- Runtime support code --- */
/* Refnanny */
#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif

/* PyObjectGetAttrStr */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif

/* GetBuiltinName */
static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}

/* PyDictVersioning */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif

/* GetModuleGlobalName */
#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}

/* PyCFunctionFastCall */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    /* _PyCFunction_FastCallDict() must not be called with an exception set,
       because it may clear it (directly or indirectly) and so the
       caller loses its exception */
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif

/* PyFunctionFastCall */
#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    /* XXX Perhaps we should create a specialized
       PyFrame_New() that doesn't take locals, but does
       take builtins without sanity checking them.
       */
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            /* function called with no arguments, but all parameters have
               a default value: use default values as arguments .*/
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif

/* PyObjectCall */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = Py_TYPE(func)->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCall2Args */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}

/* PyObjectCallMethO */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCallOneArg */
#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (__Pyx_PyFastCFunction_Check(func)) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif

/* PyObjectCallNoArg */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#ifdef __Pyx_CyFunction_USED
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif

/* PyErrFetchRestore */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif

/* WriteUnraisableException */
static void __Pyx_WriteUnraisable(const char *name, CYTHON_UNUSED int clineno,
                                  CYTHON_UNUSED int lineno, CYTHON_UNUSED const char *filename,
                                  int full_traceback, CYTHON_UNUSED int nogil) {
    PyObject *old_exc, *old_val, *old_tb;
    PyObject *ctx;
    __Pyx_PyThreadState_declare
#ifdef WITH_THREAD
    PyGILState_STATE state;
    if (nogil)
        state = PyGILState_Ensure();
#ifdef _MSC_VER
    else state = (PyGILState_STATE)-1;
#endif
#endif
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&old_exc, &old_val, &old_tb);
    if (full_traceback) {
        Py_XINCREF(old_exc);
        Py_XINCREF(old_val);
        Py_XINCREF(old_tb);
        __Pyx_ErrRestore(old_exc, old_val, old_tb);
        PyErr_PrintEx(1);
    }
    #if PY_MAJOR_VERSION < 3
    ctx = PyString_FromString(name);
    #else
    ctx = PyUnicode_FromString(name);
    #endif
    __Pyx_ErrRestore(old_exc, old_val, old_tb);
    if (!ctx) {
        PyErr_WriteUnraisable(Py_None);
    } else {
        PyErr_WriteUnraisable(ctx);
        Py_DECREF(ctx);
    }
#ifdef WITH_THREAD
    if (nogil)
        PyGILState_Release(state);
#endif
}

/* PyObjectGetMethod */
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if PY_MAJOR_VERSION >= 3
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type)))
        #endif
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (descr != NULL) {
        *method = descr;
        return 0;
    }
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(name));
#endif
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}

/* PyObjectCallMethod1 */
static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
}

/* append */
static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x) {
    if (likely(PyList_CheckExact(L))) {
        if (unlikely(__Pyx_PyList_Append(L, x) < 0)) return -1;
    } else {
        PyObject* retval = __Pyx_PyObject_CallMethod1(L, __pyx_n_s_append, x);
        if (unlikely(!retval))
            return -1;
        Py_DECREF(retval);
    }
    return 0;
}

/* GetItemInt */
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}

/* RaiseArgTupleInvalid */
static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}

/* RaiseDoubleKeywords */
static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}

/* ParseKeywords */
static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (__Pyx_PyUnicode_GET_LENGTH(**name) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (__Pyx_PyUnicode_GET_LENGTH(**argname) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}

/* decode_c_string */
static CYTHON_INLINE PyObject* __Pyx_decode_c_string(
         const char* cstring, Py_ssize_t start, Py_ssize_t stop,
         const char* encoding, const char* errors,
         PyObject* (*decode_func)(const char *s, Py_ssize_t size, const char *errors)) {
    Py_ssize_t length;
    if (unlikely((start < 0) | (stop < 0))) {
        size_t slen = strlen(cstring);
        if (unlikely(slen > (size_t) PY_SSIZE_T_MAX)) {
            PyErr_SetString(PyExc_OverflowError,
                            "c-string too long to convert to Python");
            return NULL;
        }
        length = (Py_ssize_t) slen;
        if (start < 0) {
            start += length;
            if (start < 0)
                start = 0;
        }
        if (stop < 0)
            stop += length;
    }
    if (unlikely(stop <= start))
        return __Pyx_NewRef(__pyx_empty_unicode);
    length = stop - start;
    cstring += start;
    if (decode_func) {
        return decode_func(cstring, length, errors);
    } else {
        return PyUnicode_Decode(cstring, length, encoding, errors);
    }
}

/* RaiseException */
#if PY_MAJOR_VERSION < 3
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb,
                        CYTHON_UNUSED PyObject *cause) {
    __Pyx_PyThreadState_declare
    Py_XINCREF(type);
    if (!value || value == Py_None)
        value = NULL;
    else
        Py_INCREF(value);
    if (!tb || tb == Py_None)
        tb = NULL;
    else {
        Py_INCREF(tb);
        if (!PyTraceBack_Check(tb)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: arg 3 must be a traceback or None");
            goto raise_error;
        }
    }
    if (PyType_Check(type)) {
#if CYTHON_COMPILING_IN_PYPY
        if (!value) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#endif
        PyErr_NormalizeException(&type, &value, &tb);
    } else {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        value = type;
        type = (PyObject*) Py_TYPE(type);
        Py_INCREF(type);
        if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: exception class must be a subclass of BaseException");
            goto raise_error;
        }
    }
    __Pyx_PyThreadState_assign
    __Pyx_ErrRestore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}
#else
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause) {
    PyObject* owned_instance = NULL;
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;
    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (PyExceptionClass_Check(type)) {
        PyObject *instance_class = NULL;
        if (value && PyExceptionInstance_Check(value)) {
            instance_class = (PyObject*) Py_TYPE(value);
            if (instance_class != type) {
                int is_subclass = PyObject_IsSubclass(instance_class, type);
                if (!is_subclass) {
                    instance_class = NULL;
                } else if (unlikely(is_subclass == -1)) {
                    goto bad;
                } else {
                    type = instance_class;
                }
            }
        }
        if (!instance_class) {
            PyObject *args;
            if (!value)
                args = PyTuple_New(0);
            else if (PyTuple_Check(value)) {
                Py_INCREF(value);
                args = value;
            } else
                args = PyTuple_Pack(1, value);
            if (!args)
                goto bad;
            owned_instance = PyObject_Call(type, args, NULL);
            Py_DECREF(args);
            if (!owned_instance)
                goto bad;
            value = owned_instance;
            if (!PyExceptionInstance_Check(value)) {
                PyErr_Format(PyExc_TypeError,
                             "calling %R should have returned an instance of "
                             "BaseException, not %R",
                             type, Py_TYPE(value));
                goto bad;
            }
        }
    } else {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }
    if (cause) {
        PyObject *fixed_cause;
        if (cause == Py_None) {
            fixed_cause = NULL;
        } else if (PyExceptionClass_Check(cause)) {
            fixed_cause = PyObject_CallObject(cause, NULL);
            if (fixed_cause == NULL)
                goto bad;
        } else if (PyExceptionInstance_Check(cause)) {
            fixed_cause = cause;
            Py_INCREF(fixed_cause);
        } else {
            PyErr_SetString(PyExc_TypeError,
                            "exception causes must derive from "
                            "BaseException");
            goto bad;
        }
        PyException_SetCause(value, fixed_cause);
    }
    PyErr_SetObject(type, value);
    if (tb) {
#if CYTHON_COMPILING_IN_PYPY
        PyObject *tmp_type, *tmp_value, *tmp_tb;
        PyErr_Fetch(&tmp_type, &tmp_value, &tmp_tb);
        Py_INCREF(tb);
        PyErr_Restore(tmp_type, tmp_value, tb);
        Py_XDECREF(tmp_tb);
#else
        PyThreadState *tstate = __Pyx_PyThreadState_Current;
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
#endif
    }
bad:
    Py_XDECREF(owned_instance);
    return;
}
#endif

/* PyIntBinop */
#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            x = (long)((unsigned long)a + b);
            if (likely((x^a) >= 0 || (x^b) >= 0))
                return PyInt_FromLong(x);
            return PyLong_Type.tp_as_number->nb_add(op1, op2);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_add(op1, op2);
            }
        }
                x = a + b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla + llb;
            return PyLong_FromLongLong(llx);
#endif
        
        
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
            double result;
            PyFPE_START_PROTECT("add", return NULL)
            result = ((double)a) + (double)b;
            PyFPE_END_PROTECT(result)
            return PyFloat_FromDouble(result);
    }
    return (inplace ? PyNumber_InPlaceAdd : PyNumber_Add)(op1, op2);
}
#endif

/* ArgTypeTest */
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact)
{
    if (unlikely(!type)) {
        PyErr_SetString(PyExc_SystemError, "Missing type object");
        return 0;
    }
    else if (exact) {
        #if PY_MAJOR_VERSION == 2
        if ((type == &PyBaseString_Type) && likely(__Pyx_PyBaseString_CheckExact(obj))) return 1;
        #endif
    }
    else {
        if (likely(__Pyx_TypeCheck(obj, type))) return 1;
    }
    PyErr_Format(PyExc_TypeError,
        "Argument '%.200s' has incorrect type (expected %.200s, got %.200s)",
        name, type->tp_name, Py_TYPE(obj)->tp_name);
    return 0;
}

/* Import */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}

/* ImportFrom */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name) {
    PyObject* value = __Pyx_PyObject_GetAttrStr(module, name);
    if (unlikely(!value) && PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Format(PyExc_ImportError,
        #if PY_MAJOR_VERSION < 3
            "cannot import name %.230s", PyString_AS_STRING(name));
        #else
            "cannot import name %S", name);
        #endif
    }
    return value;
}

/* GetTopmostException */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif

/* SaveResetException */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif

/* GetException */
#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}

/* SwapException */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = *type;
    exc_info->exc_value = *value;
    exc_info->exc_traceback = *tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
    #endif
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyErr_GetExcInfo(&tmp_type, &tmp_value, &tmp_tb);
    PyErr_SetExcInfo(*type, *value, *tb);
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#endif

/* PyErrExceptionMatches */
#if CYTHON_FAST_THREAD_STATE
static int __Pyx_PyErr_ExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        if (__Pyx_PyErr_GivenExceptionMatches(exc_type, PyTuple_GET_ITEM(tuple, i))) return 1;
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err) {
    PyObject *exc_type = tstate->curexc_type;
    if (exc_type == err) return 1;
    if (unlikely(!exc_type)) return 0;
    if (unlikely(PyTuple_Check(err)))
        return __Pyx_PyErr_ExceptionMatchesTuple(exc_type, err);
    return __Pyx_PyErr_GivenExceptionMatches(exc_type, err);
}
#endif

/* GetAttr */
static CYTHON_INLINE PyObject *__Pyx_GetAttr(PyObject *o, PyObject *n) {
#if CYTHON_USE_TYPE_SLOTS
#if PY_MAJOR_VERSION >= 3
    if (likely(PyUnicode_Check(n)))
#else
    if (likely(PyString_Check(n)))
#endif
        return __Pyx_PyObject_GetAttrStr(o, n);
#endif
    return PyObject_GetAttr(o, n);
}

/* GetAttr3 */
static PyObject *__Pyx_GetAttr3Default(PyObject *d) {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    if (unlikely(!__Pyx_PyErr_ExceptionMatches(PyExc_AttributeError)))
        return NULL;
    __Pyx_PyErr_Clear();
    Py_INCREF(d);
    return d;
}
static CYTHON_INLINE PyObject *__Pyx_GetAttr3(PyObject *o, PyObject *n, PyObject *d) {
    PyObject *r = __Pyx_GetAttr(o, n);
    return (likely(r)) ? r : __Pyx_GetAttr3Default(d);
}

/* HasAttr */
static CYTHON_INLINE int __Pyx_HasAttr(PyObject *o, PyObject *n) {
    PyObject *r;
    if (unlikely(!__Pyx_PyBaseString_Check(n))) {
        PyErr_SetString(PyExc_TypeError,
                        "hasattr(): attribute name must be string");
        return -1;
    }
    r = __Pyx_GetAttr(o, n);
    if (unlikely(!r)) {
        PyErr_Clear();
        return 0;
    } else {
        Py_DECREF(r);
        return 1;
    }
}

/* PyObject_GenericGetAttrNoDict */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject *__Pyx_RaiseGenericGetAttributeError(PyTypeObject *tp, PyObject *attr_name) {
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, attr_name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(attr_name));
#endif
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name) {
    PyObject *descr;
    PyTypeObject *tp = Py_TYPE(obj);
    if (unlikely(!PyString_Check(attr_name))) {
        return PyObject_GenericGetAttr(obj, attr_name);
    }
    assert(!tp->tp_dictoffset);
    descr = _PyType_Lookup(tp, attr_name);
    if (unlikely(!descr)) {
        return __Pyx_RaiseGenericGetAttributeError(tp, attr_name);
    }
    Py_INCREF(descr);
    #if PY_MAJOR_VERSION < 3
    if (likely(PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)))
    #endif
    {
        descrgetfunc f = Py_TYPE(descr)->tp_descr_get;
        if (unlikely(f)) {
            PyObject *res = f(descr, obj, (PyObject *)tp);
            Py_DECREF(descr);
            return res;
        }
    }
    return descr;
}
#endif

/* PyObject_GenericGetAttr */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject* __Pyx_PyObject_GenericGetAttr(PyObject* obj, PyObject* attr_name) {
    if (unlikely(Py_TYPE(obj)->tp_dictoffset)) {
        return PyObject_GenericGetAttr(obj, attr_name);
    }
    return __Pyx_PyObject_GenericGetAttrNoDict(obj, attr_name);
}
#endif

/* PyObjectGetAttrStrNoError */
static void __Pyx_PyObject_GetAttrStr_ClearAttributeError(void) {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    if (likely(__Pyx_PyErr_ExceptionMatches(PyExc_AttributeError)))
        __Pyx_PyErr_Clear();
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStrNoError(PyObject* obj, PyObject* attr_name) {
    PyObject *result;
#if CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_TYPE_SLOTS && PY_VERSION_HEX >= 0x030700B1
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro == PyObject_GenericGetAttr)) {
        return _PyObject_GenericGetAttrWithDict(obj, attr_name, NULL, 1);
    }
#endif
    result = __Pyx_PyObject_GetAttrStr(obj, attr_name);
    if (unlikely(!result)) {
        __Pyx_PyObject_GetAttrStr_ClearAttributeError();
    }
    return result;
}

/* SetupReduce */
static int __Pyx_setup_reduce_is_named(PyObject* meth, PyObject* name) {
  int ret;
  PyObject *name_attr;
  name_attr = __Pyx_PyObject_GetAttrStr(meth, __pyx_n_s_name);
  if (likely(name_attr)) {
      ret = PyObject_RichCompareBool(name_attr, name, Py_EQ);
  } else {
      ret = -1;
  }
  if (unlikely(ret < 0)) {
      PyErr_Clear();
      ret = 0;
  }
  Py_XDECREF(name_attr);
  return ret;
}
static int __Pyx_setup_reduce(PyObject* type_obj) {
    int ret = 0;
    PyObject *object_reduce = NULL;
    PyObject *object_reduce_ex = NULL;
    PyObject *reduce = NULL;
    PyObject *reduce_ex = NULL;
    PyObject *reduce_cython = NULL;
    PyObject *setstate = NULL;
    PyObject *setstate_cython = NULL;
#if CYTHON_USE_PYTYPE_LOOKUP
    if (_PyType_Lookup((PyTypeObject*)type_obj, __pyx_n_s_getstate)) goto __PYX_GOOD;
#else
    if (PyObject_HasAttr(type_obj, __pyx_n_s_getstate)) goto __PYX_GOOD;
#endif
#if CYTHON_USE_PYTYPE_LOOKUP
    object_reduce_ex = _PyType_Lookup(&PyBaseObject_Type, __pyx_n_s_reduce_ex); if (!object_reduce_ex) goto __PYX_BAD;
#else
    object_reduce_ex = __Pyx_PyObject_GetAttrStr((PyObject*)&PyBaseObject_Type, __pyx_n_s_reduce_ex); if (!object_reduce_ex) goto __PYX_BAD;
#endif
    reduce_ex = __Pyx_PyObject_GetAttrStr(type_obj, __pyx_n_s_reduce_ex); if (unlikely(!reduce_ex)) goto __PYX_BAD;
    if (reduce_ex == object_reduce_ex) {
#if CYTHON_USE_PYTYPE_LOOKUP
        object_reduce = _PyType_Lookup(&PyBaseObject_Type, __pyx_n_s_reduce); if (!object_reduce) goto __PYX_BAD;
#else
        object_reduce = __Pyx_PyObject_GetAttrStr((PyObject*)&PyBaseObject_Type, __pyx_n_s_reduce); if (!object_reduce) goto __PYX_BAD;
#endif
        reduce = __Pyx_PyObject_GetAttrStr(type_obj, __pyx_n_s_reduce); if (unlikely(!reduce)) goto __PYX_BAD;
        if (reduce == object_reduce || __Pyx_setup_reduce_is_named(reduce, __pyx_n_s_reduce_cython)) {
            reduce_cython = __Pyx_PyObject_GetAttrStrNoError(type_obj, __pyx_n_s_reduce_cython);
            if (likely(reduce_cython)) {
                ret = PyDict_SetItem(((PyTypeObject*)type_obj)->tp_dict, __pyx_n_s_reduce, reduce_cython); if (unlikely(ret < 0)) goto __PYX_BAD;
                ret = PyDict_DelItem(((PyTypeObject*)type_obj)->tp_dict, __pyx_n_s_reduce_cython); if (unlikely(ret < 0)) goto __PYX_BAD;
            } else if (reduce == object_reduce || PyErr_Occurred()) {
                goto __PYX_BAD;
            }
            setstate = __Pyx_PyObject_GetAttrStr(type_obj, __pyx_n_s_setstate);
            if (!setstate) PyErr_Clear();
            if (!setstate || __Pyx_setup_reduce_is_named(setstate, __pyx_n_s_setstate_cython)) {
                setstate_cython = __Pyx_PyObject_GetAttrStrNoError(type_obj, __pyx_n_s_setstate_cython);
                if (likely(setstate_cython)) {
                    ret = PyDict_SetItem(((PyTypeObject*)type_obj)->tp_dict, __pyx_n_s_setstate, setstate_cython); if (unlikely(ret < 0)) goto __PYX_BAD;
                    ret = PyDict_DelItem(((PyTypeObject*)type_obj)->tp_dict, __pyx_n_s_setstate_cython); if (unlikely(ret < 0)) goto __PYX_BAD;
                } else if (!setstate || PyErr_Occurred()) {
                    goto __PYX_BAD;
                }
            }
            PyType_Modified((PyTypeObject*)type_obj);
        }
    }
    goto __PYX_GOOD;
__PYX_BAD:
    if (!PyErr_Occurred())
        PyErr_Format(PyExc_RuntimeError, "Unable to initialize pickling for %s", ((PyTypeObject*)type_obj)->tp_name);
    ret = -1;
__PYX_GOOD:
#if !CYTHON_USE_PYTYPE_LOOKUP
    Py_XDECREF(object_reduce);
    Py_XDECREF(object_reduce_ex);
#endif
    Py_XDECREF(reduce);
    Py_XDECREF(reduce_ex);
    Py_XDECREF(reduce_cython);
    Py_XDECREF(setstate);
    Py_XDECREF(setstate_cython);
    return ret;
}

/* CLineInTraceback */
#ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_NCP_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif

/* CodeObjectCache */
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}

/* AddTraceback */
#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(filename);
    #else
    py_srcfile = PyUnicode_FromString(filename);
    #endif
    if (!py_srcfile) goto bad;
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, /*PyObject *code,*/
        __pyx_empty_tuple, /*PyObject *consts,*/
        __pyx_empty_tuple, /*PyObject *names,*/
        __pyx_empty_tuple, /*PyObject *varnames,*/
        __pyx_empty_tuple, /*PyObject *freevars,*/
        __pyx_empty_tuple, /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        py_line,
        __pyx_empty_bytes  /*PyObject *lnotab*/
    );
    Py_DECREF(py_srcfile);
    Py_DECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            /*PyThreadState *tstate,*/
        py_code,           /*PyCodeObject *code,*/
        __pyx_d,    /*PyObject *globals,*/
        0                  /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

/* CIntFromPyVerify */
#define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }

/* Print */
#if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION < 3
static PyObject *__Pyx_GetStdout(void) {
    PyObject *f = PySys_GetObject((char *)"stdout");
    if (!f) {
        PyErr_SetString(PyExc_RuntimeError, "lost sys.stdout");
    }
    return f;
}
static int __Pyx_Print(PyObject* f, PyObject *arg_tuple, int newline) {
    int i;
    if (!f) {
        if (!(f = __Pyx_GetStdout()))
            return -1;
    }
    Py_INCREF(f);
    for (i=0; i < PyTuple_GET_SIZE(arg_tuple); i++) {
        PyObject* v;
        if (PyFile_SoftSpace(f, 1)) {
            if (PyFile_WriteString(" ", f) < 0)
                goto error;
        }
        v = PyTuple_GET_ITEM(arg_tuple, i);
        if (PyFile_WriteObject(v, f, Py_PRINT_RAW) < 0)
            goto error;
        if (PyString_Check(v)) {
            char *s = PyString_AsString(v);
            Py_ssize_t len = PyString_Size(v);
            if (len > 0) {
                switch (s[len-1]) {
                    case ' ': break;
                    case '\f': case '\r': case '\n': case '\t': case '\v':
                        PyFile_SoftSpace(f, 0);
                        break;
                    default:  break;
                }
            }
        }
    }
    if (newline) {
        if (PyFile_WriteString("\n", f) < 0)
            goto error;
        PyFile_SoftSpace(f, 0);
    }
    Py_DECREF(f);
    return 0;
error:
    Py_DECREF(f);
    return -1;
}
#else
static int __Pyx_Print(PyObject* stream, PyObject *arg_tuple, int newline) {
    PyObject* kwargs = 0;
    PyObject* result = 0;
    PyObject* end_string;
    if (unlikely(!__pyx_print)) {
        __pyx_print = PyObject_GetAttr(__pyx_b, __pyx_n_s_print);
        if (!__pyx_print)
            return -1;
    }
    if (stream) {
        kwargs = PyDict_New();
        if (unlikely(!kwargs))
            return -1;
        if (unlikely(PyDict_SetItem(kwargs, __pyx_n_s_file, stream) < 0))
            goto bad;
        if (!newline) {
            end_string = PyUnicode_FromStringAndSize(" ", 1);
            if (unlikely(!end_string))
                goto bad;
            if (PyDict_SetItem(kwargs, __pyx_n_s_end, end_string) < 0) {
                Py_DECREF(end_string);
                goto bad;
            }
            Py_DECREF(end_string);
        }
    } else if (!newline) {
        if (unlikely(!__pyx_print_kwargs)) {
            __pyx_print_kwargs = PyDict_New();
            if (unlikely(!__pyx_print_kwargs))
                return -1;
            end_string = PyUnicode_FromStringAndSize(" ", 1);
            if (unlikely(!end_string))
                return -1;
            if (PyDict_SetItem(__pyx_print_kwargs, __pyx_n_s_end, end_string) < 0) {
                Py_DECREF(end_string);
                return -1;
            }
            Py_DECREF(end_string);
        }
        kwargs = __pyx_print_kwargs;
    }
    result = PyObject_Call(__pyx_print, arg_tuple, kwargs);
    if (unlikely(kwargs) && (kwargs != __pyx_print_kwargs))
        Py_DECREF(kwargs);
    if (!result)
        return -1;
    Py_DECREF(result);
    return 0;
bad:
    if (kwargs != __pyx_print_kwargs)
        Py_XDECREF(kwargs);
    return -1;
}
#endif

/* CIntFromPy */
static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}

/* CIntToPy */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_int(int value) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const int neg_one = (int) -1, const_zero = (int) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(int) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(int) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(int) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(int),
                                     little, !is_unsigned);
    }
}

/* CIntFromPy */
static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const int neg_one = (int) -1, const_zero = (int) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}

/* CIntToPy */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}

/* PrintOne */
#if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION < 3
static int __Pyx_PrintOne(PyObject* f, PyObject *o) {
    if (!f) {
        if (!(f = __Pyx_GetStdout()))
            return -1;
    }
    Py_INCREF(f);
    if (PyFile_SoftSpace(f, 0)) {
        if (PyFile_WriteString(" ", f) < 0)
            goto error;
    }
    if (PyFile_WriteObject(o, f, Py_PRINT_RAW) < 0)
        goto error;
    if (PyFile_WriteString("\n", f) < 0)
        goto error;
    Py_DECREF(f);
    return 0;
error:
    Py_DECREF(f);
    return -1;
    /* the line below is just to avoid C compiler
     * warnings about unused functions */
    return __Pyx_Print(f, NULL, 0);
}
#else
static int __Pyx_PrintOne(PyObject* stream, PyObject *o) {
    int res;
    PyObject* arg_tuple = PyTuple_Pack(1, o);
    if (unlikely(!arg_tuple))
        return -1;
    res = __Pyx_Print(stream, arg_tuple, 1);
    Py_DECREF(arg_tuple);
    return res;
}
#endif

/* FastTypeChecks */
#if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif

/* CheckBinaryVersion */
static int __Pyx_check_binary_version(void) {
    char ctversion[4], rtversion[4];
    PyOS_snprintf(ctversion, 4, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    PyOS_snprintf(rtversion, 4, "%s", Py_GetVersion());
    if (ctversion[0] != rtversion[0] || ctversion[2] != rtversion[2]) {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}

/* FunctionExport */
static int __Pyx_ExportFunction(const char *name, void (*f)(void), const char *sig) {
    PyObject *d = 0;
    PyObject *cobj = 0;
    union {
        void (*fp)(void);
        void *p;
    } tmp;
    d = PyObject_GetAttrString(__pyx_m, (char *)"__pyx_capi__");
    if (!d) {
        PyErr_Clear();
        d = PyDict_New();
        if (!d)
            goto bad;
        Py_INCREF(d);
        if (PyModule_AddObject(__pyx_m, (char *)"__pyx_capi__", d) < 0)
            goto bad;
    }
    tmp.fp = f;
#if PY_VERSION_HEX >= 0x02070000
    cobj = PyCapsule_New(tmp.p, sig, 0);
#else
    cobj = PyCObject_FromVoidPtrAndDesc(tmp.p, (void *)sig, 0);
#endif
    if (!cobj)
        goto bad;
    if (PyDict_SetItemString(d, name, cobj) < 0)
        goto bad;
    Py_DECREF(cobj);
    Py_DECREF(d);
    return 0;
bad:
    Py_XDECREF(cobj);
    Py_XDECREF(d);
    return -1;
}

/* InitStrings */
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif /* Py_PYTHON_H */
