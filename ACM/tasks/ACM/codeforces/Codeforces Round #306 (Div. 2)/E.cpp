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
bool a[100010];
bool cal(int x,int y){
    if(x==0)return 1;
    if(y==1)return 1;
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>a[i];
	}

	if(a[n-1]!=0){
        cout<<"NO"<<endl;
        return 0;
	}
	if(n>=2&&a[n-2]==0&&a[n-1]==0){
        bool f=0;
        for(int i=0;i<n-2;i++){
            if(a[i]==0)f=1;
        }
        if(f){
            cout<<"YES"<<endl;
            int m=1;
            int j=n-3;
            for(int i=n-3;i>=0;i--,j--){
                if(a[i]==0)break;
                m++;
            }
            for(int i=0;i<j;i++){
                if(a[i]==1){
                    cout<<"1->";
                }
                else{
                    int num=1;
                    while(a[i+1]==0&&i+1<j){
                        num++;
                        i++;
                    }
                    if(num&1){
                        cout<<0<<"->";
                        num--;
                    }
                    while(num){
                        cout<<"(0->0)->";
                        num-=2;
                    }

                }
            }

            for(int i=j;i<n-1;i++){
                if(i!=n-2)cout<<"(";
                cout<<a[i];
                if(i==n-2){
                    for(int k=0;k<m;k++){
                        cout<<")";
                    }
                }
                cout<<"->";
            }
            cout<<0<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        return 0;
	}
	//=================
	cout<<"YES"<<endl;
	for(int i=0;i<n-1;i++){
        if(a[i]==1){
            cout<<"1->";
        }
        else{
            int num=1;
            while(a[i+1]==0&&i+1<n-1){
                num++;
                i++;
            }
            if(num&1){
                cout<<0<<"->";
                num--;
            }
            while(num){
                cout<<"(0->0)->";
                num-=2;
            }

        }
	}
	cout<<0<<endl;
	return 0;
}



