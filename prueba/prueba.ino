char tecla = ' ';
float a = 10.7, b = 5, resultado = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  holita();
}

void holita(){
    if (Serial.available() > 0) {
    tecla = Serial.read();
    if(tecla == 'a'){
      resultado = a + b;
    }else if(tecla == 'b'){
      resultado = a-b;
    }else if(tecla == 'c'){
      resultado = a*b;
    }else if(tecla == 'd'){
      resultado = a/b;
    }

    Serial.print("El resultado es: ");
    Serial.println(resultado);
  }
}
