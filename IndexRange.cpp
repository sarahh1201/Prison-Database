#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void processFile(const string& filename){
    if(!file.is_open()){
        throw EntryException("Unable to open file");
    }

    vector<string> lines;
    string line;
    while(getline(file, line)){
     try{
            lines.push_back(line);
     }
     catch(const EntryException& e){
         cout<<e.what()<<endl;
     }
    }
}

int main() {
    processFile("example.txt");
    return 0;
}
