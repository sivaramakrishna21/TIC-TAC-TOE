#include<stdio.h>
main()
{
	char str[1000],a[1000];
	int s=1,n,i,r,j,k;
	printf("enter your string");
	gets(str);
	for(n=0;str[n]!='\0';n++);
	for(i=0;i<n;i++)
	s=s*2;
	
	for(i=1;i<s;i++)
	{
		r=i;
		j=n-1;
		while(r)
		{
			a[j]=r%2;
			r=r/2;
			j--;
		}
		for(k=0;str[k]!='\0';k++)
		{
			if(a[k]==1)
			printf("%c",str[k]);
		}
		printf("\n");
	}
}
