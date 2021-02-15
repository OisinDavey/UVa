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

struct matrix{
    int H;
    int W;
    vector<vector<ll> > val;
};

matrix matrix_create(int H, int W){
    matrix res;
    res.H = H;
    res.W = W;
    for(int i=0;i<H;++i){
        vector<ll> tmp;
        for(int j=0;j<W;++j){
            tmp.pb(0LL);
        }
        res.val.pb(tmp);
    }
    return res;
}

matrix operator * (matrix A, matrix B){
    matrix res = matrix_create(A.H, B.W);
    for(int i=0;i<res.H;++i){
        for(int j=0;j<res.W;++j){
            for(int k=0;k<A.W;++k){
                res.val[i][j] += (A.val[i][k])*(B.val[k][j]);
            }
        }
    }
    return res;
}

matrix I;

matrix matrix_bin_pow(matrix base, ll expo){
    if(expo == 0LL){
        return I;
    }else if(expo == 1LL){
        return base;
    }else{
        matrix tmp = matrix_bin_pow(base, expo/2LL);
        tmp = tmp*tmp;
        if(expo % 2LL == 1LL){
            tmp = base*tmp;
        }
        return tmp;
    }
}

int main(){
    I = matrix_create(2, 2);
    I.val[0][0] = 1LL;
    I.val[1][1] = 1LL;
    ll p, q, n;
    while(cin >> p >> q >> n){
        matrix Z = matrix_create(2, 2);
        matrix M0 = matrix_create(2, 2);
        Z.val[0][0] = p;
        Z.val[0][1] = -q;
        Z.val[1][0] = 1LL;
        Z.val[1][1] = 0LL;
        M0.val[0][0] = p*p - 2LL*q;
        M0.val[0][1] = p;
        M0.val[1][0] = p;
        M0.val[1][1] = 2LL;

        matrix MN = matrix_bin_pow(Z, n)*M0;

        cout << MN.val[1][1] << endl;

//        cout << "MN\n";
//        cout << MN.val[0][0] << ' ' << MN.val[0][1] << endl;
//        cout << MN.val[1][0] << ' ' << MN.val[1][1] << endl;
//        cout << "M0\n";
//        cout << M0.val[0][0] << ' ' << M0.val[0][1] << endl;
//        cout << M0.val[1][0] << ' ' << M0.val[1][1] << endl;
//        cout << "Z\n";
//        cout << Z.val[0][0] << ' ' << Z.val[0][1] << endl;
//        cout << Z.val[1][0] << ' ' << Z.val[1][1] << endl;
//        cout << "Identity Matrix\n";
//        cout << I.val[0][0] << ' ' << I.val[0][1] << endl;
//        cout << I.val[1][0] << ' ' << I.val[1][1] << endl;
    }
}
