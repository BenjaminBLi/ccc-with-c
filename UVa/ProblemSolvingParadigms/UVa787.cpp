#include <bits/stdc++.h>
using namespace std;

int arr[100], t, cnt;
string line;
stringstream ss;

int main(){
    freopen("in.txt", "r", stdin);
    while(scanf("%d", &t) != EOF){
        arr[0] = t; cnt = 1;
        while(scanf("%d", &t) && t != -999999)
            arr[cnt++] = t;
        for(int i = 0; i < cnt; i++) printf(" %d", arr[i]);
        cout << endl;
    }
    return 0;
}
