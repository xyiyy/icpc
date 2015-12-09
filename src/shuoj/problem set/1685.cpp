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
int sum[1000010];
int a[110];
int main()
{
	ios::sync_with_stdio(false);
    for(int i=1;i<=1000000;i++){
        int num = i;
        int j =0;
        while(num){
            a[j++]=num%10;
            num/=10;
        }
        for(int k =0;k<j;k++){
            if(a[k]==4){
                sum[i]= 1;
                break;
            }else if(k<j+1&&a[k]==3&&a[k+1]==1){
                sum[i]=1;
                break;
            }
        }
    }
    for(int i=1;i<=1000000;i++)sum[i]+=sum[i-1];
    int n,m;
    while(cin>>n>>m&&(n||m)){
        cout<<(m-n+1)-(sum[m]-sum[n-1])<<endl;
    }
	return 0;
}


