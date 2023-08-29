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
  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
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
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, v);
      Serial.println();
      Serial.print(F("Estado: "));
      Serial.println(F("---Giro Horario---"));
      break;

    case '2':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 0);
      Serial.println();
      Serial.print(F("ESTADO: "));
      Serial.println(F("---Apagado---"));
      encoder();
      break;

    case '3':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, v);
      Serial.println();
      Serial.print(F("ESTADO: "));
      Serial.println(F("---Giro Antihorario---"));
      break;

    case '4':
      v = 0;
      Serial.println();
      Serial.println(F("CAMBIO DE VELOCIDAD"));
      Serial.println(F("Ingrese la velocidad en rad/s:"));
      while (Serial.available() == 0) {;}
      
      // Leer la entrada de velocidad hasta que se presione Enter o se llenen 10 caracteres
      char inputBuffer[10]; // Ajusta el tamaño según tus necesidades
      size_t bytesRead = Serial.readBytesUntil('\n', inputBuffer, sizeof(inputBuffer) - 1);
      inputBuffer[bytesRead] = '\0'; // Asegurarse de que la cadena esté terminada correctamente
      delay(100);
      while (Serial.available() > 0) { Serial.read(); }
      
      v = strtol(inputBuffer, nullptr, 10); // Convertir la cadena a un entero
      
      Serial.print(F("Se cambio la velocidad a: "));
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
  Serial.println(F("   MENU"));
  Serial.println(F("Presione una opcion 1-3: "));
  Serial.println(F("1"));
  Serial.println(F("2"));
  Serial.println(F("3"));
  Serial.println(F("4"));
}