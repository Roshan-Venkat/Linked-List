#include<bits/stdc++.h>
#define mod 1000000007
#define FAST ios_base::sync_with_stdio(false);
#define SYNC cin.tie(NULL);
using namespace std;
struct node{
	int data;
	struct node* next;
	node(int x)
	{
		data = x;
		next = NULL;
	}
};
int main()
{
	FAST
	SYNC
	node* head = new node(190);
	head->next = new node(91);
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head ->next;
	}
}

