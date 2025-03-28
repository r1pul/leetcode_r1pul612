class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1 );
        int i2, i3, i5;
        arr[1] = 1;
        i2 = i3 = i5 = 1;
        for (int i = 2; i <= n; i++) {
            int u2 = arr[i2] * 2;
            int u3 = arr[i3] * 3;
            int u5 = arr[i5] * 5;

            int uMin = min({u2, u3, u5});
            arr[i]=uMin;

            if (uMin == u2)
                i2++;
            if (uMin == u3)
                i3++;
            if (uMin == u5)
                i5++;
        }
        return arr[n];
    }
};