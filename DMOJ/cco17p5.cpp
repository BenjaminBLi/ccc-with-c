#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int N;
vii vals;

bool comp(ii a, ii b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(){
    scanf("%d" ,&N);
    long long pts = 0;
    int bought = 0;
    for(int i = 0; i < N; i++) {
        ii curr;
        scanf("%d %d", &curr.first, &curr.second);
        if(curr.second == 0 || curr.first == 0) bought++;
        else vals.push_back(curr);
    }
    sort(vals.begin(), vals.end(), comp);
    int sz = (int) vals.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < sz; i++){
        ii curr = vals[i];
        pq.push(curr.second);
        if(curr.first > sz - i-1 + bought){
            bought++;
            pts += pq.top();pq.pop();
        }
    }

    cout << pts;
    return 0;
}
