.cfg �ļ���������

0x00000001    	 //   QSPI_Ctrl
0x00000000   	 // QSPI_DevNo
0x00000000  	 // QSPI_Interface
0x00000003  	 // QSPI_DevType
0x00000003  	 // QSPI_Action 
0x00000001	// DbgUart    
..\out\rom2ram.bin	// File to Flash
0x02010000	// RomStart



Flash ���͵�ѡ�� �������  0x00000003 �� QSPI_DevType �������MX25L12835F      
���Ҫ��¼S25FL127P   ����Ѹò����ĳ�        11  ����	0x0000000B   
   QSPI_DevType :  
1    ,  " MX25L3235E 
2    ,  " MX25L6435E   
3    ,  " MX25L12835F      
4    ,  " MX66L51239F_3BYTE_ADR  
5    ,  " MX66L51239F_4BYTE_ADR 
6     ,  " N25Q064A          
7     ,  " N25Q512A_3BYTE_ADR   
8     ,  " N25Q512A_4BYTE_ADR     
9     ,  " S25FL032P            
10    ,  " S25FL064P           
11     ,  " S25FL127P            
12     ,  " W25Q32B        
13    ,  " W25Q64C             
14    ,  " W25Q256F_3BYTE_ADR    
15   ,  " W25Q256F_4BYTE_ADR    
16    ,  " INTERNAL_32MBIT      
17     ,  " INTERNAL_64MBIT    

 QSPI_Action �������� ��ͬ�Ĳ�����
1. Read Device-ID
2. Set Mode
3. Program Device
4. Erase Entire Device
5. Disable Quad Mode
6. Test read operation

  




����ֱ������ flashutility.exe �������Լ�����Ҫ���ɲ���.
