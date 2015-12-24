//
// Created by xyiyy on 2015/8/10.
//

#ifndef ICPC_P_HPP
#define ICPC_P_HPP

const double EPS = 1e-10;

int sig(double x) {
    if (fabs(x) < EPS)return 0;
    return x < 0 ? -1 : 1;
}

double add(double a, double b) {
    if (fabs(a + b) < EPS * (fabs(a) + fabs(b)))return 0;
    return a + b;
}

class P {
public:
    double x, y;

    P() { }

    P(double x, double y) : x(x), y(y) { }

    P  operator+(const P &p) {
        return P(add(x, p.x), add(y, p.y));
    }

    P operator-(const P &p) {
        return P(add(x, -p.x), add(y, -p.y));
    }

    P operator*(const double &d) {
        return P(x * d, y * d);
    }

    P operator/(const double &d) {
        return P(x / d, y / d);
    }

    double Dot(P p) {
        return x * p.x + y * p.y;
    }

    double dot(P p) {
        return add(x * p.x, y * p.y);
    }

    double Det(P p) {
        return x * p.y - y * p.x;
    }

    double det(P p) {
        return add(x * p.y, -y * p.x);
    }


    double abs() {
        return sqrt(abs2());
    }

    double abs2() {
        return dot(*this);
    }

    //???????????B?????????????????
    P rot(double rad) {
        return P(add(x * cos(rad), -y * sin(rad)), add(x * sin(rad), y * cos(rad)));
    }

    P rot90() {
        return P(-y, x);
    }

    bool equals(P p) {
        return compareTo(p) == 0;
    }

    int compareTo(P p) {
        int b = sig(x - p.x);
        if (b != 0)return b;
        return sig(y - p.y);
    }

};


//?ж????????????
bool on_seg(P p1, P p2, P q) {
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

//????????ε????
P intersection(P p1, P p2, P q1, P q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

//??????ж?
bool crsSS(P p1, P p2, P q1, P q2) {
    if (max(p1.x, p2.x) + EPS < min(q1.x, q2.x))return false;
    if (max(q1.x, q2.x) + EPS < min(p1.x, p2.x))return false;
    if (max(p1.y, p2.y) + EPS < min(q1.y, q2.y))return false;
    if (max(q1.y, q2.y) + EPS < min(p1.y, p2.y))return false;
    /*(if((p1 - p2).det(q1 - q2) == 0){
        return (on_seg(p1,p2,q1) || on_seg(p1,p2,q2) || on_seg(q1,q2,p1) || on_seg(q1,q2,p2));
    }else{
        P r = intersection(p1,p2,q1,q2);
        return on_seg(p1,p2,r) && on_seg(q1,q2,r);

    }*/
    return (p2 - p1).det(q1 - p1) * (p2 - p1).det(q2 - p1) <= 0
           && (q2 - q1).det(p1 - q1) * (q2 - q1).det(p2 - q1) <= 0;
}

//??????????ж?
bool crsLS(P l1, P l2, P s1, P s2) {
    return (s1 - l2).det(l1 - l2) * (s2 - l2).det(l1 - l2) <= 0;
}

//??????ж?
//????-1???????0?????У?1?????
int crsLL(P p1, P p2, P q1, P q2) {
    if (sig((p1 - p2).det(q1 - q2)) != 0)return 1;
    if (sig((p1 - q2).det(q1 - p2)) != 0)return 0;
    return -1;
}

//???????????
/*P isLL(P p1,P p2,P q1,P q2){
    double d = (q2 - q1).det(p2 - p1);
    if(sig(d)==0)return NULL;
    return intersection(p1,p2,q1,q2);
}*/

//?????????
P proj(P p1, P p2, P q) {
    return p1 + ((p2 - p1) * ((p2 - p1).dot(q - p1) / (p2 - p1).abs2()));
}

//??????????
double disLP(P p1, P p2, P q) {
    return fabs((p2 - p1).det(q - p1)) / (p2 - p1).abs();
}


//??ε???????
double disSP(P p1, P p2, P q) {
    if ((p2 - p1).dot(q - p1) <= 0)return (q - p1).abs();
    if ((p1 - p2).dot(q - p2) <= 0)return (q - p2).abs();
    return disLP(p1, p2, q);
}

//???????????ж?
bool crsCS(P c, double r, P p1, P p2) {
    return disSP(p1, p2, c) < r + EPS && (r < (c - p1).abs() + EPS || r < (c - p2).abs() + EPS);
}

//?????????ж?
bool crsCC(P c1, double r1, P c2, double r2) {
    double dis = (c1 - c2).abs();
    return dis < r1 + r2 + EPS && fabs(r1 - r2) < dis + EPS;
}

//?????ж?
/*bool onC(P p1,P p2,P p3,P p4){
    P c = CCenter(p1,p2,p3);
    if(c == NULL) return false;
    return add((c - p1).abs2(), -(c - p4).abs2()) == 0;
}*/

//??????????
/*P CCenter(P p1,P p2,P p3){
    //if(disLP(p1, p2, p3) < EPS)return NULL;//??????
    P q1 = (p1 + p2) * 0.5;
    P q2 = q1 + ((p1 - p2).rot90());
    P s1 = (p3 + p2) * 0.5;
    P s2 = s1 + ((p3 - p2).rot90());
    return isLL(q1,q2,s1,s2);
}*/

//?????????? ??p?????
double polarangle(P p, P q) {
    return atan2(q.y - p.y, q.x - p.x);
}


bool cmp_x(const P &p, const P &q) {
    if (p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

vector <P> qs;

void convex_hull(P *ps, int n) {
    sort(ps, ps + n, cmp_x);
    int k = 0;
    qs.resize(2 * n);
    for (int i = 0; i < n; qs[k++] = ps[i++]) {
        while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) < EPS)k--;
    }
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--]) {
        while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) < EPS)k--;
    }
    qs.resize(k - 1);
}

//??????????
double convexDiameter() {
    int qsz = qs.size();
    if (qsz == 1)return 0;
    if (qsz == 2) {
        return (qs[0] - qs[1]).abs();
    }
    int i = 0, j = 0;
    rep(k, qsz)
    {
        if (!cmp_x(qs[i], qs[k]))i = k;
        if (cmp_x(qs[j], qs[k])) j = k;
    }
    double res = 0;
    int si = i, sj = j;
    while (i != sj || j != si) {
        res = max(res, (qs[i] - qs[j]).abs());
        if ((qs[(i + 1) % qsz] - qs[i]).det(qs[(j + 1) % qsz] - qs[j]) < 0) i = (i + 1) % qsz;
        else j = (j + 1) % qsz;
    }
    return res;
}


#endif //ICPC_P_HPP
