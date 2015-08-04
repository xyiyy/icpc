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
int a[100];
int vis[100];
bool can[9][9];
int ans[400000][10];
int n;
void change(int x){
    if(x==1){
        can[0][2]=can[2][0]=1;
    }else if(x==3){
        can[0][6]=can[6][0]=1;
    }else if(x==5){
        can[2][8]=can[8][2]=1;
    }else if(x==7){
        can[6][8]=can[8][6]=1;
    }else if(x==4){
        can[0][8]=can[8][0]=1;
        can[1][7]=can[7][1]=1;
        can[2][6]=can[6][2]=1;
        can[3][5]=can[5][3]=1;
    }
}
void nochange(int x){
    if(x==1){
        can[0][2]=can[2][0]=0;
    }else if(x==3){
        can[0][6]=can[6][0]=0;
    }else if(x==5){
        can[2][8]=can[8][2]=0;
    }else if(x==7){
        can[6][8]=can[8][6]=0;
    }else if(x==4){
        can[0][8]=can[8][0]=0;
        can[1][7]=can[7][1]=0;
        can[2][6]=can[6][2]=0;
        can[3][5]=can[5][3]=0;
    }
}
bool dfs(int x){
    if(x==n)return 1;
    bool ret=0;
    change(a[x]);
    if(can[a[x]][a[x-1]])ret=dfs(x+1);
    nochange(a[x]);
    return ret;
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(abs(i-j)==1||abs(i-j)==3)can[i][j]=1;
            else if(abs(i-j)==5)can[i][j]=1;
            else if(abs(i-j)==7)can[i][j]=1;
            else if(abs(i-j)==4&&(i!=2&&j!=2))can[i][j]=1;
            else if(abs(i-j)==2&&min(i,j)%3!=0)can[i][j]=1;
        }
    }
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
        }
        sort(a,a+n);
        int tot=0;
        do{
            change(a[0]);
            if(dfs(1))
            {
                for(int i=0;i<n;i++)
                {
                    ans[tot][i]=a[i]+1;
                }
                tot++;
                //for(int i=0;i<n;i++){
                //    if(i)printf(" ");
                //    printf("%d",a[i]+1);
               // }
               // printf("\n");
            }
            nochange(a[0]);
        }while(next_permutation(a,a+n));

        printf("%d\n",tot);
        for(int i=0;i<tot;i++){
            for(int j=0;j<n;j++){
                if(j)printf(" ");
                printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
	return 0;
}



