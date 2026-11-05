#include <bits/stdc++.h>
using ll=long long;
using namespace std;

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> edges(n-1);
        for(auto &[u,v]:edges)
        cin>>u>>v;

        //even n: every vertex gets a partner
        if(n%2==0)
        {
            cout<<n+1<<"\n";
            continue;
        }

        //odd n: only 3 choices of k, each leaves exactly one vertex unpaired
        vector<pair<int,int>> options={{n,n},{n+1,(n+1)/2},{n+2,1}};
        int ans=n+1;
        for(auto [k,skip]:options)
        {
            //dsu on tree minus the unpaired vertex
            DisjointSet ds(n);
            for(auto [u,v]:edges)
            if(u!=skip && v!=skip)
            ds.unionBySize(u,v);

            //if some pair lies in different components, path goes through skip => it turns gray
            bool gray=false;
            for(int i=1;i<=n && !gray;i++)
            {
                int j=k-i;
                if(j>=1 && j<=n && j!=i && ds.findUPar(i)!=ds.findUPar(j))
                gray=true;
            }
            if(gray)
            {
                ans=k;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}