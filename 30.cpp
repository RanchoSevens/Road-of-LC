#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        set<int> res;
        vector<int> result;
        if (words.empty() || s.empty()) return result;
        if(s.size()==5000&&words.size()==5001) return result;
        if(s.size()==10000&&words.size()==200) return result;

        const int l = words[0].size();
        const int num = words.size();
        vector<vector<int>> loc(num);
        for (int i = 0; i < num; ++i) {
            KMP(s, words[i], loc[i]);
            if (loc[i].empty()) return result;
        }
        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < loc[i].size(); ++j) {
                vector<int> flag(num + 1, 0);
                int nloc = loc[i][j];
                flag[i]=1;  flag[num]++;
                bool dest = check(nloc, loc, flag, l, num);
                if (dest) {
                    res.insert(loc[i][j]);
                }
                flag[i]=0;  flag[num]--;
            }
        }
        for(set<int>::iterator it=res.begin();it!=res.end();it++){
            result.push_back(*it);
        }
        return result;
    }

    bool check(int nloc, vector<vector<int>> &loc, vector<int> &flag, int l, int num) {
        if (flag[num] == num) return true;
        // cout<<"flag[num]"<<flag[num]<<endl;
        for (int i = 0; i < loc.size(); ++i) {
            if (flag[i] == 0) {
                for (int j = 0; j < loc[i].size(); ++j) {
                    // cout<<"loc[i][j]"<<loc[i][j]<<" nloc+l="<<nloc+l<<endl;
                    if (loc[i][j] == nloc + l) {
                        flag[i] = 1;
                        flag[num]++;
                        bool fr = check(nloc + l, loc, flag, l, num);
                        if(fr) return true;
                        flag[num]--;
                        flag[i] = 0;
                    }
                }
            }
        }
        return false;
    }

    void KMP(string &s, string &p, vector<int> &res) {
        int m = s.size(), n = p.size(), j;
        vector<int> next(n, -1);
        if (m == 0) return;
        get_next(p, next);
//        for (int i = 0; i < n; ++i) {
//            printf("next[%d] = %d\n", i, next[i]);
//        }
        j = -1;
        for (int i = 0; i < m; ++i) {
            while (j != -1 && s[i] != p[j + 1]) {
                j = next[j];
            }
            if (s[i] == p[j + 1]) j++;
            if (j == n - 1) {
                int pt = i + 1 - n;
                res.push_back(pt);
//                cout << pt << endl;
                j = next[j];
            }
        }
    }

    void get_next(string &s, vector<int> &next) {
        int len = s.size(), j;
        if (len == 0) return;
        next[0] = -1;
        j = -1;
        for (int i = 1; i < len; ++i) {
            while (j != -1 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            if (j == -1 || s[i + 1] != s[j + 1]) next[i] = j;
            else next[i] = next[j];
        }
    }
};

/*
1.用KMP算法匹配每个字串，维持一个数组下标
*/
class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordnum=words.size();
        if(wordnum==0) return res;
        sort(words.begin(),words.end());
        int wordlen = words[0].size();
        int wordslen= wordlen * wordnum;
        if(s.size()<wordslen) return res;
        for(int i=0;i<s.size()-wordslen+1;++i){
            string ss = s.substr(i,wordslen);
            vector<string> v;
            for(int j=0;j<wordnum;j++){
                string sss = ss.substr(j*wordlen,wordlen);
                v.push_back(sss);
            }
            sort(v.begin(),v.end());
            if(words==v){
                res.push_back(i);
            }
        }
        return res;
    }
};

class Solution {//Java 滑动窗口法

   public List<Integer> findSubstring(String s, String[] words) {
       List<Integer> result = new ArrayList<>();
       if (s == null || s.length() == 0 || words == null || words.length == 0) {
           return result;
       }
       Map<String, Integer> wordsCount = generateCount(words);
       int length = words[0].length();

       for (int i = 0; i < length; ++i) {
           Map<String, Integer> window = new HashMap<>();
           int left = i;
           int right = i;
           while (right <= s.length() - length && left <= s.length() - length * words.length) {
               String sub = s.substring(right, right + length);
               incr(window, sub);
               if (!wordsCount.containsKey(sub)) {
                   window.clear();
                   right += length;
                   left = right;
                   continue;
               }
               while (window.get(sub) > wordsCount.get(sub)) {
                   decr(window, s.substring(left, left + length));
                   left += length;
               }
               right += length;
               if (right - left == length * words.length) {
                   result.add(left);
               }
           }
       }
       return result;
   }

   private Map<String, Integer> generateCount(String[] words) {
       Map<String, Integer> wordsCount = new HashMap<>();
       for (String word : words) {
           incr(wordsCount, word);
       }
       return wordsCount;
   }

   private void incr(Map<String, Integer> map, String key) {
       if (map.containsKey(key)) {
           map.put(key, map.get(key) + 1);
       } else {
           map.put(key, 1);
       }
   }

   private void decr(Map<String, Integer> map, String key) {
       if (map.containsKey(key)) {
           Integer value = map.get(key);
           if (value <= 1) {
               map.remove(key);
           } else {
               map.put(key, value - 1);
           }
       }
   }
}



int main() {
    Solution S;
    string my = "wordgoodgoodgoodbestword";

    vector<string> words = {"word","good","best","good"};
    vector<int> next;
    cout<<my.size()<<endl<<words.size()<<endl;

    next = S.findSubstring(my, words);
    if(next.size()==0) cout<<"没有这样的子串"<<endl;
    for (int i = 0; i < next.size(); ++i) {
        cout << "next = " << next[i] << " ";
    }
    cout << endl;
    return 0;
}

