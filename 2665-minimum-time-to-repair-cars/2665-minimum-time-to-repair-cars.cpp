class Solution {
public:
 typedef long long ll;  
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        ll l = 1;
        int maxe = *max_element(ranks.begin(),ranks.end());
        ll r = 1LL * maxe * cars * cars;
        ll res = 0;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if(bs(ranks,mid,cars)){
                res= mid;
                r = mid -1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
    bool bs(vector<int>& ranks , ll mid , int cars){
        ll fcar = 0;
        for(int i=0 ; i< ranks.size() ; i++){
            fcar += sqrt(mid/ranks[i]);

        }
        return fcar>=cars;
    }
};