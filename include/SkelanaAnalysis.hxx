#ifndef SKELANA_ANALYSIS_HXX
#define SKELANA_ANALYSIS_HXX

#include "PhdstAnalysis.hxx"

class SkelanaAnalysis : public PhdstAnalysis
{
public:
    static SkelanaAnalysis *getInstance();
    virtual ~SkelanaAnalysis();
    virtual void user00();
    virtual int user01();
    virtual void user02();
    virtual void user99();
    virtual void initialise();
    virtual void process();
    virtual void terminate();

    void enableRunSelection();
    void setMaxEventsToProcess(int max);
    void selectT4Hadrons();


protected:
    SkelanaAnalysis();
    SkelanaAnalysis(SkelanaAnalysis &) = delete;

private:
    bool _runSelection;
    int _maxEventsToProcess;
    bool _selectT4Hadrons;
};
#endif