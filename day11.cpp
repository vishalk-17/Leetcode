//3345. Smallest Divisible Digit Product I
#include <iostream>
using namespace std;

class Solution {
public:
    int digitProduct(int num) {
        int product = 1;

        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            int product = digitProduct(n);

            if (product % t == 0)
                return n;

            n++;
        }
    }
};

int main() {
    Solution sol;

    int n, t;
    cout << "Enter n and t: ";
    cin >> n >> t;

    int result = sol.smallestNumber(n, t);

    cout << "Smallest Number = " << result << endl;

    return 0;
}