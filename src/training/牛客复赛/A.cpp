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
int Next[100010];
string p;
string str;
int minn[2000010];
void pushdown(int r){
    //if(!minn[r])return;
    minn[r<<1] = max(minn[r],minn[r<<1]);
    minn[r<<1|1] = max(minn[r],minn[r<<1|1]);
}
void update(int l,int r,int lx,int rx,int inc,int cur){
    if(l > rx || r < lx || lx > rx||lx < 0)return ;
    //cout << lx << " " << rx << endl;
    pushdown(cur);
    if(l <= lx && r >= rx){
        pushdown(cur);
        //cout << lx << " " <<rx<<endl;
        //cout << minn[cur<<1] << " " << minn[cur<<1|1]<<endl;
        minn[cur] = inc;//max(minn[cur],inc);
        return;
    }
    int mid = (lx + rx) / 2;
    update(l,r,lx,mid,inc,cur<<1);
    update(l,r,mid+1,rx,inc,cur<<1|1);
}
ll ans = 0;
void query(int l,int r,int lx,int rx,int cur){
    if(l > rx || r < lx || lx > rx || lx < 0)return;
//    min((2 * (i - j)) + 1,i)
//cout << lx << " " << rx << endl;
    pushdown(cur);
    if(lx == rx && lx >= l && lx <= r){
            //cout << lx << "                 "<<minn[cur] << endl;
        ans += minn[cur];
        return;
    }
    int mid = (lx + rx) / 2;
    query(l,r,lx,mid,cur<<1);
    query(l,r,mid+1,rx,cur<<1|1);
}
void getNext()
{
    int j,k;
    Next[0]=-1;
    j=0;
    k=-1;
    int len = p.length();
    while(j<len-1)
    {
        if(k==-1||p[j]==p[k])    //匹配的情况下,p[j]==p[k]
        {
            j++;
            k++;
            Next[j]=k;
        }
        else                   //p[j]!=p[k]
            k=Next[k];
    }
}
int KMPMatch()
{
    int i,j;
    i=0;
    j=0;
    getNext();
    int len = str.length();
    int h = (len) / 2;
    int st = 0;
    while(i < len){
        if(j==-1||str[i] == p[i]){
            i++;
            j++;
        }else break;
    }
    while(i<len)
    {
        //cout << i << endl;
        if(j==-1||str[i]==p[j])
        {
            update(i - j,min((2 * (i - j)) - 1,min(i,len-2)),0,len - 2,i - j,1);
            //update(st)
           // update(i - j + 1,min((2 * (i - j)) + 1,i), 0,len-1,i - j + 1,1);
            i++;
            j++;
           // cout << i << " " << j;


        }
        else
        {
            j=Next[j];       //消除了指针i的回溯
            st = i - j;
            //cout << i - j  <<" "<<min((2 * (i - j)) - 1,i)<<" "<<len - 2 << " " << i - j <<endl;;
            update(i - j,min((2 * (i - j)) - 1,min(i,len-2)),0,len - 2,i - j,1);
            //cout << j << "      " << st ;

        }
        //cout << endl;
    }
    //query(0,len)
    return -1;
}
class Periods {
public:
    long long getLongest(int n, string s) {
        // write code here
        str = s + "#";
        p = s + "$";
        ans = 0;
        rep(i,n*10){
            minn[i] = 0;
        }
        KMPMatch();
        query(0,n-1,0,n-1,1);
        return ans;

    }
};
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    Periods *gao = new Periods();
    while(cin>>str){
    cout << gao->getLongest(str.length(),str) << endl;
    }
    return 0;
}

