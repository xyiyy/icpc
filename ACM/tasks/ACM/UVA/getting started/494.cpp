#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;
int main()
{
	char a[10000];
	while(cin.getline (a,10000))
	{
		int len =strlen(a);
		int num=0;
		for(int i=0;i<len ;i++)
		{
			if(a[i]<65||(a[i]>90&&a[i]<97)||a[i]>122)
			{
				//i++;
			continue;
		}
			while(a[i]>64&&a[i]<91||(a[i]>96&&a[i]<123))
			{
				i++;
			}
			num++;
		}
		cout<<num<<endl;
		memset(a,'\0',10000);
	}
	return 0;
}
