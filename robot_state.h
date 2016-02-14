#ifndef _ROBOT_STATE_H
#define _ROBOT_STATE_H

enum RobotState {
  Driving,
  Turning,
  ArmMotion,
  SensorScan,
};

RobotState currentState();
RobotState lastState();
double leftMotorSpeed();
double rightMotorSpeed();
int currentStateTime();
int currentTime();
void tick(int milliseconds);

#endif
