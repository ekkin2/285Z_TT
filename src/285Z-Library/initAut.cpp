#include "285R-Main/initRobot.hpp"

ChassisControllerIntegrated aut = ChassisControllerFactory::create
(
  {1, 2},
  {-3, -4},
  AbstractMotor::gearset::green,
  {4.125_in, 9.625_in}
);

AsyncMotionProfileController profile = AsyncControllerFactory::motionProfile
(
   1.25,
   2.0,
   5.0,
   aut
);

void turn (QAngle degrees, float rpm)
{
  aut.setMaxVelocity(rpm);

  aut.turnAngle(degrees);

  aut.setMaxVelocity(200);
}
