#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
typedef struct node* NODEPTR;
NODEPTR start, tptr, newnode, shadow;
void displayList()
{
    for(tptr=start;tptr;tptr=tptr->next)
        printf("%d ",tptr->data);
}
void displayListBWD(NODEPTR ptr)
{
    if(ptr==NULL)
        return;
    else
    {
        displayListBWD(ptr->next);
        printf("%d ",ptr->data);
    }
}
void insertNode(int num)
{
    newnode=(NODEPTR)malloc(sizeof(NODE));
    newnode->data=num;
    newnode->next=NULL;
    for(tptr=start;tptr&&tptr->data<
    newnode->data;shadow=tptr,
    tptr=tptr->next);
    if(tptr==start)
    {
        newnode->next=start;
        start=newnode;
    }
    else
    {
        newnode->next=shadow->next;
        shadow->next=newnode;
    }
}
void reverseList()
{
    NODEPTR before, now, after;
    before=NULL;
    now=start;
    after=NULL;
    while(now)
    {
        after=now->next;
        now->next=before;
        before=now;
        now=after;
    }
    start=before;
}
int main()
{
    int arr[]={30,40,10,20,90,100,70,80,60,50};
    int noe, index;
    noe=sizeof(arr)/sizeof(arr[0]);
    for(index=0;index<noe;index++)
        insertNode(arr[index]);
    displayList();
    printf("\n");
    displayListBWD(start);
    //reverseList();
    //displayList();
}
