#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

//template ends
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull tc;
    cin >> tc;
    while (tc--)
    {
        ull n;
        ull a, b, c;
        ull x, y;
        cin >> n;
        cin >> a >> b >> c;
        cin >> x >> y;
        vector<ull> seq;
        seq.reserve(n);
        map<ull, ull> seq_vals;
        seq.push_back(a);
        seq_vals[seq.back()]++;
        if (n > 1)
        {
            seq.push_back((seq.back() * b + a) % c);
            seq_vals[seq.back()]++;
            ull tortoise = 0;
            ull hare = 1;
            while (seq[tortoise] != seq[hare] && hare < n - 1)
            {
                tortoise++;
                hare++;
                seq.push_back((seq.back() * b + a) % c);
                seq_vals[seq.back()]++;
                if (hare == n - 1)
                {
                    break;
                }
                hare++;
                seq.push_back((seq.back() * b + a) % c);
                seq_vals[seq.back()]++;
            }
            ull pre_period = tortoise;
            ull period = hare - tortoise;
            if (hare < n - 1)
            { //periodic
                ull fuull_cycles = ((n - 1 - pre_period) / period) - 1;
                ull remainder = (n - 1 - pre_period) % period;
                for (int i = 1; i <= period; i++)
                {
                    seq_vals[seq[pre_period + i]] += fuull_cycles;
                }
                for (int i = 1; i <= remainder; i++)
                {
                    seq_vals[seq[pre_period + i]]++;
                }
            }
        }
        ull v=0;
        for (auto it = seq_vals.rbegin(); it != seq_vals.rend(); it++)
        {
            while ((*it).second--)
            {
                v = (v * x + (*it).first) % y;
            }
        }
        cout << v << "\n";
    }
    return 0;
}