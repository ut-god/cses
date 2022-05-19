
#include <bits/stdc++.h>
 
using namespace std;


const long long INF = 100000000000;
const long long large_prime = 1e9 +7;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define set_bits __builtin_popcountll
#define rep(i, j) for(int i = 0; i<j; i++)
#define rrep(i, j) for(int i = j-1; i>=0; i--)
 
 
#ifndef ONLINE_JUDGE
#define dbg(a) cerr << endl; cerr << #a << ": "; _print(a); cerr << endl << endl;
#else
#define dbg(a)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> umap) {cerr << "{ "; for(auto i : umap) {cerr << "{";_print(i.fs); cerr << ", "; _print(i.sn); cerr << "} ";} cerr << "}";}
 
 

bool is_persq(ll a){
    if(floor(sqrt(a))==ceil(sqrt(a))){return 1;}
    else{return 0;}
    }
bool is_int(double a){
    if(floor((a))==ceil(a)){return 1;}
    else{return 0;}
    }    
long long int power(ll a, ll b){
    ll temp;
    if(b==0){return 1;}
    temp = power(a,b/2)%large_prime; 
    if(b%2==0){return (temp*temp)%large_prime;}
    else {return (((a*temp)%large_prime)*temp)%large_prime;}}
void fastIO(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);} 
    
bool sortbysecdesc(const pair<pair<ll,ll>,ll> &a, const pair<pair<ll,ll>,ll> &b) {
       if(a.first.second==b.first.second)
            return b.first.first>a.first.first;
       return b.first.second > a.first.second;}
vector<ll> sieve(ll n) {ll*arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
 

int LIS(vector<int> &a)
{
    vector<int> lis; lis.reserve(a.size());
    for(auto &x: a)
    {
        auto it = upper_bound(lis.begin(), lis.end(), x);  // upper_bound for non-decreasing
        if(it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }
    return lis.size();    
}


int p[100005];
int sizes[100005];


int get(int a ){
    return p[a]=(p[a]==a ? a : get(p[a]));}

void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        p[b] = a;
        sizes[a] += sizes[b];
     
    }}
    
    

int main(){ 
    
    fastIO();
 
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> graph(n+1);
        vector<vector<int>> edges(m);
        
        
        for(int i=0;i<m;i++){
            int a, b,c;
            cin>>a>>b>>c;
           graph[a].pb(mp(b,c));  
           edges[i]= {a,b,c};
        }
        
        vector<ll> dist(n+1,1e16 );
        vector<int> parent(n+1 , -1);
        
        dist[1]=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(dist[edges[j][1]] > dist[edges[j][0]] + edges[j][2] ){parent[edges[j][1]]=edges[j][0];}
                dist[edges[j][1]]=min(dist[edges[j][1]] , dist[edges[j][0]] + edges[j][2]);

            }
            
        }
        int start=-1;
        
        bool cycle=0;
        for(int j=0;j<m;j++){
                
               if(dist[edges[j][1]] > dist[edges[j][0]] + edges[j][2] ) {start =edges[j][1]; cycle=1;parent[edges[j][1]]=edges[j][0];}
            }
            
        dbg(cycle)
        
        
        
        if(cycle){
       
            dbg(start)
            dbg(parent)
            dbg(dist)
            
            for (int i=0; i<n; ++i){
                start = parent[start];
            }
            int end = parent[start];
            
            
            vector<int> path;
            path.pb(start);
            
            while(end!=start ){
                
               path.pb(end);
               end = parent[end];
               
            }
            
            path.pb(start);
            reverse(all(path));
            cout<<"YES"<<endl;
            for(auto x : path){cout<<x<<" ";}
        }
         else{cout<<"NO"<<endl;}
        

    }
    
  
   






   


        
       
        
    

 
 
 
 
 