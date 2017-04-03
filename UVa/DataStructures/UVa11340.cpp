#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int N, K, t, M;
unsigned char ch;
string line;
map<char, int> mp;
long long total;

int main(){
    cin >> N;
    for(int n = 1; n <= N; n){
        mp.clear();
        total = 0;
        scanf(" %d", &K);
        for(int i = 0; i < K; i++){
            cin >> ch >> t;
            cin.ignore();
            mp[ch] = t;
        }
        scanf(" %d", &M);
        cin.ignore();
        for(int i = 0; i < M; i++){
            getline(cin, line);
            for(int i = 0; i <= line.length(); i++){
                if(mp.find(line[i]) != mp.end()) total += mp[line[i]];
            }
        }
        printf("%.2f$\n", total/100.0);
    }
    return 0;
}
