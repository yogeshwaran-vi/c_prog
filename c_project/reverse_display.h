void reverse_display(ST *ptr)
{
    if(*ptr!=0)
    {
        reverse_display(ptr->next);
        printf("%d\t\t\t%s\t\t\t%f",ptr->rollno,ptr->name,ptr->percentage);
    }
}
