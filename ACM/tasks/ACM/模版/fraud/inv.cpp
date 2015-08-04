void extgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){
        d=a;x=1;y=0;
    }else{
        extgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
ll inv(ll a){
    ll d,x,y;
    extgcd(a,MOD,d,x,y);
    return d==1?(x+MOD)%MOD:-1;
}