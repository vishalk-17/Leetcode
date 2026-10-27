//3963. Create Grid With Exactly One Path
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // every row :walls, last cell free
        vector<string>g(m,string(n-1,'#')+'.');
        // the top row is fully free
        g[0]= string(n,'.');
        return g;
    }
};