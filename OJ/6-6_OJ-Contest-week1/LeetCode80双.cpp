#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/biweekly-contest-80 */

/*强密码检验器Ⅱ*/
//class Solution {
//public:
//    bool strongPasswordCheckerII(string password) {
//
//        if (password.size() < 8) return false;
//
//        string str = "!!@#$%^&*()-+";
//        bool lowchar, upchar, num, id;
//        lowchar = upchar = num = id = false;
//        for (int i = 1; i < password.size(); i++)
//        {
//            if (password[i] == password[i - 1]) return false;
//            if (password[i] >= 'a' && password[i] <= 'z') lowchar = true;
//            if (password[i] >= 'A' && password[i] <= 'Z') upchar = true;
//            if (password[i] >= '0' && password[i] <= '9') num = true;
//            if (str.find(password[i]) != -1)  id = true;
//        }
//        if (password[0] >= 'a' && password[0] <= 'z') lowchar = true;
//        if (password[0] >= 'A' && password[0] <= 'Z') upchar = true;
//        if (password[0] >= '0' && password[0] <= '9') num = true;
//        if (str.find(password[0]) != -1)  id = true;
//
//        if (lowchar && upchar && num && id) return true;
//        else return false;
//    }
//};

/*成功对数*/
//class Solution {
//
//public:
//    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//        sort(potions.begin(), potions.end());
//
//        for (int i = 0; i < spells.size(); i++)
//        {
//            long long  x = ((success % spells[i]) ? (success / spells[i]) + 1 : (success / spells[i]));
//            spells[i] = potions.end() - lower_bound(potions.begin(), potions.end(), x);
//        }
//
//        return spells;
//    }
//};
