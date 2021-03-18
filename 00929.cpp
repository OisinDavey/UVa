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
    FastIO;
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        int board[n][m];
        int dist[n][m];
        bool in_queue[n][m];

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> board[i][j];
                dist[i][j] = 10000000;
                in_queue[i][j] = false;
            }
        }

        dist[0][0] = board[0][0];

        //SPFA
        in_queue[0][0] = true;
        queue<pair<int, int> > q;
        q.push({0, 0});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            in_queue[x][y] = false;
            for(int i=0;i<4;++i){
                int _x = x + dx4[i];
                int _y = y + dy4[i];
                if(_x < 0 || _y < 0 || _x >= n || _y >= m){
                    continue;
                }
                if(dist[_x][_y] > dist[x][y] + board[_x][_y]){
                    dist[_x][_y] = dist[x][y] + board[_x][_y];
                    if(!in_queue[_x][_y]){
                        in_queue[_x][_y] = true;
                        q.push({_x, _y});
                    }
                }
            }
        }

        //Dijkstras
//        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;
//        pq.push({dist[0][0], 0, 0});
//        while(!pq.empty()){
//            auto [d, x, y] = pq.top();pq.pop();
//            if(d > dist[x][y])continue;
//            for(int i=0;i<4;++i){
//                int _x = x + dx4[i];
//                int _y = y + dy4[i];
//                if(_x < 0 || _y < 0 || _x >= n || _y >= m){
//                    continue;
//                }
//                if(dist[_x][_y] > dist[x][y] + board[_x][_y]){
//                    dist[_x][_y] = dist[x][y] + board[_x][_y];
//                    pq.push({dist[_x][_y], _x, _y});
//                }
//            }
//        }
        cout << dist[n-1][m-1] << endl;
    }
}
