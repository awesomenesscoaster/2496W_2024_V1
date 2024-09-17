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

pros::Motor lf(3, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lm(11, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lb(14, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(7, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rm(17, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rb(19, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor_Group left({lf, lm, lb});
pros::Motor_Group right({rf, rm, rb});

pros::Motor first_stage(8, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor intake(10, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor lift(9, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

pros::IMU imu(20);

pros::Rotation rotation(6);

pros::ADIDigitalOut clampP (1, false);
pros::ADIDigitalOut tiltP (2, false);
pros::ADIDigitalOut liftP (3, false);
pros::ADIDigitalOut intakeP (4, true); 

//tank 1
// Piston ClampP(CLAMP); // one piston, 1 solenoid for clamp
// Piston TiltP(TILTP); // two pistons, 1 solenoid for tilt

// //tank 2
// Piston IntakeP(INTAKEP); // tbd (prob 1 piston, 1 solenoid)
// Piston LiftP(LIFTP); 