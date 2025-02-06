#ifndef SKELANA_HXX
#define SKELANA_HXX

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

#define VECP_px(i) pucpp_.vecp[i]
#define VECP_py(i) pucpp_.vecp[3*MTRACK+i]
#define VECP_pz(i) pucpp_.vecp[6*MTRACK+i]
#define VECP_energy(i) pucpp_.vecp[9*MTRACK+i]
#define VECP_mass(i) pucpp_.vecp[12*MTRACK+i]
#define VECP_p(i) pucpp_.vecp[15*MTRACK+i]
#define VECP_charge(i) pucpp_.vecp[18*MTRACK+i]
#define VECP_masscode(i) pucpp_.vecp[21*MTRACK+i]
#define IVECP_massid(i) (int)pucpp_.vecp[24*MTRACK+i]
#define IVECP_jetnr(i) (int)pucpp_.vecp[27*MTRACK+i]

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
#define LVLOCK(i) pscvec_.lvlock[i]
#define INVEP(i) pscvec_.invecp[i]

#endif