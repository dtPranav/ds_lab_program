#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int item, x, y;
    struct node *link;
};
typedef struct node *NODE;
NODE getNode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("mem full\n");
        exit(0);
    }
    return x;
}
void freeNode(NODE x)
{
    free(x);
}
NODE insert(NODE head, int x, int y, int item)
{
    NODE temp = getNode();
    temp->item = item;
    temp->x = x;
    temp->y = y;
    temp->link = NULL;
    temp->link = head;
    head = temp;
    return head;
}
NODE add_poly(NODE p1, NODE p2)
{
    NODE temp1;
    NODE temp2;
    NODE temp3 = NULL;
    int x, y, sum, flag = 0;
    if (temp1 == NULL)
    {
        printf("First polynomial should contain atleast one term\n");
        return NULL;
    }
    if (temp2 == NULL)
    {
        printf("Second polynomial should contain atleast one term\n");
        return NULL;
    }
    temp1 = p1;
    while (temp1 != NULL)
    {
        flag = 0;
        temp2 = p2;
        while (temp2 != NULL)
        {
            if ((temp2->x == temp1->x) && (temp2->y == temp1->y))
            {
                sum = temp1->item + temp2->item;
                x = temp1->x;
                y = temp1->y;
                temp3 = insert(temp3, x, y, sum);
                flag = 1;
                break;
            }
            temp2 = temp2->link;
        }
        if (flag == 0)
        {
            sum = temp1->item;
            x = temp1->x;
            y = temp1->y;
            temp3 = insert(temp3, x, y, sum);
        }
        temp1 = temp1->link;
    }
    temp2 = p2;
    while (temp2 != NULL)
    {
        temp1 = p1;
        flag = 0;
        while (temp1 != NULL)
        {
            if ((temp1->x == temp2->x) && (temp1->y == temp2->y))
            {
                flag = 1;
                break;
            }
            temp1 = temp1->link;
        }
        if (flag == 0)
        {
            sum = temp2->item;
            x = temp2->x;
            y = temp2->y;
            temp3 = insert(temp3, x, y, sum);
        }

        temp2 = temp2->link;
    }

    return temp3;
}
void display(NODE head)
{
    NODE temp = head;
    while (temp != NULL)
    {
        printf("+%dx^%dy^%d", temp->item, temp->x, temp->y);
        temp = temp->link;
    }
}
int eval(NODE head, int x, int y)
{
    NODE temp;
    temp = head;
    int res = 0;
    int sum = 0;
    while (temp != NULL)
    {
        sum = temp->item * pow(x, temp->x) * pow(y, temp->y);
        res += sum;
        temp = temp->link;
    }
    printf("%d", res);
    return res;
}
int main()
{
    NODE head = NULL;
    NODE head1 = NULL;
    NODE head2 = NULL;
    int ch = 1;
    int x, y, item, result;
    printf("Enter first polynomial\n");
    while (ch == 1)
    {
        printf("Enter power of x terms \n");
        scanf("%d", &x);
        printf("Enter power of y terms \n");
        scanf("%d", &y);
        printf("Enter coefficient of given x and y\n");
        scanf("%d", &item);
        head = insert(head, x, y, item);
        printf("Press 1 to continue\n");
        scanf("%d", &ch);
    }
    ch = 1;
    printf("Enter second polynomial \n");
    while (ch == 1)
    {
        int x, y, item;
        printf("Enter power of x terms \n");
        scanf("%d", &x);
        printf("Enter power of y terms \n");
        scanf("%d", &y);
        printf("Enter coefficient of given x and y\n");
        scanf("%d", &item);
        head1 = insert(head1, x, y, item);
        printf("Press 1 to continue\n");
        scanf("%d", &ch);
    }
    printf("First polynomial : \n");
    display(head);
    printf("\n");
    printf("Second polynomial : \n");
    display(head1);
    printf("\n");
    head2 = add_poly(head, head1);
    printf("\nResultant polynomial is : ");
    display(head2);
    printf("\nEnter x:");
    scanf("%d", &x);
    printf("Enter y:");
    scanf("%d", &y);
    result = eval(head2, x, y);
    printf("\nSolution of the added polynomial when x=%d and y=%d : %d", x, y, result);
    return 0;
}