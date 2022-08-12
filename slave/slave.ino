
#include <Wire.h>
#include <Servo.h>
Servo myservo;  
int pos = 0;
int arr_size=0;
char Read_values[100];
void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);  // start serial for output
  myservo.attach(9); 
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  char x = Wire.read(); 
  if (x!=10){
    Read_values[arr_size]={x};
    arr_size++;
    }
    if(x==10){
    String (value)=Read_values;
    Serial.println(value);
    if(Read_values[0]=='s'||Read_values[0]=='S')
    {
      //servo_write(value);
      value.remove(0,1);
      pos = value.toInt();
      Serial.println(pos);
      myservo.write(pos);
      }
    clear_data();
    
    }
}
void clear_data()
{
  for (int i=0;i<=arr_size;i++)
  {
    Read_values[i]=" ";
    }
    arr_size=0;
  }
