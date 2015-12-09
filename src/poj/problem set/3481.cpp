//¸ßÉñ±£ÓÓ¡ª¡ªAC
#include <iostream>
#include <stdio.h>

using namespace std;/*
const int maxn=500010;
int pre[maxn],key[maxn],num[maxn],ch[maxn][2],ss[maxn];
int tot,tot2,root;
void newnode(int &r,int father,int k,int p)
{
	if(tot2)r=ss[--tot2];
	else r=++tot;
	pre[r]=father;
	ch[r][0]=ch[r][1]=0;
	key[r]=k;
	num[r]=p;
}
void init()
{
	root=tot=tot2=0;
	pre[root]=num[root]=ch[root][0]=ch[root][1];
	key[root]=0;
}

void rotate(int x,int d)
{
	int y=pre[x];
	ch[y][!d]=ch[x][d];
	pre[ch[x][d]]=y;
	if(pre[y]) ch[pre[y]][ch[pre[y]][1]==y]=x;
	pre[x]=pre[y];
	ch[x][d]=y;
	pre[y]=x;
}
void splay(int x,int goal)
{
	while(pre[x]!=goal)
	{
		if(pre[pre[x]]==goal)
		{
			rotate(x,ch[pre[x]][0]==x);
		}else
		{
			int y=pre[x];
			int d=ch[pre[y]][0]==y;
			if(ch[y][d]==x)
			{
				rotate(x,!d);
				rotate(x,d);
			}
			else
			{
				rotate(y,d);
				rotate(x,d);
			}
		}
	}
	if(goal==0)root=x;
}
void insert(int k,int p)
{
	int r=root;
	while(ch[r][k>=key[r]])
	{
		r=ch[r][k>=key[r]];
	}
	newnode(ch[r][k>=key[r]],r,k,p);
	splay(ch[r][k>=key[r]],0);
}
void erase(int r)
{
	ss[tot2++]=r;
	ch[pre[r]][ch[pre[r]][1]==r]=0;
	pre[r]=0;
}
int get_pre()
{
	int r=root,ret;
	while(ch[r][0])
	{
		r=ch[r][0];
	}
	ret=num[r];
	int rson=r;
	while(ch[rson][1])
	{
		rson=ch[rson][1];
	}
	if(rson!=r)splay(rson,pre[r]);
	erase(r);
	return ret;
}
int get_next()
{
	int r=root,ret;
	while(ch[r][1])
	{
		r=ch[r][1];
	}
	ret=num[r];
	int lson=r;
	while(ch[lson][0])
	{
		lson=ch[lson][0];
	}
	if(lson!=r)splay(lson,pre[r]);
	erase(r);
	return ret;
}
bool scan_d(int &ret){
	char c;int sgn;
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9')
	{
		ret=ret*10+(c-'0');
	}
	ret*=sgn;
	return 1;
}
void out(int x)
{
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
int main()
{
	int op;
	int k,p;
	int size=0;
	init();
	while(1)
	{
		scan_d(op);
		if(op==0)break;
		if(op==1)
		{
			scan_d(k);
			scan_d(p);
			if(size)
			insert(p,k);
			else newnode(root,0,p,k);
			size++;
		}
		else if(op==1)
		{
			if(!size)
			{
				out(0);
				puts("");
			}
			else
			{
				out(get_next());
				puts("");
				size--;
			}
		}
		else
		{
			if(!size)
			{
				out(0);
				puts("");
			}
			else
			{
				out(get_pre());
				puts("");
				size--;
			}
		}
	}
	return 0;
}
 */
#define MP(A, B)  make_pair(A,B)
typedef pair<int, int> PII;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<PII, null_type, less<PII>, splay_tree_tag, tree_order_statistics_node_update> splay_tree;

bool scan_d(int &ret) {
    char c;
    int sgn;
    while (c != '-' && (c < '0' || c > '9'))c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

void out(int x) {
    if (x > 9)out(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int op, k, p;
    int n;
    splay_tree t;
    splay_tree::iterator it;
    while (1) {
        scan_d(op);
        if (!op)break;
        else if (op == 1) {
            scan_d(k);
            scan_d(p);
            t.insert(MP(p, k));
        }
        else if (op == 3) {
            n = t.size();
            //out(n);
            //puts("");
            if (!n) {
                out(0);
                puts("");
            }
            else {
                it = t.find_by_order(0);
                out(it->second);
                t.erase(MP(it->first, it->second));
                puts("");
            }
        }
        else if (op == 2) {
            n = t.size();
            //out(n);
            //puts("");
            if (!n) {
                out(0);
                puts("");
            }
            else {
                it = t.find_by_order(n - 1);
                out(it->second);
                t.erase(MP(it->first, it->second));
                puts("");
            }
        }
    }
    return 0;
}



