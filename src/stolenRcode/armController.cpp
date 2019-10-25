#include "armController.hpp"

bool armToggle = false;

ArmController::ArmController(int iarm) :
arm(new okapi::Motor(iarm, true, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees)), task(taskFnc, this, "Arm Controller") {
}

void ArmController::setState(armStates state) {armState = state;}

ArmController::armStates ArmController::getState() {return armState;}

void ArmController::disable()
{
  // if(!disabled)
  //   arm->moveVelocity(0);

  disabled = true;
}

void ArmController::enable() {disabled = false;}

void ArmController::run()
{
  arm->setGearing(okapi::AbstractMotor::gearset::red);
  while(true)
  {    
    if(!disabled)
    {
      switch(armState)
      {
        case off:
        arm->moveVoltage(0);
        break;

        case up:
        std::cout << "armState: up" << std::endl;
        arm->moveAbsolute(640, 80);
        pros::delay(1000);
        armState = armStates::off;
        std::cout << "armState: off" << std::endl;
        armToggle = true;
        break;

        case down:
        std::cout << "armState: down" << std::endl;
        arm->moveAbsolute(0, 80);
        pros::delay(1000);
        armState = armStates::off;
        std::cout << "armState: off" << std::endl;
        armToggle = false;
        break;

        case kill:
        arm->moveVelocity(-30);
        pros::delay(1000);
        arm->tarePosition();
        armState = armStates::off;
        break;
      }
    }
    pros::delay(10);
  }
}


void ArmController::taskFnc(void* input)
{
  pros::delay(500);
  ArmController* that = static_cast<ArmController*>(input);
  that->run();
}
