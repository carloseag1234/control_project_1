#include <Arduino.h>
#line 1 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
///Motor en encoder controller Coede

/*----Pin setup variables----*/
  const int ENC_A = 2; //Interruption Pin
  const int ENC_B = 3; //Interruption Pin
  const int IN1 = 4;   //Output Pin
  const int IN2 = 5;   //Output Pin
  const int ENA = 6;   //PWM Pin

/*----Global Variables----*/
  unsigned long timing;            //time
  int v = 0;                     //PWM speed value
  float kp =  4.349;                    //Control Gains k
  float kd = 0;
  float ki = 740.774;
  float ts = 0.02;                 //Sample time
  const float maxSteps = 341.2;    //PPR(Pulse Per Revolution) Resolution 
  volatile int ProcessCounter = 0; 
  float SetPoint=0;
  int cv=0;                      //Control Value
  int cvm1=0;                    //Control Value minus one
  float error=0;                   
  float errorm1=0;                 //Error minus one
  float errorm2=0;                 //Error minus two

// Serial input for Revolutions number
  String vueltas;

/*----Pin Setup function----*/
#line 30 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
void setup();
#line 48 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
void loop();
#line 76 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
void doEncodeA();
#line 82 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
void serialEvent();
#line 90 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
void ControlValue();
#line 30 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
void setup() 
{
  Serial.begin(9600);       //Serial port begin

  /*----Interruption Encoder Read*/
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_A), doEncodeA, CHANGE);

  /*----Signals Motors----*/
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  /*----Serial Instrucction----*/
  Serial.println( ("Ingrese la distancia en milimetros :"));
}

void loop() {
    Serial.println(v);
    if(millis() > timing + ts*1000){
        timing = millis();
        ControlValue();
    }
      /*--Reach Set Point--*/
      if(error<=5 && error>=-5)
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);        
      }else	
      {
        if(error<-2)
        {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
        } 
        if(error>2)
        {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
        }
      } 
         
  }

/*----Process Counter Updater----*/
void doEncodeA()
{
  (digitalRead(ENC_A) == digitalRead(ENC_B))?  (ProcessCounter++) : (ProcessCounter--);
}

/*----Set Point Reader----*/
void serialEvent() {
  while(Serial.available () == 0) {;}
      vueltas = Serial.readStringUntil('\n');
      SetPoint = (String(vueltas).toFloat()); 
      SetPoint = SetPoint*maxSteps/8;

}
/*-------Control Value Setter------*/
void ControlValue(){
  errorm2 = errorm1;
  errorm1 = error;
  error = SetPoint - ProcessCounter;
  
  float a = (kp+(kd/ts))*error;
  float b = ((ki*ts)-kp-(2*kd/ts))*errorm1;
  float c = (kd/ts)*errorm2;

  cvm1 = v;
  cv =cvm1+ a+b+c;
  v=abs(cv);
  if (v>=255){v=255;}
  if(v<=130){v=130;}
  analogWrite(ENA,v);
}

