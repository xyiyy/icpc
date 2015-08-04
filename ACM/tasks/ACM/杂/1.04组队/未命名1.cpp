#include<iostream>
#include<iomanip>
using namespace std;

#define ll long long

ll dp[1000][1000];

ll C(int m, int n)
{
	if(m<1000&&n<1000&&dp[m][n]) return dp[m][n];
	if(m==n||n==0)return 1;
	if(n==1) return m;
	ll ret = C(m-1,n-1)*m/n;
	if(m<1000&&n<1000)dp[m][n]=ret;
	return ret;
}

int main()
{
	 int n,k;
	 while((scanf("%d%d",&n,&k)!=EOF))
	 {
	 	cout<<C(n+k-1,n-1)<<endl;
	 	
	 	/*
	 	double x=1.0;

	 	for(int i=1;i<=n+k-1;i++)
	 	{
	 		if(i<=n-1)x/=double(i);
	 		if(i>=k+1) x*=i;
	 		
	 	}
	 	cout<<fixed<<setprecision(0)<<x<<endl;
	 	*/
	 }
	 return 0;
}
	 		
	 		
	 		
	 		
	 		
