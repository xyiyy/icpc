#include<iostream>

using namespace std;
#define MAX 100005
int father[MAX], flag, sign[MAX];

int FindSet(int x) {
    while (x != father[x])
        x = father[x];
    return x;
}

void Union(int x, int y) {
    x = FindSet(x);
    y = FindSet(y);
    if (x != y)
        father[x] = y;
    else flag = 0; //同父节点，成环
}

int main() {
    int i, a, b;
    while (cin >> a >> b) {
        if (a == -1 && b == -1) break;
        if (a == 0 && b == 0) {
            cout << "Yes" << endl;
            continue;
        }
        for (i = 1; i < MAX; i++) {
            father[i] = i;
            sign[i] = 0;
        }
        sign[a] = sign[b] = 1;
        flag = 1;
        Union(a, b);
        while (cin >> a >> b) {
            if (a == 0 && b == 0) break;
            Union(a, b);
            sign[a] = sign[b] = 1;
        }
        int k = 0;
        for (i = 1; i < MAX; i++) {
            if (sign[i] && father[i] == i)
                k++;
            if (k > 1) flag = 0;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
