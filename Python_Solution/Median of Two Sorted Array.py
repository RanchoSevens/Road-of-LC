//use the sort function 
//will update soon

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums1.extend(nums2)
        nums=nums1
        nums.sort()
        num=len(nums)
        ind=int((num-1)/2)
        if num%2:
            res=nums[ind]
        else:
            res=(nums[ind]+nums[ind+1])/2
        return res
