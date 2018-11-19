//
//  rec01.cpp
//  Recitation
//
//  Created by Danny Tan on 1/28/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int temp(){
    ifstream ifs("jabberwocky.txt");
    if (!ifs){
        cout << "Could not open file. \n";
        exit(0);
    }
    string line;
    int lineCount;
    
    while (getline(ifs, line)){
        lineCount ++;
    }
    cout << "The number of lines is " << lineCount << "." << endl;
    ifs.clear();
    ifs.seekg(0);
    string word;
    int wordCount;
    while (ifs >> word){
        wordCount++;
    }
    cout << "The number of words is " << wordCount << "." << endl;
    ifs.clear();
    ifs.seekg(0);
    char character;
    int charCount;
    ifs >> noskipws;
    while (ifs >> character){
        charCount++;
    }
    cout << "The number of words is " << charCount << "." << endl;
    ifs.close();
    
    return 0;
}