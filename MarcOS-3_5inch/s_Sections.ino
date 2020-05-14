
/*  These are the pages and buttons of the various menus  */

void  StatusBar()  {

  //  Serial.println(CurrentPage);                             //  show current menu

  /*  Black Background  */
  //  tft.fillRect(0, 0, 480, 320, BLACK);                 //  full screen background

  /*  Horizontal, Vertical, Width, Height, Color  */
  tft.fillRect(0, 0, 480, 40, StatusBarColor);             //  Draw Status Bar background
  tft.drawRect(0, 0, 480, 320, StatusBarColor);            //  full screen border

  /*  if not in home menu display home icon  */
  if  (CurrentPage != "Home") {
    /*  TOUCH TO GO HOME AREA  -  HOME ICON  */
    drawHomeIcon();
  }

  /*  If there is an info menu for the current page then draw an "i" at top-right of the Status bar  */
  if  (MenuInfo ==  1)  {    
   tft.setTextSize(3);
   tft.setTextColor(TextColor);
   tft.setCursor(450, 10);
   tft.println("i");
  }
  
  /*  -------------------------------------------------------------------------------------------------------  */
  /*  SET TEXT COLOR BASED ON STATUS BAR COLOR  */
  tft.setTextSize(3);
  if  (StatusBarColor != WHITE && StatusBarColor != YELLOW)  { //  if the StatusBarColor is NOT WHITE or YELLOW
    tft.setTextColor(WHITE);                      //  set the text color to WHITE
  }
  else  {
    tft.setTextColor(BLACK);                      //  otherwise display text in BLACK
  }

  /*  -------------------------------------------------------------------------------------------------------  */
  /*  ALIGN STATUS BAR TEXT TO THE CENTER */
  if (CurrentPage == "Home") {
    tft.setCursor(205, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Led Menu") {
    tft.setCursor(180, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Led Options") {
    tft.setCursor(150, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Settings") {
    tft.setCursor(170, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "DashBoard") {
    tft.setTextColor(BLACK);                       //  Horizontal, Vertical position
    tft.setCursor(160, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Icon Menu") {
    tft.setCursor(160, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Menu1") {
    tft.setCursor(200, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Credits") {
    tft.setCursor(190, 10);                       //  Horizontal, Vertical position
  }
  else  {
    tft.setCursor(200, 10);                       //  Horizontal, Vertical position
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

  tft.setTextSize(2);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 55, 210, 70, BtnBorderColor);   //
  tft.drawRect(21, 56, 208, 68, BtnBorderColor);
  tft.setCursor(100, 83);
  tft.println("TIME");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 55, 210, 70, BtnBorderColor);
  tft.drawRect(251, 56, 208, 68, BtnBorderColor);
  tft.setCursor(305, 83);
  tft.println("LED MENU");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 145, 210, 70, BtnBorderColor);
  tft.drawRect(21, 146, 208, 68, BtnBorderColor);
  tft.setCursor(70, 173);
  tft.println("ICON MENU");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 145, 210, 70, BtnBorderColor);
  tft.drawRect(251, 146, 208, 68, BtnBorderColor);
  tft.setCursor(322, 173);
  tft.println("MENU 1");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 235, 210, 70, BtnBorderColor);
  tft.drawRect(21, 236, 208, 68, BtnBorderColor);
  tft.setCursor(92, 263);
  tft.println("MENU 2");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color - This section is commented out if using Settings button  */
  tft.drawRect(250, 235, 210, 70, BtnBorderColor);
  tft.drawRect(251, 236, 208, 68, BtnBorderColor);
  tft.setCursor(310, 263);
  tft.println("SETTINGS");

}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawDashBoard()  {          //  where Time & Date, Temperature & Humidity are displayed
  /*  DATE  */
  tft.setCursor(115, 60);
  tft.setTextSize(3);
  tft.setTextColor(GREY);
  tft.println("18 October 2017");

  /*  TIME  */
  tft.setTextSize(9);
  tft.setTextColor(WHITE);
  tft.setCursor(115, 130);
  tft.print("00");
  tft.setTextColor(GREY);
  tft.print(":");
  tft.setTextColor(WHITE);
  tft.print("00");

  /*  LIGHTS  */
  /*
    tft.setTextSize(2);
    tft.setTextColor(GREY);
    tft.setCursor(160, 230);
    tft.println("Lights are ");
    tft.setTextColor(SKY);
    tft.setCursor(290, 230);
    tft.println("blue");
  */

  /*  TEMPERATURE  */
  tft.setTextSize(2);
  tft.setTextColor(GREY);
  tft.setCursor(70, 280);
  tft.print("Temperature: ");
  tft.setTextColor(ORANGE);
  tft.print("22");
  tft.setTextSize(1);
  tft.print("o");

  //      tft.print("  ");     //  Separator

  /*  HUMIDITY  */
  tft.setTextSize(2);
  tft.setCursor(270, 280);
  tft.setTextColor(GREY);
  tft.print("Humidity: ");
  tft.setTextColor(SKY);
  tft.print("64");
  tft.print("%");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawCreditsMenu()  {                  /*  About and Credits menu  */

  tft.setCursor(140, 60);
  tft.setTextSize(3);
  tft.setTextColor(SKY);
  OSVersion();

  tft.setTextSize(3);
  tft.setTextColor(GREY);
  tft.setCursor(170, 105);
  tft.println("CREDITS:");

  tft.setTextSize(2);
  tft.setTextColor(SALMON);
  tft.setCursor(70, 150);
  tft.print("Developed by:  ");
  tft.setTextColor(WHITE);
  tft.print("Marco Santoru");
  tft.setTextColor(SKY);
  tft.setCursor(140, 190);
  tft.print("www.marcolino.net");

  tft.setTextColor(SALMON);
  tft.setCursor(70, 230);
  tft.print("Developed for: ");
  tft.setTextColor(WHITE);
  tft.print("I can fix it!");
  tft.setTextColor(SKY);
  tft.setCursor(110, 270);
  tft.print("youtube.com/icanfixit");

}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawIconMenu()  {           //  icon menu (12 buttons)

  //  95px wide, 20px separator  ( (95px*4)+(20px*5) = 480px )

  tft.setTextSize(2);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 55, 95, 70, BtnBorderColor);       //  40
  tft.drawRect(21, 56, 93, 68, BtnBorderColor);
  tft.setCursor(30, 65);                  //65
  tft.println("1");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(135, 55, 95, 70, BtnBorderColor);
  tft.drawRect(136, 56, 93, 68, BtnBorderColor);
  tft.setCursor(145, 65);
  tft.println("2");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 55, 95, 70, BtnBorderColor);
  tft.drawRect(251, 56, 93, 68, BtnBorderColor);
  tft.setCursor(260, 65);
  tft.println("3");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(365, 55, 95, 70, BtnBorderColor);
  tft.drawRect(366, 56, 93, 68, BtnBorderColor);
  tft.setCursor(375, 65);
  tft.println("4");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 145 , 95, 70, BtnBorderColor);      //  130
  tft.drawRect(21, 146, 93, 68, BtnBorderColor);
  tft.setCursor(30, 155);                 //  155
  tft.println("5");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(135, 145, 95, 70, BtnBorderColor);
  tft.drawRect(136, 146, 93, 68, BtnBorderColor);
  tft.setCursor(145, 155);
  tft.println("6");

  /*  Button 7 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 145, 95, 70, BtnBorderColor);
  tft.drawRect(251, 146, 93, 68, BtnBorderColor);
  tft.setCursor(260, 155);
  tft.println("7");

  /*  Button 8 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(365, 145, 95, 70, BtnBorderColor);
  tft.drawRect(366, 146, 93, 68, BtnBorderColor);
  tft.setCursor(375, 155);
  tft.println("8");

  /*  Button 9 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 235, 95, 70, BtnBorderColor);      // 220
  tft.drawRect(21, 236, 93, 68, BtnBorderColor);
  tft.setCursor(30, 245);       //  235
  tft.println("9");
  //  tft.setCursor(50, 280);       // 260
  //  tft.println("OFF");

  /*  Button 10 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(135, 235, 95, 70, BtnBorderColor);     // 220
  tft.drawRect(136, 236, 93, 68, BtnBorderColor);
  tft.setCursor(145, 245);            //  235
  tft.println("10");

  /*  Button 11 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 235, 95, 70, BtnBorderColor);
  tft.drawRect(251, 236, 93, 68, BtnBorderColor);
  tft.setCursor(260, 245);            //  235
  tft.println("11");


  /*  Button 12 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(365, 235, 95, 70, BtnBorderColor);
  tft.drawRect(366, 236, 93, 68, BtnBorderColor);
  tft.setCursor(375, 245);            //  235
  tft.println("12");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawSettingsMenu()  {

  tft.setTextSize(2);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 55, 210, 70, BtnBorderColor);
  tft.drawRect(21, 56, 208, 68, BtnBorderColor);
  tft.setCursor(80, 83);
  tft.println("Button 1");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 55, 210, 70, BtnBorderColor);
  tft.drawRect(251, 56, 208, 68, BtnBorderColor);
  tft.setCursor(305, 83);
  tft.println("Button 2");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 145, 210, 70, BtnBorderColor);
  tft.drawRect(21, 146, 208, 68, BtnBorderColor);
  tft.setCursor(80, 173);
  tft.println("Button 3");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 145, 210, 70, BtnBorderColor);
  tft.drawRect(251, 146, 208, 68, BtnBorderColor);
  tft.setCursor(305, 173);
  tft.println("Button 4");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 235, 210, 70, BtnBorderColor);
  tft.drawRect(21, 236, 208, 68, BtnBorderColor);
  tft.setCursor(80, 263);
  tft.println("Button 5");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color - This section is commented out if using Settings button  */
  tft.drawRect(250, 235, 210, 70, BtnBorderColor);
  tft.drawRect(251, 236, 208, 68, BtnBorderColor);
  tft.setCursor(315, 263);
  tft.println("CREDITS");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawLedMenu()  {                /*  LED colors and options  */

#define LedButtonBorderColor    WHITE

  //  95px wide, 20px separator  ( (95px*4)+(20px*5) = 480px )

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 55, 95, 70, LedButtonBorderColor);       //  40
  tft.drawRect(21, 56, 93, 68, LedButtonBorderColor);
  //  tft.fillRect(22, 57, 91, 66, Menu5ButtonColor);    /*  Single color button  */
  tft.fillRect(22, 57, 46, 33, RED);                    //  Fill button for
  tft.fillRect(68, 57, 45, 33, GREEN);                 //  Rainbow effect
  tft.fillRect(22, 90, 46, 33, BLUE);                 //  with 4 different
  tft.fillRect(68, 90, 45, 33, YELLOW);              //  colors
  tft.setCursor(28, 80);                  //65
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.println("RAINBOW");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(135, 55, 95, 70, LedButtonBorderColor);
  tft.drawRect(136, 56, 93, 68, LedButtonBorderColor);
  tft.fillRect(137, 57, 91, 66, CYAN);
  tft.setCursor(160, 80);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.println("CYAN");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 55, 95, 70, LedButtonBorderColor);
  tft.drawRect(251, 56, 93, 68, LedButtonBorderColor);
  tft.fillRect(252, 57, 91, 66, MAGENTA);
  tft.setCursor(275, 80);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.println("PINK");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(365, 55, 95, 70, LedButtonBorderColor);
  tft.drawRect(366, 56, 93, 68, LedButtonBorderColor);
  tft.fillRect(367, 57, 91, 66, GREEN);
  tft.setCursor(385, 80);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.println("GREEN");


  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 145, 95, 70, LedButtonBorderColor);      //  130
  tft.drawRect(21, 146, 93, 68, LedButtonBorderColor);
  tft.fillRect(22, 147, 91, 66, RED);
  tft.setCursor(52, 170);                 //  155
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.println("RED");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(135, 145, 95, 70, LedButtonBorderColor);
  tft.drawRect(136, 146, 93, 68, LedButtonBorderColor);
  tft.fillRect(137, 147, 91, 66, BLUE);
  tft.setCursor(162, 170);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.println("BLUE");

  /*  Button 7 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 145, 95, 70, LedButtonBorderColor);
  tft.drawRect(251, 146, 93, 68, LedButtonBorderColor);
  tft.fillRect(252, 147, 91, 66, YELLOW);
  tft.setCursor(262, 170);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.println("YELLOW");

  /*  Button 8 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(365, 145, 95, 70, LedButtonBorderColor);
  tft.drawRect(366, 146, 93, 68, LedButtonBorderColor);
  tft.fillRect(367, 147, 91, 66, WHITE);
  tft.setCursor(385, 170);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.println("WHITE");


  /*  Button 9 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 235, 95, 70, LedButtonBorderColor);      // 220
  tft.drawRect(21, 236, 93, 68, LedButtonBorderColor);
  tft.fillRect(22, 237, 91, 66, DarkGREY);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(40, 250);       //  235
  tft.println("STRIP");
  tft.setCursor(50, 275);       // 260
  tft.println("OFF");

  /*  Button 10 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(135, 235, 95, 70, LedButtonBorderColor);     // 220
  tft.drawRect(136, 236, 93, 68, LedButtonBorderColor);
  tft.fillRect(137, 237, 91, 66, DarkGREY);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(160, 250);            //  235
  tft.println("BULB");
  tft.setCursor(147, 275);
  tft.println("ON/OFF");

  /*  Button 11 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 235, 95, 70, LedButtonBorderColor);
  tft.drawRect(251, 236, 93, 68, LedButtonBorderColor);
  tft.fillRect(252, 237, 91, 66, DarkGREY);
  tft.setTextSize(2);
  tft.setCursor(268, 250);
  tft.println("TIMER");
  tft.setCursor(262, 275);
  tft.println("ON/OFF");


  /*  Button 12 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(365, 235, 95, 70, RED);
  tft.drawRect(366, 236, 93, 68, ORANGE);
  tft.fillRect(367, 237, 91, 66, DarkGREY);
//  tft.setCursor(383, 250);
  tft.setCursor(372, 262);
  tft.setTextColor(YELLOW);
  tft.println("OPTIONS");


}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawLedOptionsMenu() {          /*  LED Options screen  */

