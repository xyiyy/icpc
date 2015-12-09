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
#define MAXN 100010
char str[MAXN],s[MAXN];
int p[MAXN];
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
	
int main()
{
	ios::sync_with_stdio(false);
	while(scanf("%s",s)!=EOF){
		Manacher();
		int ans=1;
		int id;
		int maxx=1;
		for(int i=0;i<n;i++){
			if(p[i]>maxx)id=i,maxx=p[i];
		}
		//cout<<maxx<<endl;
		p[id]--;
		for(int i=id-p[id];i<=id+p[id];i++){
			if(str[i]=='#')continue;
			printf("%c",str[i]);
		}
		puts("");
	}
	return 0;
}



