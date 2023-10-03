# 1 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"
///Motor en encoder controller Coede

/*----Pin setup variables----*/
  const int ENC_A = 2; //Interruption Pin
  const int ENC_B = 3; //Interruption Pin
  const int IN1 = 4; //Output Pin
  const int IN2 = 5; //Output Pin
  const int ENA = 6; //PWM Pin

/*----Global Variables----*/
  unsigned long timing; //time
  int v = 125; //PWM speed value
  float kp = 1; //Control Gains k
  float kd = 5;
  float ki = 0.001;
  float ts = 0.02; //Sample time
  const float maxSteps = 341.2; //PPR(Pulse Per Revolution) Resolution 
  volatile int ProcessCounter = 0;
  float SetPoint=0;
  float cv=0; //Control Value
  float cvm1=0; //Control Value minus one
  float error=0;
  float errorm1=0; //Error minus one
  float errorm2=0; //Error minus two

// Serial input for Revolutions number
  String vueltas;

/*----Pin Setup function----*/
void setup()
{
  Serial.begin(9600); //Serial port begin

  /*----Interruption Encoder Read*/
  pinMode(ENC_A, 0x2);
  pinMode(ENC_B, 0x0);
  attachInterrupt(((ENC_A) == 2 ? 0 : ((ENC_A) == 3 ? 1 : -1)), doEncodeA, 1);

  /*----Signals Motors----*/
  pinMode(IN1, 0x1);
  pinMode(IN2, 0x1);
  pinMode(ENA, 0x1);

  /*----Serial Instrucction----*/
  Serial.println( ("Ingrese las vueltas deseadas :"));
}

void loop() {

    if(millis() > timing + ts*1000){
        timing = millis();
        v=ControlValue();
        if (v>255) v = 255;
    }

      /*----Speed initialaizer----*/
      analogWrite(ENA,v);

      /*--Reach Set Point--*/
      if(error<=5 && error>=-5)
      {
        digitalWrite(IN1, 0x0);
        digitalWrite(IN2, 0x0);
      }else
      {
        if(error<-2)
        {
          digitalWrite(IN1, 0x1);
          digitalWrite(IN2, 0x0);
        }
        if(error>2)
        {
          digitalWrite(IN1, 0x0);
          digitalWrite(IN2, 0x1);
        }
      }
  }

/*----Process Counter Updater----*/
void doEncodeA()
{
  (digitalRead(ENC_A) == digitalRead(ENC_B))? (ProcessCounter++) : (ProcessCounter--);
}

/*----Set Point Reader----*/
void serialEvent() {
  while(Serial.available () == 0) {;}
      vueltas = Serial.readStringUntil('\n');
      SetPoint = (String(vueltas).toFloat());
      SetPoint = SetPoint*maxSteps/8;

}
/*-------Control Value Setter------*/
float ControlValue(){
  cvm1 = cv;
  cv = cvm1+(kp+(kd/ts))*error+(-kp+ki*ts-2*(kd/ts))*errorm1+(kd/ts)*errorm2;
  errorm2 = errorm1;
  errorm1 = error;
  error = SetPoint - ProcessCounter;
  return cv;
}
