//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define LINF 0x3FFFFFFFFFFFFFFFLL
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<ll,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

ll h[900010];
PII num[1<<20];

int tot;
PII query(int lx,int rx,int l,int r,int cur){
    if(lx>r||rx<l)return MP(LINF,tot);
    if(l>=lx&&r<=rx)return num[cur];
    int mid = (l+r)>>1;
    return min(query(lx,rx,l,mid,cur<<1),query(lx,rx,mid+1,r,cur<<1|1));
}
int Scan() {
	int res=0,ch;
	while(ch=getchar(), ch<'0'||ch>'9');
	res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}
void Out(int a) {
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	t=Scan();
	int cas=1;
	while(t--){
        tot =0 ;
        int n = Scan();
        ll r = Scan();
        ll gao=r*n;
        for(int i=0;i<n;i++){
            h[i]=Scan();
            h[i]+=i*r;
            h[i+n]=h[i]+gao;
        }
        tot=1;
        int m =n+n/2;
        while(tot<=m)tot<<=1;
        for(int i=0;i<m;i++){
            num[i+tot]=MP(LINF-h[i],i);
        }
        for(int i=m;i<tot;i++){
            num[i+tot]=MP(LINF,i);
        }
        for(int i=tot-1;i>=0;i--){
            num[i]=min(num[i<<1],num[i<<1|1]);
        }
        ll tmp;
        pair<ll,pair<int,int> > ans = MP(LINF,MP(tot,tot));
        for(int i=0;i<n;i++){
            PII temp = query(i+1,i+n/2,0,tot-1,1);
            int x = temp.second;
            while(x>=n)x-=n;
            int y = i;
            if(x>y)swap(x,y);
            tmp=temp.first-h[i]+2*i*r;
            ans=min(ans,MP(tmp,MP(x,y)));
        }
        printf("Case #%d:\n",cas++);
        printf("%d %d\n",ans.second.first+1,ans.second.second+1);
	}
	return 0;
}


