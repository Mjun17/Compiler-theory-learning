#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semant.h"

#define TODO()\
  do{\
  printf ("TODO: add your code at file: \"%s\", line: %d\n", __FILE__, __LINE__);\
}while(0)

//////////////////////////////////////
// the symbol table
List_t table = 0;

// lookup an "id" in the symbol table.
// return "type" on success; and -1 for failure
Type_t Table_lookup (char *id)
{
  List_t p = table;
  while (p){
    Dec_t d = (Dec_t)p->data;
    if (strcmp(d->id, id)==0)
      return d->type;
    p = p->next;
  }
  return -1;
}

void Table_insert (Dec_t dec)
{

  if (Table_lookup (dec->id) != -1){
    fprintf (stderr, "Error: the variable "
	     "\"%s\" has been declared!\n", dec->id);
    exit (0);
  }
  table = List_new (dec, table);
  return;
}

//////////////////////////////////////////
// dec
void check_dec(Dec_t d)
{
  Table_insert (d);
}

void check_decs(List_t decs)
{
  while (decs){
    Dec_t d = (Dec_t)decs->data;
    check_dec(d);
    decs = decs->next;
  }
  return;
}

////////////////////////////////////////
// exp

// Your job:
Type_t check_exp (Exp_t exp)
{
  //TODO();
  switch(exp->kind)
  {
    case EXP_INT:{return TYPE_INT;}
    case EXP_TRUE:{return TYPE_BOOL;}
    case EXP_FALSE:{return TYPE_BOOL;}
    case EXP_ID:
    {
      Exp_Id id = (Exp_Id)exp;
      return Table_lookup(id->id);
    }
    case EXP_ADD:
    {
      Exp_Add add = (Exp_Add)exp;
      Type_t t1 = check_exp(add->left);
      Type_t t2 = check_exp(add->right);
      if(t1 == TYPE_INT && t2 ==TYPE_INT)
        return TYPE_INT;
      else if(t1 !=  TYPE_INT)
        fprintf(stderr,"type mismatch add t1\n");
      else
        fprintf(stderr,"type mismatch add t2\n");
    }
    case EXP_SUB:
    {
      Exp_Sub sub = (Exp_Sub)exp;
      Type_t t1 = check_exp(sub->left);
      Type_t t2 = check_exp(sub->right);
      if(t1 == TYPE_INT && t2 ==TYPE_INT)
        return TYPE_INT;
      else if(t1 !=  TYPE_INT)
        fprintf(stderr,"type mismatch sub t1\n");
      else
        fprintf(stderr,"type mismatch sub t2\n");
    }
    case EXP_TIMES:
    {
      Exp_Times times = (Exp_Times)exp;
      Type_t t1 = check_exp(times->left);
      Type_t t2 = check_exp(times->right);
      if(t1 == TYPE_INT && t2 ==TYPE_INT)
        return TYPE_INT;
      else if(t1 !=  TYPE_INT)
        fprintf(stderr,"type mismatch times t1\n");
      else
        fprintf(stderr,"type mismatch times t2\n");
    }
    case EXP_DIVIDE:
    {
      Exp_Divide div = (Exp_Divide)exp;
      Type_t t1 = check_exp(div->left);
      Type_t t2 = check_exp(div->right);
      if(t1 == TYPE_INT && t2 ==TYPE_INT)
        return TYPE_INT;
      else if(t1 !=  TYPE_INT)
        fprintf(stderr,"type mismatch div t1\n");
      else
        fprintf(stderr,"type mismatch div t2\n");
    }
    case EXP_AND:
    {
      Exp_And and = (Exp_And)exp;
      Type_t t1 = check_exp(and->left);
      Type_t t2 = check_exp(and->right);
      if(t1 == TYPE_BOOL && t2 ==TYPE_BOOL)
        return TYPE_BOOL;
      else if(t1 !=  TYPE_BOOL)
        fprintf(stderr,"type mismatch and t1\n");
      else
        fprintf(stderr,"type mismatch and t2\n");
    }
    case EXP_OR:
    {
      Exp_Or or = (Exp_Or)exp;
      Type_t t1 = check_exp(or->left);
      Type_t t2 = check_exp(or->right);
      if(t1 == TYPE_BOOL && t2 ==TYPE_BOOL)
        return TYPE_BOOL;
      else if(t1 !=  TYPE_BOOL)
        fprintf(stderr,"type mismatch or t1\n");
      else
        fprintf(stderr,"type mismatch or t2\n");
    }
    default:{fprintf(stderr,"type mismatch in check_exp\n");}
  }
}

////////////////////////////////////////
// stm

// Your job:
void check_stm (Stm_t stm)
{
  //TODO();
  switch (stm->kind)
  {
    case STM_ASSIGN:
    {
      Stm_Assign assign = (Stm_Assign)stm;
      Type_t t1 = Table_lookup(assign->id);
      Type_t t2 = check_exp(assign->exp);
      if(t1 != t2)
      {
        fprintf(stderr,"type mismatch in check_stm assign\n");
        printf("t1 = %d\nt2 = %d\n",t1,t2);
        break;
      }
      else
        return ;
    }
    case STM_PRINTI:
    {
      Stm_Printi prt_i = (Stm_Printi)stm;
      Type_t t = check_exp(prt_i->exp);
      if( t != TYPE_INT)
      {
       fprintf(stderr,"type mismatch in check_stm prt_i\n");
       break;
      }
      else
        return ;
    }
    case STM_PRINTB:
    {
      Stm_Printb prt_b = (Stm_Printb)stm;
      Type_t t = check_exp(prt_b->exp);
      if( t != TYPE_BOOL)
      {
        fprintf(stderr,"type mismatch in check_stm prt_b\n");
        break;
      }
      else
        return ;
    }
  }
}

void check_stms(List_t stms)
{
  while (stms){
    Stm_t s = (Stm_t)stms->data;
    check_stm(s);
    stms = stms->next;
  }
  return;
  TODO();
}


void Semant_check(Prog_t prog)
{
  // create table
  check_decs(prog->decs);
  // check stm
  check_stms(prog->stms);
  return;
}
