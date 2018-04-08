// 681. Next Closest Time
// medium
// 1. turn string time into integer
// 2. increment time to and map back to string
// 3. check each digit
class Solution {
public:
    string nextClosestTime(string time) {
        int cur = 60 * stoi(time.substr(0, 2)) + stoi(time.substr(3));
        unordered_set<int> digits;
        for(char c : time){
            if(c == ':')    continue;
            digits.insert(c - '0');
        }

        while(true){
            cur = (cur + 1) % (24 * 60);
            int temp[4] = {cur / 60 / 10, (cur / 60 ) % 10, cur % 60 /10, (cur % 60) % 10 };
            for(int i = 0; i < 4; i++){
                cout << temp[i] << " ";
            }
            cout << endl;
            bool is_valid = true;
            for(int i = 0; i < 4; i++){
                if(digits.count(temp[i]) == 0){
                    is_valid = false;
                    break;
                }
            }
            if(is_valid){
                char buffer[5];
                ostringstream oss;
                sprintf(buffer, "%02d:%02d", cur / 60, cur % 60);
                oss << buffer;
                return oss.str();
            }
        }
        return "";
    }
};
