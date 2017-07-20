#include "bits/stdc++.h"
#define s second
#define f first
using namespace std;
typedef pair<int, int> ii;
int N, res[210][210], w[210], mf, f, s, t, p[210];
map<int, int> adj[210];

/*
make a topsort, and then use a priority queue to sort all of the elements

 */

int main(){
    scanf("%d", &N);
    s = 0;
    t = N;
    for(int i = 1; i < N; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
    }

    return 0;
}