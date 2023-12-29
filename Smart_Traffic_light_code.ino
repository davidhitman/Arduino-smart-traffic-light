int yellow1 =10;//yellow1 led pin initialized
int red1=11; // red1 led pin initialized
int blue1=9; // blue1 led pin initialized
int yellow2 =12; //yellow2 led pin initialized
int red2=13; //red2 led pin initialized
int blue2=8;// blue2 led pin initialized

int sensor1inp =6;      //echo1 pin initialized
int sensor1out=5;       //trig1 pin initialized
int sensor2inp =4;      //echo2 pin initialized
int sensor2out =3;      //trig2 pin initialized
int sensor3inp =2;      //echo3 pin initialized
int sensor3out =7;      //trig3 pin initialized

int trigPin = A3;    // Trigger4
int echoPin = A2;    // Echo4
long duration, cm;   //duration of the sensor4 and cm is the distance4  
 
unsigned long duration1;          //variables for storing duration of ultrasonic sensor to return a value
unsigned long duration2;          //variables for storing duration of ultrasonic sensor to return a value
unsigned long duration3;          //variables for storing duration of ultrasonic sensor to return a value

unsigned int d1;                 // variables for storing distance
unsigned int d2;                 // variables for storing distance
unsigned int d3;                 // variables for storing distance


void setup() {
  
   pinMode(sensor1out, OUTPUT);            // setting up output
   pinMode(sensor1inp, INPUT);            // setting up input
   pinMode(sensor2out, OUTPUT);           // setting up output
   pinMode(sensor2inp, INPUT);             // setting up input
   pinMode(sensor3out, OUTPUT);           // setting up output
   pinMode(sensor3inp, INPUT);             // setting up input
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  
  pinMode(red1, OUTPUT);                // setting up output
  pinMode(yellow1, OUTPUT);            // setting up output
  pinMode(blue1, OUTPUT);              // setting up output
  pinMode(red2, OUTPUT);               // setting up output
  pinMode(yellow2, OUTPUT);            // setting up output
  pinMode(blue2, OUTPUT);              // setting up output
            
}


void loop() {       // loops code:

 
     readSensor();                          // calling readSensor(); to get readings
     digitalWrite(red1,LOW);                //switching red1 led off         
      digitalWrite(blue1,HIGH);             //switching blue1 led on
      digitalWrite(yellow1,LOW);            // switching yellow1 led off
      digitalWrite(blue2,LOW);              // switching blue2 led off
      digitalWrite(red2,HIGH);              // switching red2 led on
       digitalWrite(yellow2,LOW);           // switching yellow2 led off
        
       if((d2==1 && d3==1)||(d2==1 && d3==0)||(d2==0 && d3==1)){         // after checking the sensors, if there is traffic, we increase the duration of the siginal 
        delay(10000);
       }
       else delay(3000);                    //else the duration remains the same
      digitalWrite(red1,LOW);               //switching red1 led off    
      digitalWrite(blue1,LOW);              //switching blue1 led off
      digitalWrite(yellow1,HIGH);           // switching yellow1 led on
      digitalWrite(blue2,LOW);              // switching blue2 led off
      digitalWrite(red2,HIGH);              // switching red2 led on
       digitalWrite(yellow2,LOW);           // switching yellow2 led off
       delay(500);                          
       
      digitalWrite(red1,HIGH);             //switching red1 led on
      digitalWrite(blue1,LOW);              //switching blue1 led off
      digitalWrite(yellow1,LOW);            // switching yellow1 led off
      digitalWrite(blue2,LOW);              // switching blue2 led off
      digitalWrite(red2,HIGH);              // switching red2 led on
       digitalWrite(yellow2,LOW);           // switching yellow2 led off
       delay(500);
      readSensor();                         // calling readSensor(); to get the distance readings
       
      digitalWrite(red1,HIGH);            //switching red1 led on
      digitalWrite(blue1,LOW);             //switching blue1 led off
      digitalWrite(yellow1,LOW);           // switching yellow1 led off
      digitalWrite(blue2,HIGH);            // switching blue2 led on
      digitalWrite(red2,LOW);              // switching red2 led off
       digitalWrite(yellow2,LOW);          // switching yellow2 led off
      
       if((cm==1 && d1==1)||(cm==1 && d1==0)||(cm==0 && d1==1)){   // after checking the sensors, if there is traffic, we increase the duration of the siginal 
        delay(10000);
       }
       else delay(3000);
       
      digitalWrite(red1,HIGH);           //switching red1 led on
      digitalWrite(blue1,LOW);           //switching blue1 led off
      digitalWrite(yellow1,LOW);         //switching yellow1 led off
      digitalWrite(blue2,LOW);           // switching blue2 led off
      digitalWrite(red2,LOW);            // switching red2 led off
      digitalWrite(yellow2,HIGH);        // switching yellow2 led on
       delay(500);
      digitalWrite(red1,HIGH);          //switching red1 led on
      digitalWrite(blue1,LOW);          //switching blue1 led off
      digitalWrite(yellow1,LOW);        // switching yellow1 led off
      digitalWrite(blue2,LOW);         // switching blue2 led off
      digitalWrite(red2,HIGH);         // switching red2 led on
      digitalWrite(yellow2,LOW);        // switching yellow2 led off
       delay(500);
       }
      
  
   
    



  void readSensor(){              // method for the sensors



    
  digitalWrite(sensor1out, LOW); 
  delayMicroseconds(2);
    digitalWrite(sensor1out, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
    delayMicroseconds(10);
    digitalWrite(sensor1out, LOW);
    duration1 = pulseIn(sensor1inp, HIGH); // Read receiver pulse time
    d1= duration1/58; // Transform pulse time to distance 

    
    digitalWrite(sensor2out, LOW); 
    delayMicroseconds(2);
    digitalWrite(sensor2out, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
    delayMicroseconds(10);
    digitalWrite(sensor2out, LOW);
    duration2 = pulseIn(sensor2inp, HIGH); // Read receiver pulse time
    d2= duration2/58; // Transform pulse time to distance 
   
    
    digitalWrite(sensor3out, LOW); 
    delayMicroseconds(2);
    digitalWrite(sensor3out, HIGH); // Pulse for 10μ s to trigger ultrasonic detection
    delayMicroseconds(10);
    digitalWrite(sensor3out, LOW);
     duration3 = pulseIn(sensor3inp, HIGH); // Read receiver pulse time
    d3= duration3/58; // Transform pulse time to distance 
   
    digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  
 if (d1 < 5) d1 = 1; 
     else d1 = 0; 
     if (d2 < 5) d2 = 1; 
     else d2 = 0;        
     if (d3 < 5) d3 = 1; 
     else d3 = 0; 
     if (cm < 5) cm = 1; 
     else cm = 0;      //these condition change the distance to 0 if the distance is more then 5  and  to 1 when the distance is  less then 5
    Serial.print(d1); //Output distance
    Serial.print("\t");
    Serial.print(d2); //Output distance
    Serial.print("\t");
    Serial.print(d3); //Output distance
    Serial.print("\t");
    Serial.print(cm);
    Serial.println();
    
  }
