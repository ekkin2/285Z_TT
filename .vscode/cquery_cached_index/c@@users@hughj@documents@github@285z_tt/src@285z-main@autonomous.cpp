#include "285Z-Main/initRobot.hpp"
#include "285Z-Library/waypoints.hpp"

const bool fwd {false};
const bool bwd {true};


void liftTest(){
  liftVertical();
}

void testAut(){
  
}
void autonomous() {
  liftTest();
}
