#ifndef USE_MACRO_H
#define USE_MACRO_H
#define my_add(x, y) ((x) + (y))
#define my_max(op1, op2) ((op1 > op2) ? (op1) : (op2))

#define my_string1(x) x
#define my_string2(x) #x
#define my_string3(x) my_string2(x)
#define my_string4(x) my__##x
#define my__string4 "string4"

#endif // USE_MACRO_H