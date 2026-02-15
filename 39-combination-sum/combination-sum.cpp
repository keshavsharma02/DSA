class Solution {
public:

        void helper(vector<int> & candidates, vector<int> & vec, set<vector<int>> & result, 
        int target, int sum)
        {
            if(sum == target)
            {
                vector<int> vec1 = vec;
                sort(vec1.begin(), vec1.end());
                result.insert(vec1);
                return;
            }
            if(sum > target) return;
            for(int i = 0; i < candidates.size(); ++i)
            {
                sum += candidates[i];
                vec.push_back(candidates[i]);
                helper(candidates, vec, result, target, sum);
                vec.pop_back();
                sum -= candidates[i];
            }
        }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        set<vector<int>> result;
        int sum  = 0;
        helper(candidates, vec, result, target, sum);
        vector<vector<int>> res(result.begin(), result.end());
        return res;
    }
};