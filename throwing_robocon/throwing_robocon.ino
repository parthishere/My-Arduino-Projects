#include "cytron_robocon.h"
#include "encoder_robocon.h"

void setup() {

  cytron(1, 0, 0);
  cytron(2, 0, 0);
  cytron(3, 0, 0);
  cytron(4, 0, 0);
  
}

void loop() {
  delay(1000);
  cytron(1, 50, 0);
  cytron(2, 50, 0);
  cytron(3, 50, 0);
  cytron(4, 50, 0);
}
