// 717. 1-bit and 2-bit Characters
// easy

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while(i < bits.size() - 1){
            if(bits[i] == 1){
                i++;
            }
            i++;
            // cout << i << endl;
        }
        // cout << "final : " << i << endl;
        return i != bits.size();
    }
};
