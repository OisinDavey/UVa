//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            101
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

using namespace std;

//Global Variables
int N, M;

//SPFA Variables
ll dist[MX_N];
vector<pair<int, ll> > adj[MX_N];
bool inQ[MX_N];
ll e[MX_N];

bool SPFA(){ // Returns False if negative weight cycle
    queue<int> Q;
    Q.push(0);
    dist[0] = 0LL;
    e[0] = 0;
    inQ[0] = true;
    while(!Q.empty()){
        int at = Q.front();
        Q.pop();
        inQ[at] = false;
        for(pair<int, ll> temp : adj[at]){
            int to = temp.fi;
            ll w = temp.se;
            if(dist[to] > dist[at] + w){
                dist[to] = dist[at] + w;
                e[to] = e[at] + 1;
                if(e[to] > N){
                    return false;
                    //cout << at << ' ' << to << endl;
                }
                if(!inQ[to]){
                    inQ[to] = true;
                    Q.push(to);
                }
            }
        }
    }
    return true;
}

void solve(){
    cin >> M;
    for(int i=0;i<=N;++i){
        dist[i] = INF;
        inQ[i] = false;
        e[i] = 0;
        adj[i] = {};
    }
    for(int i=1;i<=N;++i){
        adj[0].pb(mp(i, 1000000000));
    }
    for(int i=0;i<M;++i){
        int si, ni, ki;
        string oi;
        cin >> si >> ni >> oi >> ki;
        if(oi == "lt"){
            //S(si + ni) - S(si - 1) <= k-1
            adj[si - 1].pb(mp(si + ni, ki-1));
        }else{
            //S(si - 1) - S(si + ni) <= -k-1
            adj[si + ni].pb(mp(si - 1, -ki - 1));
        }
    }
    if(SPFA()){
        cout << "lamentable kingdom\n";
    }else{
        cout << "successful conspiracy\n";
    }
}

int main(){
    while(1){
        cin >> N;
        if(N == 0)
            return 0;
        solve();
    }
}
