#include <stdio.h>
#include <stdlib.h>
struct st
{
	struct st *prev;
	int roll;
	char name[20];
	struct st *next;
}ST;
void add_end(struct st**ptr)
{
	struct st*temp=(struct st*)malloc(sizeof(struct st));
	printf("Enter the roll and name\n");
	scanf("%d %s",&temp->roll,temp->name);

	if(*ptr==0)
	{
		temp->prev=*ptr;
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		struct st*last=*ptr;

		while(last->next!=0)
			last=last->next;

		temp->prev=last;
		temp->next=last->next;
		last->next=temp;
	}
}
void display(struct st*ptr)
{
	while(ptr!=0)
	{
		printf("roll:%d\tname:%s\n",ptr->roll,ptr->name);
		ptr=ptr->next;
	}
}
int x;
void delete_particular(struct st *ptr)
{
	printf("Enter the roll no to delete the data: ");
	scanf("%d",&x);
	while(ptr!=0)
	{
		if(ptr->roll==x)
		{
			free(ptr);
			ptr=NULL;	
		}
		else
			ptr=ptr->next;
	}
}
int main()
{
	struct st *head=0;
	int op;

	while(1)
	{
		printf("1:do you to add node\n");
		printf("2:do you want to display\n");
		printf("3:do you to delete particular data\n");
		printf("4:exit\n");
		scanf("%d",&op);

		switch(op)
		{
			case 1:add_end(&head);break;
			case 2:display(head);break;
			case 3:delete_particular(head);break;
			default:exit(0);
		}
	}
}
