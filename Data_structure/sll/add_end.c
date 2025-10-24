#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
	int roll;
	char name[20];
	float marks;
	struct st *next;
}ST;

void add_end(struct st**);
void print(struct st *);
void delete_pos(struct st**,int);
int main()
{
	struct st *head=0;
	char add,del;
	int pos;
	do
	{
		add_end(&head);
		printf("do you add another student record(y/n): ");
		scanf(" %c",&add);
	}while(add=='y');

	print(head);
	printf("do you want delete any student record(y/n): ");
	scanf(" %c",&del);
	if(del=='y')
	{
		printf("enter the roll.no to delete it: ");
		scanf("%d",&pos);
		delete_pos(&head,pos);
		printf("after delete the roll.no to printing nodes\n");
		print(head);
	}


}
void add_end(struct st **ptr)
{
	struct st *temp,*last;
	temp=(struct st*)malloc(sizeof(struct st));

	printf("enter roll name and marks\n");
	scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);
	
	if(*ptr==0)
	{
		temp->next=0;
		*ptr=temp;
	}
	else
	{
		last=*ptr;
		while(last->next!=0)
			last=last->next;

		temp->next=last->next;
		last->next=temp;
	}
}
void print(struct st *ptr)
{
	printf("\nprinting the all node\n");

	while(ptr!=0)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
		ptr=ptr->next;
	}

}
void delete_pos(struct st **ptr,int n)
{
	struct st *prev,*temp;
	temp=*ptr;

	while(temp!=0)
	{
		if(temp->roll==n)
		{
			if(temp==*ptr)
				*ptr=temp->next;
			else
				prev->next=temp->next;

			free(temp);
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
}
