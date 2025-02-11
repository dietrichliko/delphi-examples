#include <iostream>

#include "Analysis06.hxx"
#include "phdst.hxx"
#include "skelana.hxx"

Analysis06 *Analysis06::getInstance(const std::string &output, bool isMC)
{
    if (!PhdstAnalysis::_instance)
    {
        PhdstAnalysis::_instance = new Analysis06(output, isMC);
    };
    return static_cast<Analysis06 *>(PhdstAnalysis::_instance);
};

Analysis06::Analysis06(const std::string &output, bool isMC) : _output(output), _isMC(isMC) {};
Analysis06::~Analysis06() {};

void Analysis06::initialise()
{
    // std::cout << "Initialise the Analysis06." << std::endl;
    _tfile = std::make_unique<TFile>(_output.c_str(), "recreate");
    _ttree = std::make_unique<TTree>("Events", "DELPHI Event Data");

    branch("Event_nrun", &IIIRUN, "nrun/I", "Run number");
    branch("Event_ievt", &IIIEVT, "ievt/I", "Event number");

    branch("nPart", &NVECP, "nPart/I", "Number of particles");
    branch("Part_px", &_partPx, "Part_px[nPart]/F", "Particle momentum p_x");
    branch("Part_py", &_partPy, "Part_py[nPart]/F", "Particle momentum p_y");
    branch("Part_pz", &_partPz, "Part_pz[nPart]/F", "Particle momentum p_z");
    branch("Part_energy", &_partEnergy, "Part_energy[nPart]/F", "Particle energy");
    branch("Part_mass", &_partMass, "Part_mass[nPart]/F", "Particle mass");
    branch("Part_momentum", &_partMomentum, "Part_momentum[nPart]/F", "Particle momentum");
    branch("Part_charge", &_partCharge, "Part_charge[nPart]/F", "Particle charge");
    branch("Part_masscode", &_partMassCode, "Part_masscode[nPart]/F", "Particle mass code");
    branch("Part_massid", &_partMassId, "Part_massid[nPart]/I", "Particle mass code");
    branch("Part_jetIdx", &_partJetIdx, "Part_jetIdx[nPart]/I", "Particle jet index");
    branch("Part_hemiIdx", &_partHemiIdx, "Part_hemiIdx[nPart]/I", "Particle hemisphere index");
    branch("Part_vtxCode", &_partVtxCode, "Part_vtxCode[nPart]/I", "Vertex code");
    branch("Part_vtxIdx", &_partVtxIdx, "Part_vtxIdx[nPart]/I", "Vertex index");

    if (_isMC)
    {
        branch("nSimPart", &NVECMC, "nSimPart/I", "Number of simulated particles");
        branch("SimPart_px", &_simPartPx, "SimPart_px[nSimPart]/F", "Simulated Particle momentum p_x");
        branch("SimPart_py", &_simPartPy, "SimPart_py[nSimPart]/F", "Simulated Particle momentum p_y");
        branch("SimPart_pz", &_simPartPz, "SimPart_pz[nSimPart]/F", "Simulated Particle momentum p_z");
        branch("SimPart_energy", &_simPartEnergy, "SimPart_energy[nSimPart]/F", "Simulated Particle energy");
        branch("SimPart_mass", &_simPartMass, "SimPart_mass[nSimPart]/F", "Simulated Particle mass");
        branch("SimPart_momentum", &_simPartMomentum, "SimPart_momentum[nSimPart]/F", "Simulated Particle momentum");
        branch("SimPart_charge", &_simPartCharge, "SimPart_charge[nSimPart]/F", "Simulated Particle charge");
        branch("SimPart_masscode", &_simPartMassCode, "SimPart_masscode[nSimPart]/F", "Simulated Particle mass code");

        branch("nGenPart", &NP, "nGenPart/I", "Number of generated particles");
        branch("GenPart_status", &KP(1, 1), "GenPart_status[nGenPart]", "KS status code");
        branch("GenPart_masscode", &KP(2, 1), "GenPart_masscode[nGenPart]", "KF particle code (PDG)");
        branch("GenPart_parentIdx", &_genPartParentIdx, "GenPart_parentIdx[nGenPart]", "Index of parent particle, or jet, or -1");
        branch("GenPart_firstChildIdx", &_genPartFirstChildIdx, "GenPart_firstChildIdx[nGenPart]", "Index of the first child particle, jet or -1");
        branch("GenPart_lastChildIdx", &_genPartLastChildIdx, "GenPart_lastChildIdx[nGenPart]", "Index of the last child particle, jet or -1");
        branch("GenPart_px", &PP(1, 1), "GenPart_px[nGenPart]", "Px, momentum in the x direction, in GeV/c");
        branch("GenPart_py", &PP(1, 2), "GenPart_py[nGenPart]", "Py, momentum in the y direction, in GeV/c");
        branch("GenPart_pz", &PP(1, 3), "GenPart_pz[nGenPart]", "Pz, momentum in the z direction, in GeV/c");
        branch("GenPart_energy", &PP(1, 4), "GenPart_energy[nGenPart]", "E , energy, in GeV");
        branch("GenPart_mass", &PP(1, 5), "GenPart_mass[nGenPart]", "m , mass, in GeV/c**2");
        branch("GenPart_x", &VP(1, 1), "GenPart_x[nGenPart]", "x position of production vertex, in mm");
        branch("GenPart_y", &VP(1, 2), "GenPart_y[nGenPart]", "y position of production vertex, in mm");
        branch("GenPart_z", &VP(1, 3), "GenPart_z[nGenPart]", "z position of production vertex, in mm");
        branch("GenPart_t", &VP(1, 4), "GenPart_t[nGenPart]", "Time of production");
        branch("GenPart_tau", &VP(1, 5), "GenPart_tau[nGenPart]", "Proper lifetime of the particle, or 0.");
    };
};

