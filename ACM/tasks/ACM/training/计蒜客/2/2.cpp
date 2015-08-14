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
int a[10]={6,2,5,5,4,5,6,3,7,6};
int b[10010];
int c[110];
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
vector<int>G[110];
int main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<3000;i++){
        int tmp = i;
        int num = 0;
        for(int j=0;j<4;j++){
            num += a[tmp%10];
            tmp /=10;
        }
        b[i]=num;
    }
    for(int i=0;i<40;i++){
        int tmp = i;
        int num = 0;
        for(int j=0;j<2;j++){
            num +=a[tmp%10];
            tmp /=10;
        }
        c[i] = num;
    }
    for(int i=0;i<3000;i++){
        if((i%400==0)||(i%4==0&&i%100!=0))day[1]=29;
        else day[1]=28;
        for(int j=1;j<=12;j++){
            for(int k=1;k<=day[j-1];k++){
                G[b[i]+c[j]+c[k]].PB(i*10000+j*100+k);
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        for(int i=0;i<str.length();i++)str[i] = str[i]-'0';
        int n;
        cin>>n;
        int y = str[0]*1000+str[1]*100+str[2]*10+str[3];
        int m = str[4]*10+str[5];
        int d = str[6]*10+str[7];
        int ans = -1;
        int fuc = y*10000+m*100+d;
        //cout<<G[n].size()<<endl;
        for(int i=0;i<G[n].size();i++){
            if(G[n][i]>=fuc){
                ans= G[n][i];
                break;
            }
        }
        if(ans==-1){
            cout<<ans<<endl;
            continue;
        }else{
            //cout<<ans<<endl;
            int tot =0;
            for(int i=0;i<y;i++){
                if((i%400==0)||(i%4==0&&i%100!=0))tot-=366;
                else tot-=365;
            }
            if((y%400==0)||(y%4==0&&y%100!=0))day[1]=29;
            else day[1]=28;
            for(int i=0;i<m-1;i++){
                tot -= day[i];
            }
            tot -= d;
            y = ans/10000;
            m = (ans%10000)/100;
            d = ans%100;
            for(int i=0;i<y;i++){
                if((i%400==0)||(i%4==0&&i%100!=0))tot+=366;
                else tot+=365;
            }
            if((y%400==0)||(y%4==0&&y%100!=0))day[1]=29;
            else day[1]=28;
            for(int i=0;i<m-1;i++){
                tot += day[i];
            }
            tot+=d;
            cout<<tot<<endl;
        }
    }
    return 0;
}
