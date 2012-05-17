//
// This file is part of the valve package
//
// (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
//

#include "driver.hh"
#include "parser.hh"
     
valve_driver::valve_driver() :
        trace_scanning(false),
        trace_parsing(false)
{
        variables["one"] = 1;
        variables["two"] = 2;
}
     
valve_driver::~valve_driver()
{ }
     
int
valve_driver::parse(const std::string &f)
{
        file = f;
        scan_begin();
        yy::valve_parser parser(*this);
        parser.set_debug_level(trace_parsing);
        int res = parser.parse();
        scan_end();
        return res;
}
     
void
valve_driver::error(const yy::location & l,
                    const std::string &  m)
{ std::cerr << l << ": " << m << std::endl; }
     
void
valve_driver::error(const std::string & m)
{ std::cerr << m << std::endl; }
