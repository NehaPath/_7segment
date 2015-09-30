int val = 0;
int buttonPin = 13;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;
int LED = 12;
int BUTTON = 11;
int TONE =10; 
int ButtonCurrentState=0; 
int LastButtonState=0; 
int ButtonCounter=0; 

uint8_t segments[] = {
  2, //a
  3, //f
  4, //e
  5,  //d
  6,  //c
  7,  //g
  8   //b
};

uint8_t numbers[10][7] = {
  {0, 0, 0, 0, 0, 1, 0}, //0
  {1, 1, 1, 1, 0, 1, 0}, //1
  {0, 1, 0, 0, 1, 0, 0}, //2 //only here
  {0, 1, 1, 0, 0, 0, 0}, //3
  {1, 0, 1, 1, 0, 0, 0}, //4
  {0, 0, 1, 0, 0, 0, 1}, //5
  {0, 0, 0, 0, 0, 0, 1}, //6
  {0, 1, 1, 1, 0, 1, 0}, //7
  {0, 0, 0, 0, 0, 0, 0}, //8
  {0, 0, 1, 0, 0, 0, 0}, //9
};

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
  Serial.begin(9600);

  for(int i = 0; i < 9; i++) {
    pinMode(segments[i], OUTPUT);
  }

}

void loop() {

ButtonCurrentState= digitalRead(BUTTON); // state of button 

if (ButtonCurrentState != LastButtonState){
  if (ButtonCurrentState == HIGH){
    ButtonCounter++; 
    Serial.println("on"); 
    Serial.print("number of button pushes: ") ;
    sendCharacter(numbers[ButtonCounter%10]);
    //if(ButtonCounter%9>0){
    Serial.println(ButtonCounter); 
   // }
    if (ButtonCounter %2 ==0) 
      tone(TONE, 440, 100); 
    } else {
      Serial.print("off"); 
      }
      delay(50); 
  }

  LastButtonState=ButtonCurrentState; 

  if (ButtonCounter %2 ==0){
    digitalWrite(LED, HIGH); 
    } else {
      digitalWrite(LED, LOW); 
      }

      
//for(int i = 9; i >= 0; i--) {
//    sendCharacter(numbers[i]);
//    delay(100);  
//  }


//buttonState = digitalRead(buttonPin);
//
//if (buttonState != lastButtonState) {
//  if (buttonState == HIGH) {
//    Serial.println("pressed");
// 
//  }
//  else {
//    Serial.println("released");
//    
//  }
//  delay(50);
//  }
//
//  lastButtonState = buttonState;

}

void sendCharacter(uint8_t character[6]) {
  for(int i = 0; i < 9; i++) {
    digitalWrite(segments[i], character[i]);
  }

}





