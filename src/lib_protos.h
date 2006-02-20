/***************************************************************************

 codesets.library - Amiga shared library for handling different codesets
 Copyright (C) 2001-2005 by Alfonso [alfie] Ranieri <alforan@tin.it>.
 Copyright (C) 2005      by codesets.library Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 codesets.library project: http://sourceforge.net/projects/codesetslib/

 $Id$

***************************************************************************/

#ifndef _LIB_PROTOS_H
#define _LIB_PROTOS_H

#include "SDI_lib.h"

/* init.c */
void freeBase(struct LibraryHeader* lib);
ULONG initBase(struct LibraryHeader* lib);

/* utils.c */
APTR allocVecPooled(APTR pool, ULONG size);
void freeVecPooled(APTR pool, APTR mem);
APTR allocArbitratePooled(ULONG s);
void freeArbitratePooled(APTR mem , ULONG s);
APTR allocArbitrateVecPooled(ULONG size);
void freeArbitrateVecPooled(APTR mem);
int countNodes(struct MinList *List);

#ifdef __MORPHOS__
void sprintf(STRPTR buf, STRPTR fmt, ...) __attribute((varargs68k));
int snprintf(STRPTR buf, int size, STRPTR fmt, ...) __attribute((varargs68k));
#elif !defined(__amigaos4__)
void STDARGS sprintf(STRPTR to, STRPTR fmt, ...);
int STDARGS snprintf(STRPTR buf, int size, STRPTR fmt, ...);
#endif

/* base64.c */
LIBPROTO(CodesetsEncodeB64A, ULONG, REG(a0, struct TagItem *attrs));
LIBPROTOVA(CodesetsEncodeB64,ULONG, ...);
LIBPROTO(CodesetsDecodeB64A, ULONG, REG(a0, struct TagItem *attrs));
LIBPROTOVA(CodesetsDecodeB64,ULONG, ...);

/* convertUTF.c */
LIBPROTO(CodesetsConvertUTF32toUTF16, ULONG, REG(a0, const UTF32 **sourceStart), REG(a1, const UTF32 *sourceEnd), REG(a2, UTF16 **targetStart), REG(a3, UTF16 *targetEnd), REG(d0, ULONG flags));
LIBPROTO(CodesetsConvertUTF16toUTF32, ULONG, REG(a0, const UTF16 **sourceStart), REG(a1, const UTF16 *sourceEnd), REG(a2, UTF32 **targetStart), REG(a3, UTF32 *targetEnd), REG(d0, ULONG flags));
LIBPROTO(CodesetsConvertUTF16toUTF8,  ULONG, REG(a0, const UTF16 **sourceStart), REG(a1, const UTF16 *sourceEnd) , REG(a2, UTF8 **targetStart), REG(a3, UTF8 *targetEnd), REG(d0, ULONG flags));
LIBPROTO(CodesetsIsLegalUTF8,         ULONG, REG(a0, const UTF8 *source), REG(d0, ULONG length));
LIBPROTO(CodesetsIsLegalUTF8Sequence, ULONG, REG(a0, const UTF8 *source), REG(a1, const UTF8 *sourceEnd));
LIBPROTO(CodesetsConvertUTF8toUTF16,  ULONG, REG(a0, const UTF8 **sourceStart), REG(a1, const UTF8 *sourceEnd), REG(a2, UTF16 **targetStart), REG(a3, UTF16 *targetEnd), REG(d0, ULONG flags));
LIBPROTO(CodesetsConvertUTF32toUTF8,  ULONG, REG(a0, const UTF32 **sourceStart), REG(a1, const UTF32 *sourceEnd), REG(a2, UTF8 **targetStart), REG(a3, UTF8 *targetEnd), REG(d0, ULONG flags));
LIBPROTO(CodesetsConvertUTF8toUTF32,  ULONG, REG(a0, const UTF8 **sourceStart), REG(a1, const UTF8 *sourceEnd), REG(a2, UTF32 **targetStart), REG(a3, UTF32 *targetEnd), REG(d0, ULONG flags));

