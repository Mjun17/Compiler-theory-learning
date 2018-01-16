#include <stdio.h>
#include "re.h"

int main (char argc, char **argv)
{
  //epsilon
  Re_t e = Re_Eps_new();
  printf ("\nthe regular expression is:\n");
  Re_print (e);
  Nfa_t nfa = Re_thompson (e);
  printf ("\nthe NFA is:\n");
  Nfa_print (nfa);
  printf("start=%d\naccpet=%d\n",nfa->start,nfa->accept);
  //a
  e = Re_Char_new ('a');
  printf ("\nthe regular expression is:\n");
  Re_print (e);
  nfa = Re_thompson (e);
  printf ("\nthe NFA is:\n");
  Nfa_print (nfa);
  printf("start=%d\naccpet=%d\n",nfa->start,nfa->accept);
  //ab
  e = Re_Concat_new (Re_Char_new ('a'), Re_Char_new ('b'));
  printf ("\nthe regular expression is:\n");
  Re_print (e);
  nfa = Re_thompson (e);
  printf ("\nthe NFA is:\n");
  Nfa_print (nfa);
  printf("start=%d\naccpet=%d\n",nfa->start,nfa->accept);
  //a|b
  e = Re_Alt_new (Re_Char_new ('a'), Re_Char_new ('b'));
  printf ("\nthe second regular expression is:\n");
  Re_print (e);
  nfa = Re_thompson (e);
  printf ("\nthe second NFA is:\n");
  Nfa_print (nfa);
  printf("start=%d\naccpet=%d\n",nfa->start,nfa->accept);
  //a*
  e = Re_Closure_new (Re_Char_new ('a'));
  printf ("\nthe second regular expression is:\n");
  Re_print (e);
  nfa = Re_thompson (e);
  printf ("\nthe second NFA is:\n");
  Nfa_print (nfa);
  printf("start=%d\naccpet=%d\n",nfa->start,nfa->accept);
  //(ab)*
  e = Re_Closure_new (Re_Concat_new (
                        Re_Char_new ('a'), Re_Char_new ('b')));
  printf ("\nthe second regular expression is:\n");
  Re_print (e);
  nfa = Re_thompson (e);
  printf ("\nthe second NFA is:\n");
  Nfa_print (nfa);
  printf("start=%d\naccpet=%d\n",nfa->start,nfa->accept);
  //(a|b)*
  e = Re_Closure_new (Re_Alt_new (
                        Re_Char_new ('a'), Re_Char_new ('b')));
  printf ("\nthe second regular expression is:\n");
  Re_print (e);
  nfa = Re_thompson (e);
  printf ("\nthe second NFA is:\n");
  Nfa_print (nfa);
  printf("start=%d\naccpet=%d\n",nfa->start,nfa->accept);
  //a(b|c)*
  e = Re_Concat_new (Re_Char_new ('a'), Re_Closure_new (
            Re_Alt_new(Re_Char_new ('b'), Re_Char_new ('c'))));
  printf ("\nthe second regular expression is:\n");
  Re_print (e);
  nfa = Re_thompson (e);
  printf ("\nthe second NFA is:\n");
  Nfa_print (nfa);
  printf("start=%d\naccpet=%d\n",nfa->start,nfa->accept);
  return 0;
}
