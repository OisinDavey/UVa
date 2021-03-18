//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            2001 
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

int disc[MX_N];
int low[MX_N];
bool in_stack[MX_N];
vector<int> AL[MX_N];
stack<int> stak;
int counter;
vector<vector<int> > scc;

void tarjan(int at){
    disc[at] = low[at] = counter++;
    for(auto& to : AL[at]){
        if(!disc[to]){
            stak.push(to);
            in_stack[to] = true;
            tarjan(to);
        }
        if(in_stack[to]){
            low[at] = min(low[at], low[to]);
        }
    }
    if(low[at] == disc[at]){
        scc.pb({});
        while(true){
            int top = stak.top();
            stak.pop();
            in_stack[top] = false;
            scc[scc.size()-1].pb(top);
            if(top == at){
                break;
            }
        }
    }
    return;
}

int main(){
    int n, m;
    while(cin >> n >> m && (n || m)){
        memset(disc, 0, sizeof(disc));
        memset(low, 0, sizeof(low));
        counter = 1;
        memset(in_stack, 0, sizeof(in_stack));
        scc = {};
        for(int i=0;i<MX_N;++i){
            AL[i] = {};
        }

        for(int i=0;i<m;++i){
            int a, b, c;
            cin >> a >> b >> c;
            --a;
            --b;
            AL[a].pb(b);
            if(c == 2){
                AL[b].pb(a);
            }
        }

        for(int i=0;i<n;++i){
            if(!disc[i]){
                stak.push(i);
                in_stack[i] = true;
                tarjan(i);
            }
        }

        if(scc.size() > 1){
            cout << "0\n";
        }else{
            cout << "1\n";
        }
    }
}
