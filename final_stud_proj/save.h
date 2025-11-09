void save(ST*ptr)
{
	FILE *fp=fopen("student_record.txt","w");
	ST *tmp=ptr;
	//fseek(fp,0,SEEK_END);
	//if(ftell(fd)==0)
        fprintf(fp,"RollNo\t\t\tName\t\t\tPercentage\n");

	while(tmp!=0)
	{
		fprintf(fp,"%d\t\t\t%s\t\t\t%f\n",tmp->rollno,tmp->name,tmp->percentage);
		tmp=tmp->next;
	}
	fclose(fp);
}
void file_read(ST **ptr)
{
    int x=1;
	FILE *fp=fopen("student_record.txt","r");
	if(fp==NULL)
	{
		return;
	}
	else
	{
		while(x!=-1)
		{
			ST *tp=(ST *)malloc(sizeof(ST));
			x=fscanf(fp,"%d%s%f\n",&tp->rollno,tp->name,&tp->percentage);
			if(x!=-1)
            {
			if(*ptr==NULL)
			{
				tp->next=*ptr;
				*ptr=tp;
			}
			else
			{
				ST *last=*ptr;
				while(last->next!=0)
                    last=last->next;

				tp->next=last->next;
				last->next=tp;
			}
            }
        }
	}
}
