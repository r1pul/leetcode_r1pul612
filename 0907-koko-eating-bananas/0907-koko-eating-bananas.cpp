class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int n = piles.size();
      int l = 1;
      int r = *max_element(piles.begin(),piles.end());
      while(l<r){
        int mid = l + (r-l)/2;
        if(caneat(piles,h,mid))
        r = mid;
        else
        l=mid+1;
      }
      return l;  
    }
    bool caneat(vector<int>& piles , int h , int mid){
        int ach = 0;
        for(auto &vec : piles){
            ach += vec/mid;
            if(vec%mid != 0)
            ach++;
        }
        return ach <= h ;
    }
};