#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        vector<int> result;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
            else {
                int left, right;

                left = low;
                right = mid;
                while (left < right) {
                    if (nums[left] == target) break;
                    else if (nums[left] < target) left++;
                    int leftmid = (left + right) / 2;
                    if (nums[leftmid] < target) left = leftmid + 1;
                    else right = leftmid;
                }
                result.push_back(left);

                left = mid;
                right = high;
                while (left < right) {
                    if (nums[right] == target) break;
                    else if (nums[right] > target) right--;
                    int rightmid = (left + right) / 2;
                    if (nums[rightmid] > target) right = rightmid - 1;
                    else left = rightmid;
                }
                result.push_back(right);
                return result;
            }
        }
        for (int i = 0; i < 2; ++i) {
            result.push_back(-1);
        }
        return result;
    }
};

int main() {
    Solution S;
    vector<int> inp = {2, 2};
    int target = 2;
    vector<int> oup = S.searchRange(inp, target);
    for (int i = 0; i < 2; ++i) {
        printf("%d\n", oup[i]);
    }
    return 0;
}
