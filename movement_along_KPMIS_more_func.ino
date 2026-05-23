#include <Ultrasonic.h>
Ultrasonic ultrasonic(6, 7);
#include <KPMIS.h>
KPMIS bot;
#include <analogSensor.h>
analogSensor leftSens(A3, 2, 5);
analogSensor rightSens(A2, 4, 3);
int crossScore = 0;
// new
void setup() {
  setting();
  //driveToCross(120, 1.5);
  for (int countCheck = 0; countCheck < 4; countCheck++) {
    while (ultrasonic.read() > 167) {
      bot.move(-75, 75);
      delay(6);
    }
  }
  movementToYellowTower(30, 100, 1.2);
  while (ultrasonic.read() > 167) {
    bot.move(-75, 75);
    delay(6);
  }
  movementToYellowTower(30, 100, 1.2);
  bot.stop();
}

void loop(){
}