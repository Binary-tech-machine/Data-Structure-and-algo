#include<stdio.h>
#include<string.h>
int main ()
{
  char a[]="harsh";
  char b[6];
  int i,j;
  for(i=0;a[i]!='\0';i++){}
    i=i-1;
    for(j=0;i>=0;i--,j++)
    {
      b[j]= a[i];
    }
    b[i]= '\0';
    printf("%s",b);
}