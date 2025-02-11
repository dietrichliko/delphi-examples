#ifndef ANALYSIS_HXX
#define ANALYSIS_HXX

#include <memory>
#include <string>

#include "TFile.h"
#include "TTree.h"

#include "SkelanaAnalysis.hxx"
#include "skelana.hxx"

class Analysis06 : public SkelanaAnalysis
{
public:
    static Analysis06 *getInstance(const std::string & output, bool isMC);

private:
    Analysis06(const std::string& output, bool isMC);
    Analysis06(Analysis06 &) = delete;
    virtual ~Analysis06();
    virtual void initialise();
    virtual void process();
    virtual void terminate();
    void branch(const std::string& name, void * address, const std::string& leaflist, const std::string& title);

    std::unique_ptr<TFile> _tfile;
    std::unique_ptr<TTree> _ttree;
    std::string _output;
    bool _isMC;

    float _partPx[MTRACK];
    float _partPy[MTRACK];
    float _partPz[MTRACK];
    float _partEnergy[MTRACK];
    float _partMass[MTRACK];
    float _partMomentum[MTRACK];
    float _partCharge[MTRACK];
    float _partMassCode[MTRACK];
    int _partMassId[MTRACK];
    int _partJetIdx[MTRACK];
    int _partHemiIdx[MTRACK];
    int _partVtxCode[MTRACK];
    int _partVtxIdx[MTRACK];

    float _simPartPx[MTRACK];
    float _simPartPy[MTRACK];
    float _simPartPz[MTRACK];
    float _simPartEnergy[MTRACK];
    float _simPartMass[MTRACK];
    float _simPartMomentum[MTRACK];
    float _simPartCharge[MTRACK];
    float _simPartMassCode[MTRACK];

    int _genPartParentIdx[NPMAX];
    int _genPartFirstChildIdx[NPMAX];
    int _genPartLastChildIdx[NPMAX];
    
};

#endif