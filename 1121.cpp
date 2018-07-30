#include<bits/stdc++.h>
#define rep(j,n) for(int i=j;i<n;i++)
#define pb push_back
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long int ll;
int main(){
	int n,k;
	while(scanf("%d %d", &n, &k) == 2){
		int a[n];
		rep(0,n)
			scanf("%d",&a[i]);
		int c=a[0];
		int d=0xfffffff;
		for(int i=0,j=0;;){
			if(c>=k){
				d=min(d,(j-i));
				c-=a[i];
				i++;
			}else{
				if(j == n-1){
					break;
				}else{
					j++;
					c+=a[j];
				}
			}
		}
		(d==0xfffffff)?puts("0"):printf("%d\n",d+1);
	}
	return 0;
}