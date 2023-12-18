//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by Rithvik Dirisala on 11/22/23.
//

#include <stdio.h>
#include "OutputTableRow.h"
#include <iostream>

namespace cs32{

void OutputTableRow::setDescription(std::string description){
    mDescription = description;
}

std::string OutputTableRow::getDescription(){
    return mDescription;
}

void OutputTableRow::setTotal(int total){
    mTotal = total;
}

int OutputTableRow::getTotal(){
    return mTotal;
}

void OutputTableRow::setSurvived(int survived){
    mSurvived = survived;
}

int OutputTableRow::getSurvived(){
    return mSurvived;
}

double OutputTableRow::getPercentage(){
    double total = mTotal;
    if(total==0){
        return 0;
    }
    return mSurvived/total;
}

void OutputTableRow::display(){
    cout << mDescription << "-   " <<mSurvived << "/" << mTotal << "   "<< getPercentage()*100.00 << endl;
    //This prints out the category of each row, follow by the survived over total and the percentage
}

}
