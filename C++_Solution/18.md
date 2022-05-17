#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        const int len = nums.size();
        vector<vector<int>> res;
        if (len < 4) return res;
        sort(nums.begin(), nums.end());
        int i, j, k, l;
        for (i = 0; i < len - 3; ++i) {
            if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) continue;
            if (i > 0 && i < len - 3 && nums[i] == nums[i - 1]) continue;
            for (j = i + 1; j < len - 2; ++j) {
                if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target) continue;
                if (j > i + 1 && j < len - 2 && nums[j] == nums[j - 1]) continue;
                k = j + 1;
                l = len - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        ++k;
                        while (k < l && nums[k] == nums[k - 1]) ++k;
                    } else if (sum > target) {
                        --l;
                        while (k < l && nums[l] == nums[l + 1]) --l;
                    } else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        while (k < l && nums[k] == nums[k - 1]) ++k;
                        --l;
                        while (k < l && nums[l] == nums[l + 1]) --l;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution S;
    vector<int> num = {5, 0, 2, -5, -5, 4, -5, 1, -1};
    int target = -5;
    vector<vector<int>> res = S.fourSum(num, target);
    return 0;
}

/*
1.4Sum，你比3Sum多一重循环
2.处理时要注意continue和break的区别
*/
