// website:https://leetcode.com/problems/longest-substring-without-repeating-characters/

//at first i want to use brutal force in python3
//like this

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        num=len(s)
        maxn=0
        for i in range(num):
            maxi=1
            j=i+1
            dur=[]
            while(j<num and s[i]!=s[j] and (s[j] not in dur)):
                dur.append(s[j])
                j=j+1
                maxi=maxi+1
            if maxi>maxn:
                maxn=maxi
        return maxn
        
//when i submit the operations tell me that time limit exceeded
//then i see the solutions other people write
//one is this:create a list that claims the longest substring when start from this position
//then find the maximum length of the list

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        num=len(s)
        maxn=0
        sublist=[s[i] for i in range(num)]
        for i,char in enumerate(s):
            if i<num-1:
                j=i+1
                while s[j] not in sublist[i]:
                    sublist[i]=sublist[i]+s[j]
                    j=j+1
                    if j==num:
                        break
        lens=[len(sublist[i]) for i in range(num)]
        if num!=0:
            maxn = max(lens)
        return maxn
        
//the problem of above is still not efficient
//use hash method
//keep a dict type to store the position of character
//use a start to store the fomer repetition as the start position
//to count the substring.Code is as below

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start=-1
        maxn=0
        d={}
        num=len(s)
        for i in range(num):
            if s[i] in d and d[s[i]]>start:
                start=d[s[i]]
                d[s[i]]=i
            else:
                d[s[i]]=i
                if i-start>maxn:
                    maxn=i-start
        return maxn

