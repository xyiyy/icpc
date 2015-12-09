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

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;

struct info {
    int band;
    int price;
    int id;

    bool operator<(const info &a) const {
        if (band == a.band) {
            if (price == a.price) {
                return id < a.id;
            }
            return price < a.price;
        }
        return band < a.band;
    }

    info &operator=(const info &a) {
        band = a.band;
        price = a.price;
        id = a.id;
        return *this;
    }


} aa[10010];

int idvis[110];
int pricevis[110];

/*bool cmp(const void *a,const void *b)
{
	info *x=(info*)a;
	info* y=(info*)b;
	if(x->band==y->band)
	{
		if(x->price==y->price)
		{
			return x->id>y->id;
		}
		return x->price>y->price;
	}
	return x->band >y->band;
} 
	 */

int main() {
    ios::sync_with_stdio(false);
    int T, n, Size, Band, Price, label;
    cin >> T;
    double B, P, maxn;
    while (T--) {
        cin >> n;
        label = 0;
        for (int i = 0; i < n; i++) {
            cin >> Size;
            for (int j = 0; j < Size; j++) {
                cin >> Band >> Price;
                aa[label].id = i + 1;
                aa[label].band = Band;
                aa[label].price = Price;
                label++;
            }
        }
        /*	for(int i=0;i<label;i++)
            {
                cout<<aa[i].band<<"  "<<aa[i].price<<"   "<<aa[i].id<<"  "<<endl;
            }*/
        memset(idvis, 0, sizeof(idvis));
        //	minn=0x7fffff;
        maxn = 0;
        //qsort(aa,label,sizeof(info),cmp);
        for (int i = 1; i < label - 1; i++) {
            for (int j = 0; j < label - i; j++) {
                if (aa[j + 1] < aa[j]) {
                    info temp = aa[j + 1];
                    aa[j + 1] = aa[j];
                    aa[j] = temp;
                }
            }
            /*		for(int i=0;i<label;i++)
            {
                cout<<aa[i].band<<"  "<<aa[i].price<<"   "<<aa[i].id<<"  "<<endl;
            }*/
        }
        /*	for(int i=0;i<label;i++)
            {
                cout<<aa[i].band<<"  "<<aa[i].price<<"   "<<aa[i].id<<"  "<<endl;
            }*/
        for (int i = 0; i < label - n + 1; i++)
            //	for(int i=0;i<1/*label-n*/;i++)
        {
            B = aa[i].band;
            P = 0;
            memset(idvis, 0, sizeof(idvis));
            idvis[aa[i].id] = 1;
            memset(pricevis, 10000, sizeof(pricevis));
            pricevis[aa[i].id] = aa[i].price;
            for (int j = i + 1; j < label; j++) {
                if (idvis[aa[j].id])continue;
                    //P+=aa[j].prize
                else {
                    if (aa[j].price < pricevis[aa[j].id]) {
                        pricevis[aa[j].id] = aa[j].price;
                        idvis[aa[j].id] = 1;
                    }
                }
            }
            for (int j = 1; j <= n; j++) {
                //		cout<<pricevis[j]<<" "<<j<<"    ";
                P += pricevis[j];
            }
            //	cout<<B<<"   ";
            //cout<<P<<"    ";
            if (B / P > maxn)maxn = B / P;
            //	cout<<maxn<<endl;
        }
        cout << fixed << setprecision(3) << maxn << endl;
    }
    return 0;
}
			
		
				
			

