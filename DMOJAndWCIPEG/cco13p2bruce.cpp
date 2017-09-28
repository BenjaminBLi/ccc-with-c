#include <bits/stdc++.h>
using namespace std;
int N, M, K, x, y; pair<int, int> t[1<<21]; char op;
int main(){
    cin >> N >> M;
    N = 1<<N; K = N-1;
    for(int i=1; i<=N; i++){
        cin >> t[K+i].first;
        t[K+i].second = i;
    }
    for(int i=K; i>=1; i--)
        t[i] = max(t[2*i], t[2*i+1]);
    while(M--){
        cin >> op;
        if(op == 'W') cout << t[1].second << endl;
        else if(op == 'R'){
            cin >> x >> y;
            t[K+x].first = y;
            for(int i=(K+x)/2; i>=1; i/=2)
                t[i] = max(t[2*i], t[2*i+1]);
        }else{
            cin >> x;
            int cnt =0;
            for(int i=(K+x)/2; i>=1; i/=2)
                if(t[i]==t[K+x]) cnt++;
                else break;
            cout << cnt << endl;
        }
    }
} 