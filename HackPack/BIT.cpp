#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class FT{
private:
    vi ft;
public:
    FT(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= (b&(-b))){
            sum += ft[b];
        }
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v) {
        for (; k < (int) ft.size(); k += (k&(-k))) {
            cout << k << endl;
            ft[k] += v;
        }
    }
};

//2d ft

void upd(int r, int c, int val) {
    for (; r <= S; r += (r & -r)) for (int nc = c; nc <= S; nc += (nc & -nc)) ft[r][nc] += val;
}
int val(int r, int c) {
    int ret = 0;
    for (; r; r -= r & -r) for (int nc = c; nc; nc -= nc & -nc) ret += ft[r][nc];
    return ret;
}
int val(int sr, int sc, int er, int ec){
    return val(er, ec) - val(sr-1, ec) - val(er, sc-1) + val(sr-1, sc-1);
}