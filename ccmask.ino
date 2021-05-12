#define echoPin 7
#define trigPin 6
int sound = 8;
int Vin;  // Variable to read the value from Arduino A0
float Temperature; // variable that receives the converted voltage


long duration;
int distance;
void setup(){
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(sound,OUTPUT);
 }
 
void loop(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm ");
  delay(50);

  Vin = analogRead(0);    //Tell the Arduino to read the voltage on pin A0
  Temperature = (500.0 * Vin)/1023; // Convert the read value into a voltage
  Serial.print("Temperature: ");
  Serial.print(Temperature);
  Serial.println("Deg. Celcius");
  delay(50);
  
  if(distance<60){
    digitalWrite(sound,HIGH);
    delay(50);
    digitalWrite(sound,LOW);
  }

  else{
    digitalWrite(sound,LOW);
  }

  
  
               
}
