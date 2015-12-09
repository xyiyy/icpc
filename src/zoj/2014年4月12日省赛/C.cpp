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

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
int test[40010];

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        memset(test, 0, sizeof(test));
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            scanf("%d", &test[i]);
        }
        sort(test, test + N);
        //	for(int i=0;i<N;i++)
        //		cout<<test[i];
        //		cout<<endl;
        while (test[N - 1]) {
            for (int i = N - 1; i > N - 1 - M && i >= 0; i--) {
                test[i]--;
            }
            sort(test, test + N);
            //	for(int i=0;i<N;i++)
            //	cout<<test[i];
            //	cout<<endl;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

