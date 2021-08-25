#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef enum {ERROR = 0, OPERATOR, VALUE, EOLN, QUIT, HELP} tokenType;

typedef struct tokenStruct
{
 tokenType type;
 char      op;
 int       val;
} token;

token getInputToken (FILE *in);

void processExpression (token inputToken, FILE *in)
{
 
 while (inputToken.type != EOLN)
   {
    if (inputToken.type == OPERATOR)
      {
       
       printf ("OP:%c, " ,inputToken.op);

      }
    else if (inputToken.type == VALUE)
      {
       
       printf ("Val: %d, ", inputToken.val);
      }
   
    /* get next token from input */
    inputToken = getInputToken (in);
   } 
    printf ("\n");
}

token getInputToken (FILE *in)
{
 token retToken;
 retToken.type = QUIT;

 int ch;
 ch = getc(in);
 if (ch == EOF)
   return retToken;
 while (('\n' != ch) && isspace (ch))
   {
    ch = getc(in);
    if (ch == EOF)
      return retToken;
   }
 if ('q' == ch)
   {
    retToken.type = QUIT;
    return retToken;
   }
 if ('?' == ch)
   {
    retToken.type = HELP;
    return retToken;
   }
 if ('\n' == ch)
   {
    retToken.type = EOLN;
    return retToken;
   }
 if ( ('+' == ch) || ('-' == ch) || ('*' == ch) ||
      ('/' == ch) || ('(' == ch) || (')' == ch) )
   {
    retToken.type = OPERATOR;
    retToken.op = ch;
    return retToken;
   }
 if (isdigit(ch))
   {
    int value = ch - '0';
    ch = getc(in);
    while (isdigit(ch))
      {
       value = value * 10 + ch - '0';
       ch = getc(in);
      }
    ungetc (ch, in);  
    retToken.type = VALUE;
    retToken.val = value;
    return retToken;
   }
      
 /* else token is invalid */
 retToken.type = ERROR;
 return retToken;
}
void clearToEoln(FILE *in)
{
 int ch;
 
 do {
     ch = getc(in);
    }
 while ((ch != '\n') && (ch != EOF));
}

void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("or any infix mathematical expression using operators of (), *, /, +, -\n");
}

int main (int argc, char **argv)
{

 char *input;
 token inputToken;

 printf ("Starting Expression Evaluation Program\n\n");
 printf ("Enter Expression: ");

 inputToken = getInputToken (stdin);
 while (inputToken.type != QUIT)
   {
    if(inputToken.type == HELP)
      {
       printCommands();
       clearToEoln(stdin);
      }
    else if(inputToken.type == ERROR)
      {
       printf ("Invalid Input - For a list of valid commands, type ?\n");
       clearToEoln(stdin);
      }
    else if(inputToken.type == EOLN)
      {
       printf ("Blank Line - Do Nothing\n");
       
      }
    else 
      {
       processExpression(inputToken, stdin);
      } 

    printf ("\nEnter Expression: ");
    inputToken = getInputToken (stdin);
   }

 printf ("Quitting Program\n");
 return 1;
}
