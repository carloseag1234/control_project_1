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
      Serial.println();
      Serial.println(F ( "CAMBIO DE VELOCIDAD"));
      Serial.println(F ("Ingrese la velocidad en rad/ s:"));
      while(Serial.available () == 0) {;}
      Serial.readBytesUntil('\n', vel, 3) ;
      delay (100) ;
      while(Serial.available ( )>0){Serial.read( );} 
      v = atoi(vel) ;
      analogWrite(ENA,v);
      Serial.print (F("Se cambio la velocidad a: "));
      Serial.println(v);
     break;

    case '5':
      Serial.println();
      Serial.println(F ( "CAMBIO DE POSICION"));
      Serial.println(F ("Ingrese la posición:"));
      while(Serial.available () == 0) {;}
      Serial.readBytesUntil('\n', pos, 3) ;
      delay (100) ;
      while(Serial.available ( )>0){Serial.read( );} 
      p = atoi(pos);
      //analogWrite(ENA,v);
      //if()
      Serial.print (F("Se cambio la posicion a: "));
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
  Serial.println(F("   MENU"));
  Serial.println(F("Presione una opcion 1-3: "));
  Serial.println(F("1. Gira Derecha"));
  Serial.println(F("2. Apagar"));
  Serial.println(F("3. Gira Izquierda"));
  Serial.println(F("4. Cambiar velocidad"));
  Serial.println(F("5. Cambiar posicion"));
}