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

stack<string>s;
stack<string>tmp;
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        while(!s.empty())s.pop();
        int n;
        cin>>n;
        string str;
        string temp;
        for(int i=0;i<n;i++){
            cin>>str;
            //cout<<str<<endl;
            if(str=="pwd"){
                cout<<"/";
                while(!s.empty()){
                    tmp.push(s.top());
                    //cout<<s.top()<<"/";
                    s.pop();
                }
                while(!tmp.empty()){
                    s.push(tmp.top());
                    cout<<tmp.top()<<"/";
                    tmp.pop();
                }
                cout<<endl;
            }else{
                cin>>str;
                temp="";
                int len=str.length();
                for(int i=0;i<len;i++){
                    if(i==0&&str[i]=='/'){
                        while(!s.empty())s.pop();
                    }else if(str[i]=='/'){
                        if(temp==".."){
                            if(!s.empty())s.pop();
                        }
                        else{
                            if(temp.length()>0)s.push(temp);
                        }
                        temp ="";

                    }else{
                        temp = temp +str[i];
                    }
                }
                if(temp=="..")s.pop();
                else{
                    if(temp.length()>0)s.push(temp);
                }
                temp ="";

            }
        }
    }
	return 0;
}



