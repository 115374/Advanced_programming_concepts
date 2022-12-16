# Statemachines
## statemachine
Een state machine is een handige tool in een computer systeem. Een state machine is een apparaat dat de status van iets in de gaten houd. Die status kan veranderen als gevolg van wijzigingen in invoerwaarden of kan in de loop van de tijd veranderen in een vooraf bepaalde volgorde. Een veel voorkomend voorbeeld is een verkeerslicht op een kruispunt of wegwerkzaamheden. De status beschrijft welke van de lamp tegelijkertijd mag branden. Voor eenvoudige getimede lichten verandert de status regelmatig na een vast tijdsinterval.
Om een finite state machine te maken in C++, zou je de volgende stappen kunnen volgen:
1.	Definiëer de verschillende staten die je finite state machine kan hebben. Dit zou kunnen zijn door middel van een enum in C++, waarbij je een naam geeft aan elke staat die je finite state machine kan hebben.
2.	Definiëer de input die je finite state machine kan ontvangen. Dit kan worden gedaan door middel van een class of een struct in C++.
3.	Maak een functie die de huidige staat van je finite state machine bepaalt. Deze functie zou bijvoorbeeld getCurrentState() kunnen heten en zou een waarde van het type dat je in stap 1 hebt gedefinieerd teruggeven.
4.	Maak een functie die de volgende staat van je finite state machine bepaalt op basis van de huidige staat en de input die het systeem ontvangt. Deze functie zou bijvoorbeeld getNextState() kunnen heten en zou twee argumenten accepteren: de huidige staat en de input. Op basis hiervan zou de functie de volgende staat van de finite state machine bepalen en deze teruggeven.
5.	Maak een functie die de finite state machine laat werken. Deze functie zou bijvoorbeeld run() kunnen heten en zou twee argumenten accepteren: de huidige staat en de input. Deze functie zou de huidige staat van de finite state machine ophalen met de functie uit stap 3, gebruik maken van de functie uit stap 4 om de volgende staat te bepalen en deze vervolgens instellen als de huidige staat. Daarna zou deze functie de nieuwe staat van de finite state machine teruggeven.

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
### Mealy Machine 
Mealy-machine wordt gedefinieerd als een machine in de berekeningstheorie waarvan de uitvoerwaarden worden bepaald door zowel de huidige status als de huidige invoer. Bij deze machine is maximaal één overgang mogelijk.
Het heeft 6 verschillende objecten:
1. Q is een eindige verzameling toestanden
2. q0 is de begintoestand
3. ∑ is het invoeralfabet
4. ▲ is het uitgangsalfabet
5. δ is de overgangsfunctie die Q×∑ → Q afbeeldt
6. ‘λ’ is de uitvoerfunctie die Q×∑→ ▲ afbeeldt

### Moore machine