//int  BoxColor = StatusBarColor;
  
  //  backlight level
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.drawRect(100, 60, 280, 50, MenuColor);         //  draw outer box

  tft.fillRect(20, 60, 60, 50, RED);            //  draw - button box
  tft.drawRect(20, 60, 60, 50, WHITE);          //  draw button outer box
  tft.setCursor(42, 73);                        //  text position
  tft.print("-");

  tft.fillRect(400, 60, 60, 50, GREEN);         //  draw + button box
  tft.drawRect(400, 60, 60, 50, WHITE);         //  draw button outer box
  tft.setCursor(422, 73);                       //  text position
  tft.print("+");

  tft.setTextSize(1);
  tft.setCursor(200, 71);                       //  text position
  tft.print("LED Brightness");
  tft.drawRect(120, 88, 240, 10, WHITE);        //  draw Led Brightness outer box

  LedBrightnessBar();                           //  draw brightness bar

  /*  ========================================================================================  */
  //  sleep time
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.drawRect(100, 130, 280, 50, MenuColor);         //  draw outer box

  tft.fillRect(20, 130, 60, 50, RED);           //  draw - button box
  tft.drawRect(20, 130, 60, 50, WHITE);         //  draw button outer box
  tft.setCursor(42, 143);                       //  text position
  tft.print("-");

  tft.fillRect(400, 130, 60, 50, GREEN);        //  draw + button box
  tft.drawRect(400, 130, 60, 50, WHITE);        //  draw button outer box
  tft.setCursor(422, 143);                      //  text position
  tft.print("+");

  tft.setTextSize(1);
  tft.setCursor(210, 141);                      //  text position
  tft.print("Sleep Time");

  showTimer();                                  //  show Timer

