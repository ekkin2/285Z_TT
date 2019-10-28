

void opcontrol(){

  model->tank(controller.getAnalog(okapi::ControllerAnalog::rightY),
              controller.getAnalog(okapi::ControllerAnalog::leftY));

if(intakeToggleButton.changedToPressed()){
}
}
