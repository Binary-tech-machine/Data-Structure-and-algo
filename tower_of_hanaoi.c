#include<stdio.h>
void TOH (int n, char a, char b, char c){
  if(n>0){
    TOH (n-1,a,c,b);
    printf("\nfrom %c to %c",a,c);
    TOH(n-1,b,a,c);
  }
} 
int main (){
  TOH(4,65,66,67);
  printf("\n finally all the disc are transfer from tower A to tower C");
  return 0;
}