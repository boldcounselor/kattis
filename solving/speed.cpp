#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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
typedef long double ld;
//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ld t;
    cin >> n >> t;
    ld period = t/n;
    ld d = 0;
    ld s = 0;
    while(n--){
        ld a, b;
        cin >> a >> b;
        d += a;
        s += period*b;
    }
    ld avg_spd = d/t;
    ld off_spd = s/t;
    cout << setprecision(15);
    cout << avg_spd - off_spd;
    return 0;
}