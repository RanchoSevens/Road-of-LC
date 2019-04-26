#include<bits/stdc++.h>
using namespace std;
/*
 Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
        PINALSIGYAHRPI
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
 */
class Solution {
public:
    string convert(string s, int numRows) {
        string out;
        if(s.size()<3 || numRows==1){
            return s;
        }
        queue<int> qe[numRows];
        int now=-1;
        int inc=1;
        for(int i=0;i<s.size();i++){
            now+=inc;
            if(now<0){
                inc=1;
                now+=2;
            }else if(now>=numRows){
                inc=-1;
                now-=2;
            }
            qe[now].push(s[i]);
        }
        for(int i=0;i<numRows;i++){
            //        printf("%d\n",qe[i].size());
            while(!qe[i].empty()){
                out+=qe[i].front();
                qe[i].pop();
            }
        }
        return out;
    }
};

int main(){
    string s;
    int numRows;
    freopen("data.txt","r",stdin);
    while(cin>>s>>numRows!=EOF){
        queue<int> qe[numRows];
        int now=-1;
        int inc=1;
        for(int i=0;i<s.size();i++){
            now+=inc;
            if(now<0){
                inc=1;
                now+=2;
            }else if(now>=numRows){
                inc=-1;
                now-=2;
            }
            qe[i].push(s[i]);
        }
        for(int i=0;i<numRows;i++){
//        printf("%d\n",qe[i].size());
            while(!qe[i].empty()){
                printf("%c",qe[i].front());
                qe[i].pop();
            }
        }
    }
    return 0;
}

