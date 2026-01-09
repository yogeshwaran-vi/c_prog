#include<stdio.h>
#include<string.h>
char* rm_splchr(char*);
char sort(char*,char*);
char* up_lower(char*);
int len1,len2;
int main()
{
	int i,j,temp,x;
	char a[50],b[50];
	printf("enter the 2 strings: ");
	scanf("%s %s",a,b);
			
	rm_splchr(a);
	rm_splchr(b);

	up_lower(a);
	up_lower(b);

	int p=sort(a,b);

	if(p==0)
	  printf("this is anagram");
	else
	  printf("this is not anagram");
}
char* rm_splchr(char *p)
{
	int i,j;
	for(i=0;p[i]!='\0';i++)
	{
	   if(!((p[i]>'A' && p[i]<'Z') || (p[i]>'a' && p[i]<'z')))		
	     {
		 for(j=i;p[j]!='\0';j++)
		 {
	            p[j]=p[j+1];
		 }
		 i--;                                                                         
	     }
	  
	}
	return p;
}
char sort(char*p,char*q)
{
	int i,j,temp;
	len1=strlen(p);
	len2=strlen(q);
	
	for(i=0;i<len1;i++)
	{
	   for(j=i+1;j<len1;j++)
		{
		  if(p[i]>p[j])
			{
	         	   temp=p[i];
			   p[i]=p[j];
			   p[j]=temp;
			}
		}
	}
	for(i=0;i<len2;i++)
        {
             for(j=i+1;j<len2;j++)
                {
                     if(q[i]>q[j])
                        {
                             temp=q[i];
                             q[i]=q[j];
                             q[j]=temp;
                        }
                }
        }
	if(strcmp(p,q)==0)
		return 0;
	else
		return 1;

}
char* up_lower(char*p)
{
	int i;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>='A' && p[i]<='Z')
		{
			p[i]+=32;
		}

	}
	return p;
}
