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
        int n, m;
        cin >> n >> m;
        vector<pair<int, int> > AL[n];
        ll mass[m];
        ll dist[n];
        for(int i=0;i<m;++i){
            int u, v;
            cin >> u >> v >> mass[i];
            AL[u].pb({v, i});
        }
        for(int i=0;i<n;++i){
            dist[i] = INF;
        }
        dist[0] = 0ll;
        for(int i=0;i<n-1;++i){
            for(int at=0;at<n;++at){
                if(dist[at] != INF){
                    for(auto& [to, id] : AL[at]){
                        dist[to] = min(dist[to], dist[at]+mass[id]);
                    }
                }
            }
        }
        bool cycle = false;
        for(int at=0;at<n;++at){
            if(dist[at] != INF){
                for(auto& [to, id] : AL[at]){
                    if(dist[to] > dist[at]+mass[id]){
                        cycle = true;
                    }
                }
            }
        }
        cout << (cycle?"possible\n":"not possible\n");
    }
}
