//3904. Smallest Stable Index II



class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>minFromIndex(n);
        int minele = INT_MAX;
        for(int i= n-1;i>=0;i--){
            minele = min(minele,nums[i]);
            minFromIndex[i]= minele;
        }
        int maxele = INT_MIN;
        for(int i=0;i<n;i++){
            maxele = max(maxele,nums[i]);
            if(maxele-minFromIndex[i]<=k)
               return i;
        }
        return -1;
    }
};