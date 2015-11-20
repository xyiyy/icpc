
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
/*const int MAXN = 400010;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[MAXN*2],wb[MAXN*2],wv[MAXN*2],ww[MAXN*2];
int c0(int *r, int a, int b) {
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k, int *r, int a, int b) {
    if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
}
void rsort(int *r, int *a, int *b, int n, int m) {
    rep(i,n) wv[i]=r[a[i]];
    rep(i,m) ww[i]=0;
    rep(i,n) ww[wv[i]]++;
    rep(i,m-1) ww[i+1]+=ww[i];
    dep(i,n-1,0) b[--ww[wv[i]]]=a[i];
}
void dc3(int *r, int *sa, int n, int m) {
    int j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    rep(i,n) if(i%3!=0) wa[tbc++]=i;
    rsort(r+2,wa,wb,tbc,m);
    rsort(r+1,wb,wa,tbc,m);
    rsort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,j=1;j<tbc;j++)
        rn[F(wb[j])]=c0(r,wb[j-1],wb[j])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else rep(i,tbc) san[rn[i]]=i;
    rep(i,tbc) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    rsort(r,wb,wa,ta,m);
    rep(i,tbc) wv[wb[i]=G(san[i])]=i;
    int i;
    for(i=j=p=0;i<ta&&j<tbc;p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
}
int ra[MAXN*2], height[MAXN*2];
void calheight(int *r,int *sa,int n) {
    int i,j,k=0;
    for(i=1;i<=n;i++) ra[sa[i]]=i;
    for(i=0;i<n;height[ra[i++]]=k)
        for(k?k--:0,j=sa[ra[i]-1];r[i+k]==r[j+k];k++);
}
//使用方法：
//str[n] = 0;
//dc3(str,sa,n+1,200);
//calheight(str,sa,n);
//sa[]: 第i大的字符串的起始位置
//ra[]: 起始位置为i的字符串的rank
//height[]：lcp(sa[i], sa[i+1])
char str1[MAXN],str2[MAXN];
int str[MAXN*2];
int sa[MAXN*2];
*/



void pre_exkmp(char x[],int m,int next[]){
    next[0] = m;
    int j = 0;
    while(j + 1 < m && x[j] == x[j+1])j++;
    next[1] = j;
    int k = 1;
    for(int i = 2;i < m;i++){
        int p = next[k] + k - 1;
        int L = next[i - k];
        if(i + L < p + 1)next[i] = L;
        else{
            j = max(0,p - i + 1);
            while(i + j < m&&x[i+j] == x[j])j++;
            next[i] = j;
            k = i;
        }
    }
}
void exkmp(char x[],int m,char y[],int n,int next[],int extend[]){
    pre_exkmp(x,m,next);
    int j = 0;
    while(j < n&&j < m&&x[j]==y[j])j++;
    extend[0] = j;
    int k = 0;
    for(int i=1;i<n;i++){
        int p = extend[k] + k - 1;
        int L = next[i - k];
        if(i+L<p+1)extend[i] = L;
        else{
            j = max(0,p-i+1);
            while(i+j<n&&j<m&&y[i+j]==x[j])j++;
            extend[i] = j;
            k = i;
        }
    }

}
const int MAXN = 100010;
int ex[MAXN];
int Next[MAXN];
char str1[MAXN],str2[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    while(scanf("%s%s",str1,str2)!=EOF){
            //cout << str1 << " "<< str2 <<endl;
        //gets(str2);
        exkmp(str2,strlen(str2),str1,strlen(str1),Next,ex);
        int ans = 0;
        int len = strlen(str1);
        rep(i,len)ans = max(ans,ex[i]);
        cout << ans << endl;
        //gets(str1);
    }
    return 0;
}
