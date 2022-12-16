#include <iostream>
#include "fridgeStates.h"
#include "statemachine.h"
#include "iState.h"

int main() {
    openState off;
    CoolingState cool;
    ClosedOffState defros;

    statemachine fsm{&off};
    fsm.declareState();
    fsm.setState(&cool/*, CLOSED_COOLING*/);
    fsm.declareState();
    fsm.setState(fsm.getState()/*, CLOSED_COOLING*/);
    fsm.declareState();
    fsm.setState(&defros/*, CLOSED_OFF*/);
    fsm.declareState();


    return 0;
}
