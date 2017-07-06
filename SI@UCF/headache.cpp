#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;

int nsets = 0, p[40010], rnk[40010], sz[40010];

int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
bool sameSet(int i, int j){return findSet(i) == findSet(j);}
void unionSet(int i, int j) {
    if (!sameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rnk[x] > rnk[y]) {
            sz[findSet(x)] += sz[findSet(y)];
            p[y] = x;
        } else {
            sz[findSet(y)] += sz[findSet(x)];
            p[x] = y;
            if (rnk[x] == rnk[y]) rnk[y]++;
        }
        nsets--;
    }
}
int getSize(int i){return sz[findSet(i)];}


struct edge{
    int u, v, w;
    edge(){};
    edge(int a, int b, int c){
        u = a, v = b, w =c;
    }
    bool operator< (const edge &o) const{
        return w < o.w;
    }
    bool operator> (const edge &o) const{
        return w > o.w;
    }
};

int N, M;

int main(){
    scanf("%d %d", &N, &M);
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge c = edge(u, v, w);
        pq.push(c);
    }
    int ans = 0;
    while(pq.size()){
        edge c = pq.top(); pq.pop();
        printf("%d %d %d\n", c.u, c.v, c.w);
        unionSet(c.u, c.v+N);
        unionSet(c.u+N, c.v);
        if(sameSet(c.u, c.v)){
            ans = c.w;
            break;
        }
    }
    printf("%d\n", ans);
}
