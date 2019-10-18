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
const int ANGLER_MOTOR_PORT_L = 17;
const int ANGLER_MOTOR_PORT_R = 18;

auto anglerControllerL = AsyncControllerFactory::posPID(ANGLER_MOTOR_PORT_L, liftkP, liftkI, liftkD);
auto anglerControllerR = AsyncControllerFactory::posPID(ANGLER_MOTOR_PORT_R, liftkP, liftkI, liftkD);

//intake function for autonomous
//intakeSpeed(integer speed value)
void intakeSpeed(int x) {
  intake.moveVelocity(x*-1);
  if(x == 0){
    intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
};

//lift function
void liftVert(){
  anglerControllerL.setTarget(1690);
  anglerControllerR.setTarget(1690);
}

void turn (QAngle degrees, float rpm)
{
  aut.setMaxVelocity(rpm);

  aut.turnAngle(degrees);

  aut.setMaxVelocity(200);
}

void
