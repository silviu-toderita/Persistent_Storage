/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    This example shows how to use the Persistent_Storage library to load and save
    a simple config file. 

    Created by Silviu Toderita in 2020.
    silviu.toderita@gmail.com
    silviutoderita.com
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//Include the Persistent Storage Library
#include "Persistent_Storage.h"

//Create a Persistent Storage object with the name "config"
Persistent_Storage config("config");

uint8_t LED_pin; //Pin that LED ground is connected to
uint8_t button_pin; //Pin that button ground is connected to
uint16_t flash_time; //Time in ms between LED turning on and off


/*  load_config: Load the settings from the config file
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void load_config(){
    //Load the LED_pin variable and convert it to an integer. If it is missing, the default is 5. 
    LED_pin = config.get("LED_pin").toInt() | 5;
    //Load the button_pin variable and convert it to an integer. If it is missing, the default is 4. 
    button_pin = config.get("button_pin").toInt() | 4;
    //Load the flash_time variable and convert it to an integer. If it is missing, the default is 500. 
    flash_time = config.get("flash_time").toInt() | 500;
}

/*  save_config: Save the settings to the config file. 
    RETURNS True if successful, false if not. 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool save_config(){
    //Set the status to true
    bool status = true;
    //Attempt to save all the settings. If any fail, set the status to false
    if(!config.set("LED_pin", String(LED_pin))){
        status = false;
    }
    if(!config.set("button_pin", String(button_pin))){
        status = false;
    }
    if(!config.set("flash_time", String(flash_time))){
        status = false;
    }

    return status;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ####  SETUP  ####
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup() {
    //Load the configuration
    load_config();

    //Set the pins
    pinMode(LED_pin, OUTPUT);
    pinMode(button_pin, INPUT_PULLUP);
    //Turn off the LED
    digitalWrite(LED_pin, HIGH);

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ####  LOOP  ####
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() {

    //If the LED pin is HIGH and flash_time has elapsed, bring it LOW
    if(digitalRead(LED_pin) && millis() % (flash_time * 2) < flash_time){
        digitalWrite(LED_pin, LOW);
    //If the LED pin is LOW and flash_time has elapsed, bring it HIGH
    }else if(!digitalRead(LED_pin) && millis() % (flash_time * 2) >= flash_time){
        digitalWrite(LED_pin, HIGH);
    }

    //If the button is pressed...
    if(!digitalRead(button_pin)){
        ///Try and save the config. If successful, restart the ESP
        if(save_config()){
            ESP.restart();
        }
        
    }

}