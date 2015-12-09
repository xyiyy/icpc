
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
string a[110];
int num[110];
int tmp [110];
int t[110][110];
int init(string str){
    char c = str[0];
    if(c>='2'&&c<='9'){
        return c-'0';
    }
    if(c=='A')return 1;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
    if(str=="1")return 1;
    if(str=="10")return 10;
    if(str=="11")return 11;
    if(str=="12")return 12;
    if(str=="13")return 13;
}
int cal(int x,int y,int i){
    if(i==0)return x+y;
    else if(i==1)return x-y;
    else if(i==2)return x*y;
    else return x/y;
}
bool check(int len){
    if(!len){
        if(tmp[0]==24)return 1;
        else return 0;
    }
    for(int i=0;i<len;i++){
        int x = tmp[i],y = tmp[i+1];
        for(int j=0;j<len+1;j++)t[len][j]=tmp[j];
        for(int j=i+1;j<len;j++)
            if(j>i)tmp[j]=tmp[j+1];
        for(int j=0;j<4;j++){
            if(j==3&&y==0)continue;
            if(j==3&&x%y!=0)continue;
            tmp[i]=cal(x,y,j);
            if(check(len-1))return 1;
        }
        for(int j=0;j<len+1;j++)tmp[j]=t[len][j];
    }
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
        for(int i=0;i<4;i++)
            num[i]=tmp[i]=init(a[i]);
        sort(tmp,tmp+4);
        bool flag = 0;
        do{
            flag|=check(3);
        }while(next_permutation(tmp,tmp+4));
        if(flag)cout<<"Y"<<endl;
        else cout<<"N"<<endl;

	}
	return 0;
}


