#ifndef DEF_H
#define DEF_H 0

#include <stdlib.h>
#define MAX_PROGRAM_SIZE 256 /*max program size line count to be assembled*/
#define ASM_SOURCE_SUFF ".as"	/*assembly source file suffix*/
#define ASM_OBJECT_SUFF ".ob"	 /*assembly object file suffix*/
#define ASM_ENTRIES_SUFF ".ent"  /*assembly entries file suffix*/
#define ASM_EXTERNALS_SUFF ".ext"  /*assembly externals file suffix*/
#define MAX_FILE_NAME 1000 /*max file path length for source assembly files*/
#define MAX_LN_LEN 80 /* max line size in assembly source file */
#define MMRY_OFFSET 100  /*memory address of the assembled program after it was loaded to memory*/
#define MAX_LBL_SZ 31  /*max char count for labe name*/
#define MAX_OP_NUM 3 /* maximum args in one line (command name, 1st & 2nd operands */

typedef struct instInfo {
	char *instName; /* insturction name */
	int opCode; /* insturction opCode */
	int funct; /* insturction funct, 0 if no funct */
	int firstOp; /* valid addressing methods for first arg */
	int secondOp; /* valid addressing methods for first arg */
} instInfo;

typedef struct psw_register /* TODO: what is it for? */
{
	unsigned int zero_flag:1;
} psw_register;

extern int lineNumber;
extern int dataImg[MAX_PROGRAM_SIZE];
extern int instImg[MAX_PROGRAM_SIZE];
extern int IC; /* instruction counter */
extern int DC; /* data counter  */

enum guideType {NO_GUIDE, DATA, STR, ENTRY, EXTERN, CODE};/*enum for label types*/
enum instAddressType {NON =-1, IMM = 0, DIR = 1, REL = 2, REG = 3 }; /*enum for operand types*/
enum codingType { ABS = 0, RELOC = 1, EXT = 2 }; /*enum for coding types*/

#endif
