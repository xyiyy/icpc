//
// Created by xyiyy on 2015/8/15.
//

#ifndef ICPC_NEWSCANNER_HPP
#define ICPC_NEWSCANNER_HPP

#define MAX_LEN 20000000
#define MAX_SINGLE_DATA 100
#define getchar Getchar
#define putchar Putchar

char buff[MAX_LEN + 1];
int len_in = 0;
int pos_in = 0;

inline void Read() {
    if(len_in < MAX_SINGLE_DATA) {
        int len = 0;
        while(len_in--)
            buff[len++] = buff[pos_in++];
        len_in = len + fread(buff + len, 1, MAX_LEN - len, stdin);
        pos_in = 0;
    }
}

inline int Getchar() {
    Read();
    if(len_in == 0) return -1;
    int res = buff[pos_in];
    if(++pos_in == MAX_LEN) pos_in = 0;
    len_in--;
    return res;
}

char buff_out[MAX_LEN + 1];
int len_out = 0;
inline void Flush() {
    fwrite(buff_out, 1, len_out, stdout);
    len_out = 0;
}

inline void Putchar(char c) {
    buff_out[len_out++] = c;
    if(len_out + MAX_SINGLE_DATA >= MAX_LEN)
        Flush();
}

inline int Scan() {
    int res, ch=0;
    while(!(ch>='0'&&ch<='9')) ch=getchar();
    res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return res;
}

template<class T>
inline void Out(T a) {
    static int arr[20];
    int p = 0;
    do{
        arr[p++] = a%10;
        a /= 10;
    }while(a);
    while(p--) {
        putchar(arr[p]+'0');
    }
}

#endif //ICPC_NEWSCANNER_HPP
