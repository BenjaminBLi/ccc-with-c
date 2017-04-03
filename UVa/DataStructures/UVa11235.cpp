#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class st{
private: vi st, A;
    int n;
    int left(int p){return p << 1;}
    int right(intp) {return (p<<1)+1;}
    void build(int p, int L, int R){
        if(L == R) st[p] = L;
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int i, int j){
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L+R)/2, i,j);
        int p2 = rmq(right(p), (L+R)/2+1,R, i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] >= A[p2]) ? p1 : p2;
    }
public:
    st(const vi &_A){
        A = _A; n = (int) A.size();
        st.assign(4*n+1, 0);
        build(1, 0, n-1);
    }
    int rmq(int i, int j){return rmq(1, 0, n-1, i, j);}
};

int n, q;
vi freq, val;
int main(){
    while(scanf("%d", &n) && n != 0){
        scanf("%d", &q);
        val.assign(n, 0); freq.assign(n, 0);
        for(int i = 0; i < n; i++) scanf("%d", &val[i]);
        int cnt = 1, curr = val[0];
        for(int i = 1; i < n; i++)
    }
    return 0;
}
