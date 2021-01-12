#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int i = 1;
    int old_test = 999999;
    while(true){
        int test = ((n%(1 << i)+n)/(1 <<i )) + i;
        if(test < old_test){
            old_test = test;
            i++;
        }
        else{
            break;
        }
    }
    cout << old_test;
    return 0;
}