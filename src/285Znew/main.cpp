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
okapi::ChassisScales scales
{
	{4.125_in, 11.5_in},
	imev5GreenTPR
};


std::shared_ptr<okapi::OdomChassisController> chassis = okapi::ChassisControllerBuilder()
      .withMotors({ frontLeft, backLeft }, { frontRight, backRight })
      .withGearset(okapi::AbstractMotor::gearset::green)
      .withDimensions(scales)
      .withOdometry(okapi::StateMode::FRAME_TRANSFORMATION, 0_mm, 0_deg, 0.0001_mps)
      .buildOdometry();
std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());