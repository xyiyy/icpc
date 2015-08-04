
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
struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};
bool operator <(const Point &a,const Point &b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
Point cao[210];
Point tu[110];
Point operator + (Point A,Point B){
    return Point(A.x+B.x,A.y+B.y);
}
Point operator -(Point A,Point B){
    return Point(A.x-B.x,A.y-B.y);
}
int Cross(Point A,Point B){
    return A.x*B.y-A.y*B.x;
}
int ConvexHull(Point *p,int n,Point *ch){
    sort(p,p+n);
    int m =0 ;
    for(int i=0;i<n;i++){
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    int k = m;
    for(int i= n -2;i>=0;i--){
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    if(n>1)m--;
    return m;
}
Point fff[110];

int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        int n,m,p,g;
        cin>>n>>m>>g>>p;
        for(int i=0;i<n+m;i++){
            cin>>cao[i].x>>cao[i].y;
        }
        int ans = g*m;
        int num = (1<<n);
        for(int i=0;i<num;i++){
            int tmp = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))tmp++;
            }
            if(tmp<3)continue;
                int hnum=0;
                for(int j=0;j<n;j++){
                    if(i&(1<<j)){
                        fff[hnum++]=cao[j];
                    }
                }
                int tnum= ConvexHull(fff,hnum,tu);
                bool flag=0;
                int neednum=0;
                for(int j=0;j<m;j++){
                    flag=0;
                    for(int k=0;k<tnum;k++){
                        //cout<<Cross(fff[(k+1)%tnum]-fff[k],cao[j+n]-fff[k])<<endl;
                        if(Cross(fff[(k+1)%tnum]-fff[k],cao[j+n]-fff[k])<=0)flag=1;
                    }
                    if(flag)neednum++;
                }
                cout<<tnum<<"  "<<neednum<<endl;
                //if(tnum==6)cout<<"ok  "<<neednum<<endl;
                ans= min(ans,p*tnum+(neednum)*g);
            //}
        }
        cout<<"Case #"<<cas++<<": "<<ans<<endl;

    }
	return 0;
}


