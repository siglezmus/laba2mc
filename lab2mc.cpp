#include <Arduino.h>
#include <TimerThree.h>
const int green3 = 4;
const int green2 = 3;
const int green1 = 2;
const int resistor = A0;
const double pi = 3.14;
double k;
double t;

void setup() {
	pinMode(green1, OUTPUT);
	pinMode(green2, OUTPUT);
	pinMode(green3, OUTPUT);
	pinMode(resistor, INPUT);
	Timer3.initialize(16000);
	Timer3.attachInterrupt(func);
}

void func(){
	t = millis()/double(1000);
	k = analogRead(resistor)/int(100);
	analogWrite(green1,255*(sin(k*t)+1)/2);
	analogWrite(green2, 255*(sin(k*t+2*pi/3)+1)/2);
	analogWrite(green3,255*(sin(k*t+4*pi/3)+1)/2);
}

void loop() {

}
