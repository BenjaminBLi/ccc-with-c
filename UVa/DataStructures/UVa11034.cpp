#include <bits/stdc++.h>
using namespace std;

int c, l, m;

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &c);
    for(;c--;){
        scanf("%d %d", &l, &m);
        l *= 100;
        queue<int> q[2];
        for(int i = 0; i < m; i++){
            int tL;
            string dir;
            cin >> tL >> dir;
            if(dir == "left") q[0].push(tL);
            else q[1].push(tL);
        }
        int loc = 0, cnt = 0;
        while(!q[0].empty() || !q[1].empty()){
            int cL = 0;
            for(; !q[loc].empty() && cL < l;){
                if(q[loc].front() + cL <= l){
                    cL += q[loc].front();
                    q[loc].pop();
                }else break;
            }
            cnt++;
            loc = (loc+1)&1;
        }
        cout << cnt << endl;
    }
    return 0;
}
