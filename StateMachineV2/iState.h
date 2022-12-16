//
// Created by Dave on 10-12-2022.
//

#ifndef STATEMACHINEV2_ISTATE_H
#define STATEMACHINEV2_ISTATE_H
class iState{
public:
    virtual void declareState()=0;

    virtual std::string returnInstance()=0;
};

#endif //STATEMACHINEV2_ISTATE_H
