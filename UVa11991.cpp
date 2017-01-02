#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

map<int, vi> mp;
int n, m, k, v, t, arr[1000000];
int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 1;i <= n; i++){
            scanf("%d", &arr[i]);
            if(mp.find(arr[i]) == mp.end()){
                vi tmp;
                mp[arr[i]] = tmp;
                mp[arr[i]].push_back(i);
            }else mp[arr[i]].push_back(i);
        }
        for(int q = 0; q < m; q++){
            scanf("%d %d", &k, &v);
            k--;
            if(mp.find(v) == mp.end() || k >= mp[v].size()) printf("%d\n", 0);
            else{
                printf("%d\n", mp[v][k]);
            }
        }
    }
    return 0;
}
