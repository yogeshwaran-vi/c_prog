int deleted_rollno=0;
int rollno=0;char ch;

void add_middle(ST **,int ,ST*);

void add_end(ST **ptr)
{
	ST *temp;
	temp = (ST*)malloc(sizeof(ST));
	printf("\nEnter the Name and percentage\n");
	scanf("%s%f",temp->name,&temp->percentage);
	if(deleted_rollno!=0)
    {
        add_middle(ptr,deleted_rollno,temp);
        deleted_rollno=0;
        return;
    }
	if(*ptr == 0)
	{
		temp->next = 0;
		temp->rollno=++rollno;
		*ptr = temp;
	}
	else
	{
		ST *last = *ptr;

		while(last->next!=NULL)
			last=last->next;

		temp->next=last->next;
		temp->rollno=++rollno;
		last->next=temp;
	}

}
