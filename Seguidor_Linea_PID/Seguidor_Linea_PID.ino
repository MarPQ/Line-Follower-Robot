#include <QTRSensors.h>
//Motor Izq
const int PWMA = 10;
const int AIN2 = 9;
const int AIN1 = 8;
//Activa el control del modulo H
const int STBY = 7;
//Motor Der
const int BIN1 = 12;
const int BIN2 = 13;
const int PWMB = 11;
//Sensor 
QTRSensors qtr;
const uint8_t SensorCount = 6;
signed int IR[6];
//Velocidad motores
int v = 100;

//PID
float kp = 0.08;
float ki = 0.03;
float kd = 0.0;

int p,d;
float i = 0;
float p_old = 0;
int u;

void setup()
{
  //configurar sensores
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount);
  qtr.setEmitterPin(6);
  //congifura motores 
  pinMode(PWMA,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(STBY,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(PWMB,OUTPUT);

  digitalWrite(STBY,HIGH);
}

void loop()
{
  // Leer sensores
  qtr.read(IR);

  p = 3*IR[0] + 2*IR[1] + IR[2] - IR[3] - 2*IR[4] - 3*IR[5];

  i = i+p;

  d = p-p_old;

  p_old = p;
 
  if ((p*i)<0) i=0;

  u = kp*p + ki*i + kd*d;

  motores();
  analogWrite(PWMA,v + u);
  analogWrite(PWMB,v - u);

}

void motores(){
  //Motor Izq
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  //Motor Der
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
}
