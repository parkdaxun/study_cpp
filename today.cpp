//
//  today.cpp
//  study-cpp
//
//  Created by 박다은 on 2022/06/27.
//
#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    int len;
    char* str;
public:
    String() : len(0){
        len = 0;
        str = NULL;
        
    };
    String(const char* s) {
        len = strlen(s)+1;
        str = new char[len];
        strcpy(str, s);
    };
    String(const String& s) {
        len = s.len;
        str = new char[len];
        strcpy(str, s.str);
    };
    ~String() {
        delete[] str;
    };
    String& operator=(const String& s) {
        if(str!=NULL)
            delete[] str;
        len = s.len;
        str = new char[len];
        strcpy(str, s.str);
        return *this;
    }
    String& operator+=(const String& s) {
        len+=(s.len-1);
        char* temp = new char[len];
        strcpy(temp, str);
        strcat(temp, s.str);
        
        if(str!=NULL)
            delete[] str;
        str = temp;
        
        return *this;
    }
    bool operator==(const String& s) {
        return strcmp(str, s.str) ? false : true;
    }
    String operator+(const String& s) {
        char* temp = new char[len+s.len-1];
        strcpy(temp, str);
        strcat(temp, s.str);
        
        String result(temp);
        delete[] temp;
        return result;
    }
};

ostream& operator<<(ostream& os, const String& s) {
    os << s.str;
    return os;
}

istream& operator>>(istream& is, String& s) {
    char str[1000];
    cin>>str;
    s = String(str);
    return is;
}

int main(void)
{
    String str1;
    String str2 = "I like";
    String str3 = str2;
    return 0;
}
