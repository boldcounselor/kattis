#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;

//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vii ranges(N);
    int a, b;
    int mei = 0;//mutually exclusive intervals
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        ranges[i] = {a, b};
    }
    sort(ranges.begin(), ranges.end(), [](auto &left, auto&right){return left.first < right.first;});
    stack<pii> range_stack;
    //figure out how to access fro m1 onwards
    //figure out how overlapping interval merge works
    range_stack.push(*ranges.begin());
    for(vii::iterator it = ++ranges.begin(); it != ranges.end(); it++){
        if((*it).first <= range_stack.top().second | (*it).second <= range_stack.top().first){
            if(range_stack.top().second < (*it).second){
                range_stack.top().second = (*it).second;
            }
        }
        else{
            range_stack.push((*it));
        }
    }
    cout << range_stack.size();
    return 0;
}