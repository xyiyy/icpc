
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
char a[1000100];
char str[1000100];
bool ok(char c){
    if(c>='0'&&c<='9')return 1;
    if(c>='A'&&c<='E')return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    while(scanf("%s",str)!=EOF){
        int len = strlen(str);
        for(int i=0;i<len-2;){
            if(str[i]=='0'&&str[i+1]=='k'){
                i+=2;
                int tot = 0;
                while(i<len&&ok(str[i])){
                    a[tot++]=str[i];
                    i++;
                    if(tot==1&&a[0]=='0'){
                        break;
                    }
                }
                if(!tot)break;
                a[tot]=='\0';
                int j = 0;
                printf("0k%s",a);
                //for(;j<tot;j++)printf("%c",a[j]);
                printf("\n");
            }else i++;
        }
    }
    return 0;
}
