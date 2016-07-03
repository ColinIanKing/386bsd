/* A lexical scanner generated by flex */

/* scanner skeleton version:
 *
 * $Header: flex/RCS/flex.skel,v 2.13 90/05/26 17:24:13 vern Exp $
 *
 *	@(#)lex.skel	5.5 (Berkeley) 5/6/91
 */

#define FLEX_SCANNER

#include <stdio.h>
#include <stdlib.h>

#ifdef __STDC__

#define YY_USE_PROTOS
#endif


/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif


#ifdef __cplusplus

#include <osfcn.h>

/* use prototypes in function declarations */
#define YY_USE_PROTOS

#endif


#ifdef YY_USE_PROTOS
#define YY_PROTO(proto) proto
#else
#define YY_PROTO(proto) ()
#endif


/* amount of stuff to slurp up with each read */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

/* returned upon end-of-file */
#define YY_END_TOK 0

/* copy whatever the last rule matched to the standard output */

/* cast to (char *) is because for 8-bit chars, yytext is (unsigned char *) */
/* this used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite()
 */
#define ECHO (void) fwrite( (char *) yytext, yyleng, 1, yyout )

/* gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#define YY_INPUT(buf,result,max_size) \
	if ( (result = read( fileno(yyin), (char *) buf, max_size )) < 0 ) \
	    YY_FATAL_ERROR( "read() in flex scanner failed" );
#define YY_NULL 0

/* no semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#define yyterminate() return ( YY_NULL )

/* report a fatal error */

/* The funky do-while is used to turn this macro definition into
 * a single C statement (which needs a semi-colon terminator).
 * This avoids problems with code like:
 *
 * 	if ( something_happens )
 *		YY_FATAL_ERROR( "oops, the something happened" );
 *	else
 *		everything_okay();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the YY_FATAL_ERROR() call.
 */

#define YY_FATAL_ERROR(msg) \
	do \
		{ \
		(void) fputs( msg, stderr ); \
		(void) putc( '\n', stderr ); \
		exit( 1 ); \
		} \
	while ( 0 )

/* default yywrap function - always treat EOF as an EOF */
#define yywrap() 1

/* enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN
 */
#define BEGIN yy_start = 1 + 2 *

/* action number for EOF rule of a given start state */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

/* special action meaning "start processing a new file" */
#define YY_NEW_FILE \
	do \
		{ \
		yy_init_buffer( yy_current_buffer, yyin ); \
		yy_load_buffer_state(); \
		} \
	while ( 0 )

/* default declaration of generated scanner - a define so the user can
 * easily add parameters
 */
#define YY_DECL int yylex YY_PROTO(( void )) 

/* code executed at the end of each rule */
#define YY_BREAK break;

#define YY_END_OF_BUFFER_CHAR 0

#ifndef YY_BUF_SIZE
#define YY_BUF_SIZE (YY_READ_BUF_SIZE * 2) /* size of default input buffer */
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;

#define YY_CHAR char
# line 1 "tcplex.l"
#define INITIAL 0
# line 2 "tcplex.l"
/*
 * Copyright (c) 1988-1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that: (1) source code distributions
 * retain the above copyright notice and this paragraph in its entirety, (2)
 * distributions including binary code include the above copyright notice and
 * this paragraph in its entirety in the documentation or other materials
 * provided with the distribution, and (3) all advertising materials mentioning
 * features or use of this software display the following acknowledgement:
 * ``This product includes software developed by the University of California,
 * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of
 * the University nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef lint
static char rcsid[] =
    "@(#) $Header: tcplex.l,v 1.21 91/06/06 22:35:55 mccanne Exp $ (LBL)";
#endif

/*
 * Compiling with gcc under SunOS will cause problems unless we have this
 * cruft here.  The flex skeleton includes stddef.h which defines these types
 * (under gcc).  They will conflict with Sun's definitions in sys/types.h.
 */
#define size_t xxxsize_t
#define ptrdiff_t xxxptrdiff_t
#include <sys/types.h>
#undef size_t
#undef ptrdiff_t

#include "nametoaddr.h"

/*
 * We need bpf since enum bpf_code is in YYSTYPE.
 */
#include <sys/time.h>
#include <net/bpf.h>

#include "tokdefs.h"

#ifdef FLEX_SCANNER
#undef YY_INPUT
#define YY_INPUT(buf, result, max)\
 {\
	char *src = in_buffer;\
	int i;\
\
	if (*src == 0)\
		result = YY_NULL;\
	else {\
		for (i = 0; *src && i < max; ++i)\
			buf[i] = *src++;\
		in_buffer += i;\
		result = i;\
	}\
 }
