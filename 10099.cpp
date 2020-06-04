//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;
const long long NINF = INT_MIN;

using namespace std;

//Global Variables
int dist[MX_N];
bool inQ[MX_N];
vector<pair<int, int> > adj[MX_N];
int mass[MX_N];
int s, d, t;

void SPFA(int N){
    queue<int> Q;
    Q.push(s);
    dist[s] = INT_MAX-100;
    while(!Q.empty()){
        int at = Q.front();
        Q.pop();
        inQ[at] = false;
        for(pair<int, int> temp : adj[at]){
            int to = temp.fi;
            int w = mass[temp.se];
            if(dist[to] < min(dist[at], w)){
                dist[to] = min(dist[at], w);
                if(!inQ[to]){
                    inQ[to] = true;
                    Q.push(to);
                }
            }
        }
    }
    return;
}

bool solve(int C){
    int n, m;
    cin >> n >> m;
    if(n==0 && m==0)
        return false;
    for(int i=0;i<n;++i){
        dist[i] = NINF;
        inQ[i] = false;
        adj[i] = {};
    }
    for(int i=0;i<m;++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].pb(mp(v, i));
        adj[v].pb(mp(u, i));
        mass[i] = w;
    }
    cin >> s >> d >> t;
    --s, --d;
    SPFA(n);
    int trip=ceil((float)t/(dist[d]-1));
    cout << "Scenario #" << C << endl;
    if(s == d)
        trip = 0;
    printf("Minimum Number of Trips = %d\n\n",trip);
    return true;
}

int main(){
    int C = 1;
    while(solve(C)){
        ++C;
    }
}
