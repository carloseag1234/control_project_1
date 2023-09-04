# 1 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
const int ENC_A = 6;
const int ENC_B = 5;
char op = '0';
char vel []= {' ',' ',' '};
char pos []= {' ',' ',' '};
const int IN1 = 2;
const int IN2 = 4;
const int ENA = 3;
int v = 255;
int p = 0;
int position;
int b;
int a;

void setup() {
  Serial.begin(9600);
  pinMode(ENC_A, 0x0);
  pinMode(ENC_B, 0x0);
  pinMode(IN1, 0x1);
  pinMode(IN2, 0x1);
  pinMode(ENA, 0x1);
  MENU();
}

void loop() {
  encoder();
  delay(3000);
}

void serialEvent() {
  delay(20);
  op = Serial.read();

  while (Serial.available() > 0) {
    Serial.read(); // Limpieza del buffer serial
  }

  switch (op) {
    case '1':
      digitalWrite(IN1, 0x1);
      digitalWrite(IN2, 0x0);
      analogWrite(ENA, v);
      Serial.println();
      Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 44 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 44 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  "Estado: "
# 44 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  ); &__c[0];}))
# 44 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 45 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 45 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "---Giro Horario---"
# 45 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 45 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
     break;

    case '2':
      digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x0);
      analogWrite(ENA, 0);
      Serial.println();
      Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 53 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 53 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  "ESTADO: "
# 53 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  ); &__c[0];}))
# 53 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 54 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 54 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "---Apagado---"
# 54 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 54 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      encoder();
     break;

    case '3':
      digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x1);
      analogWrite(ENA, v);
      Serial.println();
      Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 63 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 63 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  "ESTADO: "
# 63 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  ); &__c[0];}))
# 63 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 64 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 64 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "---Giro Antihorario---"
# 64 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 64 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
     break;

    case '4':
      Serial.println();
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 69 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 69 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "CAMBIO DE VELOCIDAD"
# 69 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 69 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 70 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 70 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "Ingrese la velocidad en rad/ s:"
# 70 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 70 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      while(Serial.available () == 0) {;}
      Serial.readBytesUntil('\n', vel, 3) ;
      delay (100) ;
      while(Serial.available ( )>0){Serial.read( );}
      v = atoi(vel) ;
      analogWrite(ENA,v);
      Serial.print ((reinterpret_cast<const __FlashStringHelper *>(
# 77 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                   (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 77 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                   "Se cambio la velocidad a: "
# 77 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                   ); &__c[0];}))
# 77 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                   )));
      Serial.println(v);
     break;

    case '5':
      Serial.println();
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 83 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 83 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "CAMBIO DE POSICION"
# 83 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 83 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 84 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 84 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "Ingrese la posición:"
# 84 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 84 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      while(Serial.available () == 0) {;}
      Serial.readBytesUntil('\n', pos, 3) ;
      delay (100) ;
      while(Serial.available ( )>0){Serial.read( );}
      p = atoi(pos);
      //analogWrite(ENA,v);
      //if()
      Serial.print ((reinterpret_cast<const __FlashStringHelper *>(
# 92 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                   (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 92 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                   "Se cambio la posicion a: "
# 92 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                   ); &__c[0];}))
# 92 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                   )));
      Serial.println(p);
     break;

  }
  MENU();
}

void encoder() {
  b = digitalRead(ENC_B);
  a = digitalRead(ENC_A);
  if(a != b){
    if(digitalRead(ENC_B) != a){
        position++;
    } else {
        position--;
    }
    b = a;
  }
}

void MENU() {
  Serial.println();
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 115 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 115 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "   MENU"
# 115 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 115 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 116 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 116 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "Presione una opcion 1-3: "
# 116 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 116 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 117 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 117 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "1. Gira Derecha"
# 117 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 117 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 118 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 118 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "2. Apagar"
# 118 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 118 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 119 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 119 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "3. Gira Izquierda"
# 119 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 119 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 120 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 120 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "4. Cambiar velocidad"
# 120 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 120 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 121 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 121 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "5. Cambiar posicion"
# 121 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 121 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
}
