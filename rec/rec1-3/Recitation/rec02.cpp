//
//  rec02.cpp
//  Recitation
//
//  Created by Danny Tan on 2/4/16.
//  Copyright © 2016 Danny Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//creates a structure for hydrocarbons
struct Hydrocarbon{
    vector<string> vectorOfName;
    int carbonNum;
    int hydroNum;
};


int temp(){
    //reads the file
    ifstream ifs ("hydrocarbons.txt");
    //if can't read file, prints error
    if (!ifs){
        cout << "Could not open file. \n";
        exit(1);
    }
    //defines variables
    string name;
    char dummy;
    int carbNum;
    int hydrNum;
    int bigCarbNum = 0;
    //defines vectors
    vector <Hydrocarbon> vectorOfHydrocarbons;
    
    
    //reads the file storing the hydrocarbon's name, carbon number, and hydrogen number
    while(ifs >> name >> dummy >> carbNum >> dummy >> hydrNum){
        //defines variables
        bool addHydrocarbon = true;
        Hydrocarbon aHydrocarbon;
        aHydrocarbon.carbonNum = carbNum;
        aHydrocarbon.hydroNum = hydrNum;
        //stores the biggest carbon number in the file for sorting later
        if (carbNum  > bigCarbNum){
            bigCarbNum = carbNum;
        }
        //stores to the hydrocarbon name to the vector of names
        aHydrocarbon.vectorOfName.push_back(name);
        //if hydrocarbon already existed, adds the name to the vector of names and don't add hydrocarbon to vector of hydrocarbons
        for (size_t i = 0; i < vectorOfHydrocarbons.size(); i++){
            if (carbNum == vectorOfHydrocarbons[i].carbonNum && hydrNum == vectorOfHydrocarbons[i].hydroNum){
                vectorOfHydrocarbons[i].vectorOfName.push_back(name);
                addHydrocarbon = false;
                }
        }
        //if it doesnt exist, adds the hydrocarbon to the list of hydrocarbons
        if (addHydrocarbon == true){
            vectorOfHydrocarbons.push_back(aHydrocarbon);
            }
    }
    int counter = 0;
    //sorts out the hydrocarbon from lowest to highest number of carbons
    while (counter <= bigCarbNum){
        //goes through the vector of hydrocarbons
        for (size_t i = 0; i < vectorOfHydrocarbons.size(); i++){
            //prints out the smallest number of carbons to highest number of carbons
            if (vectorOfHydrocarbons[i].carbonNum == counter){
                cout << "\nC" << vectorOfHydrocarbons[i].carbonNum << "H" << vectorOfHydrocarbons[i].hydroNum << endl;
                //print that vector of names with that carbon number
                for (size_t j = 0; j < vectorOfHydrocarbons[i].vectorOfName.size(); j++){
                    cout << vectorOfHydrocarbons[i].vectorOfName[j] << endl;
                }
            }
        }
        counter ++;
    }
    ifs.close();
    return 0;
}

