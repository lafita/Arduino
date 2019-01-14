/* Sweep All Servos of the MeArm
 *  The valid ranges are specified here
*/

#include <Servo.h>

Servo base;
Servo right;
Servo left;
Servo clamp;

int minbase = 60;
int maxbase = 120;

int minright = 70;
int maxright = 140;

int minleft = 80;
int maxleft = 140;

int minclamp = 130;
int maxclamp = 175;


void setup() {

  base.attach(6);
  right.attach(10);
  left.attach(9);
  clamp.attach(11);

  base.write(minbase);
  right.write(minright);
  clamp.write(minclamp);
}

void loop() {

  // Base turns right
  for (int pos = maxbase; pos >= minbase; pos -= 1) {
    base.write(pos);
    delay(20);
  }
  
  // Left goes down
  for (int pos = maxleft; pos >= minleft; pos -= 1) {
    left.write(pos);
    delay(20);
  }

  // Right goes down
  for (int pos = minright; pos <= maxright; pos += 1) {
    right.write(pos);
    delay(20);
  }

  // Clamp closes
  for (int pos = minclamp; pos <= maxclamp; pos += 1) {
    clamp.write(pos);
    delay(20);
  }

  // Right goes up
  for (int pos = maxright; pos >= minright; pos -= 1) {
    right.write(pos);
    delay(20);
  }

  // Left goes up
  for (int pos = minleft; pos <= maxleft; pos += 1) {
    left.write(pos);
    delay(20);
  }

  // Base turns left
  for (int pos = minbase; pos <= maxbase; pos += 1) {
    base.write(pos);
    delay(20);
  }
  
  // Clamp releases
  for (int pos = maxclamp; pos >= minclamp; pos -= 1) {
    clamp.write(pos);
    delay(20);
  }
  
}

