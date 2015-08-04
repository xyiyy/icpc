#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define nMax 110
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
int map[nMax][nMax];
int DFN[nMax],Low[nMax];
bool isVisted[nMax];
int gPoint[nMax];
int index, root;
int n,ans;
void tarjan(int u)
{
	DFN[u] = Low[u] = ++index;
	isVisted[u] = true;
	for (int i = 1; i <= n; ++ i)
	{
		if (map[u][i])
		{
			if (!isVisted[i])
			{
				tarjan(i);
				Low[u] = Min(Low[u], Low[i]);
				if (Low[i] >= DFN[u] && u != 1)//if it is not root
				{
					gPoint[u] ++;
				}
				else if (u == 1)//if it is root
				{
					root ++;
				}
			}
			else
			{
				Low[u] = Min(Low[u], DFN[i]);
			}
		}
	}
}
int main()
{
	while (scanf("%d", &n) && n)
	{
		int u, v;
		memset(map, 0, sizeof(map));
		memset(isVisted, false, sizeof(isVisted));
		memset(gPoint, 0, sizeof(gPoint));
		ans = root = index = 0;
		while (scanf("%d", &u) && u)
		{
			while (getchar() != '\n')
			{
				scanf("%d", &v);
				map[u][v] = 1;
				map[v][u] = 1;
			}
		}
		tarjan(1);
		if (root > 1)
		{
			ans ++;
		}
		for (int i = 2; i <= n; ++ i)
		{
			
			if (gPoint[i])
			{
				ans ++;
			}
		}
	
		printf("%d\n", ans);
	}
	return 0;
}
