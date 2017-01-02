#include <bits/stdc++.h>
using namespace std;

struct person{
    int id, cnt, points;
};

vector<person> cntst;
bool comp(person a, person b){
    if(a.cnt == b.cnt){
        if(a.points == b.points){
            return a.id < b.id;
        }
        return a.points < b.points;
    }
    return a.cnt > b.cnt;
}

int T = 0, a, b, p[100][9], solved[100];
bool ac[100][9], att[100];
char ch;


int main(){
    //freopen("in258.txt", "r", stdin);
    string line;
    stringstream ss;
    getline(cin, line);
    ss.clear();
    ss << line;
    ss >> T;
    getline(cin, line);
    while(T--){
        cntst.clear(); ss.clear();
        memset(p, 0, sizeof(p)); memset(solved, 0, sizeof(solved));
        memset(ac, false, sizeof(ac)); memset(att, false, sizeof(att));
        while(getline(cin, line)){
            //cout << line << endl;
            if(line.empty()) break;
            int a, b, c;
            ss.clear();
            ss << line;
            ss >> a >> b >> c >> ch;
            a--;
            b--;
            att[a] = true;
            if(ch == 'I' && !ac[a][b]){
                p[a][b] += 20;
                //printf("%d %d %d %c\n", a+1, b+1, c, ch);
            }else if (ch == 'C' && !ac[a][b]){
                ac[a][b] = true;
                solved[a]++;
                p[a][b] += c;
            }
            ss.clear();
        }
        for(int i = 0 ; i < 100; i++){
            if(att[i]){
                person pp;
                pp.id = i+1;
                pp.cnt = solved[i];
                pp.points = 0;
                for(int j = 0; j < 9; j++)
                    if(ac[i][j])
                        pp.points += p[i][j];

                cntst.push_back(pp);
            }
        }
        sort(cntst.begin(), cntst.end(), comp);
        for(auto it : cntst) printf("%d %d %d\n", it.id, it.cnt, it.points);
        if(T) printf("\n");
        ss.clear();
        cntst.clear();
    }
    return 0;
}
