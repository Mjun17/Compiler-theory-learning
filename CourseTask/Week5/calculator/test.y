%{
  #include <stdio.h>
  #include <stdlib.h>
  int yylex();
  void yyerror(char *s);
%}
%left '+' '-'
%left '*' '/'

%%
lines: line
      |line lines;
line: exp'\n';
exp: n
   | exp '+' exp;
   | exp '-' exp;
   | exp '*' exp;
   | exp '/' exp;
   | '(' exp ')'
;
n: '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' ;

%%

int yylex()
{
    return getchar();
}

void yyerror(char *s)
{
    fprintf(stderr,"%s\n",s);
    return ;
}
int main()
{
   yyparse();
   return 0;
}
