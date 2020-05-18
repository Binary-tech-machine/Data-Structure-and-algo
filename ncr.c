#include<stdio.h>
int fact(int n)
{
	if(n==0)
    return 1;
 return fact(n-1)*n;
}
int ncr(int n, int r)
{
 int num ,deno;
 num=fact(n);
 deno=fact(r)*fact(n-r);
 return num/deno;
}
int main()
{
  int n,r;
  printf("enter the value of n and r");
  scanf("%d%d",&n,&r);
  printf("%d",ncr(n,r));
  return 0;
} 