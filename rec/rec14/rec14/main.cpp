//
//  main.cpp
//  rec14
//
//  Created by Danny Tan on 5/5/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>

using namespace std;

void printList(const list<int>& li){
    for (list<int>::const_iterator iter = li.begin(); iter != li.end(); ++iter){
        cout << *iter << " ";
    }
}

void printList2(const list<int>& li){
    for (int x: li){
        cout << x << " ";
    }
}

auto printListOther(const list<int>& li){
    for (auto iter = li.begin(); iter != li.end(); ++(++iter)){
        cout << *iter << " ";
    }
}

list<int>::const_iterator findList(const list<int>& li, int target){
    for (list<int>::const_iterator iter = li.begin(); iter != li.end(); ++iter){
        if (*iter == target){
            return iter;
        }
    }
    return li.end();
}

auto findList2(const list<int>& li, int target){
    for (auto iter = li.begin(); iter != li.end(); ++iter){
        if (*iter == target){
            return iter;
        }
    }
    return li.end();
}

bool isEven(int n){
    return n%2 == 0;
}

list<int>::const_iterator ourFind(const list<int>& li, int target){
    cout << "ourFind function:" << endl;
    for (list<int>::const_iterator iter = li.begin(); iter != li.end(); ++iter){
        if (*iter == target){
            return iter;
        }
    }
    return li.end();
}

template <typename Apple, typename Orange>
Apple ourFind(Apple li, Apple li2, Orange target){
    cout << "In template:" << endl;
    for (Apple iter = li; iter != li2; ++iter){
        if (*iter == target){
            return iter;
        }
    }
    return li2;
}


int main(){
    cout << "task 1" << endl;
    //task 1
    vector<int> vi = {21,1,3,8,5,34,2,1};
    for (int i : vi){
        cout << i << " ";
    }
    
    cout << endl << "task 2" << endl;
    //task 2
    list<int> li(vi.begin(), vi.end());
    for (list<int>::iterator  iter = li.begin(); iter != li.end(); ++iter){
        cout << *iter << " ";
    }
    
    cout << endl << "task 3" << endl;
    //task 3
    sort (vi.begin(), vi.end());
    for (int x: vi){
        cout << x << " ";
    }
    cout << endl;
    for (int x: li){
        cout << x << " ";
    }

    cout << endl << "task 4" << endl;
    
    //task 4
    for (size_t i = 0; i < vi.size(); i+=2){
        cout << vi[i] << " ";
    }

    cout << endl << "task 5" << endl;
    
    //task 5
    li.sort();
    for (list<int>::iterator  iter = li.begin(); iter != li.end(); ++iter){
        cout << *iter << " ";
    }
    
    cout << endl << "task 6" << endl;
    
    //task 6
    for (vector<int>::iterator  iter = vi.begin(); iter != vi.end(); iter += 2){
        cout << *iter << " ";
    }
    
    cout << endl << "task 7" << endl;
    
    //task 7
    for (list<int>::iterator  iter = li.begin(); iter != li.end(); ++(++iter)){
        cout << *iter << " ";
    }
    
    cout << endl << "task 8" << endl;
    
    //task 8
    printList(li);
    
    cout << endl << "task 9" << endl;
    
    //task 9
    printList2(li);
    
    cout << endl << "task 10" << endl;
    
    //task 10
    printListOther(li);
    
    cout << endl << "task 11" << endl;
    
    //task 11
    if (findList(li, 21) != li.end()){
        cout << "21 is found" << endl;
    }
    if (findList(li, 11) == li.end()){
        cout << "11 is not found" << endl;
    }
    
    cout << endl << "task 12" << endl;
    //task 12
    if (findList2(li, 34) != li.end()){
        cout << "34 is found" << endl;
    }
    if (findList2(li, 4) == li.end()){
        cout << "4 is not found" << endl;
    }
    
    cout << endl << "task 13" << endl;
    //task 13
    if (find(li.begin(), li.end(), 21) != li.end()){
        cout << "21 is found" << endl;
    }
    
    cout << endl << "task 14" << endl;
    //task 14
    
    if(find_if(li.begin(), li.end(), isEven) != li.end()){
        cout << *(find_if(li.begin(), li.end(), isEven));
    }
    else{
        cout << "not found";
    }
    
    cout << endl << "task 15" << endl;
    //task 15
    
    if(find_if(li.begin(), li.end(),[](int n){return n%2 == 0;}) != li.end()){
        cout << *(find_if(li.begin(), li.end(),[](int n){return n%2 == 0;}));
    }
    else{
        cout << "not found";
    }
    
    cout << endl << "task 16" << endl;
    //task 16
    int arr[8];
    copy(li.begin(), li.end(), arr);
    
    for (int i =0; i < 8; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    if (find(arr, arr+8, 21) != arr+8){
        cout << "21 is found";
    }
    
    cout << endl << "task 17" << endl;
    //task 17
    
    if (ourFind(li, 5) != li.end()){
       cout << "5 is found";
    }
    
    cout << endl << "task 18" << endl;
    //task 18
    if (ourFind(vi.begin(), vi.end(), 8) != vi.end()){
        cout << "8 is found";
    }
    
    cout << endl << "task 19" << endl;
    //task 19
    
    ifstream ifs("pooh-nopunc.txt");
    
    if (!ifs){
        cout << "File is not found" << endl;
    }
    
    vector<string> words;
    string word;

    
    while (ifs >> word){
        if (find(words.begin(), words.end(), word) == words.end()){
            words.push_back(word);
        }
    }
    cout << words.size() << ":";
    for (string word: words){
        cout << word << " ";
    }
    cout << endl;
    
    ifs.close();
    
    cout << endl << "task 20" << endl;
    //task 20
    set<string> setWords;
    
    ifs.open("pooh-nopunc.txt");
    while (ifs >> word){
        setWords.insert(word);
    }
    
    cout << setWords.size() << ":";
    for (string word: setWords){
        cout << word << " ";
    }
    
    ifs.close();
    cout << endl << "task 21" << endl;
    //task 21
    
    map<string, vector<int>> wordMap;
    int position = 0;
    
    ifs.open("pooh-nopunc.txt");
    while (ifs >> word){
        wordMap[word].push_back(position);
        ++position;
    }
    
    cout << "Map size: " << wordMap.size() << endl;
    
    for (auto word: wordMap){
        cout << word.first << ":";
        for (size_t i = 0; i < word.second.size(); ++i){
            cout << word.second[i] << " ";
        }
         cout << endl;
    }
    cout << endl;
    
}
