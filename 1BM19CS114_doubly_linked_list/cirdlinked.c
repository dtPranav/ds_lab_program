// insert front cur is important
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;
NODE getNode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Space is not available\n");
    }
    return temp;
}
void freeNode(NODE x)
{
    free(x);
}
NODE insertFront(NODE head, int it)
{   NODE cur;
    NODE temp = getNode();
    temp->item = it;
    temp->prev = NULL;
    temp->next = NULL;
    cur=head->next;
    temp->prev=head;
    temp->next=cur;
    head->next=temp;
    cur->prev=temp;
    head->item+=1;
    return head;
}
NODE insertRear(NODE head, int it)
{
    NODE temp = getNode();
    temp->item = it;
    temp->next = NULL;
    temp->prev = NULL;
    NODE cur=head->prev;
    temp->prev=cur;
    cur->next=temp;    
    head->prev=temp;
    temp->next=head;
    head->item+=1;
    return head;
}
NODE insert(NODE head, int pos, int item)
{
    NODE temp = getNode();
    NODE left;
    temp->item = item;
    temp->next = NULL;
    temp->prev = NULL;
    if (pos>((head->item)+2)){
        printf("List cannot be updated at this position\n");
        return head;
    }
    int count1 = 1;
    NODE cur = head->next;
    while (count1!= pos && cur!=head)
    {
        cur = cur->next;
        count1++;
    }
    left=cur->prev;
    left->next=temp;
    temp->prev=left;
    temp->next=cur;
    cur->prev=temp;
    head->item-=1;
    return head;
}
NODE del_rear(NODE head)
{
    if (head==head->next){
        printf("List is empty \n");
        return head;
    }
    NODE temp=head->prev;
    NODE prev=temp->prev;
    prev->next=head;
    head->prev=prev;
    printf("deleted item is %d\n",temp->item);   
    freeNode(temp);
    head->item-=1;
    return head;
}
NODE delete_all_pos(NODE head,int key){
    NODE cur=head->next;
    int count1=0;
    NODE p,n;
    if (head->next==head){
        printf("List is empty \n");
        return head;
    }
    while (cur!=head){
       if (cur->item==key){
           count1++;
           p=cur->prev;
           n=cur->next;
           p->next=n;
           n->prev=p;
           freeNode(cur);
           cur=n;
       }
       else{
        cur=cur->next;
       }
    }
    if (count1==0){
        printf("Key is not present in the list \n");
    }
    else{
        printf("%d nodes containing key %d deleted from the list \n",count1,key);
    }
    head->item-=count1;
    return head;
}
void display(NODE head)
{
    if (head->next == head)
    {
        printf("List is empty \n");
    }
    NODE cur = head->next;
    while (cur!= head)
    {
        printf("%d\n", cur->item);
        cur = cur->next;
    }
}
NODE del_front(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty \n");
    }
    NODE temp=head->next;
    NODE cur=temp->next;
    head->next=temp->next;
    cur->prev=head;
    printf("Deleted item is %d\n",temp->item);
    freeNode(temp);
    head->item-=1;
    return head;
}
NODE del_dup(NODE head,int key){
    NODE cur=head->next;
    NODE n,p;
    int count1=0;
    if (cur==head){
        printf("list is empty \n");
    }
    while(cur!=head){
        if (cur->item==key){
        count1++;
        break;
        }
        cur=cur->next;
    }
    if (count1!=1){
        printf("Key is not found \n");
        return head;
        }
    while (cur!=head){
       if (cur->item==key){
           count1++;
           p=cur->prev;
           n=cur->next;
           p->next=n;
           n->prev=p;
           freeNode(cur);
           cur=n;
       }
       else{
        cur=cur->next;
       }
    }    
    return head;
    }
void search(NODE head,int item){
    NODE cur=head->next;
    int count=0;
    while(cur!=head){
        count++;
        if (cur->item==item){
            printf("%d element is present at pos %d in list \n",item,count);
        }
        cur=cur->next;
    }
    if (count==head->item){
        printf("Element is not present in the list\n");
    }
}
NODE insert_left_pos(NODE head,int item){
    NODE cur,left,temp;
    temp=getNode();
    int count=0,key;
    cur=head->next;
    while(cur!=head){
        count++;
        if (cur->item==item)
            {
                printf("Enter the item to insert\n");
                scanf("%d",&key);
                temp->item=key;
                left=cur->prev;
                temp->next=cur;
                cur->prev=temp;
                left->next=temp;
                temp->prev=left;  
                return head;       
            }
    cur=cur->next;
    }
    printf("Entered element is not present in the list\n");
    return head;
}
void main()
{
    NODE head,last;
    head=getNode();
    head->item=0;
    head->next=head;
    head->prev=head;
    int ch=1, item, pos;
    while (ch != 0)
    {
        printf("\nChoose one of the following option: \n0)Exit \n1)Insert Front \n2)Insert Rear \n3)Insert at any position \n4)Delete Rear \n5)Delete Front \n6)Display \n7)Delete all key \n8)Del duplicates \n9)Search \n10)Insert left \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Enter the item to be inserted at front position\n");
            scanf("%d", &item);
            last = insertFront(head, item);
            break;
        case 2:
            printf("Enter the item to be inserted at rear position \n");
            scanf("%d", &item);
            last = insertRear(head, item);
            break;
        case 3:
            printf("Enter the position to insert the key \n");
            scanf("%d", &pos);
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            last = insert(head, pos, item);
            display(head);
            break;
        case 4:
            last = del_rear(head);
            display(head);
            break;
        case 5:
            last = del_front(head);
            display(head);
            break;
        case 6:
            display(head);
            break;
        case 7: 
            printf("Enter the item to be deleted\n");
            scanf("%d", &item);
            last=delete_all_pos(head,item);
            display(head);
            break;
        case 8:
            printf("Enter item whose dublicates have to be deleted\n");
            scanf("%d",&item);
            last=del_dup(head,item);
            display(head);
        break;
        case 9:printf("Enter item to be searched\n");
            scanf("%d",&item);
            search(head,item);
        break;
        case 10:
            printf("Enter item ,left to which a new element have to be inserted\n");
            scanf("%d",&item);
            last=insert_left_pos(head,item);
            break;
        default:
            printf("Invalid input \n");
            break;
        }
    }
}