#include <bits/stdc++.h>
using namespace std;


int n, t;

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) && n){
        priority_queue<int, vector<int>, greater<int>> mq;
        for(int i = 0;i < n; i++){scanf("%d", &t); mq.push(t);}
        long long cost = 0;
        int total = 0;
        while(mq.size() > 1){
            total = mq.top(); mq.pop();
            total += mq.top(); mq.pop();
            cost += total;
            mq.push(total);
        }
        cout << cost << endl;
    }
    return 0;
}
