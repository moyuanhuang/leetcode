// 299. Bulls and Cows
// medium, 2-pass scan

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> umap;
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                umap[secret[i]]++;
            }
        }

        for(int i = 0; i < secret.size(); i++){
            if(secret[i] != guess[i]){
                if(umap[guess[i]] > 0){
                    // cout << guess[i] << " " << umap[guess[i]] << endl;
                    cows++;
                    umap[guess[i]]--;
                }
            }
        }
        ostringstream ss;
        ss << bulls << "A" << cows << "B";
        return ss.str();
    }
};
