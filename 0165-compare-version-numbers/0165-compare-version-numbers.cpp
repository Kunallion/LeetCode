class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1=0, num2=0, i, ind1=0, ind2=0;
        string s1="", s2="";
        while(ind1<version1.length() || ind2<version2.length())
        {
            for(i=ind1 ; i<version1.length() ; i++)
            {
                if(version1[i]!='.')
                {
                    s1 += version1[i];
                }
                else
                    break;
            }
            ind1=i+1;
            for(i=ind2 ; i<version2.length() ; i++)
            {
                if(version2[i]!='.')
                {
                    s2 += version2[i];
                }
                else
                    break;
            }
            ind2=i+1;
            if(s1.length()>0)
                num1 = stoi(s1);
            if(s2.length()>0)
                num2 = stoi(s2);
            if(num1<num2)
                return -1;
            else if(num1>num2)
                return 1;
            s1.clear();
            s2.clear();
            num1=0;
            num2=0;
        }
        return 0;
    }
};