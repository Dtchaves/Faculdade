#include "google_password.h"

#include <iostream>

using namespace std;

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
                                
    if(passwords_.find(url) == passwords_.end()) 
    {
        if(validPassword(password)) passwords_[url]= Usuario{login,password};

    }                           
}

void GooglePassword::remove(const std::string& url) {
    passwords_.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
    if(passwords_.find(url) != passwords_.end()) {
        if(old_password == passwords_[url].password){
            if(validPassword(new_password)) passwords_[url]= Usuario{login,new_password};
        }
    }
}

void GooglePassword::printPasswords() {
    cout<<passwords_.size()<<endl;
    for(auto it = passwords_.begin();it!= passwords_.end();it++)
    {
        cout<<it->first<<": "<< it->second.login<<" and "<<it->second.password<<endl;
    }
}

bool GooglePassword::validPassword(const std::string& password) const {

    if(password.find('1') != string::npos) {
        int aux = password.find('1');
        for (char i : {'1','2','3','4','5','6'}){
            if(password[aux] != i) break;
            if(i == '6') return false;
            aux++;
        }
    }
    if(password.size()>50 || password.size()<6) return false;
    for(int j = 0; j < password.size(); j++) if(password[j] == ' ') return false;
    return true;
}