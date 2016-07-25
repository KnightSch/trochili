/*!
    \file  usbd_regs.h
    \brief usb device registers
*/

/*
    Copyright (C) 2016 GigaDevice

    2014-09-06, V1.0.0, firmware for GD32F150
    2016-01-15, V1.0.1, firmware for GD32F150
    2016-04-30, V3.0.0, firmware update for GD32F150
*/

#ifndef USBD_REGS_H
#define USBD_REGS_H

#include "usbd_conf.h"

/* USB device registers base address */
#define USBD                           USBD_BASE
#define USBD_RAM                       USBD_RAM_BASE

/* registers definitions */
/* common registers */
#define USBD_CTL                       (REG32(USBD + 0x40))  /*!< control register */
#define USBD_INTF                      (REG32(USBD + 0x44))  /*!< interrupt flag register */
#define USBD_STAT                      (REG32(USBD + 0x48))  /*!< status register */
#define USBD_DADDR                     (REG32(USBD + 0x4C))  /*!< device address register */
#define USBD_BADDR                     (REG32(USBD + 0x50))  /*!< buffer address register */

/* LPM Registers */
#define USBD_SEP0                      (REG32(USBD + 0x100))  /*!< sub endpoint0 register(for LPM) */
#define USBD_LPMCTL                    (REG32(USBD + 0x140))  /*!< LPM interrupt control register */
#define USBD_LPMINTF                   (REG32(USBD + 0x144))  /*!< LPM interrupt status register */

/* endpoint control and status register */
#define USBD_EPxCS(ep_id)              (REG32(USBD + (ep_id) * 4))  /*!< endpoint x control and status register address */

/* bits definitions */
/* USBD_CTL */
#define CTL_STIE                       BIT(15)  /*!< successful transfer interrupt enable mask */
#define CTL_PMOUIE                     BIT(14)  /*!< packet memory overrun/underrun interrupt enable mask */
#define CTL_ERRIE                      BIT(13)  /*!< error interrupt enable mask */
#define CTL_WKUPIE                     BIT(12)  /*!< wakeup interrupt enable mask */
#define CTL_SPSIE                      BIT(11)  /*!< suspend state interrupt enable mask */
#define CTL_RSTIE                      BIT(10)  /*!< reset interrupt enable mask */
#define CTL_SOFIE                      BIT(9)   /*!< start of frame interrupt enable mask */
#define CTL_ESOFIE                     BIT(8)   /*!< expected start of frame interrupt enable mask */
#define CTL_RSREQ                      BIT(4)   /*!< resume request */
#define CTL_SETSPS                     BIT(3)   /*!< set suspend state */
#define CTL_LOWM                       BIT(2)   /*!< low-power mode at suspend state */
#define CTL_CLOSE                      BIT(1)   /*!< goes to close state */
#define CTL_SETRST                     BIT(0)   /*!< set USB reset */

/* USBD_INTF */
#define INTF_STIF                      BIT(15)     /*!< successful transfer interrupt flag (read only bit) */
#define INTF_PMOUIF                    BIT(14)     /*!< packet memory overrun/underrun interrupt flag (clear-only bit) */
#define INTF_ERRIF                     BIT(13)     /*!< error interrupt flag (clear-only bit) */
#define INTF_WKUPIF                    BIT(12)     /*!< wakeup interrupt flag (clear-only bit) */
#define INTF_SPSIF                     BIT(11)     /*!< suspend state interrupt flag (clear-only bit) */
#define INTF_RSTIF                     BIT(10)     /*!< reset interrupt flag (clear-only bit) */
#define INTF_SOFIF                     BIT(9)      /*!< start of frame interrupt flag (clear-only bit) */
#define INTF_ESOFIF                    BIT(8)      /*!< expected start of frame interrupt flag(clear-only bit) */
#define INTF_DIR                       BIT(4)      /*!< direction of transaction (read-only bit) */
#define INTF_EPNUM                     BITS(0, 3)  /*!< endpoint number (read-only bit)  */

/* USBD_STAT */
#define STAT_RXDP                      BIT(15)       /*!< data plus line status */
#define STAT_RXDM                      BIT(14)       /*!< data minus line status */
#define STAT_LOCK                      BIT(13)       /*!< locked the USB */
#define STAT_SOFLN                     BITS(11, 12)  /*!< SOF lost number */
#define STAT_FCNT                      BITS(0, 10)   /*!< frame number count */

/* USBD_DADDR */
#define DADDR_USBEN                    BIT(7)      /*!< USB module enable */
#define DADDR_USBADDR                  BITS(0, 6)  /*!< USB device address */

