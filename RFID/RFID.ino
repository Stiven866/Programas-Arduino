#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 53
#define RST_PIN 2
int tags [4] = {0x83, 0x7D, 0x23, 0xF0};
bool val;
MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class
void setup() {

  Serial.begin(9600);
  SPI.begin();       // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522
  Serial.println("RFID reading UID");
}
void loop() {
  if ( mfrc522.PICC_IsNewCardPresent())
  {
    if ( mfrc522.PICC_ReadCardSerial())
    {
      Serial.print("Tag UID:");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);

        if (mfrc522.uid.uidByte[i] == tags[i]) {
          val = true;
        } else {
          val = false;
        }
      }

      Serial.println();
      mfrc522.PICC_HaltA();
    }
  }
  if(val==true){
    Serial.println("Bienvenido");
    val=false;
  }


}
