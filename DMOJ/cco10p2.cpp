#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

int N, D, cols[310], white, black;
vi adj[310];
ii memo[310][310];

int main(){
    scanf("%d %d", &N, &D);
    white = black = 0;
    for(int i = 0; i < N; i++){
        int C, id, col;
        scanf("%d %d %d %d", &id, &col, &C);
        if(col) white++;
        else black++;
        for(int i = 0; i < C; i++){
            int ch;
            scanf("%d", &ch);
            adj[i].push_back(ch);
        }
    }
    int ans = 0;
    for(int i = 0; i <= N; i++){

    }

    return 0;
}
