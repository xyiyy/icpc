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
string str;
int dp[100010];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        cin>>str;
        int len= str.length();
        int s=0;
        int ans=0;
        int f=0;
        for(int i=0;i<len;i++){
            if(str[i]=='0')f++;
        }
        /*int sum=0;
        int fuc=f;
        for(int i=len-1;i>=0;i--){
            if(str[i]=='1')sum+=fuc;
            else fuc--;
        }
        dp[f+1]=0;
        int gao=f;
        int tmp=0;
        for(int i=len-1;i>=0;i--){
            if(str[i]=='1'){
                tmp++;
            }else{
                dp[gao]=tmp;
                gao--;
            }
        }
        //cout<<sum<<endl;
        ans=sum*x;
        fuc=f;
        int tot=len-fuc;
        int num=0;
        s=1;
        for(int i=len-1;i>=0;i--){
            if(s==fuc)break;
            if(str[i]=='1'){
                num++;
                sum-=fuc-s+1+dp[s]-num;
                //cout<<sum<<endl;
                s++;
                ans=min(num*y+sum*x,ans);

            }else{
                fuc--;
            }
        }
        //for()*/

        dp[f+1]=0;
        int gao=f;
        int tmp=0;
        for(int i=len-1;i>=0;i--){
            if(str[i]=='1'){
                tmp++;
            }else{
                dp[gao]=tmp;
                gao--;
            }
        }
        int num=0;
        int i=len-1;
        while(str[i]=='0'){
            i--;f--;
        }
        for(;i>=0;i--){
            if(s==f)break;
            if(str[i]=='1'){
                if(y<=(f-s)*x){
                    ans+=y;
                    s++;
                    num++;
                }else{
                    ans+=(dp[f]-num)*x;
                    f--;
                }
               // cout<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}


