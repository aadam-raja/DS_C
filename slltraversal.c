#include<stdio.h>
#include<stdlib.h>
struct house {
int membercount;
struct house *relativehouseno;
};

struct house* createhouse( int totalmembers)
{ struct house* newhouse = (struct house*)malloc(sizeof(struct house));
    newhouse->membercount= totalmembers;
    newhouse->relativehouseno=NULL;
return newhouse;
}
void traverse(struct house *head)
{
    struct house *p = head;
    while (p != NULL)
    {
        printf("%d  " ,p->membercount);
        p = p->relativehouseno;
    } }
    int main()
    {
        struct house *head = NULL;
         struct house *temp = NULL;
         struct house  *newhouse = NULL;
        int numberofhouses, totalmembers;

        printf("ENTER TOTAL HOUSES TO WHICH CARDS ARE TO BE DISTRIBUTED: ");
        scanf("%d", &numberofhouses);

        for (int i = 0; i < numberofhouses; i++)
        {
            printf("ENTER TOTAL MEMBERS IN THE HOUSE %d ", i + 1);
            scanf("%d", &totalmembers);

            newhouse  = createhouse(totalmembers);

            if (head == NULL)
            {
    
                head = newhouse;
                temp = head;}
                else

               { temp->relativehouseno = newhouse;
                temp = temp->relativehouseno;}
               }
         
          traverse(head);

          return 0; }


    
