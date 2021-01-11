#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
void printPicture(vector<string> picture, int y, int x, int k){
    int picX = x-1; //0 indexed
    int picY= y-1;
    int offset = k-1;
    for(int i=0; i<k; i++){
        picture[picY][picX-i] = '-';
        picture[picY-i][picX] = '|';
        picture[picY-offset][picX-i] = '-';
        picture[picY-i][picX-offset] = '|';
    }
    picture[picY][picX] = '+';
    picture[picY-offset][picX] = '+';
    picture[picY][picX-offset] = '+';
    picture[picY-offset][picX-offset] = '+';
    for(auto i:picture){
        cout << i << "\n" << flush;
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, s, k;
    cin >> r >> s >> k;
    vector<vector<int>> prefix(r+1, vector<int>(s+1,0)); //1-indexed
    vector<string> picture;
    string input;
    while(cin >> input){
        picture.push_back(input);
    }
    for(int i = 1; i < r+1; i++){
        for(int j = 1; j < s+1; j++){
            prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
            if(picture[i-1][j-1] == '*'){
                prefix[i][j]++;
            }
        }
    }
    // find bottom right corner that gives best flies killed
    int bestVal = 0, bestX, bestY;
    for(int i = k; i<r+1; i++){
        for(int j = k; j<s+1; j++){
            int testVal = prefix[i-1][j-1] + prefix[i-1-(k-2)][j-1-(k-2)] - prefix[i-1][j-1-(k-2)] -prefix[i-1-(k-2)][j-1];
            if(testVal>bestVal){
                bestVal=testVal;
                bestY = i;
                bestX = j;
            }
        }
    }
    cout << bestVal << "\n";
    printPicture(picture, bestY, bestX, k);
    return 0;
}