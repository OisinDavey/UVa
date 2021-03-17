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

vector<int> al[101];
bool vis[101];
int par[101];
int a_point[101];
int dfs_root;
int root_subtrees;
int dfs_num[101];
int dfs_low[101];
int dfs_count;

void dfs(int at){
    vis[at] = true;
    dfs_num[at] = dfs_num[at] = dfs_count++;
    for(auto& to : al[at]){
        if(to == par[at]){
            continue;
        }
        if(!vis[to]){
            par[to] = at;
            if(at == dfs_root){
                root_subtrees++;
            }
            dfs(to);
            if(dfs_low[to] >= dfs_num[at]){
                a_point[at] = true;
            }
            dfs_low[at] = min(dfs_low[at], dfs_low[to]);
        }else{
            dfs_low[at] = min(dfs_low[at], dfs_num[to]);
        }
    }
    return;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            return 0;
        }
        memset(par, -1, sizeof(par));
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(a_point, 0, sizeof(a_point));

        for(int i=1;i<=n;++i){
            al[i] = {};
            vis[i] = false;
        }

        int cur;
        while(cin >> cur){
            if(cur == 0){
                break;
            }
            string s;
            getline(cin, s);
            stringstream ss;
            ss << s;
            int x;
            while(ss >> x){
                al[cur].pb(x);
                al[x].pb(cur);
            }
        }

        dfs_count = 1;
        for(int i=1;i<=n;++i){
            if(!vis[i]){
                dfs_root = i;
                root_subtrees = 0;
                dfs(i);
                a_point[i] = (root_subtrees > 1);
            }
        }

        int cnt = 0;
        for(int i=1;i<=n;++i){
            cnt += a_point[i];
        }
        cout << cnt << endl;
    }
}
