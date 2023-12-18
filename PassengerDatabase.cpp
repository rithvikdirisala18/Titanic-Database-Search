//
//  PassengerDatabase.cpp
//  Titanic
//
//  Created by Rithvik Dirisala on 11/19/23.
//

#include <stdio.h>
#include "PassengerDatabase.h"
#include "CSVFile.h"
using namespace std;

namespace cs32{

int PassengerDatabase::load(std::string filePath){
    CSVFile file( this );
    int recordCount = file.readFile( filePath );
    if(recordCount>0){
        isLoaded = true;
    }
    else{
        isLoaded = false;
    }
    //if the recordCount is still 0, that means no passengers were created so the file is not loaded.
    return( recordCount );
}

void PassengerDatabase::clearAllPassengers(){
    for(Passenger* ptr: passengers){
        delete ptr;
    }
    passengers.clear();
}

bool PassengerDatabase::loaded(){
    return isLoaded;
}

Passenger* PassengerDatabase::getPassenger_byName(std::string name){
    //We check if the passenger on the list matches the given name and then push them onto the list
    for(std::vector<Passenger*>::iterator iter = passengers.begin(); iter!=passengers.end();iter++){
        if((*iter)->getName()==name){
            return *iter;
        }
    }
    return nullptr;
}

const std::vector <Passenger*> PassengerDatabase::getPassengers(){
    return passengers;
}

std::vector <Passenger*> PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare){
    std::vector <Passenger*> list;
    //We check if the passenger on the list matches all the listed requirmeents and class and then push them onto our new list.
    for(std::vector<Passenger*>::iterator iter = passengers.begin(); iter!=passengers.end();iter++){
        if((*iter)->getClass()==paidClass){
            if((*iter)->getSurvived()==survived){
                if((*iter)->getFare()>minimumFare){
                    list.push_back(*iter);
                }
            }
        }
    }
    return list;
}

std::vector <Passenger*> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare){
    std::vector <Passenger*> list;
    //We check if the passenger on the list matches all the listed requirmeents and embarcation location and then push them onto our new list.
    for(std::vector<Passenger*>::iterator iter = passengers.begin(); iter!=passengers.end();iter++){
        if((*iter)->getEmbarcation()==embarked){
            if((*iter)->getSurvived()==survived){
                if((*iter)->getFare()>minimumFare){
                    list.push_back(*iter);
                }
            }
        }
    }
    return list;
}

void PassengerDatabase::csvData( std::map< std::string, std::string > row ){
    Passenger* p = new Passenger();
    for( std::map< std::string, std::string >::iterator iter = row.begin(); iter != row.end(); iter++)
    {
        std::string category = iter->first;
        //The maps key is our category variable
        //Based on what the category is, we will be assiging the values to the passenger.
        if(category == "pclass"){
            p->setClass(iter->second);
        }
        if(category == "survived"){
            p->setSurvived(iter->second);
        }
        if(category == "name"){
            p->setName(iter->second);
        }
        if(category == "fare"){
            p->setFare(iter->second);
        }
        if(category == "embarked"){
            p->setEmbarcation(iter->second);
        }
    }
    passengers.push_back(p);
}




}