/* USBD_SEPx */
#define SUB_ST                         BIT(15)      /*!< LPM token successful receive */
#define SUB_STA                        BITS(12, 13) /*!< status bits for the handshake of receiving subpid LPM */
#define SUBPID_ATTR                    BITS(0, 10)  /*!< LPM token bmattribute field */

/* USBD_LPMCTL */
#define LPMCTL_STIE                    BIT(15)  /*!< LPM token successful transfer interrupt enable mask */

/* USBD_LPMINTF */
#define LPMINTF_STIF                   BIT(15)         /*!< LPM token successful transfer interrupt flag */
#define LPM_CLR_STIF                   (~LPMINTF_STIF) /*!< clear successful transfer interrupt flag */

/* USBD_EPxCS */
#define EPxCS_RX_ST                    BIT(15)       /*!< endpoint reception successful transferred */
#define EPxCS_RX_DTG                   BIT(14)       /*!< endpoint reception data PID toggle */
#define EPxCS_RX_STA                   BITS(12, 13)  /*!< endpoint reception status bits */
#define EPxCS_SETUP                    BIT(11)       /*!< endpoint setup transaction completed */
#define EPxCS_CTL                      BITS(9, 10)   /*!< endpoint type control */
#define EPxCS_KCTL                     BIT(8)        /*!< endpoint kind control */
#define EPxCS_TX_ST                    BIT(7)        /*!< endpoint transmission successful transfer */
#define EPxCS_TX_DTG                   BIT(6)        /*!< endpoint transmission data toggle */
#define EPxCS_TX_STA                   BITS(4, 5)    /*!< endpoint transmission transfers status bits */
#define EPxCS_AR                       BITS(0, 3)    /*!< endpoint address */

/* constants definitions */
/* endpoint control and status register mask (no toggle fields) */
#define EPCS_MASK                      (EPxCS_RX_ST|EPxCS_SETUP|EPxCS_CTL|EPxCS_KCTL|EPxCS_TX_ST|EPxCS_AR)

/* EPxCS_CTL[1:0] endpoint type control */
#define ENDP_TYPE(regval)              (EPxCS_CTL & (regval << 9))

#define EP_BULK                        ENDP_TYPE(0)  /* bulk transfers */
#define EP_CONTROL                     ENDP_TYPE(1)  /* control transfers */
#define EP_ISO                         ENDP_TYPE(2)  /* isochronous transfers */
#define EP_INTERRUPT                   ENDP_TYPE(3)  /* interrupt transfers */
#define EP_CTL_MASK                    (~EPxCS_CTL & EPCS_MASK)

/* endpoint kind control mask */
#define EPKCTL_MASK                    (~EPxCS_KCTL & EPCS_MASK)

/* EPxCS_TX_STA[1:0] status for Tx transfer */
#define ENDP_TXSTAT(regval)            (EPxCS_TX_STA & (regval << 4))

#define EPTX_DISABLED                  ENDP_TXSTAT(0)  /* transmission state is disabled */
#define EPTX_STALL                     ENDP_TXSTAT(1)  /* transmission state is STALL */
#define EPTX_NAK                       ENDP_TXSTAT(2)  /* transmission state is NAK */
#define EPTX_VALID                     ENDP_TXSTAT(3)  /* transmission state is enabled */
#define EPTX_DTGMASK                   (EPxCS_TX_STA | EPCS_MASK)

/* EPxCS_RX_STA[1:0] status for Rx transfer */
#define ENDP_RXSTAT(regval)            (EPxCS_RX_STA & (regval << 12))

#define EPRX_DISABLED                  ENDP_RXSTAT(0)  /* reception state is disabled */
#define EPRX_STALL                     ENDP_RXSTAT(1)  /* reception state is STALL */
#define EPRX_NAK                       ENDP_RXSTAT(2)  /* reception state is NAK */
#define EPRX_VALID                     ENDP_RXSTAT(3)  /* reception state is enabled */
#define EPRX_DTGMASK                   (EPxCS_RX_STA | EPCS_MASK)

/* endpoint receive/transmission counter register bit definitions */
#define EPRCNT_BLKSIZ                  BIT(15)       /* reception data block size */
#define EPRCNT_BLKNUM                  BITS(10, 14)  /* reception data block number */
#define EPRCNT_CNT                     BITS(0, 9)    /* reception data count */

#define EPTCNT_CNT                     BITS(0, 9)    /* transmisson data count */

/* interrupt flag clear bits */
#define CLR_STIF                       (~INTF_STIF)
#define CLR_PMOUIF                     (~INTF_PMOUIF)
#define CLR_ERRIF                      (~INTF_ERRIF)
#define CLR_WKUPIF                     (~INTF_WKUPIF)
#define CLR_SPSIF                      (~INTF_SPSIF)
#define CLR_RSTIF                      (~INTF_RSTIF)
#define CLR_SOFIF                      (~INTF_SOFIF)
#define CLR_ESOFIF                     (~INTF_ESOFIF)

