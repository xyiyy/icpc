#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		return 0;
		cout<<n<<endl;
		cout<<"Times:";
		int num=0;
		for(int i=1;i<n;i=3*i)
		{
			num++;
		}
		cout<<num<<endl;
	}
	return 0;
}
