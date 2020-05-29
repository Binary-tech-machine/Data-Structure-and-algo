#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LPAR '('
#define RPAR ')'
#define MINUS '-'
#define PLUS '+'
#define ADD '+'
#define SUBTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define MODULO '%'
#define FINISH '\0'
#define INT '0'
#define EXPRESSION 1
#define OPERATOR 0
struct token
{
  char kind;
  int value;
};
char expr[100];
int where = 0;
void skipWhite()
{
  while (isspace(expr[where]))
    where++;
}
void skipDigits()
{
  if (expr[where] == '+' || expr[where] == '-')
    where++;
  while (isdigit(expr[where]))
    where++;
}
struct token getExpr()
{
  struct token token;
  skipWhite();
  if (expr[where] == PLUS || expr[where] == MINUS || expr[where] >= '0' && expr[where] <= '9')
  {
    token.kind = INT;
    sscanf(expr + where, "%d", &token.value);
    skipDigits();
  }
  else
  {
    token.kind = expr[where];
    where++;
  }
  return token;
}
struct token getOperator()
{
  struct token token;
  skipWhite();
  if ((expr[where-1] == SUBTRACT && expr[where] == MINUS) || (expr[where-1] == PLUS && expr[where] == MINUS) 
      ||(expr[where-1] == MULTIPLY && expr[where] == MINUS) || (expr[where-1] == DIVIDE && expr[where] == MINUS))
  {
    token = getExpr();
    return token;
  }
  switch (expr[where])
  {
  case ADD:
    token.kind = ADD;
    where++;
    break;
  case SUBTRACT:
    token.kind = SUBTRACT;
    where++;
    break;
  case MULTIPLY:
    token.kind = MULTIPLY;
    where++;
    break;
  case DIVIDE:
    token.kind = DIVIDE;
    where++;
    break;
  case MODULO:
    token.kind = MODULO;
    where++;
    break;
  case FINISH:
    token.kind = FINISH;
    where++;
    break;
  case LPAR:
    token.kind = LPAR;
    where++;
    break;
  case RPAR:
    token.kind = RPAR;
    where++;
    break;
  default:
    printf("Bad symbol\n");
    token.kind = FINISH;
  }
  return token;
}

struct token getToken()
{
  struct token token;
  skipWhite();
  if (isdigit(expr[where]))
  {
    token = getExpr();
    return token;
  }
  else
  {
    token = getOperator();
    return token;
  }
}
int main(void)
{
  struct token token;
  int i;
  printf("Input expression:");
  fgets(expr, 99, stdin);
  token = getToken();
  while (token.kind != FINISH)
  {
    printf("%c", token.kind);
    if (token.kind == INT)
      printf(" %d", token.value);
    printf("\n");
    token = getToken();
  }
  return 0;
}
