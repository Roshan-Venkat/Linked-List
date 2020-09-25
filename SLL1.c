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
void insertNode(int num)
{
    newnode=(NODEPTR)malloc(sizeof(NODE));
    newnode->data=num;
    newnode->next=NULL;
    for(tptr=start;tptr&&tptr->data<newnode->data;shadow=tptr,tptr=tptr->next);
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
void searchNode(int num)
{
    for(tptr=start;tptr&&tptr->data!=num;
    tptr=tptr->next);
    if(tptr==NULL)
        printf("\n%d Not found\n",num);
    else
        printf("\n%d Found\n", tptr->data);
}
void deleteNode(int num)
{
    for(tptr=start;tptr&&tptr->data!=num;
    shadow=tptr,tptr=tptr->next);
    if(tptr==NULL)
        printf("\n%d Not found\n",num);
    else if(tptr==start)
    {
        start=start->next;
        free(tptr);
    }
    else
    {
        shadow->next=tptr->next;
        free(tptr);
    }
}
void deleteNLast(int N)
{
    int ctr;
    NODEPTR slow, fast;
    for(fast=start, ctr=1;fast&&ctr<=N;
    ctr++,fast=fast->next);
    if(fast==NULL)
    {
        printf("Not enuf elements to delete\n");
        return;
    }
    for(slow=start;fast;shadow=slow,
    slow=slow->next,fast=fast->next);
    shadow->next=slow->next;
    free(slow);
}
int findMid()
{
    NODEPTR slow, fast;
    for(slow=start,fast=start;fast&&
    fast->next;slow=slow->next,
    fast=fast->next->next);
    if(!slow)
        return -1;
    else
        return slow->data;
}
int main()
{
    int arr[]={100,10,90,70,50,30,20,60,80,40};
    int noe, index;
    noe=sizeof(arr)/sizeof(int);
    for(index=0;index<noe;index++)
        insertNode(arr[index]);
    displayList();
    //deleteNode(65);
    printf("\n");
    //deleteNLast(11);
    //displayList();
    printf("%d ",findMid());
}
