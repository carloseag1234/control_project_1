# 1 "C:\\Users\\carlo\\Desktop\\gitProject\\control_project_1\\control_project_1.ino"


int encoderPin1 = 2;
int encoderPin2 = 3;
volatile int lastEncoded = 0;
volatile long encoderValue = 0;
volatile long correctEncoderValue =0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

void setup() {
   Serial.begin (9600);
   pinMode(encoderPin1, 0x0);
   pinMode(encoderPin2, 0x0);
   digitalWrite(encoderPin1, 0x1); //turn pullup resistor on
   digitalWrite(encoderPin2, 0x1); //turn pullup resistor on
   attachInterrupt(0, updateEncoder, 1);
   attachInterrupt(1, updateEncoder, 1);

   pinMode(5,0x1);
   pinMode(6,0x1);
}

void loop() {
   correctEncoderValue = encoderValue/4;

   Serial.println(correctEncoderValue);

  if ( 0<=correctEncoderValue && correctEncoderValue < 3000) {
   analogWrite(5,127);
   digitalWrite(6,0x0);
  } else {
   analogWrite(5,0);
   digitalWrite(6,0x0);
  }
   delay(100);

}

void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded; //store this value for next time
}
