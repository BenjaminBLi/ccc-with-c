#include <bits/stdc++.h>
using namespace std;

int N, dist;
string dir;

int main(){

    getline(cin, dir);
    scanf(" %d", &dist);
    if(dir.compare("Infront")){
        N -= dist;
    }else
        N += dist;

    cout << N;
    return 0;
}
