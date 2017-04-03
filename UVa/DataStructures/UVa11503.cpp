#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class dset{
    private: vi p, rnk, sz; int nsets;
    public:
    dset(int N){
        rnk.assign(N, 0);p.assign(N, 0); sz.assign(N, 1);
        for(int i = 0;i < N; i++) p[i] = i;
        nsets = 0;
    }
    int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool sameSet(int i, int j){return findSet(i) == findSet(j);}
    void unionSet(int i, int j){
        if(!sameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rnk[x] > rnk[y]){
                sz[findSet(x)] += sz[findSet(y)];
                p[y] = x;
            }else{
                sz[findSet(y)] += sz[findSet(x)];
                p[x] = y;
                if(rnk[x] == rnk[y]) rnk[y]++;
            }
            nsets--;
        }
    }
    int getSize(int i){return sz[findSet(i)];}
};

int T, F;
map<string, int> idx;
string n1, n2;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for(;T--;){
        scanf("%d", &F);
        //cout << F << endl;
        int cnt = 0;
        idx.clear();
        dset s(F*2);
        for(int i = 0;i < F; i++){
            cin >> n1 >> n2;
            if(idx.find(n1) == idx.end()) idx[n1] = cnt++;
            if(idx.find(n2) == idx.end()) idx[n2] = cnt++;
            s.unionSet(idx[n1], idx[n2]);
            printf("%d\n", s.getSize(idx[n1]));
        }
    }
    return 0;
}
