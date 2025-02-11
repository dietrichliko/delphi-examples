
#include <iostream>

#include "PhdstAnalysis.hxx"
#include "phdst.hxx"

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

int PhdstAnalysis::run(const std::string &option)
{
    int flag = 0;
    PHDST(option, 0, flag);
    return flag;
};

void PhdstAnalysis::user00()
{
    std::cout << "PhdstAnalaysis::user00 called" << std::endl;
};

int PhdstAnalysis::user01()
{
    std::cout << "PhdstAnalaysis::user01 called" << std::endl;
    std::cout << "Record type: " << PHRTY() << std::endl;
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

extern "C" void USER00()
{
    PhdstAnalysis::getInstance()->user00();
};

extern "C" void USER01(int * need)
{
    *need = PhdstAnalysis::getInstance()->user01();
};

extern "C" void USER02()
{
    PhdstAnalysis::getInstance()->user02();
};

extern "C" void USER99()
{
    PhdstAnalysis::getInstance()->user99();
};
