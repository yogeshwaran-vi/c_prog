int rollno=0;		
void add_end(ST **ptr)
{
	ST *temp;
	temp = (ST*)malloc(sizeof(ST));
	printf("Enter the Name and percentage\n");
	//printf("Name\tpercentage\n");
	scanf("%s%f",temp->name,&temp->percentage);

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
