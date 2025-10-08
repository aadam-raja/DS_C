#include <stdio.h>
#include <stdlib.h>

struct house
{
    int membercount;
    struct house *relativeshouseno;
    struct house *friendshouseno;
};

struct house *addhouse(int totalmembers)
{
    struct house *newhouse = (struct house *)malloc(sizeof(struct house));
    newhouse->membercount = totalmembers;
    newhouse->relativeshouseno = NULL;
    newhouse->friendshouseno = NULL;
    return newhouse;
}

void insertatbeg(struct house **head, struct house *newhouse)
{
    newhouse->relativeshouseno = *head;
    *head = newhouse;
    newhouse->friendshouseno = NULL;
    newhouse->relativeshouseno->friendshouseno = newhouse;
}

void insertatend(struct house **head, struct house *newhouse)
{
    struct house *ptr = *head;
    while (ptr->relativeshouseno)
    {
        ptr = ptr->relativeshouseno;
    }
    ptr->relativeshouseno = newhouse;
    newhouse->friendshouseno = ptr;
    newhouse->relativeshouseno = NULL;
}

void insertatany(struct house **head, struct house *newhouse)
{
    struct house *pointer = *head;
    while (pointer->membercount % 2 != 0)
    {
        pointer = pointer->relativeshouseno;
    }
    newhouse->friendshouseno = pointer;
    newhouse->relativeshouseno = pointer->relativeshouseno;
    pointer->relativeshouseno = newhouse;
    newhouse->relativeshouseno->friendshouseno = newhouse;
}

void deleteatbeg(struct house **head)
{
    struct house *t = *head;
    *head = t->relativeshouseno;
    (*head)->friendshouseno = NULL;
    free(t);
}

void deleteatend(struct house **head)
{
    struct house *t1 = *head;
    while (t1->relativeshouseno->relativeshouseno)
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
    t3->relativeshouseno->friendshouseno = t2;
    free(t3);
}

void traverse(struct house *head)
{
    struct house *p = head;
    while (p)
    {
        printf("%d  ", p->membercount);
        p = p->relativeshouseno;
    }
    printf("\n");
}

int main()
{
    struct house *head = NULL, *temp = NULL, *newhouse = NULL;
    int totalhouses, totalmembers;

    printf("ENTER TOTAL HOUSES OF RELATIVES : ");
    scanf("%d", &totalhouses);

    for (int i = 0; i < totalhouses; i++)
    {
        printf("ENTER TOTAL MEMBERS IN HOUSE OF RELATIVES %d: ", i + 1);
        scanf("%d", &totalmembers);
        newhouse = addhouse(totalmembers);
        if (!head)
        {
            head = temp = newhouse;
        }
        else
        {
            temp->relativeshouseno = newhouse;
            newhouse->friendshouseno = temp;
            temp = newhouse;
        }
    }

    printf("ENTER MEMBERS IN HOUSE TO INSERT AT BEGINNING: ");
    scanf("%d", &totalmembers);
    newhouse = addhouse(totalmembers);
    insertatbeg(&head, newhouse);
    traverse(head);

    printf("ENTER MEMBERS IN HOUSE TO INSERT AT END: ");
    scanf("%d", &totalmembers);
    newhouse = addhouse(totalmembers);
    insertatend(&head, newhouse);
    traverse(head);

    printf("ENTER MEMEBERS IN HOUSE TO INSERT AFTER FIRST ODD NO OF MEMBERS: ");
    scanf("%d", &totalmembers);
    newhouse = addhouse(totalmembers);
    insertatany(&head, newhouse);
    traverse(head);

    deleteatbeg(&head);
    traverse(head);

    deleteatend(&head);
    traverse(head);

    deleteatany(&head);
    traverse(head);

    return 0;
}