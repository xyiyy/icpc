#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
double a[510];
double b[510][510];

int main() {
    int V, E;
    int u, v;
    double va;
    double maxx, temp;
    while (cin >> V >> E) {
        maxx = 0;
        for (int i = 0; i < V; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> va;
            b[u - 1][v - 1] = va;
            b[v - 1][u - 1] = va;
        }
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (fabs(b[i][j]) > 1e-6) {
                    temp = (a[i] + a[j]) / b[i][j];
                    maxx = max(maxx, temp);
                }
            }
        }
        cout << fixed << setprecision(13) << maxx << endl;
    }
    return 0;
}
		