#else
#undef getc
#define getc(fp)  (*in_buffer == 0 ? EOF : *in_buffer++)
#endif

extern YYSTYPE yylval;
static char *in_buffer;

# line 80 "tcplex.l"

/* done after the current pattern has been matched and before the
 * corresponding action - sets up yytext
 */
#define YY_DO_BEFORE_ACTION \
	yytext = yy_bp; \
	yyleng = yy_cp - yy_bp; \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* return all but the first 'n' matched characters back to the input stream */
#define yyless(n) \
	do \
		{ \
		/* undo effects of setting up yytext */ \
		*yy_cp = yy_hold_char; \
		yy_c_buf_p = yy_cp = yy_bp + n; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

#define unput(c) yyunput( c, yytext )


struct yy_buffer_state
    {
    FILE *yy_input_file;

    YY_CHAR *yy_ch_buf;		/* input buffer */
    YY_CHAR *yy_buf_pos;	/* current position in input buffer */

    /* size of input buffer in bytes, not including room for EOB characters*/
    int yy_buf_size;	

    /* number of characters read into yy_ch_buf, not including EOB characters */
    int yy_n_chars;

    int yy_eof_status;		/* whether we've seen an EOF on this buffer */
#define EOF_NOT_SEEN 0
    /* "pending" happens when the EOF has been seen but there's still
     * some text process
     */
#define EOF_PENDING 1
#define EOF_DONE 2
    };

static YY_BUFFER_STATE yy_current_buffer;

/* we provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state"
 */
#define YY_CURRENT_BUFFER yy_current_buffer


/* yy_hold_char holds the character lost when yytext is formed */
static YY_CHAR yy_hold_char;

static int yy_n_chars;		/* number of characters read into yy_ch_buf */



#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

#ifndef YY_USER_INIT
#define YY_USER_INIT
#endif

extern YY_CHAR *yytext;
extern int yyleng;
extern FILE *yyin, *yyout;

YY_CHAR *yytext;
int yyleng;

FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;

#define YY_END_OF_BUFFER 39
typedef int yy_state_type;
static const short int yy_accept[148] =
    {   0,
        0,    0,   39,   36,   23,   23,   24,   24,   24,   37,
       30,   30,   24,   24,   34,   34,   36,   34,   34,   34,
       34,   34,   34,   34,   34,   34,   34,   34,   34,   34,
       34,   34,   36,   27,    0,   30,    0,    0,    0,   28,
       26,   25,   29,   34,   34,   35,   35,   34,   34,   34,
       34,   34,   34,   34,   34,   34,   34,    6,   34,   34,
       34,   20,   34,   34,   34,   34,   34,   34,   31,   31,
       30,    0,    0,   30,   19,    4,   34,   34,    1,   34,
       34,   34,   34,   34,   22,   34,   11,   21,   34,   34,
       34,    2,    7,    8,    0,    0,    0,   33,    0,   34,

       17,   34,   34,   34,   10,    9,   15,   12,   34,    5,
       31,   31,   31,    0,   33,    0,   34,    3,   34,   34,
       13,    0,    0,    0,   33,   34,   34,   34,   31,   31,
       31,    0,   34,   14,   16,    0,    0,   33,   34,   31,
        0,   18,    0,   33,   32,   32,    0
    } ;

static const YY_CHAR yy_ec[128] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    2,    4,    1,    1,    1,    1,    5,    1,    6,
        6,    7,    7,    1,    8,    9,    7,   10,   11,   11,
       11,   11,   11,   11,   11,   11,   11,   12,    1,   13,
       14,   15,    1,    1,   16,   16,   16,   16,   16,   16,
       17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
       17,   17,   17,   17,   17,   17,   17,   18,   17,   17,
        5,   19,    5,    1,   20,    1,   21,   22,   23,   24,

       25,   16,   26,   27,   28,   17,   17,   29,   30,   31,
       32,   33,   17,   34,   35,   36,   37,   17,   38,   39,
       40,   17,    1,    5,    1,    1,    1
    } ;

static const YY_CHAR yy_meta[41] =
    {   0,
        1,    2,    2,    2,    1,    2,    1,    3,    3,    4,
        4,    5,    1,    1,    1,    4,    3,    3,    1,    3,
        4,    4,    4,    4,    4,    3,    3,    3,    3,    3,
        3,    3,    3,    3,    3,    3,    3,    3,    3,    3
    } ;

