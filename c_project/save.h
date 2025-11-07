void save(ST **ptr)
{
    ST*temp=*ptr;
    FILE *fd= fopen("Student_Record.txt","a+");

    fseek(fd,0,SEEK_END);
    if(ftell(fd) == 0)
        fprintf(fd,"RollNo\t\t\tName\t\t\tPercentage\n");

    while(temp!=0)
    {
        fprintf(fd,"%d\t\t\t%s\t\t\t%f\n",temp->rollno,temp->name,temp->percentage);
        temp=temp->next;
        while()
    }
    fclose(fd);
}
