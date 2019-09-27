#include "285Z-Main/initRobot.hpp"

//File
Controller joystick;

Timer timer;

/*
This is where we initialize the specific buttons
ControllerButton btnShoot												(ControllerDigital::R1);
ControllerButton btnBallIntake									(ControllerDigital::R2);
ControllerButton btnReverseBall       					(ControllerDigital::A);
ControllerButton btnDoubleShot                  (ControllerDigital::X );
ControllerButton btnReverseSystem               (ControllerDigital::Y);

ControllerButton btnHoodToggle                  (ControllerDigital::L2);
ControllerButton btnLUsager                     (ControllerDigital::L1);         //> 'L' refers to the robot's arm which was in the shape of an 'L' in its early days

ControllerButton btnLazyMode										(ControllerDigital::up);
*/
bool driveStyleToggle   {TANK};
bool lazy               {false};

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
