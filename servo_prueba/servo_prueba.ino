#include <Servo.h> //libreria 

Servo miServo;

int angulo; //la posicion que queremos
int i = 1; //para controlar 

void setup() {
  miServo.attach(3); //el cable datos se conecta allí
  Serial.begin(9600); //para ver el angulo
}

void loop() {

  if(i==1){
    angulo++;
  }
  else{
    angulo--;
  }
  
  Serial.println(angulo);

  if(angulo<=1) {
    angulo = 1;
    i = 1;
    delay(200);
  }

  if(angulo>=180) {
    angulo = 180;
    i = 0;
    delay(200);
  }

  miServo.write(angulo);
  delay(10);
}
