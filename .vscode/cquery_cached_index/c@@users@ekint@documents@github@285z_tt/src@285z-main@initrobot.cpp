#include "285Z-Main/initRobot.hpp"

Motor fl           (11, false,  AbstractMotor::gearset::green);
Motor bl           (12, false,  AbstractMotor::gearset::green);
Motor fr           (13, true,  AbstractMotor::gearset::green);
Motor br           (14, true,  AbstractMotor::gearset::green);

Motor intakeL  (19, true,  AbstractMotor::gearset::green);
Motor intakeR (16, false, AbstractMotor::gearset::green);

Motor angler1 (17, true, AbstractMotor::gearset::red);
Motor angler2 (18, false, AbstractMotor::gearset::red);


ChassisControllerIntegrated drive = ChassisControllerFactory::create
(
  {11, 12},
  {-13, -14},
  AbstractMotor::gearset::green,
  {4_in, 10_in}
);

MotorGroup driveL = MotorGroup({11, 12});
MotorGroup driveR = MotorGroup({-13, -14});

MotorGroup intake = MotorGroup({19, -16});
MotorGroup angler = MotorGroup({17, -18});
// auto scrapePID = AsyncControllerFactory::posPID
// (
//   9, scraper,
//   0.001, //kP
//   0.0,   //kI
//   0.0001 //kD
// );
