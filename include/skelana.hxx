// Project: DELPHI Examples
// File: include/skelana.hxx
//
// C++ to Fortran bindings for SKELANA.CAR
// Author: Dietrich Liko <Dietrich.Liko@oeaw.ac.at>

#ifndef SKELANA_HXX
#define SKELANA_HXX

#include <string>
#include <cstring>

extern "C" void psini_();
inline void PSINI() { psini_(); };

extern "C" void psbeg_();
inline void PSBEG() { psbeg_(); };

extern "C" void psrunq_(int *);
inline void PSRUNQ(int value)
{
    psrunq_(&value);
};

extern "C" void psruns_(int *);
inline void PSRUNS(int & isel)
{
    psruns_(&isel);
};

extern "C" struct 
{
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

//
//      NVECP               - Number of particles in VECP
//     NCVECP               - Number of charged particles
//     NNVECP               - Number of neutral particles
//     NVECMC               - Number of simulated tracks
//     NJET                 - Number of jets
//       VECP(10, 3//MTRACK) - Real    vector of particle info
//      IVECP(10, 3//MTRACK) - Integer vector of particle info
//      LVECP    (3//MTRACK) - LPA/LST links    of the tracks
//     INVECP    (3//MTRACK) - LPA/LST indecies of the tracks
//     LVLOCK    (3//MTRACK) - Bitted word per track
//
//      VECP( 1,I) - P(x)
//      VECP( 2,I) - P(y)
//      VECP( 3,I) - P(z)
//      VECP( 4,I) - E
//      VECP( 5,I) - Mass
//      VECP( 6,I) - |P|
//      VECP( 7,I) - Charge
//      VECP( 8,I) - Mass code
//     IVECP( 9,I) - Mass identification
//     IVECP(10,I) - Jet number
//
#define MTRACK 300

extern "C" struct 
{
    float vecp[3*MTRACK][10];
} pucppp_ ;

#define VECP(I,J) pucppp_.vecp[(J)-1][(I)-1]
#define IVECP(I,J) static_cast<int>(VECP(I,J))

extern "C" struct 
{
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
#define IRQDET(I) pscrnq_.irqdet[(I)-1]
#define IRQTRQ(I) pscrnq_.irqtrq[(I)-1]
#define NSRUNS pscrnq_.nsruns
#define IFRUNS(I) pscrnq_.ifruns[(I)-1]
#define ILRUNS(I) pscrnq_.ilruns[(I)-1]
#define IFFILE(I) pscrnq_.iffile[(I)-1]
#define ILFILE(I) pscrnq_.ilfile[(I)-1]


extern "C" struct 
{
    int isver;
    int ihad4;
    int nctr4;
    int nctrk;
    int nntrk;
    float ecmas;
    float echar;
    float emneu;
    float ehneu;
} pscevt_;

#define ISVER pscevt_.isver
#define IHAD4 pscevt_.ihad4
#define NCTR4 pscevt_.nctr4
#define NCTRK pscevt_.nctrk
#define NNTRK pscevt_.nntrk
#define ECMAS pscevt_.ecmas
#define EMNEU pscevt_.emneu
#define EHNEU pscevt_.ehneu

extern "C" struct 
{
    char cdtype[4];
    char labo[4];
} pscevc_;

inline std::string CDTYPE()
{
    return std::string(pscevc_.cdtype, 4);
};

inline std::string LABO()
{
    return std::string(pscevc_.labo, 4);
};

//
//     NP      - number of particles in current event
//
//     KP(I,1) - status code KS of the current particle
//     KP(I,2) - particle code KF (Particle Data Group)
//     KP(I,3) - index of parent particle, or jet, or 0
//     KP(I,4) - index of the first daughter, if none 0
//     KP(I,5) - index of the last  daughter, if none 0
//
//     PP(I,1) - Px, momentum in the x direction, in GeV/c
//     PP(I,2) - Py, momentum in the y direction, in GeV/c
//     PP(I,3) - Pz, momentum in the z direction, in GeV/c
//     PP(I,4) - E , energy, in GeV
//     PP(I,5) - m , mass, in GeV/c////2
//
//     VP(I,1) - x position of production vertex, in mm
//     VP(I,2) - y position of production vertex, in mm
//     VP(I,3) - z position of production vertex, in mm
//     VP(I,4) - time of production
//     VP(I,5) - proper lifetime of the particle, or 0.
//
#define NPMAX 4000
extern "C" struct 
{
    int np;
    int kp[5][NPMAX];
    float pp[5][NPMAX];
    float vp[5][NPMAX];
} pscluj_;

#define NP pscluj_.np
#define KP(I,J) pscluj_.kp[(J)-1][(I)-1]
#define PP(I,J) pscluj_.pp[(J)-1][(I)-1]
#define VP(I,J) pscluj_.vp[(J)-1][(I)-1]

//
//     NVTX                  - Number of reconstr. vertices
//     NVTXMC                - Number of simulated vertices
//     NVTXMX                - Maximum number  of  vertices
//     LENVTX                - Length of vertex information
//     QVTX(LENVTX,2//NVTXMX) - Real    array  of VTX info
//     KVTX(LENVTX,2//NVTXMX) - Integer array  of VTX info
//     LVTX       (2//NVTXMX) - LPV/LSP links for vertices
//
//     KVTX( 1,I) - Index of the first outgoing particle
//     KVTX( 2,I) - Index of the incomming particle
//     KVTX( 3,I) - Nb of outgoing particles (multiplicity)
//     KVTX( 4,I) - Nb of degree of freedom of the vertex fit
//     KVTX( 5,I) - Mass code of the origin particle
//     QVTX( 6,I) - X
//     QVTX( 7,I) - Y    coordinates of the vertex
//     QVTX( 8,I) - Z
//     QVTX( 9,I) - Chi2 of the vertex fit
//     QVTX(10,I) - XX
//     QVTX(11,I) - XY
//     QVTX(12,I) - YY   Error matrix
//     QVTX(13,I) - XZ
//     QVTX(14,I) - YZ
//     QVTX(15,I) - ZZ
//     KVTX(16,I) - Error flag
//     KVTX(17,I) - Vertex status bits :
//                  bit 1 set on if dummy vertex
//                  bit 2 set on if secondary vertex
//                  bit 3 set on if secondary hadronic vertex
//                  bit 4 set on if vertex with simulation data
//
#define LENVTX 17
#define NVTXMX 150

extern "C" struct
{
    int nvtx;
    int nvtxmc;
    int kvtx[2*NVTXMX][LENVTX];
} pscvtx_;

#define NVTX pscvtx_.nvtx
#define NVTXMC pscvtx_.nvtxmc
#define KVTX(I,J) pscvtx_.kvtx[(J)-1][(I)-1]

#endif