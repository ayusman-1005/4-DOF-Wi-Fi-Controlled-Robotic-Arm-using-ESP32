This is a 4 degree of freedom robotic arm;  made with the ESP32.
The components required are:
 1-ESP32, 2-servo motor(3x), 3-Stepper motor, 4-breadboard, 5-jumper wires

Material:Cardboard, Hotglue 

Software:Arduino IDE, VS Code

CODE: I)The ESP32 code contains the OTA(over the Air), Servo control, Socket(for wireless control), Decoder.
         OTA, this section code helps push updates wirelessly without the need of connecting physically every time.
         it uses the Wifi module; OTA is not built into the ESP32 bootloader hence it is required to include the OTA code everytime in the code. Here an OTA header file  
         keeps the code clean.
         Servo control, this section uses the standard ESP32 Servo library to connect to the servo through PWM outputs and write angles directly to the servo using Servo.write(angle) function.
         Socket, this section uses TCP(Transmission Control protocol) to make a socket at 3333 port through which it gets data in String format.
         Decoder, this code slices the String into tokens and converts to int and stores them in final_angles[] array of size 3. 
         II) The python code uses the socket library and sends data through port 3333 and reads and decodes the reply. 

WORKING: The python script sends data through socket, ESP32 decodes the data and controls the servo angles from the data with the help of
         ESP32 Servo library and PWM outputs.
         
