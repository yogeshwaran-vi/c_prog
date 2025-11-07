void add_middle(ST **ptr,int roll,ST*temp)
{
    temp->rollno=roll;
	if((*ptr==0)||(roll<(*ptr)->rollno))
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
    {
        ST *last=*ptr;
        while((last->next!=0)&&(roll>last->next->rollno))
            last=last->next;

        temp->next=last->next;
        last->next=temp;
    }
}
