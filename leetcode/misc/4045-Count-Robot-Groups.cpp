using ll=long long;
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        ll grps=n;
        ll maxiSpeed=speed[n-1];
        for(int i=n-1;i>0;i--)
        {
            if(position[i]-position[i-1]<=distance)
            grps--;
            else if(speed[i-1]>maxiSpeed)
            grps--;
            else
            maxiSpeed=speed[i-1];
        }
        return (int)grps;
    }
};