#include <stdio.h>
#include <stdlib.h>

struct st
{
	int roll;
	char name[20];
	float marks;
	struct st *next;
};

void add_begin(struct st **);
void print(struct st *);
void revs_print(struct st *ptr);
void save(struct st*);

int main()
{
	struct st *head=0;
	char op;

	do
	{
		add_begin(&head);
		printf("Do you add one more student record 'y' or 'n':  ");
		scanf(" %c",&op);
	}while(op=='y');
	
	print(head);
	printf("\nafter reverse printing...\n");
	revs_print(head);
	save(head);
}
void add_begin(struct st **ptr)
{
	struct st *temp;
	temp=(struct st*)malloc(sizeof(struct st));

	printf("enter the roll,name and marks\n");
	scanf("%d %s %f",&temp->roll,temp->name,&temp->marks);

	temp->next=*ptr;
	*ptr=temp;
}
void print(struct st *ptr)
{
	printf("\nprinting the all nodes...\n");

	while(ptr!=0)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}
void revs_print(struct st *ptr)
{
	if(ptr!=0)
	{
		revs_print(ptr->next);
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
	}
}
void save(struct st *ptr)
{
	FILE *fp=fopen("data.txt","w");

	while(ptr!=0)
	{
		fprintf(fp,"%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}
