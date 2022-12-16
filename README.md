# Piece of Prose: Statemachines
## statemachine
Een state machine is een handige tool in een computer systeem. Een state machine is een apparaat dat de status van iets in de gaten houd. Die status kan veranderen als gevolg van wijzigingen in invoerwaarden of kan in de loop van de tijd veranderen in een vooraf bepaalde volgorde. Een veel voorkomend voorbeeld is een verkeerslicht op een kruispunt of wegwerkzaamheden. De status beschrijft welke van de lamp tegelijkertijd mag branden. Voor eenvoudige getimede lichten verandert de status regelmatig na een vast tijdsinterval.

##### uitleg:
Dit programma is een statemachine programma dat de gebruiker in staat stelt de staten van een koelkast te beheren. Het programma is geschreven in cpp en bestaat uit drie bestanden - statemachine.h, iState.h en fridgeStates.h. Het statemachine.h-bestand bevat de statemachine-klasse die wordt gebruikt om de huidige en vorige staten van de koelkast bij te houden. Het iState.h-bestand is een interface die een basisklasse biedt voor alle staten van de koelkast. Als laatste bevat de fridgeStates.h-file drie klassen - openState, CoolingState en ClosedOffState - die de verschillende staten van de koelkast vertegenwoordigen.

Stap voor Stap Gids:
1. Maak de drie bestanden - statemachine.h, iState.h en fridgeStates.h - aan en voeg de code van het voorbeeld hierboven toe. 
2. In statemachine.h, maak de statemachine-klasse met de constructor en de setState, getState en declareState-functies. 
3. In iState.h, maak de iState-interface met de declareState en returnInstance-functies. 
4. In fridgeStates.h, maak de openState, CoolingState en ClosedOffState-klassen. 
5. In main.cpp, maak de main-functie en instantieer de openState, CoolingState en ClosedOffState-klassen. 
6. Maak het statemachine-object met de openState-klasse als argument. 
7. Gebruik het statemachine-object om de declareState, setState en getState-functies aan te roepen. 
8. Voer het programma uit.

### switch-case
Een switch-case statement is een voorbeeld van een simpele state machine.
```cpp=
function loginMachine(state, event) {
    switch (state) {
        case 'start':
            if (event === 'SUBMIT') {
                return 'loading';
            }
            break;
        case 'loading':
            if (event === 'RESOLVE') {
                return 'success';
            } else if (event === 'REJECT') {
                return 'error';
            }
            break;
        case 'success':
            // Accept no further events
            break;
        case 'error':
            if (event === 'SUBMIT') {
                return 'loading';
            }
            break;
        default:
            // This should never occur
            return undefined;
    }
}

console.log(loginMachine('start', 'SUBMIT'));
// => 'loading'
```
## Moore and mealy machines
#### Mealy state Machine 
Een mealy-machine is een finite state waarvan de outputs value worden bepaald door zowel de huidige state en de huidige input. Dit is in tegenstelling tot een Moore-machine, waarvan de outputs value alleen wordt bepaald door de huidige state. Een mealy-machine is een deterministische finite-state transducer; voor elke state en input is maximaal 1 transition mogelijk.

#### Moore state machine
Een Moore-machine is een finite-state machine waarvan de huidige output values alleen worden bepaald door de huidige state. Dit is in tegenstelling tot een Mealy-machine. Net als andere finite-state machine, beïnvloedt de input in moore-machines normaal gesproken de volgende states. De input kan dus indirect de output veranderen, maar niet de huidige output.

##### Verschil Moore en Mealy machine
Het verschil tussen Moore en Mealy machines is dus dat Moore machines de huidige output alleen wordt bepaald door de huidige state, waar dit bij Mealy wordt bepaald door de huidige state en door de huidige input. Een voordeel van een Moore machine is dat het makkelijk te maken is, maar reageert wel weer slomer op inputs. Bij mealy machine is dit andersom.
Of terwijl er zit aan beide machines voordelen en nadelen. Het is afhankelijk van waarvoor het gebruikt wordt, welke machine je nodig hebt.

Verschil van de machines, in een statediagram:
![](https://i.imgur.com/B0rHWzO.png)


## Uitwerking state machine in C++
Wij hebben een moore state machine gemaakt, maar ons doel was uiteindelijk om een mealey state machine te maken, want we wouden dan als input dingen als de temperatuur gebruiken om te kunnen bepalen of de koelkast zou moeten veranderen van closed naar cooling en van cooling naar closed, daar zijn wij uiteindelijk niet aan toe gekomen maar dat zou dan een verbeterpunt zijn voor wanneer wij ons opnieuw in dit onderwerp zouden verdiepen.

### Statediagram koelkast

![](https://user-images.githubusercontent.com/94605812/208109881-7cd5b70f-45f9-4849-a892-6f0d468231da.jpg)


### statemachine.h
```cpp=
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
```
### iState.h
Interface:
```cpp=
#ifndef STATEMACHINEV2_ISTATE_H
#define STATEMACHINEV2_ISTATE_H
class iState{
public:
    virtual void declareState()=0;

    virtual std::string returnInstance()=0;
};

#endif //STATEMACHINEV2_ISTATE_H
```

### fridgeStates.h
```cpp=
#ifndef STATEMACHINEV2_FRIDGESTATES_H
#define STATEMACHINEV2_FRIDGESTATES_H

#include <iostream>
#include "iState.h"

class fridgeStates;
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
```
#### main.cpp
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
```
    
    bronnen: 
    https://www.codeproject.com/Articles/1087619/State-Machine-Design-in-Cplusplus-2 
https://faramira.com/reusable-finite-state-machine-using-cpp/
    
    https://codereview.stackexchange.com/questions/51067/designing-simple-state-machine-in-c
    
    https://www.aleksandrhovhannisyan.com/blog/implementing-a-finite-state-machine-in-cpp/
