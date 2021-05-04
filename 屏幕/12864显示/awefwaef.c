    #include <reg52.h>
    #include <intrins.h>
    #define uchar unsigned char
    #define uint unsigned int
    #define  LcdData P0
    sbit RS=P2^6; //���е�ָ��/����ѡ���ź�, H����, L����
    sbit RW=P2^5; //���ж�дѡ���ź�, H��, Lд
    sbit E=P2^7; //����ʹ�ܶ�, H��Ч, L��Ч
    sbit PSB=P3^2; //��/���ӿ�ѡ��, H��,L��
    sbit RET=P3^4; //��λ, L��Ч
		uchar v=16;
    /*************************************
    ��LCD��д��ָ�����
    **************************************/
    void Lcd_WriteCmd(unsigned char CmdCode)
    {  
     
       
    
     RS=0;
            RW=0;
            E=0;
            _nop_();  
         _nop_();
            LcdData=CmdCode;
            _nop_(); 
         _nop_();
            E=1;
            _nop_();  
         _nop_();
            E=0;
        }
        /*��ʱ����*/
        void delayms(uint x)
        {
         uint i,j;
         for(i=x;i>0;i--)
           for(j=110;j>0;j--);
        }
        /*********************************
        ��LCDд���ֽ�����
        **********************************/
        void Lcd_WriteData(unsigned char Data)
        {  
         
         RS=1;
         RW=0;
         E=0;
       

  _nop_();  
     _nop_(); 
     LcdData=Data;
     E=1;
     _nop_();
     _nop_();
     E=0;
    }
    /*************************************
    ��LCDָ����ʼλ��д��һ���ַ���
    *************************************/
    void Lcd_WriteStr(unsigned char x,unsigned char y,unsigned char *Str)
    {
     if((y>3)||(x>7))
      return;//���ָ��λ�ò�����ʾ�����ڣ������κ�д��ֱ�ӷ���
     
     switch(y)
     {
      case 0:
        Lcd_WriteCmd(0x80+x);
        break;
      case 1:
        Lcd_WriteCmd(0x90+x);
        break;    
      case 2:
        Lcd_WriteCmd(0x88+x);
        break;
      case 3:
        Lcd_WriteCmd(0x98+x);
        break;
     }
     while(*Str>0)
     {  
      Lcd_WriteData(*Str);
        Str++;     
     }
     
    }
    /****************************************
    LCD��ʼ��
    *****************************************/
    void Lcd_Reset()
    {  
     PSB=1;
     Lcd_WriteCmd(0x30); //ѡ�����ָ�
     delayms(5);
     Lcd_WriteCmd(0x0c);       //����ʾ(���αꡢ������)
     delayms(5);
     Lcd_WriteCmd(0x01);       //�����ʾ�������趨��ַָ��Ϊ00H
     delayms(5);
    }
    void main()
    {
     Lcd_Reset();
     Lcd_WriteStr(0,0,"��ǰת�� ÿ��");


        delayms(200);
    //    Lcd_WriteCmd(0x01);  
    }
