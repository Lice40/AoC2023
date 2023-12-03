#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    string filename = argv[1];
    ifstream file("./" + filename+".txt");
    string previous_line, current_line, next_line;
    string number;
    size_t pos;
    if(file.is_open()){
        while(file.good()){
            file>>current_line;
            file>>next_line;
            number.clear();
            for(int i = 0; i < current_line.length(); i++){
            }
        }
    }else{
        exit(EXIT_FAILURE);
    }

    //faire le dernier check ici;
    file.close();
    return 0;
}
