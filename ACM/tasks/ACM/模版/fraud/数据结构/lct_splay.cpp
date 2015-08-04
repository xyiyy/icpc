#define MAXN 100010
int ch[MAXN][2],key[MAXN],pre[MAXN],size[MAXN],ss[MAXN];
int rev[MAXN];
void push_down(int r){
	if(!r)return;
	if(rev[r]){
		rev[ch[r][0]]^=1;
		rev[ch[r][1]]^=1;
		swap(ch[r][0],ch[r][1]);
		rev[r]=0;
	}
}
void rotate(int x,int d){
	int y=pre[x];
	ch[y][!d]=ch[x][d];
	if(ch[x][d])pre[ch[x][d]]=y;
	pre[x]=pre[y];
	if(ch[pre[y]][0]==y)ch[pre[x]][0]=x;
	else if(ch[pre[y]][1]==y)ch[pre[x]][1]=x;
	pre[y]=x;
	ch[x][d]=y;
}
bool check(int x,int y){
	return y&&(ch[y][0]==x||ch[y][1]==x);
}
void splay(int x){
	push_down(x);
	int y,z;
	while(check(x,y=pre[x])){
		if(check(y,z=pre[y])){
			push_down(z);
			push_down(y);
			push_down(x);
			int d=(y==ch[z][0]);
			if(x==ch[y][d]) {rotate(x,!d),rotate(x,d);}
			else {rotate(y,d),rotate(x,d);}
		}else{
			push_down(y);
			push_down(x);
			rotate(x,ch[y][0]==x);
			break;
		}
	}
}
int access(int u){
	int v=0;
	for(;u;u=pre[u]){
		splay(u);
		ch[u][1]=v;
		v=u;
	}
	//splay(u);
	return v;
}
int getroot(int x){
	for(x=access(x);push_down(x),ch[x][0];x=ch[x][0]);
	return x;
}
void makeroot(int x){
	rev[access(x)]^=1;
	splay(x);
}
void link(int x,int y){
	makeroot(x);
	pre[x]=y;
	access(x);
}
void cut(int x,int y){
	makeroot(x);
	access(y);
	splay(y);
	pre[ch[y][0]]=0;
	ch[y][0]=0;
}
