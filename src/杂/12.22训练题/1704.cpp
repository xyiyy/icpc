#include<iostream>

using namespace std;
int a[100][100], vis[100][100];
int num;

void dfs(int x, int y, int n1, int &size) {
    if (x == y || x < 0 || y < 0 || x == n1 || y == n1 || a[x][y] == 0 || vis[x][y] == 1)return;
    vis[x][y] = 1;
    size++;
    dfs(x - 1, y, n1, size);
    dfs(x, y + 1, n1, size);
    dfs(x, y - 1, n1, size);
    dfs(x + 1, y, n1, size);
}

int main() {
    int n1, e;
    while (cin >> n1 >> e) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                a[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        num = 0;

        int m[e], n[e];
        int x1, x, y1, y;
        for (int i = 0; i < e; i++) {
            cin >> x1 >> y1;
            x = x1 - 1;
            y = y1 - 1;
            if (x > y) {
                int temp;
                temp = x;
                x = y;
                y = temp;
            }
            m[i] = x;
            n[i] = y;
            a[x][y] = 1;
        }
        for (int i = 0; i < e; i++) {
            int size = 0;
            dfs(m[i], n[i], n1, size);
            if (size != 0)
                num++;
        }
        cout << num << endl;
    }
    return 0;
}
		
			
		
