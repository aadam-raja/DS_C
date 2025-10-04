#include <stdio.h>
#include <stdlib.h>

struct house // skeleton
{
    int membercount;
    struct house *relativeshouseno;
};

struct house *addhouse(int value) // creating nodes
{
    struct house *newfriend = (struct house *)malloc(sizeof(struct house));
    newfriend->membercount = value;
    newfriend->relativeshouseno = NULL;
    return newfriend;
}

void insertatbeg(struct house **head, struct house *newfriend)
{
    newfriend->relativeshouseno = *head;
    *head = newfriend;
    struct house *ptr = *head;
    while (ptr->relativeshouseno != *head) // to get last node
    {
        ptr = ptr->relativeshouseno;
    }
    ptr->relativeshouseno = *head; // to make last node point to new first node
}

void insertatend(struct house **head, struct house *newfriend)
{
    struct house *ptr = *head;
    while (ptr->relativeshouseno != *head)
    {
        ptr = ptr->relativeshouseno;
    }
    ptr->relativeshouseno = newfriend;
    newfriend->relativeshouseno = *head;
}

void insertatany(struct house **head, struct house *newfriend)
{
    struct house *pointer = *head;
    while (pointer->membercount % 2 != 0)
    {
        pointer = pointer->relativeshouseno;
    }
    newfriend->relativeshouseno = pointer->relativeshouseno;
    pointer->relativeshouseno = newfriend;
}

void deleteatbeg(struct house **head)
{
    struct house *t = *head;
    *head = (*head)->relativeshouseno;
    struct house *ptr = *head;
    while (ptr->relativeshouseno != t) // to get last node
    {
        ptr = ptr->relativeshouseno;
    }
    ptr->relativeshouseno = *head; // to point last node to new first node
    free(t);
}

void deleteatend(struct house **head)
{
    struct house *t1 = *head;
    while (t1->relativeshouseno->relativeshouseno != *head) // traversing to second last node
    {
        t1 = t1->relativeshouseno;
    }
    struct house *temp = t1->relativeshouseno;
    t1->relativeshouseno = *head;
    free(temp);
}

void deleteatany(struct house **head)
{
    struct house *t2 = *head;
    while (t2->relativeshouseno->membercount % 2 != 0) // traversing to the node before it
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
    do // to print last node as well
    {
        printf("%d  ", p->membercount);
        p = p->relativeshouseno;
    } while (p != head);
    printf("\n");
}

int main()
{
    struct house *head = NULL;
    struct house *temp = NULL;
    struct house *newfriend = NULL;
    int totalfriends, value;

    printf("ENTER TOTAL FRIENDS: ");
    scanf("%d", &totalfriends);

    for (int i = 0; i < totalfriends; i++) // loop for multiple inputs
    {
        printf("ENTER ROLL NO OF FRIEND %d: ", i + 1);
        scanf("%d", &value);

        newfriend = addhouse(value);

        if (head == NULL)
        {
            head = newfriend;
            temp = head;
        }
        else
        {
            temp->relativeshouseno = newfriend;
            temp = temp->relativeshouseno;
        }
    }
    temp->relativeshouseno = head; // last node points to first node

    // Insert at beginning
    printf("ENTER ROLL NO OF FRIEND TO INSERT AT BEGINNING: ");
    scanf("%d", &value);
    newfriend = addhouse(value);
    insertatbeg(&head, newfriend);
    traverse(head);

    // Insert at end
    printf("ENTER ROLL NO OF FRIEND TO INSERT AT END: ");
    scanf("%d", &value);
    newfriend = addhouse(value);
    insertatend(&head, newfriend);
    traverse(head);

    // Insert after first odd rollno
    printf("ENTER ROLL NO OF FRIEND TO INSERT AFTER FIRST ODD ROLL NO: ");
    scanf("%d", &value);
    newfriend = addhouse(value);
    insertatany(&head, newfriend);
    traverse(head);

    // Delete at beginning
    deleteatbeg(&head);
    traverse(head);

    // Delete at end
    deleteatend(&head);
    traverse(head);

    // Delete first even rollno
    deleteatany(&head);
    traverse(head);

    return 0;
}