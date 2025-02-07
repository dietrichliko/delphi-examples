#include <iostream>

#include "SkelanaAnalysis.hxx"
#include "skelana.hxx"

SkelanaAnalysis *SkelanaAnalysis::getInstance()
{
    if (!PhdstAnalysis::_instance)
    {
        PhdstAnalysis::_instance = new SkelanaAnalysis();
    }
    return static_cast<SkelanaAnalysis*>(PhdstAnalysis::_instance)
};

SkelanaAnalysis::SkelanaAnalysis() {};
SkelanaAnalysis::~SkelanaAnalysis() {};

void SkelanaAnalysis::user00()
{
    std::cout << "SkelanaAnalaysis::user00 called" << std::endl;
    
    // not very smart
    PHSET("FPE", 0);                                             
    PSINI();                                                           

    // Change the default values                                             
    // of control flags and keys                                             

    IFLTRA = 1;         // Track information
    IFLSIM = 1;         // Simulation                                          
    IFLBSP = 2;         // Beam spot                                            
    IFLBTG = 2;         // B-tagging
    IFLEMC = 1;         // Elm. calorimetry
    IFLHAC = 1;         // Had. calorimetry                                     
    IFLELE = 1;         // Electron identification                              
    IFLPHO = 1;         // Photon/pi0 identification
    IFLMUO = 1;         // Muon identification
    IFLHAD = 1;         // Hadron identification
    IFLVDH = 1;         // Vertex detector
    IFLRV0 = 1;         // V0 reconstruction
    IFLPHO = 1;         // photon/pi0 identification
    IFLPHC = 1;         // Converted photon
    IFLSTR = 0;         // Track selection (LVLOCK filling)
    IFLJET = 1;         // jet reconstruction
                                                                           
    // Change the default acceptance conditions for                          
    // detectors/triggers of the "RUNQUALITY" files                          
                                                                           
    //  MVX_A and MVX_C                                                       
    IRQDMN(1) = 1;                                                         
    IRQDMN(2) = 1;                                                        
                                                                           
    // TPC_0 and TPC_1                                                       
    IRQDMN(5) = 7;                                                         
    IRQDMN(6) = 7;                                                         
                                                                           
    // Read the runquality files
    PSRUNQ(0);    
};

int SkelanaAnalysis::user01()
{
    std::cout << "SkelanaAnalaysis::user01 called" << std::endl;
    return 1;
};

void SkelanaAnalysis::user02()
{
    std::cout << "SkelanaAnalaysis::user02 called" << std::endl;
};

void SkelanaAnalysis::user99()
{
    std::cout << "SkelanaAnalaysis::user99 called" << std::endl;
};