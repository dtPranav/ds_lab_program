#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct Node
{
    int item;
    struct Node *link;
};
typedef struct Node *NODE;
NODE getNode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct Node));
    return temp;
}
void freeNode(NODE x)
{
    free(x);
}
NODE insert_front(NODE first, int item)
{
    NODE temp = getNode();
    count += 1;
    temp->item = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    temp->link = first;
    first = temp;
    return first;
}
NODE insert_rear(NODE first, int item)
{
    NODE temp, x;
    count += 1;
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

NODE delete_rear(NODE first)
{
    NODE cur, prev;
    count -= 1;
    if (first == NULL)
    {
        printf("List is empty");
        return first;
    }
    if (first->link == NULL)
    {
        printf("item deleted is %d\n", first->item);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Item deleted at rearend is %d\n", cur->item);
    free(cur);
    prev->link = NULL;
    return first;
}
NODE deletefront(NODE first)
{
    NODE temp;
    count -= 1;
    temp = first;
    temp = temp->link;
    free(first);
    first = temp;
    return first;
}
NODE search(NODE first, int key)
{
    if (first->link == NULL)
    {
        printf("List is empty");
        return first;
    }
    NODE temp;
    temp = first;
    int count=0;
    if (first==NULL)
        printf("List is empty\n");
    while (temp!= NULL)
    {   count++;
        if (temp->item == key)
        {
            printf("Key found\n",count);
            return first;
        }
        temp=temp->link;
    }
    printf("Key not found\n");
    return first;
}
void display(NODE first)
{
    NODE temp;
    if (first == NULL)
        printf("list empty cannot display items\n");
    for (temp = first; temp != NULL; temp = temp->link)
    {
        printf("%d\n", temp->item);
    }
}
NODE order(NODE first, int item)
{
    NODE temp, prev, cur;
    temp = getNode();
    temp->item = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    if (item < first->item)
    {
        temp->link = first;
        return temp;
    }
    prev = NULL;
    cur = first;
    while (cur != NULL && item > cur->item)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = temp;
    temp->link = cur;
    return first;
}
NODE reverse(NODE first)
{
    NODE cur, temp;
    cur = NULL;
    while (first != NULL)
    {
        temp = first;
        first = first->link;
        temp->link = cur;
        cur = temp;
    }
    return cur;
}
NODE del_key(NODE first, int key)
{
    NODE prev;
    NODE temp = first;
    prev = first;
    while (temp->item != key)
    {
        if (temp->link == NULL)
        {
            prev->link = NULL;
            printf("\n No result found \n");
            return first;
        }
        prev = temp;
        temp = temp->link;
    }
    prev->link = temp->link;
    count -= 1;
    freeNode(temp);
    return first;
}
NODE ins_key(NODE first, int item, int pos)
{
    NODE prev, cur;
    cur = first;
    if (pos > count + 1)
    {
        printf("Enter correct position ");
        return first;
    }
    NODE temp = getNode();
    temp->item = item;
    temp->link = NULL;
    int c = 1;
    prev = cur;
    if (pos==1)
        return insert_front(first,item);
    while (c != pos)
    {
        prev = cur;
        cur = cur->link;
        c += 1;
    }
    temp->link = cur;
    prev->link = temp;
    return first;
}
NODE Sorting(NODE first)
{
    int temp;
    NODE cur = first;
    if (cur->link==NULL){
        return cur;
    }
    NODE index;
    while(cur != NULL) {  
                index = cur->link;                    
                while(index != NULL) {  
                    if(cur->item > index->item) {  
                        temp = cur->item;  
                        cur->item = index->item;  
                        index->item = temp;  
                    }  
                    index = index->link;  
                }  
                cur = cur->link;  
            }      
    return first;
}
void main()
{
    int item, choice=1, pos;
    NODE first = NULL;
    while(choice!=0)
    {
        printf("\n 0: Exit \n 1: Insert_front\n 2: Delete_front\n 3: Insert_rear\n 4: Delete_rear\n 5: Display_list\n 6: Order\n 7: Reverse \n 8: Search \n 9: Delete at specific position \n 10: Insert at any position \n 11: Sorting \n");
        printf(" enter the choice\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            printf("enter the item at front - end\n");
            scanf("%d", &item);
            first = insert_front(first, item);
            break;
        case 2:
            first = deletefront(first);
            display(first);
            break;
        case 3:
            printf("Enter the item at rear end");
            scanf("%d", &item);
            first = insert_rear(first, item);
            break;
        case 4:
            first = delete_rear(first);
            display(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            printf("enter the item\n");
            scanf("%d", &item);
            first = order(first, item);
            display(first);
            break;
        case 7:
            first = reverse(first);
            display(first);
            break;
        case 8:
            printf("Enter the item to searched for\n");
            scanf("%d", &item);
            first=search(first, item);
            break;
        case 9:
            printf("Deleted A specific key");
            scanf("%d", &item);
            first = del_key(first, item);
            display(first);
            break;
        case 10:
            printf("Enter the position of item to be inserted");
            scanf("%d", &pos);
            printf("Enter item to be inseted at any position");
            scanf("%d", &item);
            first = ins_key(first, item, pos);
            display(first);
            break;
        case 11:                                                    
            printf("\n Sorting the list \n");
            first=Sorting(first);
            display(first); 
            break;
        default:
            exit(0);
        }
    }
}