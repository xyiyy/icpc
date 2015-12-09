#include<iostream>
#include<cstring>
#include <cstdio>

using namespace std;

int main() {
    int t, cnt = 1;
    cin >> t;
    string s, k;
    for (int q = 0; q < t; q++) {
        int i = 0, num1 = 0, num2 = 0, p = 0;
        cin >> s;//getline(cin,s,'\n');
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] == 'c') {
                p = 2;
                break;
            }
        }
        for (i = 0; i < l; i++) {
            if (!(s[i] == 'f' || s[i] == 'c')) {
                p = 1;
                break;
            }
        }
        if (p != 1) {
            if (p == 0) {
                num1 = (l + 1) / 2;
            } else {
                k = "";
                for (i = 0; i < l; i++) {
                    if (s[i] == 'f') { k += s[i]; }
                    else break;
                }
                s += k;
                num2 = 0;
                l = s.length();
                for (; i < l; i++) {
                    if (s[i] == 'c') {
                        if (i + 2 < l && s[i + 1] == 'f' && s[i + 2] == 'f') {
                            num2++;
                        } else {
                            p = 1;
                        }
                    }
                }
            }
        }
        if (p == 0) cout << "Case #" << cnt++ << ": " << num1 << endl;
        else if (p == 1) cout << "Case #" << cnt++ << ": " << -1 << endl;
        else if (p == 2) cout << "Case #" << cnt++ << ": " << num2 << endl;
    }
    return 0;
}
