#include <iostream>
#include <string>
#include <vector>
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
typedef unsigned long long int ull;
typedef long double ld;
//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    const int INF = 1e9;
    while (cin >> n)
    {
        vi nums(n);
        vi d(n+1,INF);
        vi p(n+1,-1);
        d[0] = -INF;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            int j = upper_bound(d.begin(), d.end(), nums[i]) - d.begin();
            if (d[j - 1] < nums[i] && nums[i] < d[j])
            {
                p[j-1] = i;
                d[j] = nums[i];
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (d[i] < INF)
                ans = i;
        }
        vi indices;
        indices.push_back(ans);
        for(int i = ans; p[i] != 0; i++){
            indices.push_back(p[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}