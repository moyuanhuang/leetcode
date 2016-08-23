class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty())   return "";
        if(numRows == 1)    return s;
        int row = 0;
        int delta = 1;
        vector<string> temp(numRows,"");
        for(int i = 0; i < s.length(); i++)
        {
            temp[row] += s[i];
            row += delta;
            if(row == numRows)
            {
                row -= 2;
                delta = -1;
            }
            if(row == -1)
            {
                row += 2;
                delta = 1;
            }
        }
        string res;
        for(int i = 0; i < numRows; i++)
            res += temp[i];
        return res;
    }
};