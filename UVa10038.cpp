#include <bits/stdc++.h>
using namespace std;

int n, arr[3000];

bool diffs[3001];

int main(){
    while(scanf("%d", &n) == 1){
        memset(diffs, false, sizeof(diffs));
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        bool jolly = true;
        for(int i = 1; i < n; i++){
            diffs[abs(arr[i]-arr[i-1])] = true;
        }
        for(int i = 1; i < n; i++) jolly &= diffs[i];
        if(jolly) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
    return 0;
}
