%{
int row = 1;
int col = 1;
#include <stdio.h>
#include <string.h>
void yyerror(char *s)
{
  fprintf(stderr,"%s\n",s);
}
%}

N [\n]
NOT_N [" "]
ID [A-Za-z]([A-Za-z0-9])*
IF [iI][fF]
%%

{N}    {col = 1; ++row;}
{NOT_N} {++col;}
{IF} {printf("IF(%s) (%d,%d)\n",yytext,row,col);col+=2;}
{ID} {printf("ID(%s) (%d,%d)\n",yytext,row,col);col+=strlen(yytext);}

%%

int main(int argc, char *argv[])
{
  FILE *fp = 0;
  fp = fopen("input.txt","r");
  if( fp == 0)
    yyerror("OPEN FAIL!!!");
  yyin = fp;
  yylex();
  fclose(fp);
  return 0;
}

int yywrap()
{
  return 1;
}
