
/*  These are the pages and buttons of the various menus  */

void  StatusBar()  {

  //  Serial.println(CurrentPage);                             //  show current menu

  /*  Black Background  */
  //  tft.fillRect(0, 0, 320, 240, BLACK);                 //  full screen background

  /*  Horizontal, Vertical, Width, Height, Color  */
  tft.fillRect(0, 0, 320, 30, StatusBarColor);             //  Draw Status Bar background
  tft.drawRect(0, 0, 320, 240, StatusBarColor);            //  full screen border

  /*  if not in home menu display home icon  */
  if  (CurrentPage != "Home") {
    /*  TOUCH TO GO HOME AREA  -  HOME ICON  */
    drawHomeIcon();
  }

  /*  If there is an info menu for the current page then draw an "i" at top-right of the Status bar  */
  if  (MenuInfo ==  1)  {
    tft.setTextSize(2);
    tft.setTextColor(TextColor);
    tft.setCursor(300, 5.25);
    tft.println("i");
  }

  /*  -------------------------------------------------------------------------------------------------------  */
  /*  SET TEXT COLOR BASED ON STATUS BAR COLOR  */
  tft.setTextSize(2);
  if  (StatusBarColor != WHITE && StatusBarColor != YELLOW)  { //  if the StatusBarColor is NOT WHITE or YELLOW
    tft.setTextColor(WHITE);                      //  set the text color to WHITE
  }
  else  {
    tft.setTextColor(BLACK);                      //  otherwise display text in BLACK
  }

  /*  -------------------------------------------------------------------------------------------------------  */
  /*  ALIGN STATUS BAR TEXT TO THE CENTER */
  if (CurrentPage == "Home") {
    tft.setCursor(136, 7);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Led Menu") {
    tft.setCursor(100, 7);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Led Options") {
    tft.setCursor(100, 7);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Settings") {
    tft.setCursor(113, 7);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "DashBoard") {
    tft.setTextColor(BLACK);                       //  Horizontal, Vertical position
    tft.setCursor(106, 7);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Icon Menu") {
    tft.setCursor(106, 7);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Menu1") {
    tft.setCursor(133, 7);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Credits") {
    tft.setCursor(126, 7);                       //  Horizontal, Vertical position
  }
  else  {
    tft.setCursor(133, 7);                       //  Horizontal, Vertical position
  }

  tft.print(CurrentPage);

  /*  -------------------------------------------------------------------------------------------------------  */
  /*  Refresh screen based on Page Type  */
  if ((PrevPage == "DashBoard") || (PrevPage == "Credits") || (PrevPage == "Led Options")) {
    ClearPage();                      //  Clear Page
  }
  if ((PrevPage == "Info")) {
    ClearFullPage();
  }
  else {
    ClearButtons();                   //  Clear Buttons
  }
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawHomeMenu()  {           //  main menu for all settings (Leds, Time, etc...) 6 buttons

  tft.setTextSize(1.5);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13, 41, 140, 52, BtnBorderColor);   //
  tft.drawRect(14, 42, 138, 51, BtnBorderColor);
  tft.setCursor(66, 62);
  tft.println("TIME");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166, 41, 140, 52, BtnBorderColor);
  tft.drawRect(167, 42, 138, 51, BtnBorderColor);
  tft.setCursor(203, 62);
  tft.println("LED MENU");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13, 108, 140, 52, BtnBorderColor);
  tft.drawRect(14, 109, 138, 51, BtnBorderColor);
  tft.setCursor(46, 129);
  tft.println("ICON MENU");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166, 108, 140, 52, BtnBorderColor);
  tft.drawRect(167, 109, 138, 51, BtnBorderColor);
  tft.setCursor(214, 129);
  tft.println("MENU 1");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13, 176, 140, 52, BtnBorderColor);
  tft.drawRect(14, 177, 138, 51, BtnBorderColor);
  tft.setCursor(61, 197);
  tft.println("MENU 2");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color - This section is commented out if using Settings button  */
  tft.drawRect(166, 176, 140, 52, BtnBorderColor);
  tft.drawRect(167, 177, 138, 51, BtnBorderColor);
  tft.setCursor(206, 197);
  tft.println("SETTINGS");

}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawDashBoard()  {          //  where Time & Date, Temperature & Humidity are displayed
  /*  DATE  */
  tft.setCursor(110, 45);
  tft.setTextSize(1.5);
  tft.setTextColor(GREY);
  tft.println("18 October 2017");

  /*  TIME  */
  tft.setTextSize(7);
  tft.setTextColor(WHITE);
  tft.setCursor(60, 85);
  tft.print("00");
  tft.setTextColor(GREY);
  tft.print(":");
  tft.setTextColor(WHITE);
  tft.print("00");

  /*  LIGHTS  */
  /*
    tft.setTextSize(1);
    tft.setTextColor(GREY);
    tft.setCursor(106.6, 172.5);
    tft.println("Lights are ");
    tft.setTextColor(SKY);
    tft.setCursor(193.3, 172.5);
    tft.println("blue");
  */

  /*  TEMPERATURE  */
  tft.setTextSize(1);
  tft.setTextColor(GREY);
  tft.setCursor(50, 210);
  tft.print("Temperature: ");
  tft.setTextColor(ORANGE);
  tft.print("22");
  tft.setTextSize(0.3);
  tft.setCursor(140, 207);
  tft.print("o");

  //      tft.print("  ");     //  Separator

  /*  HUMIDITY  */
  tft.setTextSize(1);
  tft.setCursor(180, 210);
  tft.setTextColor(GREY);
  tft.print("Humidity: ");
  tft.setTextColor(SKY);
  tft.print("64");
  tft.print("%");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawCreditsMenu()  {                  /*  About and Credits menu  */

  tft.setCursor(118, 45);
  tft.setTextSize(1.5);
  tft.setTextColor(SKY);
  OSVersion();

  tft.setTextSize(1.5);
  tft.setTextColor(GREY);
  tft.setCursor(130, 78.7);
  tft.println("CREDITS:");

  tft.setTextSize(1);
  tft.setTextColor(SALMON);
  tft.setCursor(46.6, 112.5);
  tft.print("Developed by:  ");
  tft.setTextColor(WHITE);
  tft.print("Marco Santoru");
  tft.setTextColor(SKY);
  tft.setCursor(100, 142.5);
  tft.print("www.marcolino.net");

  tft.setTextColor(SALMON);
  tft.setCursor(46.6, 172.5);
  tft.print("Developed for: ");
  tft.setTextColor(WHITE);
  tft.print("I can fix it!");
  tft.setTextColor(SKY);
  tft.setCursor(92, 202.5);
  tft.print("youtube.com/icanfixit");

}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawIconMenu()  {           //  icon menu (12 buttons)

  //  63.3px wide, 13.3px separator  ( (63.3px*4)+(13.3px*5) = 320px )

  tft.setTextSize(1);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 41.25, 63.3, 52.5, BtnBorderColor);       //  40
  tft.drawRect(14, 42, 62, 51, BtnBorderColor);
  tft.setCursor(20, 48.75);                  //65
  tft.println("1");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(90, 41.25, 63.3, 52.5, BtnBorderColor);
  tft.drawRect(90.6, 42, 62, 51, BtnBorderColor);
  tft.setCursor(96.6, 48.75);
  tft.println("2");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 41.2, 63.3, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 42, 62, 51, BtnBorderColor);
  tft.setCursor(173.3, 48.7);
  tft.println("3");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(243.3, 41.2, 63.3, 52.5, BtnBorderColor);
  tft.drawRect(244, 42, 62, 51, BtnBorderColor);
  tft.setCursor(250, 48.7);
  tft.println("4");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 108.7 , 63.3, 52.5, BtnBorderColor);      //  130
  tft.drawRect(14, 109.5, 62, 51, BtnBorderColor);
  tft.setCursor(20, 116.25);                 //  155
  tft.println("5");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(90, 108.75, 63.3, 52.5, BtnBorderColor);
  tft.drawRect(90, 109.5, 62, 51, BtnBorderColor);
  tft.setCursor(96.6, 116.25);
  tft.println("6");

  /*  Button 7 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 108.75, 63.3, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 109.5, 62, 51, BtnBorderColor);
  tft.setCursor(173.3, 116.25);
  tft.println("7");

  /*  Button 8 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(243.3, 108.75, 63.3, 52.5, BtnBorderColor);
  tft.drawRect(244, 109.5, 62, 51, BtnBorderColor);
  tft.setCursor(250, 116.25);
  tft.println("8");

  /*  Button 9 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 176.25, 63.3, 52.5, BtnBorderColor);      // 220
  tft.drawRect(14, 177, 62, 51, BtnBorderColor);
  tft.setCursor(20, 183.75);       //  235
  tft.println("9");
  //  tft.setCursor(33.3, 210);       // 260
  //  tft.println("OFF");

  /*  Button 10 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(90, 176.25, 63.3, 52.5, BtnBorderColor);     // 220
  tft.drawRect(90.6, 177, 62, 51, BtnBorderColor);
  tft.setCursor(96.6, 183.75);            //  235
  tft.println("10");

  /*  Button 11 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 176.25, 63.3, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 177, 62, 51, BtnBorderColor);
  tft.setCursor(173.3, 183.75);            //  235
  tft.println("11");


  /*  Button 12 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(243.3, 176.25, 63.3, 52.5, BtnBorderColor);
  tft.drawRect(244, 177, 62, 51, BtnBorderColor);
  tft.setCursor(250, 183.75);            //  235
  tft.println("12");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawSettingsMenu()  {

  tft.setTextSize(1);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 41.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 42, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 62.25);
  tft.println("Button 1");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 41.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 42, 138.6, 51, BtnBorderColor);
  tft.setCursor(203.3, 62.25);
  tft.println("Button 2");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 108.75, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 109.5, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 129.75);
  tft.println("Button 3");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 108.75, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 109.5, 138.6, 51, BtnBorderColor);
  tft.setCursor(203.3, 129.75);
  tft.println("Button 4");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 176.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 177, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 197.25);
  tft.println("Button 5");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color - This section is commented out if using Settings button  */
  tft.drawRect(166.6, 176.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 177, 138.6, 51, BtnBorderColor);
  tft.setCursor(210, 197.25);
  tft.println("CREDITS");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawLedMenu()  {                /*  LED colors and options  */

#define LedButtonBorderColor    WHITE

  //  95px wide, 20px separator  ( (95px*4)+(20px*5) = 480px )

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 41.25, 63.3, 52.5, LedButtonBorderColor);       //  40
  tft.drawRect(14, 42, 62, 51, LedButtonBorderColor);
  //  tft.fillRect(14.6, 42.75, 60.6, 49.5, Menu5ButtonColor);    /*  Single color button  */
  tft.fillRect(14.6, 42.75, 30.6, 24.75, RED);                    //  Fill button for
  tft.fillRect(45.3, 42.75, 30, 24.75, GREEN);                 //  Rainbow effect
  tft.fillRect(14.6, 67.5, 30.6, 24.75, BLUE);                 //  with 4 different
  tft.fillRect(45.3, 67.5, 30, 24.75, YELLOW);              //  colors
  tft.setCursor(18.6, 60);                  //65
  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  tft.println("RAINBOW");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(90, 41.25, 63.3, 52.5, LedButtonBorderColor);
  tft.drawRect(90.6, 42, 62, 51, LedButtonBorderColor);
  tft.fillRect(91.3, 42.75, 60.6, 49.5, CYAN);
  tft.setCursor(106.6, 60);
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  tft.println("CYAN");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 41.25, 63.3, 52.5, LedButtonBorderColor);
  tft.drawRect(167.3, 42, 62, 51, LedButtonBorderColor);
  tft.fillRect(168, 42.75, 60.66, 49.5, MAGENTA);
  tft.setCursor(183.3, 60);
  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  tft.println("PINK");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(243.3, 41.25, 63.3, 52.5, LedButtonBorderColor);
  tft.drawRect(244, 42, 62, 51, LedButtonBorderColor);
  tft.fillRect(244.6, 42.75, 60.6, 49.5, GREEN);
  tft.setCursor(256.6, 60);
  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  tft.println("GREEN");


  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 108.75, 63.3, 52.5, LedButtonBorderColor);      //  130
  tft.drawRect(14, 109.5, 62, 51, LedButtonBorderColor);
  tft.fillRect(14.6, 110.25, 60.6, 49.5, RED);
  tft.setCursor(34.6, 127.5);                 //  155
  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  tft.println("RED");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(90, 108.75, 63.3, 52.5, LedButtonBorderColor);
  tft.drawRect(90.6, 109.5, 62, 51, LedButtonBorderColor);
  tft.fillRect(91.3, 110.25, 60.6, 49.5, BLUE);
  tft.setCursor(108, 127.5);
  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  tft.println("BLUE");

  /*  Button 7 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 108.75, 63.3, 52.5, LedButtonBorderColor);
  tft.drawRect(167.3, 109.5, 62, 51, LedButtonBorderColor);
  tft.fillRect(168, 110.25, 60.6, 49.5, YELLOW);
  tft.setCursor(174.6, 127.5);
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  tft.println("YELLOW");

  /*  Button 8 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(243.3, 108.75, 63.3, 52.5, LedButtonBorderColor);
  tft.drawRect(244, 109.5, 62, 51, LedButtonBorderColor);
  tft.fillRect(244.6, 110.25, 60.6, 49.5, WHITE);
  tft.setCursor(256.6, 127.5);
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  tft.println("WHITE");


  /*  Button 9 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 176.25, 63.3, 52.5, LedButtonBorderColor);      // 220
  tft.drawRect(14, 177, 62, 51, LedButtonBorderColor);
  tft.fillRect(14.6, 177.75, 60.6, 49.5, DarkGREY);
  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  tft.setCursor(26.6, 187.5);       //  235
  tft.println("STRIP");
  tft.setCursor(33.3, 206.25);       // 260
  tft.println("OFF");

  /*  Button 10 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(90, 176.25, 63.3, 52.5, LedButtonBorderColor);     // 220
  tft.drawRect(90.6, 177, 62, 51, LedButtonBorderColor);
  tft.fillRect(91.3, 177.75, 60.6, 49.5, DarkGREY);
  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  tft.setCursor(106.6, 187.5);            //  235
  tft.println("BULB");
  tft.setCursor(98, 206.25);
  tft.println("ON/OFF");

  /*  Button 11 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 176.25, 63.3, 52.5, LedButtonBorderColor);
  tft.drawRect(167.3, 177, 62, 51, LedButtonBorderColor);
  tft.fillRect(168, 177.75, 60.6, 49.5, DarkGREY);
  tft.setTextSize(1);
  tft.setCursor(178.6, 187.5);
  tft.println("TIMER");
  tft.setCursor(174.6, 206.25);
  tft.println("ON/OFF");


  /*  Button 12 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(243.3, 176.25, 63.3, 52.5, RED);
  tft.drawRect(244, 177, 62, 51, ORANGE);
  tft.fillRect(244.6, 177.75, 60.6, 49.5, DarkGREY);
  //  tft.setCursor(255.3, 187.5);
  tft.setCursor(248, 196.5);
  tft.setTextColor(YELLOW);
  tft.println("OPTIONS");


}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawLedOptionsMenu() {          /*  LED Options screen  */

  //int  BoxColor = StatusBarColor;

  //  backlight level
  tft.setTextColor(WHITE);
  tft.setTextSize(1.5);
  tft.drawRect(66.6, 45, 186.6, 37.5, MenuColor);         //  draw outer box

  tft.fillRect(13.3, 45, 40, 37.5, RED);            //  draw - button box
  tft.drawRect(13.3, 45, 40, 37.5, WHITE);          //  draw button outer box
  tft.setCursor(28, 54.75);                        //  text position
  tft.print("-");

  tft.fillRect(266.6, 45, 40, 37.5, GREEN);         //  draw + button box
  tft.drawRect(266.6, 45, 40, 37.5, WHITE);         //  draw button outer box
  tft.setCursor(281.3, 54.75);                       //  text position
  tft.print("+");

  tft.setTextSize(0.5);
  tft.setCursor(133.3, 53.25);                       //  text position
  tft.print("LED Brightness");
  tft.drawRect(80, 65, 160, 8, WHITE);        //  draw Led Brightness outer box

  LedBrightnessBar();                           //  draw brightness bar

  /*  ========================================================================================  */
  //  sleep time

  tft.setTextColor(WHITE);
  tft.setTextSize(1.5);
  tft.drawRect(66.6, 97.5, 186.6, 37.5, MenuColor);         //  draw outer box

  tft.fillRect(13.3, 97.5, 40, 37.5, RED);           //  draw - button box
  tft.drawRect(13.3, 97.5, 40, 37.5, WHITE);         //  draw button outer box
  tft.setCursor(28, 107.25);                       //  text position
  tft.print("-");

  tft.fillRect(266.6, 97.5, 40, 37.5, GREEN);        //  draw + button box
  tft.drawRect(266.6, 97.5, 40, 37.5, WHITE);        //  draw button outer box
  tft.setCursor(281.3, 107.25);                      //  text position
  tft.print("+");

  tft.setTextSize(0.5);
  tft.setCursor(140, 105.75);                      //  text position
  tft.print("Sleep Time");

  showTimer();                                  //  show Timer

  /*  uncomment the section below if you want a third adjustable option  */
  /*
    tft.setTextColor(WHITE);
    tft.setTextSize(1.5);
    tft.drawRect(66.6, 150, 186.6, 37.5, MenuColor);        //  draw outer box

    tft.fillRect(13.33, 150, 40, 37.5, RED);           //  draw - button box
    tft.drawRect(13.33, 150, 40, 37.5, WHITE);         //  draw button outer box
    tft.setCursor(28, 159.75);                       //  text position
    tft.print("-");

    tft.fillRect(266.6, 150, 40, 37.5, GREEN);        //  draw + button box
    tft.drawRect(266.6, 150, 40, 37.5, WHITE);        //  draw button outer box
    tft.setCursor(281.3, 159.75);                      //  text position
    tft.print("+");

    tft.setTextSize(0.5);
    tft.setCursor(120, 165);                      //  text position
    tft.print("OPTIONAL - NOT IN USE");
    //*/

  tft.setTextSize(1);
  tft.setTextColor(WHITE);

  /*  BACK  BUTTON  */
  tft.fillRect(80, 202.5, 66.6, 22.5, GREEN);      //  draw BACK button box
  tft.drawRect(80, 202.5, 66.6, 22.5, WHITE);       //  draw button outer box
  tft.setCursor(98, 208.5);                      //  text position
  tft.print("BACK");

  /*  SAVE  BUTTON  */
  tft.fillRect(173.3, 202.5, 66.6, 22.5, SALMON);         //  draw SAVE button box
  tft.drawRect(173.3, 202.5, 66.6, 22.5, WHITE);       //  draw button outer box
  tft.setTextSize(1);
  tft.setCursor(191.3, 208.5);                      //  text position
  tft.print("SAVE");

}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawMenu1()  {                      /*  using MenuColor variable  */

  tft.setTextSize(1);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 41.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 42, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 62.25);
  tft.println("Button 1");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 41.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.33, 42, 138.6, 51, BtnBorderColor);
  tft.setCursor(203.3, 62.25);
  tft.println("Button 2");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 108.75, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 109.5, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 129.75);
  tft.println("Button 3");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 108.75, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 109.5, 138.6, 51, BtnBorderColor);
  tft.setCursor(203.3, 129.75);
  tft.println("Button 4");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 176.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 177, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 197.25);
  tft.println("Button 5");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color - This section is commented out if using Settings button  */
  tft.drawRect(166.6, 176.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 177, 138.6, 51, BtnBorderColor);
  tft.setCursor(203.3, 197.25);
  tft.println("Button 6");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawMenu2()  {                      /*  using MenuColor variable  */

  tft.setTextSize(1);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 41.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 42, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 62.25);
  tft.println("Button 1");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 41.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 42, 138.6, 51, BtnBorderColor);
  tft.setCursor(203.3, 62.25);
  tft.println("Button 2");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 108.75, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 109.5, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 129.75);
  tft.println("Button 3");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(166.6, 108.75, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 109.5, 138.6, 51, BtnBorderColor);
  tft.setCursor(203.3, 129.75);
  tft.println("Button 4");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(13.3, 176.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(14, 177, 138.6, 51, BtnBorderColor);
  tft.setCursor(53.3, 197.25);
  tft.println("Button 5");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color - This section is commented out if using Settings button  */
  tft.drawRect(166.6, 176.25, 140, 52.5, BtnBorderColor);
  tft.drawRect(167.3, 177, 138.6, 51, BtnBorderColor);
  tft.setCursor(203.3, 197.25);
  tft.println("Button 6");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawHomeIcon() {                     /*  DRAW HOME ICON  */

  /*  TOUCH TO GO HOME AREA  -  HOME ICON  */
  tft.fillTriangle(3.33, 10, 18.75, 0, 29.3, 11.25, DarkGREY);    //  roof background
  tft.drawTriangle(3.33, 10, 18.75, 0, 29.3, 11.25, BLACK);       //  roof border
  tft.fillRect(20.6, 1.5, 4.6, 7.5, RED);                     //  chimeney background
  tft.drawRect(20.6, 1.5, 4.6, 7.5, BLACK);                   //  chimeney border
  tft.fillRect(3.3, 11.25, 26.6, 18, WHITE);                  //  house background
  tft.drawRect(3.3, 11.25, 26.6, 18, BLACK);                  //  house border
  tft.fillRect(12.6, 16.5, 8.6, 12, RED);                   //  door background
  tft.drawRect(12.6, 16.5, 8.6, 12, BLACK);                 //  door border
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedBrightUp() { // increase the backlight brightness
  blv = blv + 5;
  if (blv >= 172) {
    blv = 172;
  }
  //    analogWrite(backlight, blv);    /*  Update the brightness - Disabled for my display  */
  LedBrightnessBar();
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedBrightDown() { // decrease the backlight brightness
  blv = blv - 5;
  if (blv <= 5) {
    blv = 5;
  }
  //    analogWrite(backlight, blv);    /*  Update the brightness - Disabled for my display  */
  LedBrightnessBar();
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedBrightnessBar() { // this function fills the yellow bar in the backlight brightness adjustment
  if (blv < barv) {
    tft.fillRect(80.66, 66.75, 158.6, 6, BLACK);
  }
  backlightbox = map(blv, 0.6, 191.25, 0, 178.5);          //  98
  tft.fillRect(80.6, 66.75, backlightbox, 6, YELLOW);
  barv = blv;
  delay(25);
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedTimerUp() {                          //  sleep increase adjustment

  if (LedTimer == 14400000) {
    sleepnever = 1;
    esleep = 12;
    LedTimer = 11111111;
    showTimer();
  }
  if (LedTimer == 3600000) {
    LedTimer = 14400000;
    esleep = 11;
    showTimer();
  }
  if (LedTimer == 1800000) {
    LedTimer = 3600000;
    esleep = 10;
    showTimer();
  }
  if (LedTimer == 1200000) {
    LedTimer = 1800000;
    esleep = 9;
    showTimer();
  }
  if (LedTimer == 600000) {
    LedTimer = 1200000;
    esleep = 8;
    showTimer();
  }
  if (LedTimer == 300000) {
    LedTimer = 600000;
    esleep = 7;
    showTimer();
  }
  if (LedTimer == 120000) {
    LedTimer = 300000;
    esleep = 6;
    showTimer();
  }
  if (LedTimer == 60000) {
    LedTimer = 120000;
    esleep = 5;
    showTimer();
  }
  if (LedTimer == 30000) {
    LedTimer = 60000;
    esleep = 4;
    showTimer();
  }
  if (LedTimer == 20000) {
    LedTimer = 30000;
    esleep = 3;
    showTimer();
  }
  if (LedTimer == 10000) {
    LedTimer = 20000;
    esleep = 2;
    showTimer();
  }
  //  Serial.println("Sleep +");
  delay(350);
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedTimerDown() {                        //  sleep decrease adjustment

  if (LedTimer == 20000) {
    LedTimer = 10000;
    esleep = 1;
    showTimer();
  }
  if (LedTimer == 30000) {
    LedTimer = 20000;
    esleep = 2;
    showTimer();
  }
  if (LedTimer == 60000) {
    LedTimer = 30000;
    esleep = 3;
    showTimer();
  }
  if (LedTimer == 120000) {
    LedTimer = 60000;
    esleep = 4;
    showTimer();
  }
  if (LedTimer == 300000) {
    LedTimer = 120000;
    esleep = 5;
    showTimer();
  }
  if (LedTimer == 600000) {
    LedTimer = 300000;
    esleep = 6;
    showTimer();
  }
  if (LedTimer == 1200000) {
    LedTimer = 600000;
    esleep = 7;
    showTimer();
  }
  if (LedTimer == 1800000) {
    LedTimer = 1200000;
    esleep = 8;
    showTimer();
  }
  if (LedTimer == 3600000) {
    LedTimer = 1800000;
    esleep = 9;
    showTimer();
  }
  if (LedTimer == 14400000) {
    LedTimer = 3600000;
    esleep = 10;
    showTimer();
  }
  if (sleepnever == 1) {
    LedTimer = 14400000;
    sleepnever = 0;
    esleep = 11;
    showTimer();
  }
  //  Serial.println("Sleep -");
  delay(350);
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  showTimer() {                        //  shows the LED sleep timer on the LED options page

  //  Serial.println("Show Timer");

  tft.fillRect(190, 159, 80, 10, BLACK);

  tft.setTextSize(1);
  tft.setTextColor(LIME);
  if (LedTimer == 10000) {
    tft.setCursor(140, 120);
    tft.print("10 Seconds");
  }
  if (LedTimer == 20000) {
    tft.setCursor(140, 120);
    tft.print("20 Seconds");
  }
  if (LedTimer == 30000) {
    tft.setCursor(140, 120);
    tft.print("30 Seconds");
  }
  if (LedTimer == 60000) {
    tft.setCursor(144, 120);
    tft.print("1 Minute");
  }
  if (LedTimer == 120000) {
    tft.setCursor(142, 120);
    tft.print("2 Minutes");
  }
  if (LedTimer == 300000) {
    tft.setCursor(142, 120);
    tft.print("5 Minutes");
  }
  if (LedTimer == 600000) {
    tft.setCursor(140, 120);
    tft.print("10 Minutes");
  }
  if (LedTimer == 1200000) {
    tft.setCursor(140, 120);
    tft.print("20 Minutes");
  }
  if (LedTimer == 1800000) {
    tft.setCursor(140, 120);
    tft.print("30 Minutes");
  }
  if (LedTimer == 3600000) {
    tft.setCursor(148, 120);
    tft.print("1 Hour");
  }
  if (LedTimer == 14400000) {
    tft.setCursor(146.6, 120);
    tft.print("4 Hours");
  }
  if (sleepnever == 1) {
    tft.setCursor(141.3, 120);
    tft.print("Always On");
  }
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearPage() {                       //  Clear menus and Status bar
  //  Serial.println("Clear Page");
  tft.fillRect(13.3, 41.25, 293.3, 187.5, BLACK);                //  Clear Menu
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearButtons()  {                   //  Clear text of the Buttons

  //  Serial.println("Clear Buttons");

  tft.fillRect(13.3, 41.25, 140, 52.5, BLACK);                       //  Button 1 FULL
  tft.fillRect(166.6, 41.25, 140, 52.5, BLACK);                      //  Button 2 FULL
  tft.fillRect(13.3, 108.75, 140, 52.5, BLACK);                      //  Button 3 FULL
  tft.fillRect(166.6, 108.75, 140, 52.5, BLACK);                     //  Button 4 FULL
  tft.fillRect(13.3, 176.25, 140, 52.5, BLACK);                      //  Button 5 FULL
  tft.fillRect(166.6, 176.25, 140, 52.5, BLACK);                     //  Button 6 FULL
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearFullPage()  {                     /*  Clear text of the Buttons  */

  //  Serial.println("Clear Full Page");
  tft.fillRect(13.3, 41.25, 293.3, 187.5, BLACK);  //  Clear full page
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  SaveToEEPROM()  {         /*  Save these values to the EEPROM, so it will not lose settings without power  */

  if  (CurrentPage == "Led Options") {
    delay(500);                   //  short delay to prevent saving twice with one single press of the button
    EEPROM.write(1, blv);         //  Save Led Brightness value to EEPROM
    EEPROM.write(2, esleep);      //  Save the LedTimer value to EEPROM
    Serial.println(F("*****  SAVED LED OPTIONS TO EEPROM  *****"));
  }
  else  {
    //  Serial.println("*****  SAVED TO EEPROM  *****");
  }
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LoadLedTimer()  {

  if (esleep == 1) {
    LedTimer = 10000;
    //  Serial.println("Sleep 10 sec");
  }
  if (esleep == 2) {
    LedTimer = 20000;
    //  Serial.println("Sleep 20 sec");
  }
  if (esleep == 3) {
    LedTimer = 30000;
    //  Serial.println("Sleep 30 sec");
  }
  if (esleep == 4) {
    LedTimer = 60000;
    //  Serial.println("Sleep 1 min");
  }
  if (esleep == 5) {
    LedTimer = 120000;
    //  Serial.println("Sleep 2 min");
  }
  if (esleep == 6) {
    LedTimer = 300000;
    //  Serial.println("Sleep 5 min");
  }
  if (esleep == 7) {
    LedTimer = 600000;
    //  Serial.println("Sleep 10 min");
  }
  if (esleep == 8) {
    LedTimer = 1200000;
    //  Serial.println("Sleep 20 min");
  }
  if (esleep == 9) {
    LedTimer = 1800000;
    //  Serial.println("Sleep 30 min");
  }
  if (esleep == 10) {
    //  Serial.println("Sleep 1 Hour");
    LedTimer = 3600000;
  }
  if (esleep == 11) {
    //  Serial.println("Sleep 4 hours");
    LedTimer = 14400000;
  }
  if (esleep == 12) {
    sleepnever = 1;
    //  Serial.println("Sleep NEVER!");
  }
  awakeend = LedTimer + 1000; // set the current sleep time based on what the saved settings in EEPROM were
}


void  drawInfoPage()  {                   /*  INFO PAGES  */

  //  tft.drawLine(133.3, 0, 13.3, 240, YELLOW);     //  Left Line border (only for aligning the text)
  //  tft.drawLine(306.6, 0, 306.6, 240, YELLOW);   //  Right Line border (only for aligning the text)

  tft.setTextSize(1);
  tft.setTextColor(TextColor);

  if  (PrevPage == "Led Menu")  {                         //  Show the Led Menu Info Page
    tft.setCursor(13.3, 60);
    tft.print("You can use this menu to control");
    tft.setCursor(13.3, 82.5);
    tft.print("your LED strip. Tap one of the");
    tft.setCursor(13.3, 105);
    tft.print("colors to turn ON your LED strip.");
    tft.setCursor(13.3, 127.5);
    tft.print("The other buttons can be used to");
    tft.setCursor(13.3, 150);
    tft.print("turn OFF the strip, to turn ON/OFF a");
    tft.setCursor(13.3, 172.5);
    tft.print("light Bulb (via Relay) or to toggle");
    tft.setCursor(13.3, 195);
    tft.print("the LED Timer ON/OFF.");
  }

  if  (PrevPage == "Led Options")  {                      //  Show the Led Options Info Page
    tft.setCursor(13.3, 60);
    tft.print("This menu can be used to control the");
    tft.setCursor(13.3, 82.5);
    tft.print("Brightness of your LED strip and to");
    tft.setCursor(13.3, 105);
    tft.print("set a Timer to switch OFF your strip");
    tft.setCursor(13.3, 127.5);
    tft.print("after a certain time.");
    tft.setCursor(13.3, 150);
    tft.print("The SAVE button will save these");
    tft.setCursor(13.3, 172.5);
    tft.print("values to the EEPROM. The BACK");
    tft.setCursor(13.3, 195);
    tft.print("button will go back without saving");
  }
}
