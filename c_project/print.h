void print(ST *ptr)
{
	printf("Roll.No\tName\tpercentage\n");

	while(ptr!=0)
	{
		printf("%d\t%s\t%f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}
}
