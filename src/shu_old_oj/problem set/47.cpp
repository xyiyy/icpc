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
const int N=100010;
char a[N];
int b[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	//cin.getline(a,N,'\n');
	//istrstream s(a,N);
	//s>>n;
	int k=1;
	CLR(a,0);
//	while(n--)
//	{
		CLR(a,0);
		CLR(b,0);
		int i;
		while(cin>>i)
		{
			for(int j=0;j<i;j++)
			{
				cin>>b[j];
			}
		
		cout<<"Case "<<k++<<":"<<endl;
		if(i<4)
		{
			cout<<"No maximal and minimal!"<<endl;
		}
		else
		{
			b[i]=b[0];i++;
			b[i]=b[1];i++;
			b[i]=b[2];i++;
			int maxx=-30010,minn=30010;
			int idmax=0,idmin=0;
			for(int j=0;j<i-3;j++)
			{
				if(b[j]+b[j+1]+b[j+2]+b[j+3]>maxx)
				{
					idmax=j;
					maxx=b[j]+b[j+1]+b[j+2]+b[j+3];
				}
				if(b[j]+b[j+1]+b[j+2]+b[j+3]<minn)
				{
					idmin=j;
					minn=b[j]+b[j+1]+b[j+2]+b[j+3];
				}
			}
			cout<<"Maximum="<<maxx<<",minimum="<<minn<<",MaxIndex="<<idmax+1<<",minIndex="<<idmin+1<<endl;
		}
	}

	return 0;
}


