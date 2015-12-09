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
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
string str[10] = {"Áã", "Ò¼", "·¡", "Èþ", "ËÁ", "Îé", "Â½", "Æâ", "°Æ", "¾Á"};
string str1[10] = {"ÍòÒÚ", "ÒÚ", "Íò", "Çª", "°Û", "Ê°", "Ôª", "½Ç", "·Ö"};

int main() {
    ios::sync_with_stdio(false);
    int k = 1, n, m, flag, id;
    int a[4];
    while (cin >> n) {
        flag = 0;
        cout << "Case " << k++ << ": ";
        if (n < 0) {
            n = abs(n);
            cout << "¸º";
        }
        if (n > 1e8) {
            m = n / 1e8;
            cout << str[m] << str1[1];
            flag1 = 1;
        }
        if (n > 1e4) {
            m = n / 1e4;
            m = m % 10000;
            for (int i = 3; i >= 0; i--) {
                a[i] = m % 10;
                m /= 10;
            }
            if (flag1) {
                cout << str[a[0]];
                if (a[0]) {
                    cout << str1[3];
                    cout << str[a[1]];
                    if (a[1] != 0) {
                        cout << str1[4];
                        cout << str[a[2]];
                        if (a[2]) {
                            cout << str1[5];
                            cout << str[a[3]];
                        }
                        else {
                            if (a[3]) {
                                cout << str[a[3]];
                            }
                        }

                    }
                    else {
                        for (id = 1; a[id] == 0; id++) { ;
                        }
                        if (id == 2) {
                            cout << str[a[2]];
                            cout << str1[5];
                            if (a[3]) {
                                cout << str[a[3]];
                            }
                        }
                        if (id == 3) {
                            cout << str[a[3]];
                        }

                    }
                    else
                    {
                        for (id = 0; a[id] == 0; id++) { ;
                        }
                        if (id == 1) {
                            cout << str[a[1]];
                            if (a[1]) {
                                cout << str1[4];
                            }
                        }
                        else if (id == 2) {
                            cout << str[a[2]];
                            if (a[2]) {
                                cout << str1[5];
                            }
                        }
                        else if (id == 3) {
                            cout << str[a[3]];
                        }
                    }
                }
                else {
                }
                cout << str1[2]


                cout << endl;
            }

            return 0;
        }

