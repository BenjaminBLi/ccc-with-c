#include <bit/stdc++.h>
using namespace std;
typedef vector<int> vi;

unordered_map<string, int> id;
vi adj[100];
int N, cnt;
string line;

int main(){
	scanf("%d", &N);
	for(int n = 0; n < N; n++){
		getline(cin, line);
		if(id.count(line) == string::npos) id[line] = cnt++;
		getline(cin, line);
		while(line.find("</HTML>") == line.end()){
			
			getline(cin, line);
		}

	}

}