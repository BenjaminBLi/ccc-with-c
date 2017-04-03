#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
using namespace std;

int N, T, W[2000][3], V[2000][3], memo[10001];

int main(){
    //knapsack, but with 3 values per thing
    scanf("%d %d", &N, &T);
    fori(i, N) fori(j, 3) scanf("%d %d", &W[i][j], &V[i][j]);

    fori(i, N){
        for(int j = T; j >= 0; j--){
            fori(k, 3){
                if(j-W[i][k] >= 0){
                    memo[j] = max(memo[j], memo[j-W[i][k]]+V[i][k]);
                }
            }
        }
    }
    cout << memo[T] << endl;
    return 0;