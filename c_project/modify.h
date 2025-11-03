char modname[20],mod;
float mod_percentage;
void modify_roll(ST **ptr,int n)
{
	ST *temp=*ptr;
	while(temp!=NULL)
	{
		if(temp->rollno == n)
		{
			printf("Enter modify Name(N/n) or percentage(P/p)\n");
			scanf(" %c",&mod);
			if((mod=='N')||(mod=='n'))
			{
				printf("Enter The Name to change\n");
				scanf("%s",modname);
				strcpy(temp->name , modname);
				break;
			}
			else
			{
				printf("Enter The Percentage To Change\n");
				scanf("%f",&mod_percentage);
				temp->percentage = mod_percentage;
			}
		}
		else
		{
			temp=temp->next;
		}

	}
}
void modify_name(ST **ptr,char* name)
{
	ST *temp=*ptr;
	while(temp!=NULL)
	{
                if(strcmp((const char*)temp->name,(const char*)name)==0)
		{
			printf("Enter modify Name(N/n) or percentage(P/p)\n");
			scanf(" %c",&mod);
			if((mod=='N')||(mod=='n'))
			{
				printf("Enter The Name to change\n");
				scanf("%s",modname);
				strcpy(temp->name , modname);
				break;
			}
			else
			{
				printf("Enter The Percentage To Change\n");
				scanf("%f",&mod_percentage);
				temp->percentage = mod_percentage;
			}
		}
		else
		{
			temp=temp->next;
		}

	}
}
