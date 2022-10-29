// https://www.nowcoder.com/questionTerminal/d290db02bacc4c40965ac31d16b1c3eb
// 扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示(其中，小写joker表示小王，大写JOKER表示大王)∶
// 345678910JQKA2 joker JOKER
// 输入两手牌，两手牌之间用"∵"连接，每手牌的每张牌以空格分隔，""两边没有空格，如:444 4-joker JOKER。
// 请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
// 基本规则:
// (1)输入每手牌可能是个子、对子、顺子(连续5张)、三个、炸弹(四个)和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列;
// (2)除了炸单和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系(如，对子跟对子比较，三个跟三个比较)，不考虑拆牌情况(如:将对子拆分成个子) ;
// (3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小;顺子比较最小牌大小;炸弹大于前面所有的牌，炸弹之间比较牌面大小;对王是最大的牌;
// (4）输入的两手牌不会出现相等的情况。数据范围:字符串长度:3<s≤ 10


#include<iostream>
#include<string>
using namespace std;


// 牌序对应的字符，不满足实际字典序， 用一些字符替换掉原来的牌， 使其满足字典序
// 或者定义一个键值对，重新赋权重
int main()
{
    string str;
    getline(cin, str);
    
    //提取手牌
    int pos = str.find('-');
    string strL = str.substr(0, pos), strR = str.substr(pos + 1);
    
    //比较大小
    string left, right;
    bool l = true;
    
    for(int i = 0; i < str.size(); ++ i)
    {
        if(str[i] == ' ')//空格
        {
            continue;
        }
        if(str[i] == '-')//第二份手牌
        {
            l = false;
            continue;
        }
        
        //转换字符， 使其字典序和牌序一样
        if(str[i] == '1')//将 10 转换 成 @
        {
            ++i;
            str[i] = '@';
        }
        else if(str[i] == 'A')//将 A 转换 a
        {
            str[i] = 'a';
        }
        else if(str[i] == '2')//将 2 转换 b
        {
            str[i] = 'b';
        }
        else if(str[i] == 'Q')//将 Q 转换 K
        {
            str[i] = 'K';
        }
        else if(str[i] == 'K')//将 K 转换 Q
        {
            str[i] = 'Q';
        }
        
        if(l)
        {
            left += str[i];
        }
        else
        {
            right += str[i];
        }
    }
    
    if(left.size() == 1)//个子
    {
        if(right.size() == 1)//个子
        {
            cout << (right > left ? strR: strL);
        }
        // 炸弹， 对王， 单王
        else if(right.size() == 4 || right.size() == 10 || right == "joker" || right == "JOQER")
        {
            cout << strR;
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if(left.size() == 2)//对子
    {
        if(right.size() == 2)//对子
        {
            cout << (right > left ? strR: strL);
        }
        // 炸弹， 对王
        else if(right.size() == 4 || right.size() == 10)
        {
            cout << strR;
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if(left.size() == 3)//三个
    {
        if(right.size() == 3)//三个
        {
            cout << (right > left ? strR: strL);
        }
        // 炸弹， 对王
        else if(right.size() == 4 || right.size() == 10)
        {
            cout << strR;
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if(left.size() == 4)//炸弹
    {
        if(right.size() == 4)//炸弹
        {
            cout << (right > left ? strR: strL);
        }
        // 对王
        else if(right.size() == 10)
        {
            cout << strR;
        }
        else
        {
            cout << strL;
        }
    }
    else if(left.size() == 5 && left != "joker" && left != "JOQER")//顺子
    {
        if(right.size() == 5 && right != "joker" && right != "JOQER")//顺子
        {
            cout << (right > left ? strR: strL);
        }
        // 炸弹， 对王
        else if(right.size() == 4 || right.size() == 10)
        {
            cout << strR;
        }
        else
        {
            cout << "ERROR";
        }
    }
    else if(left == "joker" || left == "JOQER")
    {
        if(left == "joker")
        {
            if(right.size() == 1)
            {
                cout << strL;
            }
            else if(right == "JOQER")
            {
                cout << strR;
            }
            else if(right.size() == 4 || right.size() == 10)
            {
                cout << strR;
            }
            else
            {
                cout << "ERROR";
            }
        }
        else if(left == "JOQER")
        {
            if(right.size() == 1)
            {
                cout << strL;
            }
            else if(right == "joker")
            {
                cout << strL;
            }
            else if(right.size() == 4 || right.size() == 10)
            {
                cout << strR;
            }
            else
            {
                cout << "ERROR";
            }
        }
    }
    else if(left.size() == 10)
    {
        cout << strL;
    }
    
    
    return 0;
}