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
//#include <strstream>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define IT iterator
#define CLR(A,X) memset(A,X,sizeof(A))
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
char a[110];
map<int ,int > *m1,*m2;
//set<int>::IT *it;
int f1(int x)
{
	if(m1->count(x))
	{
		return (*m1)[x]=f1((*m1)[x]);
	}
	else 
	{
    	m1->insert(MP(x,x-1));
        m2->insert(MP(x,x+1));
    }
    return x;
}
int f2(int x)
{
	if(m2->count(x))
	{
		return (*m2)[x]=f2((*m2)[x]);
	}
	else 
	{
    	m1->insert(MP(x,x-1));
        m2->insert(MP(x,x+1));
    }
    return x;
}
int main()
{
//  ios::sync_with_stdio(false);
    int T,N;
    int n,siz;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        cin>>N;
        map<int ,int >ml,mr;
        m1=&ml;m2=&mr;
        printf("Case %d:\n",cas++);
        while(N--)
        {
            scanf("%s%d",&a,&n);
           // siz=n;
          //  siz=s.size();
            if(a[0]=='F')
            {  
                siz=f1(n);
            }
            else
            {
               siz=f2(n);
            }
            printf("%d\n",siz);
        }
    }
         
    return 0;
}
