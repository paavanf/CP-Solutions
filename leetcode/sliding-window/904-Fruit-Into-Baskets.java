//import java.util.*;
class Solution {
    public int totalFruit(int[] fruits) {
        //unordered_map<int,int>mpp;
        HashMap<Integer,Integer>mpp=new HashMap<>();
        int i=0,j=0,ans=0;
        //while(j<fruits.size()){
        while(j<fruits.length){
            //mpp[fruits[j]]++;
            mpp.put(fruits[j],mpp.getOrDefault(fruits[j],0)+1);
            //invalid if more than 2 type of fruits in the window
            while(mpp.size() > 2){
                //mpp[fruits[i]]--;
                mpp.put(fruits[i],mpp.get(fruits[i])-1);
                //if(mpp[fruits[i]]==0) 
                if(mpp.get(fruits[i])==0)
                mpp.remove(fruits[i]);
                i++;
            }
            //valid window
            ans=Math.max(ans,j-i+1);
            j++;
        }
        return ans;
    }
}