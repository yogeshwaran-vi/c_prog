#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structst.h"
#include "add_end.h"
#include "print.h"
#include "delete_particular.h"

char op,ch,dc;
int roll;
char temp_name[20];
void choice(void);

int main()
{
	ST *head=0;
	
	printf("-----STUDENT RECORD MENU------\n");
	printf("  A/a	:Add New Record\n");
	printf("  D/d	:Delete A Record\n");
	printf("  S/s	:Show the List\n");
	printf("  M/m	:Modify A Record\n");
	printf("  T/t	:Sort the List\n");
	printf("  U/u	:Delete All the Records\n");
	printf("  R/r	:Reverse the List\n");
	printf("  V/v	:Save\n");
	printf("  E/e	:Exit\n");
	
	choice();

	while(1)
	{
	if((op=='A')|(op=='a'))
	{
		do
		{
			add_end(&head);
			printf("Do You Add More(y/n): \n");
	    		scanf(" %c",&ch);
		}while((ch=='y')||(ch=='Y'));

		choice();
	}
	else if((op=='D')|(op=='d'))
	{
		printf("Deleted by Rollno(R/r) or Name(N/n) Any one choose to Delete\n");
		scanf(" %c",&dc); //delete choice (dc)
		if((dc=='R')||(dc=='r'))
		{
			printf("Enter the Rollno: ");
			scanf("%d",&roll);
			delete_roll_particular(&head,roll);
			choice();			
		}
		else if((dc=='N')||(dc=='n'))
		{
			printf("Enter the Name: ");
			scanf("%s",temp_name);
			delete_name_particular(&head,(char *)&temp_name);
			choice();
		}	
	}
	else if((op=='S')|(op=='s'))
	{
		print(head);
		choice();
	}
	/*if((op=='M')|(op=='m'))
	if((op=='T')|(op=='t'))
	if((op=='U')|(op=='u'))
	iname[20]f((op=='R')|(op=='r'))
	if((op=='V')|(op=='v'))*/
	else
		exit(1);
	}
	
	
}
void choice(void)
{	
	printf("Enter your Choice: ");
	scanf(" %c",&op);
}
