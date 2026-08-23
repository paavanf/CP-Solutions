class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int mid=n/2;
        int ls=0,rs=0,lq=0,rq=0;
        for(int i=0;i<mid;i++)
        {
            if(num[i]=='?')
            lq++;
            else
            ls+=num[i]-'0';
        }
        for(int i=mid;i<n;i++)
        {
            if(num[i]=='?')
            rq++;
            else
            rs+=num[i]-'0';
        }
        if(lq==0 && rq==0)
        {
            if(ls==rs)
            return false;
            else
            return true;
        }
        if((lq+rq)%2!=0)
        {
            return true;
        }
        if(((lq>=rq) && (ls>rs)) || ((lq<=rq) && (ls<rs)))
        return true;
        int qdiff=abs(lq-rq);
        int sdiff=abs(ls-rs);
        return qdiff*9/2!=sdiff;

    }
};