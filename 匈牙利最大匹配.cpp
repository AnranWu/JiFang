#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
const int MAXN = 505;  
int Nx,Ny;    
int G[MAXN][MAXN];  
int Mx[MAXN], My[MAXN];    
bool mark[MAXN];  
  
bool FindPath(int u){  
    for(int v=0; v<Ny; ++v){  
        if(G[u][v] && !mark[v]){  
            mark[v] = true;  
            if(My[v]==-1 || FindPath(My[v])){  
                My[v] = u;  
                Mx[u] = v;  
                return true;  
            }  
        }  
    }  
    return false;  
}  
int MaxMatch(){  
    int ret=0;  
    memset(Mx, -1, sizeof(Mx));  
    memset(My, -1, sizeof(My));  
    for(int u=0; u<Nx; ++u){  
        if(Mx[u] == -1) {  
            memset(mark, 0, sizeof(mark));  
            if(FindPath(u)) ++ret;  
        }  
    }  
    return ret;  
}  
  
int main(){  
    int k,a,b;  
    while(~scanf("%d%d%d",&k,&Nx,&Ny) && k){  
        memset(G,0,sizeof(G));  
        for(int i=0; i<k; ++i) {  
            scanf("%d%d",&a,&b);  
            G[a-1][b-1]=1;  
        }  
        printf("%d\n",MaxMatch());  
    }  
    return 0;  
}  
