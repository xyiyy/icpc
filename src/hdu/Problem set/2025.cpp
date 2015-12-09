#include <iostream>
#include <string>

using namespace std;

int main() {
    int i;
    string s;
    while (cin >> s) {
        char max = s[0];
        for (i = 0; i < s.size(); i++) {
            if (max < s[i])
                max = s[i];
        }
        for (i = 0; i < s.size(); i++) {
            cout << s[i];
            if (max == s[i])
                cout << "(max)";
        }
        cout << endl;
    }
    return 0;
}
