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

private:
    SkelanaAnalysis();
    SkelanaAnalysis(SkelanaAnalysis &) = delete;
};
#endif