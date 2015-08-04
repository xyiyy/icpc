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
class ChessFloor{
	public:
		int minimumChanges(vector <string> floor){
			int n = floor.size();
			int ans = INF;
			int m = floor[0].size();
			for(char i='a';i<='z';i++){
				for(char j='a';j<='z';j++){
					if(i==j)continue;
					int num = 0;
					for(int x=0;x<n;x++){
						for(int y =0;y<m;y++){
							if((x+y)&1){
								if(floor[x][y]!=i)num++;
							}else{
								if(floor[x][y]!=j)num++;
							}
						}
					}
					ans = min(num,ans);
				}
			}
			return ans;
		}
	};
