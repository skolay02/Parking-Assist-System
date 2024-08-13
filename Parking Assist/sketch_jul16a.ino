//PARKING ASSIST SYSTEM

int trigpin=12;
int echopin=11;
int buzzpin=10;
int ledpin = 9;

float pingtraveltime;
float pingtraveldistance;
float distance;

void setup()
{
  Serial.begin(9600);
 
  
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzzpin,OUTPUT);
  pinMode(ledpin,OUTPUT);
  
}

void loop()
{
  //Calculation of distance
  digitalWrite(trigpin,LOW);
  delay(10);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin,LOW);
  
  pingtraveltime=pulseIn(echopin,HIGH);
  delay(25);
  pingtraveldistance=pingtraveltime*((765.0*5280.0*12.0)/(3600.0*1000000.0)); //Distance into inches
  distance=pingtraveldistance/2.0;
  Serial.println(distance);
  delay(100);




if(distance<=8 && distance>=5)
 {
    digitalWrite(buzzpin,HIGH);
    delay(200);
    digitalWrite(buzzpin,LOW);
    delay(200);
 }


 if(distance<=5 && distance>=3)
 {
    digitalWrite(buzzpin,HIGH);
    delay(50);
    digitalWrite(buzzpin,LOW);
    delay(50);
    digitalWrite(ledpin,HIGH);
    delay(70);
    digitalWrite(ledpin,LOW);
    delay(70);

 }

 if(distance<=3)
 {
    digitalWrite(buzzpin,HIGH);
    delay(50);
    digitalWrite(buzzpin,LOW);
    delay(20);
    digitalWrite(ledpin,HIGH);

 }
 
 else
 {
 digitalWrite(buzzpin,LOW);
 digitalWrite(ledpin,LOW);
 }

}
  