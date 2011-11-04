
/* Written by Peter Ekberg, peda@lysator.liu.se */

#include "../src/thrust_t.h"

byte font[256][6] =
 {
   { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x01 ,
    0x02 ,
    0x14 ,   /* Ctrl-\ */
    0x18 ,
    0x10 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 5,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 3,
    0x00 ,
    0x00 ,
    0x00 ,   /*   */
    0x00 ,
    0x00 },

  { 1,
    0x01 ,
    0x01 ,
    0x01 ,
    0x00 ,   /* ! */
    0x01 },

  { 3,
    0x05 ,
    0x00 ,   /* " */
    0x00 ,
    0x00 ,
    0x00 },

  { 5,
    0x0a ,   /* # */
    0x1f ,
    0x0a ,
    0x1f ,
    0x0a },

  { 5,
    0x0f ,
    0x14 ,
    0x0e ,   /* $ */
    0x05 ,
    0x1e },

  { 5,
    0x11 ,
    0x02 ,
    0x04 ,   /* % */
    0x08 ,
    0x11 },

  { 5,
    0x08 ,
    0x14 ,
    0x0d ,   /* & */
    0x12 ,
    0x0d },

  { 2,
    0x01 ,
    0x02 ,
    0x00 ,
    0x00 ,   /* ' */
    0x00 },

  { 2,
    0x01 ,
    0x02 ,
    0x02 ,   /* ( */
    0x02 ,
    0x01 },

  { 2,
    0x02 ,
    0x01 ,   /* ) */
    0x01 ,
    0x01 ,
    0x02 },

  { 3,
    0x00 ,
    0x05 ,   /* * */
    0x02 ,
    0x05 ,
    0x00 },

  { 3,
    0x00 ,
    0x02 ,
    0x07 ,
    0x02 ,   /* + */
    0x00 },

  { 3,
    0x00 ,
    0x00 ,   /* , */
    0x00 ,
    0x02 ,
    0x04 },

  { 3,
    0x00 ,
    0x00 ,   /* - */
    0x07 ,
    0x00 ,
    0x00 },

  { 3,
    0x00 ,
    0x00 ,   /* . */
    0x00 ,
    0x06 ,
    0x06 },

  { 3,
    0x00 ,
    0x01 ,
    0x02 ,
    0x04 ,   /* / */
    0x00 },

  { 5,
    0x0e ,   /* 0 */
    0x11 ,
    0x15 ,
    0x11 ,
    0x0e },

  { 5,
    0x04 ,
    0x0c ,   /* 1 */
    0x04 ,
    0x04 ,
    0x0e },

  { 5,
    0x0e ,
    0x01 ,   /* 2 */
    0x0e ,
    0x10 ,
    0x1f },

  { 5,
    0x0e ,
    0x01 ,   /* 3 */
    0x06 ,
    0x01 ,
    0x1e },

  { 5,
    0x02 ,
    0x06 ,
    0x0a ,   /* 4 */
    0x1f ,
    0x02 },

  { 5,
    0x1e ,
    0x10 ,
    0x1e ,
    0x01 ,   /* 5 */
    0x1e },

  { 5,
    0x0e ,
    0x10 ,   /* 6 */
    0x1e ,
    0x11 ,
    0x0e },

  { 5,
    0x1f ,
    0x02 ,   /* 7 */
    0x04 ,
    0x08 ,
    0x08 },

  { 5,
    0x0e ,
    0x11 ,   /* 8 */
    0x0e ,
    0x11 ,
    0x0e },

  { 5,
    0x0e ,
    0x11 ,
    0x0f ,   /* 9 */
    0x01 ,
    0x0e },

  { 1,
    0x00 ,
    0x01 ,
    0x00 ,   /* : */
    0x01 ,
    0x00 },

  { 2,
    0x00 ,
    0x01 ,   /* ; */
    0x00 ,
    0x01 ,
    0x02 },

  { 3,
    0x01 ,
    0x02 ,   /* < */
    0x04 ,
    0x02 ,
    0x01 },

  { 3,
    0x00 ,
    0x07 ,   /* = */
    0x00 ,
    0x07 ,
    0x00 },

  { 3,
    0x04 ,
    0x02 ,
    0x01 ,   /* > */
    0x02 ,
    0x04 },

  { 4,
    0x0e ,
    0x01 ,
    0x06 ,   /* ? */
    0x00 ,
    0x04 },

  { 5,
    0x0e ,
    0x11 ,   /* @ */
    0x17 ,
    0x10 ,
    0x0e },

  { 5,
    0x04 ,   /* A */
    0x0a ,
    0x11 ,
    0x1f ,
    0x11 },

  { 5,
    0x1c ,
    0x12 ,
    0x1e ,   /* B */
    0x11 ,
    0x1e },

  { 5,
    0x0c ,
    0x12 ,   /* C */
    0x10 ,
    0x11 ,
    0x0e },

  { 5,
    0x1c ,
    0x12 ,   /* D */
    0x11 ,
    0x11 ,
    0x1e },

  { 5,
    0x1e ,
    0x10 ,
    0x1c ,   /* E */
    0x10 ,
    0x1f },

  { 4,
    0x0f ,
    0x08 ,
    0x0e ,   /* F */
    0x08 ,
    0x08 },

  { 5,
    0x0e ,
    0x10 ,
    0x17 ,   /* G */
    0x11 ,
    0x0e },

  { 4,
    0x09 ,
    0x09 ,
    0x0f ,
    0x09 ,   /* H */
    0x09 },

  { 3,
    0x07 ,
    0x02 ,
    0x02 ,   /* I */
    0x02 ,
    0x07 },

  { 4,
    0x03 ,
    0x01 ,   /* J */
    0x01 ,
    0x09 ,
    0x06 },

  { 5,
    0x12 ,
    0x14 ,
    0x1c ,   /* K */
    0x12 ,
    0x11 },

  { 4,
    0x08 ,
    0x08 ,
    0x08 ,
    0x08 ,   /* L */
    0x0f },

  { 5,
    0x11 ,
    0x1b ,   /* M */
    0x15 ,
    0x11 ,
    0x11 },

  { 5,
    0x11 ,
    0x19 ,   /* N */
    0x15 ,
    0x13 ,
    0x11 },

  { 5,
    0x0e ,
    0x11 ,
    0x11 ,   /* O */
    0x11 ,
    0x0e },

  { 4,
    0x0e ,
    0x09 ,
    0x0e ,   /* P */
    0x08 ,
    0x08 },

  { 5,
    0x0e ,
    0x11 ,
    0x15 ,   /* Q */
    0x13 ,
    0x0f },

  { 5,
    0x1e ,
    0x11 ,
    0x1e ,
    0x12 ,   /* R */
    0x11 },

  { 5,
    0x0e ,
    0x10 ,   /* S */
    0x0e ,
    0x01 ,
    0x1e },

  { 5,
    0x1f ,
    0x04 ,   /* T */
    0x04 ,
    0x04 ,
    0x04 },

  { 5,
    0x11 ,
    0x11 ,   /* U */
    0x11 ,
    0x11 ,
    0x0e },

  { 5,
    0x11 ,
    0x11 ,
    0x0a ,   /* V */
    0x0a ,
    0x04 },

  { 5,
    0x11 ,
    0x11 ,   /* W */
    0x15 ,
    0x15 ,
    0x0a },

  { 5,
    0x11 ,
    0x0a ,
    0x04 ,   /* X */
    0x0a ,
    0x11 },

  { 5,
    0x11 ,
    0x11 ,
    0x0e ,   /* Y */
    0x04 ,
    0x04 },

  { 5,
    0x1f ,
    0x02 ,
    0x04 ,   /* Z */
    0x08 ,
    0x1f },

  { 2,
    0x03 ,
    0x02 ,   /* [ */
    0x02 ,
    0x02 ,
    0x03 },

  { 5,
    0x10 ,
    0x08 ,   /* \ */
    0x04 ,
    0x02 ,
    0x01 },

  { 2,
    0x03 ,
    0x01 ,
    0x01 ,   /* ] */
    0x01 ,
    0x03 },

  { 3,
    0x02 ,
    0x05 ,   /* ^ */
    0x00 ,
    0x00 ,
    0x00 },

  { 4,
    0x00 ,
    0x00 ,
    0x00 ,   /* _ */
    0x00 ,
    0x0f },

  { 2,
    0x02 ,
    0x01 ,
    0x00 ,
    0x00 ,   /* ` */
    0x00 },

  { 5,
    0x00 ,   /* a */
    0x0c ,
    0x12 ,
    0x12 ,
    0x0d },

  { 4,
    0x08 ,
    0x08 ,
    0x0e ,   /* b */
    0x09 ,
    0x0e },

  { 4,
    0x00 ,
    0x07 ,   /* c */
    0x08 ,
    0x08 ,
    0x07 },

  { 4,
    0x01 ,
    0x01 ,   /* d */
    0x07 ,
    0x09 ,
    0x07 },

  { 4,
    0x00 ,
    0x07 ,
    0x0f ,   /* e */
    0x08 ,
    0x07 },

  { 3,
    0x03 ,
    0x02 ,
    0x07 ,   /* f */
    0x02 ,
    0x02 },

  { 4,
    0x00 ,
    0x07 ,
    0x0f ,   /* g */
    0x01 ,
    0x06 },

  { 4,
    0x08 ,
    0x08 ,
    0x0e ,
    0x09 ,   /* h */
    0x09 },

  { 1,
    0x01 ,
    0x00 ,
    0x01 ,   /* i */
    0x01 ,
    0x01 },

  { 3,
    0x01 ,
    0x00 ,   /* j */
    0x01 ,
    0x01 ,
    0x06 },

  { 4,
    0x08 ,
    0x09 ,
    0x0a ,   /* k */
    0x0e ,
    0x09 },

  { 1,
    0x01 ,
    0x01 ,
    0x01 ,
    0x01 ,   /* l */
    0x01 },

  { 5,
    0x00 ,
    0x1a ,   /* m */
    0x15 ,
    0x15 ,
    0x15 },

  { 4,
    0x00 ,
    0x0e ,   /* n */
    0x09 ,
    0x09 ,
    0x09 },

  { 4,
    0x00 ,
    0x06 ,
    0x09 ,   /* o */
    0x09 ,
    0x06 },

  { 4,
    0x00 ,
    0x0e ,
    0x09 ,   /* p */
    0x0e ,
    0x08 },

  { 4,
    0x00 ,
    0x07 ,
    0x09 ,   /* q */
    0x07 ,
    0x01 },

  { 3,
    0x00 ,
    0x07 ,
    0x04 ,
    0x04 ,   /* r */
    0x04 },

  { 4,
    0x00 ,
    0x07 ,   /* s */
    0x0c ,
    0x03 ,
    0x0e },

  { 3,
    0x02 ,
    0x07 ,   /* t */
    0x02 ,
    0x02 ,
    0x03 },

  { 4,
    0x00 ,
    0x09 ,   /* u */
    0x09 ,
    0x09 ,
    0x06 },

  { 5,
    0x00 ,
    0x11 ,
    0x0a ,   /* v */
    0x0a ,
    0x04 },

  { 5,
    0x00 ,
    0x15 ,   /* w */
    0x15 ,
    0x15 ,
    0x0a },

  { 3,
    0x00 ,
    0x05 ,
    0x02 ,   /* x */
    0x02 ,
    0x05 },

  { 4,
    0x00 ,
    0x09 ,
    0x07 ,   /* y */
    0x02 ,
    0x04 },

  { 4,
    0x00 ,
    0x0f ,
    0x03 ,   /* z */
    0x0c ,
    0x0f },

  { 3,
    0x03 ,   /* { */
    0x02 ,
    0x04 ,
    0x02 ,
    0x03 },

  { 1,
    0x01 ,   /* | */
    0x01 ,
    0x01 ,
    0x01 ,
    0x01 },

  { 3,
    0x06 ,   /* } */
    0x02 ,
    0x01 ,
    0x02 ,
    0x06 },

  { 5,
    0x00 ,   /* ~ */
    0x08 ,
    0x15 ,
    0x02 ,
    0x00 },

  { 5,
    0x00 ,   /* ASCII 127 */
    0x00 ,
    0x00 ,
    0x00 ,
    0x00 }
  };
