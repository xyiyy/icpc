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
ll d[10],h[10],m[10];
int main()
{
	ios::sync_with_stdio(false);
    freopen("C-small-1-attempt0.in","r",stdin);
	freopen("c.out","w",stdout);
	int t;
	cin>>t;
	int cas=1;
	while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>d[i]>>h[i]>>m[i];
        }
        ll d1,d2,h1,h2,m2,m1;
        cout<<"Case #"<<cas++<<": ";
        if(n==1){
            d2=d1=d[0];
            m1=m[0];
            m2=m1+1;
            cout<<0<<endl;
        }else{
            d1=d[0];
            d2=d[1];
            m1=m[0];
            m2=m[1];
            if(d1<d2){
                swap(d1,d2);
                swap(m1,m2);
            }
            if(d1==d2){
                if(m1<m2)swap(m1,m2);
                if((360-d1)*m1>=(720-d1)*m2)cout<<1<<endl;
                else cout<<0<<endl;
            }else if(d1>d2){
                if(m1==m2){
                    cout<<0<<endl;
                }else if(m1<m2){
                    if((360-d2)*m2>=(720-d1)*m1)cout<<1<<endl;
                    else cout<<0<<endl;
                }else{
                    if((360-d1)*m1>=(720-d2)*m2)cout<<1<<endl;
                    else cout<<0<<endl;
                }

            }
        }
	}
	return 0;
}