void Analysis06::branch(const std::string &name, void *address, const std::string &leaflist, const std::string &title)
{
    TBranch *branch = _ttree->Branch(name.c_str(), address, leaflist.c_str());
    branch->SetTitle(title.c_str());
}

void Analysis06::process()
{
    // std::cout << "Process an event." << std::endl;

    for (int i = 0; i < NVECP; ++i)
    {
        _partPx[i] = VECP(1, i + 1);
        _partPy[i] = VECP(2, i + 1);
        _partPz[i] = VECP(3, i + 1);
        _partEnergy[i] = VECP(4, i + 1);
        _partMass[i] = VECP(5, i + 1);
        _partMomentum[i] = VECP(6, i + 1);
        _partCharge[i] = VECP(7, i + 1);
        _partMassCode[i] = VECP(8, i + 1);
        _partMassId[i] = IVECP(9, i + 1);
        _partJetIdx[i] = IVECP(10, i + 1) - 1;
        _partHemiIdx[i] = IVECP(10, i + 1) - 1;
    };

    if (_isMC)
    {
        for (int i = 0; i < NVECMC; ++i)
        {
            _simPartPx[i] = VECP(1, MTRACK + i + 1);
            _simPartPy[i] = VECP(2, MTRACK + i + 1);
            _simPartPz[i] = VECP(3, MTRACK + i + 1);
            _simPartEnergy[i] = VECP(4, MTRACK + i + 1);
            _simPartMass[i] = VECP(5, MTRACK + i + 1);
            _simPartMomentum[i] = VECP(6, MTRACK + i + 1);
            _simPartCharge[i] = VECP(7, MTRACK + i + 1);
            _simPartMassCode[i] = VECP(8, MTRACK + i + 1);
        };
    };

    _ttree->Fill();
};

void Analysis06::terminate()
{
    // std::cout << "Terminate the Analysis06." << std::endl;
    _ttree->Write();
    _tfile->Close();
};
