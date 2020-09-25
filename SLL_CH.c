#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    char ch;
    struct node *next;
}NODE;
typedef NODE* NODEPTR;
NODEPTR start, newnode, shadow, tptr;
void insertNode(char data)
{
    newnode=(NODEPTR)malloc(sizeof(NODE));
    newnode->ch=data;
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
        printf("%c ",tptr->ch);
}
int main()
{
    char str[100];
    int index;
    printf("\n\n\n\n\n\n");
    scanf("%s",str);
    for(index=0;str[index];index++)
        insertNode(str[index]);

    displayList();
    return 0;

}
