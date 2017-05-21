#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

unordered_map<ll, int> maxId, minId;
int N, M;

long long solveMax(int n, int m){
    if(n <= 0 || m <= 0) return 0;
    if(N < 2*M){
        if(M%2 == 0){
            //transition to (f(M, N-M/2)+1
        }
        if(N%2 == 0){
            //transition fo f(N, M-N/2)+1
        }
    }if(N == 2*M){
        return 1;
    }if(N > 2*M){
        //transition to (m, n%(2*M)) + n/(2m)
        if(M%2 == 0){
            int complete = N/(2*M)-1;
            int rem = (int) ceil((N%(2*M))*1.0/(M/2));
            int x = 2*M + (N%(2*M)) - rem;

        }
    }

}

int main(){
    scanf("%d %d", &N, &M);


    return 0;
}
