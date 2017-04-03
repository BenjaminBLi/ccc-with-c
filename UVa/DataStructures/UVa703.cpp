#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class dset{
    private: vi p, rnk;
    public:
    dset(int N){
        rnk.assign(N, 0); p.assign(N, 0);
        for(int i = 0;i < N; i++) p[i] = i;
    }
    int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool sameSet(int i, int j){return findSet(i) == findSet(j);}
    void unionSet(int i, int j){
        if(!sameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rnk[x] > rnk[y]) p[y] = x;
            else{
                p[x] = y;
                if(rnk[x] == rnk[y]) rnk[y]++;
            }
        }
    }
};

int T, n, a, b;
string line;
stringstream ss;
char ch;
int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d\n", &T);
    while(T--){
        scanf("%d", &n);
        dset s(n);
        int co = 0, wr = 0;
        getchar();
        while((ch = getchar()) && isalpha(ch)){
            //cout << ch << endl;
            scanf("%d %d", &a, &b); getchar(); a--; b--;
            if(ch == 'c') s.unionSet(a, b);
            else{
                if(s.sameSet(a, b)) co++;
                else wr++;
            }
        }
        printf("%d,%d\n", co, wr);
        if(T) printf("\n");
    }
    return 0;
}
