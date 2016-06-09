#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define motorAA 6
#define motorAB 5
#define motorBA 3
#define motorBB 2
#define ARMA 12
#define ARMB 13
#define ARMS 4

bool c=0,s;
int i;
void setup()
{
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(motorAA,OUTPUT);
  pinMode(motorAB,OUTPUT);
  pinMode(motorBA,OUTPUT);
  pinMode(motorBB,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value);
     irrecv.resume(); // Receive the next value
     
     
    }

 if (results.value == 3772778233) {
//UP 
 m_advance(); 
  }else if (results.value == 3772810873) {
//DOWN
 m_backward();
  }else if (results.value == 3772782313) {
//Stop
 m_stop();
  }else if (results.value == 3772794553) {
//RIGHT
  m_right();
  }else if (results.value == 3772819033) {
//LEFT
  m_left();
  }else if (results.value == 551486205) {
//CATCH  
closearm();
  }else if (results.value == 551518845) {
//RELEASE
openarm();

  }
}


void arm(bool dir) {
//This function is used by other functions dont bother looking
digitalWrite(ARMA,dir);
digitalWrite(ARMB,!dir);
delay(5);
}

void openarm(){
s=digitalRead(ARMS);
while (s == 0) {
s=digitalRead(4);
Serial.println(s);
arm(1);
}
stoparm();
}
void closearm(){
arm(0);
}
void stoparm(){
digitalWrite(ARMA,0);
digitalWrite(ARMB,0);
  }

void m_advance(){
digitalWrite(6,1);
digitalWrite(3,1);
digitalWrite(5,0);
digitalWrite(2,0);
  }

 void m_stop(){
  digitalWrite(6,0);
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(2,0);
  }

void m_right(){
digitalWrite(6,0);
digitalWrite(3,1);
digitalWrite(5,1);
digitalWrite(2,0);
  }

void m_left(){
digitalWrite(6,0);
digitalWrite(3,1);
digitalWrite(5,1);
digitalWrite(2,0);
  }
void m_backward(){
digitalWrite(6,0);
digitalWrite(3,0);
digitalWrite(5,1);
digitalWrite(2,1);
  }
