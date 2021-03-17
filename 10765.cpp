//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            10001 
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

int root;
int cnt;
int articulation_point[MX_N];
vector<int> AL[MX_N];
int disc[MX_N];
int low[MX_N];

int dfs_ap(int at, int par){
    int kids = 0;
    low[at] = disc[at] = cnt++;
    for(auto& to : AL[at]){
        if(to == par){
            continue;
        }
        if(!disc[to]){
            ++kids;
            dfs_ap(to, at);
            if(disc[at] <= low[to]){
                articulation_point[at]++;
            }
            low[at] = min(low[at], low[to]);
        }else{
            low[at] = min(low[at], disc[to]);
        }
    }
    return kids;
}

struct cust{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second < b.second;
        }else{
            return a.first > b.first;
        }
    }
};

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            return 0;
        }
        memset(disc, 0, sizeof(disc));
        memset(articulation_point, 0, sizeof(articulation_point));
        for(int i=0;i<n;++i){
            AL[i] = {};
        }

        int x, y;
        while(cin >> x >> y){
            if(x == -1 && y == -1){
                break;
            }
            AL[x].pb(y);
            AL[y].pb(x);
        }

        cnt = 1;
        for(int i=0;i<n;++i){
            if(!disc[i]){
                root = i;
                articulation_point[i] = (dfs_ap(i, i) > 1);
            }
        }

        vector<pair<int, int> > vi;

        for(int i=0;i<n;++i){
            vi.pb({articulation_point[i]+1, i});
        }

        sort(All(vi), cust());
        for(int i=0;i<m;++i){
            cout << vi[i].second << ' ' << vi[i].first << endl;
        }
        cout << endl;
    }
}
