/* YourDuino.com Example Software Sketch
   Small Stepper Motor and Driver V1.5 06/21/17
   http://www.yourduino.com/sunshop/index.php?l=product_detail&p=126
   Shows 4-step sequence, Then 1/2 turn and back different speeds
   terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <Stepper.h>

/*-----( Declare Constants, Pin Numbers )-----*/
//---( Number of steps per revolution of INTERNAL motor in 4-step mode )---
#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  

/*-----( Declare objects )-----*/
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to

//The pin connections need to be pins 8,9,10,11 connected
// to Motor Driver In1, In2, In3, In4 

// Then the pins are entered here in the sequence 1-3-2-4 for proper sequencing
Stepper horiz_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);
Stepper vert_stepper(STEPS_PER_MOTOR_REVOLUTION, 4, 5, 6, 7);


/*-----( Declare Variables )-----*/
int  hSteps;
int  vSteps;

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
// Nothing  (Stepper Library sets pins as outputs)
  hSteps  = STEPS_PER_OUTPUT_REVOLUTION *2 ;  // Rotate CCW 1/2 turn  
  vSteps  = STEPS_PER_OUTPUT_REVOLUTION *2;  // Rotate CCW 1/2 turn  
  horiz_stepper.setSpeed(500);  // 700 a good max speed??
  vert_stepper.setSpeed(500);  // 700 a good max speed??
  Serial.begin(9600); 

}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  
  horiz_stepper.step(hSteps);
  delay(100);
  Serial.print(hSteps);
  hSteps *= -0.9;
  
  Serial.print("\t");
  
  vert_stepper.step(vSteps);
  delay(100);
  Serial.println(vSteps);
  vSteps *= -0.9;

}/* --(end main loop )-- */

/* ( THE END ) */

