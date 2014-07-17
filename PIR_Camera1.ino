#include <Servo.h>

Servo Servo1;

const int led_pin = 8;
const int pir_pin = 7;
const int servo_pin = 6;

int pir_value;

void setup() {
  Serial.begin(9600); 
  pinMode(led_pin, OUTPUT); 
  pinMode(pir_pin, INPUT);  
  Servo1.attach(servo_pin);
}

void loop() {
  
  pir_value = digitalRead(pir_pin);
  
  // check if motion was detected
  if (pir_value == LOW) {
    blink_LED();
    move_servo();
    delay(5000);
  }
  
}

void blink_LED() {
  digitalWrite(led_pin, HIGH);
  delay(500);
  digitalWrite(led_pin, LOW);
  delay(500);
  digitalWrite(led_pin, HIGH);
  delay(500);
  digitalWrite(led_pin, LOW);
  delay(500);
}

void move_servo() {

  int pos = 0;
  
  for(pos = 80; pos < 100; pos += 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for(pos = 100; pos>=80; pos-=1)     // goes from 180 degrees to 0 degrees
  {                                
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}
