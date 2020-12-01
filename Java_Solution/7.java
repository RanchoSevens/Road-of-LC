class Solution {
    public int reverse(int x) {
        int result = 0;
        int bot;
        while(x != 0)
        {
            bot = x % 10;
            int newResult = result * 10 + bot;
            if( (newResult - bot)/10 != result){
                return 0;
            }
            result = newResult;
            x = x / 10;
        }
        return result;
    }
}