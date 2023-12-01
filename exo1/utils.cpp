#ifndef UTILS_H
#define UTILS_H

#include<map>
#include<iterator>
#include<string>
using namespace std;

string replaceSubStr(
    std::string str)
{
    //cout<<"INPUT "<<str<<endl;
    size_t pos;
    std::map<string, string> numbers{
        {"zero", "0"},
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four","4"},
        {"five","5"},
        {"six","6"},
        {"seven","7"},
        {"eight","8"},
        {"nine","9"},
    };

    std::map<string,string> specific{
        {"zerone", "01"},
        {"twone", "21"},
        {"oneight", "18"},
        {"threeight", "38"},
        {"fiveight", "58"},
        {"sevenine", "78"},
        {"eightwo","82"},
        {"eighthtee", "83"},
        {"nineight", "98"},
    };
    // Search for the given substring in string
    std::map<string,string>::iterator it= numbers.begin();

    std::map<string,string>::iterator it2= specific.begin();
    // Iterate till index position of substring is valid

    while(it2 != specific.end()){
        pos = str.find(it2->first);
        while (pos != std::string::npos)
        {   
            // Replace the first occurrence of substring in string
            // from position pos onwards
            //subStr.substr(0, subStr.length()-1)
            str.replace(pos, (it2->first).length(), it2->second);
            //str.insert(pos+replacement.length(), replacement);
            // Get the index position of next occurrence of substring in string
            pos = str.find(it2->first, pos + (it2->second).length());
        }
        it2++;
    }

    while(it != numbers.end()){
        pos = str.find(it->first);
        while (pos != std::string::npos)
        {   
            // Replace the first occurrence of substring in string
            // from position pos onwards
            //subStr.substr(0, subStr.length()-1)
            str.replace(pos, (it->first).length(), it->second);
            //str.insert(pos+replacement.length(), replacement);
            // Get the index position of next occurrence of substring in string
            pos = str.find(it->first, pos + (it->second).length());
        }
        it++;
    }
    
    return str;
}

#endif