/* 38. Count and Say
 * Created by Moyuan Huang on Sep.20, 2016.
*/

class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        if(n < 1)	return "";
        if(n == 1)  return "1";
        for(int i = 0; i < n-1; i++)
        {
        	char prev = 0;
        	int count = 0;
        	string temp = "";
        	while(ret.length() > 0)
        	{
        		char first = ret[0];
        		ret.erase(ret.begin());
        		if(prev == 0)
        		{
        			prev = first;
        			count++;
        			continue;
        		}
        		if(first == prev)	count++;
        		else
        		{
        			temp += to_string(count);
        			temp.push_back(prev);
        			prev = first;
        			count = 1;
        		}
        	}
        	temp += to_string(count);
        	temp.push_back(prev);
        	ret = temp;
        // 	cout << i << ":" << ret << endl;
        }
        return ret;
    }
};