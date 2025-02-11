#include <iostream>
#include <vector>
#include <string>

#include "Analysis06.hxx"

int main(int argc, char **argv)
{
    bool isMC = false;
    std::string output("example06.root");

    // cmdline parsing
    std::vector<std::string> args(argv + 1, argv + argc);
    for (auto i = args.begin(); i != args.end(); ++i)
    {
        if ((*i == "-h") | (*i == "--help"))
        {
            std::cerr << "Usage: example06 [--mc] [--output OUTPUT]" << std::endl;
            return EXIT_SUCCESS;
        }
        else if (*i == "--mc")
        {
            isMC = true;
        }
        else if (*i == "--output")
        {
            ++i;
            if (i != args.end())
            {
                output = *i;
            }
            else
            {
                std::cerr << "ERROR: Missing argument for --output." << std::endl;
                return EXIT_FAILURE;
            };
        }
        else
        {
            std::cerr << "ERROR: Invalid option " << *i << std::endl;
            return EXIT_FAILURE;
        };
    };

    Analysis06 *analysis = Analysis06::getInstance(output, isMC);
    analysis->run(" ");
    return EXIT_SUCCESS;
}