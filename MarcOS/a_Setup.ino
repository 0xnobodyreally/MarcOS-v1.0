

// -- Setup

void setup(void) {

  Serial.begin(9600);
  Serial.println("Serial Monitor started");

  pinMode(13, OUTPUT);

  tft.reset();

  /*  Set Values Manually | uncomment this and run once if you have not used the EEPROM before on your Arduino */
  //  blv = 255;                //  Led Brightness value
  //  esleep  = 7;              //  Set Default Led Sleep Time (10 minutes)


  /*  Read Values stored on EEPROM  */
  blv = EEPROM.read(1);                       //  LED Brightness
  esleep = EEPROM.read(2);                    //  LED Timer
  LoadLedTimer();

  delay(150);
  //  Serial.print("EEPROM read 1: ");        //  uncomment these to show the EEPROM saved values in the serial monitor
  //  Serial.println(EEPROM.read(1));
  //  Serial.print("EEPROM read 2: ");
  //  Serial.println(EEPROM.read(2));

  /*  Reset the TFT Display  */
  tft.begin(0x9341);                          // The address of your Display
  tft.setRotation(LCDROTATION);               // Need for the Mega, please changed for your choice or rotation initial
  tft.fillScreen(BLACK);

  StartupScreen();                            //  Display Startup Screen
  delay(1500);

  ClearPage();
  HomeScreen();                               //  Pre-Load the Home Screen

  Serial.println("Starting Loop");
}

