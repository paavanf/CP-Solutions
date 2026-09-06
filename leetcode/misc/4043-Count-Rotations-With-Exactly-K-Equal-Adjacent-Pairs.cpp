class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int score=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[(i+1)%n])
            score++;
        }
        if(s[n-1]==s[0])
        score++;
        if(score==k)
        return n-score;
        if(score==k+1)
        return score;
        return 0;
    }
};