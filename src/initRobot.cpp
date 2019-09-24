#include "285Z-Main/initRobot.hpp"

Motor fl           (1, false,  AbstractMotor::gearset::green);
Motor bl           (2, false,  AbstractMotor::gearset::green);
Motor fr           (3, true,  AbstractMotor::gearset::green);
Motor br           (4, true,  AbstractMotor::gearset::green);

ChassisControllerIntegrated drive = ChassisControllerFactory::create
(
  {1, 2},
  {-3, -11},
  AbstractMotor::gearset::green,
  {4_in, 9.78_in}
);

MotorGroup driveL = MotorGroup({1, 2});
MotorGroup driveR = MotorGroup({-3, -11});

// auto scrapePID = AsyncControllerFactory::posPID
// (
//   9, scraper,
//   0.001, //kP
//   0.0,   //kI
//   0.0001 //kD
// );
