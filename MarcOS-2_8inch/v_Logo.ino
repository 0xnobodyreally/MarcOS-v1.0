
/*  DISPLAY OS VERSION ON CREDIT PAGE AND STARTUP SCREEN  */

void OSVersion()  {

//  tft.setCursor(400, 310);        //  show at bottom right
//  tft.setTextColor(GREY);
//  tft.setTextSize(1);
  tft.println(MarcOS_Version);
}


/*  STARTUP SCREEN  */

void StartupScreen()   {

#define wait1 70 //  50
#define wait2 50

  /*  Horizontal, Vertical, Width, Height  */

  tft.drawRect(0, 0, 320, 240, WHITE);
  tft.drawRect(13, 46, 293, 100, WHITE);
  delay(wait1);
  tft.fillRect(26, 60, 33, 66, RED);
  delay(wait1);
  tft.fillRect(73, 60, 33, 66, RED);
  delay(wait1);
  tft.fillRect(120, 60, 33, 66, RED);
  delay(wait1);
  tft.fillRect(166, 60, 33, 66, RED);    //
  delay(wait1);
  tft.fillRect(213, 60, 33, 66, GREEN);  //
  delay(wait1);
  tft.fillRect(260, 60, 33, 66, GREEN);  //

  delay(150);

  tft.setTextSize(3);
  tft.setTextColor(WHITE);

  /*  Horizontal, Vertical  */
  tft.setCursor(34, 80);
  tft.print("M");
  delay(wait2);
  tft.setCursor(81, 80);
  tft.print("A");
  delay(wait2);
  tft.setCursor(128, 80);
  tft.print("R");
  delay(wait2);
  tft.setCursor(174, 80);
  tft.print("C");
  delay(wait2);
  tft.setCursor(221, 80);
  tft.print("O");
  delay(wait2);
  tft.setCursor(268, 80);
  tft.print("S");
  delay(wait2);

  delay(700);

  tft.setTextSize(1);
  tft.setCursor(117, 180);
  tft.print(MarcOS_Version);
  tft.print("  -  2017");
  tft.setCursor(140, 207);
  tft.print("I can fix it!");
}
