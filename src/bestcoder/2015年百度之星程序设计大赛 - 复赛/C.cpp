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
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<string, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

struct node {
    int v;
    string str;

    node(int _v, string _str) {
        v = _v;
        str = _str;
    }
};

vector<node> G[110];
vector<int> last[110];
string iniG[51][51];
string tempG[51][51];
string dis[60];

/*
bool dijkstra(int s){
    dis[s]="";
    string str;
    priority_queue<PII,vector<PII>,greater<PII> >q;
    q.push(MP("",s));
    int num=0;
    while(!q.empty()){
        if(num==500000)return 0;
        q.
    }
}*/
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int cas = 1;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int u, v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                iniG[i][j] = "";
            }
            // G[i].clear();
            // last[i].clear();
        }
        string str;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> str;
            if (iniG[u][v] == "") {
                iniG[u][v] = str;
            } else if (iniG[u][v] > str) {
                iniG[u][v] = str;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //if(iniG[i][j]!=""){
                //   G[i].PB(node(v,str));
                //}
                tempG[i][j] = iniG[i][j];
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == k || j == k || i == j)continue;
                    if (tempG[i][k] == "" || tempG[k][j] == "")continue;
                    string temp = tempG[i][k] + tempG[k][j];
                    if (tempG[i][j] == "")tempG[i][j] = temp;
                    else tempG[i][j] = min(tempG[i][j], temp);
                }
            }
        }
        bool flag = 0;
        if (tempG[a][b] == "")flag = 1;
        for (int i = 0; i < n; i++) {
            if (tempG[i][a] != "" && tempG[a][i] != "") {
                for (int j = 0; j < n; j++) {
                    if (tempG[i][j] != "" && tempG[j][i] != "") {
                        string temp = tempG[a][i];
                        int num = 10;
                        string tmp = tempG[i][j] + tempG[j][i];
                        while (num--)temp += tmp;
                        if (tmp + tempG[i][b] < tempG[a][b])flag = 1;
                    }
                }
                /* string temp=tempG[a][i];
                 for(int j=50;j>=0;j--){
                     temp = temp+tempG[i][i];
                 }
                 if(temp+tempG[i][t]<tempG[a][b])flag=1;*/
            }
        }
        // for(int i=0;i<n;i++)dis[i]=".";
        cout << "Case #" << cas++ << ":" << endl;
        if (flag) {
            cout << "Tough way!" << endl;
        } else {
            cout << tempG[a][b] << endl;
        }


    }
    return 0;
}


