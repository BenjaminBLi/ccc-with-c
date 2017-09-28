#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

//max time is N-1 if I have to go back
//tree's diameter is the longest path
//clean subtrees that do not have restaurants
//every leaf node needs to be a restaurant.
//do a dfs to construct new adjacency list without the irrelevant nodes.
//find the new tree's diameter
//the answer is 2*E-diameter
vi tree[100000], pruned[100000];
bool is[100000], nV[100000], v[100000];
int N, M, ok, a, b, maxH, ansV, sz, bDst, edges, bNode, pMask, mask, p[100000], height[100000];

void dfs2(int prev, int curr){
    //cout << curr << endl;
    nV[curr] = true;
    for(int node : tree[curr]){
        if(!nV[node]){
            dfs2(curr, node);
        }
    }
    if((is[curr] || !pruned[curr].empty())){
        //cout << curr << " is valid" << endl;
        if(prev != -1){
            edges++;
            pruned[curr].push_back(prev);
            pruned[prev].push_back(curr);
        }
    }
}

void dfs(int curr){
    sz++;
    curr[v] = true;
    for(int node : pruned[curr]){
        if(!v[node]){
            dfs(node);
        }
    }
    if(sz > maxH){
        maxH = sz;
        ansV = curr;
    }
    sz--;
}

int main(){
    scanf("%d %d", &N, &M);
    memset(is, false, sizeof(is));
    memset(height, 0, sizeof(height));
    for(int i = 0; i < M; i++){
        scanf("%d", &ok);
        is[ok] = true;
    }
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        tree[a].push_back(b); 
        tree[b].push_back(a);
    }
    dfs2(-1, ok);
    //for(int i = 0; i < N; i++) printf("%d: %d\n", i, p[i]);
    /*
    for(int i =0; i < N; i++){
        printf("%d: ", i);
        for(int n : pruned[i]) printf("%d, ", n);
        cout << endl;
    }
    */
    memset(v, false, sizeof(v)); sz = 0; maxH = -1; ansV = -1;
    dfs(ok);
    memset(v, false, sizeof(v)); sz = 0;
    dfs(ansV);
    maxH--;
    edges *= 2;
    cout << edges -maxH << endl;

    return 0;
}