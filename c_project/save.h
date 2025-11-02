void save(ST *ptr)
{
    FILE *fp= fopen("student.txt","a+");

    while(ptr!=0)
    {
        fprintf(fp,"%d\t\t\t%s\t\t\t%f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
}
