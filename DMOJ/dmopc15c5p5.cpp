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
        for (; b; b -= (b&(-b)))
            sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v) {
        for (; k < (int) ft.size(); k += (k&(-k))) {
            ft[k] += v;
        }
    }
};

int N, p[200000], order[200000], root;
vector<vi> tree;

int main(){

    scanf("%d", &N); tree.assign(N, vi());
    for(int i =0; i < N; i++){
        scanf("%d", &p[i]);
        if(p[i]){
           p[i]--;
            tree[i].push_back(p[i]);
            tree[p[i]].push_back(i);
        }
        else root = i;
    }
    for(int i =0; i < N; i++) scanf("%d", &order[i]);
    //
    return 0;
}
