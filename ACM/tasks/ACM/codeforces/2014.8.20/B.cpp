#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define X first
#define Y second
#define MAX_V 100
#define maxn 100000+5
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
int cal(ll x)
{
	int ans=0;
	while(x>0)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
ll Pow(int x,int a)
{
	ll ans=1;
	while(a--)
	{
		ans*=x;
	}
	return ans;
}
int main()
{
	ll a,b,c;
	vector<int>v;
	while(cin>>a>>b>>c)
	{	
		int num=0;
		for(int i=1;i<82;++i)
		{
			ll L=b*Pow(i,a)+c;
			if(L<1000000000 && L>0 && cal(L)==i){
				v.push_back(L);//s(x)
				num++;
			}
		}
		if(num==0)
		{
			cout<<0<<endl;
			return 0;
		}
		cout<<num<<endl;
		sort(v.begin(),v.end());
		cout<<v[0];
		for(int i=1;i<v.size();++i)
		cout<<" "<<v[i];
		cout<<endl;
	}
	
	
	
	
	
	return 0;
}

