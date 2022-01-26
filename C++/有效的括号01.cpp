/* 
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s 
判断字符串是否有效

有效字符串需满足：
左括号必须用相同类型的右括号闭合
左括号必须以正确的顺序闭合

来源：力扣（LeetCode）
*/
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> store;
        auto strSize = s.size();
        if(strSize % 2 == 1){
            return false;
        }
        for (auto tmpChar : s)
        {
            char popChar = ' ';
            switch (tmpChar)
            {
            //如果是(,[,{,就压入栈中
            case '(':
            case '[':
            case '{':
                store.push(tmpChar);
                break;
            case ')':
                //注意栈为空的情况
                if (store.empty())
                {
                    return false;
                }
                popChar = store.top();
                store.pop();
                if (popChar != '(')
                {
                    return false;
                }
                break;
            case ']':
                if (store.empty())
                {
                    return false;
                }
                popChar = store.top();
                store.pop();
                if (popChar != '[')
                {
                    return false;
                }
                break;
            case '}':
                if (store.empty())
                {
                    return false;
                }
                popChar = store.top();
                store.pop();
                if (popChar != '{')
                {
                    return false;
                }
                break;
            default:
                return false;
                break;
            }
        }
        if (store.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
