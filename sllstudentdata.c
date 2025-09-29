#include<stdio.h>
struct student
{ int rollno;
char name[50];
struct student *next;
};
int main()
{ struct student s[5];
 for(int i=0;i<5;i++)
 { printf("ENTER ROLL NUMBER FOR STUDENT %d ",i+1);
    scanf("%d", &s[i].rollno);
    printf("ENTER NAME FOR STUDENT %d ",i+1);
    scanf("%s",s[i].name);
 }
for(int i=0;i<4;i++)
{ s[i].next = &s[i+1]; 
}
s[4].next = NULL;
struct student *h;
h = &s[0];
struct student *p;
p=h;
while(p->next != NULL)
 { printf("%d %s",p->rollno,p->name);
    p = p->next;
 }
 return 0; }


