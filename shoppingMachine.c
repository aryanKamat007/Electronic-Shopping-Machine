#include <at89c51xd2.h>
void delay(unsigned int);
void lcd_send(bit);
void lcd_init(void);
unsigned int temp1; // to store command
unsigned int temp2; // to store data
unsigned int var, j;
unsigned int total = 0;
sbit wave = P1 ^ 5;

sbit RS = P2 ^ 7; // register select pin
sbit EN = P2 ^ 6; // enable pin to latch data
sbit R0 = P3 ^ 0;
sbit R1 = P3 ^ 1;
sbit R2 = P3 ^ 2;
sbit R3 = P3 ^ 3;
sbit C0 = P3 ^ 4;
sbit C1 = P3 ^ 5;
sbit C2 = P3 ^ 6;
sbit C3 = P3 ^ 7;
bit rs;
int main()
{
    unsigned char data1[] = {"Welcome to Store"};
    unsigned char data3[] = {"Cart: "};
    unsigned char data4[] = {"Checkout: "};
    unsigned char data2[] = {"Visit Again."};

    delay(1000);
    lcd_init();
    temp1 = 0x80; // start displaying from first line first character
    rs = 0;
    lcd_send(rs);
    delay(500);
    for (j = 0; j < 16; j++) // send data character each char at a time
    {
        temp1 = data1[j];
        rs = 1;
        lcd_send(rs);
        delay(50000); // wait for sometime
    }
    temp1 = 0x01; // clear the display once string is displayed
    rs = 0;
    lcd_send(rs);
    delay(500);
    while (1)
    {

        R0 = R1 = R2 = R3 = 1;
        R0 = 0;
        if (C0 == 0)
        {
            total += 2;
            temp1 = 0x80; // start displaying from first line first character
            rs = 0;
            lcd_send(rs);
            delay(500);
            for (j = 0; j < 6; j++) // send data character each char at a time
            {
                temp1 = data3[j];
                rs = 1;
                lcd_send(rs);
                delay(50000); // wait for sometime
            }
            temp1 = total / 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = total % 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = 0x01; // clear the display once string is displayed
            rs = 0;
            lcd_send(rs);
            delay(500);
        }
        R0 = R1 = R2 = R3 = 1;
        R0 = 0;
        if (C1 == 0)
        {
            total += 5;
            temp1 = 0x80; // start displaying from first line first character
            rs = 0;
            lcd_send(rs);
            delay(500);
            for (j = 0; j < 6; j++) // send data character each char at a time
            {
                temp1 = data3[j];
                rs = 1;
                lcd_send(rs);
                delay(50000); // wait for sometime
            }
            temp1 = total / 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = total % 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = 0x01; // clear the display once string is displayed
            rs = 0;
            lcd_send(rs);
            delay(500);
        }

        R0 = R1 = R2 = R3 = 1;
        R0 = 0;
        if (C2 == 0)
        {
            total += 10;
            temp1 = 0x80; // start displaying from first line first character
            rs = 0;
            lcd_send(rs);
            delay(500);
            for (j = 0; j < 6; j++) // send data character each char at a time
            {
                temp1 = data3[j];
                rs = 1;
                lcd_send(rs);
                delay(50000); // wait for sometime
            }
            temp1 = total / 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = total % 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = 0x01; // clear the display once string is displayed
            rs = 0;
            lcd_send(rs);
            delay(500);
        }

        R0 = R1 = R2 = R3 = 1;
        R0 = 0;
        if (C3 == 0)
        {
            total += 15;
            temp1 = 0x80; // start displaying from first line first character
            rs = 0;
            lcd_send(rs);
            delay(500);
            for (j = 0; j < 6; j++) // send data character each char at a time
            {
                temp1 = data3[j];
                rs = 1;
                lcd_send(rs);
                delay(50000); // wait for sometime
            }

            temp1 = total / 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = total % 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = 0x01; // clear the display once string is displayed
            rs = 0;
            lcd_send(rs);
            delay(500);
        }

        R0 = R1 = R2 = R3 = 1;
        R1 = 0;
        if (C0 == 0)
        {
            wave = 0;
            delay(1000);

            delay(1000);
            temp1 = 0x80; // start displaying from first line first character
            rs = 0;
            lcd_send(rs);
            delay(500);
            for (j = 0; j < 10; j++) // send data character each char at a time
            {
                temp1 = data4[j];
                rs = 1;
                lcd_send(rs);
                delay(50000); // wait for sometime
            }
            temp1 = total / 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = total % 10 + 48;
            rs = 1;
            lcd_send(rs);
            delay(50000);

            temp1 = 0x01; // clear the display once string is displayed
            rs = 0;
            lcd_send(rs);
            delay(500);
            total = 0;

            temp1 = 0x80; // start displaying from first line first character
            rs = 0;
            lcd_send(rs);
            delay(500);
            for (j = 0; j < 12; j++) // send data character each char at a time
            {
                temp1 = data2[j];
                rs = 1;
                lcd_send(rs);
                delay(50000); // wait for sometime
            }
            temp1 = 0x01; // clear the display once string is displayed
            rs = 0;
            lcd_send(rs);
            delay(500);
        }

        R0 = R1 = R2 = R3 = 1;
        R1 = 0;
        if (C1 == 0)
        {
            wave = 1;
            temp1 = 0x80; // start displaying from first line first character
            rs = 0;
            lcd_send(rs);
            delay(500);
            for (j = 0; j < 16; j++) // send data character each char at a time
            {
                temp1 = data1[j];
                rs = 1;
                lcd_send(rs);
                delay(50000); // wait for sometime
            }
            temp1 = 0x01; // clear the display once string is displayed
            rs = 0;
            lcd_send(rs);
            delay(500);
        }
    }
}
void lcd_init(void)
{
    unsigned int cmd[] = {0x30, 0x30, 0x30, 0x20, 0x28, 0x28, 0x0e, 0x06, 0x01, 0x80};
    unsigned int j;
    for (j = 0; j < 10; j++)
    {
        temp1 = cmd[j]; // send individual command
        rs = 0;
        lcd_send(rs);
        delay(500); // wiat for sometime
    }
}
// Function to pass commands to LCD
void lcd_send(bit rs)
{
    var = temp1;          // save for future use
    temp1 = temp1 & 0xf0; // Convert the byte into two nibbles
    temp1 = temp1 >> 4;   // Shift the most significant nibble to least position
    P2 = temp1;           // send higher nibble to port
    RS = rs;
    EN = 1;
    delay(2);
    EN = 0;             // EN=0
    temp1 = var & 0x0f; // Get the least significant nibble
    P2 = temp1;         // send lower nibble to port
    RS = rs;
    EN = 1;
    delay(2);
    EN = 0; // EN=0
    delay(60);
}
void delay(unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++)
        ;
}