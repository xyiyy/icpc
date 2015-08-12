//
// Created by xyiyy on 2015/8/10.
//

#ifndef JHELPER_EXAMPLE_PROJECT_MATRIX_HPP
#define JHELPER_EXAMPLE_PROJECT_MATRIX_HPP
class Matrix{
public:
    Matrix(int _r,int _c):r(_r),c(_c){}
    void Init()
    {
        rep(i,r){
            rep(j,c){
                if(i==j)m[i][j] = 1;
                else m[i][j] =0;
            }
        }
    }
    void Unit();
    friend Matrix operator *(const Matrix &,const Matrix &);
    Matrix power(ll n);
    ll m[maxn][maxn];
    int r,c;
};
Matrix operator*(const Matrix&M1,const Matrix &M2)
{
    Matrix M(M1.r,M2.c);
    rep(i,M1.r)
    rep(j,M2.c)M.m[i][j] = 0;
    rep(i,M1.r)
    rep(k,M1.c)
    {
        if(M1.m[i][k]!=0)
        rep(j,M2.c)
        {
            M.m[i][j]=(M.m[i][j]+M1.m[i][k]*M2.m[k][j])%MOD;
        }
    }
    return M;
}
Matrix Matrix::power(ll n){
    Matrix tmp(r,r);
    rep(i,r){
        rep(j,c){
            tmp.m[i][j] = m[i][j];
        }
    }
    (*this).Init();
    while(n){
        if(n&1)(*this) = (*this)*tmp;
        tmp =tmp *tmp;
        n>>=1;
    }
    return *this;
}

#endif //JHELPER_EXAMPLE_PROJECT_MATRIX_HPP
