void setting(){
  bot.initMotors();
  bot.waitButtons();
}
void startAtYellowCube() {
  driveToCross(70, 1.2);
  bot.move(70, 70, 300);
  driveToCross(70, 1.2);
  turnLeft(80, 5.0, 1000);
  driveToCross(70, 1.2);
  bot.stop();
}


// бот съезжает после проезда инверсии
void movementInSmallCircle(){
  turnRight(80, 5.0, 2000);
  turnRight(80, 8.0, 4000);
  driveToCross(135, 2.3);
  bot.move(80, 80, 2000);
  while (leftSens.mapRead() < 50) pMove(rightSens.mapRead() - 40, 90, 3.0);
  bot.stop();
  //bot.move(70, 70, 300);
  //while (rightSens.mapRead() < 50) pMove(leftSens.mapRead() - 40, 90, 3.0);
  //while (crossScore < 2) {
  //  crossScore++;
  //  driveToCross(120, 1.8);
  //  bot.move(120, 120, 500);
  //}
}

