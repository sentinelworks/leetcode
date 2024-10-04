
class Solution {
public:
    int dfs(int *a, int *b, int m, int n, int k) {
        //cout << m << " " << n <<  ' ' << k << endl;
        if(m>n) return dfs(b, a, n, m, k);
        if(m==0) return b[k-1];
        if(k==1) return min(*a, *b);
        int u =min((m+1)/2, k-1), v = k-u;
        if(a[u-1]<=b[v-1]) {
            return dfs(a+u, b, m-u, n, k-u);
        }

        return dfs(a, b+v, m, n-v, k-v);
    }
    double findMedianSortedArrays(vector<int>& x, vector<int>& y) {
        int m = x.size(), n=y.size(), k=m+n;
        //cout << m << " " << n <<  ' ' << k << endl;
        if(k%2) {
            return dfs(x.data(), y.data(), m, n, (k+1)/2);
        }
        return (dfs(x.data(), y.data(), m, n, k/2)+
                dfs(x.data(), y.data(), m, n, k/2+1))/2.0;
    }
};
