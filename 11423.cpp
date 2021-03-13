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

int n;
int cache_sizes[30];
int tree[10000001];
int pos_in_tree[20000000];
int last_stat[30];
int total_stat[30];
int gind = 1;

void update_point(int at, int val){
    while(at <= 10000000){
        tree[at] += val;
        at += ((at)&(-at));
    }
    return;
}

int query_pref(int at){
    if(at == 0){
        return 0;
    }
    int res = 0;
    while(at > 0){
        res += tree[at];
        at -= ((at)&(-at));
    }
    return res;
}

int query_range(int L, int R){
    return query_pref(R) - query_pref(L-1);
}

void process_cache_query(int ind){
    if(pos_in_tree[ind] > 0){
        int dist = query_range(pos_in_tree[ind], gind-1);
        update_point(pos_in_tree[ind], -1);
        for(int i=0;i<n;++i){
            if(dist > cache_sizes[i]){
                ++total_stat[i];
            }else{
                break;
            }
        }
    }else{
        for(int i=0;i<n;++i){
            ++total_stat[i];
        }
    }
    update_point(gind, +1);
    pos_in_tree[ind] = gind;
    ++gind;
    return;
}

int main(){
    memset(pos_in_tree, 0, sizeof(pos_in_tree));
    memset(tree, 0, sizeof(tree));
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> cache_sizes[i];
    }
    string s;
    while(cin >> s){
        if(s == "END"){
            return 0;
        }else if(s == "ADDR"){
            int x;
            cin >> x;
            process_cache_query(x);
        }else if(s == "RANGE"){
            int b, y, k;
            cin >> b >> y >> k;
            for(int i=0;i<k;++i){
                process_cache_query(b+y*i);
            }
        }else if(s == "STAT"){
            for(int i=0;i<n;++i){
                if(i != 0){
                    cout << ' ';
                }
                cout << total_stat[i] - last_stat[i];
                last_stat[i] = total_stat[i];
            }
            cout << endl;
        }
    }
}
