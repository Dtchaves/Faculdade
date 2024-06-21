#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../include/doctest.h"

#include "../../include/word_list.h"

TEST_CASE("bool arch(set<string>& entrance_files)") {
    set<string> entrance_files;
    arch(entrance_files);

    CHECK(entrance_files.size() == 30);

    auto first = entrance_files.begin();
    auto last = --entrance_files.end();

    CHECK(*first == "d1.txt");
    CHECK(*last == "d9.txt");
}

TEST_CASE("specialWord()") {
    map<char,char> specialChar = specialWord();
    CHECK(specialChar['à']=='a');
    CHECK(specialChar['á']=='a');
    CHECK(specialChar['ã']=='a');
    CHECK(specialChar['é']=='e');
    CHECK(specialChar['ê']=='e');
    CHECK(specialChar['í']=='i');
    CHECK(specialChar['ó']=='o');
    CHECK(specialChar['ç']=='c');
    CHECK(specialChar['ú']=='u');
    CHECK(specialChar['À']=='a');
    CHECK(specialChar['Á']=='a');
    CHECK(specialChar['Ã']=='a');
    CHECK(specialChar['É']=='e');
    CHECK(specialChar['Ê']=='e');
    CHECK(specialChar['Í']=='i');
    CHECK(specialChar['Ó']=='o');
    CHECK(specialChar['Ç']=='c');
    CHECK(specialChar['Ú']=='u');
}

TEST_CASE("void normalizeWords(string *entrance)") {
    string aux =  "àáãéêíóçAÇÃBÓ";
    normalizeWords(&aux);
    CHECK(aux == "aaaeeiocacabo");

    string aux2= "@";
    normalizeWords(&aux2);
    CHECK(aux2 == "");

    string aux3= "%$(";
    normalizeWords(&aux3);
    CHECK(aux3 == "");
}

TEST_CASE("vector<string> WordList::find_files(set<string> entrance)") {
    set<string> entrance_files;
    arch(entrance_files);
    WordList Words_files(entrance_files);
    set<string> entrance;
    string di = "DIOGO";
    string la = "LAILA";

    normalizeWords(&di);
    normalizeWords(&la);

    entrance.insert(di);
    entrance.insert(la);

    vector<string> Files_exit = Words_files.find_files(entrance);
    CHECK(Files_exit[0]=="d1.txt");
    CHECK(Files_exit[1]=="d11.txt");
    CHECK(Files_exit[2]=="d2.txt");
    CHECK(Files_exit[3]=="d27.txt");
    CHECK(Files_exit[4]=="d9.txt");

}