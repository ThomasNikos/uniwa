/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DELIMITER = 258,
     IDENTIFIER = 259,
     KEYWORD = 260,
     STRING = 261,
     INTEGER = 262,
     FLOAT = 263,
     PLUS = 264,
     MINUS = 265,
     TIMES = 266,
     DIVIDE = 267,
     POWER = 268,
     COMMENT = 269,
     NEG = 270,
     UNKNOWN_TOKEN = 271,
     NEWLINE = 272,
     MINUS_ASSIGN = 273,
     PLUS_ASSIGN = 274,
     TIMES_ASSIGN = 275,
     MOD = 276,
     BACKSLASH_NEWLINE = 277,
     DIVIDE_ASSIGN = 278,
     PRINT = 279,
     LEFT_PT = 280,
     RIGHT_PT = 281,
     SEMICOLON = 282,
     ASSIGNOP = 283,
     CMP_OPERATOR = 284,
     TYPE = 285,
     SCAN = 286,
     LEN = 287,
     CMP = 288,
     COMMA = 289,
     FUNC = 290,
     LEFT_BR = 291,
     RIGHT_BR = 292,
     IF = 293,
     WHILE = 294,
     FOR = 295,
     RETURN = 296,
     DOUBLE_PLUS = 297,
     DOUBLE_MINUS = 298,
     LOGIC_OPERATOR = 299,
     LOG_NOT = 300,
     RIGHT_AR = 301,
     LEFT_AR = 302,
     AMPERSAND = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