#define ATTR_BREMOTEWAKE               BIT(8)
#define ATTR_HIRD                      BITS(4, 7)
#define ATTR_BLINKSTATE                BITS(0, 3)

/* STAT_TX[1:0] status for Tx transfer */
#define SUBEP_STAT(regval)             (SUB_STA & (regval << 12))

#define SUBEP_DISABLE                  SUBEP_STAT(0)
#define SUBEP_STALL                    SUBEP_STAT(1)
#define SUBEP_NYET                     SUBEP_STAT(2)
#define SUBEP_VALID                    SUBEP_STAT(3)

/* endpoint receive/transmission counter register bit offset */
#define BLKSIZE_OFFSET                 (0x01)
#define BLKNUM_OFFSET                  (0x05)
#define RXCNT_OFFSET                   (0x0A)

#define TXCNT_OFFSET                   (0x0A)

#define BLKSIZE32_MASK                 (0x1f)
#define BLKSIZE2_MASK                  (0x01)

#define BLKSIZE32_OFFSETMASK           (0x05)
#define BLKSIZE2_OFFSETMASK            (0x01)

/* double buffer endpoint direction */
typedef enum
{
    DBUF_EP_IN,   /* double buffer IN direction */
    DBUF_EP_OUT,  /* double buffer OUT direction */
    DBUF_EP_ERR,  /* double buffer errer direction */
}dbuf_ep_dir_enum;

/* endpoints address */
/* first bit is direction(0 for Rx and 1 for Tx) */
#define EP0_OUT                        ((uint8_t)0x00)  /* OUT endpoint 0 address */
#define EP0_IN                         ((uint8_t)0x80)  /* IN endpoint 0 address */
#define EP1_OUT                        ((uint8_t)0x01)  /* OUT endpoint 1 address */
#define EP1_IN                         ((uint8_t)0x81)  /* IN endpoint 1 address */
#define EP2_OUT                        ((uint8_t)0x02)  /* OUT endpoint 2 address */
#define EP2_IN                         ((uint8_t)0x82)  /* IN endpoint 2 address */
#define EP3_OUT                        ((uint8_t)0x03)  /* OUT endpoint 3 address */
#define EP3_IN                         ((uint8_t)0x83)  /* IN endpoint 3 address */
#define EP4_OUT                        ((uint8_t)0x04)  /* OUT endpoint 4 address */
#define EP4_IN                         ((uint8_t)0x84)  /* IN endpoint 4 address */
#define EP5_OUT                        ((uint8_t)0x05)  /* OUT endpoint 5 address */
#define EP5_IN                         ((uint8_t)0x85)  /* IN endpoint 5 address */
#define EP6_OUT                        ((uint8_t)0x06)  /* OUT endpoint 6 address */
#define EP6_IN                         ((uint8_t)0x86)  /* IN endpoint 6 address */
#define EP7_OUT                        ((uint8_t)0x07)  /* OUT endpoint 7 address */
#define EP7_IN                         ((uint8_t)0x87)  /* IN endpoint 7 address */

/* endpoints_Identifier */
#define EP0                            ((uint8_t)0)  /* endpoint 0 ID */
#define EP1                            ((uint8_t)1)  /* endpoint 1 ID */
#define EP2                            ((uint8_t)2)  /* endpoint 2 ID */
#define EP3                            ((uint8_t)3)  /* endpoint 3 ID */
#define EP4                            ((uint8_t)4)  /* endpoint 4 ID */
#define EP5                            ((uint8_t)5)  /* endpoint 5 ID */
#define EP6                            ((uint8_t)6)  /* endpoint 6 ID */
#define EP7                            ((uint8_t)7)  /* endpoint 7 ID */

/* USBD operation macros */

/* set register value */
#define USBD_REG_SET(reg, regvalue)    (reg = (uint16_t)regvalue)

/* get register value */
#define USBD_REG_GET(reg)              ((uint16_t)reg)

/* Tx or Rx transfer status setting (bits EPTX_STA[1:0]) */
#define USBD_ENDP_TX_STATUS_SET(ep_id, state) {\
    register uint16_t _regval;       \
    _regval = USBD_REG_GET(USBD_EPxCS(ep_id)) & EPTX_DTGMASK;\
    USBD_REG_SET(USBD_EPxCS(ep_id), (_regval ^ state));    \
}

