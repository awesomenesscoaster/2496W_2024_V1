#include "robot.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "piston.h"

// -------- All electronic definitions -------- //

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor lf(0, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lm(0, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lb(0, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(0, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rm(0, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rb(0, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor_Group left({lf, lm, lb});
pros::Motor_Group right({rf, rm, rb});

pros::Motor first_stage(2, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor intake(11, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

pros::IMU imu(0);

//tank 1
// Piston ClampP(CLAMP); // one piston, 1 solenoid for clamp
// Piston TiltP(TILTP); // two pistons, 1 solenoid for tilt

// //tank 2
// Piston IntakeP(INTAKEP); // tbd (prob 1 piston, 1 solenoid)
// Piston LiftP(LIFTP); 