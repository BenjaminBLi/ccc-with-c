#include <bits/stdc++.h>
using namespace std;
int n, m, t, c, tt, aT[10004], lT[10004];
string pos;

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &c);
    for(; c--;){
        memset(aT, 0, sizeof(aT));
        memset(lT, 0, sizeof(aT));
        queue<int> cars[2];
        cin >> n >> t >> m;
        for(int i = 0; i < m; i++){
            cin >> tt >> pos;
            aT[i] = tt;
            if(pos == "left") cars[0].push(i);
            else cars[1].push(i);
        }
        int time = 0, loc = 0;
        while(!cars[0].empty() || !cars[1].empty()){
            int next = cars[0].empty() ? aT[cars[1].front()] :
                       cars[1].empty() ? aT[cars[0].front()] :
                       min(aT[cars[0].front()], aT[cars[1].front()]);
            time = max(time, next);
            int cnt = 0;
            while(!cars[loc].empty() && aT[cars[loc].front()] <= time && cnt < n){
                lT[cars[loc].front()] = time + t;
                cars[loc].pop();
                cnt++;
            }

            loc = (loc+1)&1;
            time += t;
            //cout << time << endl;
        }
        for(int i = 0; i < m; i++) cout << lT[i] << endl;
        if(c) cout << endl;
    }
    return 0;
}
