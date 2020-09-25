#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    char data;
    struct node *next;
}NODE;
typedef NODE * NODEPTR;
NODEPTR start, tptr, newnode, shadow;
void insertNode(char ch)
{
    newnode=(NODEPTR)malloc(sizeof(NODE));
    newnode->data=ch;
    newnode->next=NULL;
    for(tptr=start;tptr;shadow=tptr,tptr=tptr->next);
    if(start==NULL)
        start=newnode;
    else
        shadow->next=newnode;
}
void displayList()
{
    for(tptr=start;tptr;tptr=tptr->next)
        printf("%c ",tptr->data);
}
void reverse2Half()
{
    NODEPTR slow, fast, before, now, after;
    for(slow=fast=start;fast&&fast->next;
    shadow=slow,slow=slow->next,
    fast=fast->next->next);
    before=after=NULL;
    now=slow;
    while(now)
    {
        after=now->next;
        now->next=before;
        before=now;
        now=after;
    }
    shadow->next=before;
}
void reverse1Half()
{
    NODEPTR slow, fast, before, now, after;
    for(slow=fast=start;fast&&fast->next;
    shadow=slow,slow=slow->next,
    fast=fast->next->next);
    after=NULL;
    before=slow;
    now=start;
    while(now!=slow)
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
    char str[100];
    int index;
    scanf("%s",str);
    for(index=0;str[index];index++)
        insertNode(str[index]);
    displayList();
    reverse1Half();
    printf("\n");
    displayList();
}
