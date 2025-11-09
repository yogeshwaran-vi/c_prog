void delete_allrecords(void)
{
    char ch;
    FILE *fs=fopen("Student_record.txt","r");
    FILE *fp=fopen("temp.txt","w");

    while((ch=fgetc(fs))!=EOF)
    {
        fprintf(fp,"%c",ch);
        if(ch=='\n')
        {
            fprintf(fp,"%c",'\n');
            break;
        }
    }
    fclose(fs);
    fclose(fp);

    remove("student_Record.txt");
    rename("temp.txt","student_Record.txt");
}
