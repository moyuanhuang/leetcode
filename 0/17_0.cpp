/* 17. Letter Combinations of a Phone Number
 * Created by Moyuan Huang on Sep.3, 2016.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(!digits.length())    return res;
        vector<string> digitMapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < digitMapping[digits[0]-'0'].length(); i++)
        {
            string temp = "";
            temp.push_back(digitMapping[digits[0]-'0'][i]);
            res.push_back(temp);
        }
        for(int i = 1; i < digits.length(); i++)
        {
        	vector<string> temp;
        	for(int j = 0; j < res.size(); j++)
        	{
        	    int digit = digits[i] - '0';
        		for(int k = 0; k < digitMapping[digit].length(); k++)
        		{
        		    string incomplete = res[j];
        		    incomplete.push_back(digitMapping[digit][k]);
        		    temp.push_back(incomplete);
        		}
        	}
        	res = temp;
        }
        return res;
    }
};
