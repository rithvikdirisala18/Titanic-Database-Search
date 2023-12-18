//
//  Passenger.cpp
//  Titanic
//
//  Created by Rithvik Dirisala on 11/19/23.
//

#include "Passenger.h"
#include <stdio.h>
#include <iostream>
using namespace std;

namespace cs32{

void Passenger::setName(string name){
    mName = name;
}

std::string Passenger::getName(){
    return mName;
}

void Passenger::setFare(std::string fare){
    if(fare>="0"){
        mFare = std::stof(fare);
    }
    else{
        mFare = 0;
    }
}

double Passenger::getFare(){
    return mFare;
}

void Passenger::setClass(std::string classofFare){
    if(classofFare=="1"){
        mClass = Class::FIRST;
    }
    else if(classofFare=="2"){
        mClass = Class::SECOND;
    }
    else if(classofFare=="3"){
        mClass = Class::THIRD;
    }
    else{
        mClass = Class::NOTKNOWN;
    }
}

Class Passenger::getClass(){
    return mClass;
}

void Passenger::setSurvived(std::string survived){
    if(survived=="0"){
        mSurvived = false;
    }
    else if (survived=="1"){
        mSurvived = true;
    }
    else{
        mSurvived = false;
    }
}

bool Passenger::getSurvived(){
    return mSurvived;
}

void Passenger::setEmbarcation(std::string embarked){
    if(embarked=="C"){
        mEmbarked = Embarcation::CHERBOURG;
    }
    else if(embarked=="Q"){
        mEmbarked = Embarcation::QUEENSTOWN;
    }
    else if(embarked=="S"){
        mEmbarked = Embarcation::SOUTHHAMPTON;
    }
    else{
        mEmbarked = Embarcation::NOTKNOWN;
    }
}

Embarcation Passenger::getEmbarcation(){
    return mEmbarked;
}

}




