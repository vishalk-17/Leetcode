//462. Minimum Moves to Equal Array Elements II

// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//     long long int minn=INT_MAX,sum=0,n=nums.size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             long long int diff=abs(nums[i]-nums[j]);
//             sum=sum+diff;
            
//         }
//         minn=min(sum,minn);
//         sum=0;
//     }
//     return minn;
//     }
// };


class Solution {
public:
    int minMoves2(vector<int>& nums) { // o(n)
        int n = nums.size();
        nth_element(begin(nums),begin(nums)+n/2,end(nums));
        int mid =nums[n/2];
        int moves = 0;
        for(int i=0;i<n/2;i++){
            moves += abs(nums[i]-mid);
            moves += abs(nums[n-i-1]-mid);
        }
        return moves;
    }
};