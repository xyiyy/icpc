#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

int main() {
    char a[1000];
    while (cin.getline(a, 1000)) {
        int len = strlen(a);
        for (int i = 0; i < len; i++) {
            a[i] -= 7;
        }
        cout << a << endl;
        memset(a, '\0', len);
    }
    return 0;
}
