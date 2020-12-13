#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int item;
struct node *link;
};
typedef struct node *NODE;
NODE getNode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("mem full\n");
exit(0);
}
return x;
}
void freenode(NODE x)
{
free(x);
}
NODE insert_front(NODE first, int item)
{
    NODE temp = getNode();
    temp->item = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    temp->link = first;
    first = temp;
    return first;
}
NODE delete_front(NODE first)
{   if (first==NULL)
    {
    printf("list is empty\n");
    return first;
    }
    NODE temp;
    temp = first;
    printf("Popped element is %d \n",first->item);
    first = first->link;
    free(temp);
    return first;
}
void display(NODE first)
{
NODE temp;
if(first==NULL)
printf("Stack empty cannot display items\n");
for(temp=first;temp!=NULL;temp=temp->link)
{
printf("%d\n",temp->item);
}
}
void main()
{
int item,choice,pos;
NODE first=NULL;
for(;;)
{
printf("\n 1: PUSH \n 2:POP\n 3:Display\n 4:Exit\n");
printf("Enter the choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("Enter the item to push\n");
scanf("%d",&item);
first=insert_front(first,item);
break;
case 2:first=delete_front(first);
break;
case 3:display(first);
break;
case 4:exit(0);
default:printf("\n Invalid Input");
break;
}
}
}