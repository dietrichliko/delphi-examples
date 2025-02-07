#include "SkelanaAnalysis.hxx"

#include "PhdstAnalysis.cxx"


int main()
{
    PhdstAnalysis *analysis = SkelanaAnalysis::getInstance();
    analysis->run(" ");
}