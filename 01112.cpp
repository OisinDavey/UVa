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
    int T;
    cin >> T;
    while(T--){
        int n, e, t, m;
        cin >> n >> e >> t >> m;
        --e;
        vector<pair<int, int> > trans_AL[n];
        ll mass[m];
        for(int i=0;i<m;++i){
            int a, b;
            cin >> a >> b >> mass[i];
            --a, --b;
            trans_AL[b].pb({a, i});
        }
        ll dist[n];
        for(int i=0;i<n;++i){
            dist[i] = INF;
        }
        dist[e] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({dist[e], e});
        while(!pq.empty()){
            auto [d, at] = pq.top();pq.pop();
            if(d > dist[at]) continue;
            for(auto& [to, id] : trans_AL[at]){
                if(dist[to] > dist[at] + mass[id]){
                    dist[to] = dist[at] + mass[id];
                    pq.push({dist[to], to});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;++i){
            cnt += (dist[i] <= t);
        }
        cout << cnt << "\n";
        if(T != 0){
            cout << endl;
        }
    }
}
