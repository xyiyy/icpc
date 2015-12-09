int B[4010];
void Bell(int T[],int N,int MOD){
    B[0] = 1;B[1] = 1;T[0] = 1;
    for(int i=2;i<N;i++){
        T[i-1] = B[i-1];
        for(int j=i-2;j>=0;j--)T[j] = (T[j]+T[j+1])%MOD;
        B[i] = T[0];
    }
}

