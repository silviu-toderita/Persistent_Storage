# Persistent_Storage
 A persistent storage library for the ESP8266 that uses the flash memory. Should also be compatible with any Arduino that has flash memory connected to the SPI bus. 

 This library allows you to store Strings as key:value pairs. 

 To use, initialize a Persistent_Storage object using passing a String as the sole argument for the name. Use the set() function to create or change an entry, get() to retrieve an entry, and remove() to delete an entry. 
