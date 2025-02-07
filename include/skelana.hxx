#ifndef SKELANA_HXX
#define SKELANA_HXX

#include <cstring>

extern "C" void phset_(char *, int *, size_t);
#define PHSET(A,B) {char * a = strdup(A); int b = B; phset_(a,&b,std::strlen(a)); free(a);}

extern "C" void psini_();
#define PSINI() psini_()

extern "C" void psrunq_(int *);
#define PSRUNQ(A) {int a = A; psrunq_(&a);}

extern "C" struct {
    int ifltra;
    int iflfix;
    int iflrnq;
    int iflstr;
    int ifljet;
    int iflsim;
    int iflbsp;
    int iflbtg;
    int iflemc;
    int iflhac;
    int iflstc;
    int iflele;
    int iflpho;
    int iflmuo;
    int iflhad;
    int iflvdh;
    int iflrv0;
    int iflute;
    int iflphc;
    int iflvec;
    int iflbhp;
    int iflecl;
    int iflrvr;
    int iflodr;
    int iflpvt;
    int iflcut;
    int iflvdr;
    int iflfct;
    int iflenr;
} pscflg_;

#define  IFLTRA pscflg_.ifltra
#define  IFLFIX pscflg_.iflfix
#define  IFLRNQ pscflg_.iflrnq
#define  IFLSTR pscflg_.iflstr
#define  IFLJET pscflg_.ifljet
#define  IFLSIM pscflg_.iflsim
#define  IFLBSP pscflg_.iflbsp
#define  IFLBTG pscflg_.iflbtg
#define  IFLEMC pscflg_.iflemc
#define  IFLHAC pscflg_.iflhac
#define  IFLSTC pscflg_.iflstc
#define  IFLELE pscflg_.iflele
#define  IFLPHO pscflg_.iflpho
#define  IFLMUO pscflg_.iflmuo
#define  IFLHAD pscflg_.iflhad
#define  IFLVDH pscflg_.iflvdh
#define  IFLRV0 pscflg_.iflrv0
#define  IFLUTE pscflg_.iflute
#define  IFLPHC pscflg_.iflphc
#define  IFLVEC pscflg_.iflvec
#define  IFLBHP pscflg_.iflbhp
#define  IFLECL pscflg_.iflecl
#define  IFLRVR pscflg_.iflrvr
#define  IFLODR pscflg_.iflodr
#define  IFLPVT pscflg_.iflpvt
#define  IFLCUT pscflg_.iflcut
#define  IFLVDR pscflg_.iflvdr
#define  IFLFCT pscflg_.iflfct
#define  IFLENR pscflg_.iflenr

#define MTRACK 300

extern "C" struct {
    float vecp[3*10*MTRACK];
} pucppp_ ;

#define VECP(I,J) pucpp_.vecp[3*10*MTRACK*((I)-1)+(J)-1]
#define IVECP(I,J) (int)pucpp_.vecp[3*10*MTRACK*((I)-1)+(J)-1]

extern "C" struct {
    int nvecp;
    int ncvecp;
    int nnvecp;
    int nvecmc;
    int njet;
    int lvlock[3*MTRACK];
    int invecp[3*MTRACK];
} pscvec_;

#define NVECP pscvec_.nvecp
#define NCVECP pscvec_.ncvecp
#define NNVECP pscvec_.nnvecp
#define NVECMC pscvec_.nvecmc
#define NJET pscvec_.njet
#define LVLOCK(I) pscvec_.lvlock[(I)-1]
#define INVEP(I) pscvec_.invecp[(I)-1]

#define MRQFIL 5000
#define NRQDET 38
#define NRQTRG 23
#define MSRUNS 3000

extern "C" struct {
    int nrqfil;
    int irqfil[MRQFIL];
    float erqfil[MRQFIL];
    int irqdmn[NRQDET];
    int irqdmx[NRQDET];
    int irqtmn[NRQTRG];
    int irqtmx[NRQTRG];
    int irqdet[NRQDET];
    int irqtrg[NRQDET];
    int nsruns;
    int ifruns[MSRUNS];
    int ilruns[MSRUNS];
    int iffile[MSRUNS];
    int ilfile[MSRUNS];
} pscrnq_;

#define NRQFIL pscrnq_.nrqfil
#define IRQFIL(I) pscrnq_.nrqfil[(I)-1]
#define ERQFIL(I) pscrnq_.erqfil[(I)-1]
#define IRQDMN(I) pscrnq_.irqdmn[(I)-1]
#define IRQDMX(I) pscrnq_.irqdmx[(I)-1]
#define IRQTMN(I) pscrnq_.irqtmn[(I)-1]
#define IRQTMX(I) pscrnq_.irqtmx[(I)-1]
#define IRQDET[I] pscrnq_.irqdet[(I)-1]
#define IRQTRQ[I] pscrnq_.irqtrq[(I)-1]
#define NSRUNS pscrnq_.nsruns
#define IFRUNS(I) pscrnq_.ifruns[(I)-1]
#define ILRUNS(I) pscrnq_.ilruns[(I)-1]
#define IFFILE(I) pscrnq_.iffile[(I)-1]
#define ILFILE(I) pscrnq_.ilfile[(I)-1]

#endif