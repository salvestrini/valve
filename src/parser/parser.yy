/*  -*- C++ -*- */
%skeleton "lalr1.cc"
%defines

%{
#define YYSTYPE int
int yylex(YYSTYPE* yylval_param);
%}

%%
start :        /* empty */
%%

int
yylex(YYSTYPE*)
{
    return 0;
}

void
yy::parser::error(const yy::parser::location_type&, const std::string& m)
{
    return;
}
