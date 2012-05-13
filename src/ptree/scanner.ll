%option noyywrap

%{

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead.
 */
#define YY_NO_UNISTD_H 1
%}

%%

"GOOD"   return EOF;
.

%%