#define USBD_ENDP_RX_STATUS_SET(ep_id, state) {\
    register uint16_t _regval;   \
    _regval = USBD_REG_GET(USBD_EPxCS(ep_id)) & EPRX_DTGMASK;\
    USBD_REG_SET(USBD_EPxCS(ep_id), (_regval ^ state)); \
}

/* Tx or Rx transfer status getting (bits EPxCS_RX_STA[1:0]) */
#define USBD_ENDP_TX_STATUS_GET(ep_id) ((uint16_t)USBD_REG_GET(USBD_EPxCS(ep_id)) & EPxCS_TX_STA)
#define USBD_ENDP_RX_STATUS_GET(ep_id) ((uint16_t)USBD_REG_GET(USBD_EPxCS(ep_id)) & EPxCS_RX_STA)

/* Rx and Tx transfer status setting (bits EPxCS_RX_STA[1:0] & EPxCS_TX_STA[1:0]) */
#define USBD_ENDP_RX_TX_STATUS_SET(ep_id, state_rx, state_tx) {\
    register uint16_t _regval;   \
    _regval = USBD_REG_GET(USBD_EPxCS(ep_id)) & (EPRX_DTGMASK | EPxCS_TX_STA) ;\
    USBD_REG_SET(USBD_EPxCS(ep_id), ((_regval ^ state_rx) ^ state_tx));    \
}

/* set and clear endpoint kind (bit EPxCS_KCTL) */
#define USBD_ENDP_KIND_SET(ep_id)      (USBD_REG_SET(USBD_EPxCS(ep_id), ((USBD_REG_GET(USBD_EPxCS(ep_id)) | EPxCS_KCTL) & EPCS_MASK)))
#define USBD_ENDP_KIND_CLEAR(ep_id)    (USBD_REG_SET(USBD_EPxCS(ep_id), (USBD_REG_GET(USBD_EPxCS(ep_id)) & EPKCTL_MASK)))

/* set and clear directly STATUS_OUT state of endpoint */
#define USBD_STATUS_OUT_SET(ep_id)     USBD_ENDP_KIND_SET(ep_id)
#define USBD_STATUS_OUT_CLEAR(ep_id)   USBD_ENDP_KIND_CLEAR(ep_id)

/* clear bit EPxCS_RX_ST/EPxCS_TX_ST in the endpoint control and status register */
#define USBD_ENDP_RX_STAT_CLEAR(ep_id) (USBD_REG_SET(USBD_EPxCS(ep_id), USBD_REG_GET(USBD_EPxCS(ep_id)) & 0x7FFF & EPCS_MASK))
#define USBD_ENDP_TX_STAT_CLEAR(ep_id) (USBD_REG_SET(USBD_EPxCS(ep_id), USBD_REG_GET(USBD_EPxCS(ep_id)) & 0xFF7F & EPCS_MASK))

/* toggle EPxCS_RX_DTG or EPxCS_TX_DTG bit in the endpoint control and status register */
#define USBD_DTG_RX_TOGGLE(ep_id)      (USBD_REG_SET(USBD_EPxCS(ep_id), EPxCS_RX_DTG | (USBD_REG_GET(USBD_EPxCS(ep_id)) & EPCS_MASK)))
#define USBD_DTG_TX_TOGGLE(ep_id)      (USBD_REG_SET(USBD_EPxCS(ep_id), EPxCS_TX_DTG | (USBD_REG_GET(USBD_EPxCS(ep_id)) & EPCS_MASK)))

/* clear EPxCS_RX_DTG or EPxCS_TX_DTG bit in the endpoint control and status register */
#define USBD_DTG_RX_CLEAR(ep_id)       if ((USBD_REG_GET(USBD_EPxCS(ep_id)) & EPxCS_RX_DTG) != 0) USBD_DTG_RX_TOGGLE(ep_id)
#define USBD_DTG_TX_CLEAR(ep_id)       if ((USBD_REG_GET(USBD_EPxCS(ep_id)) & EPxCS_TX_DTG) != 0) USBD_DTG_TX_TOGGLE(ep_id)

/* set and clear directly double buffered feature of endpoint */
#define USBD_ENDP_DOUBLE_BUF_SET(ep_id)   USBD_ENDP_KIND_SET(ep_id)
#define USBD_ENDP_DOUBLE_BUF_CLEAR(ep_id) USBD_ENDP_KIND_CLEAR(ep_id)

/* toggle SW_BUF bit in the double buffered endpoint */
#define USBD_SWBUF_TX_TOGGLE(ep_id)    USBD_DTG_RX_TOGGLE(ep_id)
#define USBD_SWBUF_RX_TOGGLE(ep_id)    USBD_DTG_TX_TOGGLE(ep_id)

#endif /* USBD_REGS_H */