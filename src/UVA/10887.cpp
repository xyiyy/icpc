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
typedef unsigned long long ull;
const int MAXN = 2250010;
int num,head[MAXN],Next[MAXN];
int Hash(char *ss){
    int seed = 131;
    int sum = 0;
    int n = strlen(ss);
    for(int i=0;i<n;i++){
        sum = sum*seed+ss[i];
    }
    return (sum&0x7FFFFFFF)%MAXN;
}
char hash_str[MAXN][25];
void Insert(int _id){
    int h = Hash(hash_str[_id]);
    int u = head[h];
    while(u){
        if(!strcmp(hash_str[_id],hash_str[u]))return;
        u = Next[u];
    }
    Next[_id]=head[h];
    head[h]=_id;
    num++;
}
//const ull B = 31;
//ull gao[110];
//ull Hash1[2100];
//ull Hash2[2100];
char s[2100][15],str[2100][15];
//typedef pair<unsigned long long,unsigned long long>PUU;
//vector<pair<ull,PUU> > vec;
int main()
{
   // ios::sync_with_stdio(false);
    //gao[0]=1;
    //for(int i=1;i<110;i++)gao[i]=gao[i-1]*B;
    //for(int i=0;i<31;i++)cout<<gao[i]<<endl;
    int t;
    int cas =1;
    scanf("%d",&t);
    //cin>>t;
    while(t--){
        int n,m;
        num = 1;
        scanf("%d%d",&n,&m);
       // cin>>n>>m;
        getchar();
        CLR(head,0);
        //vec.clear();
        for(int i=0;i<n;i++){
            gets(str[i]);
            //getline(cin,str[i],'\n');
            //while(str[i].length()==0)getline(cin,str[i],'\n');
        }
        for(int i=0;i<m;i++){
            gets(s[i]);
           // getline(cin,s[i],'\n');
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sprintf(hash_str[num],"%s%s",str[i],s[j]);
                //hash_str[num] = str[i] + s[j];
                Insert(num);
            }
        }
        printf("Case %d: %d\n",cas++,num-1);
        //cout<< num<<endl;
        //cout<<"Case "<<cas++<<": "<<num-1<<endl;;
        /*for(int i=0;i<n;i++){
            ull ah=0;
            for(int j=0;j<str[i].length();j++){
                ah=ah*B+str[i][j];
            }
            Hash1[i]=ah;
        }
        for(int i=0;i<m;i++){
            ull ah = 0;
            for(int j=0;j<s[i].length();j++){
                ah=ah*B+s[i][j];
            }
            Hash2[i]=ah;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.PB(MP(Hash1[i]*gao[s[j].length()]+Hash2[j],MP(Hash1[i]*Hash2[j],Hash1[i])));
            }
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        cout<<"Case "<<cas++<<": "<<vec.size()<<endl;;*/
    }
    return 0;
}
