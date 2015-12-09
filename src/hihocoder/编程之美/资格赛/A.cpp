#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int cal_m(string s) {
    if (s == "January")return 1;
    else if (s == "February")return 2;
    return 3;
}

int gao(int y, int m, int d, int x) {
    int ret = 0;
    if (m * 100 + d < 229 && x)y--;
    else if (x == 0 && m * 100 + d <= 229)y--;
    return y / 4 - y / 100 + y / 400;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string s1, s2;
    int sy, sm, sd;
    int ey, em, ed;
    int cas = 1;
    while (t--) {
        cin >> s1 >> s2 >> sy;
        sm = cal_m(s1);
        int len = s2.length();
        sd = 0;
        for (int i = 0; i < len - 1; i++)
            sd = s2[i] - '0' + sd * 10;
        cin >> s1 >> s2 >> ey;
        em = cal_m(s1);
        len = s2.length();
        ed = 0;
        for (int i = 0; i < len - 1; i++)
            ed = s2[i] - '0' + ed * 10;
        int ans = gao(ey, em, ed, 1) - gao(sy, sm, sd, 0);
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
    return 0;
}
