#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int N;
	char a[2000];
	cin>>N;
	while(N--)
	{
		memset(a,'\0',sizeof(a));
		cin>>a;
		int n=strlen(a);
		int flag=1;
		for(int i=0;i<n/2;i++)
		{
			if(a[i]!=a[n-1-i])flag=0;
			if(!flag)break;
		}
		if(flag)cout<<"YES!"<<endl;
		else cout<<"NO!"<<endl;
	}
	return 0;
}
		
