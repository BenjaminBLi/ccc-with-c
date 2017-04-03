#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
int t, acorns, trees;
string line;
bool visited[26];
queue<int> q;
vi lst[26];
map<char, int> m;
int bfs(int si){
    int cnt = 0;
    q.push(si);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        //cout << curr << endl;
        cnt++;
        visited[curr] = true;
        for(int node : lst[curr]){
            if(!visited[node]) q.push(node);
        }
    }
    //cout << endl;
    return cnt;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--){
        m.clear();
        int idx = 0;
        memset(visited, false, sizeof(visited));
        for(int i = 0;i < 26; i++){
            lst[i].clear();
        }
        while(cin >> line && line[0] != '*'){
            if(m.find(line[1]) == m.end()){
                m[line[1]] = idx++;
                //printf("%c %d\n", line[1], m[line[1]]);
            }
            if(m.find(line[3]) == m.end()){
                m[line[3]] = idx++;
                //printf("%d %d\n", line[3], m[line[3]]);
            }
            lst[m[line[1]]].push_back(m[line[3]]);
            lst[m[line[3]]].push_back(m[line[1]]);
        }
        cin >> line;
        for(int i = 0; i < line.length(); i+=2)
            if(m.find(line[i]) == m.end()) m[line[i]] = idx++;
        acorns = trees = 0;
        //cout << idx << endl << endl;
        for(int i = 0; i < idx; i++){
            if(!visited[i]){
                int c = bfs(i);
                if(c == 1) acorns++;
                else trees++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }

    return 0;
}
