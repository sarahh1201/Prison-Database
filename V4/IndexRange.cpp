/*#include<iostream>
#include<fstream>
#include<vector>
#include <cstring>

using namespace std;

void processFile(const string& filename){
    if(!filename.is_open()){
        throw EntryException("Unable to open file");
    }

    vector<string> lines;
    string line;
    while(getline(filename, line)){
     try{
            lines.push_back(line);
     }
     catch(const EntryException& ex){
         cout<<ex.what()<<endl;
     }
    }
}

int main() {
    processFile("example.txt");
    return 0;
}*/
