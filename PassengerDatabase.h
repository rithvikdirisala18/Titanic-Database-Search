//
//  PassengerDatabase.h
//  Titanic
//
//  Created by Rithvik Dirisala on 11/19/23.
//

#ifndef PassengerDatabase_h
#define PassengerDatabase_h
#include "Passenger.h"
#include "Enums.h"
#include <iostream>
#include "DataCollectorCallback.h"
#include "Settings.h"
using namespace std;

namespace cs32{
class PassengerDatabase : public DataCollectorCallback{
public:
    PassengerDatabase(){}
    
    virtual ~PassengerDatabase(){
        clearAllPassengers();
    }
    
    int load(std::string filePath);
    void clearAllPassengers();
    bool loaded();
    
    Passenger* getPassenger_byName(std::string name);
    const std::vector <Passenger*> getPassengers() ;
    std::vector <Passenger*> getPassengers_byClass(Class paidClass, bool survived, double minimumFare);
    std::vector <Passenger*> getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare);
    
    virtual void csvData( std::map< std::string, std::string > row );
    
    
private:
    std::vector<Passenger*> passengers;
    bool isLoaded;
};


}


#endif /* PassengerDatabase_h */
