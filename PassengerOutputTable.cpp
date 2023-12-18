//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by Rithvik Dirisala on 11/22/23.
//

#include <stdio.h>
#include "PassengerOutputTable.h"
#include <iostream>

namespace cs32{

void PassengerOutputTable::setOutputField(Field f){
    if(rowCount()==0){
        mField = f;
    }
    else{
        mRows.clear();
        mField = f;
    }
}

void PassengerOutputTable::setDescription(std::string description){
    mDescription = description;
}

Field PassengerOutputTable::getOutputField(){
    return mField;
}

std::string PassengerOutputTable::getDescription(){
    return mDescription;
}

void PassengerOutputTable::display(){
    if(mField == Field::BYCLASS){
        //Here we are moving the passengers inot rows based on their class status.
        OutputTableRow first;
        OutputTableRow second;
        OutputTableRow third;
        OutputTableRow notknown;
        first.setDescription("First Class");
        second.setDescription("Second Class");
        third.setDescription("Third Class");
        notknown.setDescription("Not Known");
        for(int i = 0; i< mPassengerList.size();i++){
            if(mPassengerList[i]->getClass()==Class::FIRST){
                if(mPassengerList[i]->getSurvived()==true){
                    first.setSurvived(first.getSurvived()+1);
                }
                first.setTotal(first.getTotal()+1);
            }
            if(mPassengerList[i]->getClass()==Class::SECOND){
                if(mPassengerList[i]->getSurvived()==true){
                    second.setSurvived(second.getSurvived()+1);
                }
                second.setTotal(second.getTotal()+1);
            }
            if(mPassengerList[i]->getClass()==Class::THIRD){
                if(mPassengerList[i]->getSurvived()==true){
                    third.setSurvived(third.getSurvived()+1);
                }
                third.setTotal(third.getTotal()+1);
            }
            if(mPassengerList[i]->getClass()==Class::NOTKNOWN){
                if(mPassengerList[i]->getSurvived()==true){
                    notknown.setSurvived(notknown.getSurvived()+1);
                }
                notknown.setTotal(notknown.getTotal()+1);
            }
        }
        mRows.push_back(first);
        mRows.push_back(second);
        mRows.push_back(third);
        mRows.push_back(notknown);
    }
    if(mField == Field::BYEMBARCATION){
        //In this if statement we are moving each passenger into the respective rows based on the embarcation location
        OutputTableRow Q;
        OutputTableRow C;
        OutputTableRow S;
        OutputTableRow notknown;
        Q.setDescription("Queenstown");
        C.setDescription("Cherbourg");
        S.setDescription("South Hampton");
        notknown.setDescription("Not Known");
        for(int i = 0; i< mPassengerList.size();i++){
            if(mPassengerList[i]->getEmbarcation()==Embarcation::QUEENSTOWN){
                if(mPassengerList[i]->getSurvived()==true){
                    Q.setSurvived(Q.getSurvived()+1);
                }
                Q.setTotal(Q.getTotal()+1);
            }
            if(mPassengerList[i]->getEmbarcation()==Embarcation::CHERBOURG){
                if(mPassengerList[i]->getSurvived()==true){
                    C.setSurvived(C.getSurvived()+1);
                }
                C.setTotal(C.getTotal()+1);
            }
            if(mPassengerList[i]->getEmbarcation()==Embarcation::SOUTHHAMPTON){
                if(mPassengerList[i]->getSurvived()==true){
                    S.setSurvived(S.getSurvived()+1);
                }
                S.setTotal(S.getTotal()+1);
            }
            if(mPassengerList[i]->getEmbarcation()==Embarcation::NOTKNOWN){
                if(mPassengerList[i]->getSurvived()==true){
                    notknown.setSurvived(notknown.getSurvived()+1);
                }
                notknown.setTotal(notknown.getTotal()+1);
            }
        }
        mRows.push_back(Q);
        mRows.push_back(C);
        mRows.push_back(S);
        mRows.push_back(notknown);
    }
    if(mField == Field::BYFARE){
        //In this if statement, we are setting the description of each row based on the price range and then we are pushing the passengers who fit the description into each row
        OutputTableRow first;
        OutputTableRow second;
        OutputTableRow third;
        OutputTableRow fourth;
        OutputTableRow notknown;
        notknown.setDescription("Not Known");
        first.setDescription("$ 1-$10");
        second.setDescription("$10-$25");
        third.setDescription("$25-$50");
        fourth.setDescription("   >$50");
        for(int i = 0; i< mPassengerList.size();i++){
            if(mPassengerList[i]->getFare()==0){
                if(mPassengerList[i]->getSurvived()==true){
                    notknown.setSurvived(notknown.getSurvived()+1);
                }
                notknown.setTotal(notknown.getTotal()+1);
            }
            if(0<mPassengerList[i]->getFare()&&mPassengerList[i]->getFare()<=10){
                if(mPassengerList[i]->getSurvived()==true){
                    first.setSurvived(first.getSurvived()+1);
                }
                first.setTotal(first.getTotal()+1);
            }
            if(10<mPassengerList[i]->getFare()&&mPassengerList[i]->getFare()<=25){
                if(mPassengerList[i]->getSurvived()==true){
                    second.setSurvived(second.getSurvived()+1);
                }
                second.setTotal(second.getTotal()+1);
            }
            if(25<mPassengerList[i]->getFare()&&mPassengerList[i]->getFare()<=50){
                if(mPassengerList[i]->getSurvived()==true){
                    third.setSurvived(third.getSurvived()+1);
                }
                third.setTotal(third.getTotal()+1);
            }
            if(50<mPassengerList[i]->getFare()){
                if(mPassengerList[i]->getSurvived()==true){
                    fourth.setSurvived(fourth.getSurvived()+1);
                }
                fourth.setTotal(fourth.getTotal()+1);
            }
        }
        mRows.push_back(first);
        mRows.push_back(second);
        mRows.push_back(third);
        mRows.push_back(fourth);
        mRows.push_back(notknown);
    }
    if(mField==Field::NOVALUE){
        //In a NOVALUE table, nothing is printed
        return;
    }
    cout << mDescription << endl;
    for(int i = 0; i< mRows.size(); i++){
        mRows[i].display();
    }
    //This prints out the description along with each row.
}

size_t PassengerOutputTable::rowCount(){
    return mRows.size();
}

OutputTableRow PassengerOutputTable::getRow(int index){
    if(index<rowCount()){
        return mRows[index];
    }
    else{
        return OutputTableRow();
    }
    //If the index is too large, we return a new empty output table row
}

}
