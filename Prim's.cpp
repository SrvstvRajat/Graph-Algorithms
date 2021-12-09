/*--------------------------------------------------------♆-😈-Devil-😈-♆-----------------------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
#define ll long long
#define lld long long double
#define ull unsigned long long
#define PI 3.14159265
#define MOD 1000000007
#define FASITO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define pb(x) push_back(x)
#define nl "\n"
#define sz size
#define ff first
#define ss second
#define mp make_pair
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define ump unordered_map
using namespace std;

void init()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void google(int t) {cout << "Case #" << t << ": ";}

string upper(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second);}
ll modInverse(ll a, ll m) {ll m0 = m; ll y = 0, x = 1; if (m == 1)return 0; while (a > 1) { ll q = a / m; ll t = m; m = a % m, a = t; t = y; y = x - q * y; x = t;} if (x < 0)x += m0; return x;}
set<int> primeFactors(int n) {set<int> s; while (n % 2 == 0) { s.insert(2); n = n / 2; } for (int i = 3; i <= sqrt(n); i = i + 2) {  while (n % i == 0) {s.insert(i); n = n / i; } } if (n > 2) s.insert(n); return s;}
void sort(string &s) { sort(s.begin(), s.end()); }


int main()
{
    init();
    FASITO;
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>>adj[n];
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    int par[n];
    bool vis[n];
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
        dis[i] = INT_MAX;
    }
    par[0] = -1;
    pq.push({0, 0});
    for (int j = 0; j < n - 1; j++)
    {
        int k = pq.top().ss;
        pq.pop();
        vis[k] = true;
        for (auto i : adj[k])
        {
            int v = i.ff;
            int wei = i.ss;
            if (vis[v] == false && wei < dis[v])
            {
                par[i.ff] = k;
                dis[v] = wei;
                pq.push({wei, v});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << par[i] << " " << i << nl;
    }


}
