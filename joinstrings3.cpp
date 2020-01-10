#include <bits/stdc++.h>
#include <string>
using namespace std;
//Credit goes to Steven Halim. This is extracted from his book "Competitive Programming 3".
vector<int> child;
vector<string> words;

void haier(int p, int c){
    if(child[p]==p){
        child[p]=c;
    }
    else{
        haier(child[p], c);
    }
}

void prRec(int p){
    if(child[p]==p){
        cout << words[p];
    }
    else{
        cout << words[p];
        prRec(child[p]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    child.resize(n+2);
    words.resize(n+2);
    for(int i=1; i<=n; i++){
        string word;
        cin >> word;
        words[i]=word;
        child[i]=i;
    }
    int a, b;
    while(cin >> a >> b){
        haier(a,b);
    }
    prRec(a);
    return 0;
}