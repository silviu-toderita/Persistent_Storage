/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    A persistent storage library for ESP8266. Allows storage of key:value pairs of
    Strings. 

    To use, initialize an object with the path you'd like to use. Use set() to
    store or change a key:value pair, and get() to retrieve a value based on the
    key. Use remove() to delete a key:value pair. 

    Created by Silviu Toderita in 2020.
    silviu.toderita@gmail.com
    silviutoderita.com
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "Arduino.h"
#include "FS.h" //SPI Flash File System (SPIFFS) Library
#include "ArduinoJson.h" //Arduino JavaScript Object Notation Library

class Persistent_Storage{
    
    public:

        Persistent_Storage(String name);
    
        bool
            set(String key, String value),
            remove(String key);

        String 
            get(String key);

    private:

        String path; //The path for this object

};