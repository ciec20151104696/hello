#include<stdio.h>
struct Node
{
	char name[40];
	int age;
	struct Node *next;
};
int main()
{
	struct Node *head,*p,*tail;
	head=new Node;
	head->next=0;
	tail=head;
	scanf("%s",head->name);
	scanf("%d",&head->age);
	for(int i=0;i<4;i++)
	{
		p=new Node;
		scanf("%s",p->name);
		scanf("%d",&p->age);
		p->next=0;
		tail->next=p;
		tail=p;
	} 
	p=head;
	while(p)
	{
		printf("%s  %d\n",p->name,p->age);
		p=p->next;
	}
	return 0;
}
