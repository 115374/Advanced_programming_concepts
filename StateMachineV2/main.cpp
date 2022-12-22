#include <iostream>
#include "fridgeStates.h"
#include "statemachine.h"
#include "iState.h"

int main() {
    openState off;
    CoolingState cool;
    ClosedOffState closed;

    statemachine fsm{&off};
    fsm.declareState();
    fsm.setState(&cool);
    fsm.declareState();
    fsm.setState(fsm.getState());
    fsm.declareState();
    fsm.setState(&closed);
    fsm.declareState();



    return 0;
}