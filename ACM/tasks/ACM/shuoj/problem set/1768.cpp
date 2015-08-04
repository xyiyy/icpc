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
char a[100][10];
char b;
int h[110],m[110],s[110];
int t[110];
int main()
{
    ios::sync_with_stdio(false);
    int t7,tc,c7,cc;
    int T;
    int n;
    int l7,lc;
    double x,y;
    cin>>T;
    int flag;
    int cas=1;
    while(T--)
    {
        cout<<"Case "<<cas++<<":"<<endl;
        flag=0;
        CLR(a,0);
        CLR(h,0);
        CLR(m,0);
        CLR(s,0);
        CLR(t,0);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            cin>>h[i]>>b>>m[i]>>b>>s[i];
        }
        for(int i=1;i<n;i++)
        {
            t[i]=(h[i]-h[i-1])*3600+(m[i]-m[i-1])*60+(s[i]-s[i-1]);
        }
        t[0]=0;
        c7=0;
        cc=0;
        t7=0;
        tc=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][0]=='7')
            {
                c7++;
                t7+=t[i];
            }
            else
            {
                cc++;
                tc+=t[i];
            }
        }
        cout<<t7<<" "<<tc<<" "<<c7<<" "<<cc<<" ";
        if(tc==0)flag=1;
        x=(t7*1.0)/(tc*1.0);
        y=(c7*1.0)/(cc/1.0);
        if(x>=0.5&&x<=2.0&&y>=0.5&&y<=2.0);
        else flag=1;
        if(flag)
        {
            cout<<"unhappy"<<endl;
        }
        else cout<<"happy"<<endl;
    }
             
                 
             
    return 0;
}
