#include <bits/stdc++.h>
using namespace std;

int N, A[100001], B[100001];
char S[100001];

void step(int k){
    int l=(1LL<<k)%N;
    int r=(N-l)%N;

    for(int i = 0; i < N; i++) B[i] = A[(i+l)%N]^A[(i+r)%N];


    for(int i =0; i < N; i++){
        A[i] = B[i];
    }
}

int main(){
    long long T;
    scanf("%d %lld", &N, &T);
    scanf("%s", S);
    for(int i = N-1; i >= 0; i--) A[i] = S[i]-'0';
    
    for(int i = 60; i >= 0; i--) if(T&(1LL<<i))
        step(i);
    
    for(int i = 0; i < N; i++) printf("%d", A[i]);
    printf("\n");
    return 0;
}
