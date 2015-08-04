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
class DevuAndPlantingTrees{
public:
    int maximumTreesDevuCanGrow(vector<string>garden){
        string s1=garden[0];
        string s2=garden[1];
        int len =s1.length();
        int ans=0;
        for(int i=0;i<len;i++){
            if(!i){
                if(s1[i]==s1[i+1]&&s1[i]=='.'&&s2[i]==s2[i+1]&&s2[i]=='.'){
                   // ans++;
                    s1[i]='*';
                }
            }
            else if(i<len-1){
                if(s1[i]==s1[i+1]&&s1[i]=='.'&&s2[i]==s2[i+1]&&s2[i]=='.'&&s1[i-1]==s2[i-1]&&s1[i-1]=='.'){
                   // ans++;
                    s1[i]='*';
                }
            }else{
                if(s1[i]==s2[i]&&s1[i]=='.'&&s1[i-1]==s2[i-1]&&s1[i-1]=='.'){
                    //ans++;
                    s1[i]='*';
                }
            }
        }
        for(int i=0;i<len;i++){
            if(s1[i]=='*')ans++;
            if(s2[i]=='*')ans++;
        }
        return ans;
    }
};
int main()
{
	ios::sync_with_stdio(false);

	return 0;
}



