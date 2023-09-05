const int ENC_A = 2;
const int ENC_B = 3;
char op = '0';
String vel ;
String vueltas;
const int IN1 = 4;
const int IN2 = 5;
const int ENA = 6;
int v = 50;
int vu=0;
bool sentido;
const float maxSteps = 341.2;
volatile int ISRCounter = 0;
int counter = 0;
int error=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_A), doEncodeA, CHANGE);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.println( ("Ingrese las vueltas deseadas :"));
}

void loop() {
      analogWrite(ENA,v);
      error=vu-ISRCounter;
      Serial.println( vu);
      Serial.println(ISRCounter);
      if(error<2){
        digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
        } 
        if(error>-2){
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
        }
        if(error>=-5 && error<=5){
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          Serial.println("Finalizado");
          Serial.println();
        }
    
      
      
    // case '4':
    //   Serial.println();
    //   Serial.println(F ( "CAMBIO DE VELOCIDAD"));
    //   Serial.println(F ("Ingrese la velocidad en rad/ s:"));
    //   while(Serial.available () == 0) {;}
    //   vel = Serial.readStringUntil('\n');
    //   v = String(vel).toInt() ;
    //   Serial.println(v);
    //   analogWrite(ENA,v);
    //   Serial.print (F("Se cambio la velocidad a: "));
    //   Serial.println(v);
    //  break;

  }


void doEncodeA()
{
    if (digitalRead(ENC_A) == digitalRead(ENC_B))
    {
      ISRCounter++;
    }
    else
    {
      ISRCounter--;
    }
}

void serialEvent() {
  while(Serial.available () == 0) {;}
      vueltas = Serial.readStringUntil('\n');
      vu = (String(vueltas).toInt()); 
      vu = vu*maxSteps;

}
