void reverse_display(ST *ptr)
{
    if(ptr!=0)
    {
        reverse_display(ptr->next);
        printf("%d\t\t\t%s\t\t\t%f\n",ptr->rollno,ptr->name,ptr->percentage);
    }
}
