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

pros::Motor lf(8, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lm(7, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lb(17, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(9, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rm(16, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rb(20, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor_Group left({lf, lm, lb});
pros::Motor_Group right({rf, rm, rb});

pros::Motor first_stage(3, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor intake(10, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor lift(11, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

pros::IMU imu(5);
pros::Rotation rotation(6);

pros::ADIDigitalOut clampP (1, false);
pros::ADIDigitalOut tiltP (2, false);
pros::ADIDigitalOut hangP (3, false);
pros::ADIDigitalOut intakeP (4, true); 