#include<stdio.h>
void toh(int n,char source,char auxilary,char destination)
{ if(n==1)
 printf("MOVE RING %d from %c to %c\n",n,source,destination);
 else
 {toh(n-1,source,destination,auxilary);
 printf("MOVE RING %d from %c to %c \n",n,source,destination);
toh(n-1,auxilary,source,destination);
 }
}
int main() {
int n;
printf("ENTER NUMBER OF RINGS \n");
scanf("%d",&n);
toh(n,'A','B','C');
return 0; 
}