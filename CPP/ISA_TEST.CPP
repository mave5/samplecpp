#include    	<stdio.h>
#include    	<dos.h>
#include    	<conio.h>
#include    	<process.h>
#include	<string.h>
#include	<stdlib.h>
#include	<math.h>
#include	<fstream.h>
#include	<time.h>

//#define 	JTAG_ADD 		0x5300
#define 	STATUS_ADD0 		0x0302
#define 	STATUS_ADD1 		0x1302
#define 	STATUS_ADD2 		0x2302
#define 	STATUS_ADD3 		0x3302
#define 	STATUS_ADD4 		0x4302
#define 	STATUS_ADD5 		0x5302
#define 	STATUS_ADD6 		0x6302
#define 	STATUS_ADD7 		0x7302
#define 	STATUS_ADD8 		0x8302
#define 	STATUS_ADD9 		0x9302
#define 	STATUS_ADD10		0xA302
#define 	STATUS_ADD11		0xB302
#define 	STATUS_ADD12		0xC302
#define 	STATUS_ADD13		0xD302
#define 	STATUS_ADD14		0xE302
#define 	STATUS_ADD15		0xF302
//----------- FIFO_NWK Address Definition -----------
#define 	FIFO_NWK0 		0x0306
#define 	FIFO_NWK1 		0x1306
#define 	FIFO_NWK2 		0x2306
#define 	FIFO_NWK3 		0x3306
#define 	FIFO_NWK4 		0x4306
#define 	FIFO_NWK5 		0x5306
#define 	FIFO_NWK6 		0x6306
#define 	FIFO_NWK7 		0x7306
#define 	FIFO_NWK8 		0x8306
#define 	FIFO_NWK9 		0x9306
#define 	FIFO_NWK10		0xA306
#define 	FIFO_NWK11		0xB306
#define 	FIFO_NWK12		0xC306
#define 	FIFO_NWK13		0xD306
#define 	FIFO_NWK14		0xE306
#define 	FIFO_NWK15		0xF306
//----------- FIFO_MAC Address Definition -----------
#define 	FIFO_MAC0 		0x0308
#define 	FIFO_MAC1 		0x1308
#define 	FIFO_MAC2 		0x2308
#define 	FIFO_MAC3 		0x3308
#define 	FIFO_MAC4 		0x4308
#define 	FIFO_MAC5 		0x5308
#define 	FIFO_MAC6 		0x6308
#define 	FIFO_MAC7 		0x7308
#define 	FIFO_MAC8 		0x8308
#define 	FIFO_MAC9 		0x9308
#define 	FIFO_MAC10		0xA308
#define 	FIFO_MAC11		0xB308
#define 	FIFO_MAC12		0xC308
#define 	FIFO_MAC13		0xD308
#define 	FIFO_MAC14		0xE308
#define 	FIFO_MAC15		0xF308
//----------- FIFO_User Address Definition -----------
#define 	FIFO_User0		0x030A
#define 	FIFO_User1		0x130A
#define 	FIFO_User2		0x230A
#define 	FIFO_User3		0x330A
#define 	FIFO_User4 		0x430A
#define 	FIFO_User5 		0x530A
#define 	FIFO_User6 		0x630A
#define 	FIFO_User7 		0x730A
#define 	FIFO_User8 		0x830A
#define 	FIFO_User9 		0x930A
#define 	FIFO_User10		0xA30A
#define 	FIFO_User11		0xB30A
#define 	FIFO_User12		0xC30A
#define 	FIFO_User13		0xD30A
#define 	FIFO_User14		0xE30A
#define 	FIFO_User15		0xF30A
//----------- FIFO_User Address Definition -----------
#define 	FIFO_Rst_Card0	0x030C
#define 	FIFO_Rst_Card1 	0x130C
#define 	FIFO_Rst_Card2	0x230C
#define 	FIFO_Rst_Card3	0x330C
#define 	FIFO_Rst_Card4	0x430C
#define 	FIFO_Rst_Card5	0x530C
#define 	FIFO_Rst_Card6	0x630C
#define 	FIFO_Rst_Card7	0x730C
#define 	FIFO_Rst_Card8	0x830C
#define 	FIFO_Rst_Card9	0x930C
#define 	FIFO_Rst_Card10 0xA30C
#define 	FIFO_Rst_Card11	0xB30C
#define 	FIFO_Rst_Card12	0xC30C
#define 	FIFO_Rst_Card13	0xD30C
#define 	FIFO_Rst_Card14	0xE30C
#define 	FIFO_Rst_Card15	0xF30C



#define 	My_STBUS 		8
#define    	BYTE            unsigned char
#define    	WORD            unsigned int
#define		Esc			0x1B

