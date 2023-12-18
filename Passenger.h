//
//  Passenger.h
//  Titanic
//
//  Created by Rithvik Dirisala on 11/19/23.
//

#ifndef Passenger_h
#define Passenger_h

#include <stdio.h>
#include "Enums.h"
#include <string>
using namespace std;

namespace cs32{

class Passenger
{
    
public:
    Passenger(){
        mClass = Class::NOTKNOWN;
        mEmbarked = Embarcation::NOTKNOWN;
        mName = "";
        mSurvived = false;
        mFare = 0.0;
    }
    
    void setName(std::string name);
    std::string getName();
    
    void setEmbarcation(std::string embarked);
    void setClass(std::string classofFare);
    void setSurvived(std::string survived);
    void setFare(std::string fare);
    
    Embarcation getEmbarcation();
    Class getClass();
    bool getSurvived();
    double getFare();
    
    
private:
    Class mClass;
    Embarcation mEmbarked;
    string mName;
    bool mSurvived;
    double mFare;
};

}



#endif /* Passenger_h */
