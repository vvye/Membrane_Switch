// TODO clean up this mess


    #include <targets/LPC2000.h>

    void delay(void);

    void lcd(unsigned char);

    char keypad(void);

    char c;


    int main(void)
    {
       // PINSEL0 = PINSEL2 = 0;
       IO0DIR=0x000003ff;
       IO1DIR=0x00780000;
        while(1)
         {
           c=keypad();                            //Obtaining values from keypad
           lcd(c);
          }
    }


    void lcd(unsigned char a)         //LCD Subroutine
      {
        debug_printf("%s", a);
      }



    char keypad(void)                         //Keypad Scan
     {
       while(1)
       {
          IO1CLR|=(1<<19);               //Making row1 LOW
          IO1SET|=(1<<20)|(1<<21)|(1<<22); //Making rest of the rows '1'
          if(!(IO1PIN&(1<<16)))             //Scan for key press
           {
            while(!(IO1PIN&(1<<16)));
            return '1';                           //Returning value to display
           }
          if(!(IO1PIN&(1<<17)))
           {
             while(!(IO1PIN&(1<<17)));
             return '2';
           }
          if(!(IO1PIN&(1<<18)))
           {
             while(!(IO1PIN&(1<<18)));
             return '3';
           }
          IO1CLR|=(1<<20);
          IO1SET|=(1<<21)|(1<<22)|(1<<19);
          if(!(IO1PIN&(1<<16)))
    {
            while(!(IO1PIN&(1<<16)));
            return '4';
          }
          if(!(IO1PIN&(1<<17)))
    {
            while(!(IO1PIN&(1<<17)));
            return '5';
         }
          if(!(IO1PIN&(1<<18)))
    {
            while(!(IO1PIN&(1<<18)));
            return '6';
         }
          IO1CLR|=(1<<21);
          IO1SET|=(1<<22)|(1<<20)|(1<<19);
          if(!(IO1PIN&(1<<16)))
    {
            while(!(IO1PIN&(1<<16)));
            return '7';
         }
          if(!(IO1PIN&(1<<17)))
    {
           while(!(IO1PIN&(1<<17)));
           return '8';
        }
          if(!(IO1PIN&(1<<18)))
    {
            while(!(IO1PIN&(1<<18)));
            return '9';
    }
          IO1CLR|=(1<<22);
          IO1SET|=(1<<19)|(1<<20)|(1<<21);
          if(!(IO1PIN&(1<<16)))
    {
            while(!(IO1PIN&(1<<16)));
            return '*';
    }
          if(!(IO1PIN&(1<<17)))
    {
            while(!(IO1PIN&(1<<17)));
            return '0';
    }
          if(!(IO1PIN&(1<<18)))
    {
            while(!(IO1PIN&(1<<18)));
            return '#';
    }
       }
    }

    void delay(void)                                    //Delay loop
    {
      unsigned int i;
      for(i=0;i<=20000;i++);
    }