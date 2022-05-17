class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        const int len = s.size();
        bool result = true;
        stack<char> st;
        string left="([{";
        string right=")]}";

        st.push(s[0]);
        int index = 1;
        while(!s.empty()&&index<len){
            if(left.find(st.top())!=string::npos){//是左值
                int x = left.find(st.top());
                if(s[index]==right[x]){
                    st.pop();//匹配上
                    if(st.empty()&&index+1<len){
                        st.push(s[++index]);
                    }
                }
                else st.push(s[index]);//未匹配
                index++;
            }else{//不是左值
                st.push(s[index++]);
            }

        }
        if(!st.empty()||index<len){
            result=false;
        }
        return result;
    }
};
/*
1.在pop时需要判断栈空，如果因为出栈导致栈空而字符串还未读到最后，要额外进栈保证循环不跳出
*/
