/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronic Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : LPDDR/SDRAM configurations
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : DMC
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
****************************************************************************/
#ifndef DMC_PARAMS_H
#define DMC_PARAMS_H

/**********************************************
*                Include files                *
**********************************************/
#include "config.h"
#include "captypes.h"

/**********************************************
*                Definitions                  *
**********************************************/

/**********************************************
*   MT46H8M32LFB5-6                           *
**********************************************/
#if (RAM_DEVICE == 1)

/* memory type */
#define MEMORY_TYPE          (DMC_TYPE_LPDDR)
/* memory width */
#define MEMORY_WIDTH         (DMC_BUSWIDTH_32BIT)
/* memory density */
#define MEMORY_DENSITY       (DMC_DENSITY_256Mbit)
/* memory clock rate */
#define MEMORY_CLOCK_RATE    (DMC_CLOCK_RATE_166MHz)

/* gear values */
#define GEAR_RATIO_0         (0x3ff)
#define GEAR_RATIO_1         (0x3ff)
#define GEAR_RATIO_2         (0x3ff)
#define GEAR_RATIO_3         (0x3ff)

/* CAS latency */
#define MEMORY_T_CAS         (0x00000006)
/* RAS latency */
#define MEMORY_T_RAS         (0x00000007)
/* t_mrd */
#define MEMORY_T_MRD         (0x00000002)
/* t_rc */
#define MEMORY_T_RC          (0x0000000B)
/* t_rcd */
#define MEMORY_T_RCD         (((uint32_t)3 << (uint32_t)0) /* t_rcd */ | ((uint32_t)0 << (uint32_t)3) /* schedule_rcd */ )
/* t_rfc */
#define MEMORY_T_RFC         (0x00000212)
/* t_rp */
#define MEMORY_T_RP          (0x0000001D)
/* t_rrd */
#define MEMORY_T_RRD         (0x00000002)
/* t_wr */
#define MEMORY_T_WR          (0x00000003)
/* t_wrt */
#define MEMORY_T_WTR         (0x00000002)
/* t_xp */
#define MEMORY_T_XP          (0x00000001)
/* t_xsr */
#define MEMORY_T_XSR         (0x0000000C)
/* t_esr */
#define MEMORY_T_ESR         (0x00000014)
/* memory refresh period */
#define MEMORY_REFRESH_PRD   (1200)       /* = 7.8us/6.18ns */

/**********************************************
*   MT46H16M32LFB5-6                          *
**********************************************/
#elif (RAM_DEVICE == 2)

/* memory type */
#define MEMORY_TYPE          (DMC_TYPE_LPDDR)
/* memory width */
#define MEMORY_WIDTH         (DMC_BUSWIDTH_32BIT)
/* memory density */
#define MEMORY_DENSITY       (DMC_DENSITY_256Mbit)
/* memory clock rate */
#define MEMORY_CLOCK_RATE    (DMC_CLOCK_RATE_166MHz)

/* gear values */
#define GEAR_RATIO_0         (0x3ff)
#define GEAR_RATIO_1         (0x3ff)
#define GEAR_RATIO_2         (0x3ff)
#define GEAR_RATIO_3         (0x3ff)

/* CAS latency */
#define MEMORY_T_CAS         (0x00000006)
/* RAS latency */
#define MEMORY_T_RAS         (0x00000007)
/* t_mrd */
#define MEMORY_T_MRD         (0x00000002)
/* t_rc */
#define MEMORY_T_RC          (0x0000000B)
/* t_rcd */
#define MEMORY_T_RCD         (((uint32_t)3 << (uint32_t)0) /* t_rcd */ | ((uint32_t)0 << (uint32_t)3) /* schedule_rcd */ )
/* t_rfc */
#define MEMORY_T_RFC         (0x00000212)
/* t_rp */
#define MEMORY_T_RP          (0x0000001D)
/* t_rrd */
#define MEMORY_T_RRD         (0x00000002)
/* t_wr */
#define MEMORY_T_WR          (0x00000003)
/* t_wrt */
#define MEMORY_T_WTR         (0x00000002)
/* t_xp */
#define MEMORY_T_XP          (0x00000001)
/* t_xsr */
#define MEMORY_T_XSR         (0x0000000C)
/* t_esr */
#define MEMORY_T_ESR         (0x00000014)
/* memory refresh period */
#define MEMORY_REFRESH_PRD   (1200)       /* = 7.8us/6.18ns */

