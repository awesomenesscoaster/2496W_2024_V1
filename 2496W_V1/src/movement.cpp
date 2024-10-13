#include "movement.h"
#include "display/lv_misc/lv_task.h"
#include "main.h"
#include "robot.h"
#include <cmath>
#include <math.h>
#include <vector>

// ------------ Chassis movement functions (PID, arcs, etc....) ------------ //

pidConstants t_consts;
int error = 0;
int prevError = 0;
int integral = 0;
int derivative = 0;
float power = 0;

void setConstants(pidConstants constants) { t_consts = constants; }

float calc(float target, float input, float integralKI, int maxI) {
  prevError = error;
  error = target - input;

  if (std::abs(error) < integralKI) {
    integral += error;
  } else {
    integral = 0;
  }

  if (integral >= 0) {
    integral = std::min(integral, maxI);
  } else {
    integral = std::max(integral, -maxI);
  }

  derivative = error - prevError;

  power = t_consts.p * error + t_consts.i * integral + t_consts.d * derivative;

  return power;
}

void driver_move(float lPwr, float rPwr) {
  left = lPwr;
  right = rPwr;
}

void spin_left(float lPwr) { left.move(lPwr); }

void spin_right(float rPwr) { right.move(rPwr); }

void set_brake_coast() {
  lf.set_brake_mode(MOTOR_BRAKE_COAST);
  lm.set_brake_mode(MOTOR_BRAKE_COAST);
  lb.set_brake_mode(MOTOR_BRAKE_COAST);
  rf.set_brake_mode(MOTOR_BRAKE_COAST);
  rm.set_brake_mode(MOTOR_BRAKE_COAST);
  rb.set_brake_mode(MOTOR_BRAKE_COAST);
}