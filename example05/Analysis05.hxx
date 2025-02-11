#ifndef ANALYSIS_HXX
#define ANALYSIS_HXX

#include "SkelanaAnalysis.hxx"

class Analysis05 : public SkelanaAnalysis
{
public:
    static Analysis05 *getInstance();

private:
    Analysis05();
    Analysis05(Analysis05 &) = delete;
    virtual ~Analysis05();
    virtual void initialise();
    virtual void process();
    virtual void terminate();
};

#endif