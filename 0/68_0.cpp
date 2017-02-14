class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		vector<string> ret;
		for(int i = 0; i < words.size(); i++)
		{
			string temp = "";
			int l = maxWidth;
			int cnt = 0;
			int index = i;
			while(maxWidth - words[index].size() >= 0)
			{
				l -= words[index].size();
				index++;
				cnt++;
			}
			int spaces = l/cnt;
			int ext = l%cnt;
			for(int j = 0; j < cnt - 1; j++)
			{
				temp += words[i];
				temp += j < ext? string(spaces, " "): string(spaces+1, " ");
				i++;
			}
			temp += words[i];
			cout << "this time:" << temp << endl;
		}
		return ret;
	}
};