#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char leftChar, rightChar;
    int leftLen, rightLen, best;
};

class SegmentTree {
    int n;
    vector<Node> tree;
    string s;

    void pull(int node, int l, int r) {
        int mid = (l + r) / 2;
        int left = node * 2, right = node * 2 + 1;

        tree[node].leftChar = tree[left].leftChar;
        tree[node].rightChar = tree[right].rightChar;

        tree[node].leftLen = tree[left].leftLen;
        if (tree[left].leftLen == (mid - l + 1) &&
            tree[left].leftChar == tree[right].leftChar)
            tree[node].leftLen += tree[right].leftLen;

        tree[node].rightLen = tree[right].rightLen;
        if (tree[right].rightLen == (r - mid) &&
            tree[right].rightChar == tree[left].rightChar)
            tree[node].rightLen += tree[left].rightLen;

        tree[node].best = max(tree[left].best, tree[right].best);

        if (tree[left].rightChar == tree[right].leftChar)
            tree[node].best = max(tree[node].best,
                                  tree[left].rightLen + tree[right].leftLen);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].leftChar = tree[node].rightChar = s[l];
            tree[node].leftLen = tree[node].rightLen = tree[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        pull(node, l, r);
    }

    void update(int node, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[node].leftChar = tree[node].rightChar = ch;
            tree[node].leftLen = tree[node].rightLen = tree[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, ch);
        else
            update(node * 2 + 1, mid + 1, r, pos, ch);

        pull(node, l, r);
    }

public:
    SegmentTree(const string &str) : n(str.size()), s(str) {
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int pos, char ch) {
        update(1, 0, n - 1, pos, ch);
    }

    int getBest() const {
        return tree[1].best;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s,string queryCharacters,vector<int> &queryIndices) {

        SegmentTree st(s);
        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans.push_back(st.getBest());
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s = "babacc";
    string queryCharacters = "bcb";
    vector<int> queryIndices = {1, 3, 3};

    vector<int> result =
        obj.longestRepeating(s, queryCharacters, queryIndices);

    cout << "Output: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}