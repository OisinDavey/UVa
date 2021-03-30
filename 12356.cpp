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
    int n, b;
    while((cin >> n >> b) && (n or b)){
        int left[n];
        int right[n];
        left[0] = 0;
        right[n-1] = n-1;
        for(int i=0;i<n;++i){
            if(i > 0){
                left[i] = i-1;
            }
            if(i < n-1){
                right[i] = i+1;
            }
        }
        for(int i=0;i<b;++i){
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int L = -1, R = -1;
            if(left[l] == l){//Leftmost possible
                if(right[r] != r){//Rightmost possible
                    left[right[r]] = right[r];
                    R = right[r];
                }
            }else if(right[r] == r){
                right[left[l]] = left[l];
                L = left[l];
            }else{
                left[right[r]] = left[l];
                right[left[l]] = right[r];
                R = right[r];
                L = left[l];
            }
            if(L == -1){
                cout << "* ";
            }else{
                cout << L+1 << ' ';
            }
            if(R == -1){
                cout << "*\n";
            }else{
                cout << R+1 << endl;
            }
        }
        cout << "-\n";
    }
}
