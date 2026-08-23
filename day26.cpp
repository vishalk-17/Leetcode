// leaders of array

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> ans = leaders(arr);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}