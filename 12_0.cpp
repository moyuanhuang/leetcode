/*
 * 12. Integer to Roman
 * Created by Moyuan Huang on 8/26/2016
*/
class Solution {
public:
    string intToRoman(int num) {
    	vector<pair<int, char>> base = {make_pair(1000,'M'), make_pair(500,'D'), make_pair(100,'C'), 
    		make_pair(50,'L'), make_pair(10,'X'), make_pair(5,'V'), make_pair(1,'I')};
    	string result = "";
        for(int i = 0; i < base.size(); i++)
        {
        	int r = num % base[i].first;
        	int q = num / base[i].first;
        	if( q <= 3 )
        		for(int j = 0; j < q; j++)	result += base[i].second;
        	else
        	{
        		if(result.back() == base[i-1].second)
        		{
        			result[result.size()-1] = base[i].second;
        			result += base[i-2].second;
        		}
        		else
        		{
        			result += base[i].second;
        			result += base[i-1].second;
        		}
        	}
        	num = r;
        }
    	return result;
    }
};