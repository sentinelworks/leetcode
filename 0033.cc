class Solution {
public:
    int search(vector<int>& a, int t) {
        int l=0, r=a.size()-1;
        while(l<=r) {
            int m = (l+r+1)/2;
            if(a[m]==t) return m;
            if(a[l] < a[m]) {
                if (t>=a[l] and t< a[m]) r = m-1;
                else l = m+1;
            } else {
                if(t>a[m] and t<=a[r]) l=m+1;
                else r=m-1;
            }
        }
        return -1;
    }
};
