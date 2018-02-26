#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution
{
  public:
    void f(string s, int level, const int n, set<string> &result)
    {
        if (level == n)
        {
            result.insert(s);
        }
        else
        {
            if (s == "")
            {
                f("()", level + 1, n, result);
            }
            else
            {
                for (int i = 0; i < s.length(); i++)
                {
                    f(s.substr(0, i) + "()" + s.substr(i), level + 1, n, result);
                }
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        set<string> result;
        f("", 0, n, result);
        return vector<string>(result.begin(), result.end());
    }
};
merge k sorted lists