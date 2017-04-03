#include <algorithm>
#include <cstdio>
using namespace std;
int N, M, arr[500][500], Q, L, U;

int main(){
    for(;;){
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0) break;
        for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) scanf("%d", &arr[i][j]);
        scanf("%d", &Q);
        for(int q = 0; q < Q; q++){
            scanf("%d %d", &L, &U);
            int cMax = 0;
            for(int i = 0; i < N; i++){
                int* lb = lower_bound(arr[i], arr[i]+M, L);
                int minIdx = lb-arr[i];
                for(int j = cMax; j < N; j++){
                    if(i+j >= N || minIdx+j >= M || arr[i+j][minIdx+j] > U) break;
                    if(j+1 > cMax) cMax = j+1;
                }
            }
            printf("%d\n", cMax);
        }
        printf("-\n");
    }
    return 0;
}
