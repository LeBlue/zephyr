/*
 * Copyright (c) 2019 Matthias Wauer
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __INC_BOARD_H
#define __INC_BOARD_H

/* External edge connector pin mappings to nRF51 GPIO pin numbers.
 * More information:
 * https://calliope-mini.github.io/v10/
 * https://calliope-mini.github.io/assets/v10/img/Calliope%20mini%20rev1.3.png
 * TODO
 */

/* This is how it is named in the schematic file, header EXP1 */
#define EXT_EXP1_P1_GPIO_PIN         /* EXT1 P1, GND */
#define EXT_EXP1_P2_GPIO_PIN         /* EXT1 P2, 3.3V */
#define EXT_EXP1_P3_GPIO_PIN     19  /* P3, I2C0 SCL */
#define EXT_EXP1_P4_GPIO_PIN     20  /* P4, I2C0 SDA */
#define EXT_EXP1_P5_GPIO_PIN     27  /* P5, UART(1) TX */
#define EXT_EXP1_P6_GPIO_PIN     26  /* P6, UART(1) RX */
#define EXT_EXP1_P7_GPIO_PIN     15  /* P7, LED Row 3 */
#define EXT_EXP1_P8_GPIO_PIN     14  /* P8, LED Row 2 */
#define EXT_EXP1_P9_GPIO_PIN     13  /* P9, LED Row 1 */
#define EXT_EXP1_P10_GPIO_PIN    12  /* P10, LED Col 9 */
#define EXT_EXP1_P11_GPIO_PIN    11  /* P11, LED Col 8 */
#define EXT_EXP1_P12_GPIO_PIN    10  /* P12, LED Col 7  */
#define EXT_EXP1_P13_GPIO_PIN      /* P13, GND */
#define EXT_EXP1_P14_GPIO_PIN      /* P14, GND */
#define EXT_EXP1_P15_GPIO_PIN     9  /* P15, LED Col 6 */
#define EXT_EXP1_P16_GPIO_PIN     8  /* P16, LED Col 5  */
#define EXT_EXP1_P17_GPIO_PIN     7  /* P17, LED Col 4  */
#define EXT_EXP1_P18_GPIO_PIN     6  /* P18, LED Col 3  */
#define EXT_EXP1_P19_GPIO_PIN     5  /* P19, LED Col 2 */
#define EXT_EXP1_P20_GPIO_PIN     4  /* P20, LED Col 1 */
#define EXT_EXP1_P21_GPIO_PIN    22  /* P21,*/
#define EXT_EXP1_P22_GPIO_PIN     2  /* P22,*/
#define EXT_EXP1_P23_GPIO_PIN     1  /* P23*/
#define EXT_EXP1_P24_GPIO_PIN     0  /* P24,*/
#define EXT_EXP1_P25_GPIO_PIN      /* P20, VCC */
#define EXT_EXP1_P26_GPIO_PIN      /* P20, GND */

/* These are the aliases from the assembly overview */
/* All the C* aliases */
#define EXT_C0_GPIO_PIN   EXT_EXP1_P24_GPIO_PIN /* C0 */
#define EXT_C1_GPIO_PIN   EXT_EXP1_P23_GPIO_PIN /* C1 */
#define EXT_C2_GPIO_PIN   EXT_EXP1_P22_GPIO_PIN /* C2 */
#define EXT_C3_GPIO_PIN   EXT_EXP1_P21_GPIO_PIN /* C3 */
#define EXT_C4_GPIO_PIN   EXT_EXP1_P20_GPIO_PIN /* C4 */
#define EXT_C5_GPIO_PIN   EXT_EXP1_P19_GPIO_PIN /* C5 */
#define EXT_C6_GPIO_PIN   EXT_EXP1_P18_GPIO_PIN /* C6 */
#define EXT_C7_GPIO_PIN   EXT_EXP1_P17_GPIO_PIN /* C7 */
#define EXT_C8_GPIO_PIN   EXT_EXP1_P16_GPIO_PIN /* C8 */
#define EXT_C9_GPIO_PIN   EXT_EXP1_P15_GPIO_PIN /* C9 */

#define EXT_C10_GPIO_PIN  EXT_EXP1_P12_GPIO_PIN /* C10 */
#define EXT_C11_GPIO_PIN  EXT_EXP1_P11_GPIO_PIN /* C11 */
#define EXT_C12_GPIO_PIN  EXT_EXP1_P10_GPIO_PIN /* C12 */
#define EXT_C13_GPIO_PIN  EXT_EXP1_P9_GPIO_PIN /* C13 */
#define EXT_C14_GPIO_PIN  EXT_EXP1_P8_GPIO_PIN /* C14 */
#define EXT_C15_GPIO_PIN  EXT_EXP1_P7_GPIO_PIN /* C15 */

#define EXT_C16_GPIO_PIN  EXT_EXP1_P6_GPIO_PIN /* C16 UART RX*/
#define EXT_C17_GPIO_PIN  EXT_EXP1_P5_GPIO_PIN /* C17 UART TX*/
#define EXT_C18_GPIO_PIN  EXT_EXP1_P4_GPIO_PIN /* C18 I2C0 SCL*/
#define EXT_C19_GPIO_PIN  EXT_EXP1_P3_GPIO_PIN /* C19 I2C0 SDA*/
/* ?? */
/* #define EXT_C20_GPIO_PIN  EXT_EXP1_P5_GPIO_PIN
#define EXT_C21_GPIO_PIN  EXT_EXP1_P4_GPIO_PIN*/

/* Labeled BANANA_PCB in the SCH, P* aliases */
#define EXT_P0_GPIO_PIN   EXT_C0_GPIO_PIN
#define EXT_P1_GPIO_PIN   EXT_C1_GPIO_PIN
#define EXT_P2_GPIO_PIN   EXT_C2_GPIO_PIN
#define EXT_P3_GPIO_PIN   EXT_C3_GPIO_PIN

/* header A0 aliases */
#define EXT_A0_P1_GPIO_PIN  EXT_C18_GPIO_PIN /* I2C0 SDA */
#define EXT_SDA_GPIO_PIN    EXT_C18_GPIO_PIN
#define EXT_A0_P2_GPIO_PIN  EXT_C19_GPIO_PIN /* I2C0 SCL */
#define EXT_SCL_GPIO_PIN    EXT_C19_GPIO_PIN
#define EXT_A0_P3_GPIO_PIN      /* P3, VCC */
#define EXT_A0_P4_GPIO_PIN      /* P4, GND */

/* header A1 aliases */
#define EXT_A1_P1_GPIO_PIN  EXT_C16_GPIO_PIN /* UART(?) RX */
#define EXT_TX_GPIO_PIN     EXT_C16_GPIO_PIN
#define EXT_A1_P2_GPIO_PIN  EXT_C17_GPIO_PIN /* UART(?) TX */
#define EXT_RX_GPIO_PIN     EXT_C17_GPIO_PIN
#define EXT_A1_P3_GPIO_PIN      /* P3, VCC */
#define EXT_A1_P4_GPIO_PIN      /* P4, GND */


#endif /* __INC_BOARD_H */
