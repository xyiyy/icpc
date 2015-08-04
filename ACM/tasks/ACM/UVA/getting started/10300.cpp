#include<iostream>
using namespace std;

int a[20],b[20],c[20];
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int t ,k=0;
		cin>>t;
		for(int i=0;i<t;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			k+=a[i]*c[i];
		}
		cout<<k<<endl;
	}
	return 0;
}
