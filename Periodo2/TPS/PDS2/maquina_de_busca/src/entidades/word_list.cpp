#include <bits/stdc++.h>
#include <filesystem>
#include <dirent.h>
#include "../../include/word_list.h"

using namespace std;


bool arch(set<string>& entrance_files){
DIR *dir; struct dirent *diread;
    

    if ((dir = opendir("./public/documentos")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            entrance_files.insert(diread->d_name);
        }
        closedir (dir);
    } else {
        perror ("opendir");
        return EXIT_FAILURE;
    }

    //o caminho feito (.|..) fica salvo no set,logo devemos apaga-lo
    auto it = entrance_files.begin();
    entrance_files.erase(it);
    it = entrance_files.begin();
    entrance_files.erase(it);

    return EXIT_FAILURE;
}

map<char,char> specialWord(){
     map<char,char> specialChar;
     specialChar['à']='a';
     specialChar['á']='a';
     specialChar['ã']='a';
     specialChar['é']='e';
     specialChar['ê']='e';
     specialChar['í']='i';
     specialChar['ó']='o';
     specialChar['ú']='u';
     specialChar['ç']='c';
     specialChar['À']='a';
     specialChar['Á']='a';
     specialChar['Ã']='a';
     specialChar['É']='e';
     specialChar['Ê']='e';
     specialChar['Í']='i';
     specialChar['Ó']='o';
     specialChar['Ç']='c';
     specialChar['Ú']='u';
     return specialChar;
}

void normalizeWords(string *entrance)
{
    map<char,char> specialChar=specialWord();
    auto begin = entrance->begin();
    auto end = entrance->end();
    for(auto it = begin; it != end;)
    {

        if(specialChar.find(*it)!=specialChar.end()){
            *it=specialChar[*it];
        }

        if((*it > 122 || *it < 97) && (*it > 57 || *it < 48))
        {
            if(*it >= 65 && *it <= 90)
            {
                *it += 32;
                it++;
            }
            else
                {
                auto aux = entrance->erase(it);
                it = aux--;
                end = entrance->end();
                }
            }

        else 
        {
            it++;
        }

    }
}

WordList::WordList(set<string> files): files(files)
{
    read_files(files);
    organize_words_files(); 
}

void WordList::read_files(set<string> files){
     for(auto it=files.begin();it!=files.end();it++){
        set<string> filesName;
        string direct="./public/documentos/";
        string completeName= direct + *it ;

        ifstream fin(completeName);
        string word;

            while(fin>>word){
                normalizeWords(&word);
                if(words_.find(word) == words_.end()) words_[word];
            }
        }
        if(words_.find("") != words_.end()) words_.erase(words_.find(""));

}

void WordList::organize_words_files()
{
    for(auto it=files.begin();it!=files.end();it++)
    {
        set<string> filesName;
        string direct="./public/documentos/";
        string completeName= direct + *it ;

        ifstream fin(completeName);
        string word;
        set<string> words_in_file;
        
        while(fin>>word)
        {
            normalizeWords(&word);
            words_in_file.insert(word);
        }

        for(auto it_words_in_file = words_in_file.begin();it_words_in_file != words_in_file.end();it_words_in_file++)
        {
            for(auto it_words_ = words_.begin();it_words_ != words_.end();it_words_++)
            {

                if(*it_words_in_file == it_words_->first)
                {
                    words_[it_words_->first].insert(*it);
                }
            }
        }
        words_in_file.clear();
    }
}


vector<string> WordList::find_files(set<string> entrance)
{
    map<string,int> files_word_counter;
    invalidWord exception; 

    for(auto it=entrance.begin();it!=entrance.end();it++)
    {
        auto aux = words_.find(*it);
        
        if(aux == words_.end()) exception.word.push_back(*it);

        else
        {
            for(auto help=words_[*it].begin();help!=words_[*it].end();help++)
            {
                if(files_word_counter.find(*help) == files_word_counter.end())
                {
                    files_word_counter[*help] = 1;
                }
                else files_word_counter[*help]++;
            }
        }
    }
    if(!exception.word.empty()) throw exception;

    vector<string> files_with_words;

    for(auto it_fwc=files_word_counter.begin();it_fwc!=files_word_counter.end();it_fwc++)
    {
        if(it_fwc->second == entrance.size())
        {
            files_with_words.push_back(it_fwc->first);
        }
    }
    sort(files_with_words.begin(),files_with_words.end());

    return files_with_words;
        
}