#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int s;
string line = "**********************************************************************";
vi values;
set<set<int>> combos;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    values.push_back(0);
    for(int i = 1; i <= 20; i++){
        values.push_back(i);
        values.push_back(i+i);
        values.push_back(i+i+i);
    }
    values.push_back(50);
    sort(values.begin(), values.end());
    //for(int i = 0; i < 62; i++) cout << values[i] << endl;
    while(scanf("%d", &s) && s > 0){
        combos.clear();
        for(int i = 0; i < values.size() && values[i] <= s; i++){
            for(int j = 0; j < values.size() && values[j] <= s-values[i]; j++){
                for(int k = 0; k < values.size() && values[k] <= s-values[i]-values[j]; k++){
                    if(values[i]+values[j]+values[k] != s) continue;
                    set<int> combo;
                    combo.insert(values[i]); combo.insert(values[j]); combo.insert(values[k]);
                    combos.insert(combo);
                }
            }
        }
        if(combos.size() > 0){
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", s, combos.size());
            int perms = 0;
            for(auto c : combos){
                if(c.size() == 1) perms += 1;
                else if (c.size() == 2) perms += 3;
                else perms += 6;
            }
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", s, perms);
        }else{
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", s);
        }
        cout << line << endl;
    }
    printf("END OF OUTPUT\n");
    return 0;
}
