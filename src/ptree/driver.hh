//
// This file is part of the valve package
//
// (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
//

#ifndef VALVE_CONTEXT_HH
#define VALVE_CONTEXT_HH

# include <string>
# include <map>

# include "parser.hh"

// Tell Flex the lexer's prototype ...
# define YY_DECL                                        \
        yy::valve_parser::token_type                    \
        yylex (yy::valve_parser::semantic_type* yylval, \
               yy::valve_parser::location_type* yylloc, \
               valve_driver& driver)

YY_DECL;

// Conducting the whole scanning and parsing of Calc++.
class valve_driver
{
public:
        valve_driver ();
        virtual ~valve_driver ();
     
        std::map<std::string, int> variables;
     
        int result;

        // Handling the scanner.
        void scan_begin ();
        void scan_end ();
        bool trace_scanning;

        int parse (const std::string& f);

        std::string file;
        bool trace_parsing;

        // Error handling.
        void error (const yy::location& l, const std::string& m);
        void error (const std::string& m);
};
#endif
