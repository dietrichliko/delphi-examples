#ifndef PHDST_ANALYSIS_HXX
#define PHDST_ANALYSIS_HXX

#include <string>

class PhdstAnalysis
{
public:
    static PhdstAnalysis *getInstance();
    virtual int run(const std::string &option);
    virtual void user00();
    virtual int user01();
    virtual void user02();
    virtual void user99();

protected:
    PhdstAnalysis();
    PhdstAnalysis(PhdstAnalysis &) = delete;
    virtual ~PhdstAnalysis();

    static PhdstAnalysis *_instance;
};

#endif