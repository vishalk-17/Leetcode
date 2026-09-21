/*3524. Find X Value of Array I
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of positive integers nums, and a positive integer k.*/


class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<int>lurminexod = nums;
        int z = lurminexod.size(),K = k;
        vector<long long>q(K),a(K),b(K);
        for(int i=0;i<z;++i){
            int  m =lurminexod[i]%k;
            fill(b.begin(),b.end(),0LL);
            for(int p =0;p<k;++p) b[(int)((1LL*p*m)%K)]+=a[p];
            b[m]++;
            for(int x=0;x<k;++x) q[x]+=b[x];
            a.swap(b);
        }
        return q;
    }
};