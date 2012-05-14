//
// This file is part of the valve package
//
// (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
//

#include "config.h"

#include <iostream>
#include <cstdlib>

void bug()
{
        std::cerr << "Please report this bug to "
                  << "<" << PACKAGE_BUGREPORT << ">"
                  << std::endl;
        abort();
}

void bug(const std::string & message)
{
        std::cerr << message << std::endl;
        bug();
}
