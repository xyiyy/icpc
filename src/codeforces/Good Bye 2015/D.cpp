//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
char a[5010];
ll dp[5010][5010];
ll sum[5010][5010];
const ll MOD = 1000000007;
ll add(ll x,ll y){
    x += y;
    while(x>=MOD)x-=MOD;
    return x;
}
int n,k;
const int MAXN = 10010;
int Rank[MAXN],tmp[MAXN],height[MAXN],sa[MAXN];
bool cmp(int i,int j){
	if(Rank[i]!=Rank[j])return Rank[i]<Rank[j];
	else{
		int ri = i+k <= n ? Rank[i+k] : -1;
		int rj = j+k <= n ? Rank[j+k] : -1;
		return ri < rj;
	}
}
void build(int len,char *s){
	n=len;
	for(int i=0;i<=n;i++)sa[i]=i,Rank[i]= i<n ? s[i] : -1;
	for(k=1;k<=n;k<<=1){
		sort(sa,sa+n+1,cmp);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++)tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i]) ? 1 : 0);
		for(int i=0;i<=n;i++)Rank[i]=tmp[i];
	}
}
void calheight(int len,char *s){
	n=len;
	for(int i=0;i<=n;i++)Rank[sa[i]]=i;
	int h=0;
	height[0]=0;
	for(int i=0;i<=n;i++){
		int j=sa[Rank[i]-1];
		if(h>0)h--;
		for(;j+h<n&&i+h<n;h++){
			if(s[i+h]!=s[j+h])break;
		}
		height[Rank[i]-1]=h;
	}
}
int dp2[5010][5010];
int getmin(int l,int r){
    int k = log2(double(r-l+1));
    return min(dp2[l][k],dp2[r-(1<<k)+1][k]);
}


int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    //int n;
    while(cin>>n){
        rep2(i,1,n)cin>>a[i];
        build(n,a+1);
        calheight(n,a+1);
        //for(int i=0;i<)
        //rep2(i,0,n)cout << Rank[i] << endl;
        rep2(i,1,n-1)dp2[i][0] = height[i];
        for(int j = 1;(1<<j)<n;j++){
            int len = (1<<j)-1;
            for(int i=0;i+len<n;i++){
                int p = (1<<(j-1));
                dp2[i][j] = min(dp2[i][j-1],dp2[i+p][j-1]);
            }
        }
        sum[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(a[j]=='0')dp[j][i] = 0;
                else{
                    int last = j-1;
                    int num = i - j + 1;
                    dp[j][i] = 0;
                    if(num <= last){
                        int l = Rank[j - num-1];
                        int r = Rank[j - 1];
                  //      cout << l << " " << r << " "<<getmin(l,r-1)<<endl;
                        if(l<r&&getmin(l,r-1)<num)
                        dp[j][i]=add(dp[j-num][j-1],dp[j][i]);
                        ll temp = sum[j-1][j-1] - sum[j - num ][j - 1];
                        temp = (temp+MOD)%MOD;
                        dp[j][i] = add(dp[j][i],temp);
                    }else {
                        dp[j][i] = add(dp[j][i],sum[j-1][j-1]);
                    }

                    //dp[][]
                }
             //   cout<< dp[j][i] << " ";
            }
           // if(i==1)dp[1][1] = 1;
         //   cout << endl;
            for(int j=1;j<=i;j++)sum[j][i] = add(sum[j-1][i],dp[j][i]);
        }
       /* for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)cout << dp[j][i]<<" ";
            cout << endl;
        }*/
        ll ans = 0;
        rep2(i,0,n)ans = add(ans,dp[i][n]);
        cout << ans << endl;
    }
    return 0;
}

