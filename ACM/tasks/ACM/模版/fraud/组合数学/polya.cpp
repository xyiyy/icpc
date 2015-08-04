
const int maxn;
int perm[maxn];
bool vis[maxn];
int num;//置换节个数
 
int polya(int n)//n表示要求的为0~n-1的一个置换
{
	num=0;
	int j,p;
	CLR(vis,0);
	int ret=1;//返回置换最小周期 
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			num++;
			for(j=0,p=i;!vis[p=perm[p]];j++)
			{
				vis[p]=1;
			}
			ret*=j/__gcd(ret,j);
		}
	}
	return ret;
}

