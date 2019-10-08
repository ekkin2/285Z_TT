#include "285Z-Main/initRobot.hpp"

//File
Controller joystick;

Timer timer;

//This is where we initialize the specific buttons
ControllerButton btnVert(ControllerDigital::L1); //Make stack vertical
ControllerButton btnAngle(ControllerDigital::L2); //Make stack angled
ControllerButton btnIntake(ControllerDigital::R2); //Start Intake

ControllerButton btnLazyMode(ControllerDigital::up);

//BOOLEANS FOR TOGGLE
bool driveStyleToggle   {TANK};
bool intakeToggleBool   {false};
bool liftUp             {false};
bool lazy               {false};

void liftVert() {
  //-1690 degrees
  //TODO: Change angler1 to angler when there are two motors
  joystick.setText(0, 0, std::to_string(angler1.getPosition()));
  if (btnAngle.changedToPressed())
  {
    liftUp = true;
  }
  else if (liftUp)
  {
    angler1.moveAbsolute(-1690, 100);
  }
}

void lowerFlat(){

}


void intakeToggle ()
{
    if (btnIntake.changedToPressed())
    {
      intakeToggleBool = !intakeToggleBool;
    }
    else if(intakeToggleBool)
    {
      intake.moveVelocity   (600);
    }
    else
    {
      intake.moveVelocity	(0);
    }
}

void lazyMode ()
{
  drive.stop();

  driveL.tarePosition();
  driveR.tarePosition();

  driveL.setBrakeMode(AbstractMotor::brakeMode::hold);
  driveR.setBrakeMode(AbstractMotor::brakeMode::hold);

  pros::Task::delay(500);

  driveL.moveAbsolute(0, 200);
  driveR.moveAbsolute(0, 200);

  joystick.setText(0, 0, "Active Brake: On");
}

void doArcade ()
{
  if (!lazy)
  {
    driveL.setBrakeMode(AbstractMotor::brakeMode::brake);
    driveR.setBrakeMode(AbstractMotor::brakeMode::brake);
    drive.arcade
    (
      joystick.getAnalog(ControllerAnalog::leftY),
      joystick.getAnalog(ControllerAnalog::rightX)
    );
  }
  else
    lazyMode();
}

void doTank ()
{
  if (!lazy)
  {
    driveL.setBrakeMode(AbstractMotor::brakeMode::hold);
    driveR.setBrakeMode(AbstractMotor::brakeMode::hold);
    drive.tank
    (
      joystick.getAnalog(ControllerAnalog::leftY),
      joystick.getAnalog(ControllerAnalog::rightY)
    );
  }
  else
    lazyMode();
}

void driveStyle (int style)
{
  if(style == ARCADE){
    doArcade();
  } else if (style == TANK){
    doTank();
  } else {
    doTank();
  }
}
