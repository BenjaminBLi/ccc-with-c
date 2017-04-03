#include <bits/stdc++.h>
using namespace std;

int t, n, M[20][20];

int main(){
    scanf("%d", &t);
    for(;t--;){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &M[i][j]);
        int won = 0, turn  = 0;
        int choice[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        int best = 1<<30;
        do{
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += M[i][choice[i]];
            }
            best = min(best, sum);
        }while(next_permutation(choice, choice+n));
        printf("%d\n", best);
    }
    return 0;
}
