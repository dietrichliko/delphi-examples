#ifndef PHDST_HXX
#define PHDST_HXX

#include <cstring>

extern "C" void phdst_(char *, int *, int *, size_t);
#define PHDST(A,B,C) phdst_(A,&B,&C,std::strlen(A))

#define USER00() extern "C" void user00_()
#define USER01(A) extern "C" void user01_(A)
#define USER02() extern "C" void user02_()
#define USER99() extern "C" void user99_()

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

int * LQ = &uxcom_.luxstr[0];
int * IQ = &uxcom_.luxstr[8]; 
float * Q = (float*)&uxcom_.luxstr[8];

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

#endif
