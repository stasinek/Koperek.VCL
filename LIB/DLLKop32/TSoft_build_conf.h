#ifdef  BUILD_KOPDLL
#define KOP_IMPEXP __declspec(dllexport)
#else
#define KOP_IMPEXP __declspec(dllimport)
#endif

