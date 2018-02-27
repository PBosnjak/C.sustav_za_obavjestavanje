#include <SoftwareSerial.h>
#include <LedControl.h>

#define DATA_pin 7
#define CS_pin 6
#define CLK_pin 5

LedControl LED_CTRL (DATA_pin, CLK_pin, CS_pin, 1);

SoftwareSerial BT(10,11); 
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND
void setup()  
{
   LED_CTRL.shutdown(0,false);
  /* Set the brightness to a medium value */
  LED_CTRL.setIntensity(0,8);
  /* and clear the display */
  LED_CTRL.clearDisplay(0); 
  // set digital pin to control as an output
  pinMode(2, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
}
char a; // stores incoming character from other device
String str;
void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  //beep(200,2);
  {
    a=(BT.read());
    str += a;
    if (a=='b')
    {
      BT.println(str);
      str="";
         LED_CTRL.clearDisplay(0);
      LED_CTRL.setRow(0, 3, 24);
      LED_CTRL.setRow(0, 4, 24);
   //   ispisSlova();
    }
    if (a=='?')
    {
      beep(200,2);
       LED_CTRL.clearDisplay(0);
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED on");
    }   
    // you can add more "if" statements with other characters to add more commands
  }
}

void beep(byte delayms, int pin){
 tone(pin, 1000);
 delay(delayms);
 noTone(pin);
 delay(delayms);
}

void ispisSlova(){
  
    LED_CTRL.clearDisplay(0);
    LED_CTRL.setRow(0, 3, 24);
    LED_CTRL.setRow(0, 4, 24);
  }