long		i;
int		day;
int		month;
int		year;
int		sec;
int		min;
int		hour;
unsigned int	In_char;
unsigned int 	InputData;
unsigned int 	FIFO_NWK0_Data;
unsigned int 	FIFO_NWK1_Data;
unsigned int 	FIFO_NWK2_Data;
unsigned int 	FIFO_NWK3_Data;
unsigned int 	FIFO_NWK4_Data;
unsigned int 	FIFO_NWK5_Data;
unsigned int 	FIFO_NWK6_Data;
unsigned int 	FIFO_NWK7_Data;
unsigned int 	FIFO_NWK8_Data;
unsigned int 	FIFO_NWK9_Data;
unsigned int 	FIFO_NWK10_Data;
unsigned int 	FIFO_NWK11_Data;
unsigned int 	FIFO_NWK12_Data;
unsigned int 	FIFO_NWK13_Data;
unsigned int 	FIFO_NWK14_Data;
unsigned int 	FIFO_NWK15_Data;
unsigned int 	FIFO_MAC0_Data;
unsigned int 	FIFO_MAC1_Data;
unsigned int 	FIFO_MAC2_Data;
unsigned int 	FIFO_MAC3_Data;
unsigned int 	FIFO_MAC4_Data;
unsigned int 	FIFO_MAC5_Data;
unsigned int 	FIFO_MAC6_Data;
unsigned int 	FIFO_MAC7_Data;
unsigned int 	FIFO_MAC8_Data;
unsigned int 	FIFO_MAC9_Data;
unsigned int 	FIFO_MAC10_Data;
unsigned int 	FIFO_MAC11_Data;
unsigned int 	FIFO_MAC12_Data;
unsigned int 	FIFO_MAC13_Data;
unsigned int 	FIFO_MAC14_Data;
unsigned int 	FIFO_MAC15_Data;
unsigned int 	FIFO_User0_Data;
unsigned int 	FIFO_User1_Data;
unsigned int 	FIFO_User2_Data;
unsigned int 	FIFO_User3_Data;
unsigned int 	FIFO_User4_Data;
unsigned int 	FIFO_User5_Data;
unsigned int 	FIFO_User6_Data;
unsigned int 	FIFO_User7_Data;
unsigned int 	FIFO_User8_Data;
unsigned int 	FIFO_User9_Data;
unsigned int 	FIFO_User10_Data;
unsigned int 	FIFO_User11_Data;
unsigned int 	FIFO_User12_Data;
unsigned int 	FIFO_User13_Data;
unsigned int 	FIFO_User14_Data;
unsigned int 	FIFO_User15_Data;
unsigned int		Status0;
unsigned int		Status1;
unsigned int		Status2;
unsigned int		Status3;
unsigned int		Status4;
unsigned int		Status5;
unsigned int		Status6;
unsigned int		Status7;
unsigned int		Status8;
unsigned int		Status9;
unsigned int		Status10;
unsigned int		Status11;
unsigned int		Status12;
unsigned int		Status13;
unsigned int		Status14;
unsigned int		Status15;
unsigned int	FIFO_NWK0_Error;
unsigned int	FIFO_NWK1_Error;
unsigned int	FIFO_NWK2_Error;
unsigned int	FIFO_NWK3_Error;
unsigned int	FIFO_NWK4_Error;
unsigned int	FIFO_NWK5_Error;
unsigned int	FIFO_NWK6_Error;
unsigned int	FIFO_NWK7_Error;
unsigned int	FIFO_NWK8_Error;
unsigned int	FIFO_NWK9_Error;
unsigned int	FIFO_NWK10_Error;
unsigned int	FIFO_NWK11_Error;
unsigned int	FIFO_NWK12_Error;
unsigned int	FIFO_NWK13_Error;
unsigned int	FIFO_NWK14_Error;
unsigned int	FIFO_NWK15_Error;
unsigned int	FIFO_MAC0_Error;
unsigned int	FIFO_MAC1_Error;
unsigned int	FIFO_MAC2_Error;
unsigned int	FIFO_MAC3_Error;
unsigned int	FIFO_MAC4_Error;
unsigned int	FIFO_MAC5_Error;
unsigned int	FIFO_MAC6_Error;
unsigned int	FIFO_MAC7_Error;
unsigned int	FIFO_MAC8_Error;
unsigned int	FIFO_MAC9_Error;
unsigned int	FIFO_MAC10_Error;
unsigned int	FIFO_MAC11_Error;
unsigned int	FIFO_MAC12_Error;
unsigned int	FIFO_MAC13_Error;
unsigned int	FIFO_MAC14_Error;
unsigned int	FIFO_MAC15_Error;
unsigned int	FIFO_User0_Error;
unsigned int	FIFO_User1_Error;
unsigned int	FIFO_User2_Error;
unsigned int	FIFO_User3_Error;
unsigned int	FIFO_User4_Error;
unsigned int	FIFO_User5_Error;
unsigned int	FIFO_User6_Error;
unsigned int	FIFO_User7_Error;
unsigned int	FIFO_User8_Error;
unsigned int	FIFO_User9_Error;
unsigned int	FIFO_User10_Error;
unsigned int	FIFO_User11_Error;
unsigned int	FIFO_User12_Error;
unsigned int	FIFO_User13_Error;
unsigned int	FIFO_User14_Error;
unsigned int	FIFO_User15_Error;
int		CardNum;
unsigned int    Retry;
unsigned int 	FIFO_NWK_Error;
unsigned int 	FIFO_MAC_Error;
unsigned int 	FIFO_User_Error;
unsigned int 	FIFO_NWK_Data;
unsigned int 	FIFO_MAC_Data;
unsigned int 	FIFO_User_Data;

