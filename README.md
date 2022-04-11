# ToyRobot
The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

## Build
The source code can be compiled using Visual Studio C++. A VS project solution is available in `ToyRobot/ToyRobot.sln`

## Commands (case and space sensitive)
* PLACE x,y,face  
  &nbsp;&nbsp;Description: Places the toy robot on the table with the given x,y coordinates and face direction  
  &nbsp;&nbsp;Parameters:  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;x : number 0-4  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;y : number 0-4  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;face : [EAST, WEST, NORTH, SOUTH]  
  
* MOVE  
  &nbsp;&nbsp;Description: Moves the toy robot 1 unit to the face direction  
  &nbsp;&nbsp;Note: Toy robot must be placed on the table first before MOVE command can be performed.  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Toy robot will not move outside the table
    
* LEFT  
  &nbsp;&nbsp;Description: Turns the toy robot 90 degrees to the left, changing the face direction
    
* RIGHT  
  &nbsp;&nbsp;Description: Turns the toy robot 90 degrees to the right, changing the face direction
    
* REPORT  
  &nbsp;&nbsp;Description: Prints out the current x,y location of the toy robot on the table and the face direction
  
## Unit Testing
  Sample unit test code is available in `ToyRobot/ToyRobotTest.cpp`
  To run the unit test, pass a `--test` parameter when running `ToyRobot.exe`
