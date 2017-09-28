#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/*
11
1 2
1 3
3 11
3 9
9 10
2 4
4 5
4 8
5 7
5 6
-30 12 0 -50 21 2 51 -7 34 15 27

            .        +          .      .          .
     .            _        .                    .
  ,              /;-._,-.____        ,-----.__
 ((        .    (_:#::_.:::. `-._   /:, /-._, `._,
  `                 \   _|`"=:_::.`.);  \ __/ /
                      ,    `./  \:. `.   )==-'  .
    .      ., ,-=-.  ,\, +#./`   \:.  / /           .
.           \/:/`-' , ,\ '` ` `   ): , /_  -o
       .    /:+- - + +- : :- + + -:'  /(o-) \)     .
  .      ,=':  \    ` `/` ' , , ,:' `'--".--"---._/`7
   `.   (    \: \,-._` ` + '\, ,"   _,--._,---":.__/
              \:  `  X` _| _,\/'   .-'
.               ":._:`\____  /:'  /      .           .
                    \::.  :\/:'  /              +
   .                 `.:.  /:'  }      .
           .           ):_(:;   \           .
                      /:. _/ ,  |
                   . (|::.     ,`                  .
     .                |::.    {\
                      |::.\  \ `.
                      |:::(\    |
              O       |:::/{ }  |                  (o
               )  ___/#\::`/ (O "==._____   O, (O  /`
          ~~~w/w~"~~,\` `:/,-(~`"~~~~~~~~"~o~\~/~w|/~
      ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\|/~~
*/
int N, sum[400010], p[400010];
vi adj[400010];
bool visited[400010];
int main(){
	//TREEEEE
	scanf("%d", &N);
	memset(p, -1, sizeof(p));
	for(int i = 1;i < N; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		p[v] = u;
		adj[u].push_back(v);

	}
	for(int i = 1; i<= N; i++) {
		scanf("%d", sum+i);
	}

	stack<int> q;
	q.push(1);
	bool flag;
	while(!q.empty()){
		flag = false;
		int u = q.top();
		//cout << u << endl;
		visited[u] = true;
		for(int v : adj[u]){
			if(!visited[v]){
				q.push(v);
				flag = true;
				break;
			}
		}
		if(!flag){
			sum[p[u]] += sum[u];
			if(!q.empty())q.pop();
		}
	}
	//for(int i = 1; i <= N; i++) printf("%d, ", sum[i]); cout << endl;
	int best = -1000*400000;
	//cout << best << endl;
	for(int i = 1; i <= N; i++){
		best = max(best, sum[i]);
	}
	cout << best << endl;
	return 0;
}