//---------------------------------------------------------------------------
//--------COPYRIGHT: Stanislaw Stasiak sstsoft.pl @2001-2002-----------------
//--------https://github.com/stasinek/Koperek.VCL----------------------------
//---------------------------------------------------------------------------
#ifdef BUILD_DLLIO
    // To build library .dll or link statically expport all functions
    #define IMPEXP __declspec(dllexport)
#else
    // Shall be defined to use .dll use headers to import functions from library
    #define IMPEXP __declspec(dllimport)
#endif
//---------------------------------------------------------------------------

