class Solution {
public:
    int maxArea(vector<int>& height) {
      int n = height.size();
      int r=0;
      int l = n-1;
      int maxa=0;
      while(r<l)
      {
        maxa=max(maxa,(l-r) * min(height[l],height[r]));
        if(height[r]<height[l])
        r++;
        else
        l--;
      }
      return maxa;
    }
};