#include "hwwtree.h"
#include "rooutil.h"
#include "utility.h"

// ./process INPUTFILEPATH OUTPUTINDEX [NEVENTS]
int main(int argc, char** argv)
{

    util::parse_arguments(argc, argv);
    util::initialize_analysis();
    util::set_cuts();
    util::create_histograms();
    util::book_histograms();
    util::run_analysis();

    return 0;
}
