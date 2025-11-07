void save(ST **ptr)
{
    ST*temp=*ptr;
    FILE *fd= fopen("Student_Record.txt","a+");

    fseek(fd, 0, SEEK_SET);

    char line[100];
    if(fgets(line, sizeof(line), fd) != NULL)
    {
        int file_roll;
        char file_name[50];
        float file_perc;

        while(fscanf(fd, "%d\t\t\t%s\t\t\t\t%f", &file_roll, file_name, &file_perc) == 3)
        {
            rollno = file_roll;
        }
    }

    fseek(fd,0,SEEK_END);
    if(ftell(fd) == 0)
        fprintf(fd,"RollNo\t\t\tName\t\t\t\tPercentage\n");

    while(temp!=0)
    {
        temp->rollno = rollno + 1;
        fprintf(fd,"%d\t\t\t%s\t\t\t\t%f\n",temp->rollno,temp->name,temp->percentage);
        rollno++;
        temp=temp->next;
    }
    fclose(fd);
}