static const short int yy_base[166] =
    {   0,
        0,    0,  340,   40,  341,  341,  325,  341,   41,  341,
       52,   26,   32,   35,   82,  326,   71,   98,   48,   20,
       35,   46,   69,  101,   31,  103,   77,   84,   74,  105,
      113,   73,  126,  341,   89,  131,  325,  324,    0,  341,
      341,  341,  341,  323,  322,  143,    0,  125,  114,  119,
      118,  134,   75,  136,  140,  141,  144,  321,  146,  147,
      148,  320,  145,  154,  151,  152,  149,  155,  180,  183,
      186,  319,  318,  320,  316,  315,  157,  175,  314,  187,
      189,  159,  190,  191,  313,  192,  312,  311,  193,  194,
      195,  310,  309,  308,  198,    0,  307,  306,  305,  198,

      304,  199,  201,  204,  303,  302,  301,  300,  203,  299,
      227,  232,  301,  270,  263,  262,  208,  261,  211,  209,
      260,  207,    0,  259,  258,  232,   72,  213,  238,  240,
      259,  255,  234,  253,  252,    0,  251,  250,  240,    0,
      249,  248,  247,  246,  245,  243,  341,  275,  280,  282,
      250,  284,  286,  169,  288,  290,  292,  164,  294,  296,
       53,  298,  300,  302,  304
    } ;

static const short int yy_def[166] =
    {   0,
      147,    1,  147,  147,  147,  147,  147,  147,  147,  147,
      147,   11,  147,  147,  148,  148,  149,  148,   18,   18,
       18,  148,  148,  148,  148,  148,  148,  148,  148,  148,
      148,  148,  147,  147,  147,  147,  150,  147,  151,  147,
      147,  147,  147,  148,  148,  149,  149,  148,  148,  148,
      148,  148,  148,  148,  148,  148,  148,  148,  148,  148,
      148,  148,  148,  148,  148,  148,  148,  148,  147,  147,
      147,  152,  153,  151,  148,  148,  148,  148,  148,  148,
      148,  148,  148,  148,  148,  148,  148,  148,  148,  148,
      148,  148,  148,  148,  147,  154,  147,  155,  156,  148,

      148,  148,  148,  148,  148,  148,  148,  148,  148,  148,
      147,  147,  154,  157,  153,  147,  148,  148,  148,  148,
      148,  147,  158,  147,  159,  148,  148,  148,  147,  147,
      158,  160,  148,  148,  148,  161,  147,  162,  148,  161,
      163,  148,  147,  164,  165,  147,    0,  147,  147,  147,
      147,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147,  147,  147,  147,  147
    } ;

static const short int yy_nxt[382] =
    {   0,
        4,    5,    6,    7,    8,    8,    9,    8,   10,   11,
       12,    9,   13,    8,   14,   15,   16,   16,   17,   10,
       18,   19,   15,   20,   21,   22,   23,   24,   25,   16,
       26,   27,   28,   29,   30,   31,   32,   16,   16,   16,
       33,   33,  147,  147,   40,   41,   33,   33,   42,   43,
       44,   33,   33,   44,   52,   59,  140,  147,   33,   33,
       35,   36,   36,   37,  147,   44,   54,   38,   44,   39,
       53,   46,   38,   38,   38,   38,   38,   46,   44,   55,
      147,   50,   46,  147,  147,  147,  147,   51,  147,   46,
       39,   45,   45,   37,   65,  147,   68,   45,   69,   70,

       56,   80,   45,   45,   45,   45,   45,   45,   45,   37,
       62,  134,  147,   45,  147,   63,  147,   64,   45,   45,
       45,   45,   45,   57,  147,  147,   33,   60,   48,  147,
      147,   49,   33,   58,   61,   67,  147,   33,   66,   35,
       71,   71,   37,   46,   33,  147,   76,  147,   75,   46,
       77,  147,  147,   78,   46,  147,  147,  147,  147,  147,
      147,   46,  147,  147,   82,  147,  147,  131,  147,   79,
      147,   81,  113,   84,   92,   83,   85,  100,   89,  104,
       86,   93,   87,   88,   91,   90,  147,   94,   95,   70,
       70,   95,   70,   70,   35,   71,   71,   96,  147,  101,

      147,  147,  147,  147,  147,  147,  147,  111,  112,  147,
      147,  102,  147,  103,  147,  147,  129,  130,   96,  147,
      147,  117,  147,  106,  147,  105,  107,  110,  108,  109,
      126,  127,  118,  128,  121,  122,  112,  112,  119,  120,
      122,  112,  112,  147,  123,  147,  135,  130,  130,  130,
      130,  147,  133,   74,  115,  136,  115,  115,  144,  147,
      144,  115,  138,  147,  147,  123,  138,  122,  139,  115,
      125,  147,  147,  115,  115,  142,  136,   44,   44,   44,
       47,  125,   47,   47,   47,   72,   72,   97,   97,   99,
       99,  114,  114,  116,  116,  124,  124,  132,  132,  137,

      137,  141,  141,  143,  143,  145,  145,  146,  146,   95,
      147,  147,  147,  147,  147,  147,  115,  115,   98,  147,
      147,  147,  147,  147,  147,  147,  147,  147,   35,   73,
       98,  147,  147,   37,  147,   37,   73,  147,   34,  147,
        3,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147
    } ;

