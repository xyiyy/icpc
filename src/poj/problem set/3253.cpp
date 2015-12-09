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
int a[20010];

void swap1(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        long long num = 0;
        int j;
        int temp, temp2;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
            }
            for (j = i + 2; j < n; j++) {
                if (a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    temp2 = a[i + 1];
                    a[i + 1] = temp;
                    a[j] = temp2;
                    //swap1(a+mm,a+j);
                    //swap1(a+nn,a+j);
                }
                else if (a[j] < a[i + 1]) {
                    temp = a[i + 1];
                    a[i + 1] = a[j];
                    a[j] = temp;
                    //	swap1(a+nn,a+j);
                }
            }
            num += a[i] + a[i + 1];
            a[i + 1] = a[i] + a[i + 1];
        }
        //	for(int i=0;i<n;i++)cout<<a[i]<<endl;
        cout << num << endl;
    }


    return 0;
}

