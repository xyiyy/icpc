#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	double a[3];
	while(cin>>a[0]>>a[1]>>a[2])
	{
		sort(a,a+3);
		for(int i=0;i<2;i++)
		{
			cout<<a[i]<<", ";
		}
		cout<<a[2]<<endl;
	}
	return 0;
}

