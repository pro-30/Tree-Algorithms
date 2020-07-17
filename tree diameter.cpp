// #include<bits/stdc++.h>

// const double pi=acos(-1.0);
// using namespace std;
// #define   endl    '\n'
// #define   sl(n)     scanf("%lld",&n)
// #define   mp      make_pair
// #define   pb      push_back
// #define   ppb     pop_back
// #define   fi      first
// #define   se      second
// #define   ll      long long
// #define   ull     unsigned long long
// #define   ld      long double
// #define   pii     pair<int, int>
// #define   f(i,a,b)  for(ll i = (ll)(a); i < (ll)(b); i++)
// #define   rf(i,a,b)   for(ll i = (ll)(a); i > (ll)(b); i--)
// #define   ms(a,b)   memset((a),(b),sizeof(a))
// #define   abs(x)    ((x<0)?(-(x)):(x))
// #define   MAX     200005
// #define   inf     LLONG_MAX
// #define   ninf    LLONG_MIN
// #define   MIN     INT_MIN
// #define   yeet    return 0;
// #define tihs if(fopen("input.txt","r"))freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

// #define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// inline long long  MAX2(long long  a, long long  b){return (a)>(b)?(a):(b);}
// inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
// inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
// inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}


// int mod = 1e9 +7 ;


// ////****************************************************************************************************************************************************************************************************************////

// vector<int>adj[MAX];
// ll dist[MAX];
// void dfs(int src,int par){

//         dist[src]=dist[par]+1;
//         for(auto child:adj[src]){
//              if(child!=par){
//                   dfs(child,src);
//              }
//         }
//      }
//  int main(){
//      tihs;
//      int n;
//      cin>>n;
//      for(int i=0;i<n-1;i++){
//         int ss,ee;
//         cin>>ss>>ee;
//         adj[ss].pb(ee);
//         adj[ee].pb(ss);
//      }
//      dfs(1,0);
//       int max_d=1;
//       int len=0;
//       for(int i=1;i<=n;i++){
//            if(len<dist[i]){
//              len=dist[i];
//              max_d=i;
//            }
//       }
//       ms(dist,0);
//       dfs(max_d,0);
//       ll ans=0;

//       for(int i=1;i<=n;i++)ans=MAX2(ans,dist[i]);
//      cout<<ans-1<<endl;



// }

#include<bits/stdc++.h>
//#include <ext/pb_ds/detail/standard_policies.hpp>

const double pi=acos(-1.0);
//memset ( a , 0 , n * sizeof(ll) ) ;
using namespace std;
//using namespace __gnu_pbds;
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
// Use cout.flush() for interactive problems.
// Use this for increased stack size: g++ -o a.exe -Wl,--stack=256000000 -O2 source.cpp
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

// ll f[MAX];
// ll iv[MAX];
// ll C(ll n,ll r){
//   if(n<r)return 0;
//   ll ans=(f[n]%mod * iv[r]%mod)%mod;
//   ans=(ans%mod * iv[n-r]%mod)%mod;
//   return ans%mod;
// }
// void init(){
//   f[0]=1;
//      iv[0]=1;
//      f(i,1,MAX)f[i]=(i*f[i-1])%mod;
//      iv[MAX-1]=exp(f[MAX-1],mod-2);

//      for(int i=MAX-2;i>=0;--i)iv[i]=(iv[i+1]*(i+1))%mod;

// }

////****************************************************************************************************************************************************************************************************************////

vector<int>adj[MAX];
ll depth[MAX];
ll dp[MAX][2];
ll downpath(int src,int par){
        int len=0;
        int leaf=1;
         for(auto child:adj[src]){
                    if(child!=par){
                        leaf=0;
                        downpath(child,src);
                        len=MAX2(len,depth[child]);
                    }
         }
         if(leaf)depth[src]=0;
         else depth[src]=1+len;
}

void dfs(int src,int par){
       int curr=0;
       int leaf=1;
       dp[src][0]=dp[src][1]=0;
       for(auto child:adj[src]){
                if(child!=par){
                    leaf=0;
                    dfs(child,src);
                }
       }
       for(auto child:adj[src]){
           if(child!=par)dp[src][0]=MAX2(dp[src][0],MAX2(dp[child][1],dp[child][0]));
       }
       vector<ll>g1;
       for(auto child:adj[src]){
         if(child!=par){
                g1.pb(depth[child]);
         }
       }
       sort(g1.begin(),g1.end(),greater<ll>());
       if(g1.size()>=2)dp[src][1]=2+g1[0]+g1[1];
       else if(g1.size()==1)dp[src][1]=1+g1[0];
       else dp[src][1]=0;


}

 int main(){
     tihs;
     int n;
     cin>>n;
     for(int i=0;i<n-1;i++){
         int ss,ee;
         cin>>ss>>ee;
         adj[ss].pb(ee);
         adj[ee].pb(ss);
     }
     downpath(1,0);
     dfs(1,0);
     cout<<MAX2(dp[1][0],dp[1][1])<<endl;





      }


