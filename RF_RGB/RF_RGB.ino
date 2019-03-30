/*
By Kiike Chávez  30/03/2019
*/

int botonState = 0;

void setup() {
  Serial.begin(9600); // configurando la velocidad en baudios
  Serial.println("Decodificación del botón del receptor RF"); // Imprimiendo
  pinMode(2, OUTPUT); // COLOR ROJO
  pinMode(3, OUTPUT); // COLOR VERDE
  pinMode(4, OUTPUT); // COLOR AZUL
  pinMode(9, INPUT_PULLUP); // BOTÓN A
  pinMode(10, INPUT_PULLUP); // BOTÓN B
  pinMode(11, INPUT_PULLUP); // BOTÓN C
  pinMode(12, INPUT_PULLUP); // BOTÓN D

}

void loop() {


  if (digitalRead(9) == HIGH) { // Botón A presionado
    Serial.println("Estás oprimiendo el botón A");
    botonState = 1;
    delay(200);
  }
  if (digitalRead(10) == HIGH) { // Botón B presionado
    Serial.println("Estás oprimiendo el botón B");
    botonState = 2;
    delay(200);
  }
  if (digitalRead(11) == HIGH) { // Botón C presionado
    Serial.println("Estás oprimiendo el botón C");
    botonState = 3;
    delay(200);
  }
  if (digitalRead(12) == HIGH) { // Botón D presionado
    Serial.println("Estás oprimiendo el botón D");
    botonState = 4;
    delay(200);
  }

  switch (botonState) {

    case 1:
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      break;

    case 2:
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      break;

    case 3:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      break;
    
    case 4:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      break;
      
  }
}