static const short int yy_chk[382] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        4,    9,   25,   12,   13,   13,    4,    9,   14,   14,
       20,    4,    9,   20,   20,   25,  161,   22,    4,    9,
       11,   11,   11,   11,   12,   21,   22,   11,   21,   11,
       21,   17,   11,   11,   11,   11,   11,   17,   19,   22,
       23,   19,   17,  127,   32,   29,   53,   19,   27,   17,
       11,   15,   15,   15,   29,   28,   32,   15,   35,   35,

       23,   53,   15,   15,   15,   15,   15,   18,   18,   18,
       27,  127,   24,   18,   26,   28,   30,   28,   18,   18,
       18,   18,   18,   24,   31,   49,   33,   26,   18,   51,
       50,   18,   33,   24,   26,   31,   48,   33,   30,   36,
       36,   36,   36,   46,   33,   52,   49,   54,   48,   46,
       50,   55,   56,   51,   46,   57,   63,   59,   60,   61,
       67,   46,   65,   66,   55,   64,   68,  158,   77,   52,
       82,   54,  154,   57,   66,   56,   59,   77,   63,   82,
       59,   67,   60,   61,   65,   64,   78,   68,   69,   69,
       69,   70,   70,   70,   71,   71,   71,   69,   80,   78,

       81,   83,   84,   86,   89,   90,   91,   95,   95,  100,
      102,   80,  103,   81,  109,  104,  122,  122,   69,  117,
      120,  100,  119,   84,  128,   83,   86,   91,   89,   90,
      117,  119,  102,  120,  109,  111,  111,  111,  103,  104,
      112,  112,  112,  126,  111,  133,  128,  129,  129,  130,
      130,  139,  126,  151,  146,  129,  145,  144,  143,  142,
      141,  138,  137,  135,  134,  111,  132,  131,  133,  125,
      124,  121,  118,  116,  115,  139,  129,  148,  148,  148,
      149,  114,  149,  149,  149,  150,  150,  152,  152,  153,
      153,  155,  155,  156,  156,  157,  157,  159,  159,  160,

      160,  162,  162,  163,  163,  164,  164,  165,  165,  113,
      110,  108,  107,  106,  105,  101,   99,   98,   97,   94,
       93,   92,   88,   87,   85,   79,   76,   75,   74,   73,
       72,   62,   58,   45,   44,   38,   37,   16,    7,    3,
      147,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147,  147,  147,  147,  147,  147,  147,  147,  147,  147,
      147
    } ;

static yy_state_type yy_last_accepting_state;
static YY_CHAR *yy_last_accepting_cpos;

/* the intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed
 */
#define REJECT reject_used_but_not_detected
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0

/* these variables are all declared out here so that section 3 code can
 * manipulate them
 */
/* points to current character in buffer */
static YY_CHAR *yy_c_buf_p = (YY_CHAR *) 0;
static int yy_init = 1;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */

/* flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yyin.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;

static yy_state_type yy_get_previous_state YY_PROTO(( void ));
static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));
static int yy_get_next_buffer YY_PROTO(( void ));
static void yyunput YY_PROTO(( YY_CHAR c, YY_CHAR *buf_ptr ));
void yyrestart YY_PROTO(( FILE *input_file ));
void yy_switch_to_buffer YY_PROTO(( YY_BUFFER_STATE new_buffer ));
void yy_load_buffer_state YY_PROTO(( void ));
YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));
void yy_delete_buffer YY_PROTO(( YY_BUFFER_STATE b ));
void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));

#define yy_new_buffer yy_create_buffer

#ifdef __cplusplus
static int yyinput YY_PROTO(( void ));
#else
static int input YY_PROTO(( void ));
#endif

YY_DECL
    {
    register yy_state_type yy_current_state;
    register YY_CHAR *yy_cp, *yy_bp;
    register int yy_act;



    if ( yy_init )
	{
	YY_USER_INIT;

	if ( ! yy_start )
	    yy_start = 1;	/* first start state */

	if ( ! yyin )
	    yyin = stdin;

	if ( ! yyout )
	    yyout = stdout;

	if ( yy_current_buffer )
	    yy_init_buffer( yy_current_buffer, yyin );
	else
	    yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );

	yy_load_buffer_state();

	yy_init = 0;
	}

    while ( 1 )		/* loops until end-of-file is reached */
	{
	yy_cp = yy_c_buf_p;

	/* support of yytext */
	*yy_cp = yy_hold_char;

	/* yy_bp points to the position in yy_ch_buf of the start of the
	 * current run.
	 */
	yy_bp = yy_cp;

	yy_current_state = yy_start;
yy_match:
	do
	    {
	    register YY_CHAR yy_c = yy_ec[*yy_cp];
	    if ( yy_accept[yy_current_state] )
		{
		yy_last_accepting_state = yy_current_state;
		yy_last_accepting_cpos = yy_cp;
		}
	    while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = yy_def[yy_current_state];
		if ( yy_current_state >= 148 )
		    yy_c = yy_meta[yy_c];
		}
	    yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
	    ++yy_cp;
	    }
	while ( yy_current_state != 147 );
	yy_cp = yy_last_accepting_cpos;
	yy_current_state = yy_last_accepting_state;

