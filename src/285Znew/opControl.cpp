void opcontrol(){
    drive->arcade(controller.getAnalog(ControllerAnalog::leftY),
                  controller.getAnalog(ControllerAnalog::rightY));    
}
