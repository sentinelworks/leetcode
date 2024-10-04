class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        for (int i=0, m = a.size(), r = a[0].size()-1; r>=0 and i<m; i++) {
            int l = 0;
            while(l<=r) {
                int x = (l+r+1)/2;
                if(a[i][x] == t) return true;
                if(a[i][x]>t) r = x-1;
                else l=x+1;
            }
        }
        return false;
    }
};
