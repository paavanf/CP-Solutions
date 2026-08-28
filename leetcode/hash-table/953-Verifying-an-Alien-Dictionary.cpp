class Solution {
public:
    bool check(string &s1,string &s2,unordered_map<char,int>&mpp){
        // checks if first word is wrong ---> will return true if first word is greater
        int m=s1.size() , n=s2.size() , i=0;
        while(i<m && i<n){
            if(s1[i]!=s2[i]){
                return mpp[s1[i]] > mpp[s2[i]];
            }
            i++;
        }
        return m > n;  // if first word larger when all equal then return true 
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mpp;
        for(int i=0;i<order.size();i++){
            mpp[order[i]]=i;
        }

        for(int i=0;i<words.size()-1;i++){
            if(check(words[i],words[i+1],mpp)){  // if this returns true means its wrong
                return false;
            }
        }
        return true;
    }
};