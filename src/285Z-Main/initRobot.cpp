#include "285Z-Main/initRobot.hpp"
//new code
Motor frontLeft = 11;
Motor backLeft = 12;
Motor frontRight = 13;
Motor backRight = 14;

Motor intakeRight = 19;


//old code
Motor fl           (11, true,  AbstractMotor::gearset::green);
Motor bl           (12, true,  AbstractMotor::gearset::green);
Motor fr           (13, true,  AbstractMotor::gearset::green);
Motor br           (14, true,  AbstractMotor::gearset::green);

Motor intakeL  (19, true,  AbstractMotor::gearset::green);
Motor intakeR (16, false, AbstractMotor::gearset::green);

Motor angler1 (20, true, AbstractMotor::gearset::red);
Motor angler2 (15, true, AbstractMotor::gearset::red);


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
MotorGroup angler = MotorGroup({-20, 15});
// auto scrapePID = AsyncControllerFactory::posPID
// (
//   9, scraper,
//   0.001, //kP
//   0.0,   //kI
//   0.0001 //kD
// );
