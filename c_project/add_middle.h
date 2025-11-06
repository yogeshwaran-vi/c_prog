void add_middle(ST **ptr)
{
	ST *temp=(ST*)malloc(sizeof(ST));
	printf("Enter the Name & Percentage");
	scanf("%s %f",temp->name,temp->percentage);
	if(*ptr==0)
	{
		*ptr->rollno=1;

	}
}
