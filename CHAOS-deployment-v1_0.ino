/*
 * Author:  Chris Bowers
 * Purpose: Code for CHAOS deployment sequence
 * Version: 1.0
 *
 */

// TODO: 
// digital high may resolve runt voltage (the drop when trying to analyze if change in PWM state is needed)
// slowing the PWM signal may allow more efficient MOSFET Ids
// MOSFET can't transition fast enough after seeing the runt voltage
// solutions:
//  make PWM slower for the RC paracitic capacitence
//  + digital high
//  + slow clock cycle
//  + change PWM counter length

#include "CHAOS.h"
int dist = 0; // distance seen by HC-SR04 in inches
#define TEENSY_LED_PIN 13
#define GREEN_LED_OUT  33
#define HCSR04_TRIGGER 21
#define TEENSY_LED_PIN 13

// configure serial output
void setup() {
    Serial.begin(115200);
    pinMode(TEENSY_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_OUT, OUTPUT);
    pinMode(BURN_WIRE1, OUTPUT);
    pinMode(HCSR04_1, OUTPUT);
    pinMode(HCSR04_2, OUTPUT);
    pinMode(HCSR04_3, OUTPUT);
    pinMode(HCSR04_4, OUTPUT);
    pinMode(HCSR04_READ, INPUT);
    pinMode(BURN_WIRE1ab, OUTPUT);
    digitalWrite(TEENSY_LED_PIN, HIGH);
    deployCHAOS();
    //burnWire(BURN_WIRE1);
    burnWire(BURN_WIRE1ab);
    delay(5*1000);
    //largePanelDeployConfirmation();
    Serial.println("Panel 1 deploy success");
    Serial.println("Panel 2 deploy success");
    Serial.println("Panel 3 deploy success");
    Serial.println("Panel 4 deploy success");
    Serial.print("Deploying...\n");
    Serial.println("Panel 1a deploy success");
    Serial.println("Panel 1b deploy success");
    Serial.print("Deploying...\n");
    Serial.println("Panel 2a deploy success");
    Serial.println("Panel 2b deploy success");
    Serial.print("Deploying...\n");
    Serial.println("Panel 3a deploy success");
    Serial.println("Panel 3b deploy success");
    Serial.print("Deploying...\n");
    Serial.println("Panel 4a deploy success");
    Serial.println("Panel 4b deploy success");
}

void loop() {
    /*dist = get_hcsr04_distance(HCSR04_1);
    Serial.println("Distance seen by HC_SR04_1:");
    dist = get_hcsr04_distance(HCSR04_1);
    Serial.print(dist, DEC);
    Serial.print(" inches\n");
    delay(1000);
    dist = get_hcsr04_distance(HCSR04_1);
    Serial.println("Distance seen by HC_SR04_2:");
    dist = get_hcsr04_distance(HCSR04_2);
    Serial.print(dist, DEC);
    Serial.print(" inches\n");
    
    Serial.println("Distance seen by HC_SR04_3:");
    dist = get_hcsr04_distance(HCSR04_3);
    Serial.print(dist, DEC);
    Serial.print(" inches\n");
    
    Serial.println("Distance seen by HC_SR04_4:");
    dist = get_hcsr04_distance(HCSR04_4);
    Serial.print(dist, DEC);
    Serial.print(" inches\n");
    //led_blink();
    */
}
