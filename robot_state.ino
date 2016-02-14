#include "robot_state.h"
int _time = 0;

RobotState currentState() {
  return Driving;
}

RobotState lastState() {
  return Turning;
}

double leftMotorSpeed() {
  return 3;
}

double rightMotorSpeed() {
  return 3;
}

int currentStateTime() {
  return currentTime();
}

int currentTime() {
  return _time;
}

void tick(int milliseconds) {
  _time += milliseconds;
  delay(milliseconds);
}
