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
  intakeSpeed(0);
  profile.generatePath({redblocksFirstSet, postSquiggle}, "squiggle");
  profile.setTarget("squiggle", bwd);
  profile.waitUntilSettled();


}
//^ included
  /*
  profile.generatePath({Point{1_ft, 7_ft, 45_deg}, Point{2.5_ft, 8.5_ft, 45_deg}}, "Cap Scrape"); //goes forward to cap to scrape
  profile.setTarget("Cap Scrape");
  pros::Task::delay(750);
  profile.waitUntilSettled();
  profile.removePath("Cap Scrape");

  // aut.setMaxVelocity(100);
  profile.generatePath({Point{1_ft, 7_ft, 45_deg}, Point{2.8_ft, 8.8_ft, 45_deg}}, "Left Column");
  profile.setTarget("Left Column", bwd);
  pros::Task::delay(100);
  profile.waitUntilSettled();
//  l.moveAbsolute(0,50); //resets scraper
  profile.removePath("Left Column");
  aut.setMaxVelocity(200);

  turn(-43_deg, 50); //turns to face left column
  turn(-2_deg, 50); //readjusts to go straight
  profile.generatePath({hpRed, Point{1_ft, 10_ft, 0_deg}}, "Left Low Flag");
  profile.setTarget("Left Low Flag");
  profile.waitUntilSettled();

  profile.generatePath({Point{1_ft, 9_ft, 90_deg}, lRed}, "Middle Low Flag P1");
  profile.setTarget("Middle Low Flag P1", bwd);
  profile.waitUntilSettled();
  profile.removePath("Middle Low Flag P1");
  turn(90_deg, 100);

  profile.generatePath({Point{1_ft, 9_ft, 0_deg}, Point{5.2_ft, 11_ft, 90_deg}}, "Middle Low Flag P2");
  profile.setTarget("Middle Low Flag P2");
  profile.waitUntilSettled(); */


void autonomous() {
  redAut();
}
