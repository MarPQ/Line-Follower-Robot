#include <QTRSensors.h>

QTRSensors qtra((unsigned char[]) {0, 1, 2, 3, 4},5);
unsigned int IR[5];


void setup() {
  Serial.begin(9600);

}

void loop() {
  qtra.read(IR);

   for (int i=0; i<5; i++)
  {
    Serial.print(IR[i]); 
    Serial.print(" , ");
  }

  Serial.println(); 

}
