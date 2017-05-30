#include <iostream>

#include <boost/program_options.hpp>
#include <boost/format.hpp>
#include "myjq_config.h"
#include "parser.h"

namespace po = boost::program_options;

using namespace std;

int main(int argc, char* argv[]) {
  parser::Object obj();
  po::options_description desc("Allowed options");

  desc.add_options()
    ("help", "produce help message")
    ("version", "version")
    ("compression", po::value<double>(), "set compression level")
    ;

  po::variables_map vm;

  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("version")) {
    cout << boost::format("myjq v%1%.%2%.%3%") % myjq_VERSION_MAJOR % myjq_VERSION_MINOR % myjq_VERSION_PATCH;
    cout << endl;
  }

  if (vm.count("help")) {
    cout << desc << endl;
    return 0;
  }

  if (vm.count("compression")) {
    cout << "compression level was set to "
         << vm["compression"].as<double>() << "." << endl;
  } else {
    cout << "compresion level not set." << endl;
  }
}
