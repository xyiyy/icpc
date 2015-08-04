//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
#define MAXN 100010
char str[MAXN],s[MAXN];//MAXN至少要开到原字符串的两倍
int p[MAXN];//p中的最大值-1就是最长回文子串的长度
int n;
void Manacher(){
	n=strlen(s);
	str[0]='$';
	str[1]='#';
	for(int i=0;i<n;i++)str[2*i+2]=s[i],str[2*i+3]='#';
	n=n*2+2;
	str[n]=0;
	int mx=0,id;
	for(int i=1;i<n;i++){
		if(mx>i)p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		for(;str[i+p[i]]==str[i-p[i]];p[i]++);
		if(p[i]+i>mx)mx=p[i]+i,id=i;
	}
}
vector<int>v1,v2;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        if(strlen(s)<3){
            cout<<"No"<<endl;
            continue;
        }
    v1.clear();v2.clear();
        Manacher();
        rep(i,n)p[i]--;
        //rep(i,n)cout<<p[i]<<endl;
        rep2(i,2,n-2){
            if(p[i]+1==i)v1.pb(i+p[i]+1);
        }
        rep2(i,2,n-2){
            if(p[i]+i==n-1)v2.pb(i-p[i]-1);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        reverse(v2.begin(),v2.end());
        int len = strlen(s);
        int s1 = v1.size();
        int s2 = v2.size();
        //rep(i,s1)cout<<v1[i]<<" ";
        //cout<<endl;
        //rep(i,s2)cout<<v2[i]<<" ";
        //cout<<endl;
        int f = 0;
        int x,y;
        for(int i=0;i<s1;i++){
            x = v1[i];
            for(int j=0;j<s2;j++){
                y = v2[j];
                if(y<x)break;
                if((y-x+1)%2==0)continue;
                int tmp = (x+y)>>1;
                if(p[tmp]+tmp>=y)f=1;
                if(f)break;
            }
            if(f)break;
        }
        if(f)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}

