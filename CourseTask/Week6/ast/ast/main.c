#include "ast.h"
#include <stdio.h>

extern Exp_t tree;
void yyparse ();
extern struct List_t *all;

int main (int argc, char **argv)
{
  yyparse();
  Exp_print (tree);

  printf("\ncompile start");
  compile(tree);
  List_reverse_print(all);
  printf("\ncompile end");
  return 0;
}
