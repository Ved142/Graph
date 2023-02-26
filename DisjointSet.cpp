#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vll;
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mini(a, b, c) min(c, min(a, b))
#define minf(a, b, c, d) min(d, min(c, min(a, b)))
#define rfoi(n) for (int i = n - 1; i >= 0; i--)
#define rfoj(n) for (int j = n - 1; j >= 0; j--)
#define foi(n) for (int i = 0; i < n; i++)
#define foj(n) for (int j = 0; j < n; j++)
#define printv(v)     \
    for (auto it : v) \
        cout << it;
#define print(x) cout << x << endl;

#include <bits/stdc++.h>

using namespace std;

class DSU
{
public:
    vector<int> rank;
    vector<int> parent;
    DSU(int size)
    {
        for (int i = 0; i <= size; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findpar(parent[node]); // path compression
    }

    void _union(int u, int v)
    {
        int x = findpar(u);
        int y = findpar(v);
        if (rank[x] < rank[y])
        {
            parent[x] = y;
        }
        else if (rank[y] < rank[x])
        {
            parent[y] = x;
        }
        else
        {
            parent[y] = x;
            rank[x]++;
        }
    }

    // finding the number of components
    ll component()
    {
        ll count = 0;
        for (ll i = 1; i < parent.size() - 1; i++)
        {
            if (i == parent[i])
            {
                count++;
            }
        }

        return count;
    }
};

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a;
    vector<ll> b;
    for (ll i = 0; i < n; i++)
    {
        ll inp;
        cin >> inp;
        a.push_back(inp);
    }

    for (ll i = 0; i < n; i++)
    {
        ll inp;
        cin >> inp;
        b.push_back(inp);
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++)
    {
        adj[a[i]].pb(b[i]);
    }

    DSU d(n + 1);
    for (int i = 1; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            d._union(i, adj[i][j]);
        }
    }

    ll ans = d.component();
    cout << binpow(2, ans, mod) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}