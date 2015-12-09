#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string key;
    while (cin >> key && key != "THEEND") {
        int len = key.length();
        char a[20][20], result[20][20];
        string input;
        cin >> input;
        int row = input.length() / len;
        int temp = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < row; j++) {
                a[j][i] = input[temp];
                temp++;
            }
        }
        int b[10] = {0};
        for (int i = 0; i < len; i++) {
            char temp = *min_element(key.begin(), key.end());
            b[i] = key.find(temp);
            key[b[i]] += 27;
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < row; j++) {
                result[j][b[i]] = a[j][i];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < len; j++) {
                cout << result[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}



 
