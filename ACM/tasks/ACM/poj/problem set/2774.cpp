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
struct suffix_automaton{
	string s;
	int son[MAXN][26],pre[MAXN],step[MAXN],last,total;
	void Add(int v){
		step[++total]=v;
	}
	void Extend(char ch){
		Add(step[last]+1);
		int p=last,np=total;
		for(;!son[p][ch];p=pre[p])son[p][ch]=np;
		if(!p)pre[np]=0;
		else{
			int q=son[p][ch];
			if(step[q]!=step[p]+1){
				Add(step[p]+1);
				int nq=total;
				memcpy(son[nq],son[q],sizeof(son[q]));
				pre[nq]=pre[q];
				pre[q]=pre[np]=nq;
				for(;son[p][ch]==q;p=pre[p])son[p][ch]=nq;
			}else pre[np]=q;
		}
		last=np;
	}
	void build(){
		total=last=0;
		memset(son,0,sizeof(son));
		memset(pre,0,sizeof(pre));
		memset(step,0,sizeof(step));
		for(int i=0,End=s.length();i!=End;i++)Extend(s[i]-'a');
	}
}SAM;		
string str;

	
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>SAM.s){
		cin>>str;
		SAM.build();
		int tot=0;
		int len=str.length();
		int ans=0;
		int now=1;
		while(tot<len){
			int x=str[tot]-'a';
			if(SAM.son[now][x]){
				now=SAM.son[now][x];
				ans=max(ans,SAM.step[now]);
			}
			else{
				for(;!SAM.son[now][x];now=SAM.pre[now]);
				ans=max(ans,SAM.step[now]);
			}
			tot++;
		}
		cout<<ans<<endl;
	}
	return 0;
}



