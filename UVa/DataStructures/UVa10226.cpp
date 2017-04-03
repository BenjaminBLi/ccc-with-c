#include <bits/stdc++.h>
using namespace std;

string line;
int t;
map<string, int> m;

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d\n\n", &t);
    for(;t--;){
        int total = 0;
        m.clear();
        total = 0;
        while(getline(cin, line)){
            //cout << line << endl;
            if(line.empty()) break;
            if(m.find(line) == m.end()) m[line] = 1;
            else m[line]++;
            total++;
        }
       //cout << total << endl;
        for(auto it : m){
            cout << it.first;
            printf(" %.04lf\n", (double) it.second/ (double) total *100.0);
        }
        if(t) cout << endl;
    }
    return 0;
}
