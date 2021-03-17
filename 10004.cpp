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

bool vis[201];
bool col[201];


int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            return 0;
        }
        vector<int> al[201];
        int l;
        cin >> l;
        for(int i=0;i<l;++i){
            int a, b;
            cin >> a >> b;
            al[a].pb(b);
            al[b].pb(a);
        }
        for(int i=0;i<n;++i){
            vis[i] = false;
        }
        queue<int> Q;
        Q.push(0);
        vis[0] = true;
        bool bad = false;
        while(!Q.empty()){
            int at = Q.front();
            Q.pop();
            for(auto& to : al[at]){
                if(vis[to]){
                    if(col[at] == col[to]){
                        bad = true;
                        break;
                    }
                }else{
                    col[to] = !col[at];
                    vis[to] = true;
                    Q.push(to);
                }
            }
            if(bad){
                break;
            }
        }
        cout << (bad?"NOT BICOLORABLE.\n":"BICOLORABLE.\n");
    }
}
