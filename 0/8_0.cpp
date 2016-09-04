/*
 * 8. String to Integer(atoi)
 * Created by Moyuan Huang on 8.24.2016
*/ 
class Solution {
public:
    int myAtoi(string str)
    {
    	int result = 0;
    	int sign = 1;
    	int i = 0;
    	while(str[i] == ' ')
    	    i++;
    	if(str[i] == '-')
    	{
    		sign = -sign;
    		i += 1;
    	}
    	if(str[i] == '+')	i += 1;
    	cout << str << " " << str[0]<<  endl;
    	while(i < str.length())
    	{
    	    cout << str[i] << endl;
    // 		while(str[i] == ' ')
    // 		    i++;
    		if(str[i] >= '0' and str[i] <= '9')
    			result = result * 10 + (str[i] - '0');
    		else
    		{
    		    cout << str[i] << "  wtf" << endl;
    			break;
    		}
    		i++;
    		cout << result << endl;
    	}
    	return result * sign;

    }
};