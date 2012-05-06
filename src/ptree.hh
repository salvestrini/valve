//
// This file is part of the valve package
//
// (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
//

#ifndef VALVE_PTREE_HH
#define VALVE_PTREE_HH

#include <iostream>

#include "ast.hh"

class ptree {
public:
        ptree()  { }
        ~ptree() { }

        void parse(const std::string & filename) { }
        ast  transform() { }
};

#endif
