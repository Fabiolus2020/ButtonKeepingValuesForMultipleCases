

const int buttonPin  = 7;     // the pin that the pushbutton is attached to


int buttonState      = 0;     // current state of the button
int lastButtonState  = 0;     // previous state of the button
int modeState         = 0;     // remember current led state
int stateNum;
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // initialize the button pin as a input

}

void loop() {
  // read the pushbutton input pin
  buttonState = digitalRead(buttonPin);

  // check if the button is pressed or released
  // by comparing the buttonState to its previous state
  if (buttonState != lastButtonState) {

    // change the state of the led when someone pressed the button
    if (buttonState == 1) {
      stateNum++;
      if (stateNum > 3) stateNum = 1;


    }

    // remember the current state of the button
    lastButtonState = buttonState;
  }


  Serial.println(stateNum);
  // adding a small delay prevents reading the buttonState to fast
  // ( debouncing )
  delay(20);
}
