#include<iostream>
#include<fstream>
#include<string>
#include"utils.cpp"
using namespace std;

int main(int argc, char const *argv[])
{     
    string filename = argv[1];
    int game_counter = 1, sum_valid = 0, sum_min = 0, min;
    bool valid;
    string line;
    string working_str= "";
    ifstream file ("./"+filename+".txt");
    vector<string> v;

    if(file.is_open()){
        while (getline(file, line)){
            working_str.clear();
            v = split(line, ":");
            working_str = delete_first_element(v[1]);
            valid = check_validity(working_str, min);

            cout<<"game "<<game_counter<<": "<<valid<<endl<<"power: "<< min<<endl;
            if(valid){
                sum_valid += game_counter;
            }
            sum_min += min;
            game_counter++;
        }
    }else{
        return -1;
    }
    file.close();

    cout<<"résultat: "<<sum_valid<<endl<<"power: "<<sum_min<<endl;
    return 0;
}


