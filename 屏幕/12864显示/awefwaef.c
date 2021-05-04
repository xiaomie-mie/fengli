    #include <reg52.h>
    #include <intrins.h>
    #define uchar unsigned char
    #define uint unsigned int
    #define  LcdData P0
    sbit RS=P2^6; //并行的指令/数据选择信号, H数据, L命令
    sbit RW=P2^5; //并行读写选择信号, H读, L写
    sbit E=P2^7; //并行使能端, H有效, L无效
    sbit PSB=P3^2; //并/串接口选择, H并,L串
    sbit RET=P3^4; //复位, L有效
		uchar v=16;
    /*************************************
    想LCD中写入指令代码
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
        /*延时函数*/
        void delayms(uint x)
        {
         uint i,j;
         for(i=x;i>0;i--)
           for(j=110;j>0;j--);
        }
        /*********************************
        向LCD写入字节数据
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
    向LCD指定起始位置写入一个字符串
    *************************************/
    void Lcd_WriteStr(unsigned char x,unsigned char y,unsigned char *Str)
    {
     if((y>3)||(x>7))
      return;//如果指定位置不在显示区域内，则不做任何写入直接返回
     
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
    LCD初始化
    *****************************************/
    void Lcd_Reset()
    {  
     PSB=1;
     Lcd_WriteCmd(0x30); //选择基本指令集
     delayms(5);
     Lcd_WriteCmd(0x0c);       //开显示(无游标、不反白)
     delayms(5);
     Lcd_WriteCmd(0x01);       //清除显示，并且设定地址指针为00H
     delayms(5);
    }
    void main()
    {
     Lcd_Reset();
     Lcd_WriteStr(0,0,"当前转速 每秒");


        delayms(200);
    //    Lcd_WriteCmd(0x01);  
    }
