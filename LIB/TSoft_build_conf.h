#ifdef  BUILD_DLL
#ifndef IMPEXP
#define IMPEXP __declspec(dllexport)
#endif
#else
#ifndef IMPEXP
#define IMPEXP __declspec(dllimport)
#endif
#endif