yy_find_action:
	yy_act = yy_accept[yy_current_state];

	YY_DO_BEFORE_ACTION;
	YY_USER_ACTION;

do_action:	/* this label is used only to access EOF actions */


	switch ( yy_act )
	    {
	    case 0: /* must backtrack */
	    /* undo the effects of YY_DO_BEFORE_ACTION */
	    *yy_cp = yy_hold_char;
	    yy_cp = yy_last_accepting_cpos;
	    yy_current_state = yy_last_accepting_state;
	    goto yy_find_action;

case 1:
# line 81 "tcplex.l"
return DST;
	YY_BREAK
case 2:
# line 82 "tcplex.l"
return SRC;
	YY_BREAK
case 3:
# line 84 "tcplex.l"
return ETHER;
	YY_BREAK
case 4:
# line 85 "tcplex.l"
return ARP;
	YY_BREAK
case 5:
# line 86 "tcplex.l"
return RARP;
	YY_BREAK
case 6:
# line 87 "tcplex.l"
return IP;
	YY_BREAK
case 7:
# line 88 "tcplex.l"
return TCP;
	YY_BREAK
case 8:
# line 89 "tcplex.l"
return UDP;
	YY_BREAK
case 9:
# line 90 "tcplex.l"
return ICMP;
	YY_BREAK
case 10:
# line 92 "tcplex.l"
return HOST;
	YY_BREAK
case 11:
# line 93 "tcplex.l"
return NET;
	YY_BREAK
case 12:
# line 94 "tcplex.l"
return PORT;
	YY_BREAK
case 13:
# line 95 "tcplex.l"
return PROTO;
	YY_BREAK
case 14:
# line 97 "tcplex.l"
return GATEWAY;
	YY_BREAK
case 15:
# line 99 "tcplex.l"
return LESS;
	YY_BREAK
case 16:
# line 100 "tcplex.l"
return GREATER;
	YY_BREAK
case 17:
# line 101 "tcplex.l"
return BYTE;
	YY_BREAK
case 18:
# line 102 "tcplex.l"
return BROADCAST;
	YY_BREAK
case 19:
# line 104 "tcplex.l"
return AND;
	YY_BREAK
case 20:
# line 105 "tcplex.l"
return OR;
	YY_BREAK
case 21:
# line 106 "tcplex.l"
return '!';
	YY_BREAK
case 22:
# line 108 "tcplex.l"
return LEN;
	YY_BREAK
case 23:
# line 110 "tcplex.l"
;
	YY_BREAK
case 24:
# line 111 "tcplex.l"
return yytext[0];
	YY_BREAK
case 25:
# line 112 "tcplex.l"
return GEQ;
	YY_BREAK
case 26:
# line 113 "tcplex.l"
return LEQ;
	YY_BREAK
case 27:
# line 114 "tcplex.l"
return NEQ;
	YY_BREAK
case 28:
# line 115 "tcplex.l"
return LSH;
	YY_BREAK
case 29:
# line 116 "tcplex.l"
return RSH;
	YY_BREAK
case 30:
# line 117 "tcplex.l"
{ yylval.i = stoi(yytext); return NUM; }
	YY_BREAK
case 31:
# line 118 "tcplex.l"
{ 
			yylval.h = atoin(yytext); return HID;
}
	YY_BREAK
case 32:
# line 121 "tcplex.l"
{ yylval.e = ETHER_aton(yytext); return EID; }
	YY_BREAK
case 33:
# line 122 "tcplex.l"
{ error("bogus ethernet address %s", yytext); }
	YY_BREAK
case 34:
# line 123 "tcplex.l"
{ yylval.s = yytext; return ID; }
	YY_BREAK
case 35:
# line 124 "tcplex.l"
{ yylval.s = yytext + 1; return ID; }
	YY_BREAK
case 36:
# line 125 "tcplex.l"
{ error("illegal token: %s\n", yytext); }
	YY_BREAK
case 37:
# line 126 "tcplex.l"
{ error("illegal char '%c'", *yytext); }
	YY_BREAK
case 38:
# line 127 "tcplex.l"
ECHO;
	YY_BREAK
case YY_STATE_EOF(INITIAL):
    yyterminate();

	    case YY_END_OF_BUFFER:
		{
		/* amount of text matched not including the EOB char */
		int yy_amount_of_matched_text = yy_cp - yytext - 1;

		/* undo the effects of YY_DO_BEFORE_ACTION */
		*yy_cp = yy_hold_char;

		/* note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the end-
		 * of-buffer state).  Contrast this with the test in yyinput().
		 */
		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
		    /* this was really a NUL */
		    {
		    yy_state_type yy_next_state;

		    yy_c_buf_p = yytext + yy_amount_of_matched_text;

		    yy_current_state = yy_get_previous_state();

		    /* okay, we're now positioned to make the
		     * NUL transition.  We couldn't have
		     * yy_get_previous_state() go ahead and do it
		     * for us because it doesn't know how to deal
		     * with the possibility of jamming (and we
		     * don't want to build jamming into it because
		     * then it will run more slowly)
		     */

		    yy_next_state = yy_try_NUL_trans( yy_current_state );

		    yy_bp = yytext + YY_MORE_ADJ;

		    if ( yy_next_state )
			{
			/* consume the NUL */
			yy_cp = ++yy_c_buf_p;
			yy_current_state = yy_next_state;
			goto yy_match;
			}

		    else
			{
			    yy_cp = yy_last_accepting_cpos;
			    yy_current_state = yy_last_accepting_state;
			goto yy_find_action;
			}
		    }

		else switch ( yy_get_next_buffer() )
		    {
		    case EOB_ACT_END_OF_FILE:
			{
			yy_did_buffer_switch_on_eof = 0;

			if ( yywrap() )
			    {
			    /* note: because we've taken care in
			     * yy_get_next_buffer() to have set up yytext,
			     * we can now set up yy_c_buf_p so that if some
			     * total hoser (like flex itself) wants
			     * to call the scanner after we return the
			     * YY_NULL, it'll still work - another YY_NULL
			     * will get returned.
			     */
			    yy_c_buf_p = yytext + YY_MORE_ADJ;

			    yy_act = YY_STATE_EOF((yy_start - 1) / 2);
			    goto do_action;
			    }

			else
			    {
			    if ( ! yy_did_buffer_switch_on_eof )
				YY_NEW_FILE;
			    }
			}
			break;

		    case EOB_ACT_CONTINUE_SCAN:
			yy_c_buf_p = yytext + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state();

			yy_cp = yy_c_buf_p;
			yy_bp = yytext + YY_MORE_ADJ;
			goto yy_match;

		    case EOB_ACT_LAST_MATCH:
			yy_c_buf_p =
			    &yy_current_buffer->yy_ch_buf[yy_n_chars];

			yy_current_state = yy_get_previous_state();

			yy_cp = yy_c_buf_p;
			yy_bp = yytext + YY_MORE_ADJ;
			goto yy_find_action;
		    }
		break;
		}

	    default:
#ifdef FLEX_DEBUG
		printf( "action # %d\n", yy_act );
#endif
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	    }
	}
    }


