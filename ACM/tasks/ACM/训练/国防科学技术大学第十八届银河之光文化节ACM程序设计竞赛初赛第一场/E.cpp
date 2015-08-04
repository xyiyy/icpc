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


struct Square{
	int ll, lr, ul, ur;
	int color;
	int area;
	bool cut;
	Square()
	{
	}
	Square(int ll, int lr, int ul, int ur, int color)
	{
		this->ll = ll;
		this->lr = lr;
		this->ul = ul;
		this->ur = ur;
		this->color = color;
		this->area = (ul - ll) * (ur - lr);
		this->cut = false;
	}
};


void addSquare(vector<Square> &squares, const Square& square)
{
	if(square.area != 0)
	{
		squares.push_back(square);
	}
}

int main()
{

	int a, b, n;
	int t;
	scanf("%d",&t);
	while(t--){
	scanf("%d%d%d", &a, &b, &n);
	vector<Square> squares;
	squares.push_back(Square(0, 0, a, b, 1));
	for(int i = 0; i < n; ++i)
	{
		int ll, lr, ul, ur, color;
		scanf("%d%d%d%d%d", &ll, &lr, &ul, &ur, &color);
		Square square(ll, lr, ul, ur, color);
		for(unsigned int j = 0; j < squares.size(); ++j)
		{
			if(!squares[j].cut)
			{
				int maxll, maxlr, minul, minur;
				maxll = max(ll, squares[j].ll);
				maxlr = max(lr, squares[j].lr);
				minul = min(ul, squares[j].ul);
				minur = min(ur, squares[j].ur);
				if(maxll >= minul || maxlr >= minur)
				{
					continue;
				}
				squares[j].cut = true;
				addSquare(squares, Square(squares[j].ll, squares[j].lr, maxll,
					squares[j].ur, squares[j].color));
				addSquare(squares, Square(maxll, minur, minul,
					squares[j].ur, squares[j].color));
				addSquare(squares, Square(minul, squares[j].lr, squares[j].ul,
					squares[j].ur, squares[j].color));
				addSquare(squares, Square(maxll, squares[j].lr, minul,
					maxlr, squares[j].color));
			}
		}
		addSquare(squares, square);
	}

	map<int, int> cntColors;
	for(unsigned int i = 0; i < squares.size(); ++i)
	{
		if(!squares[i].cut)
		{
			if(cntColors.find(squares[i].color) == cntColors.end())
			{
				cntColors[squares[i].color] = squares[i].area;
			}
			else
			{
				cntColors[squares[i].color] += squares[i].area;
			}
		}
	}
	for(map<int, int>::iterator iter = cntColors.begin(); iter != cntColors.end(); ++iter)
	{
		printf("%d %d\n", iter->first, iter->second);
	}
	}
	return 0;
}
