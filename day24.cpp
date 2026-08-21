// pascal traingle row print

#include <iostream>
#include <vector>

std::vector<int> pascalRow(int r) {
    std::vector<int> row;

    long long value = 1;

    for (int i = 0; i <= r; ++i) {
        row.push_back(static_cast<int>(value));

        value = value * (r - i) / (i + 1);
    }

    return row;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> result = pascalRow(n);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];

        if (i < result.size() - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}