/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   File Name   : $RCSfile: can.h,v $
*   Description : Header for CAN-driver
*****************************************************************************
*   PROJECT     : Capricorn_Bt
*   MODULE      : CAN-driver
*   TAG         : $Name:  $
*   LIBRARIES   :
*   AUTHOR      : $Author: mto $
*****************************************************************************
*   VERSION     : $Revision: 1.3 $
*   RELEASE     : Preliminary and Confidential
*   DATE        : $Date: 2014/12/17 15:17:49 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Demo_7inch/usecases/inc/can.h,v $
****************************************************************************/
#ifndef CAN_H
#define CAN_H

/**********************************************
*                Include files                *
**********************************************/


/**********************************************
*                 Definitions                 *
**********************************************/
/* speed settings for 1M */
#define BRP_1M     1
#define BT1_1M    13
#define BT2_1M     3

/* speed settings for 500k */
#define BRP_500K   4
#define BT1_500K  10
#define BT2_500K   2

/* speed settings for 250k */
#define BRP_250K   9
#define BT1_250K  10
#define BT2_250K   2

/* speed settings for 125k */
#define BRP_125K  19
#define BT1_125K  10
#define BT2_125K   2

/* speed settings for 100k */
#define BRP_100K  24
#define BT1_100K  10
#define BT2_100K   2

/* speed settings for 50k */
#define BRP_50K   49
#define BT1_50K   10
#define BT2_50K    2

/* speed settings for 20k */
#define BRP_20K  124
#define BT1_20K   10
#define BT2_20K    2

/* speed settings for 10k */
#define BRP_10K  249
#define BT1_10K   10
#define BT2_10K    2

/**********************************************
*        Exported function prototypes         *
**********************************************/
/****************************************************************************
 *
 * Function:      vInitCAN
 *
 * Purpose:       initialisation of CAN-module
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vInitCAN(void);

/****************************************************************************
 *
 * Function:      vEvalCAN
 *
 * Purpose:       get information out of mailbox and transfer it to
 *                statevariables
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vEvalCAN(void);

/****************************************************************************/

#endif /* CAN_H */

/****************************************************************************/

/************************** BEGIN of DISCLAIMER   **************************

- TOSHIBA is continually working to improve the quality and reliability of   
  its products. Nevertheless, semiconductor devices in general can
  malfunction or fail due to their inherent electrical sensitivity and 
  vulnerability to physical stress. It is the responsibility of the buyer, 
  when utilizing TOSHIBA products, to comply with the standards of safety 
  in making a safe design for the entire system, and to avoid situations in 
  which a malfunction or failure of such TOSHIBA products could cause loss of
  human life, bodily injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used 
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications.
  Also, please keep in mind the precautions and conditions set forth in the 
  “Handling Guide for Semiconductor Devices,” or 
  “TOSHIBA Semiconductor Reliability Handbook” etc..

- The Toshiba products listed in this document are intended for usage in 
  general electronics applications (computer, personal equipment, office 
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.). 
  These Toshiba products are neither intended nor warranted for usage in 
  equipment that requires extraordinarily high quality and/or reliability or
  a malfunction or failure of which may cause loss of human life or bodily 
  injury (“Unintended Usage”). Unintended Usage include atomic energy control
  instruments, airplane or spaceship instruments, transportation instruments, 
  traffic signal instruments, combustion control instruments, medical 
  instruments, all types of safety devices, etc.. 
  Unintended Usage of Toshiba products listed in this document shall be 
  made at the customer’s own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit,business interruption, loss of business
  information,and other pecuniary losses) occurring 
  from the use of, or inability to use, this product.

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

