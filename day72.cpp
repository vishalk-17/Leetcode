//2778. Sum of Squares of Special Elements
#include <iostream>
#include <vector>
using namespace std;

int sumOfSquares(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (n % (i + 1) == 0) {
            sum += nums[i] * nums[i];
        }
    }

    return sum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    cout << sumOfSquares(nums) << endl;

    return 0;
}
