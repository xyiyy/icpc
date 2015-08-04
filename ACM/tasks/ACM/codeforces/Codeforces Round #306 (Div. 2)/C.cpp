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
string str[130]={"0","8","16","24","32","40","48","56","64","72","80","88","96","104","112","120","128","136","144","152","160","168","176","184","192","200",
"208","216","224","232","240","248","256","264","272","280","288","296","304","312","320","328","336","344","352","360","368","376","384","392","400",
"408","416","424","432","440","448","456","464","472","480","488","496","504","512","520","528","536","544","552","560","568","576","584","592","600",
"608","616","624","632","640","648","656","664","672","680","688","696","704","712","720","728","736","744","752","760","768","776","784","792","800",
"808","816","824","832","840","848","856","864","872","880","888","896","904","912","920","928","936","944","952","960","968","976","984","992","1000"
};
int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int len =s.length();
	string ans;
	bool flag=0;
	for(int i=0;i<125;i++){
        int len2=str[i].length();
        int j=len2-1;
        for(int k=len-1;k>=0;k--){
            if(s[k]==str[i][j]){
                j--;
            }
            if(j<0){
                flag=1;
            }
        }
        if(flag){
            ans=str[i];
            break;
        }
	}
	if(flag){
        cout<<"YES"<<endl;
        cout<<ans<<endl;
	}
	else cout<<"NO"<<endl;

	return 0;
}



