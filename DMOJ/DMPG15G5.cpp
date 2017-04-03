#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int N, R, c1, ca, cb, cm, v1, va, vb, vm;

priority_queue<int, vi, greater<int>> pq[2111];
long long memo[2111], bonus;
int main(){
    scanf("%d %d", &N, &R);
    int E;
    bonus = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &E);
        scanf("%d %d %d %d %d %d %d %d", &c1, &v1, &ca, &cb, &cm, &va, &vb, &vm);
        if(c1 == 0) bonus += v1;
        else if(c1 <= R){
            pq[c1].push(v1);
            if(pq[c1].size()*c1 > R) pq[c1].pop();
        }
        
        for(int j = 1; j < E; j++){
            c1 = (1LL*c1*ca+cb)%cm;
            v1 = (1LL*v1*va+vb)%vm;
            if(c1 == 0) bonus += v1;
            else if(c1 <= R){
                pq[c1].push(v1);
                if(pq[c1].size()*c1 > R) pq[c1].pop();
            }
        }
    }
    memset(memo, 0, sizeof(memo));
    int curr;
    for(int i = 1; i <= R; i++){
        while(!pq[i].empty()){
            curr = pq[i].top(); pq[i].pop();
            for(int j = R; j >= 0; j--){
                if(j-i>= 0){
                    memo[j] = max(memo[j], memo[j-i]+curr);
                }
            }
        }
    }
    cout << memo[R]+bonus << endl;
    return 0;
}
