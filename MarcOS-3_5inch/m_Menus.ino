
/*  Menus  */

void  HomeScreen()  {

  CurrentPage     =  "Home";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   SKY;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();        //  Draw Status Bar
  drawHomeMenu();     //  Draw Home Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  DashBoard()  {

  CurrentPage     =   "DashBoard";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   BLACK;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();        //  Draw Status Bar
  drawDashBoard();     //  Draw DashBoard
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedMenu()  {

  CurrentPage     =   "Led Menu";
  MenuInfo        =   1;
  StatusBarColor  =   GREEN;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   WHITE;
  StatusBar();        //  Draw Status Bar
  drawLedMenu();     //  Draw Home Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  IconMenu()  {

  CurrentPage     =   "Icon Menu";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   PINK;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   WHITE;
  StatusBar();        //  Draw Status Bar
  drawIconMenu();     //  Draw Home Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  SettingsMenu()  {

  CurrentPage     =   "Settings";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   WHITE;
  MenuColor       =   StatusBarColor;
  BtnBorderColor  =   MenuColor;
  TextColor       =   TextColor;
  StatusBar();                //  Draw Status Bar
  drawSettingsMenu();         //  Draw Menu 5 Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedSettingsMenu()  {

  CurrentPage     =   "Led Options";  
  MenuInfo        =   1;                //  Enable Info Page
  StatusBarColor  =   GOLD;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  StatusBar();                          //  Draw Status Bar
  drawLedOptionsMenu();                 //  Draw Led Settings Menu
//  OSVersion();                        //  Display OS Version at bottom-right corner
  PrevPage      =   CurrentPage;        //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  CreditsMenu()  {

  CurrentPage     =   "Credits";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   GREY;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  StatusBar();        //  Draw Status Bar
  drawCreditsMenu();    //  Draw DashBoard
//  OSVersion();        //  Display OS Version at bottom-right corner
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  Menu1()  {

  CurrentPage     =   "Menu1";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();        //  Draw Status Bar
  drawMenu1();        //  Draw Menu 1 Buttons
//  OSVersion();        //  Display OS Version at bottom-right corner
  PrevPage      =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  Menu2()  {

  CurrentPage     =   "Menu2";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   GOLD;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();        //  Draw Status Bar
  drawMenu2();        //  Draw Menu 2 Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  InfoPage() {                            /*  INFO PAGE  */

  CurrentPage     =  "Info";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar
  drawInfoPage();                            //  Draw info page
  PrevPage        =   CurrentPage;           //  Reset Previous Page variable

}

  


