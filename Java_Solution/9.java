/*
1. Simple Solution
*/
class Solution {
    public boolean isPalindrome(int x) {
        char[] s1 = String.valueOf(x).toCharArray();
        int len = s1.length;
        for(int i=0;i<len/2;++i){
            if(s1[i] != s1[len-1-i]){
                return false;
            }
        }
        return true;
    }
}

/*
Other's Solution
1. x can't be the factor of 10
2. x==recv || x=recv/10 means odd or even
*/
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0 || (x!=0)&&(x%10==0)) return false;
        int recv = 0;
        while(x > recv){
            recv = recv * 10 + x % 10;
            x /= 10;
        }
        return (x==recv)||(x==recv/10);
    }
}
