
const int dataIN = 2; 

unsigned long prevmillis; 
unsigned long duration; 
unsigned long refresh;

int rpm;

boolean currentstate; 
boolean prevstate; 
void setup()
{
  pinMode(dataIN,INPUT);       
  prevmillis = 0;
  prevstate = LOW;  
  Serial.begin(9600);
}

void loop()
{
 // RPM Measurement
  currentstate = digitalRead(dataIN);
 if( prevstate != currentstate) 
   {
     if( currentstate == HIGH )
       {
         duration = ( micros() - prevmillis );
         rpm = (60000000/duration); 
         prevmillis = micros(); 
       }
   }
  prevstate = currentstate;
    if( ( millis()-refresh ) >= 100 )
    {
       Serial.println(rpm);  
    }
//Speed(m/s) = Pi * D(in meter) * rps
//Speed(km/hr) = Pi*D(in kilometer) * rpm * 60
  
}

