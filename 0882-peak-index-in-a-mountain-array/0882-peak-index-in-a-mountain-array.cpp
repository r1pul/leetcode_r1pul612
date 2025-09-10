class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int  i =0, n = arr.size();
        while(i < n && arr[i]<arr[i+1])
            i++;
            return i;
    }
};