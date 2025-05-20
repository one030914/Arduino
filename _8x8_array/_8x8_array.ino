#define display_array_size 8
// ascii 8x8 dot font
#define data_null 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // null char
#define data_ascii_A 0x17, 0x35, 0x15, 0x1f, 0x14, 0x28, 0x7f, 0x28  /*"A",0*/
#define data_ascii_B 0x7c, 0x54, 0xff, 0x54, 0x7c, 0x80, 0x7f, 0x20  /*"B",1*/
#define data_ascii_C 0x00, 0x00, 0x02, 0x02, 0xfe, 0xfe, 0x42, 0x02  /*"C",2*/
#define data_ascii_D 0x00, 0x00, 0x66, 0xf6, 0x92, 0x9a, 0xce, 0x46  /*"D",3*/
#define data_ascii_E 0x00, 0x00, 0x66, 0xf6, 0x92, 0x9a, 0xce, 0x46  /*"E",4*/
#define data_ascii_F 0x00, 0x0a, 0xfe, 0xfe, 0xca, 0x68, 0x38, 0x18  /*"F",5*/
#define data_ascii_G 0x00, 0x7c, 0xfe, 0xb2, 0x9a, 0x8e, 0xfe, 0x7c  /*"G",6*/
#define data_ascii_H 0x00, 0x00, 0x9c, 0xbe, 0xa2, 0xa2, 0xe6, 0xe4  /*"H",7*/
#define data_ascii_I 0x00, 0x00, 0x02, 0x02, 0xfe, 0xfe, 0x42, 0x02 
// display array
byte data_ascii[][display_array_size] = {
  data_null,
  data_ascii_A, data_ascii_B,
  data_ascii_C,
  data_ascii_D,
  data_ascii_E,
  data_ascii_F,
  data_ascii_G,
  data_ascii_H,
  data_ascii_I,
};
//the pin to control ROW
const int row1 = 2; // the number of the row pin 24
const int row2 = 3; // the number of the row pin 23
const int row3 = 4; // the number of the row pin 22
const int row4 = 5; // the number of the row pin 21
const int row5 = 17; // the number of the row pin 4
const int row6 = 16; // the number of the row pin 3
const int row7 = 15; // the number of the row pin 2
const int row8 = 14; // the number of the row pin 1
//the pin to control COl
const int col1 = 6; // the number of the col pin 20
const int col2 = 7; // the number of the col pin 19
const int col3 = 8; // the number of the col pin 18
const int col4 = 9; // the number of the col pin 17
const int col5 = 10; // the number of the col pin 16
const int col6 = 11; // the number of the col pin 15
const int col7 = 12; // the number of the col pin 14
const int col8 = 13; // the number of the col pin 13

void displayNum(byte rowNum,int colNum)
{
  int j;
  byte temp = rowNum;
  for(j=2;j<6;j++)
  {
    digitalWrite(j, LOW);
  }
  digitalWrite(row5, LOW);
  digitalWrite(row6, LOW);
  digitalWrite(row7, LOW);
  digitalWrite(row8, LOW);
  for(j=6;j<14;j++)
  {
    digitalWrite(j, HIGH); }
    switch(colNum)
    {
      case 1: digitalWrite(col1, LOW); break;
      case 2: digitalWrite(col2, LOW); break;
      case 3: digitalWrite(col3, LOW); break;
      case 4: digitalWrite(col4, LOW); break;
      case 5: digitalWrite(col5, LOW); break;
      case 6: digitalWrite(col6, LOW); break;
      case 7: digitalWrite(col7, LOW); break;
      case 8: digitalWrite(col8, LOW); break;
      default: break;
    }
    for(j = 1 ;j < 9; j++)
    {
      temp = (0x80)&(temp) ;
      if(temp==0)
      {
        temp = rowNum<<j;
        continue;
      }
      switch(j)
      {
        case 1: digitalWrite(row1, HIGH); break;
        case 2: digitalWrite(row2, HIGH); break;
        case 3: digitalWrite(row3, HIGH); break;
        case 4: digitalWrite(row4, HIGH); break;
        case 5: digitalWrite(row5, HIGH); break;
        case 6: digitalWrite(row6, HIGH); break;
        case 7: digitalWrite(row7, HIGH); break;
        case 8: digitalWrite(row8, HIGH); break;
        default: break;
     }
    temp = rowNum<<j;
  }
}

void setup(){
  int i = 0 ;
  for(i=2;i<18;i++)
  {
    pinMode(i, OUTPUT);
  }

  for(i=2;i<18;i++) {
    digitalWrite(i, LOW);
  }
}
void loop(){
  int t1;
  int l;
  int arrage;
  for(arrage=0;arrage<10;arrage++)
  {
    for(l=0;l<512;l++)
    {
      for(t1=0;t1<8;t1++)
      {
        displayNum(data_ascii[arrage][t1],(t1+1));
      }
    }
  }
}
