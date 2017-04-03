#include <bits/stdc++.h>
using  namespace std;
typedef pair<int, int> ii;
int N, K, t;
long long total = 0, l = 0;
deque<ii> minQ, maxQ;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &t);
        while(!maxQ.empty() && maxQ.back().first > t) maxQ.pop_back();
        while(!minQ.empty() && minQ.back().first < t) minQ.pop_back();
        maxQ.push_back(ii(t, i));
        minQ.push_back(ii(t, i));
        while(!maxQ.empty() && !minQ.empty() && abs(maxQ.front().first-minQ.front().first) > K){
            if(l == maxQ.front().second){
                maxQ.pop_front();
            }if(l == minQ.front().second) minQ.pop_front();
                l++;
        }
        total += i-l+1;
    }
    cout << total;
    return 0;
}
