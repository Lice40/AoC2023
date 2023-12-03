#ifndef UTILS_H
#define UTILS_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> split(string s, string delim){
    size_t pos_start = 0, pos_end, delim_len = delim.length();
    string token;
    vector<string> res;
    while((pos_end = s.find(delim, pos_start)) != std::string::npos){
        token = s.substr(pos_start,pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}


string delete_first_element(string s){
    if(s[0] == ' '){
        return s.erase(0,1);
    }else{
        return s;
    }
}

bool check_validity(string s, int& square_min){
    vector<std::string> games, tirages, units;
    int min[3]={0,0,0};//r, g, b
    int value;
    string key;
    bool valid = true;
    games = split(s, ";");
    for(auto game:games){
        tirages = split(delete_first_element(game), ",");
        for (auto tirage:tirages){
            units = split(delete_first_element(tirage), " ");
            
            value = stoi(units[0]);
            key = units[1];
            cout<<"value: "<<value<<" key: "<<key<<endl;

            if(key == "red"){

                if(value > 12){
                    valid =  false;
                }
                
                if(min[0] == 0){
                    min[0] = value;
                }

                if(value > min[0]){
                    min[0] = value;
                }
            }

            if (key =="green" ){
                
                if(value > 13){
                    valid =  false;
                }
                
                if(min[1] == 0){
                    min[1] = value;
                }

                if(value > min[1]){
                    min[1] = value;
                }
            }

            if( key =="blue"){
                
                if(value > 14){
                    valid =  false;
                }
                
                if(min[2] == 0){
                    min[2] = value;
                }

                if(value > min[2]){
                    min[2] = value;
                }
            }
            
        }
    }
    square_min = min[0]*min[1]*min[2];
    return valid;

}

#endif