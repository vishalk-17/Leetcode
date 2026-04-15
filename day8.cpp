//2515. Shortest Distance to Target String in a Circular Array
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int closetTarget(vector<string>& words, string target, int startIndex){
        int ans=INT_MAX;
        
        for(int i=0;i<words.size();i++){
            if(words[i]==target) ans=min(ans,min(abs(startIndex-i),int(words.size())-abs(startIndex-i)));
        }
        
        return ans==INT_MAX?-1:ans;
    }

};
int main(){
    vector<string> words={"hello","i","am","leetcode"};
    string target="hello";
    int startIndex=3;
    Solution s;
    cout<<s.closetTarget(words,target,startIndex);
    return 0;


}