#include <HCSR04.h>

#define p_trigger 4
#define p_echo 5

UltraSonicDistanceSensor distanceSensor(p_trigger, p_echo);

int dist_cm, dist-M;

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    dist_cm=distanceSensor.measureDistanceCm();
    dist_m=dist_cm/100;
    Serial.print("Distancia ");
    Serial.print(dist_cm);
    Serial.print("cm | ");
    Serial.print(dist_m);
    Serial.println("m");
    Serial.println("----------------------------------");
    delay(1000);
}
