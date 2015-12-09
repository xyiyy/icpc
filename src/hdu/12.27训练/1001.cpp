#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iterator>

using namespace std;
int const maxn = 500010;

char ch[maxn][33];
int tab[maxn];

bool mysort(int n, int n2) {
    return strcmp(ch[n], ch[n2]) < 0;
}

bool isin(int n1, int n2) {
    int n = strlen(ch[n1]);
    for (int i = 0; i < n; i++)
        if (ch[n1][i] != ch[n2][i])return 0;
    return 1;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int c = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", ch[i]);
            tab[i] = i;
        }
        sort(tab, tab + n, mysort);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isin(tab[i], tab[j]))
                    ++c;
                else break;
                if (c > 11519) {
                    c %= 11519;
                }
            }
        }
        printf("%d\n", c);
    }

    return 0;


}

