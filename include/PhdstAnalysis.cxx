
#include <iostream>

#include "PhdstAnalysis.hxx"


PhdstAnalysis *PhdstAnalysis::_instance = nullptr;

PhdstAnalysis *PhdstAnalysis::getInstance()
{
    if (!PhdstAnalysis::_instance)
    {
        PhdstAnalysis::_instance = new PhdstAnalysis();
    }
    return _instance;
};

PhdstAnalysis::PhdstAnalysis() {};
PhdstAnalysis::~PhdstAnalysis() {};

int PhdstAnalysis::run(const std::string& option)
{
    char * opt = strdup(option.c_str());
    int dummy = 0;
    int flag;
    PHDST(opt, dummy, flag);
    return flag;
};

void PhdstAnalysis::user00()
{
    std::cout << "PhdstAnalaysis::user00 called" << std::endl;
};

int PhdstAnalysis::user01()
{
    std::cout << "PhdstAnalaysis::user01 called" << std::endl;
    return 1;
};

void PhdstAnalysis::user02()
{
    std::cout << "PhdstAnalaysis::user02 called" << std::endl;
};

void PhdstAnalysis::user99()
{
    std::cout << "PhdstAnalaysis::user99 called" << std::endl;
};

USER00()
{
    PhdstAnalysis::getInstance()->user00();
};

USER01(int &need)
{
    need = PhdstAnalysis::getInstance()->user01();
};

USER02()
{
    PhdstAnalysis::getInstance()->user02();
};

USER99()
{
    PhdstAnalysis::getInstance()->user99();
};

