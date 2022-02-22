 /*
 
if you modified this code and publish it on the internet somewhere, please left these in and put your username as "editor"

original code is written by:
  greentea(youtube https://www.youtube.com/channel/UCTnM3fNV56z9NxU_HqNDCzA)
  gndatabase(twitter https://twitter.com/gndbupdates)
  shervain123(github https://github.com/shervain123)

original code can be found at:
  https://github.com/shervain123/usb-volume-knob

yes i have diffrent username depending on where you search


this code was made using sample code that can be found online
the sample code used are:
  rotary encoder (https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/)
  serial read and write (arduino build-in library sample)
  hid input (hid-project build-in sample)

library used in this code (installation is required using library manager in arduino ide):
  HID-Project (https://github.com/NicoHood/HID)


if you want to flip the direction of the rotary encoder, just change the outputA and outputB
 */
 
 #define outputA A1
 #define outputB A2
 #define inputA A0
 #define r A3
 #include <HID-Project.h>
 int aState;
 int ass = 0;
 int aLastState;  
 int mode = 48;
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (inputA,INPUT_PULLUP);
   pinMode(r,OUTPUT);
   Serial.begin (115200);
   Consumer.begin();
   Mouse.begin();
   Keyboard.begin();
   aLastState = digitalRead(outputA);   
 } 

 void loop() { 
    //Volume
  if(mode == 48){
    digitalWrite(r,HIGH);
   aState = digitalRead(outputA);
   if(aState != aLastState){     
     if(digitalRead(outputB) != aState){
      Consumer.write(MEDIA_VOL_UP);
      } else {
        Consumer.write(MEDIA_VOL_DOWN);
        }
   } 
   if(digitalRead(inputA) == LOW){
    mode = 49;
    delay(500);  
   }
   aLastState = aState;
  }else
  
  //zoom
  if(mode == 49){
    digitalWrite(r, LOW);
   aState = digitalRead(outputA);
   if(aState != aLastState){     
     if(digitalRead(outputB) != aState){
       Keyboard.press(KEY_LEFT_CTRL);
       Mouse.move(0,0,1);
       delay(100);
       Keyboard.releaseAll();
      } else {
       Keyboard.press(KEY_LEFT_CTRL);
       Mouse.move(0,0,-1);
       delay(100);
       Keyboard.releaseAll();
        }
   } 
   if(digitalRead(inputA) == LOW){
    mode = 50;
    delay(500);
   }
   aLastState = aState;
  }else
  
  //scroll
  if(mode == 50){
    digitalWrite(r, LOW);
   aState = digitalRead(outputA);
   if(aState != aLastState){     
     if(digitalRead(outputB) != aState){
      Mouse.move(0,0,-1);
      } else {
      Mouse.move(0,0,1);
        }
   } 
   if(digitalRead(inputA) == LOW){
      mode = 48;
      delay(500);
   }
   aLastState = aState;
  }else
  //left scroll
  if(mode == 51){
    digitalWrite(r, LOW);
   aState = digitalRead(outputA);
   if(aState != aLastState){     
     if(digitalRead(outputB) != aState){
       Keyboard.press(KEY_LEFT_SHIFT);
       Mouse.move(0,0,-1);
       delay(100);
       Keyboard.releaseAll();
      } else {
       Keyboard.press(KEY_LEFT_SHIFT);
       Mouse.move(0,0,1);
       delay(100);
       Keyboard.releaseAll();
        }
   } 
   if(digitalRead(inputA) == LOW){
      mode = 52;
      delay(500);
   }
   aLastState = aState;
  }else
    //arrow
  if(mode == 52){
    digitalWrite(r, LOW);
   aState = digitalRead(outputA);
   if(aState != aLastState){     
     if(digitalRead(outputB) != aState){
       Keyboard.write(KEY_RIGHT_ARROW);
      } else {
       Keyboard.write(KEY_LEFT_ARROW);
        }
   } 
   if(digitalRead(inputA) == LOW){
      mode = 53;
      delay(500);
   }
   aLastState = aState;
  }else 
  //page up down
  if(mode == 53){
    digitalWrite(r, LOW);
   aState = digitalRead(outputA);
   if(aState != aLastState){     
     if(digitalRead(outputB) != aState){
       Keyboard.write(KEY_PAGE_UP);
      } else {
       Keyboard.write(KEY_PAGE_DOWN);
        }
   } 
   if(digitalRead(inputA) == LOW){
      mode = 48;
      delay(500);
   }
   aLastState = aState;
  }else 
  //Serial
  if(mode == 54){
    digitalWrite(r, LOW);
   aState = digitalRead(outputA);
   if(aState != aLastState){     
     if(digitalRead(outputB) != aState){
       Serial.print("8");
      } else {
       Serial.print("9");
        }
   } 
   if(digitalRead(inputA) == LOW){
      mode = 48;
      delay(500);
   }
   aLastState = aState;
  }
    if (Serial.available() > 0) {
    mode = Serial.read(),DEC;
    }
  
 }
 
 
