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

int main(){
    int n, m, b, p;
    while(cin >> n >> m >> b >> p){
        ll dist[n+1];
        ll mass[m+1];
        for(int i=0;i<=n;++i){
            dist[i] = INF;
        }
        vector<pair<int, int> > AL[n+1];
        for(int i=1;i<=m;++i){
            int u, v;
            cin >> u >> v >> mass[i];
            ++u, ++v;
            AL[u].pb({v, i});
            AL[v].pb({u, i});
        }
        int banks[b];
        for(int i=0;i<b;++i){
            cin >> banks[i];
            ++banks[i];
        }
        for(int i=0;i<p;++i){
            int u;
            cin >> u;
            ++u;
            AL[0].pb({u, 0});
        }
        mass[0] = 0;
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({dist[0], 0});
        while(!pq.empty()){
            auto [d, at] = pq.top();pq.pop();
            if(d > dist[at]) continue;
            for(auto& [to, id] : AL[at]){
                if(dist[to] > dist[at] + mass[id]){
                    dist[to] = dist[at] + mass[id];
                    pq.push({dist[to], to});
                }
            }
        }
        ll biggest = -1;
        for(int i=0;i<b;++i){
            biggest = max(biggest, dist[banks[i]]);
        }
        vector<int> biggest_banks;
        for(int i=0;i<b;++i){
            if(dist[banks[i]] == biggest){
                biggest_banks.pb(banks[i]);
            }
        }
        sort(All(biggest_banks));
        cout << biggest_banks.size() << ' ';
        if(biggest == INF){
            cout << "*\n";
        }else{
            cout << biggest << endl;
        }
        for(int bank : biggest_banks){
            cout << bank-1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