/* yy_get_next_buffer - try to read in a new buffer
 *
 * synopsis
 *     int yy_get_next_buffer();
 *     
 * returns a code representing an action
 *     EOB_ACT_LAST_MATCH - 
 *     EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *     EOB_ACT_END_OF_FILE - end of file
 */

static int yy_get_next_buffer()

    {
    register YY_CHAR *dest = yy_current_buffer->yy_ch_buf;
    register YY_CHAR *source = yytext - 1; /* copy prev. char, too */
    register int number_to_move, i;
    int ret_val;

    if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
	YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

    /* try to read more data */

    /* first move last chars to start of buffer */
    number_to_move = yy_c_buf_p - yytext;

    for ( i = 0; i < number_to_move; ++i )
	*(dest++) = *(source++);

    if ( yy_current_buffer->yy_eof_status != EOF_NOT_SEEN )
	/* don't do the read, it's not guaranteed to return an EOF,
	 * just force an EOF
	 */
	yy_n_chars = 0;

    else
	{
	int num_to_read = yy_current_buffer->yy_buf_size - number_to_move - 1;

	if ( num_to_read > YY_READ_BUF_SIZE )
	    num_to_read = YY_READ_BUF_SIZE;

	else if ( num_to_read <= 0 )
	    YY_FATAL_ERROR( "fatal error - scanner input buffer overflow" );

	/* read in more data */
	YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),
		  yy_n_chars, num_to_read );
	}

    if ( yy_n_chars == 0 )
	{
	if ( number_to_move == 1 )
	    {
	    ret_val = EOB_ACT_END_OF_FILE;
	    yy_current_buffer->yy_eof_status = EOF_DONE;
	    }

	else
	    {
	    ret_val = EOB_ACT_LAST_MATCH;
	    yy_current_buffer->yy_eof_status = EOF_PENDING;
	    }
	}

    else
	ret_val = EOB_ACT_CONTINUE_SCAN;

    yy_n_chars += number_to_move;
    yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
    yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

    /* yytext begins at the second character in yy_ch_buf; the first
     * character is the one which preceded it before reading in the latest
     * buffer; it needs to be kept around in case it's a newline, so
     * yy_get_previous_state() will have with '^' rules active
     */

    yytext = &yy_current_buffer->yy_ch_buf[1];

    return ( ret_val );
    }


