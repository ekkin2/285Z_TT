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
void turnTest()
{
  turn(135_deg, 50);

}

void liftTest(){

  liftVert();
  delay(200);
}
void autonomous() {
  redAut();
}
