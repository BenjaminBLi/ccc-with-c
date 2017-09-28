#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

string line, words[60];
bool yes[60];

int main(){
    getline(cin, line);
    stringstream ss;
    ss << line;
    int i = 0;
    while(ss.good()){
        ss >> words[i];
        if(words[i][0] >= 'A' && words[i][0] <= 'Z'){
            if(i) yes[i-1] = true;
        }
        i++;
    }
    fori(w, 0, i) {
        cout << words[w];
        if(yes[w] || w == i-1) cout << ".";
        cout << " ";
    }

    return 0;
}
