#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Kind {IF,ID};

struct Token {
  enum Kind kind;
  char *lexeme;
  int row;
  int col;
};

struct Token *Token_new (enum Kind kind,char *lexeme,int row,int col)
{
  struct Token *p = (struct Token*)malloc (sizeof(*p));
  p->kind = kind;
  //p->lexeme = lexeme;
  p->lexeme = (char*)malloc(sizeof(*lexeme));
  strncpy(p->lexeme,lexeme,strlen(lexeme));
  p->row = row;
  p->col = col;
  return p;
}

struct List {
  struct Token *token;
  struct List *next;
};

struct List *all = 0;

struct List *List_new(struct Token *token,struct List *next)
{
  struct List *p = (struct List*)malloc (sizeof(*p))  ;
  p->token = token;
  p->next = next;
  return p;
}

void List_print(struct List *list)
{
  if(list == NULL)
    return ;

  List_print(list->next);
  switch(list->token->kind)
  {
    case IF:
    {
      printf("IF (%d,%d)\n",list->token->row,list->token->col);
      break;
    }
    case ID:
    {
      printf("ID(%s) (%d,%d)\n",list->token->lexeme,list->token->row,list->token->col);
      break;
    }
    default:
    {
      break;
    }
  }
}

void Process_word(char *word,int len,int row,int col)
{
  if(strcmp("if",word) == 0)
  {
    struct Token *token = Token_new(IF,word,row,col);
    all = List_new(token,all);
  }
  else
  {
    struct Token *token = Token_new(ID,word,row,col);
    all = List_new(token,all);
  }
}

#define MAX_LINE 1024
int main()
{
  FILE *fp;
  char strLine[MAX_LINE];
  char str[MAX_LINE];
  if( (fp = fopen("input.txt","r")) == NULL)
  {
    printf("Open failed!!!\n");
    return 0;
  }
  int curr_row = 0;
  while(!feof(fp))
  {
    curr_row++;
    if(fgets(strLine,MAX_LINE,fp))
    {
      printf("%s",strLine);
      int len = strlen(strLine);
      int str_save_len = 0;
      for(int i = 0; i < len; i++)
      {
        char c = strLine[i];
        switch (c)
        {
          case ' ':
          {
            if(str_save_len > 0)
            {
              str[str_save_len] = '\0';
              Process_word(str,str_save_len,curr_row,i+1-str_save_len);
              str_save_len = 0;
            }
            break;
          }
          case '\n':
          {
            if(str_save_len > 0)
            {
              str[str_save_len] = '\0';
              Process_word(str,str_save_len,curr_row,i+1-str_save_len);
              str_save_len = 0;
            }
            break;
          }
          default:
          {
            str[str_save_len++] = c;
          }
        }
      }
    }
  }
  printf("\n");
  List_print(all);
  fclose(fp);
  return 0;
}
