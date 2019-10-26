#include "285Z-Main/initRobot.hpp"
#include "285Z-Library/waypoints.hpp"

const bool fwd {false};
const bool bwd {true};

const bool slow {false};
const bool fast {true};
//true means backwards, false means forwards

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void redSimple(){
  intakeSpeed(400);
  //Move to blocks
  //mpMove(reblocksFirstSet, redblocksBack, fwd, "Blocks1")
  profile.generatePath({startRedTT, redblocksFirstSet}, "Blocks1");
  profile.setTarget("Blocks1", fwd);
  profile.waitUntilSettled();
  profile.removePath("Blocks1");
  intakeSpeed(0);
  //back up


  //aut.moveDistance(-300);
  //mpMove(redblocksBack, redStack, fwd, "ToStack")
  profile.generatePath({redblocksFirstSet, redblocksBack}, "Back");
  profile.setTarget("Back", bwd);
  profile.waitUntilSettled();

  intakeSpeed(-5);
  //need to work out deceleration program
  //sqiggle backwards to line up with second row
  pros::Task::delay(200);

  //turn(270_deg, 100);
  /*profile.generatePath({redblocksFirstSet, redblocksBack}, "Back");
  profile.setTarget("Back", bwd);
  profile.waitUntilSettled();*/

  aut.setMaxVelocity(150);
  aut.moveDistance(500);

  liftVertAut();
  pros::Task::delay(200);
  //Move backwards slowly
  aut.setMaxVelocity(50);
  aut.moveDistance(-100);
}

void blueSimple(){
  intakeSpeed(200);
  aut.moveDistance(1000);
  mpMove(startBlueTT, blueblocksFirstSet, fwd, slow, "Blocks1");
  mpMove(blueblocksFirstSet, blueblocksBack, bwd, fast, "MoveBack");
  pros::Task::delay(1000);
  intakeSpeed(0);


  turn(120_deg, 80);

  driveL.moveRelative(300, 60);
  driveR.moveRelative(300, 60);
  //aut.moveDistance(700);
  intakeSpeed(-5);
  angler.moveRelative(1690, 60);

  //liftVertAut();

  intakeSpeed(0);
  pros::Task::delay(1000);
  aut.setMaxVelocity(50);
  aut.moveDistance(-2_ft);
}

void turnTest(){
  //regular turn
  turn(90_deg, 60);

  //turn with motion profiling
  profile.generatePath({redblocksBack, redStack}, "Blocks1");
  profile.setTarget("Blocks1", fwd);
  profile.waitUntilSettled();
  profile.removePath("Blocks1");
}

void mpMoveTest(){
  mpMove(redblocksFirstSet, redblocksBack, fwd, slow, "Blocks1");
}

void redAut(){

  //NOTE: Robot Length = 11"
  //NOTE: Robot Width = 10"

  //Intake On
  intakeSpeed(400);
  aut.setMaxVelocity(150);
  //Move to blocks
  profile.generatePath({startRedTT, Point{5_ft, 9.9_ft, 0_deg}}, "Blocks1");
  profile.setTarget("Blocks1", fwd);
  profile.waitUntilSettled();

  //need to work out deceleration program
  //sqiggle backwards to line up with second row
  turn(30_deg, 60);
  aut.moveDistance(-1300);
  //turn(-15_deg, 60);
  /*
  profile.generatePath({Point{4.5_ft, 9.9_ft, 0_deg}, Point{1.5_ft, 4_ft, 0_deg}}, "squiggle");
  profile.setTarget("squiggle", bwd);
  profile.waitUntilSettled();
  */
  //intake second batch of blocks
  profile.generatePath({ Point{1.5_ft, 4_ft, 0_deg}, Point{4_ft, 4_ft, 0_deg}}, "Blocks2");
  profile.setTarget("Blocks2", fwd);
  profile.waitUntilSettled();
  //turn towards goal
  turn(135_deg, 50);
  //go towards goal
  profile.generatePath({ Point{4_ft, 4_ft, -45_deg}, Point{2_ft, 10_ft, -45_deg}}, "GoToStack");
  profile.setTarget("GoToStack", fwd);
  profile.waitUntilSettled();
  //Raise lift upwards
  liftVert();
  //Move backwards slowly
  aut.setMaxVelocity(50);
  aut.moveDistance(-100);

}

void blueAut(){

    //NOTE: Robot Length = 11"
    //NOTE: Robot Width = 10"

    //Intake On
    intakeSpeed(400);
    //Move to blocks
    profile.generatePath({startBlueTT, Point{8_ft, 9.9_ft, 180_deg}}, "Blocks1");
    profile.setTarget("Blocks1", fwd);
    profile.waitUntilSettled();
    //need to work out deceleration program
    //sqiggle backwards to line up with second row
    profile.generatePath({Point{8_ft, 9.9_ft, 180_deg}, Point{1_ft, 5.9_ft, 180_deg}}, "squiggle");
    profile.setTarget("squiggle", bwd);
    profile.waitUntilSettled();
    //intake second batch of blocks
    profile.generatePath({ Point{1_ft, 5.9_ft, 180_deg}, Point{8_ft, 5.9_ft, 180_deg}}, "Blocks2");
    profile.setTarget("Blocks2", fwd);
    profile.waitUntilSettled();
    //turn towards goal
    turn(-135_deg, 50);
    //go towards goal
    profile.generatePath({ Point{8_ft, 5.9_ft, -45_deg}, Point{10_ft, 10_ft, -45_deg}}, "GoToStack");
    profile.setTarget("GoToStack", fwd);
    profile.waitUntilSettled();
    //Raise lift upwards
    liftVertAut();
    //Move backwards slowly
    aut.setMaxVelocity(50);
    aut.moveDistance(-100);
}


void liftTest(){

  liftVertAut();

}


void autonomous() {
  pros::Task::delay(100);
  hughShelbySimple();
  //driveL.moveRelative(-250, -100);
  //driveR.moveRelative(-250, -100);
}
void hughShelbySimple(){
  intakeSpeed(400);
  angler1.moveVelocity(200);
  angler2.moveVelocity(200);
  pros::delay(200);
  angler1.setBrakeMode(AbstractMotor::brakeMode::hold);
  angler2.setBrakeMode(AbstractMotor::brakeMode::hold);
  angler1.moveVelocity(0);
  angler2.moveVelocity(0);
}
