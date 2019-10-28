#include "functions.hpp"

void drive(drive){
  if(driveStyle == tankDrive){
    drive->tank(controller.getAnalog(ControllerAnalog::leftY),
                controller.getAnalog(ControllerAnalog::rightY));
  } else {
    drive->arcade(controller.getAnalog(ControllerAnalog::leftY),
                  controller.getAnalog(ControllerAnalog::rightY));

  }
}
