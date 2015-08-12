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
char a[10010];
char b[10010];
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    ios::sync_with_stdio(false);
    int T,N;
    cin>>T;
    int cas=1;
    int nl,nr;
    int mon,day,d;
    int l,r;
    int ans;
    int flag;
    while(T--)
    {
        cout<<"Case "<<cas++<<":"<<endl;
        cin>>N;
        l=1;r=365;
        flag=0;
        for(int i=0;i<N;i++)
        {
            cin>>a>>b;
            mon=(a[0]-'0')*10+(a[1]-'0');
            day=(a[2]-'0')*10+(a[3]-'0');
            d=0;
            for(int i=1;i<mon;i++)
            {
                d+=m[i];
            }
            d+=day;
        //  cout<<b<<endl;
            if(b[0]=='A')
            {
                nl=d+1;
                l=max(l,nl);
            }
            else
            {
                nr=d-1;
                r=min(r,nr);
            }
            if(r-l<0)flag=1;
        }
        if(flag)cout<<"Impossible"<<endl;
        else if(r-l==0)
        {
            int i;
            for(i=1;l>m[i];i++)
            {
                l-=m[i];
            }
            if(i<10)cout<<"0"<<i;
            else cout<<i;
            if(l<10)cout<<"0"<<l;
            else cout<<l;
            cout<<endl;
        }
        else cout<<r-l+1<<endl;
    }
             
    return 0;
}
