char ch,dc;
int roll;
char temp_name[20];
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
    printf("\nEnter the RollNo:\n");
    scanf(" %d",&roll);
    printf("\n");
}
void scan_name(void)
{
    printf("\nEnter the Name:\n");
    scanf(" %s",temp_name);
    printf("\n");
}
