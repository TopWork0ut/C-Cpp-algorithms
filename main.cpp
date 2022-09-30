#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        return intToBinaryString(calculateBinary(a) + calculateBinary(b));
    }

    int calculateBinary(string a){
        int num = 0;
        for(int i = a.size() - 1; i >= 0; i--){
            if((int)a.at(i) - 48 == 1){
                num += pow(2,a.size()-i-1);
            }
        }
        return num;
    }

    string intToBinaryString(int num3){
        int num = num3;
        string k = "0";
        int n = 0;
        while(pow(2,n) < num3){
            n++;
        }
        if(pow(2,n) > num3) {
            n--;
        }
        while(calculateBinary(k) < num3){
            if((num - pow(2,n)) >= 0){
                k.push_back('1');
                num -= pow(2,n);

            }else{
                k.push_back('0');
            }
            n--;
        }
        if(k.at(0) == '0' && k.size()==1){
           /*nothing*/
        }else{
            k.erase(0,1);
        }
        return k;
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("1011","10100") << endl;
    /*1011 = 11
    10100 = 20
    11111 = 31*/

    return 0;
}


