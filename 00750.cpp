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

vector<int> h = {0, 1, 2, 3, 4, 5, 6, 7};

bool valid(){
    for(int i=0;i<8;++i){
        for(int j=i+1;j<8;++j){
            int xa = i;
            int xb = j;
            int ya = h[i];
            int yb = h[j];
            if(xa == xb){
                //Row
                return false;
            }else if(ya == yb){
                //Col
                return false;
            }else if(ya - yb == xa - xb){
                //Positive diagonal
                return false;
            }else if(yb - ya == xa - xb){
                //Negative diagonal
                return false;
            }
        }
    }
    return true;
}

vector<vector<int> > all_boards;

void check_all(){
    while(next_permutation(h.begin(), h.end())){
        if(valid()){
            all_boards.pb(h);
        }
    }
    return;
}

int main(){
    check_all();
    int T;
    cin >> T;
    while(T--){
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n";
        cout << "\n";
        int ans = 0;
        for(auto& v : all_boards){
            if(v[y] == x){
                ++ans;
                if(ans < 10){
                    cout << ' ';
                }
                cout << ans << "      ";
                for(int val : v){
                    cout << val+1 << ' ';
                }
                cout << endl;
            }
        }
        if(T > 0){
            cout << endl;
        }
    }
}
