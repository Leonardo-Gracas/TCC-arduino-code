#include <Servo.h>
#include <HCSR04.h>
#include <math.h>

#define SERVO 7 // Porta Digital 7 PWM
#define p_trigger 4
#define p_echo 5

Servo s; // Variável Servo
int pos; // Posição Servo

int matriz[32][32], sensorPos[2], seeing[2];

UltraSonicDistanceSensor distanceSensor(p_trigger, p_echo);
float dist_cm, dist_M;

void setup ()
{
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
  sensorPos[0] = 256;
  sensorPos[1] = 256;
}

void readSensor(){
  float degree = pos;
  float hipotenusa = distanceSensor.measureDistanceCm();
  float co = (sin(M_PI / (180/degree)) * hipotenusa);
  float ca = (cos(M_PI / (180/degree)) * hipotenusa);
  float x = co;
  float y = ca;
  Serial.print("degree: ");
  Serial.println(degree);
  Serial.print("hipotenusa: ");
  Serial.println(hipotenusa);
  Serial.print("x (CO): ");
  Serial.println(x);
  Serial.print("y (CA): ");
  Serial.println(y);
  
}

void loop()
{
  for(pos = 0; pos < 10; pos++)
  {
    s.write(pos);
    readSensor();
    delay(1000);
  }
  delay(1000);
  pos = 0;

  Serial.begin(9600);  
  dist_cm=distanceSensor.measureDistanceCm();
  dist_M=dist_cm/100;
  Serial.print("Distancia ");
  Serial.print(dist_cm);
  Serial.print("cm | ");
  Serial.print(dist_M);
  Serial.println("m");
  
  /*for(int i = 0; i < 32; i++){
    for(int j = 0; j < 32; j++){
      Serial.print(matriz[i][j]);
    }
    Serial.println(' ');
  }*/
  Serial.println("----------------------------------");
  readSensor();
  delay(10000);
}
