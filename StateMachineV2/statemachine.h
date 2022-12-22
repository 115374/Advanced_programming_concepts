//
// Created by Dave on 10-12-2022.
//

#ifndef STATEMACHINEV2_STATEMACHINE_H
#define STATEMACHINEV2_STATEMACHINE_H
#include "iState.h"
#include "fridgeStates.h"

class statemachine{
public:

    statemachine() : currentState(nullptr){

    }
    statemachine(iState* state) : currentState(state){
    }
    void setState(iState* state/*, States states*/){
        prevState = currentState;
        currentState = state;
        //m_state = states;
    }
    iState* getState(){
        return currentState;
    }
    void declareState(){
        if(currentState != prevState){
            currentState->declareState();
        }else{
            std::cout << "You can't perform action: " << prevState->returnInstance()  << std::endl;
        }
    }
private:
    iState* currentState;
    iState* prevState;
};
#endif //STATEMACHINEV2_STATEMACHINE_H
