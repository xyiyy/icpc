#include <iostream>
#include <cstring>
using namespace std;

char a[20000];
char b[20000];

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		cin>>a;
		int n=strlen(a);
		for(int i=0;i<n;i++)
		{
			b[i]=a[n-1-i];
		}
		cout<<b<<endl;
	}
	return 0;
}


