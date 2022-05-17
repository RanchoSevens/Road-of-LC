class Solution{
public{
        int calculate1(string s) {
            istringstream in('+' + s + '+');
            long long total = 0, term = 0, n;
            char op;
            while (in >> op) {
                if (op == '+' or op == '-') {
                    total += term;
                    in >> term;
                    term *= 44 - op;
                } else {
                    in >> n;
                    if (op == '*')
                        term *= n;
                    else
                        term /= n;
                }
            }
            return total;
        }
    }
}

class Solution{
public{
        int calculate2(string s) {
                stringstream ss("+" + s);
                char op;
                int n, last, ans = 0;
                while (ss >> op >> n) {
                    if (op == '+' || op == '-') {
                        n = op == '+' ? n : -n;
                        ans += n;
                    } else {
                        n = op == '*' ? last * n : last / n;
                        ans = ans - last + n; // simulate a stack by recovering last values
                    }
                    last = n;
                }
                return ans;
          }
     }
}
/*
1.使用stringstream分别读入操作数与操作符，并自动忽略空格
*/
