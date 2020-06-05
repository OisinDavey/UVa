//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            201 
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

//Global Variables
long double dist[MX_N];
pair<long double, long double> coord[MX_N];
long double mass[MX_N][MX_N];
int N;

long double sdist(int a, int b){
    return sqrt((coord[a].fi - coord[b].fi)*(coord[a].fi - coord[b].fi) + (coord[a].se - coord[b].se)*(coord[a].se - coord[b].se));
}

//BellManFord Variables
int edge[MX_N*MX_N][2]; // u, v
vector<int> EdgeID; // id

void BellManFord(){
    for(int i=0;i<N;++i){
        dist[i] = INF;
        cin >> coord[i].fi >> coord[i].se;
    }
    int E = 0;

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            edge[E][0] = i;
            edge[E][1] = j;
            mass[i][j] = sdist(i, j);
            ++E;
        }
    }
    dist[0] = 0.0;
    for(int i=0;i<N-1;++i){
        for(int j=0;j<E;++j){
            int u = edge[j][0];
            int v = edge[j][1];
            if(dist[v] > max(dist[u], mass[u][v])){
                dist[v] = max(dist[u], mass[u][v]);
            }
        }
    }
}

//Dijkstra Variables
bool processed[MX_N];

void Dijkstra(){
    for(int i=0;i<N;++i){
        processed[i] = 0;
        dist[i] = INF;
        cin >> coord[i].fi >> coord[i].se;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            mass[i][j] = sdist(i, j);
        }
    }
    priority_queue<pair<long double, int> > PQ;
    dist[0] = 0.0;
    PQ.push(mp(0, 0));
    while(!PQ.empty()){
        pair<long double, int> temp = PQ.top();
        int at = temp.se;
        PQ.pop();
        if(processed[at])
            continue;
        processed[at] = true;
        for(int i=0;i<N;++i){
            if(dist[i] > max(dist[at], mass[i][at])){
                dist[i] = max(dist[at], mass[i][at]);
                PQ.push(mp(-dist[i], i));
            }
        }
    }
}

int main(){
    FastIO;
    int Case = 1;
    while(1){
        cin >> N;
        if(N == 0){
            return 0;
        }
        Dijkstra();
        cout << "Scenario #" << Case << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << dist[1] << endl;
        cout << endl;
        ++Case;
    }
}
