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

pair<int, bool> stat[201];
bool vis[201];

int cnts[201][2];

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(vis, 0, sizeof(vis));
        memset(cnts, 0, sizeof(cnts));
        int n;
        cin >> n;
        vector<int> al[201];
        for(int i=0;i<n;++i){
            int k;
            cin >> k;
            for(int j=0;j<k;++j){
                int x;
                cin >> x;
                al[i].pb(x-1);
                al[x-1].pb(i);
            }
        }
        int gint = 0;
        for(int i=0;i<200;++i){
            if(vis[i]){
                continue;
            }
            ++gint;
            queue<int> Q;
            Q.push(i);
            vis[i] = true;
            stat[i] = {gint, false};
            if(i < n){
                cnts[gint][0]++;
            }
            while(!Q.empty()){
                int at = Q.front();
                Q.pop();
                for(auto to : al[at]){
                    if(vis[to]){
                        continue;
                    }else{
                        vis[to] = true;
                        stat[to] = {gint, !stat[at].second};
                        if(to < n){
                            cnts[gint][!stat[at].second]++;
                        }
                        Q.push(to);
                    }
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        bool gint_done[gint+1];
        bool gint_bad[gint+1];
        memset(gint_done, 0, sizeof(gint_done));
        memset(gint_bad, 0, sizeof(gint_bad));
        for(int i=0;i<200;++i){
            if(vis[i]){
                continue;
            }
            if(gint_done[stat[i].first]){
                continue;
            }
            queue<int> Q;
            Q.push(i);
            vis[i] = true;
            gint_done[stat[i].first] = true;
            while(!Q.empty()){
                if(gint_bad[stat[i].first]){
                    break;
                }
                int at = Q.front();
                Q.pop();
                for(auto to : al[at]){
                    if(vis[to]){
                        if(stat[to].second == stat[at].second){
                            cnts[stat[at].first][0] = 0;
                            cnts[stat[at].first][1] = 0;
                            gint_bad[stat[at].first] = true;
                            break;
                        }
                        continue;
                    }else{
                        vis[to] = true;
                        Q.push(to);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=gint;++i){
            ans += max(cnts[i][0], cnts[i][1]);
        }
        cout << ans << endl;
    }
}
