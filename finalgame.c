#include<stdio.h>
#include<string.h>
int v,a[3][3]={1,2,3,4,5,6,7,8,9},f6=0,i,j,k,f2=0,f5=0,c[10],c1=0,f3=0,a1[3][3]={3,6,9,2,5,8,1,4,7},a2[3][3]={9,8,7,6,5,4,3,2,1},a3[3][3]={7,8,9,4,5,6,1,2,3},a4[3][3]={1,4,7,2,5,8,3,6,9},a5[3][3]={9,6,3,8,5,2,7,4,1};
char b[3][3],dup[3][3];;
main()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]='_';
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			v=i*3+j+1;
			printf("%d\t",v);
		}
		printf("\n");
	}
//	print();
	printf("\n\n");
	int f=0;
	printf("enter your first position");
	scanf("%d",&c[c1++]);
	for(i=0;i<3;i++)
	{
		
		for(j=0;j<3;j++)
		{
			if(a[i][j]==c[c1-1])
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			f=0;
			break;
		}
	}
	b[i][j]='X';
	print();
	printf("\n\n");
	if((c[c1-1]==1)||(c[c1-1]==2))
	{
		dup[1][1]='O';
		b[1][1]='O';
		second(a);
	}
	else if(c[c1-1]==3)
	{
		b[1][1]='O';
		second(a1);
	}
	else if(c[c1-1]==8||c[c1-1]==9)
	{
		b[1][1]='O';
		second(a2);
	}
	else if(c[c1-1]==7)
	{
		b[1][1]='O';
		second(a3);
	}
	else if(c[c1-1]==4)
	{
		b[1][1]='O';
		second(a4);
	}
	else if(c[c1-1]==6)
	{
		b[1][1]='O';
		second(a5);
	}
	else if(c[c1-1]==5)
	{
		b[0][0]='O';
		second(a);
	}
	if(f6==0)
		printf("---------------------------------------------------GAME DRAW--------------------------------------------------\n---------------------------------------------------THE END--------------------------------------------------\n");
}
second(int d[3][3])
{
	
	print();
	printf("\n\n");
	printf("enter next position where you want to insert");
	scanf("%d",&c[c1++]);
	int f=0;
	for(i=0;i<3;i++)
	{
		
		for(j=0;j<3;j++)
		{
			if(a[i][j]==c[c1-1])
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			f=0;
			break;
		}
	}
	b[i][j]='X';
	print();
	printf("\n\n");
	f5=1;
	check(d);
	if(f3==0){
		f5=0;
		check(d);
		//printf("%d\n",f2);
		if(f2==0)
		{
			exchange(b,d);
			printf("\n\n");
			if(dup[0][0]=='X'&&dup[1][2]=='X'&&dup[0][1]=='_'&&dup[0][2]=='_')
			{
				dup[0][2]='O';
				printf("\n\n");
				exchangeback(dup,d);
			}
			else if(dup[0][0]=='X'&&dup[2][1]=='X'&&dup[1][0]=='_'&&dup[2][0]=='_')
			{
				dup[2][0]='O';
				exchangeback(dup,d);
			}
			else if(dup[0][0]=='_'&&dup[2][0]=='X'&&dup[0][1]=='X'&&dup[1][0]=='_')
			{
				dup[0][0]='O';
				exchangeback(dup,d);
			}
			else if(dup[0][2]=='_'&&dup[2][2]=='X'&&dup[0][1]=='X'&&dup[0][2]=='_')
			{
				dup[0][2]='O';
				exchangeback(dup,d);
			}
			else if(dup[0][0]=='X'&&dup[2][2]=='X')
			{
				dup[1][0]='O';
				exchangeback(dup,d);
			}
			else if(dup[1][1]=='X'&&dup[2][2]=='X'&&dup[0][2]=='_')
			{
				dup[0][2]='O';
				exchangeback(dup,d);
			}
			else
			{
				int t=0;
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if(b[i][j]=='_')
						{
							t=1;
							b[i][j]='O';
							break;
						}
					}
					if(t==1)
						break;
				}	
			}
		}
	}
	print();
	printf("\n\n");
	third(d);
	

}
third(int d[3][3])
{
	int p1=2;
	while(p1)
	{
		printf("enter your next position");
		scanf("%d",&c[c1++]);
		int f=0;
		for(i=0;i<3;i++)
		{
			
			for(j=0;j<3;j++)
			{
				if(a[i][j]==c[c1-1])
				{
					f=1;
					break;
				}
			}
			if(f==1)
			{
				f=0;
				break;
			}
		}
		b[i][j]='X';
		print();
		f5=1;
		check(d);
		//result();
	//	printf("%d",f3);
		if(f3==0)
		{
			f5=0;
			check(d);
				if(f2==0)
			{
				int t=0;
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if(b[i][j]=='_')
						{
							t=1;
							b[i][j]='O';
							break;
						}
					}
					if(t==1)
						break;
				}	
			}
		}
		printf("\n\n");
		print();
		result();
		p1--;
	}
}
check(int d[3][3])
{
	char s2;
	
	f2=0;
	f3=0;
	if(f5==1)
	s2='O';
	else
	s2='X';
	char s[3];
	for(i=0;i<3;i++)
	{
		s[0]=b[i][0];
		s[1]=b[i][1];
		s[2]=b[i][2];
		if(s[0]==s2&&s[1]==s2&&s[2]=='_')
		{
			f2=1;
			f3=1;
			b[i][2]='O';
			return;
		}
		if(s[0]==s2&&s[1]=='_'&&s[2]==s2)
		{
			f2=1;
			f3=1;
			b[i][1]='O';
			return;
		}
		if(s[0]=='_'&&s[1]==s2&&s[2]==s2)
		{
			f2=1;
			f3=1;
			b[i][0]='O';
			return;
		}
	}
	for(i=0;i<3;i++)
	{
		s[0]=b[0][i];
		s[1]=b[1][i];
		s[2]=b[2][i];
		if(s[0]==s2&&s[1]==s2&&s[2]=='_')
		{
			f2=1;
			f3=1;
			b[2][i]='O';
			return;
		}
		if(s[0]==s2&&s[1]=='_'&&s[2]==s2)
		{
			f2=1;
			f3=1;
			b[1][i]='O';
			return;
		}
		if(s[0]=='_'&&s[1]==s2&&s[2]==s2)
		{
			f2=1;
			f3=1;
			b[0][i]='O';
			return;
		}
	}
	if(b[0][0]==s2&&b[1][1]==s2&&b[2][2]=='_')
	{
		f2=1;
		f3=1;
		b[2][2]='O';
		return;
	}
	if(b[0][0]==s2&&b[1][1]=='_'&&b[2][2]==s2)
	{
		f2=1;
		f3=1;
		b[1][1]='O';
		return;
	}
	if(b[0][0]=='_'&&b[1][1]==s2&&b[2][2]==s2)
	{
		f2=1;
		f3=1;
		b[0][0]='O';
		return;
	}
	if(b[0][2]==s2&&b[1][1]==s2&&b[2][0]=='_')
	{
		f2=1;
		f3=1;
		b[2][0]='O';
		return;
	}
	if(b[0][2]=='_'&&b[1][1]==s2&&b[2][0]==s2)
	{
		f2=1;
		f3=1;
		b[0][2]='O';
		return;
	}
	if(b[0][2]==s2&&b[1][1]=='_'&&b[2][0]==s2)
	{
		f2=1;
		f3=1;
		b[1][1]='O';
		return;
	}
	
}
print()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%c\t",b[i][j]);
		}
	printf("\n");
	}
}
exchange(char d1[3][3],int d[3][3])
{
	int p1,p2;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			p1=(d[i][j]-1)/3;
			p2=(d[i][j]-1)%3;
			dup[i][j]=d1[p1][p2];
		}
	}
}
exchangeback(char d2[3][3],int d[3][3])
{
	int p1,p2;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			p1=(d[i][j]-1)/3;
			p2=(d[i][j]-1)%3;
			b[p1][p2]=d2[i][j];
		}
	}
}
result()
{
	for(i=0;i<3;i++)
	{
		if((b[i][0]=='O'&&b[i][1]=='O'&&b[i][2]=='O')||(b[0][i]=='O'&&b[1][i]=='O'&&b[2][i]=='O')){
			printf("---------------------------------------------------COMPUTER WON--------------------------------------------------\n---------------------------------------------------THE END--------------------------------------------------\n");
			f6=1;
			break;
		}
	}
	if(b[0][0]=='O'&&b[1][1]=='O'&&b[2][2]=='O'){
			printf("---------------------------------------------------COMPUTER WON--------------------------------------------------\n---------------------------------------------------THE END--------------------------------------------------\n");
		f6=1;
		
	}
	else if(b[0][2]=='O'&&b[1][1]=='O'&&b[2][0]=='O')
	{
				printf("---------------------------------------------------COMPUTER WON--------------------------------------------------\n---------------------------------------------------THE END--------------------------------------------------\n");
			f6=1;
	}
	
	
}
