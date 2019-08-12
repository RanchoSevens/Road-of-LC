#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        map<char, int> mp;
        mp['+'] = mp['-'] = 1;
        mp['*'] = mp['/'] = 2;

        stack<char> st;
        stack<int> exp;
        int i = 0, len = s.size(), dg;
        char c;
        while (i < len || !st.empty()) {
            if (i == len) {
                sw(st,mp,exp);
                continue;
            }
            c = s[i];
            if (isdigit(c)) {//操作数
                char digit[40];
                digit[0] = c;
                ++i;
                c = s[i];
                int k = 1;
                while (isdigit(c)) {
                    digit[k++] = c;
                    c = s[++i];
                }

                while (c == ' ') {
                    c = s[++i];
                }

                digit[k] = '\0';
                sscanf(digit, "%d", &dg);
                exp.push(dg);
            } else if (c == ' ') {
                while (c == ' ') {
                    c = s[++i];
                }
            } else {
                if(st.empty()||exp.size()<2||c=='('){
                    if(c==')') st.pop();
                    else st.push(c);
                    ++i;
                }else{
                    if(c==')'){
                        cout<<st.top()<<endl;
                        while(st.top()!='('){
                            sw(st,mp,exp);
                        }
                        cout<<"now="<<st.top()<<endl;
                        cout<<"exp="<<exp.top()<<endl;
                        st.pop();
                    }else{
                        char r=compare(c,st.top(),mp);
                        while(r=='='||r=='<'){
                            sw(st,mp,exp);
                            if(st.empty())
                                break;
                            else{
                                r=compare(c,st.top(),mp);
                            }
                        }
                        st.push(c);
                    }
                    i++;
                }
            }
        }
        return exp.top();
    }

    void sw(stack<char> &st, map<char, int> &mp, stack<int> &exp) {
        int a = exp.top();
        exp.pop();
        int b = exp.top();
        exp.pop();
        cout<<b<<st.top()<<a<<endl;
        a = cal(a, b, st.top());
        st.pop();
        exp.push(a);
    }

    char compare(char a, char b, map<char, int> &mp) {
        if (mp[a] > mp[b]) return '>';
        else if (mp[a] == mp[b]) return '=';
        else return '<';
    }

    int cal(int a, int b, char op) {
        int result = 0;
        switch (op) {
            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '*':
                result = b * a;
                break;
            case '/':
                result = b / a;
                break;
        }
        return result;
    }
};

/*
1.使用调度场算法将中缀表达式转为后缀
2.操作数压栈，操作符运算
3.字符优先级相等的情况下要先计算栈里的，栈优先级大于的也要先计算，只有栈优先级小于当前优先级，压栈
4.操作数和操作符都用栈表示，且后出栈的元素对先出栈元素操作
*/

int main() {
    string s = "1*2-3/4+5*6-7*8+9/10";
    Solution S;
    printf("result = %d\n", S.calculate(s));
    return 0;

}
