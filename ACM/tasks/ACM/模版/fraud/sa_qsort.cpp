int n,k;
int rank[MAXN],tmp[MAXN],height[MAXN],sa[MAXN];
bool cmp(int i,int j){
	if(rank[i]!=rank[j])return rank[i]<rank[j];
	else{
		int ri = i+k <= n ? rank[i+k] : -1;
		int rj = j+k <= n ? rank[j+k] : -1;
		return ri < rj;
	}
}
void build(int len,char *s){
	n=len;
	for(int i=0;i<=n;i++)sa[i]=i,rank[i]= i<n ? s[i] : -1;
	for(k=1;k<=n;k<<=1){
		sort(sa,sa+n+1,cmp);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++)tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i]) ? 1 : 0);
		for(int i=0;i<=n;i++)rank[i]=tmp[i];
	}
}
void calheight(int len,char *s){
	n=len;
	for(int i=0;i<=n;i++)rank[sa[i]]=i;
	int h=0;
	height[0]=0;
	for(int i=0;i<=n;i++){
		int j=sa[rank[i]-1];
		if(h>0)h--;
		for(;j+h<n&&i+h<n;h++){
			if(s[i+h]!=s[j+h])break;
		}
		height[rank[i]-1]=h;
	}
}
	
