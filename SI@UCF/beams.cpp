#include <bits/stdc++.h>
using namespace std;

string line;

int main(){
    cin >> line;
    int sz = line.size();
    stack<char> dq;
    int cnt = 0;
    for(char c : line){
        if(dq.size()) {
            if (dq.top() == c) {
                cnt++;
                dq.pop();
            } else {
                dq.push(c);
            }
        }else{
            dq.push(c);
        }
    }
    if((dq.size()))
        cnt += (dq.size()-1) >> 1;

    cout << cnt << endl;

    return 0;
}
