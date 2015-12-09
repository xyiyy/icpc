const int MAXN = 5000010;
ll phi[MAXN];
void eular(){
    for(int i=2;i<=MAXN;i++)phi[i]=0;
    phi[1]=1;
    for(int i=2;i<=MAXN;i++){
        if(!phi[i])
        for(int j=i;j<=MAXN;j+=i){
            if(!phi[j])phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
    }
    phi[0]=0;
}