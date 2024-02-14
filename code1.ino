/*************************************************************

  You’ll need:
   - Blynk IoT app (download from App Store or Google Play)
   - ESP32 board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "xxxxxx"
#define BLYNK_TEMPLATE_NAME "xxxxxx"
#define BLYNK_AUTH_TOKEN "your-token-xxxxxxxxxxxx"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
                
Servo servo1;

const int servoPin = 2;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "your-ssid";
char pass[] = "password";

BLYNK_WRITE(V0)
{
   int s0 = param.asInt();
   if( s0 == 1){
    Serial.println("Feed! my fish");
    for(int i =0 ; i<3;i++){
       servo1.write(0);
       delay(500);
       servo1.write(90);
       delay(1000);
    }
    servo1.write(0);
    delay(500);
   }else{ 
     // noting 
   }
  
}


void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
  servo1.attach(servoPin);
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
