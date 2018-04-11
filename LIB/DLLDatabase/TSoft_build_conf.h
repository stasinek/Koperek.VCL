#ifdef  BUILD_DLLDATABASE
#define DATABASE_IMPEXP __declspec(dllexport)
#else
#define DATABASE_IMPEXP __declspec(dllimport)
#endif

