#include <stdio.h>
#include <math.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define INF 0x3FFFFFFF
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>rb_tree;
int main()
{
	rb_tree t;
	int n,a,b,sz1=0,sz2=0,ans=0;
	rb_tree::iterator x,y;
	t.insert(-INF);
	t.insert(INF);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		x=t.lower_bound(b);
        y=x--;
		if(a==0){
			if(sz2)
			{
				if(abs(*x-b)<=abs(*y-b)){
					ans+=abs(*x-b);
					t.erase(*x);
				}else if(abs(*x-b)>abs(*y-b)){
					ans+=abs(*y-b);
					t.erase(*y);
				}
				sz2--;
			}else
			{
				t.insert(b);
				sz1++;
			}
		}
		else {
			if(sz1)
			{
				if(abs(*x-b)<=abs(*y-b)){
					ans+=abs(*x-b);
					//printf("%d\n",*x);
					t.erase(*x);
				}else if(abs(*x-b)>abs(*y-b)){
					ans+=abs(*y-b);
					t.erase(*y);
				}
				sz1--;
			}else
			{
				t.insert(b);
				sz2++;
			}
		}
		ans%=1000000;
	}
	printf("%d\n",ans);
	return 0;
}


