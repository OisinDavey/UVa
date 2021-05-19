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
    vector<pair<int, pair<int, int> > > v;
    int w, IQ;
    int ID = 0;
    while(cin >> w >> IQ){
        v.pb({w, {IQ, ID}});
        ++ID;
    }
    sort(All(v));
    int n = v.size();
    int val[n], p[n];
    pair<int, int> longest = {1, 0};
    memset(p, -1, sizeof(p));
    for(int i=0;i<n;++i){
        val[i] = v[i].second.first;
    }
    int dp[n];
    dp[0] = 1;
    for(int i=1;i<n;++i){
        dp[i] = 0;
        for(int j=0;j<i;++j){
            if(val[j] > val[i] && v[j].first < v[i].first && dp[j] > dp[i]){
                dp[i] = dp[j];
                p[i] = j;
            }
        }
        ++dp[i];
        if(dp[i] > longest.first){
            longest.first = dp[i];
            longest.second = i;
        }
    }
    vector<int> ans;
    int at = longest.second;
    while(at >= 0){
        ans.pb(at);
        at = p[at];
    }
    reverse(All(ans));
    cout << ans.size() << endl;
    for(int i : ans){
        cout << v[i].second.second+1 << endl;
    }
}
