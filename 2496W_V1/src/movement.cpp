#include "display/lv_misc/lv_task.h"
#include "main.h"
#include "robot.h"
#include <cmath>
#include <math.h>
#include <vector>

// ------------ Chassis movement functions (PID, arcs, etc....) ------------ //

void driver_move(float lPwr, float rPwr){
    left = lPwr;
    right = rPwr;
}