/* yy_get_previous_state - get the state just before the EOB char was reached
 *
 * synopsis
 *     yy_state_type yy_get_previous_state();
 */

static yy_state_type yy_get_previous_state()

    {
    register yy_state_type yy_current_state;
    register YY_CHAR *yy_cp;

    yy_current_state = yy_start;

    for ( yy_cp = yytext + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
	{
	register YY_CHAR yy_c = (*yy_cp ? yy_ec[*yy_cp] : 1);
	if ( yy_accept[yy_current_state] )
	    {
	    yy_last_accepting_state = yy_current_state;
	    yy_last_accepting_cpos = yy_cp;
	    }
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	    {
	    yy_current_state = yy_def[yy_current_state];
	    if ( yy_current_state >= 148 )
		yy_c = yy_meta[yy_c];
	    }
	yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
	}

    return ( yy_current_state );
    }


/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *     next_state = yy_try_NUL_trans( current_state );
 */

#ifdef YY_USE_PROTOS
static yy_state_type yy_try_NUL_trans( register yy_state_type yy_current_state )
#else
static yy_state_type yy_try_NUL_trans( yy_current_state )
register yy_state_type yy_current_state;
#endif

    {
    register int yy_is_jam;
    register YY_CHAR *yy_cp = yy_c_buf_p;

    register YY_CHAR yy_c = 1;
    if ( yy_accept[yy_current_state] )
	{
	yy_last_accepting_state = yy_current_state;
	yy_last_accepting_cpos = yy_cp;
	}
    while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	{
	yy_current_state = yy_def[yy_current_state];
	if ( yy_current_state >= 148 )
	    yy_c = yy_meta[yy_c];
	}
    yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
    yy_is_jam = (yy_current_state == 147);

    return ( yy_is_jam ? 0 : yy_current_state );
    }


#ifdef YY_USE_PROTOS
static void yyunput( YY_CHAR c, register YY_CHAR *yy_bp )
#else
static void yyunput( c, yy_bp )
YY_CHAR c;
register YY_CHAR *yy_bp;
#endif

    {
    register YY_CHAR *yy_cp = yy_c_buf_p;

    /* undo effects of setting up yytext */
    *yy_cp = yy_hold_char;

    if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
	{ /* need to shift things up to make room */
	register int number_to_move = yy_n_chars + 2; /* +2 for EOB chars */
	register YY_CHAR *dest =
	    &yy_current_buffer->yy_ch_buf[yy_current_buffer->yy_buf_size + 2];
	register YY_CHAR *source =
	    &yy_current_buffer->yy_ch_buf[number_to_move];

	while ( source > yy_current_buffer->yy_ch_buf )
	    *--dest = *--source;

	yy_cp += dest - source;
	yy_bp += dest - source;
	yy_n_chars = yy_current_buffer->yy_buf_size;

	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
	    YY_FATAL_ERROR( "flex scanner push-back overflow" );
	}

    if ( yy_cp > yy_bp && yy_cp[-1] == '\n' )
	yy_cp[-2] = '\n';

    *--yy_cp = c;

    /* note: the formal parameter *must* be called "yy_bp" for this
     *       macro to now work correctly
     */
    YY_DO_BEFORE_ACTION; /* set up yytext again */
    }


#ifdef __cplusplus
static int yyinput()
#else
static int input()
#endif

    {
    int c;
    YY_CHAR *yy_cp = yy_c_buf_p;

    *yy_cp = yy_hold_char;

    if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )
	{
	/* yy_c_buf_p now points to the character we want to return.
	 * If this occurs *before* the EOB characters, then it's a
	 * valid NUL; if not, then we've hit the end of the buffer.
	 */
	if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )
	    /* this was really a NUL */
	    *yy_c_buf_p = '\0';

	else
	    { /* need more input */
	    yytext = yy_c_buf_p;
	    ++yy_c_buf_p;

	    switch ( yy_get_next_buffer() )
		{
		case EOB_ACT_END_OF_FILE:
		    {
		    if ( yywrap() )
			{
			yy_c_buf_p = yytext + YY_MORE_ADJ;
			return ( EOF );
			}

		    YY_NEW_FILE;

#ifdef __cplusplus
		    return ( yyinput() );
#else
		    return ( input() );
#endif
		    }
		    break;

		case EOB_ACT_CONTINUE_SCAN:
		    yy_c_buf_p = yytext + YY_MORE_ADJ;
		    break;

		case EOB_ACT_LAST_MATCH:
#ifdef __cplusplus
		    YY_FATAL_ERROR( "unexpected last match in yyinput()" );
#else
		    YY_FATAL_ERROR( "unexpected last match in input()" );
#endif
		}
	    }
	}

    c = *yy_c_buf_p;
    yy_hold_char = *++yy_c_buf_p;

    return ( c );
    }


