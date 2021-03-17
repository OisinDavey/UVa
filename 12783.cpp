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

using namespace std;

int disc[MX_N];
int low[MX_N];
int counter;
vector<int> AL[MX_N];
vector<pair<int, int> > bridges;

void find_bridges(int at, int par){
    disc[at] = low[at] = counter++;
    for(int& to : AL[at]){
        if(to == par){
            continue;
        }
        if(!disc[to]){
            find_bridges(to, at);
            if(low[to] > disc[at]){
                bridges.pb({min(at,to), max(at,to)});
            }
            low[at] = min(low[at], low[to]);
        }else{
            low[at] = min(low[at], disc[to]);
        }
    }
    return;
}

int main(){
    int n, m;
    while(cin >> n >> m && (n || m)){
        memset(disc, 0, sizeof(disc));
        memset(low, 0, sizeof(low));
        counter = 1;
        bridges = {};
        for(int i=0;i<n;++i){
            AL[i] = {};
        }
        for(int i=0;i<m;++i){
            int a, b;
            cin >> a >> b;
            AL[a].pb(b);
            AL[b].pb(a);
        }
        for(int i=0;i<n;++i){
            if(!disc[i]){
                find_bridges(i, i);
            }
        }
        sort(All(bridges));
        cout << bridges.size();
        if(bridges.size() != 0){
            cout << ' ';
        }
        for(int i=0;i<bridges.size();++i){
            cout << bridges[i].first << ' ' << bridges[i].second;
            if(i != bridges.size()-1){
                cout << ' ';
            }
        }
        cout << endl;
    }
}
