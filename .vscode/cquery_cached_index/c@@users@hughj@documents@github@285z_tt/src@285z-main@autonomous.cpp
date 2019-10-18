#include "285Z-Main/initRobot.hpp"
#include "285Z-Library/waypoints.hpp"

const bool fwd {false};
const bool bwd {true};
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
  intakeSpeed(250);
  mpMove(startBlueTT, blueblocksFirstSet, fwd, "Blocks1");
  //mpMove(blueblocksFirstSet, blueStack, fwd, "ToStack");
  pros::Task::delay(1500);
  mpMove(blueblocksFirstSet, blueblocksBack, bwd, "MoveBack");
  turn(-135_deg, 60);
  //aut.moveDistance(2_ft);
  mpMove(blueblocksBackTurn, blueStack, fwd, "ToStack");
  intakeSpeed(-5);
  liftVertAut();
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
  mpMove(redblocksFirstSet, redblocksBack, fwd, "Blocks1");
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
  liftTest();
}
