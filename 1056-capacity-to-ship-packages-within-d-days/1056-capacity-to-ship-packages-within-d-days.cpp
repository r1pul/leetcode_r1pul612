class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        long long sum=0, maxi=0;
        for(int  wt: weights){
            sum+=(long long)wt;
            maxi=max(maxi,(long long)wt);
        }

        int low=maxi, high=sum, ans=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    bool isValid(vector<int>&weights, int cap, int days){
        int day=1, load=0;
        int n=weights.size();
        for (int wt : weights) {
            if (load + wt > cap) {
                day++;
                load = 0;
            }
            load += wt;
            if(day>days)return false;
        }
        return true;
    }
};