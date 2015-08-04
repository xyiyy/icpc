#include <iostream>
using namespace std;
#define INF 0x3FFFFFFF

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> rb_tree;
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	int x,y,ans;
	while(cin>>n)
	{
		ans=0;
		rb_tree t;
		rb_tree::iterator x,y;
		t.insert(-INF);
		t.insert(INF);
		for(int i=0;i<n;i++)
		{
		    m=0;
			cin>>m;
			//cout<<m<<endl;
			if(i)
            {
                x=t.lower_bound(m);
                y=x--;
               // cout<<*x<<"  "<<*y<<endl;
                ans+=min(abs(*x-m),abs(*y-m));
            }
			else{
                ans+=m;
			}
			//cout<<ans<<endl;
			t.insert(m);
		}
		cout<<ans<<endl;
		n=0;
	}

	return 0;
}


