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
int a[100100];
vector<PII>G[100100];
int gao[100100];
ll C[41][41];
int totc[41];
int b[100];
int p[100100];
bool cmp(int x,int y){
    return gao[x]>gao[y];
}
bool cmp1(int x,int y){
    return G[a[x]].size()>G[a[y]].size();
}
int main()
{
	ios::sync_with_stdio(false);
    int n;
    int x,y;
    for(int i=1;i<=100000;i++){
        int temp = i;
        //G[i].PB(MP(1,1));
        for(int j=2;j*j<=temp;j++){
            y=0;
            while(temp%j==0){
                temp/=j;
                y++;
                x++;
            }
            if(y){
                G[i].PB(MP(j,y));
            }
        }
        if(temp!=1){
            G[i].PB(MP(temp,1));
            x++;
        }
        gao[i]=x;
    }
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
            p[i]=i;
        }
        sort(a,a+n);
        n = unique(a,a+n)-a;
        int ans=0;
        if(n<1000){
            for(int i=0;i<n;i++){
                int l=a[i];
                int sz1=G[a[i]].size();
                for(int j=i;j<n;j++){
                    int r= a[j];
                    x=0,y=0;
                    int sz2=G[a[j]].size();
                    int k=0;
                    while(x<sz1&&y<sz2){
                        if(G[l][x].first==G[r][y].first){
                            b[k++]=G[l][x].second+G[r][y].second;
                            x++;y++;
                        }else if(G[l][x].first<G[r][y].first){
                            b[k++]=G[l][x].second;
                            x++;
                        }else{
                            b[k++]=G[r][y].second;
                            y++;
                        }
                    }
                    int temp=1;
                    while(x<sz1){
                        b[k++]=G[l][x].second;
                        x++;
                    }
                    while(y<sz2){
                        b[k++]=G[r][y].second;
                        y++;
                    }
                    for(int ii=0;ii<k;ii++){
                        temp*=b[ii]+1;
                    }
                    ans=max(ans,temp);

                }
            }
        }else{
            sort(p,p+n,cmp);
           // cout<<p[0]<<endl;
            for(int i=0;i<1000;i++){
                int l=a[p[i]];
                int sz1=G[l].size();
                for(int j=i;j<1000;j++){
                    int r=a[p[j]];
                    x=0,y=0;
                    int sz2=G[r].size();
                    int k=0;
                    while(x<sz1&&y<sz2){
                        if(G[l][x].first==G[r][y].first){
                            b[k++]=G[l][x].second+G[r][y].second;
                            x++;y++;
                        }else if(G[l][x].first<G[r][y].first){
                            b[k++]=G[l][x].second;
                            x++;
                        }else{
                            b[k++]=G[r][y].second;
                            y++;
                        }
                    }
                    int temp=1;
                    while(x<sz1){
                        b[k++]=G[l][x].second;
                        x++;
                    }
                    while(y<sz2){
                        b[k++]=G[r][y].second;
                        y++;
                    }
                    for(int ii=0;ii<k;ii++){
                        temp*=b[ii]+1;
                    }
                    ans=max(ans,temp);

                }
            }
        }
        for(int i=0;i<n;i++)p[i]=i;
        if(n>=1000){
            sort(p,p+n,cmp1);
            for(int i=0;i<1000;i++){
                int l=a[p[i]];
                int sz1=G[l].size();
                for(int j=i;j<1000;j++){
                    int r=a[p[j]];
                    x=0,y=0;
                    int sz2=G[r].size();
                    int k=0;
                    while(x<sz1&&y<sz2){
                        if(G[l][x].first==G[r][y].first){
                            b[k++]=G[l][x].second+G[r][y].second;
                            x++;y++;
                        }else if(G[l][x].first<G[r][y].first){
                            b[k++]=G[l][x].second;
                            x++;
                        }else{
                            b[k++]=G[r][y].second;
                            y++;
                        }
                    }
                    int temp=1;
                    while(x<sz1){
                        b[k++]=G[l][x].second;
                        x++;
                    }
                    while(y<sz2){
                        b[k++]=G[r][y].second;
                        y++;
                    }
                    for(int ii=0;ii<k;ii++){
                        temp*=b[ii]+1;
                    }
                    ans=max(ans,temp);

                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}


