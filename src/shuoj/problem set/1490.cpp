#include <iostream>
#include <cstring>
using namespace std;

char a[20000];
char b[20000];

int main()
{
	int N;
	cin>>N;
	int l=0;
	//cin.ignore();
	while(N--)
	{
		cout<<"Case "<<++l<<":"<<endl;
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		//gif(l>1)
		//getchar();
		cin.getline(a,20000,'\n');
		while(!strlen(a))
		{
			cin.getline(a,20000,'\n');
		}
	//	cin.ignore();
		cin.getline(b,20000,'\n');
	//	char *c=a
		cout<<b<<endl;
		cout<<a<<endl;
	}
	return 0;
}
	
	
	
