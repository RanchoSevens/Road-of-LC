class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if(n==0) return false;
        if (target < matrix[0][0]) return false;
        if (target > matrix[m - 1][n - 1]) return false;
        int low, high, left, right;
        low=0,high=m-1,left=0,right=n-1;
        while (low < high) {//找到行
            int mid = (low + high) / 2;
            if (target < matrix[mid][0]) high = mid - 1;
            else if (target > matrix[mid][0]) {
                if (target < matrix[mid][n - 1]) {
                    low = mid;
                    break;
                } else if (target > matrix[mid][n - 1]) {
                    low = mid + 1;
                } else {
                    return true;
                }
            } else return true;
        }
//        printf("%s", typeid(matrix[low]).name());
//        vector<int> *p = *(matrix[low]);
        while (left < right) {
            int mid = (left + right) / 2;
            if (target < matrix[low][mid]) {
                right = mid - 1;
            } else if (target > matrix[low][mid]) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        if(matrix[low][left]==target){
            return true;
        }
        return false;
    }
};
/*
1.对二分查找返回的状态要多加分析
*/
