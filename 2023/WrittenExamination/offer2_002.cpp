class Solution {
public:
    string addBinary(string a, string b) {

        string res;

        int i = a.size() - 1, j = b.size() - 1;

        int carry = 0;

        while(i >= 0 || j >= 0 || carry > 0)
        {
            int ii = i >= 0 ? a[i--] - '0' : 0;
            int jj = j >= 0 ? b[j--] - '0' : 0;


            int sum = ii + jj + carry;
            carry = sum / 2;
            char ch = sum % 2 + '0';
            res.push_back(ch); 
        }

        reverse(res.begin(), res.end());

        return res;

    }
};