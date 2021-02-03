#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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

class UnionFind
{ // OOP style
private:
    vi p, rank, setSize; // vi p is the key part
    int numSets;
    map<int, unordered_set<int>> children;

public:
    UnionFind(int N)
    {
        p.assign(N + 1, 0);
        for (int i = 1; i < N + 1; ++i)
            p[i] = i;
        rank.assign(N, 0);    // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N;          // optional feature
    }

    int findSet(int i)
    {
        if (p[i] == i)
        {
            return i;
        }
        else
        {
            children[p[i]].erase(i);
            p[i] = findSet(p[i]);
            children[p[i]].insert(i);
            return p[i];
        }
    }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }            // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
    void moveToSet(int a, int b){
        for(auto i : children[a]){
            p[i] = p[a];
            children[p[a]].insert(i);
            children[a].erase(i);
        }
        p[a] = b;
        children[b].insert(a);
    }
    unordered_set<int> returnSet(int a){
        int root = findSet(a);

    }
    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;                         // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y])
            swap(x, y);        // keep x 'shorter' than y
        p[x] = y;              // set x under y
        children[y].insert(x); //add x under y;
        if (rank[x] == rank[y])
            ++rank[y];            // optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        --numSets;                // a union reduces numSets
    }
};
//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    UnionFind ufds(n);
    while (m--)
    {
        int cm;
        cin >> cm;
        if (cm == 1)
        {
            int a, b;
            cin >> a >> b;
            ufds.unionSet(a, b);
        }
        else if (cm == 2)
        {
        }
        else if (cm == 3)
        {
        }
    }
    return 0;
}