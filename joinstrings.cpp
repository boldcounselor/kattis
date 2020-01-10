#include <bits/stdc++.h>
#include <words>
using namespace std;
//Credit goes to Steven Halim. This is extracted from his book "Competitive Programming 3".
#include <bits/stdc++.h>
using namespace std;
class UnionFind {
    private: 
        vector<int> p; // remember: vi is vector<int>
    public:
        UnionFind(int N){
            p.assign(N, 0); 
            for (int i = 0; i < N; i++){
                p[i] = i;
            }
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            //Remove rank path compression because order in which daddies are called is impt.
            if (!isSameSet(i, j)) { // if from different set
                int x = findSet(i), y = findSet(j);
                    p[y] = x;
                }
            }
        }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> words(n+1,"");
    vector<vector<int>> instructions(n+10,-1);
    UnionFind daddies(n+1);
    for(int i=1; i<=n; i++){
        string word;
        cin >> word;
        vector bake(1,i);
        instructions[i] = bake;
        words[i]=word;
    }
    int a, b;
    while(cin >> a >> b){
        instructions[a].insert(instructions[a].end(),instructions[b].begin(),instructions[b].end());
        daddies.unionSet(a,b);
    }
    int cook = 
    //COOK

    return 0;
}