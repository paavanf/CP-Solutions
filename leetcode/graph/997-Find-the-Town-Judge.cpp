class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        vector<int>in(n+1,1),out(n+1,1);

        for(auto vec : trust){
            int u=vec[0],v=vec[1];
            adj[u].push_back(v);
        }

        for(int i=0;i<=n;i++){

            for(int num: adj[i]){
                out[i]++;
                in[num]++;
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(in[i]==n && out[i]==1) ans =i;
        }
        return ans;
    }
};