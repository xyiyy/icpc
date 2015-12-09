#include<iostream>

using namespace std;

int main() {
    unsigned int t;
    cin >> t;
    if (t == 0 || t > 50)
        return 0;
    unsigned int a[t];
    int x = 0;
    for (int i = 0; i < t; i++) {
        cin >> a[i];
        if (a[i] > 2013 || a[i] == 0)
            return 0;
        if (a[i] == 1)
            cout << "Mission Complete!" << endl;
        else {
            if (a[i] == 2)
                cout << "Needs at least 1 ATP!" << endl;
            else {
                x = a[i] * (a[i] - 1) / 2;
                cout << "Needs at least " << x << " ATPs!" << endl;
            }
        }
    }
    return 0;
}
		
		
		
	 
