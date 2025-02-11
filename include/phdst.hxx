// Project: DELPHI Examples
// File: include/phdst.hxx
//
// C++ to Fortran bindings for PHDSTXX.CAR
// Author: Dietrich Liko <Dietrich.Liko@oeaw.ac.at>

#ifndef PHDST_HXX
#define PHDST_HXX

#include <string>
#include <cstring>

// Runs PHDST from the main program.
//
// int flag;
// PHDST(' ', 0, flag);
//
extern "C" void phdst_(char *, int *, int *, size_t);
inline void PHDST(const std::string& option, int dummy, int & flag)
{
    char * opt = strdup(option.c_str());
    phdst_(opt, &dummy, &flag, strlen(opt));
    free(opt);
};

// Set PHDST options.
//
// PHSET("FPE", 0);
//
extern "C" void phset_(char *, int *, size_t);
inline void PHSET(const std::string& option, int value)
{
    char * opt = strdup(option.c_str());
    phset_(opt, &value, strlen(opt));
    free(opt);
};

// Return type of data record. 
// For analysis usualy only DST type records are of interest 
//
// std::string rectype = PHRTY();
//
extern "C" void phrty_(char *);
inline std::string PHRTY()
{
    char response []= "1234";
    phrty_(response);
    return std::string(response,4);

};

// Find a Pilot record blocklet by name.
//
// int ipos = IPPIC("IDEN", 0);
// int ihad4 = IPILOT(ipos+4);
//
extern "C" int iphpic_(char *, int *, size_t);
inline int IPHPIC(const std::string & name, int value)
{
    char * c_name = strdup(name.c_str());
    int i = iphpic_(c_name, &value, strlen(c_name));
    free(c_name);
    return i;
}

// Kernlib timeing routine TIMED
//
// float time;
// TIMED(time);
//
extern "C" void timed_(float *);
inline void TIMED(float & time)
{
    timed_(&time);
};

// Kernlib timeing routine TIMEX
//
// float time;
// TIMEX(time);
//
extern "C" void timex_(float *);
inline void TIMEX(float & time)
{
    timex_(&time);
};

// User routines, which are called by PHDST.
// The analysis has to be implemented in these routines
//
// In case of the PhdstAnalysis helper class, the corresponding methodes are
// called by the implentation.
//
// extern "C" USER00() { };                    # Initilise
// extern "C" USER01(int & need) { need = 1;}; # Select events based on pilot record 
// extern "C" USER02() {};                     # Process event
// extern "C" USER99() {};                     # Terminate

extern "C" void user00_();
extern "C" void user01_(int *);
extern "C" void user02_();
extern "C" void user99_();

#define USER00 user00_
#define USER01(A) user01_(A)
#define USER02 user02_
#define USER99 user99_

extern "C" struct {
    int phgfst;
    int nfzfil;
    int nfzpil;
    int nfzget;
    int nfzpix;
    int nfzgex;
    int nevent;
    int ngoods;
    int nevenx;
    int ngoodx;
    int intrct;
    float timtot;
    float timend;
    int maxpst;
    int limpsf;
    int lapstg;
    int nfilou;
    int ndssav[10];
    int packed;
    int ivpack;
    float filimt;
    int filacc;
    int stgputw;
    int sgnexit;
    int phglst;
} phgen_;

 #define PHGFST phgen_.phgfst
 #define NFZFIL phgen_.nfzfil
 #define NFZPIL phgen_.nfzpil
 #define NFZGET phgen_.nfzget
 #define NFZPIX phgen_.nfzpix
 #define NFZGEX phgen_.nfzgex
 #define NEVENT phgen_.nevent
 #define NGOODS phgen_.ngoods
 #define NEVENX phgen_.nevenx
 #define NGOODX phgen_.ngoodx
 #define INTRCT phgen_.intrct
 #define TIMTOT phgen_.timtot
 #define TIMEND phgen_.timend
 #define MAXPST phgen_.maxpst
 #define LIMPSF phgen_.limpsf
 #define LAPSTG phgen_.lapstg
 #define NFILOU phgen_.nfilou
 #define NDSSAV phgen_.ndssav
 #define PACKED phgen_.packed
 #define IVPACK phgen_.ivpack
 #define FILIMT phgen_.filimt
 #define FILACC phgen_.filacc
 #define STGPUTW phgen_.stgputw
 #define SGNEXIT phgen_.sgnexit
 #define PHGLST phgen_.phglst  

extern "C" struct {
    int iiiexp;
    int iiirun;
    int iifile;
    int iiievt;
    int iiidat;
    int iiitim;
    int iifill;
} phciii_;

#define IIIEXP phciii_.iiiexp
#define IIIRUN phciii_.iiirun
#define IIIEVT phciii_.iiievt
#define IIIDAT phciii_.iiidat
#define IIITIM phciii_.iiitim
#define IIFILL phciii_.iifill


extern "C" struct {
    int uxfenv[10];
    int luxstr[30];
    int luxref[30];
} uxcom_;

#define LQ(I) = uxcom_.luxstr[(I)-1];
#define IQ(I) = uxcom_.luxstr[(I)+7]; 
#define Q(I) = (float)uxcom_.luxstr[(I)+7];

extern "C" struct {
    int ltemp;
    int lrtop;
    int lstop;
    int lttop;
    int litop;
    int lrtemp;
    int lrwtmp;
    int lrawux;
    int lbktop;
    int lortop;
    int lrtint;
    int ldtop;
} uxlink_;

#define LDTOP uxlink_.ldtop

#define NWPXMA 1024
extern "C" struct {
    int nwpilt;
    int iupilt[NWPXMA];
} pxchdr_;

#define NWPILT pxchdr_.nwpilt
#define NPILOT pxchdr_.nwpilt
#define IUPILT(I) pxchdr_.iupilt[(I)-1]
#define IPILOT(I) pxchdr_.iupilt[(I)-1]

#endif
