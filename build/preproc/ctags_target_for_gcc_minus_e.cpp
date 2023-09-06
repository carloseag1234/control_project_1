# 1 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
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
volatile int ProcessPoint = 0;
int counter = 0;
int error=0;

void setup()
{
  Serial.begin(9600);
  pinMode(ENC_A, 0x2);
  pinMode(ENC_B, 0x0);
  attachInterrupt(((ENC_A) == 2 ? 0 : ((ENC_A) == 3 ? 1 : -1)), doEncodeA, 1);
  pinMode(IN1, 0x1);
  pinMode(IN2, 0x1);
  pinMode(ENA, 0x1);
  Serial.println( ("Ingrese las vueltas deseadas :"));
}

void loop() {
      analogWrite(ENA,v);
      error=vu-ProcessPoint;
      Serial.println( vu);
      Serial.println(ProcessPoint);
      if(error<2){
        digitalWrite(IN1, 0x1);
          digitalWrite(IN2, 0x0);
        }
        if(error>-2){
          digitalWrite(IN1, 0x0);
          digitalWrite(IN2, 0x1);
        }
        if(error>=-5 && error<=5){
          digitalWrite(IN1, 0x0);
          digitalWrite(IN2, 0x0);
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
      ProcessPoint++;
    }
    else
    {
      ProcessPoint--;
    }
}

void serialEvent() {
  while(Serial.available () == 0) {;}
      vueltas = Serial.readStringUntil('\n');
      vu = (String(vueltas).toInt());
      vu = vu*maxSteps;

}
