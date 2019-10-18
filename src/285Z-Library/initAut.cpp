#include "285Z-Main/initRobot.hpp"
#include "285Z-Library/waypoints.hpp"

ChassisControllerIntegrated aut = ChassisControllerFactory::create
(
  {11, 12},
  {-13, -14},
  AbstractMotor::gearset::green,
  {4.125_in, 11_in}
);

AsyncMotionProfileController profileSlow = AsyncControllerFactory::motionProfile
(
   1.5,
   1.2,
   0.9,
   aut
);

AsyncMotionProfileController profileFast = AsyncControllerFactory::motionProfile
(
   5,
   2,
   1.5,
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
  joystick.setText(0, 0, "Inside function");
  anglerControllerLAut.setTarget(1670);
  anglerControllerRAut.setTarget(1670);
  anglerControllerLAut.waitUntilSettled();
  anglerControllerRAut.waitUntilSettled();
  joystick.setText(0, 0, "Done");
}

void mpMove(Point start, Point end, bool dir, bool speed, std::string name){
  if(!speed){
    profileSlow.generatePath({start, end}, name);
    profileSlow.setTarget(name, dir);
    profileSlow.waitUntilSettled();
    profileSlow.removePath(name);
  } else {
    profileFast.generatePath({start, end}, name);
    profileFast.setTarget(name, dir);
    profileFast.waitUntilSettled();
    profileFast.removePath(name);
  }

}

void turn (QAngle degrees, float rpm)
{
  aut.setMaxVelocity(rpm);

  aut.turnAngle(degrees);

  aut.setMaxVelocity(200);
}
