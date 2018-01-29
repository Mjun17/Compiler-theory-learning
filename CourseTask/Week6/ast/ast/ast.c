#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

// "constructors"
Exp_t Exp_Int_new (int n)
{
  Exp_Int p = malloc (sizeof (*p));
  p->kind = EXP_INT;
  p->n = n;
  return (Exp_t)p;
}

Exp_t Exp_Add_new (Exp_t left, Exp_t right)
{
  Exp_Add p = malloc (sizeof (*p));
  p->kind = EXP_ADD;
  p->left = left;
  p->right = right;
  return (Exp_t)p;
}

Exp_t Exp_Times_new (Exp_t left, Exp_t right)
{
  Exp_Add p = malloc (sizeof (*p));
  p->kind = EXP_TIMES;
  p->left = left;
  p->right = right;
  return (Exp_t)p;
}

Exp_t Exp_Sub_new (Exp_t left, Exp_t right)
{
  Exp_Sub p = malloc (sizeof (*p));
  p->kind = EXP_SUB;
  p->left = left;
  p->right = right;
  return (Exp_t)p;
}

Exp_t Exp_Div_new (Exp_t left, Exp_t right)
{
  Exp_Div p = malloc (sizeof (*p));
  p->kind = EXP_DIV;
  p->left = left;
  p->right = right;
  return (Exp_t)p;
}
// all operations on "Exp"
void Exp_print (Exp_t exp)
{
  switch (exp->kind){
  case EXP_INT:{
    Exp_Int p = (Exp_Int)exp;
    printf ("%d", p->n);
    return;
  }
  case EXP_ADD:{
    Exp_Add p = (Exp_Add)exp;
    printf ("(");
    Exp_print (p->left);
    printf (") + (");
    Exp_print (p->right);
    printf (")");
    return;
  }
  case EXP_TIMES:{
    Exp_Times p = (Exp_Times)exp;
    printf ("(");
    Exp_print (p->left);
    printf (") * (");
    Exp_print (p->right);
    printf (")");
    return;
  }
  case EXP_SUB:{
    Exp_Sub p = (Exp_Sub)exp;
    printf ("(");
    Exp_print (p->left);
    printf (") - (");
    Exp_print (p->right);
    printf (")");
    return;
  }
  case EXP_DIV:{
    Exp_Div p = (Exp_Div)exp;
    printf ("(");
    Exp_print (p->left);
    printf (") / (");
    Exp_print (p->right);
    printf (")");
    return;
  }
  default:
    return;
  }
}

struct List_t *all = 0;

Stack_t Stack_Add_new ()
{
  Stack_Add p = malloc(sizeof(*p));
  p->kind = STACK_ADD;
  return (Stack_t)p;
}

Stack_t Stack_Sub_new ()
{
  Stack_Sub p = malloc(sizeof(*p));
  p->kind = STACK_SUB;
  return (Stack_t)p;
}

Stack_t Stack_Times_new ()
{
  Stack_Times p = malloc(sizeof(*p));
  p->kind = STACK_TIMES;
  return (Stack_t)p;
}

Stack_t Stack_Div_new ()
{
  Stack_Div p = malloc(sizeof(*p));
  p->kind = STACK_DIV;
  return (Stack_t)p;
}

Stack_t Stack_Push_new (int i)
{
  Stack_Push p = malloc(sizeof(*p));
  p->kind = STACK_PUSH;
  p->i = i;
  return (Stack_t)p;
}

struct List_t *List_new (struct Stack_t *instr, struct List_t *next) {
  struct List_t *p = malloc(sizeof(*p));
  p->instr = instr;
  p->next = next;
  return p;
}

void List_reverse_print (struct List_t *list) {
  if(list->next != 0)
     List_reverse_print(list->next);
  struct Stack_Push *p  = (struct Stack_Push*)(list->instr);
  switch (p->kind)
  {
    case STACK_ADD:
    {
      printf("\nadd()");
      break;
    }
    case STACK_SUB:
    {
      printf("\nsub()");
      break;
    }
    case STACK_TIMES:
    {
      printf("\ntimes()");
      break;
    }
    case STACK_DIV:
    {
      printf("\ndiv()");
      break;
    }
    case STACK_PUSH:
    {
      printf("\npush %d",p->i);
      break;
    }
    default:
    {
      break;
    }
  }
}

void emit (struct Stack_t *instr) {
  all = List_new (instr, all);
}

void compile (struct Exp_t *exp)
{
  switch (exp->kind)
  {
      case EXP_INT:
      {
        struct Exp_Int *p = (struct Exp_Int *)exp;
        emit (Stack_Push_new (p->n));
        break;
      }
      case EXP_ADD:
      {
        struct Exp_Add *p = (struct Exp_Add*)exp;
        if(p->left != NULL)
          compile(p->left);
        if(p->right != NULL)
          compile(p->right);
        emit (Stack_Add_new ());
        break;
      }
      case EXP_SUB:
      {
        struct Exp_Sub *p = (struct Exp_Sub *)exp;
        if(p->left != NULL)
          compile(p->left);
        if(p->right != NULL)
          compile(p->right);
        emit (Stack_Sub_new ());
        break;
      }
      case EXP_TIMES:
      {
        struct Exp_Times *p = (struct Exp_Times *)exp;
        if(p->left != NULL)
          compile(p->left);
        if(p->right != NULL)
          compile(p->right);
        emit (Stack_Times_new ());
        break;
      }
      case EXP_DIV:
      {
        struct Exp_Div *p = (struct Exp_Div *)exp;
        if(p->left != NULL)
          compile(p->left);
        if(p->right != NULL)
          compile(p->right);
        emit (Stack_Div_new ());
        break;
      }
      default:
        break;
  }
}
