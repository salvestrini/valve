%skeleton "lalr1.cc"                          /*  -*- C++ -*- */
%require "2.5"
%defines
%define parser_class_name "valve_parser"

%code requires {
# include <string>
class valve_driver;
}

// The parsing context.
%parse-param { valve_driver & driver }
%lex-param   { valve_driver & driver }

%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};

%debug
%error-verbose

// Symbols.
%union
{
  int           ival;
  std::string * sval;
};

%code {
# include "driver.hh"
}

%token        END      0 "end of file"
%token        ASSIGN     ":="
%token <sval> IDENTIFIER "identifier"
%token <ival> NUMBER     "number"
%type  <ival> exp

%printer    { debug_stream () << *$$; } "identifier"
%destructor { delete $$; } "identifier"
%printer    { debug_stream () << $$; } <ival>

%%

%start unit;
unit: assignments exp  { driver.result = $2; };

assignments: assignments assignment {}
           | /* Nothing.  */        {};

assignment:
     "identifier" ":=" exp
       { driver.variables[*$1] = $3; delete $1; };

%left '+' '-';
%left '*' '/';
exp: exp '+' exp   { $$ = $1 + $3; }
   | exp '-' exp   { $$ = $1 - $3; }
   | exp '*' exp   { $$ = $1 * $3; }
   | exp '/' exp   { $$ = $1 / $3; }
   | "identifier"  { $$ = driver.variables[*$1]; delete $1; }
   | "number"      { $$ = $1; };
%%

void
yy::valve_parser::error(const yy::valve_parser::location_type & l,
                        const std::string &                     m)
{ driver.error (l, m); }
