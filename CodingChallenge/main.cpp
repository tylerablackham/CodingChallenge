#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;


int toDecNum(string RomanNum){
    map<char,int> constants;
    constants['I'] = 1; constants['V'] = 5; constants['X'] = 10; constants['L'] = 50;
    constants['C'] = 100; constants['D'] = 500; constants['M'] = 1000;
    vector<int> numbers;
    for (auto s: RomanNum){
        s = std::toupper(s);
        if (!constants.count(s)){
            throw invalid_argument("Invalid Roman Numeral"); //make sure all characters are valid roman numerals
        }
        numbers.push_back(constants[s]);
    }
    set<int> nums;
    nums.insert(1000); nums.insert(900); nums.insert(50); nums.insert(400);
    nums.insert(100); nums.insert(90); nums.insert(50); nums.insert(40);
    nums.insert(10); nums.insert(9); nums.insert(5); nums.insert(4); nums.insert(1);
    int decimalNum = 0;
    for (int i = 0; i<numbers.size(); i++){
        int add = numbers[i];
        if (i+1 < numbers.size()){
            if(numbers[i] < numbers[i+1]){
                add = numbers[i+1] - numbers[i];
                if (!nums.count(add)){
                    throw invalid_argument("Invalid Roman Numeral"); //make sure Roman Numerals are in valid order
                }
                i++;
            }
        }
        decimalNum += add;
    }
    return decimalNum;
}
string toRomNum(int DecimalNum){
    if (DecimalNum < 1){
        throw invalid_argument("Number must be larger than zero"); //Makes sure number is a positive number
    }
    map<int,string> constants; constants[1] = "I"; constants[4] = "IV"; constants[5] = "V";
    constants[9] = "IX"; constants[10] = "X"; constants[40] = "XL"; constants[50] = "L";
    constants[90] = "XC"; constants[100] = "C"; constants[400] = "CD";constants[500] = "D";
    constants[900] = "CM"; constants[1000] = "M";
    vector<int> nums;
    nums.push_back(1000); nums.push_back(900); nums.push_back(500); nums.push_back(400);
    nums.push_back(100); nums.push_back(90); nums.push_back(50); nums.push_back(40);
    nums.push_back(10); nums.push_back(9); nums.push_back(5); nums.push_back(4); nums.push_back(1);
    string RomanNum = "";
    for (int i:nums){
        int temp = DecimalNum / i;
        for(int n = 0; n < temp; n++) {
            RomanNum += constants[i];
        }
        DecimalNum = DecimalNum - (temp*i);
    }
    return RomanNum;

}
int main() {

    bool keep_going = true;
    while(keep_going){
        cout << "What would you like to do? Please type 1, 2, or 3" << endl
        << "(1) Convert Roman Numeral to Decimal Number" << endl
        << "(2) Convert Decimal Number to Roman Number" << endl
        << "(3) Quit" << endl;
        int k = 0;
        cin >> k; cout << endl;
        if (k == 1){
            cout << "Please type the Roman Numeral you would like me to convert" << endl;
            string romNum;
            cin >> romNum;
            int decNum = toDecNum(romNum);
            cout << romNum << " converted to Decimal is: " << decNum << endl << endl;
        }
        if (k == 2){
            cout << "Please type the Decimal Number you would like me to convert" << endl;
            int decNum;
            cin >> decNum;
            string romNum = toRomNum(decNum);
            cout << decNum << " converted to Roman Numerals is: " << romNum << endl << endl;
        }
        if (k == 3){
            keep_going = false;
        }
    }

    return 0;
}