/*  uncomment the section below if you want a third adjustable option  */
/*
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.drawRect(100, 200, 280, 50, MenuColor);        //  draw outer box

  tft.fillRect(20, 200, 60, 50, RED);           //  draw - button box
  tft.drawRect(20, 200, 60, 50, WHITE);         //  draw button outer box
  tft.setCursor(42, 213);                       //  text position
  tft.print("-");

  tft.fillRect(400, 200, 60, 50, GREEN);        //  draw + button box
  tft.drawRect(400, 200, 60, 50, WHITE);        //  draw button outer box
  tft.setCursor(422, 213);                      //  text position
  tft.print("+");

  tft.setTextSize(1);
  tft.setCursor(180, 220);                      //  text position
  tft.print("OPTIONAL - NOT IN USE");
//*/

  tft.setTextSize(2);
  tft.setTextColor(WHITE);

/*  BACK  BUTTON  */
  tft.fillRect(120, 270, 100, 30, GREEN);      //  draw BACK button box
  tft.drawRect(120, 270, 100, 30, WHITE);       //  draw button outer box
  tft.setCursor(147, 278);                      //  text position
  tft.print("BACK");

/*  SAVE  BUTTON  */
  tft.fillRect(260, 270, 100, 30, SALMON);         //  draw SAVE button box
  tft.drawRect(260, 270, 100, 30, WHITE);       //  draw button outer box
  tft.setTextSize(2);
  tft.setCursor(287, 278);                      //  text position
  tft.print("SAVE");

}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawMenu1()  {                      /*  using MenuColor variable  */

  tft.setTextSize(2);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 55, 210, 70, BtnBorderColor);
  tft.drawRect(21, 56, 208, 68, BtnBorderColor);
  tft.setCursor(80, 83);
  tft.println("Button 1");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 55, 210, 70, BtnBorderColor);
  tft.drawRect(251, 56, 208, 68, BtnBorderColor);
  tft.setCursor(305, 83);
  tft.println("Button 2");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 145, 210, 70, BtnBorderColor);
  tft.drawRect(21, 146, 208, 68, BtnBorderColor);
  tft.setCursor(80, 173);
  tft.println("Button 3");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 145, 210, 70, BtnBorderColor);
  tft.drawRect(251, 146, 208, 68, BtnBorderColor);
  tft.setCursor(305, 173);
  tft.println("Button 4");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 235, 210, 70, BtnBorderColor);
  tft.drawRect(21, 236, 208, 68, BtnBorderColor);
  tft.setCursor(80, 263);
  tft.println("Button 5");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color - This section is commented out if using Settings button  */
  tft.drawRect(250, 235, 210, 70, BtnBorderColor);
  tft.drawRect(251, 236, 208, 68, BtnBorderColor);
  tft.setCursor(305, 263);
  tft.println("Button 6");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawMenu2()  {                      /*  using MenuColor variable  */

  tft.setTextSize(2);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 55, 210, 70, BtnBorderColor);
  tft.drawRect(21, 56, 208, 68, BtnBorderColor);
  tft.setCursor(80, 83);
  tft.println("Button 1");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 55, 210, 70, BtnBorderColor);
  tft.drawRect(251, 56, 208, 68, BtnBorderColor);
  tft.setCursor(305, 83);
  tft.println("Button 2");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 145, 210, 70, BtnBorderColor);
  tft.drawRect(21, 146, 208, 68, BtnBorderColor);
  tft.setCursor(80, 173);
  tft.println("Button 3");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 145, 210, 70, BtnBorderColor);
  tft.drawRect(251, 146, 208, 68, BtnBorderColor);
  tft.setCursor(305, 173);
  tft.println("Button 4");

  /*  Button 5 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 235, 210, 70, BtnBorderColor);
  tft.drawRect(21, 236, 208, 68, BtnBorderColor);
  tft.setCursor(80, 263);
  tft.println("Button 5");

  /*  Button 6 - Horizontal, Vertical, Width, Height, Color - This section is commented out if using Settings button  */
  tft.drawRect(250, 235, 210, 70, BtnBorderColor);
  tft.drawRect(251, 236, 208, 68, BtnBorderColor);
  tft.setCursor(305, 263);
  tft.println("Button 6");
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawHomeIcon() {                     /*  DRAW HOME ICON  */

  /*  TOUCH TO GO HOME AREA  -  HOME ICON  */
  tft.fillTriangle(5, 15, 25, 0, 44, 15, DarkGREY);    //  roof background
  tft.drawTriangle(5, 15, 25, 0, 44, 15, BLACK);       //  roof border
  tft.fillRect(31, 2, 7, 10, RED);                     //  chimeney background
  tft.drawRect(31, 2, 7, 10, BLACK);                   //  chimeney border
  tft.fillRect(5, 15, 40, 24, WHITE);                  //  house background
  tft.drawRect(5, 15, 40, 24, BLACK);                  //  house border
  tft.fillRect(19, 22, 13, 16, RED);                   //  door background
  tft.drawRect(19, 22, 13, 16, BLACK);                 //  door border
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedBrightUp() { // increase the backlight brightness
  blv = blv + 5;
  if (blv >= 255) {
    blv = 255;
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
    tft.fillRect(121, 89, 238, 8, BLACK);
  }
  backlightbox = map(blv, 1, 255, 0, 238);          //  98
  tft.fillRect(121, 89, backlightbox, 8, YELLOW);
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
    tft.setCursor(210, 160);
    tft.print("10 Seconds");
  }
  if (LedTimer == 20000) {
    tft.setCursor(210, 160);
    tft.print("20 Seconds");
  }
  if (LedTimer == 30000) {
    tft.setCursor(210, 160);
    tft.print("30 Seconds");
  }
  if (LedTimer == 60000) {
    tft.setCursor(216, 160);
    tft.print("1 Minute");
  }
  if (LedTimer == 120000) {
    tft.setCursor(213, 160);
    tft.print("2 Minutes");
  }
  if (LedTimer == 300000) {
    tft.setCursor(213, 160);
    tft.print("5 Minutes");
  }
  if (LedTimer == 600000) {
    tft.setCursor(210, 160);
    tft.print("10 Minutes");
  }
  if (LedTimer == 1200000) {
    tft.setCursor(210, 160);
    tft.print("20 Minutes");
  }
  if (LedTimer == 1800000) {
    tft.setCursor(210, 160);
    tft.print("30 Minutes");
  }
  if (LedTimer == 3600000) {
    tft.setCursor(222, 160);
    tft.print("1 Hour");
  }
  if (LedTimer == 14400000) {
    tft.setCursor(220, 160);
    tft.print("4 Hours");
  }
  if (sleepnever == 1) {
    tft.setCursor(212, 160);
    tft.print("Always On");
  }
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearPage() {                       //  Clear menus and Status bar
  //  Serial.println("Clear Page");
  tft.fillRect(20, 55, 440, 250, BLACK);                        //  Clear Menu
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearButtons()  {                   //  Clear text of the Buttons

  //  Serial.println("Clear Buttons");

  tft.fillRect(20, 55, 210, 70, BLACK);                       //  Button 1 FULL
  tft.fillRect(250, 55, 210, 70, BLACK);                      //  Button 2 FULL
  tft.fillRect(20, 145, 210, 70, BLACK);                      //  Button 3 FULL
  tft.fillRect(250, 145, 210, 70, BLACK);                     //  Button 4 FULL
  tft.fillRect(20, 235, 210, 70, BLACK);                      //  Button 5 FULL
  tft.fillRect(250, 235, 210, 70, BLACK);                     //  Button 6 FULL
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearFullPage()  {                     /*  Clear text of the Buttons  */

  //  Serial.println("Clear Full Page");
  tft.fillRect(20, 55, 440, 250, BLACK);  //  Clear full page
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

//  tft.drawLine(20, 0, 20, 320, YELLOW);     //  Left Line border (only for aligning the text)
//  tft.drawLine(460, 0, 460, 320, YELLOW);   //  Right Line border (only for aligning the text)
  
  tft.setTextSize(2);
  tft.setTextColor(TextColor);

  if  (PrevPage == "Led Menu")  {                         //  Show the Led Menu Info Page
    tft.setCursor(20, 80);
    tft.print("You can use this menu to control");
    tft.setCursor(20, 110);
    tft.print("your LED strip. Tap one of the");
    tft.setCursor(20, 140);
    tft.print("colors to turn ON your LED strip.");
    tft.setCursor(20, 170);
    tft.print("The other buttons can be used to");
    tft.setCursor(20, 200);
    tft.print("turn OFF the strip, to turn ON/OFF a");
    tft.setCursor(20, 230);
    tft.print("light Bulb (via Relay) or to toggle");
    tft.setCursor(20, 260);
    tft.print("the LED Timer ON/OFF.");
  }
  
  if  (PrevPage == "Led Options")  {                      //  Show the Led Options Info Page
    tft.setCursor(20, 80);
    tft.print("This menu can be used to control the");
    tft.setCursor(20, 110);
    tft.print("Brightness of your LED strip and to");
    tft.setCursor(20, 140);
    tft.print("set a Timer to switch OFF your strip");
    tft.setCursor(20, 170);
    tft.print("after a certain time.");
    tft.setCursor(20, 200);
    tft.print("The SAVE button will save these");
    tft.setCursor(20, 230);
    tft.print("values to the EEPROM. The BACK");
    tft.setCursor(20, 260);
    tft.print("button will go back without saving");
  }  
}



