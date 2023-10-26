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

void setup() {
  pinMode(PWMA,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(STBY,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(PWMB,OUTPUT);

  digitalWrite(STBY,HIGH);
  
}

void loop() {

  adelante();
  analogWrite(PWMA,150);
  analogWrite(PWMB,150);
  delay(5000);
  digitalWrite(STBY,LOW);

}

void adelante(){
  //Motor Izq
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  //Motor Der
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
}

void derecha(){
  //Motor Izq
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  //Motor Der
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
}

void izquierda(){
  //Motor Izq
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  //Motor Der
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
}

void atras(){
  //Motor Izq
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  //Motor Der
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
}

void detener(){
  //Motor Izq
  analogWrite(PWMA,0);
  //Motor Der
  analogWrite(PWMB,0);
}
