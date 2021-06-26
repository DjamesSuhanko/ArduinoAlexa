#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int alexa[5] = {0};

void setup() {
  pinMode(8,OUTPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    
  }

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  Serial.println("comecou");
}

void loop() { // run over and over
  uint8_t i = 0;
  while (mySerial.available()){
    alexa[i] = mySerial.read();
    i++;

    Serial.println("-----");
  Serial.println(alexa[0]);
  Serial.println(alexa[1]);
  Serial.println(alexa[2]);
  Serial.println("-----");
  }


  if (alexa[0] != 0){
    if (alexa[0] = 0x5E && alexa[1] == 117){
      if (alexa[2] == 49){
        digitalWrite(8,HIGH);
        Serial.println("Ligado");
      }
      else{
        digitalWrite(8,LOW);
        Serial.println("Desligado");
      }
    }
  }

  memset(alexa,0,sizeof(alexa));
}