/**********************************************
*   IS42S32800D-6                             *
**********************************************/
#elif (RAM_DEVICE == 3)

/* memory type */
#define MEMORY_TYPE          (DMC_TYPE_SDRAM)
/* memory width */
#define MEMORY_WIDTH         (DMC_BUSWIDTH_32BIT)
/* memory density */
#define MEMORY_DENSITY       (DMC_DENSITY_8Gbit)
/* memory clock rate */
#define MEMORY_CLOCK_RATE    (DMC_CLOCK_RATE_133MHz)

/* gear values */
#define GEAR_RATIO_0         (0x0)
#define GEAR_RATIO_1         (0x0)
#define GEAR_RATIO_2         (0x0)
#define GEAR_RATIO_3         (0x0)

/* CAS latency */
#define MEMORY_T_CAS         (0x00000006)
/* RAS latency */
#define MEMORY_T_RAS         (0x00000007)
/* t_mrd */
#define MEMORY_T_MRD         (0x00000002)
/* t_rc */
#define MEMORY_T_RC          (0x0000000B)
/* t_rcd */
#define MEMORY_T_RCD         (((uint32_t)3 << (uint32_t)0) /* t_rcd */ | ((uint32_t)0 << (uint32_t)3) /* schedule_rcd */ )
/* t_rfc */
#define MEMORY_T_RFC         (0x00000212)
/* t_rp */
#define MEMORY_T_RP          (0x0000001D)
/* t_rrd */
#define MEMORY_T_RRD         (0x00000002)
/* t_wr */
#define MEMORY_T_WR          (0x00000003)
/* t_wrt */
#define MEMORY_T_WTR         (0x00000002)
/* t_xp */
#define MEMORY_T_XP          (0x00000001)
/* t_xsr */
#define MEMORY_T_XSR         (0x0000000C)
/* t_esr */
#define MEMORY_T_ESR         (0x00000014)
/* memory refresh period */
#define MEMORY_REFRESH_PRD   (1200)       /* = 7.8us/6.18ns */

/****************************************************************************/

#else
		#error Memory configuration not supported !!!
#endif


/****************************************************************************/


#endif /* DMC_PARAMS_H */

/****************************************************************************/


/************************* BEGIN of DISCLAIMER   *****************************

- TOSHIBA is continually working to improve the quality and reliability of its
  products. Nevertheless, semiconductor devices in general can malfunction or
  fail due to their inherent electrical sensitivity and vulnerability to
  physical stress. It is the responsibility of the buyer, when utilizing
  TOSHIBA products, to comply with the standards of safety in making a safe
  design for the entire system, and to avoid situations in which a malfunction
  or failure of such TOSHIBA products could cause loss of human life, bodily
  injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications. Also, please keep in mind the precautions and
  conditions set forth in the Handling Guide for Semiconductor Devices,
  or TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment, office
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.). These Toshiba products are neither intended nor warranted for usage
  in equipment that requires extraordinarily high quality and/or reliability
  or a malfunction or failure of which may cause loss of human life or bodily
  injury (Unintended Usage). Unintended Usage include atomic energy control
  instruments, airplane or spaceship instruments, transportation instruments,
  traffic signal instruments, combustion control instruments, medical
  instruments, all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer’s own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit, business interruption, loss of business
  information, and other pecuniary losses) occurring from the use of, or
  inability to use, this product.

- The products described in this document are subject to the foreign exchange
  and foreign trade laws.

- The products described in this document contain components made in the
  United States and subject to export control of the U.S. authorities.
  Diversion contrary to the U.S. law is prohibited.

- The information contained herein is presented only as a guide for the
  applications of our products. No responsibility is assumed by TOSHIBA
  CORPORATION for any infringements of intellectual property or other rights
  of the third parties which may result from its use. No license is granted by
  implication or otherwise under any intellectual property or other rights
  of TOSHIBA CORPORATION or others.

- The information contained herein is subject to change without notice.

****************************  END of DISCLAIMER *****************************/

