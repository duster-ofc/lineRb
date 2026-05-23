void lineMove(int pwr, float kp) {
  int error = leftSens.mapRead() - rightSens.mapRead();
  int Psost = error * kp;
  bot.move(1.05 * pwr - Psost, pwr + Psost); 
}

void lineMove(int pwr, float kp, int prd) {
  long currentMillis = millis();
  while (millis() - currentMillis < prd) lineMove(pwr, kp);
}

void driveToCross(int pwr, float kp) {
  while (leftSens.mapRead() < 55 or rightSens.mapRead() < 55) lineMove(pwr, kp);
}

void driveToCrossReverse(int pwr, float kp) {
  while (leftSens.mapRead() > 55 or rightSens.mapRead() > 55) lineMove(pwr, kp);
}

void pMove(int error, int pwr, float kp){
  int Psost = error * kp;
  bot.move(pwr - Psost, pwr + Psost);
}

void turnLeft(int pwr, float kp, int prd){
  long currentMillis = millis();
  while (millis() - currentMillis < prd) pMove(leftSens.mapRead() - 40, pwr, kp);
}

void turnRight(int pwr, float kp, int prd){
  long currentMillis = millis();
  while (millis() - currentMillis < prd) pMove(40 - rightSens.mapRead(), pwr, kp);
}

  // Робот вращается до нахождения банки-коробки
void findTower(int dist) {
  bot.move(60, -60);
  int distance = dist + 10;
  while (distance > dist or distance < 10) {
    distance = ultrasonic.read();
    delay(10);
  }
  bot.stop();
}

void lineMoveToTower(int dist, int pwr, float kp) {
  int distance = dist + 10;
  while (distance > dist) {
    distance = ultrasonic.read(); // или distance = ultrasonic.read() (distance + (ultrasonic.read() - distance) / 2)
    lineMove(pwr, kp, 6);
  }
}

  // Робот двигается к удаленному объекту с вращением (постоянно проверяет расположение коробки-банки)
void moveToTower(int distToStop, int distToFind){
  int distance = distToStop + 10;
  while (distance > distToStop or distance < 10) {
    distance = ultrasonic.read();
    if (distance > distToFind) {
      findTower(distToFind);
    }
    else bot.move(80, 80);
    delay(10);
  }
}
  // Робот объезжает банку
void aroundTheTower() {
  bot.move(-80, 0, 700);
  bot.move(80, 80, 2000);
  bot.move(80, 0, 2000);
  bot.move(80, 80);
  while(leftSens.mapRead() < 50){};
  bot.stop();
}

