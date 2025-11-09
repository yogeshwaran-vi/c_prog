float temp_per;
int temp_roll,c=0,c1=0;
void sort_list_name(ST *head)
{
    ST *temp=head,swap_temp;
    int i,j,k;
    while(temp!=0)
    {
        c++;
        temp=temp->next;
    }
    ST arr[c];
    temp=head;
    for(k=0;k<c;k++)
    {
        arr[k]=*temp;
        arr[k].next=NULL;
        temp=temp->next;
    }

    for(i = 0; i<c-1; i ++)
    {
        for(j = i+1; j<c; j++)
        {
            if(strcmp(arr[i].name,arr[j].name)>0)
            {
                swap_temp=arr[i];
                arr[i]=arr[j];
                arr[j]=swap_temp;
            }
        }
    }
    printf("------------------------------------------------------------\n");
	printf("Roll.No\t\t\tName\t\t\t percentage\n");
    printf("------------------------------------------------------------\n");
    for(i=0;i<c;i++)
    {
        printf("%d\t\t\t%s \t\t\t%f\n",arr[i].rollno,arr[i].name,arr[i].percentage);
        printf("------------------------------------------------------------\n");
    }
}
void sort_list_percentage(ST *head)
{
    ST *temp=head,swap_per;
    ST per[c1];
    int i,j,k;
    while(temp!=0)
    {
        c1++;
        temp=temp->next;
    }
    temp=head;
    for(k=0;k<c1;k++)
    {
        per[k]=*temp;
        per[k].next=NULL;
        temp=temp->next;
    }

    for(i = 0; i<c1-1; i ++)
    {
        for(j = i+1; j<c1; j++)
        {
            if(per[i].percentage<per[j].percentage)
            {
                swap_per=per[i];
                per[i]=per[j];
                per[j]=swap_per;
            }
        }
    }
    printf("------------------------------------------------------------\n");
	printf("Roll.No\t\t\tName\t\t\t percentage\n");
    printf("------------------------------------------------------------\n");
    for(i=0;i<c1;i++)
    {
        printf("%d\t\t\t%s \t\t\t%f\n",per[i].rollno,per[i].name,per[i].percentage);
        printf("------------------------------------------------------------\n");
    }
}
