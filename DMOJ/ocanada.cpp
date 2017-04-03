#include <bits/stdc++.h>
using namespace std;
int N, G;
char t;
bool box[10][10];
map<int, int> cnt;

int main() {
	scanf("%d %d", &N, &G);
    for(int n = 1; n <= G; n++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf(" %c", &t);
                box[i][j] = t == 'R';
            }
        }
        for(int i = 0; i < N-1; i++){
            for(int j = 0; j < N-1; j++){
                if(box[i][j]){
                    box[i][j] = !box[i][j];
                    box[i+1][j] = !box[i+1][j];
                    box[i][j+1] = !box[i][j+1];
                    box[i+1][j+1] = !box[i+1][j+1];
                }
            }
        }
        int key = 0;
        int cntr = 0;
        for(int i = 0; i < N; i++){
            key += box[N-1][i]<<cntr++;
        }
        for(int i = N-2; i >= 0; i--){
            key += box[i][N-1]<<cntr++;
        }
        if(cnt.find(key) != cnt.end()) cnt[key]++;
        else cnt[key] = 1;
    }
    long long tot = 0;
    for(auto it : cnt)
        tot += it.second*(it.second-1)/2;

    printf("%lld", tot);
	return 0;
}
