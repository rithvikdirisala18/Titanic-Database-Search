//
//  OutputTableRow.h
//  Titanic
//
//  Created by Rithvik Dirisala on 11/22/23.
//

#ifndef OutputTableRow_h
#define OutputTableRow_h
using namespace std;
#include <string>

namespace cs32{
class OutputTableRow{
public:
    OutputTableRow(){
        mDescription="";
        mSurvived = 0;
        mTotal = 0;
    }
    
    void setDescription(std::string description);
    void setSurvived(int survived);
    void setTotal(int total);
    
    std::string getDescription();
    int getSurvived();
    int getTotal();
    double getPercentage();
    
    void display();
    
private:
    std::string mDescription;
    int mSurvived;
    int mTotal;
    std::string padToThreeCharacters(int value);
    
};


}




#endif /* OutputTableRow_h */
