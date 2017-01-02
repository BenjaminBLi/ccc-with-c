#include <bits/stdc++.h>
using namespace std;

int Q, tmp;
string line, q;
vector<vector<int>> ids;
int main(){
    //freopen("in.txt", "r", stdin);
    cin >> line;
    ids.assign(256, vector<int>());
    for(int i = 0; i < line.size(); i++){
        ids[line[i]].push_back(i);
    }
    cin >> Q;
    for(int qi = 0; qi < Q; qi++){
        cin >> q;
        int s = -1, e = 0, tmpi; bool ok = true;
        for(int i = 0; i < q.size(); i++){
            tmp = q[i];
            vector<int>::iterator idx = upper_bound(ids[tmp].begin(), ids[tmp].end(), s);
            tmpi = idx - ids[tmp].begin();
            if(idx == ids[tmp].end()){ ok = false; break;}
            s = ids[tmp][tmpi];
            if(i == 0) e = s;
        }
        if(ok) printf("Matched %d %d\n", e, s);
        else printf("Not matched\n");
    }
    return 0;
}
