
//https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=29311&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

class Gift 
{
public:
    int getValue(vector<int> gifts, int n) 
    {
        map<int,int> count;
        int middle = gifts.size() / 2;
        for(const auto& e : gifts)
        {
            ++count[e];
        }
        for(const auto& e : count)
        {
            if(e.second >= middle)
                return e.first;
        }
        return 0;
    }
};
