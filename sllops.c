#include <stdio.h>
#include <stdlib.h>
struct house // skeleton
{
    int membercount;
    struct house *relativeshouseno;
};

struct house *addhouse(int totalmembers) //creating nodes
{
    struct house *newhouse = (struct house *)malloc(sizeof(struct house));
    newhouse->membercount = totalmembers;
    newhouse->relativeshouseno = NULL;
    return newhouse;
}
void insertatbeg(struct house **head, struct house *newhouse)
{
    newhouse->relativeshouseno = *head;
    *head = newhouse;
}
void insertatend(struct house **head, struct house *newhouse)
{
    struct house *ptr = *head;
    while (ptr->relativeshouseno != NULL)
    {
        ptr = ptr->relativeshouseno;
    }
    ptr->relativeshouseno = newhouse;
    newhouse->relativeshouseno = NULL;
}
void insertatany(struct house **head, struct house *newhouse)
{
    struct house *pointer = *head;
    while (pointer->membercount % 2 != 0) 
    {
        pointer = pointer->relativeshouseno;
    }
    newhouse->relativeshouseno = pointer->relativeshouseno;
    pointer->relativeshouseno = newhouse;
}

void deleteatbeg(struct house **head)
{
    struct house *t = *head;
    *head = (*head)->relativeshouseno;
    free(t);
}
void deleteatend(struct house **head)
{
    struct house *t1 = *head;
    while (t1->relativeshouseno->relativeshouseno != NULL)
    {
        t1 = t1->relativeshouseno;
    }
    struct house *temp = t1->relativeshouseno;
    t1->relativeshouseno = NULL;
    free(temp);
}
void deleteatany(struct house **head)
{
    struct house *t2 = *head;
    while (t2->relativeshouseno->membercount % 2 != 0) 
    {
        t2 = t2->relativeshouseno;
    }
    struct house *t3 = t2->relativeshouseno;
    t2->relativeshouseno = t3->relativeshouseno;
    free(t3);
}

void traverse(struct house *head)
{
    struct house *p = head;
    while (p != NULL) 
    {
        printf("%d  ", p->membercount);
        p = p->relativeshouseno;
    }
    printf("\n");
}

int main()
{
    struct house *head = NULL;
    struct house *temp = NULL;
    struct house *newhouse = NULL;
    int totalhouses, totalmembers;

    printf("ENTER TOTAL HOUSES OF RELATIVES : ");
    scanf("%d", &totalhouses);

    for (int i = 0; i < totalhouses; i++) //loop for multiple inputs
    {
        printf("ENTER TOTAL MEMBERS IN HOUSE  OF RELATIVES %d: ", i + 1);
        scanf("%d", &totalmembers);

        newhouse = addhouse(totalmembers);

        if (head == NULL)
        {
            head = newhouse;
            temp = head;
        }
        else
        {
            temp->relativeshouseno = newhouse;
            temp = temp->relativeshouseno;
        }
    }

    // Insert at beginning
    printf("ENTER MEMBERS IN HOUSE TO INSERT AT BEGINNING: ");
    scanf("%d", &totalmembers);
    newhouse = addhouse(totalmembers);
    insertatbeg(&head, newhouse);
    traverse(head);

    // Insert at end
    printf("ENTER MEMBERS IN HOUSE TO INSERT AT END: ");
    scanf("%d", &totalmembers);
    newhouse = addhouse(totalmembers);
    insertatend(&head, newhouse);
    traverse(head);

    // Insert after first odd no of members
    printf("ENTER MEMEBERS IN HOUSE  TO INSERT AFTER FIRST ODD NO OF MEMBERS: ");
    scanf("%d", &totalmembers);
    newhouse = addhouse(totalmembers);
    insertatany(&head, newhouse);
    traverse(head);

    // Delete at beginning
    deleteatbeg(&head);
    traverse(head);

    // Delete at end
    deleteatend(&head);
    traverse(head);

    // Delete first even membered house
    deleteatany(&head);
    traverse(head);

    return 0;
}