#include<stdio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node* link;
};
typedef struct node* NODE;
NODE getNode(){
    NODE temp;
    temp=(NODE) malloc(sizeof(NODE));
    return temp;
}
void freeNode(NODE temp){
    free(temp);
}
NODE insert_front(NODE first, int item)
{
    NODE temp = getNode();
    temp->item = item;
    temp->link = NULL;
    if (first==NULL)
        return temp; 
    temp->link=first;
    first = temp;
    return first;
}
NODE insert_rear(NODE first, int item)
{
    NODE temp, x;
    temp = getNode();
    temp->item = item;
    temp->link = NULL;
    x = first;
    if (x == NULL)
    {
        return temp;
    }
    while (x->link != NULL)
    {
        x = x->link;
    }
    x->link = temp;
    return first;
}
NODE delete_rear(NODE first){
    NODE cur,prev;
    if (first==NULL){
        printf("List is empty");
        return first;
    }
    if (first->link==NULL){
        printf("item deleted is %d\n",first->item);
        free(first);
        return NULL;
    }
        prev=NULL;
        cur=first;
        while(cur->link!=NULL){
            prev=cur;
            cur=cur->link;
        }        
        printf("Item deleted at rearend is %d",cur->item);
        free(cur);
        prev->link=NULL;
        return first;
}
NODE deletefront(NODE first)
{   if (first==NULL)
    {
    printf("list is empty\n");
    return first;
    }
    NODE temp;
    temp = first;
    printf("Element deleted at front-end is %d \n",first->item);
    first = first->link;
    free(temp);
    return first;
}

void display(NODE first)
{
NODE temp;
if(first==NULL)
printf("list empty cannot display items\n");
for(temp=first;temp!=NULL;temp=temp->link)
{
printf("%d\n",temp->item);
}
}
void main()
{
    int item, choice, pos;
    NODE first = NULL;
    for (;;)
    {
        printf("\n 0: Exit \n 1: Insert_front\n 2: Delete_front\n 3: Insert_rear\n 4: Delete_rear\n 5: Display_list\n");
        printf(" enter the choice\n ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0: exit(0);
        case 1:
            printf("enter the item at front - end\n");
            scanf("%d",&item);
            first = insert_front(first, item);
            break;
        case 2:
            first = deletefront(first);
            break;
        case 3:
            printf("Enter the item at rear end");
            scanf("%d",&item);
            first = insert_rear(first, item);
            break;
        case 4:
            first = delete_rear(first);
            break;
        case 5:
            display(first);
            break;
        default:
            exit(0);
            break;
        }
    }
}
