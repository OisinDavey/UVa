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
    int n, k;
    int cs = 1;
    while(cin >> n >> k and (n or k)){
        ll board[n][n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin >> board[i][j];
            }
        }
        ll dp[3][k+1][n][n];
        //0 down, 1 left, 2 right
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int q=0;q<=k;++q){
                    for(int t=0;t<3;++t){
                        dp[t][q][i][j] = -INF;
                    }
                }
            }
        }
        if(board[0][0] < 0){
            dp[0][1][0][0] = board[0][0];
        }else{
            dp[0][0][0][0] = board[0][0];
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int q=0;q<=k;++q){
                    for(int t=0;t<3;++t){
                        if(dp[t][q][i][j] == -INF)continue;

                        //Going down
                        if(i < n-1){
                            if(board[i+1][j] < 0){
                                if(q < k){
                                    if(dp[0][q+1][i+1][j] < dp[t][q][i][j] + board[i+1][j]){
                                        dp[0][q+1][i+1][j] = dp[t][q][i][j] + board[i+1][j];
                                    }
                                }
                            }else{
                                if(dp[0][q][i+1][j] < dp[t][q][i][j] + board[i+1][j]){
                                    dp[0][q][i+1][j] = dp[t][q][i][j] + board[i+1][j];
                                }
                            }
                        }

                        //Going left
                        if(j > 0 && t != 2){
                            if(board[i][j-1] < 0){
                                if(q < k){
                                    if(dp[1][q+1][i][j-1] < dp[t][q][i][j] + board[i][j-1]){
                                        dp[1][q+1][i][j-1] = dp[t][q][i][j] + board[i][j-1];
                                    }
                                }
                            }else{
                                if(dp[1][q][i][j-1] < dp[t][q][i][j] + board[i][j-1]){
                                    dp[1][q][i][j-1] = dp[t][q][i][j] + board[i][j-1];
                                }
                            }
                        }

                        //Going right
                        if(j < n-1 && t != 1){
                            if(board[i][j+1] < 0){
                                if(q < k){
                                    if(dp[2][q+1][i][j+1] < dp[t][q][i][j] + board[i][j+1]){
                                        dp[2][q+1][i][j+1] = dp[t][q][i][j] + board[i][j+1];
                                    }
                                }
                            }else{
                                if(dp[2][q][i][j+1] < dp[t][q][i][j] + board[i][j+1]){
                                    dp[2][q][i][j+1] = dp[t][q][i][j] + board[i][j+1];
                                }
                            }
                        }
                    }
                }
            }
            for(int j=n-1;j>=0;--j){
                for(int q=0;q<=k;++q){
                    for(int t=0;t<3;++t){
                        if(dp[t][q][i][j] == -INF)continue;

                        //Going down
                        if(i < n-1){
                            if(board[i+1][j] < 0){
                                if(q < k){
                                    if(dp[0][q+1][i+1][j] < dp[t][q][i][j] + board[i+1][j]){
                                        dp[0][q+1][i+1][j] = dp[t][q][i][j] + board[i+1][j];
                                    }
                                }
                            }else{
                                if(dp[0][q][i+1][j] < dp[t][q][i][j] + board[i+1][j]){
                                    dp[0][q][i+1][j] = dp[t][q][i][j] + board[i+1][j];
                                }
                            }
                        }

                        //Going left
                        if(j > 0 && t != 2){
                            if(board[i][j-1] < 0){
                                if(q < k){
                                    if(dp[1][q+1][i][j-1] < dp[t][q][i][j] + board[i][j-1]){
                                        dp[1][q+1][i][j-1] = dp[t][q][i][j] + board[i][j-1];
                                    }
                                }
                            }else{
                                if(dp[1][q][i][j-1] < dp[t][q][i][j] + board[i][j-1]){
                                    dp[1][q][i][j-1] = dp[t][q][i][j] + board[i][j-1];
                                }
                            }
                        }

                        //Going right
                        if(j < n-1 && t != 1){
                            if(board[i][j+1] < 0){
                                if(q < k){
                                    if(dp[2][q+1][i][j+1] < dp[t][q][i][j] + board[i][j+1]){
                                        dp[2][q+1][i][j+1] = dp[t][q][i][j] + board[i][j+1];
                                    }
                                }
                            }else{
                                if(dp[2][q][i][j+1] < dp[t][q][i][j] + board[i][j+1]){
                                    dp[2][q][i][j+1] = dp[t][q][i][j] + board[i][j+1];
                                }
                            }
                        }
                    }
                }
            }
        }

        ll ans = -1;
        for(int q=0;q<=k;++q){
            ans = max(ans, max(dp[0][q][n-1][n-1], max(dp[1][q][n-1][n-1], dp[2][q][n-1][n-1])));
        }
        cout << "Case " << cs << ": ";
        if(ans == -1){
            cout << "impossible\n";
        }else{
            cout << ans << endl;
        }
        ++cs;
    }
}
