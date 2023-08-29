# 1 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
const int ENC_A = 6;
const int ENC_B = 5;
char op = '0';
char vel []= {' ',' ',' '};
const int IN1 = 2;
const int IN2 = 3;
const int ENA = 4;
int v = 300;

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
# 39 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 39 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  "Estado: "
# 39 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  ); &__c[0];}))
# 39 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 40 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 40 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "---Giro Horario---"
# 40 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 40 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      break;

    case '2':
      digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x0);
      analogWrite(ENA, 0);
      Serial.println();
      Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 48 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 48 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  "ESTADO: "
# 48 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  ); &__c[0];}))
# 48 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 49 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 49 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "---Apagado---"
# 49 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 49 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      encoder();
      break;

    case '3':
      digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x1);
      analogWrite(ENA, v);
      Serial.println();
      Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 58 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 58 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  "ESTADO: "
# 58 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  ); &__c[0];}))
# 58 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 59 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 59 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "---Giro Antihorario---"
# 59 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 59 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      break;

    case '4':
      v = 0;
      Serial.println();
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 65 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 65 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "CAMBIO DE VELOCIDAD"
# 65 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 65 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 66 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 66 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    "Ingrese la velocidad en rad/s:"
# 66 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                    ); &__c[0];}))
# 66 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                    )));
      while (Serial.available() == 0) {;}

      // Leer la entrada de velocidad hasta que se presione Enter o se llenen 10 caracteres
      char inputBuffer[10]; // Ajusta el tamaño según tus necesidades
      size_t bytesRead = Serial.readBytesUntil('\n', inputBuffer, sizeof(inputBuffer) - 1);
      inputBuffer[bytesRead] = '\0'; // Asegurarse de que la cadena esté terminada correctamente
      delay(100);
      while (Serial.available() > 0) { Serial.read(); }

      v = strtol(inputBuffer, nullptr, 10); // Convertir la cadena a un entero

      Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 78 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 78 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  "Se cambio la velocidad a: "
# 78 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                  ); &__c[0];}))
# 78 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                  )));
      Serial.println(v);
      break;


  }
  MENU();
}

void encoder() {
  int a = digitalRead(ENC_A);
  int b = digitalRead(ENC_B);
  Serial.print(a * 5);
  Serial.print("");
  Serial.println(b * 5);
}

void MENU() {
  Serial.println();
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 97 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 97 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "   MENU"
# 97 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 97 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 98 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 98 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "Presione una opcion 1-3: "
# 98 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 98 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 99 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 99 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "1"
# 99 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 99 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 100 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 100 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "2"
# 100 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 100 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 101 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 101 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "3"
# 101 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 101 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 102 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 102 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                "4"
# 102 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino" 3
                ); &__c[0];}))
# 102 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
                )));
}
