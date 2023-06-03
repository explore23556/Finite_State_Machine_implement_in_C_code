#include <stdio.h>
#include <stdlib.h>

typedef enum{    
    INSERT_COINS,
    SELECT_OPTIONS,
    ENTER_PINS,
    TAKE_DRINKS, 
    FINISH_SHOPPIING
}VENDING_SERVICE_EVENT;

typedef enum{
    IDLE_STATE,    
    INSERT_COINS_STATE,
    SELECT_OPTIONS_STATE,
    ENTER_PINS_STATE,
    TAKE_DRINKS_STATE
}VENDING_SERVICE_STATE;

typedef VENDING_SERVICE_STATE (*fpTransitionHandler)(void);

typedef struct state_machine{
    VENDING_SERVICE_STATE vs_state;
    VENDING_SERVICE_EVENT vs_event;
    fpTransitionHandler trans_handler;
}sState_Machine;

VENDING_SERVICE_STATE IdleHandler(void){
    
    return IDLE_STATE;
}

VENDING_SERVICE_STATE InsertCoinsHandler(void){
    
    return INSERT_COINS_STATE;
}

VENDING_SERVICE_STATE SelectOptionsHandler(void){
    
    return SELECT_OPTIONS_STATE;
}

VENDING_SERVICE_STATE EnterPinsHandler(void){
    
    return ENTER_PINS_STATE;
}

VENDING_SERVICE_STATE TakeDrinksHandler(void){
    
    return TAKE_DRINKS_STATE;
}

sState_Machine asState_Machine[] = {
    {IDLE_STATE, INSERT_COINS, InsertCoinsHandler},
    {INSERT_COINS_STATE, SELECT_OPTIONS, SelectOptionsHandler},
    {SELECT_OPTIONS_STATE, ENTER_PINS, EnterPinsHandler},
    {ENTER_PINS_STATE, TAKE_DRINKS, TakeDrinksHandler},
    {TAKE_DRINKS_STATE, FINISH_SHOPPIING, IdleHandler}
};

void ReadEventHandler(VENDING_SERVICE_EVENT event){
    // return the state of now
    switch(event){
        case INSERT_COINS:
            printf("Current State is IDLE\n");
            break;
        case SELECT_OPTIONS:
            printf("Current State is INSERT COINS\n");
            break;
        case ENTER_PINS:    
            printf("Current State is SELECT OPTIONS\n");
            break;
        case TAKE_DRINKS:
            printf("Current State is ENTER PINS\n");
            break;    
        case FINISH_SHOPPIING:
            printf("Current State is TAKE DRINKS\n");
            break;
    }
    return; 
}

int main(void)
{
    // declare initial state
    VENDING_SERVICE_STATE vs_current_state = asState_Machine[0].vs_state;
    while(1){
        printf("Now Read Vending State...\n");
        ReadEventHandler(asState_Machine[vs_current_state].vs_event);   
        vs_current_state = (*asState_Machine[vs_current_state].trans_handler)();
    }
    
    return 0;
}
