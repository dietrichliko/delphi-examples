#include <iostream>
#include <iomanip>

#include "Analysis05.hxx"
#include "phdst.hxx"
#include "skelana.hxx"

Analysis05 *Analysis05::getInstance()
{
    if (!PhdstAnalysis::_instance)
    {
        PhdstAnalysis::_instance = new Analysis05();
    };
    return static_cast<Analysis05 *>(PhdstAnalysis::_instance);
};

Analysis05::Analysis05() {};
Analysis05::~Analysis05() {};

void Analysis05::initialise()
{
    std::cout << "Initialise the analysis." << std::endl;
};

void Analysis05::process()
{
    std::cout << "Process an event." << std::endl;

    static bool first = true;
    if (first)
    {
        std::cout << "DST Version = " << ISVER << ", Type = " << CDTYPE() << std::endl;
        first = false;
    }

    std::cout << "NRUN = " << IIIRUN << ", NEVT = " << IIIEVT << std::endl;
    std::cout << "NVECP = " << NVECP << std::endl;
    // Index with fortran conventions
    for (int i = 1; i <= NVECP; i++)
    {
        std::cout << std::setw(3) << i 
            // << std::setw(9) << std::fixed << std::setprecision(3) 
            << " : " << VECP(1,i) 
            << " " << VECP(2,i) 
            << " " << VECP(3,i) 
            << " " << VECP(4,i) 
            << " " << VECP(5,i)
            << " " << VECP(6,i)
            << " " << int(VECP(7,i))
            << " " << int(VECP(8,i))
            << " " << std::hex << IVECP(9,i)
            << " " << IVECP(10,i) << std::dec << std::endl;            
    };
};

void Analysis05::terminate()
{
    std::cout << "Terminate the analysis." << std::endl;
};
