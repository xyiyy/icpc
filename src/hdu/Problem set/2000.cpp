#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
//	char a,b,c;
	char a[3];
	while(cin>>a[0]>>a[1]>>a[2])
	{
		//if(a>b&&a>c) cout
		//a=k[0];b[]
		sort(a,a+3);
		for(int i=0;i<2;i++)
		cout<<a[i]<<" ";
		cout<<a[2]<<endl;
		
	}
	return 0;
}
