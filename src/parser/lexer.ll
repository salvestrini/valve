%option noyywrap

%{
#define YY_NO_UNISTD_H 1
%}

%%

"GOOD"   return EOF;
.

%%
