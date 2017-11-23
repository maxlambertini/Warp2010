#ifndef LIBNOISELUA_GLOBAL_H
#define LIBNOISELUA_GLOBAL_H

#  ifdef Q_OS_WIN
#    define Q_DECL_EXPORT     __declspec(dllexport)
#    define Q_DECL_IMPORT     __declspec(dllimport)
# else
#    define Q_DECL_EXPORT
#    define Q_DECL_IMPORT
#endif



#if defined(LIBNOISELUA_LIBRARY)
#  define LIBNOISELUASHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBNOISELUASHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBNOISELUA_GLOBAL_H
