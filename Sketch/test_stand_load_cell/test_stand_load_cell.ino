/*
 Test Stand Load Measurement Code
*/

// include the library code:
#include "Wire.h"
#include "LiquidCrystal.h"

// Connect via i2c, default address #0 (A0-A2 not jumpered)
LiquidCrystal lcd(0);

// Load Cell
float fs_voltage = 0.0 ;

void setup() {
  long time =0;
  int interval = 500; // Take a reading every 500ms
  
  /* Load Cell Calibaration
  TBD
  */
  // Equation from Datasheet for reading
  float excitation_voltage = 5; // V
  float fs_output_span = 20; // mV/V
  float gain = 64; //Amplifier Gain
  fs_voltage = excitation_voltage*fs_output_span*gain;
  
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("LOAD (lbf):");
  lcd.setBacklight(HIGH);
}

void loop() {
  // Read all Load Cellss
  float loadcell_A = analogRead(0);
  float loadcell_B = 0;
  float loadcell_C = 0;
  float loadcell_D = 0;

  // Calculate load based on readings
  float load_A = loadcell_A/fs_voltage*100; // lbf
  float load_B = loadcell_B/fs_voltage*100; // lbf
  float load_C = loadcell_C/fs_voltage*100; // lbf
  float load_D = loadcell_D/fs_voltage*100; // lbf
  float total_load = load_A + load_B + load_C + load_D; // lbf
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(total_load);

}

