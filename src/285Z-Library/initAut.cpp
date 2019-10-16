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

//PID Controller
const double liftkP = 0.001;
const double liftkI = 0.0001;
const double liftkD = 0.0001;

//TODO: WILL HAVE TO MODIFY WHEN WE HAVE TWO MOTORS FOR ANGLER

auto anglerControllerLAut = AsyncControllerFactory::posPID(17, liftkP, liftkI, liftkD);
auto anglerControllerRAut = AsyncControllerFactory::posPID(18, liftkP, liftkI, liftkD);

//intake function for autonomous
//intakeSpeed(integer speed value)
void intakeSpeed(int x) {
  intake.moveVelocity(x*-1);
  if(x == 0){
    intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
};

//lift function
void liftVertAut(){
  anglerControllerLAut.setTarget(1690);
  anglerControllerRAut.setTarget(1690);
}

void turn (QAngle degrees, float rpm)
{
  aut.setMaxVelocity(rpm);

  aut.turnAngle(degrees);

  aut.setMaxVelocity(200);
}
