#include <mcs51/8051.h>

unsigned char __code table[] = {0x3f, 0x06, 0x5b, 0x4f,
                                0x66, 0x6d, 0x7d, 0x07,
                                0x7f, 0x6f, 0x77, 0x7c,
                                0x39, 0x5e, 0x79, 0x71};

#define segmentSelect P2_6
#define bitSelect P2_7

#define number P0

unsigned char timeCount = 0;
unsigned char index = 0;

void deley(int num);

int main()
{
   TMOD = 0x01;
   TH0 = (65536 - 50000) / 256;
   TL0 = (65536 - 50000) % 256;
   EA = 1;
   ET0 = 1;
   TR0 = 1;
   
   bitSelect = 1;
   number = 0xc0;
   bitSelect = 0 ;

   segmentSelect = 1;
   number = table[index];
   segmentSelect = 0;
   
   while (1)
   {
      if (timeCount == 20)
      {
         timeCount = 0;
         segmentSelect = 1;
         number = table[index++ % 16];
         segmentSelect = 0;
      }
   }
   return 0;
}

void time() __interrupt 1
{
   TH0 = (65536 - 50000) / 256;
   TL0 = (65536 - 50000) % 256;
   timeCount++; 
}

void deley(int num) {
   for (int i = 0; i < num; i++)
   {
      for (int j = 0; j < 110; j++)
      {
         /* code */
      }
      
   }
   
}
