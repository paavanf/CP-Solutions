class Solution {
public:
    int ds(int x)
    {
        int s=0;
        while(x>0)
        {
            s+=x%10;
            x/=10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++)
        mp.push_back({nums[i],i});
        sort(mp.begin(),mp.end(),[&](auto &a,auto &b)
        {
            int s1=ds(a.first);
            int s2=ds(b.first);
            if(s1==s2)
            return a.first<b.first;
            return s1<s2;
        });
        //now we req swap count
        //cycle detection would be a good idea
        vector<int>pos(n);
        for(int i=0;i<n;i++)
        pos[mp[i].second]=i;
        vector<bool>vis(n,false);
        int swaps=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i] || pos[i]==i)
            continue;
            int j=i;
            int cycle=0;
            while(!vis[j])
            {
                vis[j]=true;
                j=pos[j];
                cycle++;
            }
            swaps+=cycle-1;
        }
        return swaps;
    }
};