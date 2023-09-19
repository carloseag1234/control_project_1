///Motor en encoder controller Coede

/*----Pin setup variables----*/
  const int ENC_A = 2; //Interruption Pin
  const int ENC_B = 3; //Interruption Pin
  const int IN1 = 4;   //Output Pin
  const int IN2 = 5;   //Output Pin
  const int ENA = 6;   //PWM Pin

/*----Global Variables----*/
  int v = 125;                     //PWM speed value
  const float maxSteps = 341.2;    //PPR(Pulse Per Revolution) Resolution 
  volatile int ProcessCounter = 0; 
  float SetPoint=0;
  float error=0;

// Serial input for Revolutions number
  String vueltas;

/*----Pin Setup function----*/
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
  Serial.println( ("Ingrese las vueltas deseadas :"));
}

void loop() {
      /*----Speed initialaizer----*/
      analogWrite(ENA,v);

      /*----Process to Set Point Error----*/
      error=SetPoint-ProcessCounter;
      
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
