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
 int r=fact(5);
 printf("%d ",r);
 return 0;
} 
