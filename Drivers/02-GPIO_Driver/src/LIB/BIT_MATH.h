#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(Reg, BitNo) (Reg |= (1 << BitNo))
#define CLR_BIT(Reg, BitNo) (Reg &= ~(1 << BitNo))
#define GET_BIT(Reg, BitNo) ((Reg >> BitNo) & 1)

#define CONC_32BIT(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)  Conc_32help(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_32help(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) 0b##b31##b30##b29##b28##b27##b26##b25##b24##b23##b22##b21##b20##b19##b18##b17##b16##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0


#define CONC_16_2BIT(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)  Conc_16_2help(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_16_2help(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) 0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0
#endif
