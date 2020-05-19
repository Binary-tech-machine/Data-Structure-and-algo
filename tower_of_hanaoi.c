#include<stdio.h>
void TOH (int n, char a, char b, char c)
{
  if(n>0)
  {
    TOH (n-1,a,c,b);
    printf("\nfrom disc %c to disc %c",a,c);
    TOH(n-1,b,a,c);
  }
} 
int main ()
{
  int n;
  printf("enter the number of disc:");
  scanf("%d",&n);
  TOH(n,65,66,67);
  printf("\nfinally all the disc are transfer from tower A to tower C");
  return 0;
}