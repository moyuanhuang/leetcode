#define BILLION = 1000000000;
#define MILLION = 1000000;
#define THOUSAND = 1000;
#define HUNDRED = 100;

class Solution {
public:
    string numberToWords(int num) {
      if(n == 0) return "Zero";
      else return int_string(n).substr(1);
    }

private:
    static const char * const below_20 = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    static const char * const Solution::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    static string int_string(int n){
      if(n >= BILLION) return int_string(n/BILLION) + "Billion" + int_string(n % BILLION);
      else if(n >= MILLION) return int_string(n / MILLION) + "Million" + int_string(n % MILLION);
      else if(n >= THOUSAND)  return int_string(n / THOUSAND) + "Thousand" + int_string(n % THOUSAND);
      else if(n >= HUNDRED) return int_string(n / HUNDRED) + "Hundred" + int_string(n % HUNDRED);
      else if(n >= 20)  return below_100[n / 10 - 2] + int_string(n % 10);
      else if (n >= 1) return below_20[n - 1];
      else return string("");
    }
};
