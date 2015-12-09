#include <iostream>
#include <cmath>
using namespace std;
const double PI= 3.141592653589;
double x[10010],y[10010];
double dis(double a,double b,double c,double d)
{
	return sqrt((a-b)*(a-b)+(c-d)*(c-d)); 
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int cas=1;
	freopen("1703.in","r",stdin);
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		x[n]=x[0];
		y[n]=y[0];
		double a,b,c;
		double xx,yy;
		cin>>xx>>yy;
		double ans=0;
		double temp;
		for(int i=0;i<n;i++)
		{
			//if()
			a=dis(x[i],xx,y[i],yy);
			b=dis(x[i+1],xx,y[i+1],yy);
			c=dis(x[i],x[i+1],y[i],y[i+1]);
			temp=acos((a*a+b*b-c*c)/(2*a*b));
			//if(temp<1e-12)temp+=PI;
			ans+=temp;
		}
		cout<<"Case "<<cas++<<":"<<endl;
		ans=fabs(ans);
		cout<<ans<<endl;
		if(fabs(ans-2*PI)<=1e-4)cout<<"Yes!"<<endl;
		else cout<<"No!"<<endl;
	}
	return 0;
}
		
		
