class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxC=0,nowC;
        int i=0,j=height.size()-1;
        while(i!=j){
            nowC=(j-i)*min(height[i],height[j]);
            maxC=max(maxC,nowC);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxC;
    }
};


/*
1.采用skyline的方式比较直观，但时间复杂度无法降至O(n)，在最后四五个样例会遇到超时
2.双指针从头和尾往中间遍历，每次移动短的那一端
*/
