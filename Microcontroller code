#include<OTAHelper.h>
#include<ESP32Servo.h>

const char* ssid = "realme 8i";
const char* password ="hdsdkysyh";


Servo S1;
Servo S2;
Servo S3;

// int ServoPins[]={25,26,27};
// int Channels[]={0,1,2};
// int numServo = 3;

String data="";
OTAHelper ota(ssid,password,"ritun","ritun-esp32");
WiFiServer server(3333);
int final_angles[3]={90,90,90};

void SetServo(int servo , int angle){
  angle = constrain(angle,0,180);
  if (servo == 0){
    S1.write(angle);
  }
  else if(servo==1){
    S2.write(angle);
  }
  else if(servo==2){
    S3.write(angle);
  }
}


// LEDC (didnot work)
// void SetServo(int servo, int angle){
//   angle = constrain(angle, 0, 180);
//   int duty=map(angle,0,180,3277, 6553);
//   ledcWrite(Channels[servo],duty);
//  }

void setup() {
  //setup and OTA
  Serial.begin(115200);
  ota.begin();
  //Socket setup
  server.begin();
  Serial.println("TCP Server ready");
  //Main code


  S1.attach(25);
  S2.attach(26);
  S3.attach(27);

//   //Servo LEDC setup
//  for (int i=0;i<numServo;i++){
//   ledcAttachChannel(ServoPins[i],50,16,Channels[i]);

//    SetServo(i, final_angles[i]);
//  }
 
  

}

void loop() {
  //OTA 
 ota.handle();
//socket 
  WiFiClient client = server.available();
if (client && client.connected()) {
  while (client.available()) {
    char c = client.read();
    if (c == '\n') {
      // Process full message
      char buf[50];
      data.toCharArray(buf, 50);

      char *token = strtok(buf, ",");
      for (int i = 0; i < 3 && token != NULL; i++) {
        final_angles[i] = atoi(token);
        token = strtok(NULL, ",");
      }

      Serial.println("Received: " + data);
      data = ""; 
    } else {
      data += c; 
    }
  }
}

//Main code
 for (int i=0; i<3;i++){
    SetServo(i,final_angles[i]);
   }


// myServo.write(final_angles[1]);


}
