#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define PI 3.14159

int main()
{
    int T = 0;
    cin >> T;

    double V = 0.0, D = 0.0;
    double g = 9.8;
    double theta1 = 0.0;
    double theta2 = 0.0;
    for(int i = 0; i < T; i++)
    {
        cin >> V >> D;
        double tmp = g*D/(V*V);
        // cout << "xxxxxxxxxxxx" << V << "\t" << D << "\t" << tmp << endl;
        double b = sqrt(1 + tmp);
        double ac = 0.0;
        if(1 - tmp < 1e-6 && 1 - tmp > -1e-6)
        {
            ac = 0.0;
        }
        else
        {
            ac = sqrt(1 - tmp);
        }
        theta1 = asin((b + ac)/2)*180.0/M_PI;
        theta2 = asin((b - ac)/2)*180.0/M_PI;
        // cout << "xxxxxxxxxxxx" << V << "\t" << D << "\t" << 1 - tmp << endl;

        if(theta1 > 0 && theta2 > 0)
        {
            if(theta1 > theta2)
            {
                cout << "Case #" << i + 1 << ": ";
                cout.setf(ios::fixed);
                cout.precision(7);
                cout << theta2 << endl;
                cout.unsetf(ios::fixed);
            }
            else
            {
                cout << "Case #" << i + 1 << ": ";
                cout.setf(ios::fixed);
                cout.precision(7);
                cout << theta1 << endl;
                cout.unsetf(ios::fixed);
            }
        }
        else
        {
            if(theta1 > theta2)
            {   
                cout << "Case #" << i + 1 << ": ";
                cout.setf(ios::fixed);
                cout.precision(7);
                cout << theta1 << endl;
                cout.unsetf(ios::fixed);
            }
            else
            {
                cout << "Case #" << i + 1 << ": ";
                cout.setf(ios::fixed);
                cout.precision(7);
                cout << theta2 << endl;
                cout.unsetf(ios::fixed);

            }
        }
    }
    return 0;
}
