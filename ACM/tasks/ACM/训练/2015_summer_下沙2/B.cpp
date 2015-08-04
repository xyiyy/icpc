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
bool check(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return 1;
    return 0;
}
int a[200010];
int b[200010];
int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin>>str;
    int len = str.length();
    for(int i=0;i<len;i++){
        if(str[i]>='A'&&str[i]<='Z')str[i]=str[i]-'A'+'a';
    }
    a[0]=0;
    for(int i=0;i<len;i++){
        a[i+1]=a[i];
        if(check(str[i]))a[i+1]++;
        else a[i+1]-=2;
    }
    b[len+1]=INF;
    for(int i=len;i>=0;i--)b[i]=min(b[i+1],a[i]);
    int ans = 0;
    int sum = 0;
    for(int i=0;i<len;i++){
        int r=len+1,l=i;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(b[mid]<=a[i]){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(ans<l-i){
            ans=l-i;
            sum=1;
        }else if(ans==l-i){
            sum++;
        }
    }
    if(!ans)cout<<"No solution"<<endl;
    else cout<<ans<<" "<<sum<<endl;



    return 0;
}
