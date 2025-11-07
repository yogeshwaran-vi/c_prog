char temp[50];
float temp_per;
int temp_roll;
void sort_list(ST *head)
{
    ST *i,*j;
    for(i = head; (i != NULL && i->next != NULL); i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(strcmp(i->name, j->name) > 0)
            {
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);

                temp_per=i->percentage;
                i->percentage=j->percentage;
                j->percentage=temp_per;

                temp_roll=i->rollno;
                i->rollno=j->rollno;
                j->rollno=temp_roll;
            }
        }
    }
}
