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


VENDING_SERVICE_STATE InsertCoinsHandler(void){
    // return the state of insert coins
    return INSERT_COINS_STATE;
}

VENDING_SERVICE_STATE SelectOptionsHandler(void){
    // return the state of select options
    return SELECT_OPTIONS_STATE;
}

VENDING_SERVICE_STATE EnterPinsHandler(void){
    // return the state of enter pins
    return ENTER_PINS_STATE;
}

VENDING_SERVICE_STATE TakeDrinksHandler(void){
    // return the state of take drinks
    return TAKE_DRINKS_STATE;
}

VENDING_SERVICE_STATE IdleHandler(void){
    // return the state of Idle
    return IDLE_STATE;
}

VENDING_SERVICE_EVENT ReadEventHandler(VENDING_SERVICE_STATE state){
    // return the state of now
    VENDING_SERVICE_EVENT event;
    switch(state){
        case IDLE_STATE:
            event = INSERT_COINS;
            printf("Current State is IDLE\n");
            break;
        case INSERT_COINS_STATE:
            event = SELECT_OPTIONS;
            printf("Current State is INSERT COINS\n");
            break;
        case SELECT_OPTIONS_STATE:    
            event = ENTER_PINS;
            printf("Current State is SELECT OPTIONS\n");
            break;
        case ENTER_PINS_STATE:
            event = TAKE_DRINKS;
            printf("Current State is ENTER PINS\n");
            break;    
        case TAKE_DRINKS_STATE:
            event = FINISH_SHOPPIING;
            printf("Current State is TAKE DRINKS\n");
            break;
    }
    return event; 
}


int main(void){
    VENDING_SERVICE_STATE vs_state = IDLE_STATE;
    VENDING_SERVICE_EVENT vs_event;
    
    while(1){
        printf("Now Read Vending State...\n");
        vs_event = ReadEventHandler(vs_state);
        switch(vs_event){
            case INSERT_COINS:
                vs_state = InsertCoinsHandler();
                break;
            case ENTER_PINS:
                vs_state = EnterPinsHandler();
                break;
            case SELECT_OPTIONS:
                vs_state = SelectOptionsHandler();
                break;
            case TAKE_DRINKS:    
                vs_state = TakeDrinksHandler();
                break;
            case FINISH_SHOPPIING:
                vs_state = IdleHandler();
                break;
        }
    }
    
    return 0;
}
