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
int n,i;
char a[10010];
int num[2010];
int l=-1,r=0,mid=0;
/*int bi_search()
{
	l=-1;r=i;
	while(l+1!=r)
	{
		mid=(l+r)/2;
		if(num[mid]>=n)
		{
			r=mid;
		}
		if(num[mid]<n)
		{
			l=mid;
		}
	}
	return (r<i&&num[r]==n)?r:-1;
}*/

int main()
{
	ios::sync_with_stdio(false);
	int k=1;
	while(cin.getline(a,10010,'\n'))
//	while(cin>>n)
	{
		memset(num,0,sizeof(num));
	//	cin.ignore();
		istrstream ss(a,10010);
		ss>>n;
		memset(a,'\0',sizeof(a));
		cin.getline(a,10010,'\n');
		istrstream s(a,10010);
		i=0;
		while(s>>num[i])
		{
			i++;
		}
		
		l=0;r=i;
		while(l+1!=r)
		{
			mid=(l+r)/2;
			if(num[mid]<=n)
			{
				l=mid;
				if(num[mid]==n)break;
			}
			else
			
			{
				r=mid;
			}
		}
	//	l=0;r=i;
		cout<<"Case "<<k++<<": "<<n<<", "<<((l<i&&num[l]==n)?l:-1)<<endl;
		memset(a,'\0',sizeof(a)); 
	}
	
	return 0;
}

