#include "285Z-Main/initRobot.hpp"

Controller joystickController;

okapi::ControllerButton buttonIntakeToggle = okapi::ControllerDigital::R2;
okapi::ControllerButton buttonTrayToggle = okapi::ControllerDigital::L1;
okapi::ControllerButton buttonOuttakeWP = okapi::ControllerDigital::R1;
okapi::ControllerButton buttonLiftToggle = okapi::ControllerDigital::L2;

drive.tank(masterController.getAnalog(ControllerAnalog::leftY),
           masterController.getAnalog(ControllerAnalog::rightY));











//OLD CODE OlD CODE OLD CODE
    //OLD CODE OlD CODE OLD CODE
//OLD CODE OlD CODE OLD CODE
  //OLD CODE OlD CODE OLD CODE
//OLD CODE OlD CODE OLD CODE

//File
Controller joystick;

Timer timer;

//PID Controller
const double liftkP = 0.001;
const double liftkI = 0.0001;
const double liftkD = 0.0001;

//TODO: WILL HAVE TO MODIFY WHEN WE HAVE TWO MOTORS FOR ANGLER
const int ANGLER_MOTOR_PORT_L = 17;
const int ANGLER_MOTOR_PORT_R = 18;

auto anglerControllerLPID = AsyncControllerFactory::posPID(ANGLER_MOTOR_PORT_L, liftkP, liftkI, liftkD);
auto anglerControllerRPID = AsyncControllerFactory::posPID(ANGLER_MOTOR_PORT_R, liftkP, liftkI, liftkD);

//This is where we initialize the specific buttons
ControllerButton btnVert(ControllerDigital::L2); //Make stack vertical
ControllerButton btnAngle(ControllerDigital::L1); //Make stack angled
ControllerButton btnIntake(ControllerDigital::R2); //Start Intake
ControllerButton btnIntakeRev(ControllerDigital::R1);
ControllerButton btnLazyMode(ControllerDigital::up);

//BOOLEANS FOR TOGGLE
bool driveStyleToggle   {TANK};
bool intakeToggleBool   {false};
bool liftUp             {false};
bool lazy               {false};

void liftVertOp() {
  //-1690 degrees
  //TODO: Change angler1 to angler when there are two motors
  joystick.setText(0, 0, std::to_string(angler1.getPosition()));
  if (btnVert.changedToPressed())
  {
    anglerControllerLPID.setTarget(1690);
    anglerControllerRPID.setTarget(1690);
  }
}

void lowerFlat(){
  //TODO: Change angler1 to angler when there are two motors
  joystick.setText(0, 0, std::to_string(angler1.getPosition()));
  if (btnAngle.changedToPressed())
  {
    anglerControllerLPID.setTarget(0);
    anglerControllerRPID.setTarget(0);
    //angler1.moveAbsolute(0, 100);
  }
}


//  INTAKE FUNCTIONS //
void intakeToggle ()
{
    if (btnIntake.changedToPressed())
    {
      intakeToggleBool = !intakeToggleBool;
    }
    else if(intakeToggleBool)
    {
      intake.moveVelocity   (-600);
    }
    else
    {
      intake.moveVelocity	(0);
      intake.setBrakeMode(AbstractMotor::brakeMode::hold);
    }
}

void intakeRev()
{
  if (btnIntakeRev.isPressed())
  {
    intake.moveVelocity (100);
  }
}



//  DRIVE FUNCTIONS //
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
