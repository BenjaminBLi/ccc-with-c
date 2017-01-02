#include <bits/stdc++.h>
using namespace std;

string line;

int main(){
    getline(cin, line);
    while(line.compare("#") != 0){
        if(next_permutation(line.begin(), line.end())) cout << line << "\n";
        else cout << "No Successor\n";
        getline(cin, line);
    }

    return 0;
}
