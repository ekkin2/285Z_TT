#include "285Z-Main/initRobot.hpp"

ChassisControllerIntegrated aut = ChassisControllerFactory::create
(
  {11, 12},
  {-13, -14},
  AbstractMotor::gearset::green,
  {4_in, 10_in}
);

AsyncMotionProfileController profile = AsyncControllerFactory::motionProfile
(
   1.25,
   2.0,
   5.0,
   aut
);

//TODO: WILL HAVE TO MODIFY WHEN WE HAVE TWO MOTORS FOR ANGLER
const int AnglerMotor = 18;


//intake function for autonomous
//intakeSpeed(integer speed value)
void intakeSpeed(int x) {
  intake.moveVelocity(x*-1);
  if(x == 0){
    intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
};

void anglerSpeed(int x) {
  intake.moveVelocity(x*-1);
  if(x == 0){
    intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
};
//lift function
void liftVert(){
  angler.moveVelocity(100);
};

void turn (QAngle degrees, float rpm)
{
  aut.setMaxVelocity(rpm);

  aut.turnAngle(degrees);

  aut.setMaxVelocity(200);
};
