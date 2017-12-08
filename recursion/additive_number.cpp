class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size()/2; ++i){
            for(int j=1; j<=(num.size()-i)/2; j++){
                bool temp = find_next(num.substr(0,i), num.substr(i, j), num.substr(i + j));
                if(temp)    return true;
            }
        }
        return false;
    }

private:
    bool find_next(string n1, string n2, string num){
        if((n1.size() > 1 and n1[0] == '0') or (n2.size() > 1 and n2[0] == '0'))    return false;
        string sum = add(n1, n2);
        if(sum == num)  return true;
        if(sum.size() <= num.size() and sum.compare(num.substr(0, sum.size())) == 0){
            cout << "beginning two: " << n2 << " " << sum <<  " "  << num.substr(sum.size()) << endl;
            return find_next(n2, sum, num.substr(sum.size()));
        }
        return false;
    }

    string add(string a, string b){
        string res;
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        while(i >= 0 or j >= 0){
            int d = (i >= 0? (a[i] - '0') : 0) + (j >= 0? (b[j] - '0') : 0) + carry;
            carry = d / 10;
            d = d % 10;
            res.push_back(d + '0');
            i--; j--;
        }
        if(carry)   res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
