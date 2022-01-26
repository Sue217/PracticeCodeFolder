/* 
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s 
判断字符串是否有效

有效字符串需满足：
左括号必须用相同类型的右括号闭合
左括号必须以正确的顺序闭合

来源：力扣（LeetCode）
*/
class Solution {
public:
    bool isMatch(char left,char right)
    {
        switch(right)
        {
            case ')':
                return '(';
                break;
            case ']':
                return '[';
                break;
            case '}':
                return '{';
                break;
            default:
                return false;
                break;
        }
    }
    bool isValid(string s) 
    {
        stack<char> Stack;//建栈
        if(s.length() == 0)
        {//空栈返回true
            return true;
        }
        for(auto currentChar : s)//for(auto x : range)，创建拷贝，无法修改range中的元素
        {
            if(currentChar == ')' || currentChar == ']' || currentChar == '}')
            {
                if(Stack.empty() || !isMatch(Stack.top(),currentChar))
                {//如果此时栈为空，或者不满足匹配条件
                    return false;
                }
                else
                {
                    Stack.pop();//如果top元素与currentChar元素匹配，弹出top元素
                }
            }
            else
                {
                    Stack.push(currentChar);//如果输入的不是右括号，将左括号压入栈底
                }
        }
        if(Stack.empty())
            return Stack.empty();
            return false;
    }
};