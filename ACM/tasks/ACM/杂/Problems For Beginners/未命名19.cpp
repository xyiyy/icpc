# include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	if(N>10)return 0;
	int a[N][N]; 
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>a[i][j];
		}
	}
	int sum=0;
	for(int i=0;i<N;i++)
	{
		sum+=a[i][i];
		sum+=a[i][N-1-i];
	}
	if(N%2==1)
	{
		sum=sum-a[N/2][N/2];
	}
	cout<<sum;
	return 0;
}

