void print(ST *ptr)
{
    //printf("------------------------------------------------------------\n");
	printf("Roll.No\t\t\tName\t\t\t percentage\n");
    printf("------------------------------------------------------------\n");
	while(ptr!=0)
	{
		printf("%d \t\t\t%s\t\t\t %f\n",ptr->rollno,ptr->name,ptr->percentage);
		printf("------------------------------------------------------------\n");
		ptr=ptr->next;
	}
}