struct 	date d;
struct  time t;
ofstream outfile("Report.txt",ios::trunc);

	void Display(int CardNum,unsigned int FIFO_Empty_Status,unsigned int FIFO_NWK,unsigned int FIFO_MAC,unsigned int FIFO_User,
		     unsigned int FIFO_NWK_Data,unsigned int FIFO_MAC_Data,unsigned int FIFO_User_Data)
		 //    unsigned int FIFO_NWK_Error,unsigned int FIFO_MAC_Error,unsigned int FIFO_User_Error)
	{
//			  	ifstream infile ("Input.txt",ios::in);
//				infile	>> InputData;
				InputData = (random(0xff)<< 8)+(random(0xff));
				outport(FIFO_NWK,InputData);
				outport(FIFO_MAC,InputData);
				outport(FIFO_User,InputData);
				Retry = 0;
				while(inport(FIFO_Empty_Status) != 0x0000)
				{
				Retry = Retry + 1;
				if (Retry == 5) break;
				}
				FIFO_NWK_Data  = inport(FIFO_NWK);
				FIFO_MAC_Data  = inport(FIFO_MAC);
				FIFO_User_Data = inport(FIFO_User);
				if (FIFO_NWK_Data != InputData)
				{
					FIFO_NWK_Error = FIFO_NWK_Error + 1;
					gettime(&t);
					getdate(&d);
					day   = d.da_day;
					month = d.da_mon;
					year  = d.da_year;
					sec   = t.ti_sec;
					min   = t.ti_min;
					hour  = t.ti_hour;
					gotoxy((wherex()-1),wherey());
					printf("\rError found in Network_FIFO of card %d at: %d/%d/%d , %d:%d:%d  ",CardNum,d.da_mon,d.da_day,d.da_year,t.ti_hour, t.ti_min, t.ti_sec);
					printf("\nInput Data = %x \t Output Data = %x\n",InputData,FIFO_NWK_Data);

					outfile	<< ("\n");
					outfile	<< ("Error found in NWK_FIFO of card ");
					outfile << ("%d",CardNum);
					outfile << (" at: ");
					outfile	<< ("%d",month);
					outfile	<< ("/");
					outfile	<< ("%d",day);
					outfile	<< ("/");
					outfile	<< ("%d",year);
					outfile	<< (",");
					outfile << ("%d",hour);
					outfile	<< (":");
					outfile << ("%d",min);
					outfile	<< (":");
					outfile << ("%d",sec);
					outfile << ("\n");
					outfile << ("Input Data =");
					outfile << ("%d",InputData);
					outfile << ("\t");
					outfile << ("Output Data =");
					outfile << ("%d",FIFO_NWK_Data);
					outfile << ("\n");
					printf("\nTest process is running... ");
				 }
				if (FIFO_MAC_Data != InputData)
				{
					FIFO_MAC_Error = FIFO_MAC_Error + 1;
					gettime(&t);
					getdate(&d);
					day   = d.da_day;
					month = d.da_mon;
					year  = d.da_year;
					sec   = t.ti_sec;
					min   = t.ti_min;
					hour  = t.ti_hour;
					gotoxy((wherex()-1),wherey());
					printf("\rError found in MAC_FIFO of card %d at: %d/%d/%d , %d:%d:%d  ",CardNum,d.da_mon,d.da_day,d.da_year,t.ti_hour, t.ti_min, t.ti_sec);
					printf("\nInput Data = %x \t Output Data = %x\n",InputData,FIFO_MAC_Data);

					outfile	<< ("\n");
					outfile	<< ("Error found in MAC_FIFO of card ");
					outfile << ("%d",CardNum);
					outfile << (" at: ");
					outfile	<< ("%d",month);
					outfile	<< ("/");
					outfile	<< ("%d",day);
					outfile	<< ("/");
					outfile	<< ("%d",year);
					outfile	<< (",");
					outfile << ("%d",hour);
					outfile	<< (":");
					outfile << ("%d",min);
					outfile	<< (":");
					outfile << ("%d",sec);
					outfile << ("\n");
					outfile << ("Input Data =");
					outfile << ("%d",InputData);
					outfile << ("\t");
					outfile << ("Output Data =");
					outfile << ("%d",FIFO_MAC_Data);
					outfile << ("\n");
					printf("\nTest process is running... ");
				 }
				if (FIFO_User_Data != InputData)
				{
					FIFO_User_Error = FIFO_User_Error + 1;
					gettime(&t);
					getdate(&d);
					day   = d.da_day;
					month = d.da_mon;
					year  = d.da_year;
					sec   = t.ti_sec;
					min   = t.ti_min;
					hour  = t.ti_hour;
					gotoxy((wherex()-1),wherey());
					printf("\rError found in User_FIFO of card %d at: %d/%d/%d , %d:%d:%d  ",CardNum,d.da_mon,d.da_day,d.da_year,t.ti_hour, t.ti_min, t.ti_sec);
					printf("\nInput Data = %x \t Output Data = %x\n",InputData,FIFO_User_Data);

					outfile	<< ("\n");
					outfile	<< ("Error found in User_FIFO of card ");
					outfile << ("%d",CardNum);
					outfile << (" at: ");
					outfile	<< ("%d",month);
					outfile	<< ("/");
					outfile	<< ("%d",day);
					outfile	<< ("/");
					outfile	<< ("%d",year);
					outfile	<< (",");
					outfile << ("%d",hour);
					outfile	<< (":");
					outfile << ("%d",min);
					outfile	<< (":");
					outfile << ("%d",sec);
					outfile << ("\n");
					outfile << ("Input Data =");
					outfile << ("%d",InputData);
					outfile << ("\t");
					outfile << ("Output Data =");
					outfile << ("%d",FIFO_User_Data);
					outfile << ("\n");
					printf("\nTest process is running... ");
				 }
	}

