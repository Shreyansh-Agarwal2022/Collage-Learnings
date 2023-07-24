#include <stdio.h>
#include <stdlib.h>
//Structure of Node
//Remeber it is for Singly Linked List
typedef struct node
{
    int coeff;
    int degree;
    struct node *next;
} node;
//Create function creates a Node. c is coefficient and p is power of x/degree and Node next is NULL.
//It returns the pointer/address of that new node.
node *create(int c, int p)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->coeff = c;
    temp->degree = p;
    temp->next = NULL;
    return temp;
}
//Make function add node to head linked list in such a way linked list remains sorted after the insertion.
//Here, I have commented print statements that can be used for understanding how code flows for different cases.
//I have used node**head because new element can be added to starting of linked list do change the head in main.
void make(node **head, node *new)
{
    // printf("\n\n%d\n",new->degree);
    node *temp1 = *head;
    node *temp2;
    if (*head == NULL)
    {
        // printf("\na\n");
        *head = new;
        return;
    }
    else if ((*head)->degree < new->degree)
    {
        // printf("\nb\n");
        new->next = (*head);
        *head = new;
        return;
    }
    else if ((*head)->degree >= new->degree)
    {
        // printf("\nc\n");
        while (temp1 != NULL && temp1->degree > new->degree)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if (temp1 == NULL)
        {
            // printf("\nd\n");
            temp2->next = new;
            return;
        }
        else if (temp1->degree == new->degree)
        {
            // printf("\ne\n");
            temp1->coeff += new->coeff;
            free(new);
            return;
        }
        else if (temp1->degree < new->degree)
        {
            // printf("\nf\n");
            new->next = temp1;
            temp2->next = new;
            return;
        }
    }
}
//printlist function prints the given linked list
void printlist(node *head)
{
    int i = 1;
    while (head != NULL)
    {
        printf("Element %d :\nCoefficient : %d \nDegree of x : %d \n", i, head->coeff, head->degree);
        i++;
        head = head->next;
    }
}
//Merge function is used to make a new sorted linked list using linked lists p and q.
//Merge funtion returns the head pointer of the new linked list.
node *merge(node *p, node *q)
{
    node *r = NULL;
    node *temp = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->degree > q->degree)
        {
            if (r == NULL)
            {
                r = (node *)malloc(sizeof(node));
                r->coeff = p->coeff;
                r->degree = p->degree;
                r->next = NULL;
                p = p->next;
                temp = r;
            }
            else
            {
                temp->next = (node *)malloc(sizeof(node));
                temp = temp->next;
                temp->coeff = p->coeff;
                temp->degree = p->degree;
                temp->next = NULL;
                p = p->next;
            }
        }
        else if (p->degree < q->degree)
        {
            if (r == NULL)
            {
                r = (node *)malloc(sizeof(node));
                r->coeff = q->coeff;
                r->degree = q->degree;
                r->next = NULL;
                q = q->next;
                temp = r;
            }
            else
            {
                temp->next = (node *)malloc(sizeof(node));
                temp = temp->next;
                temp->coeff = q->coeff;
                temp->degree = q->degree;
                temp->next = NULL;
                q = q->next;
            }
        }
        else if (p->degree == q->degree)
        {
            if (r == NULL)
            {
                r = (node *)malloc(sizeof(node));
                r->coeff = q->coeff + p->coeff;
                r->degree = q->degree;
                r->next = NULL;
                q = q->next;
                p = p->next;
                temp = r;
            }
            else
            {
                temp->next = (node *)malloc(sizeof(node));
                temp = temp->next;
                temp->coeff = q->coeff + p->coeff;
                temp->degree = q->degree;
                temp->next = NULL;
                p = p->next;
                q = q->next;
            }
        }
    }
    if (p == NULL)
    {
        while (q != NULL)
        {
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
            temp->coeff = q->coeff;
            temp->degree = q->degree;
            temp->next = NULL;
            q = q->next;
        }
    }
    else if (q == NULL)
    {
        while (p != NULL)
        {
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
            temp->coeff = p->coeff;
            temp->degree = p->degree;
            temp->next = NULL;
            p = p->next;
        }
    }
    return r;
}
//Here we have our main function it which I have taken input from user about the data to be filled in the Linked List.
void main()
{
    //p1 is the linked list for first polynomial, p2 is for second polynomial and p3 is for merged polynomial.
    node *p1 = NULL;
    node *p2 = NULL;
    node *p3 = NULL;
    node *t = NULL;
    //c is coefficient and p is degree/power of x
    int c, p;
    //ch is for choice entered by user.
    char ch;
    //catch is used for making the entering data process work correctly.
    int catch = 0;

    printf("For First Polynomial :\n\n");
    //do_while loop because choice is asked after user have added atleast one node
    do
    {
        if (catch == 1)
            getchar();
        //Exception Handling
        while (1)
        {
            printf("Enter The Power of x (degree) : ");
            scanf("%d", &p);
            if (p >= 0)
                break;
            else
                printf("Power/Degree is always greater than or equal to 0. Enter Again !\n");
        }
        //Exception Handling
        while (1)
        {
            printf("Enter The Coefficient : ");
            scanf("%d", &c);
            if (c != 0)
                break;
            else
                printf("Coefficient cannot be 0.\n");
        }
        t = create(c, p);
        make(&p1, t);
        printf("Do you want to add more [y/n] : ");
        getchar();
        scanf("%c", &ch);
        catch = 1;
    
    } 
    while (ch != 'n' && ch != 'N');

    catch = 0;
    printf("For Second Polynomial :\n\n");
    do
    {
        while (1)
        {
            if (catch == 1)
                getchar();
            printf("Enter The Power of x (degree) : ");
            scanf("%d", &p);
            if (p >= 0)
                break;
            else
                printf("Power/Degree is always greater than or equal to 0. Enter Again !\n");
        }
        while (1)
        {
            printf("Enter The Coefficient : ");
            scanf("%d", &c);
            if (c != 0)
                break;
            else
                printf("Coefficient cannot be 0.\n");
        }
        t = create(c, p);
        make(&p2, t);
        printf("Do you want to add more [y/n] : ");
        getchar();
        scanf("%c", &ch);
        catch = 1;

    } 
    while (ch != 'n' && ch != 'N');

    p3 = merge(p1, p2);

    //Now we are displaying all linked lists.
    printf("\nDisplaying First List :\n");
    printlist(p1);
    printf("\nDisplaying Second List :\n");
    printlist(p2);
    printf("\nDisplaying Merged List :\n");
    printlist(p3);
}