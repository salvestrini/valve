//
// This file is part of the valve package
//
// (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
//

#include "config.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

#include <getopt.h>

#include "defs.hh"
#include "utils.hh"
#include "ptree.hh"
#include "ast.hh"
#include "bytecode.hh"

static std::string version()
{
        std::stringstream ss;
        ss << PACKAGE_NAME << " " << PACKAGE_VERSION;
        return ss.str();
}

static void hint(const std::string & message)
{
        std::cerr << PROGRAM_NAME << ": " << message << std::endl;
        std::cerr << "Try `" << PROGRAM_NAME << " --help' for "
                  << "more information." << std::endl;
}

static void help()
{
        std::cout << "Usage: " << PROGRAM_NAME << " [OPTION].. [FILE]..."
                  << std::endl;
        std::cout << std::endl;
        std::cout << "  -h, --help       print this help, then exit"
                  << std::endl;
        std::cout << "  -V, --version    print version, then exit"
                  << std::endl;
        std::cout << std::endl;
        std::cout << "Report bugs to <" << PACKAGE_BUGREPORT << ">"
                  << std::endl;
}

void handle(const std::string & filename)
{
        ptree p;
        {
                timedelta delta("parse-tree");
                p.parse(filename);
        }

        ast a;
        {
                timedelta delta("abstract-syntax-tree");
                a = p.transform();
        }

        cfg c;
        {
                timedelta delta("control-flow-graph");
                c = a.transform();
        }

        bytecode b;
        {
                timedelta delta("bytecode-compile");
                b = c.transform();
        }

        {
                timedelta delta("bytecode-run");
                b.run();
        }
}

int main(int argc, char * argv[])
{
        try {
                struct option long_options[] = {
                        {"help",    no_argument, 0, 'h'},
                        {"version", no_argument, 0, 'V'},
                        {0,         0,           0, 0}
                };

                int opt       = 0;
                int opt_index = 0;

                opterr = 0;
                while ((opt = getopt_long(argc, argv,
                                          "hV",
                                          long_options, &opt_index)) != -1) {
                        switch (opt) {
                                case 'h':
                                        help();
                                        return EXIT_SUCCESS;
                                case 'V':
                                        std::cout << version() << std::endl;
                                        return EXIT_SUCCESS;
                                default:
                                        hint("unknown argument");
                                        return EXIT_FAILURE;
                        }
                }

                if (optind >= argc) {
                        hint("missing filename");
                        return EXIT_FAILURE;
                }

                while (optind < argc) {
                        handle(argv[optind++]);
                }
        } catch (std::exception & e) {
                std::stringstream ss;
                ss << "Got unhandled exception (" << e.what() << ")";
                bug(ss.str());
        } catch (...) {
                bug("Got unhandled exception");
        }

        return EXIT_SUCCESS;
}