#ifdef YY_USE_PROTOS
void yyrestart( FILE *input_file )
#else
void yyrestart( input_file )
FILE *input_file;
#endif

    {
    yy_init_buffer( yy_current_buffer, input_file );
    yy_load_buffer_state();
    }


#ifdef YY_USE_PROTOS
void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )
#else
void yy_switch_to_buffer( new_buffer )
YY_BUFFER_STATE new_buffer;
#endif

    {
    if ( yy_current_buffer == new_buffer )
	return;

    if ( yy_current_buffer )
	{
	/* flush out information for old buffer */
	*yy_c_buf_p = yy_hold_char;
	yy_current_buffer->yy_buf_pos = yy_c_buf_p;
	yy_current_buffer->yy_n_chars = yy_n_chars;
	}

    yy_current_buffer = new_buffer;
    yy_load_buffer_state();

    /* we don't actually know whether we did this switch during
     * EOF (yywrap()) processing, but the only time this flag
     * is looked at is after yywrap() is called, so it's safe
     * to go ahead and always set it.
     */
    yy_did_buffer_switch_on_eof = 1;
    }


#ifdef YY_USE_PROTOS
void yy_load_buffer_state( void )
#else
void yy_load_buffer_state()
#endif

    {
    yy_n_chars = yy_current_buffer->yy_n_chars;
    yytext = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
    yyin = yy_current_buffer->yy_input_file;
    yy_hold_char = *yy_c_buf_p;
    }


#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )
#else
YY_BUFFER_STATE yy_create_buffer( file, size )
FILE *file;
int size;
#endif

    {
    YY_BUFFER_STATE b;

    b = (YY_BUFFER_STATE) malloc( sizeof( struct yy_buffer_state ) );

    if ( ! b )
	YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

    b->yy_buf_size = size;

    /* yy_ch_buf has to be 2 characters longer than the size given because
     * we need to put in 2 end-of-buffer characters.
     */
    b->yy_ch_buf = (YY_CHAR *) malloc( (unsigned) (b->yy_buf_size + 2) );

    if ( ! b->yy_ch_buf )
	YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

    yy_init_buffer( b, file );

    return ( b );
    }


#ifdef YY_USE_PROTOS
void yy_delete_buffer( YY_BUFFER_STATE b )
#else
void yy_delete_buffer( b )
YY_BUFFER_STATE b;
#endif

    {
    if ( b == yy_current_buffer )
	yy_current_buffer = (YY_BUFFER_STATE) 0;

    free( (char *) b->yy_ch_buf );
    free( (char *) b );
    }


#ifdef YY_USE_PROTOS
void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
#else
void yy_init_buffer( b, file )
YY_BUFFER_STATE b;
FILE *file;
#endif

    {
    b->yy_input_file = file;

    /* we put in the '\n' and start reading from [1] so that an
     * initial match-at-newline will be true.
     */

    b->yy_ch_buf[0] = '\n';
    b->yy_n_chars = 1;

    /* we always need two end-of-buffer characters.  The first causes
     * a transition to the end-of-buffer state.  The second causes
     * a jam in that state.
     */
    b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;
    b->yy_ch_buf[2] = YY_END_OF_BUFFER_CHAR;

    b->yy_buf_pos = &b->yy_ch_buf[1];

    b->yy_eof_status = EOF_NOT_SEEN;
    }
# line 127 "tcplex.l"

void
lex_init(buf)
	char *buf;
{
	in_buffer = buf;
}
#ifndef FLEX_SCANNER
int 
yywrap()
/* so we don't need -ll */
{
	return 1;
}				
#endif