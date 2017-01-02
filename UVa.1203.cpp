#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, pair<int, int>>,
			 vector<pair<int, pair<int, int>>>,
			greater<pair<int, pair<int, int>>>>  q;
string t;
int id, p, K;
int main(){
    //freopen("in.txt", "r", stdin);
    cin >> t;
    while(t != "#"){
        cin >> id >> p;
        q.push(pair<int, pair<int, int>> (p, pair<int, int>(id, p)));
        cin >> t;
    }
    scanf("%d", &K);
    while(K--){
        pair<int, pair<int, int>> curr = q.top();
        q.pop();
        cout << curr.second.first << endl;
        curr.first += curr.second.second;
        q.push(curr);
    }
    return 0;
}