/* codesets.c */
BOOL codesetsInit(struct MinList *codesetsList);
void codesetsCleanup(struct MinList *codesetsList);
struct codeset *codesetsFind(struct MinList *codesetsList, STRPTR name);
struct codeset *codesetsFindBest(struct MinList *codesetsList, STRPTR text, int text_len, int *error_ptr);

LIBPROTO(CodesetsSupportedA,  STRPTR *, REG(a0, struct TagItem *attrs));
LIBPROTOVA(CodesetsSupported, STRPTR *, ...);
LIBPROTO(CodesetsFreeA,       void, REG(a0, APTR obj), REG(a1, struct TagItem *attrs));
LIBPROTOVA(CodesetsFree,      void, REG(a0, APTR obj), ...);
LIBPROTO(CodesetsSetDefaultA, struct codeset *, REG(a0, STRPTR name), REG(a1, struct TagItem *attrs));
LIBPROTOVA(CodesetsSetDefault,struct codeset *, REG(a0, STRPTR name), ...);
LIBPROTO(CodesetsFindA,       struct codeset *, REG(a0, STRPTR name), REG(a1, struct TagItem *attrs));
LIBPROTOVA(CodesetsFind,      struct codeset *, REG(a0, STRPTR name), ...);
LIBPROTO(CodesetsFindBestA,   struct codeset *, REG(a0, STRPTR text) , REG(d0, ULONG text_len) , REG(a1, ULONG *error_ptr), REG(a2, struct TagItem *attrs));
LIBPROTOVA(CodesetsFindBest,  struct codeset *, REG(a0, STRPTR text) , REG(d0, ULONG text_len) , REG(a1, ULONG *error_ptr), ...);
LIBPROTO(CodesetsStrLenA,     ULONG, REG(a0, STRPTR str), REG(a1, struct TagItem *attrs));
LIBPROTOVA(CodesetsStrLen,    ULONG, REG(a0, STRPTR str), ...);
LIBPROTO(CodesetsConvertStrA, STRPTR, REG(a0, struct TagItem *attrs));
LIBPROTOVA(CodesetsConvertStr,STRPTR, ...);
LIBPROTO(CodesetsUTF8ToStrA,  STRPTR, REG(a0, struct TagItem *attrs));
LIBPROTOVA(CodesetsUTF8ToStr, STRPTR, ...);
LIBPROTO(CodesetsUTF8CreateA, UTF8 *, REG(a0, struct TagItem *attrs));
LIBPROTOVA(CodesetsUTF8Create,UTF8 *, ...);
LIBPROTO(CodesetsFreeVecPooledA, void, REG(a0, APTR pool), REG(a1, APTR mem), REG(a2, struct TagItem *attrs));
LIBPROTOVA(CodesetsFreeVecPooled,void, REG(a0, APTR pool), REG(a1, APTR mem), ...);
LIBPROTO(CodesetsIsValidUTF8,ULONG, REG(a0, STRPTR s));
LIBPROTO(CodesetsUTF8Len,    ULONG, REG(a0, UTF8 *str));
LIBPROTO(CodesetsListCreateA, struct MinList *, REG(a0, struct TagItem *attrs));
LIBPROTOVA(CodesetsListCreate, struct MinList *, ...);
LIBPROTO(CodesetsListDelete, void, REG(a0, struct MinList *codesetsList));
LIBPROTO(CodesetsListAddA, void, REG(a0, struct MinList *codesetsList), REG(a1, struct TagItem *attrs));
LIBPROTOVA(CodesetsListAdd, void, REG(a0, struct MinList *codesetsList), ...);
LIBPROTO(CodesetsListRemoveA, void, REG(a0, struct TagItem *attrs));
LIBPROTOVA(CodesetsListRemove, void, ...);

#endif /* _LIB_PROTOS_H */
