//but full node is deleted
void delete_roll_particular(ST **ptr,int roll)
{
	ST *prev,*temp=*ptr;
	while(temp!=NULL)
	{
		if(temp->rollno==roll)
		{
			if(temp==*ptr)
				*ptr=temp->next;
			else
			{
				prev->next=temp->next;
			}
			free(temp);temp=NULL;
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
}
void delete_name_particular(ST **ptr,char*name)
{
        ST *prev,*temp=*ptr;
        while(temp!=NULL)
        {
                if(strcmp((const char*)temp->name,(const char*)name)==0)
                {
                        deleted_rollno=temp->rollno;
                        if(temp==*ptr)
                                *ptr=temp->next;
                        else
                        {
                                prev->next=temp->next;
                        }
                        free(temp);temp=NULL;
                }
                else
                {
                        prev=temp;
                        temp=temp->next;
                }
        }
}

