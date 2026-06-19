class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height = 0;
        int maxi = 0;
        for(int i: gain){
            height += i;
            maxi = max(maxi, height);
        }
        return maxi;
    }
};