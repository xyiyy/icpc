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
double x[1010],y[1010],w[1010];
double z[1010];
double m[1010];
int p[1010];
bool cmp(int i,int j){
    if(x[i]+y[i]==x[j]+y[j])return x[i]<x[j];
    return x[i]+y[i]<x[j]+y[j];
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i]>>w[i];
        }
        for(int i=0;i<n;i++){
            m[i]=y[i]*y[i];
            z[i]=w[i]-m[i];
            p[i]=i;
        }
        sort(p,p+n,cmp);
        int l = 1<<n;
        double lastx;
        double maxx=0;
        for(int i=1;i<l;i++){
            int temp= i;
            lastx=1001;
            int c=0;
            double nowx;
            double rx;
            while(temp){
                double ans=0;
                if(temp&1){
                    nowx=x[p[n-1-c]]-y[p[n-1-c]];
                    rx = x[p[n-1-c]]+y[p[n-1-c]];
                    if(rx<=lastx){
                        ans+=z[p[n-1-c]];
                    }
                    else if(nowx<lastx){
                        ans+=w[p[n-1-c]]-(lastx-nowx)*(rx-lastx)/2.0-(lastx-nowx)*(y[p[n-1-c]]-(rx-lastx))/2.0;
                    }else{
                        ans+=w[p[n-1-c]];
                    }
                    lastx=min(nowx,lastx);
                    maxx = max(ans,maxx);
                }
                c++;
                temp>>=1;
            }
        }
        cout<<"Case #"<<cas++<<": ";
        cout<<fixed<<setprecision(2)<<maxx<<endl;



    }
	return 0;
}



