#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	double a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		double ans=(c-a)*(c-a)+(d-b)*(d-b);
		ans=sqrt(ans);
		cout<<fixed <<setprecision(2)<<ans<<endl;
	}
	return 0;
}
		 
