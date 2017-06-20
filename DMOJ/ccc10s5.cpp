#include "bits/stdc++.h"
using namespace std;

int X, tree[20000], cIdx, memo[410][2510], memoL[410][2510], memoR[410][2510];
char curr;
string line;
void read(){
    curr = line[cIdx++];
    while(isspace(curr)) curr = line[cIdx++];
}
void build(int idx){
    read();
    if(isdigit(curr)){
        int val = curr - '0';
        for(curr = line[cIdx++]; isdigit(curr); curr = line[cIdx++]){
            val *= 10;
            val += curr-'0';
        }
        cIdx--;
        tree[idx] = val;
    }else if(curr == '('){
        build(idx*2);
        build(idx*2+1);
        read();
    }
}

void solve(int node){
    if(tree[node] == 0) {
        solve(node*2);
        solve(node*2+1);
        for (int i = 0; i <= X; i++)
            for (int j = 0; j <= i; j++)
                memoL[node][i] = max(memoL[node][i], min((1 + j) * (1 + j), memo[node * 2][i - j]));
        for (int i = 0; i <= X; i++)
            for (int j = 0; j <= i; j++)
                memoR[node][i] = max(memoR[node][i], min((1 + j) * (1 + j), memo[node * 2 + 1][i - j]));
        for (int i = 0; i <= X; i++)
            for (int j = 0; j <= i; j++)
                memo[node][i] = max(memo[node][i], memoL[node][j] + memoR[node][i-j]);
    }else{
        for(int i = 0; i <= X; i++) memo[node][i] = tree[node]+i;
    }
}

int main(){
    cIdx = 0;
    getline(cin, line);
    build(1);
    cin >> X;
    solve(1);
    cout << memo[1][X] << "\n";
    //for(int i = 0; i <= 50; i++) printf("%d, ", memo[i][X]);
    return 0;
}
