#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> shts;

//returns length of A-size paper
long double length(int size){
    return pow(2, 0.25 -0.5*size);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    int input;

    while(cin >> input){
        shts.push_back(input);
    }
    long double tape_used = 0;
    int amt_req = 2;
    for(int i = 0; i < shts.size(); i++){
        int size = i+2;
        int amt_left = amt_req - shts[i];
        tape_used += (amt_req/2)*length(size);
        if(amt_left > 0){
            amt_req = amt_left*2;
        }
        else{
            amt_req = 0;
            break;
        }
        tape_used -= (shts[i]/2)*length(size-1);
    }
    if(amt_req > 0){
        cout << "impossible" << "\n";
    }
    else{
        cout << tape_used << "\n";
    }
    return 0;
}