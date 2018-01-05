#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#include "IRremoteExt.h"

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;



void setup(){
    Serial.begin(9600);
    beginIRremote(2);

    Serial.println("Press a Remote Key ..." );

}

void loop(){
    unsigned long value = getPressedIRremote();
    if( value != 0xffffffff){
      Serial.print("Press Key = " );
      Serial.println(value);
    }
    
    handelIRremote();
    
}

