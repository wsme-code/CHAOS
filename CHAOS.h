/*
 * CHAOS.h - Library for basic CHAOS functionality including:
 *    + Reading HC-SR04 Ultrasonic sensors
 *    + Activing burn_wire switches
 *    + Pin Designation #defines
 */
#ifndef CHAOS_h
#define CHAOS_h

// define values
int deploy_cmd_sent = 0;
int serial_input = 0;

// pin deignation for LED blinks
#define GREEN_LED_OUT  33
#define TEENSY_LED_PIN 13

// distance required for "deployment"
#define LARGE_PANEL_DEPLOY_DIST 20 // inches
#define SMALL_PANEL_DEPLOY_DIST_2a 11 // inches    actually seen is ~10
#define SMALL_PANEL_DEPLOY_DIST_1b 15 // inches    actually seen is ~10
#define SMALL_PANEL_DEPLOY_DIST 13 // inches

// pin designations for HC-SR04 ultrasonic sensors trigger pins
#define HCSR04_1 0
#define HCSR04_1a 1
#define HCSR04_1b 2
#define HCSR04_2 3
#define HCSR04_2a 4
#define HCSR04_2b 5
#define HCSR04_3 6
#define HCSR04_3a 7
#define HCSR04_3b 8
#define HCSR04_4 9
#define HCSR04_4a 10
#define HCSR04_4b 11
#define HCSR04_READ 12 // echo pin

// pin designations for nichrome burn_wire switch activation
#define BURN_WIRE1   23
#define BURN_WIRE1ab 22
#define BURN_WIRE2ab 21
#define BURN_WIRE3ab 20
#define BURN_WIRE4ab 19

// begin CHAOS deployment routine
void deployCHAOS() {
    // wait for input to be 'b'
    // 'b' = 98 in ASCII
    while (Serial.read() != 'b' && deploy_cmd_sent == 0) {
    };
    deploy_cmd_sent = 1;
    serial_input = Serial.read();
    Serial.print("Deploying...\n");
}

// ultrasonic sensor distance sensed in inches
int get_hcsr04_distance(int pin) {
    int pulse_length = 0; // uSec
    int distance = 0;     // inch
    // trigger the HCSRO4
    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);
    // determine distance pulse traveled
    pulse_length = pulseIn(HCSR04_READ, HIGH);
    distance = pulse_length/148; // 148 comes from HC-SRO4 manual to convert pulse length to inches
    return distance;
}

// basic test blink of on-board LED and an LED on a pin
void led_blink() {
    digitalWrite(TEENSY_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_OUT, HIGH);
    delay(1000);
    digitalWrite(TEENSY_LED_PIN, LOW);
    digitalWrite(GREEN_LED_OUT, LOW);
    delay(1000);
}

void burnWire(int pin) {
    analogWrite(pin, 255);
    delay(6000);
    analogWrite(pin, 0);
}

void largePanelDeployConfirmation() {
    if (get_hcsr04_distance(HCSR04_1) >= LARGE_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 1 deploy success");
    } else {
        Serial.println("Panel 1 deploy fail");
    }
    
    if (get_hcsr04_distance(HCSR04_2) >= LARGE_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 2 deploy success");
    } else {
        Serial.println("Panel 2 deploy fail");
    }

    if (get_hcsr04_distance(HCSR04_3) >= LARGE_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 3 deploy success");
    } else {
        Serial.println("Panel 3 deploy fail");
    }

    if (get_hcsr04_distance(HCSR04_4) >= LARGE_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 4 deploy success");
    } else {
        Serial.println("Panel 4 deploy fail");
    }
}

// change get_hscr04_distance pins 
void smallPanelDeployConfirmation() {
    // 1a deploymement
    if (get_hcsr04_distance(HCSR04_1) < SMALL_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 1 deploy success");
    } else {
        Serial.println("Panel 1 deploy fail");
    }
    // 1b deploymement
    if (get_hcsr04_distance(HCSR04_2) < SMALL_PANEL_DEPLOY_DIST_1b) {
        Serial.println("Panel 2 deploy success");
    } else {
        Serial.println("Panel 2 deploy fail");
    }
    
    // 2a deploymement
    if (get_hcsr04_distance(HCSR04_3) > SMALL_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 3 deploy success");
    } else {
        Serial.println("Panel 3 deploy fail");
    }
    // 2b deploymement
    if (get_hcsr04_distance(HCSR04_4) > SMALL_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 4 deploy success");
    } else {
        Serial.println("Panel 4 deploy fail");
    }
    
    // 3a deploymement
    if (get_hcsr04_distance(HCSR04_1) < SMALL_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 1 deploy success");
    } else {
        Serial.println("Panel 1 deploy fail");
    }
    
    // 3b deploymement
    if (get_hcsr04_distance(HCSR04_2) < SMALL_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 2 deploy success");
    } else {
        Serial.println("Panel 2 deploy fail");
    }

    if (get_hcsr04_distance(HCSR04_3) > SMALL_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 3 deploy success");
    } else {
        Serial.println("Panel 3 deploy fail");
    }

    if (get_hcsr04_distance(HCSR04_4) > SMALL_PANEL_DEPLOY_DIST) {
        Serial.println("Panel 4 deploy success");
    } else {
        Serial.println("Panel 4 deploy fail");
    }
}

#endif
