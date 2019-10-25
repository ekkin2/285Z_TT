#include "285Z-Main/initRobot.hpp"
#include "285Z-Library/waypoints.hpp"
/*
const bool fwd {false};
const bool bwd {true};
//true means backwards, false means forwards

/*
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
/*
void testAut() {
  //Only generates path, then setTarget makes it move
  profile.generatePath({initRed, redBall}, "Ball"); //gets ball
  profile.setTarget("Ball", fwd);
  profile.waitUntilSettled();

  profile.setTarget("Ball", bwd);
  profile.waitUntilSettled();
  profile.removePath("Ball");
  turn(-48_deg,50);
}

void redAut(){

  //NOTE: Robot Length = 11"
  //NOTE: Robot Width = 10"

  //Intake On
  intakeSpeed(400);
  //Move to blocks
  profile.generatePath({startRedTT, redblocksFirstSet}, "Blocks1");
  profile.setTarget("Blocks1", fwd);
  profile.waitUntilSettled();
  //need to work out deceleration program
  //sqiggle backwards to line up with second row
  profile.generatePath({Point{4_ft, 9.9_ft, 0_deg}, Point{1_ft, 5.9_ft, 0_deg}}, "squiggle");
  profile.setTarget("squiggle", bwd);
  profile.waitUntilSettled();
  //intake second batch of blocks
  profile.generatePath({ Point{1_ft, 5.9_ft, 0_deg}, Point{4_ft, 5.9_ft, 0_deg}}, "Blocks2");
  profile.setTarget("Blocks2", fwd);
  profile.waitUntilSettled();
  //turn towards goal
  turn(135_deg, 50);
  //go towards goal
  profile.generatePath({ Point{1_ft, 5.9_ft, -45_deg}, Point{2_ft, 10_ft, -45_deg}}, "GoToStack");
  profile.setTarget("GoToStack", fwd);
  profile.waitUntilSettled();
  //Raise lift upwards
  liftVertAut();
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
    profile.generatePath({startRedTT, redblocksFirstSet}, "Blocks1");
    profile.setTarget("Blocks1", fwd);
    profile.waitUntilSettled();
    //need to work out deceleration program
    //sqiggle backwards to line up with second row
    profile.generatePath({redblocksFirstSet, postSquiggle}, "squiggle");
    profile.setTarget("squiggle", bwd);
    profile.waitUntilSettled();
    //intake second batch of blocks
    profile.generatePath({postSquiggle, pickUpSecondStack}, "Blocks2");
    profile.setTarget("Blocks2", fwd);
    profile.waitUntilSettled();
    //turn towards goal
    turn(135_deg, 50);
    //go towards goal
    profile.generatePath({pickUpSecondStack, maybeGoBack}, "GoToStack");
    profile.setTarget("GoToStack", fwd);
    profile.waitUntilSettled();
    //Raise lift upwards
    liftVertAut();
    //Move backwards slowly
    aut.setMaxVelocity(50);
    aut.moveDistance(-100);
}

void turnTest(){

  turn(135_deg, 50);

}

void liftTest(){

  liftVertAut();

}


void autonomous() {
  liftTest();
}
*/
