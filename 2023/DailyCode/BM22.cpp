#include<iostream>
#include<string>

using namespace std;



int compare(string version1, string version2) {
        // write code here

        int pos1 = 0, pos2 = 0;

        while(~pos1 || ~pos2)
        {
            int p1 = version1.find('.', pos1);
            int p2 = version2.find('.', pos2);


            int v1 = stoi(pos1 == -1 ? "0" : version1.substr(pos1, p1 - pos1));
            int v2 = stoi(pos2 == -1 ? "0" : version2.substr(pos2, p2 - pos2));

            if(v1 != v2)
                if(v1 > v2) return 1;
                else return -1;

            pos1 = p1 == -1 ? -1 : p1 + 1;
            pos2 = p2 == -1 ? -1 : p2 + 1;

        }

        return 0;
    }

    int main()
    {
        int ret = compare("1","1.1");

        return 0;
    }