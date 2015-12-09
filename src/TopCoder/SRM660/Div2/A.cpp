
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
char a[1010];
class Cyclemin{
public:
    string bestmod(string s, int k){
        int len = s.length();
        string str1=s;
        string str2=s;
        int num =k;
        CLR(a,0);
        for(int i=0;i<len;i++){
           s = str1.substr(i,str1.length())+str1.substr(0,i);
           for(int i=0;i<len;i++){
                a[i]=s[i];
            }
        //sort(a,a+len);
            k=num;
            for(int i=0;i<len&&k;i++){
                if(a[i]=='a'){
                    continue;
                }else{
                    a[i]='a';
                    k--;
                }
            }
            for(int i=0;i<len;i++){
                s[i]=a[i];
            }
            if(s<str2)str2=s;

        }

        return str2;
    }
};

int main()
{
	ios::sync_with_stdio(false);
    Cyclemin *temp = new Cyclemin();
    string str;
    int k;
    cin>>str>>k;
    cout<<temp->bestmod(str,k)<<endl;;

	return 0;
}


