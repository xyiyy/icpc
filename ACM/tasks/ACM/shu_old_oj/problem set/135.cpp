#include <iostream>
#include <sstream>
#include <strstream> 
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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
double a[30];
const int N=10010;
char b[N];
double al[30],am[30],ar[30];
int main()
{
	ios::sync_with_stdio(false);
	double l,r,mid;
	double fl,fm,fr;
	int i,k=1;
	while(cin.getline(b,N,'\n'))
	{
		istrstream ss(b,N);
		i=0;
		while(ss>>a[i])
		{
			i++;
		}
	//	cout<<i<<endl;
		l=0;r=1.0;
		while(1)
		{
			mid=(l+r)/2;
			fl=fm=fr=0;
			ar[i-1]=al[i-1]=am[i-1]=1.0;
			for(int j=i-2;j>=0;j--)
			{
				ar[i]=ar[i+1]*r;
				am[i]=am[i+1]*mid;
				al[i]=al[i+1]*l;
			}
			fl=fm=fr=0;
			for(int j=i-1;j>=0;j--)
			{
				fl+=a[j]*al[j];
				fr+=ar[j]*a[j]; 
				fm+=am[j]*a[j];
			}
			if(fm<1e-8&&fm>-(1e-8))
			{
				l=mid;
				break;
			}
			else if(fl<1e-8&&fl>-(1e-8))
			{
				break;
			}
			else if(fr<1e-8&&fr>-(1e-8))
			{
				l=r;
				break;
			}
			else if(fl*fm<0)
			{
				r=mid;
			}
			else if(fr*fm<0)
			{
				l=mid;
			}
			
		}
		cout<<"Case "<<k++<<": "<<l<<endl;
		CLR(b,'\0');
		CLR(a,0);
	}
	return 0;
}

