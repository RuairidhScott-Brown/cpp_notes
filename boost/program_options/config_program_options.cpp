#include <boost/program_options.hpp>
#include <iostream>
#include <vector>
#include <string>

namespace po = boost::program_options;



int main(int argc, const char *argv[]) {
    //options that are allowed only on the command line
    po::options_description Generic("Generic options");  //class that controls things
    Generic.add_options()
    ("version,v", "print version string")
    ("help", "produce help message");

    int opt;

    //options that are allowed on the command line and in the config file
    po::options_description config("Configuration");
    config.add_options()
    ("optimization", po::value<int>(&opt)->default_value(10), "optimization level")
    ("include-path,I", po::value<std::vector<std::string>>()->composing(), "include path"); //values from different source should be composed together

    //allowed in config file and on the command line but not shown to the user
    po::options_description hidden("Hidden options");
    hidden.add_options()
    ("input-file", po::value<std::vector<std::string>>(), "input file"); 

    po::options_description cmdline_options;
    cmdline_options.add(Generic).add(config).add(hidden);

    po::options_description config_file_options;
    config_file_options.add(config).add(hidden);

    po::options_description visible("Allowed options");
    visible.add(Generic).add(config);    

    /* TO BE CONTINUED */
    // https://valelab4.ucsf.edu/svn/3rdpartypublic/boost/doc/html/program_options/tutorial.html




    return 0;
}