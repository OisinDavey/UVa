//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            501
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define mp              make_pair
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

const long long INF=1e18;

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

using namespace std;

//Global Variables
int N;
bool inQ[MX_N];
ll dist[MX_N];
ll mass[MX_N][MX_N];

void SPFA(){
    cin >> N;
    for(int i=0;i<N;++i){
        dist[i] = INF;
        mass[i][i] = 0LL;
        inQ[i] = false;
        for(int j=0;j<i;++j){
            string inp;
            cin >> inp;
            if(inp == "x"){
                mass[i][j] = -1;
                mass[j][i] = -1;
                continue;
            }
            stringstream ss(inp);
            ll w;
            ss >> w;
            mass[i][j] = w;
            mass[j][i] = w;
        }
    }
    queue<int> Q;
    dist[0] = 0;
    Q.push(0);
    inQ[0] = true;
    while(!Q.empty()){
        int at = Q.front();
        Q.pop();
        inQ[at] = false;
        for(int to=0;to<N;++to){
            if(mass[at][to] == -1)
                continue;
            if(dist[to] > dist[at] + mass[at][to]){
                dist[to] = dist[at] + mass[at][to];
                if(!inQ[to]){
                    inQ[to] = true;
                    Q.push(to);
                }
            }
        }
    }
}

int main(){
    FastIO;
    SPFA();
    ll maxmindist = 0LL;
    for(int i=0;i<N;++i)
        if(dist[i] != INF)
            maxmindist = max(maxmindist, dist[i]);
    cout << maxmindist << endl;
}
