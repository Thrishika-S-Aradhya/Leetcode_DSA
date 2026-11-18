class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(unordered_map<int, int>& freq, vector<int>& permutation) {
        if (permutation.size() == n) {
            result.push_back(permutation);
            return;
        }

        for (auto& [num, count] : freq) {
            if(count != 0) {
                permutation.push_back(num);
                freq[num]--;

                solve(freq, permutation);

                permutation.pop_back();
                freq[num]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        vector<int> permutation;
        unordered_map<int, int> freq;

        for (auto& num : nums)
            freq[num]++;

        solve(freq, permutation);

        return result;
    }
};