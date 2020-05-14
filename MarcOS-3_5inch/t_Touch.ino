
/*  Touch Buttons - Define here the touch buttons and their functions  */

void  Touch() {

  TSPoint p = ts.getPoint();

  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  //pinMode(XP, OUTPUT);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  //pinMode(YM, OUTPUT);

  // minimum pressure we consider 'valid' - pressure of 0 means no pressing!
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {

    // scale from 0->1023 to tft.width
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);

    /*  Display Touch coordinates and pressure to the Serial console  */
    Serial.print("p.x = ");
    Serial.print(p.x);
    Serial.print("  |  p.y = ");
    Serial.print(p.y);
    Serial.print("  |  Pressure = ");
    Serial.println(p.z);

  /*  -------------------------------------------------------------------------------------------------------  */    
    if  (CurrentPage != "Home") {                           //  if not in home menu display home button
      //  Top-Left corner of the Status Bar  - RIGHT  &  EDGE & TOP  & BOTTOM EDGE
      if (p.y > 310 && p.y < 339 && p.x > 0 && p.x < 60) {
        HomeScreen();   //  Go Back to Home Screen
      }
    }

    //  Button 1  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p.y > 183 && p.y < 328 && p.x > 88 && p.x < 192) {

      /*  These must be defined in reverse order to work */
      if  (CurrentPage == "Menu4") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
        Menu2();
      }
      else if  (CurrentPage == "Home") {
        DashBoard();
      }
    }

    //  Button 2  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    else if (p.y > 22 && p.y < 164 && p.x > 88 && p.x < 192) {

      /*  These must be defined in reverse order for it to work */
      if  (CurrentPage == "Menu4") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
      }
      else if  (CurrentPage == "Home") {
        LedMenu();
      }
    }

    //    Button 3  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p.y > 183 && p.y < 328 && p.x > 227 && p.x < 334) {

      /*  These must be defined in reverse order for it to work */
      if  (CurrentPage == "Menu4") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
      }
      else if  (CurrentPage == "Home") {
        IconMenu();
      }
    }

    //  Button 4  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p.y > 22 && p.y < 164 && p.x > 227 && p.x < 334) {

      /*  These must be defined in reverse order for it to work */
      if  (CurrentPage == "Menu4") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
        HomeScreen();
      }
      else if  (CurrentPage == "Home") {
        Menu1();
      }
    }

    //      Button 5  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p.y > 188 && p.y < 325 && p.x > 368 && p.x < 475) {


      if  (CurrentPage == "Led Options") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
      }
      else if  (CurrentPage == "Home") {
//        LedSettingsMenu();
        Menu2();
      }
    }

    //  Button 6  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE    -  SETTINGS  / CANCEL
    if (p.y > 22 && p.y < 164 && p.x > 368 && p.x < 475) {

      if  (CurrentPage == "Settings") {
        CreditsMenu();
      }
      else if  (CurrentPage == "Home") {
        SettingsMenu();
      }
    }



    /*  LED BRIGHTNESS + - BUTTONS  BEGIN*/

    //  Button "+"  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  Led Brightness UP
    if (p.y > 22 && p.y < 61 && p.x > 101 && p.x < 168) {

      if  (CurrentPage == "Led Options") {
        LedBrightUp();
      }
    }

    //  Button "-"  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  Led Brightness DOWN
    if (p.y > 292 && p.y < 328 && p.x > 101 && p.x < 168) {

      if  (CurrentPage == "Led Options") {
        LedBrightDown();
      }
    }
    /*  LED BRIGHTNESS + - BUTTONS  END */



    /*  LED TIMER + - BUTTONS  BEGIN */

    //  Button "+"  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  Led Timer Increase
    if (p.y > 22 && p.y < 61 && p.x > 205 && p.x < 275) {

      if  (CurrentPage == "Led Options") {
        LedTimerUp();
      }
    }

    //  Button "-"  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  Led Time Decrease
    if (p.y > 292 && p.y < 328 && p.x > 205 && p.x < 275) {

      if  (CurrentPage == "Led Options") {
        LedTimerDown();
      }
    }
    /*  LED TIMER + - BUTTONS  END */



    /*  BACK & SAVE BUTTONS BEGIN  */

    //  BACK Button - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  BACK TO PREVIOUS PAGE
    if (p.y > 189 && p.y < 260 && p.x > 426 && p.x < 469) {

      if  (CurrentPage == "Home") {
      }
      else if  (CurrentPage == "Led Options") {
        //  Serial.println("Go back to Led Menu");
        LedMenu();
      }

//      else {
//        //      Do Nothing
//      }
    }

    //  SAVE Button - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  SAVE TO EEPROM
    if (p.y > 90 && p.y < 159 && p.x > 426 && p.x < 469) {

      if  (CurrentPage == "Led Options") {
        SaveToEEPROM();
      }
    }

    /*  BACK & SAVE BUTTONS END  */



    /*  ICON VIEW TOUCH SETTINGS  BEGIN*/

    //  Icon 12 - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p.y > 22 && p.y < 85 && p.x > 371 && p.x < 475) {

      if  (CurrentPage == "Led Menu") {
        LedSettingsMenu();
      }
    }

    /*  ICON VIEW TOUCH SETTINGS  END*/



    /*  INFO AREA BEGIN*/

    //  Info area - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE   -   show info menu
    if (p.y > 0 && p.y < 40 && p.x > 5 && p.x < 60) {

//      if  (CurrentPage == "Led Menu") {
      if  (MenuInfo == 0) {
        //  Serial.println("There's no menu for this page");        
      }
      if  (MenuInfo == 1) {
        InfoPage();
      }
    }

    /*  INFO AREA  END*/
    
  }

}

