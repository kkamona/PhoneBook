
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Put your functions for Task 1 here (note that you also have to write
// code that tests them in main( ) below).
// You can start working on a function by removing the comment.



// Advance p to the first non-whitespace character.
// You can use isspace( ) from ctype.h. It's even better.
// A note about the word 'const'. It protects against accidentily overwriting
// the memory that p points to. If the 'const' confuses you, you can remove
// all occurrences of it from the template and not use it in your code.
// If you understand how it works, it's better to use it.

 const char* skipwhitespace( const char* p ) { // 1st function of the task 1
                                               //removes spaces at the beginning of a string
 int space = isspace(*p);
 if(space != 0) {
   while(space != 0) {
            p = p + 1;
        if(*p == '\0') {
            return p;
    }
     space = isspace(*p);
}
}

return p;
}


// Copy inp into data until either a (,) or the 0-character is
// enountered.

const char* readunquoteddata( const char* inp, char* data ) {//2nd function of the 2nd task
                                                             //reads data without quotes from the string
if(*inp == '\0' || *inp == ',') { //to detect empty fields without quotes
        *data = '\0';
        return inp;
}
    while(*inp != '\0' && *inp != ',') {
          *data = *inp;
           data++;
           inp++;
        if(*inp == '\0' || *inp == ',') {
            *data = '\0';
             return inp;
        }
    }

return inp;
}


// If the first non-space character is "
// we copy everything until the next " into str, but
// remove the first and final quote.
// We never read beyond a 0-character.
// Skipping a possible (,) is not part of our job.

 const char* readquoteddata( const char* inp, char* data ) { //3rd function of task 1
                                                             //reads data without one or two quotes
  while(*inp != '\"') {
        inp = inp + 1;
    }
        if( !inp || *inp != '\"' ){
           abort( );
           }
              inp = inp + 1;

                do{
                    *data = *inp;
                    data = data + 1;
                    inp = inp + 1;
                    if(*inp == '\0') {
                        *data = '\0';
                         return inp;
                    }
                }while(*inp != '\"');

    *data = '\0';
    inp = inp + 1; //to return pointer to a character after the quotes

    return inp;
 }


 const char* readdata( const char* inp, char* data ) { //4th function of task 1
                                                       //decides what type of changes the given data requires
 inp = skipwhitespace(inp);
if(*inp == '\"') {
  inp = readquoteddata(inp, data);

     if(*inp == ','){
        inp = inp + 1;
     }

inp = skipwhitespace(inp);

return inp;
}else {
inp = readunquoteddata(inp, data);

     if(*inp == ',') {
        inp = inp + 1;
     }
return inp;
}
}


 void correctfield( const char* fld, char* corrected ) { //5th function of task 1
                                                        //gets rid of unnecessary spaces and tabs
     fld = skipwhitespace(fld); //to remove spaces at the beginning

do{
   if(*fld == '\t') { //to replace tabs with one space
    *corrected = ' ';
    corrected = corrected + 1;
    fld = fld + 1;
   }

   if(*fld == ' '){ //to remove extra spaces in the middle of the string
   while(*fld == ' ' || *fld == '\t') {
         fld = fld + 1;
    }
    fld = fld - 1;
   }

   if(*fld != '\t' && *fld != '\0') {
    *corrected = *fld;
    corrected = corrected + 1;
    fld = fld + 1;
   }

}while(*fld != '\0');

corrected = corrected - 1;

if(*corrected == ' ' || *corrected == '\t') { //to remove spaces from the end of the string
            while(*corrected == ' ' || *corrected == '\t') {
                    corrected = corrected - 1;
            }
        corrected = corrected + 1;
        *corrected = '\0';
}else{
   corrected = corrected + 1;
   *corrected = '\0';
}
}


// You are not obliged to use this function, but you can:
// char USAcode( char c )


 void correctPhoneNumber( const char* number, char* corrected ) { //6th function of task 1
                                                                //make changes to a phone number field
   if(*number == '0' && *(number+1) == '0') {
        *corrected = '+';
        corrected = corrected + 1;
        number = number + 2;

         }else if(*number != '+') {
         *corrected = '+';
          corrected = corrected + 1;

             }else if(*number == '+') {
              *corrected = *number;
              corrected = corrected + 1;
              number = number + 1;
             }

     do{
        if(*number >= '0' && *number <= '9') { //copies integers into the phone number field
            *corrected = *number;
            corrected = corrected + 1;
            number = number + 1;

        }else if(isalpha(*number) != 0) { //converts letters into integers
         char letter = tolower(*number);

         switch(letter) {
     case 'a':
     case 'b':
     case 'c':
        *corrected = '2';
        corrected = corrected + 1;
        number = number + 1;
        break;
    case 'e':
    case 'd':
    case 'f':
            *corrected = '3';
            corrected = corrected + 1;
            number = number + 1;
            break;
    case 'g':
    case 'h':
    case 'i':
        *corrected = '4';
        corrected = corrected + 1;
        number = number + 1;
        break;
    case 'j':
    case 'k':
    case 'l':
        *corrected = '5';
        corrected = corrected + 1;
        number = number + 1;
        break;
    case 'm':
    case 'n':
    case 'o':
        *corrected = '6';
        corrected = corrected + 1;
        number = number + 1;
        break;
     case 'p':
     case 'q':
     case 'r':
     case 's':
        *corrected = '7';
        corrected = corrected + 1;
        number = number + 1;
        break;
     case 't':
     case 'u':
     case 'v':
        *corrected = '8';
        corrected = corrected + 1;
        number = number + 1;
        break;
    case 'w':
    case 'x':
    case 'y':
    case 'z':
        *corrected = '9';
        corrected = corrected + 1;
        number = number + 1;
        break;
        }
        }else{
        number = number + 1; //ignores other characters besides letters and integers
        }
     }while(*number != '\0');
     *corrected = '\0';
 }


// Put your functions for task 2 here (make sure that you include tests
// in main( ) ).


// Determine the length of a file, by reading it once to the end
// If the file does not exist, return -1 as length.
// Don't forget to close the file.
 int countlines( const char* fname ) { //1st function of the task 2
                                       //counts the number of lines of the input file
   int count = 0;
     FILE *file;
     file = fopen(fname, "r");
     if(file == NULL) {
        return -1;
     }
         do{
         char ch;
              ch = fgetc(file);
         if(ch == '\n' || ch == EOF) {
            count++;
         }
         }while(!feof(file));
     fclose(file);

     return count;
 }



// I find the interface to fgets annoying, so we write this function.
// We always assume that every line has 500 characters.

 int readline( FILE* f, char line[] ) { //2nd function of the task 2

    int i = 0;
    line[i] = fgetc(f);
    do{
         i++;
             if(i >= 500) { //if the number of characters exceeds 500, it stops copying
             while(fgetc(f) != '\n' && fgetc(f) != EOF) {
                fgetc(f);
             }
                 }else {
                    line[i] = fgetc(f);
                 }
    }while(line[i] != '\n' && line[i] != EOF);

    if(line[i] == '\n') {
        line[i] = '\0';
        return '\n';

        }else if(line[i] == EOF) {
                 line[i]='\0';
                 return EOF;
            }else{
            return line[i];
            }
 }


typedef struct
{
   char firstname[30];
   char secondname[30];
   char address[50];
   char phonenumber[30];

} PhoneEntry;


// Eto podarok:

void initPhoneEntry( PhoneEntry* e ) {
   e -> firstname[0] = 0;
   e -> secondname[0] = 0;
   e -> address[0] = 0;
   e -> phonenumber[0] = 0;
}


 void printPhoneEntry( FILE* f, const PhoneEntry* e ) {
      fprintf(f, "%-20.30s %-20.30s %-40.50s %-20.30s\n", e -> firstname, e -> secondname, e -> address, e -> phonenumber);
 }


 void printPhoneEntryCSV( FILE* f, const PhoneEntry* e ) {
      fprintf(f, "\"%s\",\"%s\",\"%s\",\"%s\"\n", e -> firstname, e -> secondname, e -> address, e -> phonenumber);
 }

 void printPhoneBook( FILE* f, const PhoneEntry* start, int size ) { //prints into text file
     fprintf( f, "Phonebook\n" );
     fprintf( f, "======================================================================\n" );
     fprintf( f, "Firstname\t\t\t Secondname\t\t\t  Address\t\t\t\t\t\t\t\t\tPhone Number\n");
     int i=0;
   do{
       i++;
       printPhoneEntry(f, start);
       start = start + 1;
   }while(i < size);

 }


 void printPhoneBookCSV( FILE* f, const PhoneEntry* start, int size ) { //prints into csv file
   int i=0;
   do{
       i++;
       printPhoneEntryCSV(f, start);
       start = start + 1;
   }while(i < size);
 }

 const char* readwithcutoff( const char* inp, char* fld, int flen ) { //3rd function of task 2
                                                                     //locates the data from the string into appropriate fields
    inp = skipwhitespace( inp );

   char data[500];
   int i = 0;
   inp = readdata(inp, data);
   int count;
   count = strlen(data);

   if(count > flen) { //cuts off extra characters
    while(i < flen - 1) {
    *fld = data[i];
    fld = fld + 1;
    i++;
   }
       }else{
       while(data[i] != '\0') {
       *fld = data[i];
        fld = fld + 1;
        i++;
       }
       }

   *fld = '\0';
   return inp;
}


 void parseEntry( PhoneEntry* e, const char* inp ) { //4th function of task 2
                                                   //passes the content of the string into struct
  initPhoneEntry(e);

  inp = readwithcutoff(inp, e -> firstname, 30);
  inp = readwithcutoff(inp, e -> secondname, 30);
  inp = readwithcutoff(inp, e -> address, 50);
  inp = readwithcutoff(inp, e -> phonenumber, 30);
}


// Your code for Task 3 comes here:

 void checkPhoneEntry( PhoneEntry* e, int linenr ) { //1st function of task 3
                                                     //check all the entries passed for printing into a file
    char inp[500];
    PhoneEntry corrected;

    int accepted = 0;
    while( !accepted )
    {
       accepted = 1;
correctfield(e -> firstname, corrected.firstname);
correctfield(e -> secondname, corrected.secondname);
correctfield(e -> address, corrected.address);
correctPhoneNumber(e -> phonenumber, corrected.phonenumber);

int entrylength;
entrylength = strlen(corrected.firstname);

if(entrylength == 0) { //requires to enter first name if the field is empty
        do{
            printf("The field with firstname of line %i is empty\n", linenr);
            scanf("%s", corrected.firstname);
            entrylength = strlen(corrected.firstname);
        }while(entrylength == 0);

    strcpy(inp, corrected.firstname);
    readwithcutoff(inp, e -> firstname, 30);
    accepted = 0;
}

entrylength = strlen(corrected.secondname);

if(entrylength == 0) {//requires to enter second name if the field is empty
    do{
        printf("The field with secondname of line %i is empty\n", linenr);
        scanf("%s",corrected.secondname);
        entrylength = strlen(corrected.secondname);
    }while(entrylength == 0);

    strcpy(inp, corrected.secondname);
    readwithcutoff(inp, e -> secondname, 30);
    accepted = 0;
}

entrylength = strlen(corrected.address);

if(entrylength == 0) {
    do{
        printf("The field with address of line %i is empty\n", linenr);
        scanf("%s", corrected.address);
        entrylength = strlen(corrected.address);
    }while(entrylength == 0);

    strcpy(inp, corrected.address);
    readwithcutoff(inp, e -> address, 50);
    accepted = 0;
}

entrylength = strlen(corrected.phonenumber);

if(entrylength < 13 || entrylength > 13){
        if(entrylength < 13){
            while(entrylength < 13) {
                printf("The field with phonenumber of line %i is too short\n", linenr);
                scanf("%s", corrected.phonenumber);
                entrylength = strlen(corrected.phonenumber);
            }
        }else if(entrylength > 13){
             while(entrylength > 13) {
                    printf("The field with phonenumber of line %i is too long\n", linenr);
                    scanf("%s", corrected.phonenumber);
                    entrylength = strlen(corrected.phonenumber);
                }
        }
      strcpy(inp, corrected.phonenumber);
      readwithcutoff(inp, e -> phonenumber, 30);
      accepted = 0;
}
}
*e = corrected;
}




int main( )
{
   printf( "CSCI 151, Assignment 3\n" );  // Don't change.

   printf( "Assiya Yeraly\n" );           // Replace by your Imya Familiya
   printf( "student ID = 201960841\n" );   // Your student number as string.
   printf("------\n");
   printf("TASK 1\n");
   printf("------\n");

   /////////////////////////////////////////////////////////
   // Put your tests for your functions of Task 1 here:
   /*
    char inp[] = "    Arnold,  , \"What does it mean\", +666666668484 "; //test for functions 1, 2, 3
    char* p = inp;
    char outp[500];

    p = (char*)skipwhitespace(p);
    p = (char*) readunquoteddata( p, outp );
    printf("%s\n", outp ); //prints Arnold

        if( *p != ',' ){
        printf( "expected a comma\n" );
        }
        p = p + 1;

    p = (char*) skipwhitespace(p);
        if( *p != 'G' ){
            printf( "It was expected to be a G here\n" );
        }

    p = (char*)readunquoteddata( p, outp );
    printf("%s\n", outp ); //nothing is printed

        if( *p != ',' ) {
        printf( "expected a comma" );
        }
        p = p + 1;

    p = (char*)readquoteddata( p, outp );
    printf("%s\n", outp ); //prints "what does it mean" without quotes


char test[] = "   Dylan, O'Brien, \"Best Actor\", +7494747484948 ";
char output[500];

char* k = test;
k = (char*)readdata( k, output );
printf( "%s\n", output ); //prints Dylan
k = (char*) readdata( k, output );
printf( "%s\n", output ); //prints O'Brien
k = (char*) readdata( k, output );
printf( "%s\n", output ); //prints Best Actor
k = (char*) readdata( k, output );
printf( "%s\n", output ); //prints the number

        if( *k != '\0' ) {
            printf( "should be end of line, but instead we got %s\n", k );
        }

char inp2[] = "             check     for   \t\t spaces      ";
char *pointer = inp2;

printf( "%s\n", inp2 ); //prints the content of inp2 before the changes
correctfield( inp2, output );
printf( "%s\n", output ); //prints inp2 after the changes

char inp3[] = "what thePROB +++";
correctPhoneNumber( inp3, output );
printf( "%s\n", output ); //prints +94288437762

char inp4[] = "00858585";
correctPhoneNumber( inp4, output );
printf( "%s\n", output ); //prints +858585

char inp5[] = "7. 5. 9. 1. 2. 6. 6. 9. 1";
correctPhoneNumber( inp5, output );
printf( "%s\n", output ); //prints +759126691 */


   printf("\n\n\n------\n");
   printf("TASK 2\n");
   printf("------\n");

   ////////////////////////////////////////////////////////
   // Put your tests for your functions of Task 2 here:

  /* char testfile [] = "Count.Lines.csv"; //test for the 1st function
   int testLines = countlines(testfile);

   FILE *tfile; //test for function 2
   tfile = fopen("WhatAboutMe.cvs", "r");
   if(tfile == NULL){
        printf("The file does not exist\n");
        return -9;
   }else{
       char firstline[500];
       readline(tfile, firstline);
       printf("The line ends with %c\n", readline);
   }

    PhoneEntry str; //test for function 3
    pointer = (char*)readwithcutoff(inp2, str.firstname, 30);
    printf("The firstname is %s\n", *pointer);
    */



   // When you are finished testing, you can use the code below, by
   // uncommenting it:

   char bookname[] = "phoneobook.csv";  // When you submit, don't change this name!!

   int lines = countlines( bookname );
   printf( "number of lines = %d\n", lines );

   if( lines < 0 )
   {
      printf( "could not open the phonebook %s\n", bookname );
      return -1;
   }



   // Now we know how much to allocate, so let's do it:

   PhoneEntry* thebook  = malloc( ( lines + 1 ) * sizeof( PhoneEntry ));
   int thebooksize = 0;

   if( !thebook )
   {
      printf( "could not reserve memory\n" );
      return 0;
   }

   FILE* f = fopen( bookname, "r" );
   if( !f )
   {
      printf( "could not open the phonebook %s\n", bookname );
      free( thebook );
      return -1;
   }

   int linenr = 1;

   char line[500];
   int c = readline( f, line );
   while( c != EOF )
   {
      const char* p = line;
      p = skipwhitespace(p);

      if( *p )
      {
         parseEntry( thebook + thebooksize, p );

         ++ thebooksize;
      }

      c = readline( f, line );

      ++ linenr;
   }

fclose(f);

   printf("\n\n\n------\n");
   printf("TASK 3\n");
   printf("------\n");

   /////////////////////////////////////////////////////////////////
   // Put your code for Task 3 here:
   FILE *file;
   FILE *txt;
   f = fopen("PhoneBook.csv", "r");
   file = fopen("output.csv", "w");
   txt = fopen("output.txt", "w");
   PhoneEntry e[lines];

int updt = 0;
int count = 0;
while(updt < lines) {
      readline(f, line);
int size = strlen(line);

if(size > 1) {
    parseEntry(&e[count], line);
    checkPhoneEntry(&e[count], count+1);
    count++;
}
updt++;
}

printPhoneBookCSV(file, e, count);
printPhoneBook(txt, e, count);

fclose(txt);
fclose(file);
fclose(f);

   // Don't forget to do this:
    free( thebook );


   // DO NOT WRITE ANYTHING BELOW THIS LINE!
   // DO NOT REMOVE OR CHANGE THIS LINE, IT IS USED FOR AUTOMATIC PROCESSING.

   return 0;
}



