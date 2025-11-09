#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_all_files.h"

char op,ch,dc;
int roll;
char temp_name[20];

void choice(void);
void in_valid(void);
void scan_roll(void);
void scan_name(void);
int search_print_roll(ST *,int);
int search_print_name(ST *,char *);

int main()
{
	ST *head=0;

    //file_read(&head);

	printf("|_-_-_-_-_-_-_-_-STUDENT RECORD MENU_-_-_-_-_-_-_-_-|\n");
	printf("|\t\tA/a:Add New Record                  |\n");
	printf("|\t\tD/d:Delete A Record                 |\n");
	printf("|\t\tS/s:Show The List                   |\n");
	printf("|\t\tM/m:Modify A Record                 |\n");
	printf("|\t\tT/t:Sort The List                   |\n");
	printf("|\t\tU/u:Delete All The Records          |\n");
	printf("|\t\tR/r:Reverse The List                |\n");
	printf("|\t\tV/v:Save                            |\n");
	printf("|\t\tE/e:Exit                            |\n");
	printf("|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|\n");

	choice();

	while(1)
	{
	if((op=='A')|(op=='a'))
	{
		do
		{
			add_end(&head);
			printf("\nDo You Add More(y/n): ");
            scanf(" %c",&ch);
		}while((ch=='y')||(ch=='Y'));

		choice();
	}
	else if((op=='D')|(op=='d'))
	{
		printf("Deleted by RollNo(R/r) or Name(N/n): ");
		scanf(" %c",&dc); //delete choice (dc) declared in global
		if((dc=='R')||(dc=='r'))
		{
			scan_roll();
			int count=search_print_roll(head,roll);
			if(count==1)
            {
			delete_roll_particular(&head,roll);
			deleted_rollno=roll;
			choice();
			}
			else
            {
               printf("Data is Not Valid\n");
               choice();
            }
		}

		else if((dc=='N')||(dc=='n'))
		{
			scan_name();
			count=search_print_name(head,(char *)&temp_name);
            if((count!=0)&&(count!=1))
            {
             scan_roll();
             delete_roll_particular(&head,roll);
             deleted_rollno=roll;
             printf("\nDeleted Successfully...!\n");
			 choice();
            }
            else if(count==1)
            {
                scan_name();
                delete_name_particular(&head,(char *)&temp_name);
                //deleted_rollno=rollno; //this deleted_roll assign in function
                printf("\nDeleted Successfully...!\n");
			    choice();
            }
            else
            {
                printf("Data is Not Valid\n");
                choice();
            }
		}
		else
        {
           in_valid();
        }
        //choice();
	}
	else if((op=='S')|(op=='s'))
	{
		print(head);
		choice();
	}
	else if((op=='V')|(op=='v'))
    {
        save(head);
        printf("Save successfully...\n");
        choice();
    }
	else if((op=='M')|(op=='m'))
    {
        printf("Enter The RollNo(R/r) & Name(N/n) To Modify: ");
        scanf(" %c",&ch);
        printf("\n");

        if((ch=='r')||(ch=='R'))
        {
            scan_roll();
            modify_roll(&head,roll);
            choice();
        }
        else if((ch=='N')||(ch=='n'))
        {
            scan_name();
            modify_name(&head,(char *)&temp_name);
            choice();
        }
        else
        {
           in_valid();
        }
    }
	else if((op=='T')|(op=='t'))
	{
        printf("Enter The Name(N/n) & Percentage(P/p) To Sort: ");
        scanf(" %c",&ch);
        printf("\n");
        if((ch=='N')||(ch=='n'))
        {
	    sort_list_name(head);
	    choice();
        }
        else if((ch=='P')||(ch=='p'))
        {
	    sort_list_percentage(head);
	    choice();
        }
        else
            in_valid();
	}
	else if((op=='U')|(op=='u'))
    {
         delete_allrecords();
         free(head);
         head=NULL;
         printf("\nSuccessfully Delete All Record...\n");
         deleted_rollno=0;
         choice();
    }
	else if((op=='R')|(op=='r'))
    {
        printf("------------------------------------------------------------\n");
        printf("Roll.No\t\t\tName\t\t\t percentage\n");
        printf("------------------------------------------------------------\n");
        reverse_display(head);
        choice();
    }
	else if((op=='e')|(op=='E'))
    {
        printf("Do You Want To Save The Changes(y/n):  ");
        scanf(" %c",&ch);

        if((ch=='y')||(ch=='Y'))
        {
            save(head);
            printf("\nSave successfully...\n");
            exit(1);
        }
        else if((ch=='n')||(ch=='N'))
        {
            exit(1);
        }
    }
    else
        in_valid();
	}
}
void choice(void)
{
	printf("\nEnter your Choice: ");
	scanf(" %c",&op);
	printf("\n");
}
void in_valid(void)
{
    printf("\nPlease Enter the valid data..!\n");
    printf("\n");
    choice();
}
void scan_roll(void)
{
    printf("\nEnter the RollNo: ");
    scanf(" %d",&roll);
    printf("\n");
}
void scan_name(void)
{
    printf("\nEnter the Name: ");
    scanf(" %s",temp_name);
    printf("\n");
}
