#include "285Z-Main/initRobot.hpp"
//new code

//motors for the drivetrain
//could be incorrect
Motor frontLeft(11);
Motor backLeft(12);
Motor frontRight(-13);
Motor backRight(-14);

//motors for the intake. (looking from the front)
Motor intakeRight(16);
Motor intakeLeft(19);

//solo angler motor
Motor anglerCenter(20);

okapi::ChassisScales scales{4_in, 11.5_in};

std::shared_ptr<okapi::OdomChassisController> chassis = okapi::ChassisControllerBuilder()
      .withMotors({ 11, 12 }, { -13, 14 })
      .withGearset(okapi::AbstractMotor::gearset::green)
      .withDimensions(scales)
      .withOdometry(okapi::StateMode::FRAME_TRANSFORMATION, 0_mm, 0_deg, 0.0001_mps)
      .buildOdometry();
std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());
auto driveTrain = ChassisControllerFactory::create(
  -11, 1,
  AbstractMotor::gearset::green,
  {4_in, 10_in}
);

//old code

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
