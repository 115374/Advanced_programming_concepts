//
// Created by Dave on 10-12-2022.
//

#ifndef STATEMACHINEV2_FRIDGESTATES_H
#define STATEMACHINEV2_FRIDGESTATES_H

#include <iostream>
#include "iState.h"

class fridgeStates;
//enum States{
//    OPEN_OFF,
//    CLOSED_COOLING,
//    CLOSED_OFF,
//};

class openState : public iState{
public:
    void declareState(){
        std::cout << "Fridge is open, and the cooling system is now off!" << std::endl;
    }

    std::string returnInstance(){
        static std::string s = " open fridge ";
        return s;
    }


};

class CoolingState : public iState{
public:
    void declareState(){
        std::cout << "Fridge is now Closed and cooling!!" << std::endl;
    }
     std::string returnInstance(){
        static std::string s = " Cool fridge ";
        return s;
    }
};
class ClosedOffState : public iState{
public:
    void declareState(){
        std::cout << "Fridge is now Closed!" << std::endl;
    }
     std::string returnInstance(){
        static std::string s = " Close fridge ";
        return s;
    }

};

#endif //STATEMACHINEV2_FRIDGESTATES_H
