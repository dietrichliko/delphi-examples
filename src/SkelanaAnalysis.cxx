#include <iostream>

#include "SkelanaAnalysis.hxx"
#include "phdst.hxx"
#include "skelana.hxx"

SkelanaAnalysis *SkelanaAnalysis::getInstance()
{
    if (!PhdstAnalysis::_instance)
    {
        PhdstAnalysis::_instance = new SkelanaAnalysis();
    }
    return static_cast<SkelanaAnalysis *>(PhdstAnalysis::_instance);
};

SkelanaAnalysis::SkelanaAnalysis() : _runSelection(false), _maxEventsToProcess(0), _selectT4Hadrons(false) {};
SkelanaAnalysis::~SkelanaAnalysis() {};

void SkelanaAnalysis::enableRunSelection()
{
    _runSelection = true;
};

void SkelanaAnalysis::setMaxEventsToProcess(int max)
{
    _maxEventsToProcess = max;
};

void SkelanaAnalysis::selectT4Hadrons()
{
    _selectT4Hadrons = true;
}

void SkelanaAnalysis::user00()
{
    // std::cout << "SkelanaAnalaysis::user00 called" << std::endl;

    // supress floating point errros
    PHSET("FPE", 0);
    // Initialse Skelana
    PSINI();

    // Change the default value of control flags and keys
    // Values can be changed in a derived constructor

    IFLTRA = 1; // Track information
    IFLSIM = 1; // Simulation
    IFLBSP = 2; // Beam spot
    IFLBTG = 2; // B-tagging
    IFLEMC = 1; // Elm. calorimetry
    IFLHAC = 1; // Had. calorimetry
    IFLELE = 1; // Electron identification
    IFLPHO = 1; // Photon/pi0 identification
    IFLMUO = 1; // Muon identification
    IFLHAD = 1; // Hadron identification
    IFLVDH = 1; // Vertex detector
    IFLRV0 = 1; // V0 reconstruction
    IFLPHO = 1; // photon/pi0 identification
    IFLPHC = 1; // Converted photon
    IFLSTR = 0; // Track selection (LVLOCK filling)
    IFLJET = 1; // jet reconstruction

    // Change the default acceptance conditions for
    // detectors/triggers of the "RUNQUALITY" files

    //  MVX_A and MVX_C
    IRQDMN(1) = 1;
    IRQDMN(2) = 1;

    // TPC_0 and TPC_1
    IRQDMN(5) = 7;
    IRQDMN(6) = 7;

    // Read the runquality files
    if (_runSelection)
    {
        PSRUNQ(0);
    };

    // call the
    initialise();
};

int SkelanaAnalysis::user01()
{
    // std::cout << "SkelanaAnalaysis::user01 called" << std::endl;

    std::string recType = PHRTY();

    if ((recType == "SOR ") |
        (recType == "COR ") |
        (recType == "EOR ") |
        (recType == "SOS ") |
        (recType == "BOF ") |
        (recType == "CPT ") |
        (recType == "0072"))
    {
        return 0;
    };

    if (_maxEventsToProcess > 0)
    {
        if (NEVENT > _maxEventsToProcess)
        {
            return -3;
        };
    };

    if ((recType != "DST ") & (recType != "MINI"))
    {
        if (_selectT4Hadrons)
        {
            int iden = IPHPIC("IDEN", 1);
            bool hadronFlag = iden >= 0 ? (IPILOT(iden + 6) & 0b11) == 0b11 : false;
            if (!hadronFlag)
            {
                return 0;
            };
        };
        if (_runSelection)
        {
            int irsel = 0;
            PSRUNS(irsel);
            if (irsel == 0)
            {
                return 0;
            };
        };
        return 1;
    };

    if (recType == "DST ")
    {
        return 1;
    };

    std::cout << "ERROR: Event not in DST format. Run " << IIIRUN
              << ", Event " << IIIEVT << ", " << NEVENT << std::endl;
    return 0;
};

void SkelanaAnalysis::user02()
{
    // std::cout << "SkelanaAnalaysis::user02 called" << std::endl;
    // Skelana start of event
    PSBEG();

    // analyse the event
    process();

    // Skelana end of event
    float time;
    TIMED(time);
    if ((NGOODS > 0) & (NGOODS % 10000 == 0))
    {
        TIMEX(time);
    };
};

void SkelanaAnalysis::user99()
{
    // std::cout << "SkelanaAnalaysis::user99 called" << std::endl;
    terminate();
};

void SkelanaAnalysis::initialise()
{
    std::cout << "Initialise the analysis." << std::endl;
};

void SkelanaAnalysis::process()
{
    std::cout << "Process an event" << std::endl;
};

void SkelanaAnalysis::terminate()
{
    std::cout << "Terminate the analysis" << std::endl;
}