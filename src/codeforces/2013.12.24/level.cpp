#include<iostream>
#include<cstring>
using namespace std;

char s[1000000];
int main()
{
	int i=0;
	while(cin.getline(s,1000000))
	{
		int pivot=0;
		for(i=0;pivot==0;i++)
		{
			if(s[i]==94)
			{
				pivot=i+1;
			}
		}
		int len=strlen(s);
		int a[pivot-1];
		int b[len-pivot];
		for(i=0;i<pivot-1;i++)
		{
			if(s[i]==61)
			{
				a[pivot-2-i]=0;
			}
			else
			{
				a[pivot-2-i]=s[i]-48;
			}
		}
		for(i=0;i<len-pivot;i++)
		{
			if(s[i+pivot]==61)
			{
				b[i]=0;
			}
			else
			{
				b[i]=s[pivot+i]-48;
			}
		}
		int left=0,right=0;
		for(i=0;i<pivot-1;i++)
		{
			left+=a[i]*(i+1);
		}
		for(i=0;i<len-pivot;i++)
		{
			right+=b[i]*(i+1);
		}
		if(left==right)
		{
			cout<<"balance"<<endl;
		}
		else
		{
			if(left<right)
			{
				cout<<"right"<<endl;
			}
			else
			{
				cout<<"left"<<endl;
			}
		}
		for(i=0;i<len;i++)
		{
			s[i]='\0';
		}
	}
	return 0;
}
			
				
				
				
				
				
				
				
				
				
				
				
