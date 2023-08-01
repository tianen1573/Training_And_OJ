class Solution {
public:
    
    bool judge(string str) {
        
        int l = 0, r = str.size() - 1;

        while(l < r)
        {
            if(str[l ++] != str[r --])
                return false;
        }
        return true;

    }
};