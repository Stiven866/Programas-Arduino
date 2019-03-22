#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 53
#define RST_PIN 49
#define a 2
#define b 3
#define BOMBILLO 4
int tags [4]= {0x83,0x7D,0x23,0xF0};
bool val;
MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class
void setup() {
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(BOMBILLO, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  
  Serial.begin(9600);
  SPI.begin();       // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522
  Serial.println("RFID reading UID");
}
void loop() {
  if(digitalRead(a)){
    val=true;
  }else if(digitalRead(b)){
    val=false;
  }
  if ( mfrc522.PICC_IsNewCardPresent())
  {
    if ( mfrc522.PICC_ReadCardSerial())
    {
      Serial.print("Tag UID:");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        if(mfrc522.uid.uidByte[i]== tags[i]){
            val = true;
          }else{
            val = false;
          }
      }

      Serial.println();
      mfrc522.PICC_HaltA();
    }
  }

  if (val) {
    digitalWrite(BOMBILLO, 1);
    Serial.println("Estoy encendido :)");
  } else{
    digitalWrite(BOMBILLO, 0);
    Serial.println("Estoy apagado :(");
  }
}
