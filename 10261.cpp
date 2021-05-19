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

pair<int, int> Prev[505][10005];

void solve(){
    int L;
    cin >> L;
    L *= 100;
    vector<int> q;
    int x;
    while(cin >> x){
        if(x == 0){
            break;
        }
        q.pb(x);
    }
    int n = q.size();
    if(n == 0){
        cout << "0\n";
        return;
    }
    int pref[n];
    pref[0] = q[0];
    for(int i=1;i<n;++i){
        pref[i] = pref[i-1] + q[i];
    }
    bool dp[n+1][L+1];
    memset(dp, 1, sizeof(dp));
    dp[0][0] = true;
    pair<int, int> best = {0, 0};
    for(int i=1;i<=n;++i){
        for(int l=0;l<=L;++l){
            int r = pref[i-1] - l;
            bool pass = false;
            if(r <= L && l >= q[i-1]){
                if(dp[i-1][l-q[i-1]]){
                    pass = true;
                    Prev[i][l] = {i-1, l-q[i-1]};
                }
            }
            if(r <= L && r >= q[i-1]){
                if(dp[i-1][l]){
                    pass = true;
                    Prev[i][l] = {i-1, l};
                }
            }
            dp[i][l] = pass;
            if(dp[i][l]){
                best = {i, l};
            }
        }
    }
    vector<bool> ans;
    while(best.first > 0){
        pair<int, int> next = Prev[best.first][best.second];
        ans.pb(best.second == next.second);
        best = next;
    }
    reverse(All(ans));
    cout << ans.size() << endl;
    for(bool b : ans){
        cout << (!b?"port\n":"starboard\n");
    }
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
        if(T){
            cout << endl;
        }
    }
}
