#include <boost/program_options.hpp>
#include <iostream>
#include <vector>
#include <string>

namespace po = boost::program_options;


int main(int argc, const char *argv[]) {
    po::options_description desc("Allowed options");  //class that controls things
    po::positional_options_description p;

    p.add("input-file", -1);

    int opt;

    //when accessing the arguments, you have to add -- to the from ("--help")
    desc.add_options() //<option name>, <information about the value>, <options description>
    ("help", "produce help message")
    ("compression", po::value<int>(), "set compression level")
    ("optimisation", po::value<int>(&opt)->default_value(10), "optimisataion level") //specifying the address and the default option
    ("include-path,I", po::value<std::vector<std::string>>(), "include path") //inlcude the short option name
    ("input-file", po::value<std::vector<std::string>>(), "input file"); 

    po::variables_map vm;
    po::store(po::command_line_parser(argc,argv).options(desc).positional(p).run(), vm);
    po::notify(vm); 

    if (vm.count("help")) {
        std::cout <<  desc << '\n';
        return 1;
    }

    if (vm.count("compression")) {
        std::cout <<  "Compresssion level was set to "
        << vm["compression"].as<int>() << ".\n";
    } else {
        std::cout << "Compression level was not set.\n";
    }

    if (vm.count("include-path")) {
     std::vector<std::string> names = vm["include-path"].as<std::vector<std::string>>();
  
    std::cout << "Include paths are: "; 
        
    for (auto a: names) {
        std::cout <<  a << " ";
    }
        std::cout << std::endl;
    }

    if (vm.count("input-file")) {
        std::vector<std::string> names = vm["input-file"].as<std::vector<std::string>>();
  
        std::cout << "Input files are: "; 
        
        for (auto a: names) {
            std::cout <<  a << " ";
        }
        std::cout << std::endl;
    }

    std::cout <<  "Optimisation level is " << opt << std::endl;
    return 0;
}
