/*
  * TTFAcc.h: Interface file for TTFAcc.c - Written by Louise Pathe
  *
  * Copyright 1990-1997. Microsoft Corporation.
  * 
  */

/* NOTE: must include TYPEDEFS.H and TTFF.H before this file */
/* must include ttfcntrl.h after this file in order to use the *Generic functions */
  
#ifndef TTFACC_DOT_H_DEFINED
#define TTFACC_DOT_H_DEFINED        

#ifndef NO_ERROR
#define NO_ERROR 0
#endif
#ifndef ERR_GENERIC
#define ERR_GENERIC 1000  
#define ERR_READOUTOFBOUNDS 1001	/* trying to read from memory not allowed - data error? */
#define ERR_WRITEOUTOFBOUNDS 1002	/* trying to write to memory not allowed - data error? */
#define ERR_READCONTROL 1003	/* read control structure does not match data */
#define ERR_WRITECONTROL 1004	/* write control structure does not match data */
#define ERR_MEM 1005   /* error allocating memory */
#define ERR_FORMAT 1006 /* input data format error */
#endif

#define TTFACC_BYTE 0x01   /* read/write/pad 1 byte */
#define TTFACC_WORD 0x02   /* read/write/pad 1 word */
#define TTFACC_LONG 0x04   /* read/write/pad 1 long word */
#define TTFACC_DATA 0x07  /* bits that define data size */
#define TTFACC_PAD  0x10   /* pad by whatever is specified */
#define TTFACC_NO_XLATE  0x20   /* don't translate the data */

#ifndef CFP_ALLOCPROC_DEFINED
#define CFP_ALLOCPROC_DEFINED
typedef void *(*CFP_ALLOCPROC)(size_t);
typedef void *(*CFP_REALLOCPROC)(void *, size_t);
typedef void (*CFP_FREEPROC)(void *);
#endif

typedef struct TTFACC_FILEBUFFERINFO {
	uint8 * puchBuffer;
	uint32 ulBufferSize;
	uint32 ulOffsetTableOffset;	/* offset into puchBuffer where OffsetTable begins */
	CFP_REALLOCPROC lpfnReAllocate;
} TTFACC_FILEBUFFERINFO;

typedef struct CONST_TTFACC_FILEBUFFERINFO {
	CONST uint8 * puchBuffer;
	uint32 ulBufferSize;
	uint32 ulOffsetTableOffset;	/* offset into puchBuffer where OffsetTable begins */
	CFP_REALLOCPROC lpfnReAllocate;
} CONST_TTFACC_FILEBUFFERINFO;

int16 ReadByte(TTFACC_FILEBUFFERINFO * pInputBufferInfo, uint8 * puchBuffer, uint32 ulOffset);
int16 ReadWord(TTFACC_FILEBUFFERINFO * pInputBufferInfo, uint16 * pusBuffer, uint32 ulOffset);
int16 ReadLong(TTFACC_FILEBUFFERINFO * pInputBufferInfo, uint32 * pulBuffer, uint32 ulOffset);
int16 ReadBytes(TTFACC_FILEBUFFERINFO * pInputBufferInfo, uint8 * puchBuffer, uint32 ulOffset, size_t Count);
int16 WriteByte(TTFACC_FILEBUFFERINFO * pOutputBufferInfo, uint8 uchValue, uint32 ulOffset);
int16 WriteWord(TTFACC_FILEBUFFERINFO * pOutputBufferInfo, uint16 usValue, uint32 ulOffset);
int16 WriteLong(TTFACC_FILEBUFFERINFO * pOutputBufferInfo, uint32 ulValue, uint32 ulOffset);
int16 WriteBytes(TTFACC_FILEBUFFERINFO * pOutputBufferInfo, uint8 * puchBuffer, uint32 ulOffset, size_t Count);

/* ReadGeneric - Generic read of data - Translation buffer provided for Word and Long swapping and RISC alignment handling */
/* 
Output:
puchDestBuffer updated with new data
Return:
0 or ErrorCode.
*/
int16 ReadGeneric(
TTFACC_FILEBUFFERINFO * pInputBufferInfo, /* buffer info of file buffer to read from */
uint8 * puchBuffer, 	/* buffer to read into - pad according to pControl data	*/
uint16 usBufferSize, 	/* size of buffer */
uint8 * puchControl, 	/* pControl - describes the size of each element in the structure, if a pad byte should be inserted in the output buffer */
uint32 ulOffset, 		/* offset into input TTF Buffer of where to read */
uint16 * pusBytesRead			/* number of bytes read from the file */
);

int16 ReadGenericRepeat(
TTFACC_FILEBUFFERINFO * pInputBufferInfo, /* buffer info of file buffer to read from */
uint8 * puchBuffer, 	/* buffer to read into - pad according to pControl data	*/
uint8 * puchControl, 	/* pControl - describes the size of each element in the structure, if a pad byte should be inserted in the output buffer */
uint32 ulOffset, 		/* offset into input TTF Buffer of where to read */
uint32 * pulBytesRead,	/* number of bytes read from the file */
uint16 usItemCount, 	/* number of times to read into the buffer */
uint16 usItemSize  		/* size of item in buffer */
);

/* WriteGeneric - Generic write of data - Translation buffer provided for Word and Long swapping and RISC alignment handling
Output:
puchDestBuffer updated with new data
Return:
Number of bytes written.
*/

int16 WriteGeneric(
TTFACC_FILEBUFFERINFO * pOutputBufferInfo,
uint8 * puchBuffer, 
uint16 usBufferSize,
uint8 * puchControl, 
uint32 ulOffset, /* offset into output TTF Buffer of where to write */
uint16 *pusBytesWritten
);

int16 WriteGenericRepeat(
TTFACC_FILEBUFFERINFO * pOutputBufferInfo,
uint8 * puchBuffer, 	/* buffer to read from - pad according to pControl data	*/
uint8 * puchControl, 	/* pControl - describes the size of each element in the structure, if a pad byte should be inserted in the output buffer */
uint32 ulOffset, 		/* offset into output TTF Buffer of where to write */
uint32 * pulBytesWritten,/* number of bytes written to the file */
uint16 usItemCount, 	/* number of times to read into the buffer */
uint16 usItemSize 		/* size of item in buffer */
);

uint16 GetGenericSize(uint8 * puchControl); 
int16 CalcChecksum( TTFACC_FILEBUFFERINFO * pInputBufferInfo, 
				  uint32 ulOffset,
				  uint32 ulLength,
                  uint32 * pulChecksum );
uint32 CalcFileChecksum( TTFACC_FILEBUFFERINFO * pInputBufferInfo, uint32 ulLength ) ;

#endif /* TTFACC_DOT_H_DEFINED */
