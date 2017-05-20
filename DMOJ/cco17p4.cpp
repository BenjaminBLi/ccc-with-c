#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int p[510], memo[2][25010], N;
bool seen[251];

bool comp(int a, int b){
    return a > b;
}

int main(){
    scanf("%d", &N);
    for(int i= 0; i<N; i++) scanf("%d", p+i);
    sort(p, p+N, comp);
    //for(int i = 0; i < N; i++) printf("%d, ", p[i]);

    memo[1][0] = 1;
    int maxH = N*p[0];
    seen[p[1]] = true;
    for(int i = 2; i < N; i++){
        //cout << p[i] << endl;
        seen[p[i]] = true;
        int pre = (i-1)&1;
        int curr = i&1;
        memset(memo[curr], 0, sizeof(memo[curr]));
        for(int j = 0; j <= maxH; j++) memo[curr][j] = memo[pre][j];
        //for(int j = 0; j < maxH; j++) printf("%d, ", memo[curr][j]); cout << endl;
        for(int j = 50; j > p[i]; j--){
            if(!seen[j]) continue;
            int diff = j-p[i];
            //cout << diff << endl;
            for(int k = diff; k <= maxH; k++){
                memo[curr][k] |= memo[pre][k-diff];
            }
        }
        //for(int j = 0; j < maxH; j++) printf("%d, ", memo[curr][j]); cout << endl; cout << endl;
    }

    for(int i = 0; i <= maxH; i++) if(memo[(N-1)&1][i]) printf("%d ", i);


    return 0;
}
