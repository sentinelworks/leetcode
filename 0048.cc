class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        for(int i=0; i < a.size(); i++){
            for(int j = i+1; j < a.size(); j++){
                swap(a[i][j],a[j][i]);
            }
        }

        for (int i=0; i< a.size(); i++) {
            for (int j=0, k=a.size()-1; j<k; j++, k--) {
                swap(a[i][j], a[i][k]);
            }
        }
    }
};
