#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
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


vector<string> remove_all_occurences(vector<string> datas, string elt){
    vector<string> res;
    for(int i = 0; i<datas.size(); i++){
        if (datas[i] != elt){
            res.push_back(datas[i]);
        }
    }
    return res;
}

string delete_first_element(string s){
    if(s[0] == ' '){
        return s.erase(0,1);
    }else{
        return s;
    }
}

bool contains(string elt, vector<string> datas){
    for(int i =0; i < datas.size(); i++){
        if(datas[i] == elt){
            return true;
        }
    }
    return false;
        
}
void process_game(string  line,int idx, vector<int> &copies) {
    int wins=0;
    vector<string> datas = split(line,"|");
    vector<string> guess = remove_all_occurences(split(datas[0], " "),"");
    vector<string> winning_numbers = remove_all_occurences(split(datas[1], " "),"");
    cout<<endl;
        wins = 0;
        for(int nbE=0; nbE< guess.size(); nbE++){
            if(contains(guess[nbE], winning_numbers)){
                wins++;
            }
        }
        for(int i = idx+1; i<idx+wins+1; i++){
            if(i<copies.size()){
                copies[i]+= copies[idx];
            }
    }   
}