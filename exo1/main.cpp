#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<map>
#include"utils.cpp"
using namespace std;






int main(){
    string digits, numbers, result;
    string test[2];
    int sum = 0;
    string line;
    ifstream file ("./inputs.txt");

    if(file.is_open()){

        while(file.good()){
            line.clear();
            digits.clear();
            numbers.clear();
            result.clear();
            file >> line;
            numbers=replaceSubStr(line);
            cout<<"ligne modif: "<<numbers<<endl;
            for(int i = 0; i < numbers.length(); i++){
                if(isdigit(numbers[i])){
                    if(digits.length()==0){
                        digits  = numbers[i];
                        digits = digits+numbers[i];
                    }else{
                        digits[1] = numbers[i];
                    }
                }
            }

            sum =   sum + stoi(digits);

            cout <<line<<endl<<"digit: "<<digits<<endl;

        }
        cout<<"result: "<<sum<<endl;
    }else{
        return -1;
    }
    /*
    string test = "twotowthreetwone";
    cout << "original: "<<test<<endl;
    replaceSubStr(test, "two", "2");
    cout<<"edit: "<<test<<endl;*/
    return 0;
}

