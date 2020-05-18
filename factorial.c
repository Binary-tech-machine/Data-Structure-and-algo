#include<stdio.h>
int fact(int n)
{
 int f=1,i;
 for(i=1;i<=n;i++)
 f=f*i;

 return f;
}
int main()
{
  int n;
  printf("enter the value of n :");
  scanf("%d",&n);
  int r=fact(n);
  printf("%d ",r);
  return 0;
  
} 
