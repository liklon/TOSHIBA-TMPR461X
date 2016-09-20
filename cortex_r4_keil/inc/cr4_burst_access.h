/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Cortex R4 burst access definitions
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Cortex R4 Core
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.7 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef CR4_BURST_H
#define CR4_BURST_H

/**********************************************
*                Include files                *
**********************************************/


/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/


/*********************************************/


/**********************************************
*                    Macros                   *
**********************************************/


/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
*
* Function:      vASM_Init8WordsInBurst
*
* Purpose:       Initialize memory with a predefined pattern in 8 words bursts
*
* Inputs:        ulPattern  : Data pasttern (initializer value)
*                ulDstAddr  : Destination address (must be 8 words aligned)
*                ulTransCnt : Number of bursts
*
* Outputs:       none
*
* Return Values: none 
*
* Limitations:   No alignment checks will be done, burst is not guaranteed
*
***************************************************************************/
extern void vASM_Init8WordsInBurst(unsigned long ulPattern, unsigned long ulDestAddr, unsigned long ulTransCnt);


/****************************************************************************
*
* Function:      vASM_Copy8WordsInBurst
*
* Purpose:       Copy using 8 words burst accesses
*
* Inputs:        ulSrcAddr  : Source address (must be 8 words aligned)
*                ulDstAddr  : Destination address (must be 8 words aligned)
*                ulTransCnt : Number of bursts
*
* Outputs:       none
*
* Return Values: none
*
* Limitations:   No alignment checks will be done, burst is not guaranteed
*
***************************************************************************/
extern void vASM_Copy8WordsInBurst(unsigned long ulSrcAddr, unsigned long ulDestAddr, unsigned long ulTransCnt);



/****************************************************************************
*
* Function:      vASM_Copy4WordsInBurstMem2FiFo
*
* Purpose:       Copy using 4 words burst accesses
*
* Inputs:        ulSrcAddr  : Memory Source address (must be 4 words aligned, auto incremented)
*                ulDestAddr : Destination address (constant)
*                ulTransCnt : Number of bursts
*
* Outputs:       none
*
* Return Values: none
*
* Limitations:   No alignment checks will be done, burst is not guaranteed
*
***************************************************************************/
extern void vASM_Copy4WordsInBurstMem2FiFo(unsigned long ulSrcAddr, unsigned long ulDestAddr, unsigned long ulTransCnt);

/****************************************************************************
*
* Function:      vASM_Copy8WordsInBurstMem2FiFo
*
* Purpose:       Copy using 8 words burst accesses
*
* Inputs:        ulSrcAddr  : Memory Source address (must be 8 words aligned, auto incremented)
*                ulDestAddr : Destination address (constant)
*                ulTransCnt : Number of bursts
*
* Outputs:       none
*
* Return Values: none
*
* Limitations:   No alignment checks will be done, burst is not guaranteed
*
***************************************************************************/
extern void vASM_Copy8WordsInBurstMem2FiFo(unsigned long ulSrcAddr, unsigned long ulDestAddr, unsigned long ulTransCnt);

/****************************************************************************
*
* Function:      vASM_Copy4WordsInBurstFiFo2Mem
*
* Purpose:       Copy using 4 words burst accesses
*
* Inputs:        ulSrcAddr  : TSM FiFo Source address (constant)
*                ulDestAddr : Memory Destination address (must be 4 words aligned, auto incremented)
*                ulTransCnt : Number of bursts
*
* Outputs:       none
*
* Return Values: none
*
* Limitations:   No alignment checks will be done, burst is not guaranteed
*
***************************************************************************/
extern void vASM_Copy4WordsInBurstFiFo2Mem(unsigned long ulSrcAddr, unsigned long ulDestAddr, unsigned long ulTransCnt);

/****************************************************************************
*
* Function:      vASM_Copy8WordsInBurstFiFo2Mem
*
* Purpose:       Copy using 8 words burst accesses
*
* Inputs:        ulSrcAddr  : TSM FiFo Source address (constant)
*                ulDestAddr : Memory Destination address (must be 8 words aligned, auto incremented)
*                ulTransCnt : Number of bursts
*
* Outputs:       none
*
* Return Values: none
*
* Limitations:   No alignment checks will be done, burst is not guaranteed
*
***************************************************************************/
extern void vASM_Copy8WordsInBurstFiFo2Mem(unsigned long ulSrcAddr, unsigned long ulDestAddr, unsigned long ulTransCnt);

/****************************************************************************/

#endif /* CR4_BURST_H */

/****************************************************************************/


/***********************  BEGIN of DISCLAIMER   *****************************

- TOSHIBA is continually working to improve the quality and reliability of
  its products.
  Nevertheless, semiconductor devices in general can malfunction or fail
  due to their inherent electrical sensitivity and vulnerability to physical
  stress. It is the responsibility of the buyer, when utilizing TOSHIBA
  products, to comply with the standards of safety in making a safe design
  for the entire system, and to avoid situations in which a malfunction or
  failure of such TOSHIBA products could cause loss of human life,
  bodily injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications. Also, please keep in mind the precautions and
  conditions set forth in the “Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (“Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer’s own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit,business interruption, loss of business
  information,and other pecuniary losses) occurring from the use of,
  or inability to use, this product.

- The products described in this document are subject to the foreign exchange
  and foreign trade laws.

- The products described in this document contain components made in the
  United States and subject to export control of the U.S. authorities.
  Diversion contrary to the U.S. law is prohibited.

- The information contained herein is presented only as a guide for the
  applications of our products.
  No responsibility is assumed by TOSHIBA CORPORATION for any infringements
  of intellectual property or other rights of the third parties which may
  result from its use.
  No license is granted by implication or otherwise under any intellectual
  property or other rights of TOSHIBA CORPORATION or others.

- The information contained herein is subject to change without notice.

****************************  END of DISCLAIMER ****************************/

