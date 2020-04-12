#include <bits/stdc++.h>
#include <string>
using namespace std;
//Credit goes to Steven Halim. This is extracted from his book "Competitive Programming 3".
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, string> words;
    unordered_map<int, vector<int>> cookbook;
    for(int i=1; i<=n; i++){
        string word;
        cin >> word;
        vector<int> bake(1,i);
        cookbook.insert({i,bake});
        words.insert({i,word});
    }
    int a, b;
    while(cin >> a >> b){
        cookbook[a].insert(cookbook[a].end(),cookbook[b].begin(),cookbook[b].end());
        cookbook.erase(b);
    }
    for(auto& [key, value] : cookbook){
        if(!value.empty()){
            for(auto ingredient : value){
                cout << words[ingredient];
            }
            cout << "\n";
        }
    }
    return 0;
}