#include <iostream>
#include <algorithm>
using namespace std;

double a[3];
int main()
{
	while (cin>>a[0]>>a[1]>>a[2])
	{
		sort(a,a+3);
		cout<<a[2]<<endl;
	}
	return 0;
}

