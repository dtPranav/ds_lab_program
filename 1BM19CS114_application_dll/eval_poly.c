#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int item,x,y;
    struct node* link;
};
typedef struct node* NODE;
NODE getNode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf(";mem full\n");
        exit(0);
    }
    return x;
}
void freeNode(NODE x)
{
    free(x);
}
NODE insert(NODE head,int x,int y,int item)
{  
    NODE temp = getNode();
    temp->item = item;
    temp->x = x;
    temp->y = y;
    temp->link=NULL;
    temp->link=head;
    head=temp;    
    return head;
}
int eval(NODE head,int x,int y){
    NODE temp;
    int sum=0;
    temp=head;
    while(temp!=NULL){
        sum+=((temp->item)*pow(x,temp->x)*pow(y,temp->y));
        temp=temp->link;
    }
    return sum;
}
void display(NODE head){
    NODE temp=head;
    while (temp!=NULL)
    {
        printf("+%dx^%dy^%d",temp->item,temp->x,temp->y);
        temp=temp->link;
    }
}
void main(){
    NODE head=NULL;
    int ch=1,x,y,result;
    printf("Enter first polynomial\n");
    while(ch==1){
    int x,y,item;
    printf("Enter power of x terms \n");
    scanf("%d",&x);
    printf("Enter power of y terms \n");
    scanf("%d",&y);
    printf("Enter coefficient of given x and y\n");
    scanf("%d",&item);
    head=insert(head,x,y,item);
    printf("Press 1 to continue\n");
    scanf("%d",&ch);
    }
    display(head);
    printf("\nEnter x:");
    scanf("%d",&x);
    printf("Enter y:");
    scanf("%d",&y);
    result=eval(head,x,y);
    printf("The result : %d",result);
}