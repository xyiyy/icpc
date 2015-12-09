#include <iostream>
#include <iomanip>
using namespace std;
int n=0;
//int a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin>>hex;
	while(cin>>n)
	{
	//	a=b=n;
		cout<<uppercase<<oct<<n<<"(Oct), "
			<<dec<<n<<"(Dec), "
			<<hex<<n<<"(Hex)"<<endl;
	}
	return 0;
}

