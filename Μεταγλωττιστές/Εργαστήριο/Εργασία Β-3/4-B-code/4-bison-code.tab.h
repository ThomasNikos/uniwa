/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_4_BISON_CODE_TAB_H_INCLUDED
# define YY_YY_4_BISON_CODE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    DIVIDE_ASSIGN = 277,
    AMPERSAND = 278,
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
    IF = 292,
    WHILE = 293,
    FOR = 294,
    RETURN = 295,
    DOUBLE_PLUS = 296,
    DOUBLE_MINUS = 297,
    LOGIC_OPERATOR = 298,
    LOG_NOT = 299,
    RIGHT_AR = 300,
    LEFT_AR = 301,
    RIGHT_BR = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_4_BISON_CODE_TAB_H_INCLUDED  */
