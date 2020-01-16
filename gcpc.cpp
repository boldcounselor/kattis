#include <bits/stdc++.h>
using namespace std;
struct team{
    int number, solved, penalty;

    team(int number){
        this->number = number;
        solved=0; penalty=0;
    }

    friend bool operator<(team a, team b){
        if(a.solved>b.solved){
            return true;
        }
        else if (a.solved==b.solved && a.penalty<b.penalty{
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
    int n, m;
    cin >> n >> m;
    set<team> leaderboard;
    for(n--)
        leaderboard.insert(team dui(n));
    }
    while(m--){
        int t, p;
        cin >> t >> p;
        leaderboard[t].solved++;
        leaderboard[t].penalty+=p;
    }
}