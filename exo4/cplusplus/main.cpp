#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include"utils.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int sum = 0;
    vector<int> copies(202, 1);
    ifstream file("./day_04.in");
    string line, working_line;
    int game = 0;
    if(file.is_open()){
        while(getline(file, line)){
            cout<<"Game "<<game<<endl;
            working_line = delete_first_element(split(line, ":")[1]);
            process_game(working_line, game, copies);
            game++;
        }

        for(auto x:  copies){
            cout<<x<<" , ";
            sum+=x;
        }
        cout<<endl;

        cout<<"résultat: "<<sum<<endl;
    }else{
        exit(EXIT_FAILURE);
    }
    return 0;
}
