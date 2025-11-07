int count=0;
void search_print_roll(ST *ptr,int roll)
{
	printf("Roll.No\t\t\tName\t\t\t percentage\n");
	while(ptr!=0)
	{
	    if(ptr->rollno==roll)
        {
            printf("%d\t\t\t%s\t\t\t %f\n",ptr->rollno,ptr->name,ptr->percentage);
            printf("Deleted successfully...!\n");
            ptr=ptr->next;
            return;
        }
        else if(ptr->rollno!=roll)
        {
            ptr=ptr->next;
           //printf("--\t\t\t--\t\t\t--\n");
          // printf("\nData Is Not Valid\n");
          // break;
        }
        else
            printf("\nData Is Not Valid\n");

	}

}
int search_print_name(ST *ptr,char *name)
{
	printf("Roll.No\t\t\tName\t\t\t percentage\n");
	while(ptr!=0)
	{
	    if(strcmp(ptr->name,name)==0)
        {
            count++;
            printf("%d\t\t\t%s\t\t\t %f\n",ptr->rollno,ptr->name,ptr->percentage);
            ptr=ptr->next;
        }
        else if((strcmp(ptr->name,name)>0)||(strcmp(ptr->name,name)>0))
        {
           //printf("--\t\t\t--\t\t\t--\n");
           //printf("\nData Is Not Valid\n");
          // break;
          ptr=ptr->next;
        }
        else
            printf("\nData Is Not Valid\n");

	}
	return count;

}
