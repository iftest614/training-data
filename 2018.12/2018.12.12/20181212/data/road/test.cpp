#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define all(a) a.begin(),a.end()
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){x=x>y?y:x;}
template<class T> inline void gmax(T &x,const T &y){x=x<y?y:x;}
template<class T> inline bool Gmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T> inline bool Gmax(T &x,const T &y){return x<y?x=y,1:0;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){rev|=c=='-';c=Getchar();if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const int inf=0x3f3f3f3f;
const int N=2005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,K,w0;

namespace chk{
	int m,d[N];
	pii p[N];
	vi g[N];
	inline void pre(int x,int y){p[++m]=mp(x,y);}
	inline void add(int x,int y){g[x].pb(y);g[y].pb(x);}
	inline void bfs(int x){
		static int q[N];
		clr(d,0);
		int h=1,t=1;q[t]=x;
		d[x]=1;
		while(h<=t){
			int x=q[h++];
			for(int y:g[x])
				if(!d[y]) d[y]=d[x]+1,q[++t]=y;
		}
	}
	inline int get(vector<pii> &a){
		if(SZ(a)>K) return inf;
		for(int i=1;i<=n;i++) vi(0).swap(g[i]);
		for(int i=1;i<n;i++)
			add(p[i].FF,p[i].SS);
		for(auto i:a)
			add(i.FF,i.SS);
		int ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<i;j++)
				ans+=d[j]-1;
		}
		return ans;
	}
}

int du[N];

inline int solve(int rt,vector<pii> &E){
	static int rk[N];
	for(int i=1;i<=n;i++)
		rk[i]=i;
	sort(rk+1,rk+n+1,[&](int x,int y){return du[x]>du[y];});
	vector<pii>(0).swap(E);
	for(int i=1;i<=n;i++)
		if(rk[i]!=rt){
			E.pb(mp(rk[i],rt));
			if(SZ(E)==K) break;
		}
	return chk::get(E);
}

int main(){
#ifdef rqgao2014
//	assert(freopen("in/01.txt","r",stdin));
#endif
	scanf("%d%d%d",&n,&K,&w0);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		chk::pre(x,y);
		du[x]++;du[y]++;
	}
	int ans=inf;
	vector<pii> e(0);
	for(int i=1;i<=n;i++){
		vector<pii> E;
		if(Gmin(ans,solve(i,E))) e=E;
//		debug(i);
	}
	double P=(n==20?10:18),S=1.0-(double)ans/(double)w0;
	double score=min(P,P*pow(20,S));
	debug(score);
	for(auto i:e)
		printf("%d %d\n",i.FF,i.SS);
	return 0;
}
