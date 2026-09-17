/*1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of integers arr and an integer target*/


class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<long long>dp(n,INT_MAX);
        int sum = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>target)
                 sum -=arr[j++];
            if(sum==target)
                dp[i]=i-j+1;      
        }
        long long res=1e10;
        for(int i =0;i<n;i++){
            if(dp[i]<INT_MAX){
                long long left = i-dp[i];
                if(left>=0)
                   res = min(res,(dp[i]+dp[left]));
            }
            if(i-1>=0)
              dp[i]=min(dp[i],dp[i-1]);
        }
        if(res>n)
         return -1;
        else
         return res;  
    }
};