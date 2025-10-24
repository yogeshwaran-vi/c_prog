#include <stdio.h>
#include <stdlib.h>

struct st
{
	struct st *prev;
	int roll;
	char name[20];
	float marks;
	struct st *next;
};

void add_begin_dll(struct st **);
void reverse_print(struct st *);

int main()
{
	struct st *head=0;
	char add;
	do
	{
		add_begin_dll(&head);
		printf("do you add another student record(y/n): ");
		scanf(" %c",&add);
	}while(add=='y');

	printf("\nprinting all node....\n");
	reverse_print(head);	
}
void add_begin_dll(struct st **ptr)
{
	struct st *temp;
	temp=(struct st*)malloc(sizeof(struct st));

	printf("enter roll,name and marks");
	scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);

	temp->prev=0;
	temp->next=*ptr;

	if(*ptr!=0)
	{
		(*ptr)->prev=temp;
	}
	*ptr=temp;
}
void reverse_print(struct st *ptr)
{

	if(ptr!=0)
	{
		reverse_print(ptr->next);
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
	}
}