void main(void){
i	        = 0;
Status0		= 0;
Status1		= 0;
Status2		= 0;
Status3		= 0;
Status4		= 0;
Status5		= 0;
Status6		= 0;
Status7		= 0;
Status8		= 0;
Status9		= 0;
Status10	= 0;
Status11	= 0;
Status12	= 0;
Status13	= 0;
Status14	= 0;
Status15	= 0;
FIFO_NWK0_Error = 0;
FIFO_NWK1_Error = 0;
FIFO_NWK2_Error = 0;
FIFO_NWK3_Error = 0;
FIFO_NWK4_Error = 0;
FIFO_NWK5_Error = 0;
FIFO_NWK6_Error = 0;
FIFO_NWK7_Error = 0;
FIFO_NWK8_Error = 0;
FIFO_NWK9_Error = 0;
FIFO_NWK10_Error = 0;
FIFO_NWK11_Error = 0;
FIFO_NWK12_Error = 0;
FIFO_NWK13_Error = 0;
FIFO_NWK14_Error = 0;
FIFO_NWK15_Error = 0;
FIFO_MAC0_Error = 0;
FIFO_MAC1_Error = 0;
FIFO_MAC2_Error = 0;
FIFO_MAC3_Error = 0;
FIFO_MAC4_Error = 0;
FIFO_MAC5_Error = 0;
FIFO_MAC6_Error = 0;
FIFO_MAC7_Error = 0;
FIFO_MAC8_Error = 0;
FIFO_MAC9_Error = 0;
FIFO_MAC10_Error = 0;
FIFO_MAC11_Error = 0;
FIFO_MAC12_Error = 0;
FIFO_MAC13_Error = 0;
FIFO_MAC14_Error = 0;
FIFO_MAC15_Error = 0;
FIFO_User0_Error = 0;
FIFO_User1_Error = 0;
FIFO_User2_Error = 0;
FIFO_User3_Error = 0;
FIFO_User4_Error = 0;
FIFO_User5_Error = 0;
FIFO_User6_Error = 0;
FIFO_User7_Error = 0;
FIFO_User8_Error = 0;
FIFO_User9_Error = 0;
FIFO_User10_Error = 0;
FIFO_User11_Error = 0;
FIFO_User12_Error = 0;
FIFO_User13_Error = 0;
FIFO_User14_Error = 0;
FIFO_User15_Error = 0;
FIFO_NWK_Data	  = 0;
FIFO_MAC_Data	  = 0;
FIFO_User_Data	  = 0;
FIFO_NWK_Error	  = 0;
FIFO_MAC_Error	  = 0;
FIFO_User_Error	  = 0;

//	ofstream outfile("Report.txt",ios::trunc);

	randomize();
	Status0  = inport(STATUS_ADD0);
	Status1  = inport(STATUS_ADD1);
	Status2  = inport(STATUS_ADD2);
	Status3  = inport(STATUS_ADD3);
	Status4  = inport(STATUS_ADD4);
	Status5  = inport(STATUS_ADD5);
	Status6  = inport(STATUS_ADD6);
	Status7  = inport(STATUS_ADD7);
	Status8  = inport(STATUS_ADD8);
	Status9  = inport(STATUS_ADD9);
	Status10 = inport(STATUS_ADD10);
	Status11 = inport(STATUS_ADD11);
	Status12 = inport(STATUS_ADD12);
	Status13 = inport(STATUS_ADD13);
	Status14 = inport(STATUS_ADD14);
	Status15 = inport(STATUS_ADD15);
	clrscr();
	printf("\nAttached BSC cards:\t ");
	if (Status0 == 0xD25C) printf("0  ");
	if (Status1 == 0xD25C) printf("1  ");
	if (Status2 == 0xD25C) printf("2  ");
	if (Status3 == 0xD25C) printf("3  ");
	if (Status4 == 0xD25C) printf("4  ");
	if (Status5 == 0xD25C) printf("5  ");
	if (Status6 == 0xD25C) printf("6  ");
	if (Status7 == 0xD25C) printf("7  ");
	if (Status8 == 0xD25C) printf("8  ");
	if (Status9 == 0xD25C) printf("9  ");
	if (Status10== 0xD25C) printf("10 ");
	if (Status11== 0xD25C) printf("11 ");
	if (Status12== 0xD25C) printf("12 ");
	if (Status13== 0xD25C) printf("13 ");
	if (Status14== 0xD25C) printf("14 ");
	if (Status15== 0xD25C) printf("15 ");

	printf("\nPress T to start test process or Esc to exit...");
	struct 	date d;
	struct  time t;
label1:	In_char = getch();
	if (In_char == 't' | In_char == 'T')
	{
		gettime(&t);
		getdate(&d);
		day   = d.da_day;
		month = d.da_mon;
		year  = d.da_year;
		sec   = t.ti_sec;
		min   = t.ti_min;
		hour  = t.ti_hour;
		printf("\rTest process started at: %d/%d/%d , %d:%d:%d\t\n",d.da_mon,d.da_day,d.da_year,t.ti_hour, t.ti_min, t.ti_sec);

		outfile	<< ("Test process started at: ");
		outfile	<< ("%d",month);
		outfile	<< ("/");
		outfile	<< ("%d",day);
		outfile	<< ("/");
		outfile	<< ("%d",year);
		outfile	<< (" , ");
		outfile << ("%d",hour);
		outfile	<< (":");
		outfile << ("%d",min);
		outfile	<< (":");
		outfile << ("%d",sec);
		outfile	<< ("\n");

		printf("\nTest process is running... ");
		do
		{
			if (i%9000==0)
			{
				i=0;
				gotoxy((wherex()-1),wherey());
				cprintf("/");
			}
			else if (i%9000==3000)
			{
				gotoxy((wherex()-1),wherey());
				cprintf("-");
			}
			else if (i%9000==6000)
			{
				gotoxy((wherex()-1),wherey());
				cprintf("\\");
			}
			i = i + 1;
			if (Status0 == 0xD25C | Status1 == 0xD25C | Status2 == 0xD25C | Status3 == 0xD25C |
				Status4 == 0xD25C |	Status5 == 0xD25C | Status6 == 0xD25C | Status7 == 0xD25C |
				Status8 == 0xD25C | Status9 == 0xD25C |	Status10== 0xD25C | Status11== 0xD25C |
				Status12== 0xD25C | Status13== 0xD25C | Status14== 0xD25C |	Status15== 0xD25C)
			{
			if (Status0 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK0_Error;
				FIFO_MAC_Error = FIFO_MAC0_Error;
				FIFO_User_Error = FIFO_User0_Error;
				Display(0,0x0304,FIFO_NWK0,FIFO_MAC0,FIFO_User0,FIFO_NWK0_Data,FIFO_MAC0_Data,FIFO_User0_Data);
//					FIFO_NWK0_Error,FIFO_MAC0_Error,FIFO_User0_Error);
				FIFO_NWK0_Error = FIFO_NWK_Error;
				FIFO_MAC0_Error = FIFO_MAC_Error;
				FIFO_User0_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card0,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status0 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status1 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK1_Error;
				FIFO_MAC_Error = FIFO_MAC1_Error;
				FIFO_User_Error = FIFO_User1_Error;
				Display(1,0x1304,FIFO_NWK1,FIFO_MAC1,FIFO_User1,FIFO_NWK1_Data,FIFO_MAC1_Data,FIFO_User1_Data);
//					FIFO_NWK1_Error,FIFO_MAC1_Error,FIFO_User1_Error);
				FIFO_NWK1_Error = FIFO_NWK_Error;
				FIFO_MAC1_Error = FIFO_MAC_Error;
				FIFO_User1_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card1,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status1 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status2 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK2_Error;
				FIFO_MAC_Error = FIFO_MAC2_Error;
				FIFO_User_Error = FIFO_User2_Error;
				Display(2,0x2304,FIFO_NWK2,FIFO_MAC2,FIFO_User2,FIFO_NWK2_Data,FIFO_MAC2_Data,FIFO_User2_Data);
//					FIFO_NWK2_Error,FIFO_MAC2_Error,FIFO_User2_Error);
				FIFO_NWK2_Error = FIFO_NWK_Error;
				FIFO_MAC2_Error = FIFO_MAC_Error;
				FIFO_User2_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card2,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status2 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status3 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK3_Error;
				FIFO_MAC_Error = FIFO_MAC3_Error;
				FIFO_User_Error = FIFO_User3_Error;
				Display(3,0x3304,FIFO_NWK3,FIFO_MAC3,FIFO_User3,FIFO_NWK3_Data,FIFO_MAC3_Data,FIFO_User3_Data);
//					FIFO_NWK3_Error,FIFO_MAC3_Error,FIFO_User3_Error);
				FIFO_NWK3_Error = FIFO_NWK_Error;
				FIFO_MAC3_Error = FIFO_MAC_Error;
				FIFO_User3_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card3,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status3 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status4 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK4_Error;
				FIFO_MAC_Error = FIFO_MAC4_Error;
				FIFO_User_Error = FIFO_User4_Error;
				Display(4,0x4304,FIFO_NWK4,FIFO_MAC4,FIFO_User4,FIFO_NWK4_Data,FIFO_MAC4_Data,FIFO_User4_Data);
//					FIFO_NWK4_Error,FIFO_MAC4_Error,FIFO_User4_Error);
				FIFO_NWK4_Error = FIFO_NWK_Error;
				FIFO_MAC4_Error = FIFO_MAC_Error;
				FIFO_User4_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card4,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status4 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status5 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK5_Error;
				FIFO_MAC_Error = FIFO_MAC5_Error;
				FIFO_User_Error = FIFO_User5_Error;
				Display(5,0x5304,FIFO_NWK5,FIFO_MAC5,FIFO_User5,FIFO_NWK5_Data,FIFO_MAC5_Data,FIFO_User5_Data);
//					FIFO_NWK5_Error,FIFO_MAC5_Error,FIFO_User5_Error);
				FIFO_NWK5_Error = FIFO_NWK_Error;
				FIFO_MAC5_Error = FIFO_MAC_Error;
				FIFO_User5_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card5,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status5 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status6 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK6_Error;
				FIFO_MAC_Error = FIFO_MAC6_Error;
				FIFO_User_Error = FIFO_User6_Error;
				Display(6,0x6304,FIFO_NWK6,FIFO_MAC6,FIFO_User6,FIFO_NWK6_Data,FIFO_MAC6_Data,FIFO_User6_Data);
//					FIFO_NWK6_Error,FIFO_MAC6_Error,FIFO_User6_Error);
				FIFO_NWK6_Error = FIFO_NWK_Error;
				FIFO_MAC6_Error = FIFO_MAC_Error;
				FIFO_User6_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card6,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status6 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status7 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK7_Error;
				FIFO_MAC_Error = FIFO_MAC7_Error;
				FIFO_User_Error = FIFO_User7_Error;
				Display(7,0x7304,FIFO_NWK7,FIFO_MAC7,FIFO_User7,FIFO_NWK7_Data,FIFO_MAC7_Data,FIFO_User7_Data);
//					FIFO_NWK7_Error,FIFO_MAC7_Error,FIFO_User7_Error);
				FIFO_NWK7_Error = FIFO_NWK_Error;
				FIFO_MAC7_Error = FIFO_MAC_Error;
				FIFO_User7_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card7,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status7 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status8 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK8_Error;
				FIFO_MAC_Error = FIFO_MAC8_Error;
				FIFO_User_Error = FIFO_User8_Error;
				Display(8,0x8304,FIFO_NWK8,FIFO_MAC8,FIFO_User8,FIFO_NWK8_Data,FIFO_MAC8_Data,FIFO_User8_Data);
//					FIFO_NWK8_Error,FIFO_MAC8_Error,FIFO_User8_Error);
				FIFO_NWK8_Error = FIFO_NWK_Error;
				FIFO_MAC8_Error = FIFO_MAC_Error;
				FIFO_User8_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card8,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status8 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status9 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK9_Error;
				FIFO_MAC_Error = FIFO_MAC9_Error;
				FIFO_User_Error = FIFO_User9_Error;
				Display(9,0x9304,FIFO_NWK9,FIFO_MAC9,FIFO_User9,FIFO_NWK9_Data,FIFO_MAC9_Data,FIFO_User9_Data);
//					FIFO_NWK9_Error,FIFO_MAC9_Error,FIFO_User9_Error);
				FIFO_NWK9_Error = FIFO_NWK_Error;
				FIFO_MAC9_Error = FIFO_MAC_Error;
				FIFO_User9_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card9,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status9 = 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status10 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK10_Error;
				FIFO_MAC_Error = FIFO_MAC10_Error;
				FIFO_User_Error = FIFO_User10_Error;
				Display(10,0xA304,FIFO_NWK10,FIFO_MAC10,FIFO_User10,FIFO_NWK10_Data,FIFO_MAC10_Data,FIFO_User10_Data);
//					FIFO_NWK10_Error,FIFO_MAC10_Error,FIFO_User10_Error);
				FIFO_NWK10_Error = FIFO_NWK_Error;
				FIFO_MAC10_Error = FIFO_MAC_Error;
				FIFO_User10_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card10,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status10= 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status11 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK11_Error;
				FIFO_MAC_Error = FIFO_MAC11_Error;
				FIFO_User_Error = FIFO_User11_Error;
				Display(11,0xB304,FIFO_NWK11,FIFO_MAC11,FIFO_User11,FIFO_NWK11_Data,FIFO_MAC11_Data,FIFO_User11_Data);
//					FIFO_NWK11_Error,FIFO_MAC11_Error,FIFO_User11_Error);
				FIFO_NWK11_Error = FIFO_NWK_Error;
				FIFO_MAC11_Error = FIFO_MAC_Error;
				FIFO_User11_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card11,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status11= 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status12 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK12_Error;
				FIFO_MAC_Error = FIFO_MAC12_Error;
				FIFO_User_Error = FIFO_User12_Error;
				Display(12,0xC304,FIFO_NWK12,FIFO_MAC12,FIFO_User12,FIFO_NWK12_Data,FIFO_MAC12_Data,FIFO_User12_Data);
//					FIFO_NWK12_Error,FIFO_MAC12_Error,FIFO_User12_Error);
				FIFO_NWK12_Error = FIFO_NWK_Error;
				FIFO_MAC12_Error = FIFO_MAC_Error;
				FIFO_User12_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card12,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status12= 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status13 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK13_Error;
				FIFO_MAC_Error = FIFO_MAC13_Error;
				FIFO_User_Error = FIFO_User13_Error;
				Display(13,0xD304,FIFO_NWK13,FIFO_MAC13,FIFO_User13,FIFO_NWK13_Data,FIFO_MAC13_Data,FIFO_User13_Data);
//					FIFO_NWK13_Error,FIFO_MAC13_Error,FIFO_User13_Error);
				FIFO_NWK13_Error = FIFO_NWK_Error;
				FIFO_MAC13_Error = FIFO_MAC_Error;
				FIFO_User13_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card13,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status13= 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status14 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK14_Error;
				FIFO_MAC_Error = FIFO_MAC14_Error;
				FIFO_User_Error = FIFO_User14_Error;
				Display(14,0xE304,FIFO_NWK14,FIFO_MAC14,FIFO_User14,FIFO_NWK14_Data,FIFO_MAC14_Data,FIFO_User14_Data);
//					FIFO_NWK14_Error,FIFO_MAC14_Error,FIFO_User14_Error);
				FIFO_NWK14_Error = FIFO_NWK_Error;
				FIFO_MAC14_Error = FIFO_MAC_Error;
				FIFO_User14_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card14,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status14= 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}
			if (Status15 == 0xD25C)
			{
				FIFO_NWK_Error = FIFO_NWK15_Error;
				FIFO_MAC_Error = FIFO_MAC15_Error;
				FIFO_User_Error = FIFO_User15_Error;
				Display(15,0xF304,FIFO_NWK15,FIFO_MAC15,FIFO_User15,FIFO_NWK15_Data,FIFO_MAC15_Data,FIFO_User15_Data);
//					FIFO_NWK15_Error,FIFO_MAC15_Error,FIFO_User15_Error);
				FIFO_NWK15_Error = FIFO_NWK_Error;
				FIFO_MAC15_Error = FIFO_MAC_Error;
				FIFO_User15_Error= FIFO_User_Error;
				outport (FIFO_Rst_Card15,0x0F0F);
				 if (FIFO_NWK_Error==0xFFFF|FIFO_MAC_Error==0xFFFF|FIFO_User_Error==0xFFFF)
				 {
					gotoxy((wherex()-1),wherey());
					cprintf(" ");
					textcolor(LIGHTRED);
					cprintf("\rError Overflow !            ");
					Status15= 40;
					textcolor(7);
					cprintf("\n\n\rTest process is running... ");
				  }
			}

			}
			else if (Status0 == 40 | Status1 == 40 | Status2 == 40 | Status3 == 40 | Status4 == 40 |
					 Status5 == 40 | Status6 == 40 | Status7 == 40 | Status8 == 40 | Status9 == 40 |
					 Status10== 40 | Status11== 40 | Status12== 40 | Status13== 40 | Status14== 40 | Status15== 40)
				goto label5;
			else
				goto label4;
		}while (!kbhit());
label5:		gotoxy((wherex()-1),wherey());
		cprintf(" ");
		gettime(&t);
		getdate(&d);
		day   = d.da_day;
		month = d.da_mon;
		year  = d.da_year;
		sec   = t.ti_sec;
		min   = t.ti_min;
		hour  = t.ti_hour;
		printf("\n\nTest process stopped at: %d/%d/%d , %d:%d:%d\n",d.da_mon,d.da_day,d.da_year,t.ti_hour, t.ti_min, t.ti_sec);

		outfile	<< ("\n");
		outfile	<< ("Test process stopped at: ");
		outfile	<< ("%d",month);
		outfile	<< ("/");
		outfile	<< ("%d",day);
		outfile	<< ("/");
		outfile	<< ("%d",year);
		outfile	<< (" , ");
		outfile << ("%d",hour);
		outfile	<< (":");
		outfile << ("%d",min);
		outfile	<< (":");
		outfile << ("%d",sec);
		outfile << ("\n");

		if (Status2 == 0xD25C | Status2 == 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 2nd card was : ");
			outfile << ("%d",FIFO_NWK2_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 2nd card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK2_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 2nd card was : ");
			outfile << ("%d",FIFO_MAC2_Error);
			printf("\nNumber of errors in MAC_FIFO test of 2nd card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC2_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 2nd card was : ");
			outfile << ("%d",FIFO_User2_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 2nd card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User2_Error);
		}

		if (Status3 == 0xD25C | Status3 == 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 3rd card was : ");
			outfile << ("%d",FIFO_NWK3_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 3rd card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK3_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 3rd card was : ");
			outfile << ("%d",FIFO_MAC3_Error);
			printf("\nNumber of errors in MAC_FIFO test of 3rd card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC3_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 3rd card was : ");
			outfile << ("%d",FIFO_User3_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 3rd card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User3_Error);
		}

		if (Status4 == 0xD25C | Status4 == 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 4th card was : ");
			outfile << ("%d",FIFO_NWK4_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 4th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK4_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 4th card was : ");
			outfile << ("%d",FIFO_MAC4_Error);
			printf("\nNumber of errors in MAC_FIFO test of 4th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC4_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 4th card was : ");
			outfile << ("%d",FIFO_User4_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 4th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User4_Error);
		}

		if (Status5 == 0xD25C | Status5 == 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 5th card was : ");
			outfile << ("%d",FIFO_NWK5_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 5th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK5_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 5th card was : ");
			outfile << ("%d",FIFO_MAC5_Error);
			printf("\nNumber of errors in MAC_FIFO test of 5th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC5_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 5th card was : ");
			outfile << ("%d",FIFO_User5_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 5th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User5_Error);
		}

		if (Status6 == 0xD25C | Status6 == 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 6th card was : ");
			outfile << ("%d",FIFO_NWK6_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 6th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK6_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 6th card was : ");
			outfile << ("%d",FIFO_MAC6_Error);
			printf("\nNumber of errors in MAC_FIFO test of 6th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC6_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 6th card was : ");
			outfile << ("%d",FIFO_User6_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 6th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User6_Error);
		}

		if (Status7 == 0xD25C | Status7 == 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 7th card was : ");
			outfile << ("%d",FIFO_NWK7_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 7th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK7_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 7th card was : ");
			outfile << ("%d",FIFO_MAC7_Error);
			printf("\nNumber of errors in MAC_FIFO test of 7th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC7_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 7th card was : ");
			outfile << ("%d",FIFO_User7_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 7th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User7_Error);
		}

		if (Status8 == 0xD25C | Status8 == 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 8th card was : ");
			outfile << ("%d",FIFO_NWK8_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 8th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK8_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 8th card was : ");
			outfile << ("%d",FIFO_MAC8_Error);
			printf("\nNumber of errors in MAC_FIFO test of 8th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC8_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 8th card was : ");
			outfile << ("%d",FIFO_User8_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 8th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User8_Error);
		}

		if (Status9 == 0xD25C | Status9 == 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 9th card was : ");
			outfile << ("%d",FIFO_NWK9_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 9th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK9_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 9th card was : ");
			outfile << ("%d",FIFO_MAC9_Error);
			printf("\nNumber of errors in MAC_FIFO test of 9th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC9_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 9th card was : ");
			outfile << ("%d",FIFO_User9_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 9th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User9_Error);
		}

		if (Status10== 0xD25C | Status10== 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 10th card was : ");
			outfile << ("%d",FIFO_NWK10_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 10th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK10_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 10th card was : ");
			outfile << ("%d",FIFO_MAC10_Error);
			printf("\nNumber of errors in MAC_FIFO test of 10th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC10_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 10th card was : ");
			outfile << ("%d",FIFO_User10_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 10th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User10_Error);
		}

		if (Status11== 0xD25C | Status11== 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 11th card was : ");
			outfile << ("%d",FIFO_NWK11_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 11th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK11_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 11th card was : ");
			outfile << ("%d",FIFO_MAC11_Error);
			printf("\nNumber of errors in MAC_FIFO test of 11th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC11_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 11th card was : ");
			outfile << ("%d",FIFO_User11_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 11th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User11_Error);
		}

		if (Status12== 0xD25C | Status12== 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 12th card was : ");
			outfile << ("%d",FIFO_NWK12_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 12th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK12_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 12th card was : ");
			outfile << ("%d",FIFO_MAC12_Error);
			printf("\nNumber of errors in MAC_FIFO test of 12th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC12_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 12th card was : ");
			outfile << ("%d",FIFO_User12_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 12th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User12_Error);
		}

		if (Status13== 0xD25C | Status13== 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 13th card was : ");
			outfile << ("%d",FIFO_NWK13_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 13th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK13_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 13th card was : ");
			outfile << ("%d",FIFO_MAC13_Error);
			printf("\nNumber of errors in MAC_FIFO test of 13th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC13_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 13th card was : ");
			outfile << ("%d",FIFO_User13_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 13th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User13_Error);
		}

		if (Status14== 0xD25C | Status14== 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 14th card was : ");
			outfile << ("%d",FIFO_NWK14_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 14th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK14_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 14th card was : ");
			outfile << ("%d",FIFO_MAC14_Error);
			printf("\nNumber of errors in MAC_FIFO test of 14th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC14_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 14th card was : ");
			outfile << ("%d",FIFO_User14_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 14th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User14_Error);
		}

		if (Status15== 0xD25C | Status15== 40)
		{
			outfile << ("\nNumber of errors for NWK_FIFO test of 15th card was : ");
			outfile << ("%d",FIFO_NWK15_Error);
			printf("\n\n\rNumber of errors in NWK_FIFO test of 15th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_NWK15_Error);

			outfile << ("\nNumber of errors for MAC_FIFO test of 15th card was : ");
			outfile << ("%d",FIFO_MAC15_Error);
			printf("\nNumber of errors in MAC_FIFO test of 15th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_MAC15_Error);

			outfile << ("\nNumber of errors for User_FIFO test of 15th card was : ");
			outfile << ("%d",FIFO_User15_Error);
			outfile << ("\n");
			printf("\nNumber of errors in User_FIFO test of 15th card was\t: ");
			textcolor(RED);
			cprintf("%u",FIFO_User15_Error);
		}

	}

	else if (In_char == Esc)
	{
		cprintf("\n\n\rAction cancelled by user.");
		goto End;
	}
	else goto label1;

label2:		In_char = getch();
		if (In_char == Esc)
		goto End;
		else goto label2;

label4:		clrscr();
		i = 0;
label3:		do
		{
		if ((i%100000)==0)
		{
			i=0;
			gotoxy(25,10);
//			textbackground(0);
			textcolor(YELLOW);
			cprintf("NO ATTACHED CARD DETECTED!");
		}
		else if ((i%100000)==70000)
		{
			gotoxy(25,10);
//			textbackground(0);
			cprintf("                          ");
		 }
		i = i + 1;
		}while (!kbhit());

		In_char = getch();
		if (In_char == Esc)
		{
			outfile	<< ("NO ATTACHED CARD DETECTED.");
			gotoxy(25,10);
			textcolor(7);
			cprintf("                          ");
			cprintf("\r");
			goto End;
		}
		else goto label3;
End:
}