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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
struct node
{
    int key,num;
    bool operator <(const node &b)const
    {
        return key<b.key;
    }

};
typedef tree<node,null_type,less<node>,splay_tree_tag,tree_order_statistics_node_update> splay_tree;

int main()
{
	ios::sync_with_stdio(false);
	int n,pos,k;
	node Node;
	while(~scanf("%d",&n))
	{
		splay_tree t;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&pos,&k);
			Node.key=pos;
			Node.num=k;
			t.insert(Node);
		}
		splay_tree::iterator it=t.begin();
		for(int i=0;i<n;i++)
		{
			if(i)printf(" ");
			printf("%d",(*it).num);
			it++;
		}
		printf("\n");
	}

	return 0;
}


