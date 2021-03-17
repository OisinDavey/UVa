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

int low[MX_N];
int disc[MX_N];
int counter;
vector<int> AL[MX_N];

int parent[MX_N];

int find_set(int at){
    if(at == parent[at]){
        return at;
    }else{
        return parent[at] = find_set(parent[at]);
    }
}

void union_set(int a, int b){
    int tmp_a = find_set(a);
    int tmp_b = find_set(b);
    if(tmp_a == tmp_b){
        return;
    }
    parent[tmp_b] = tmp_a;
}

bool same_set(int a, int b){
    return (find_set(a) == find_set(b));
}

void bridge_finder(int at, int par){
    low[at] = disc[at] = counter++;
    for(int& to : AL[at]){
        if(to == par){
            continue;
        }
        if(!disc[to]){
            bridge_finder(to, at);
            if(low[to] > disc[at]){
                union_set(at, to);
            }
            low[at] = min(low[at], low[to]);
        }else{
            low[at] = min(low[at], disc[to]);
        }
    }
}

int main(){
    int R, C, Q;
    while(cin >> R >> C >> Q and (R or C or Q)){
        memset(low, 0, sizeof(low));
        memset(disc, 0, sizeof(disc));
        for(int i=1;i<=R;++i){
            AL[i] = {};
            parent[i] = i;
        }
        for(int i=0;i<C;++i){
            int A, B;
            cin >> A >> B;
            AL[A].pb(B);
            AL[B].pb(A);
        }
        counter = 1;
        for(int i=1;i<=R;++i){
            if(!disc[i]){
                bridge_finder(i, i);
            }
        }
        while(Q--){
            int S, T;
            cin >> S >> T;
            cout << (same_set(S, T)?"Y\n":"N\n");
        }
        cout << "-\n";
    }
}
