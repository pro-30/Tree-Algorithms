#include<bits/stdc++.h>

const double pi=acos(-1.0);
using namespace std;
#define   endl    '\n'
#define   sl(n)     scanf("%lld",&n)
#define   mp      make_pair
#define   pb      push_back
#define   ppb     pop_back
#define   fi      first
#define   se      second
#define   ll      long long
#define   ull     unsigned long long
#define   ld      long double
#define   pii     pair<int, int>
#define   f(i,a,b)  for(ll i = (ll)(a); i < (ll)(b); i++)
#define   rf(i,a,b)   for(ll i = (ll)(a); i > (ll)(b); i--)
#define   ms(a,b)   memset((a),(b),sizeof(a))
#define   abs(x)    ((x<0)?(-(x)):(x))
#define   MAX     200005
#define   inf     LLONG_MAX
#define   ninf    LLONG_MIN
#define   MIN     INT_MIN
#define   yeet    return 0;
#define tihs if(fopen("input.txt","r"))freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


inline long long  MAX2(long long  a, long long  b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}

//typedef
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


int mod = 1e9 +7 ;
int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {if (!a) {x = 0;y = 1;return b;}int64_t x1, y1;int64_t d = extGcd(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
inline ll addmod(ll a,ll b){a=a%mod+b%mod;if(a>mod)a%=mod;return a;}
inline ll submod(ll a,ll b){a=a%mod-b%mod;if(a<0)a+=mod;return a;}
inline ll mulmod(ll a,ll b){return (a%mod * b%mod)%mod;}

int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};
inline ll exp(ll a,ll b){if(a==0)return 0ll;ll r=1LL;while(b>0){if(b&1){r=r*(a%mod);r=(r+mod)%mod;}b/=2;a=(a%mod)*(a%mod);a=(a+mod)%mod;}return (r+mod)%mod;}
ll gcd(ll a,ll b){if(b==0)return a;if(a==0)return b;return gcd(b,a%b);}
uint32 setbits(ll n){uint32 count=0;while (n){n&=(n-1);count++;}return count; }

////****************************************************************************************************************************************************************************************************************////

vector<int>adj[MAX];
int lev[MAX];
int up[MAX][20];

void dfs(int src,int par){
        lev[src]=1+ lev[par];
        for(auto child:adj[src]){
                    if(child!=par)dfs(child,src);
        }
}

void binary_lifting(int src,int par){
      up[src][0]=par;
      for(int i=1;i<20;i++){
         if(up[src][i-1]!=-1){
            up[src][i]=up[up[src][i-1]][i-1];
         }
         else{
            up[src][i]=-1;
         }
      }
      for(auto child:adj[src]){
         if(child!=par)binary_lifting(child,src);
      }
}
int lift_node(int src,int jump){

             for(int i=19;i>=0;i--){
                   if(jump==0 or src==-1)break;

                   if(jump >= (1<<i)){
                    jump=jump-(1<<i);
                    src=up[src][i];
                   }
             }
             return src;
}
int lca(int u,int v){
            if(lev[u]<lev[v])swap(u,v);
            int diff= lev[u]-lev[v];
            u=lift_node(u,diff);
            if(u==v)return u;
            for(int i=19;i>=0;i--){
                 int n1= up[u][i];
                 int n2= up[v][i];
                 if(n1!=n2){
                     u=n1;
                     v=n2;
                 }
            }
            return up[u][0];
}
int main(){
     tihs;
     int n,q;
     cin>>n>>q;
     for(int i=0;i<n-1;i++){
         int ss,ee;
         cin>>ss>>ee;
         adj[ss].pb(ee);
         adj[ee].pb(ss);
     }
     dfs(1,0); // store level;
     binary_lifting(1,0);
     while(q--){
         int a,b;
         cin>>a>>b;
         int Lca= lca(a,b);
         int ans= lev[a]+lev[b]-2*lev[Lca];
         cout<<ans<<endl;
     }
}
