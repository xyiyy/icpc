//
// Created by xyiyy on 2015/8/11.
//

#ifndef JHELPER_EXAMPLE_PROJECT_BIT_HPP
#define JHELPER_EXAMPLE_PROJECT_BIT_HPP
struct BIT{
    int sz;
    ll* bit;
    void init()
    {
        rep(i,sz+1) bit[i]=0;
    }
    BIT(int size)
    {
        sz=size>0?size:0;
        bit=new ll[sz+1];
        this->init(); // initialize
    }
    ~BIT()
    {
        delete[] bit;
    }
    void add(int i, ll x)
    {
        while(i<=sz)
        {
            bit[i]+=x;
            i+=i&-i;
        }
    }
    ll query(int i)
    {
        ll sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=i&-i;
        }
        return sum;
    }
    int kth(int k)
    {
        int r = 0, h = H;
        while(h>>=1)
        {
            r += h;
            if(r > sz || bit[r] >= k)
                r -= h;
            else
                k -= bit[r];
        }
        /*
        int i = r+1;
        while(i<=sz)
        {
            bit[i]--;
            i += i&-i;
        }
        */
        return r;
    }
};
struct BIT2{
    int sz;
    ll* bit0;
    ll* bit1;
    void init()
    {
        rep(i,sz+1) bit0[i] = bit1[i] = 0;
    }
    BIT(int size)
    {
        sz=size>0?size:0;
        bit1 = new ll[sz+1];
        bit2 = new ll[sz+1];
        this->init(); // initialize
    }
    ~BIT()
    {
        delete[] bit0;
        delete[] bit1;
    }
    ll query(ll *b,int i){
        ll s = 0;
        while(i>0){
            s += b[i];
            i -= i & -i;
        }
        return s;
    }
    void add(ll *b,int i,int v){
        while(i<=sz){
            b[i] += v;
            i += i & -i;
        }
    }
    void add(int l,int r,ll x) {//[l,r] add x
        add(bit0, l, -x * (l - 1));
        add(bit1, l, x);
        add(bit0, r + 1, x * r);
        add(bit1, r + 1, -x);
    }
    ll query(int l,int r){//[l,r]
        ll ret = 0;
        ret += query(bit0, r) + query(bit1, r) * r;
        ret -= query(bit0, l - 1) + query(bit1, l - 1) * (l - 1);
        return ret;
    }
};

#endif //JHELPER_EXAMPLE_PROJECT_BIT_HPP
