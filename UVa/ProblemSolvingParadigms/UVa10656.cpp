#include <bits/stdc++.h>
#define MAX 1000
#define fori(i, n) for(int i = 0, _n = n; i < _n; i++)
using namespace std;

int N, arr[MAX];
bool allneg;
int main(){
    while(scanf("%d", &N) && N){
        fori(i, N) scanf("%d", &arr[i]);
        bool notZ = false;
        fori(i, N){
            if(arr[i]){
                if(notZ) printf(" ");
                notZ = true;
                printf("%d", arr[i]);
            }
        }
        if(!notZ) printf("0");
        printf("\n");
    }
    return 0;
}
