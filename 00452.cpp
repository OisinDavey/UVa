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
    string inp;
    getline(cin, inp);
    getline(cin, inp);
    while(T--){
        vector<int> AL[26];
        int mass[26];
        int dist[26];
        int in_degree[26];
        memset(mass, 0, sizeof(mass));
        memset(in_degree, 0, sizeof(in_degree));
        memset(dist, 0, sizeof(dist));
        while(getline(cin, inp)){
            if(inp.size()==0){
                break;
            }
            stringstream ss;
            ss << inp;
            char at;
            ss >> at;
            at -= 'A';
            ss >> mass[at];
            char to;
            while(ss >> to){
                to -= 'A';
                AL[at].pb(to);
                ++in_degree[to];
            }
        }
        queue<int> Q;
        vector<int> toposort;
        for(int i=0;i<26;++i){
            if(in_degree[i] == 0){
                Q.push(i);
            }
        }
        while(!Q.empty()){
            int at = Q.front();Q.pop();
            toposort.pb(at);
            for(int to : AL[at]){
                --in_degree[to];
                if(in_degree[to] == 0){
                    Q.push(to);
                }
            }
        }
        int longest = 0;
        for(int at : toposort){
            dist[at] += mass[at];
            longest = max(longest, dist[at]);
            for(int to : AL[at]){
                dist[to] = max(dist[to], dist[at]);
            }
        }
        cout << longest << endl;
        if(T){
            cout << endl;
        }
    }
}
