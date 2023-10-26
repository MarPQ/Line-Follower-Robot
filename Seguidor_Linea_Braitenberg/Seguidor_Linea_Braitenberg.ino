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
uint16_t sensorValues[SensorCount];
//Pesos
float w0 = 0;
float w1 = 0;
float w2 = 0;
//float w3 = 0;
//Velocidad motores
float vl = 0;
float vr = 0;


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

  Serial.begin(9600);
}


void loop()
{
  // Leer sensores
  qtr.read(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++)
  {
        if (sensorValues[i] >= 900){        //Umbral para definir si el sensor detecta la linea
        sensorValues[i] = 1;   
        }
        else{
        sensorValues[i] = 0;
        }
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
    //Serial.println();

  w0 = 80;
  w1 = w0*0.7;
  w2 = w0*0.3;
  //w3 = w0*0.1;
  
  vl = w0 - sensorValues[5]*w1 - sensorValues[4]*w2;
  vr = w0 - sensorValues[0]*w1 - sensorValues[1]*w2;
  
  adelante();
  analogWrite(PWMA,vl);
  analogWrite(PWMB,vr);

  Serial.print(vl);
  Serial.print('\t');
  Serial.print(vr);
  Serial.println();
}

void adelante(){
  //Motor Izq
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  //Motor Der
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
}
