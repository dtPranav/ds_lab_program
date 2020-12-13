#include<stdio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node* link;
};
typedef struct node* NODE;
NODE getNode(){
    NODE temp=(NODE)malloc(sizeof(struct node));
    return temp;
}
void freeNode(NODE temp){
    free(temp);
}
NODE insert_front(NODE last,int key){
    NODE temp=getNode();
    temp->item=key;
    if (last==NULL){
        temp->link=temp;
        return temp;
    }
    temp->link=last->link;
    last->link=temp;
    return last;
}
NODE insert_rear(NODE last,int key){
    NODE temp=getNode();
    temp->item=key;
    if (last==NULL){
        return temp;
    }
    temp->link=last->link;
    last->link=temp; 
    return temp;
}
NODE delete_front(NODE last){
    NODE temp;
    if (last==NULL){
        printf("List is empty \n");
    }
    temp=last->link;
    last->link=temp->link;
    freeNode(temp);
    return last;
}
NODE delete_rear(NODE last){
    NODE prev,cur,l;
    if (last==NULL){
        printf("List is empty \n");
    }
    l=last;
    cur=last->link;

    do{ 
        cur=cur->link;
    }while(cur->link!=l);
    cur->link=last->link;
    return cur;
}
void display(NODE last){
    if (last==NULL){
        printf("List is empty\n");
    }
    NODE cur=last;
    NODE l=last->link;
    do{
        cur=cur->link;
        printf("%d\n",cur->item);
    }while(cur->link!=l);
}
int main(){ 
    NODE last=NULL;
    int s,key;
    while(s!=0){
    printf("\n 1: Insert Front \n 2: Insert Rear \n 3: Delete Front \n 4: Delete Rear \n 5: Display \n");
    printf("Enter the choice \n");
    scanf("%d",&s);

    switch(s){
        case 0: exit(0);
        break;
        case 1:printf("Enter the item to be inserted in the front end \n");
            scanf("%d",&key);
            last=insert_front(last,key); 
            break;
        case 2:printf("Enter the item to be inserted at rear end \n");
        scanf("%d",&key);
        last=insert_rear(last,key);
        break;
        case 3: printf("Item deleted at the front end \n");
        last=delete_front(last);
        break;
        case 4: printf("Item deleted at the rear end \n");
        last=delete_rear(last);
        break;
        case 5: printf("list contains \n ");
        display(last);
    }
    }
    return 0;
}

