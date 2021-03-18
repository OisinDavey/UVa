//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            20001 
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

int n, m;
int s, t;

ll dist[MX_N];
vector<pair<int, int> > AL[MX_N];

ll mass[MX_N*4];

int main(){
    FastIO;
    int T;
    cin >> T;
    for(int c=1;c<=T;++c){
        cin >> n >> m >> s >> t;
        for(int i=0;i<n;++i){
            dist[i] = INF;
            AL[i] = {};
        }
        int edge_gint = 1;
        for(int i=0;i<m;++i){
            int u, v;
            ll w;
            cin >> u >> v >> w;
            AL[u].pb({v, edge_gint});
            AL[v].pb({u, edge_gint});
            mass[edge_gint] = w;
            ++edge_gint;
        }

        //Dijkstras
//        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
//        dist[s] = 0;
//        pq.push({dist[s], s});
//        while(!pq.empty()){
//            auto [d, at] = pq.top();
//            pq.pop();
//            if(d > dist[at]){
//                continue;
//            }
//            for(auto& [to, id] : AL[at]){
//                if(dist[to] > dist[at] + mass[id]){
//                    dist[to] = dist[at] + mass[id];
//                    pq.push({dist[to], to});
//                }
//            }
//        }
        //SPFA
        queue<int> q;
        q.push(s);
        bool in_queue[MX_N];
        memset(in_queue, 0, sizeof(in_queue));
        in_queue[s] = true;
        dist[s] = 0;
        while(!q.empty()){
            int at = q.front();
            q.pop();
            in_queue[at] = false;
            for(auto& [to, id] : AL[at]){
                if(dist[to] > dist[at] + mass[id]){
                    dist[to] = dist[at] + mass[id];
                    if(!in_queue[to]){
                        q.push(to);
                        in_queue[to] = true;
                    }
                }
            }
        }
        cout << "Case #" << c << ": ";
        if(dist[t] == INF){
            cout << "unreachable\n";
        }else{
            cout << dist[t] << endl;
        }
    }
}
