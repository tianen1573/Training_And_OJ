class Solution {
public:
    bool isNumber(string s) {
        int k=0;
        while(s[k]==' ')k++;
        if(!isnum(s,k,1))return false;//判断前面的数是否合理
        if(s[k]=='e' || s[k]=='E'){
            k++;
            if(!isnum(s,k,0))return false;//整数判断
        }
        while(s[k]==' ')k++;
        return k==s.size();//若出现不满足条件的字符，k会卡在某个关节无法进行
    }
    bool isnum(string& s,int& k,int spot){
        if(s[k]=='+' || s[k]=='-')k++;
        int first=k+spot;
        while('0'<=s[k] && s[k]<='9' || s[k]=='.'){
            if(s[k]=='.'){
                spot--;
                if(spot<0)return false;
            }
            k++;
        }
        return first<k+spot;
    }
};

//作者：raven_z