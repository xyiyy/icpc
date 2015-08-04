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
char a[210][10]={"h","he","li","be","b","c","n","o","f","ne",
"na","mg","al","si","p","s","cl","ar",
"k","ca","sc" ,"ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr",
"rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe",
"cs", "ba" , "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn",
"fr", "ra" , "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn",
"fl",
"lv",
"la", "ce", "pr", "nd", "pm", "sm" ,"eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
 "ac", "th", "pa", "u" ,"np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"};
char b[100010];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	bool flag=0,flag1,flag2;
	int len2;
	while(T--)
	{
		flag=true;
		flag1=0;
		CLR(b,0);
		cin>>b;
		len2=strlen(b);
		REP(i,len2)
		{
			flag2=flag1;
			flag1=flag;
			flag=0;
			for(int j=0;j<190;j++)
			{
				if(strlen(a[j])==1&&b[i]==a[j][0]&&flag1)
				{
					flag=1;
					break;
				}
				else if(strlen(a[j])==2&&b[i-1]==a[j][0]&&b[i]==a[j][1]&&flag2)
				{
					flag=1;
					break;
				}
			}
		//	if(!flag)break;
			
			
		}
		if(!flag)
		{
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}	
	return 0;
}


