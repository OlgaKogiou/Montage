#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include <mtbl.h>

#include <mBackground.h>
#include <montage.h>

#include <dlio_profiler/dlio_profiler.h>

#define MAXSTR  256


int main(int argc, char **argv)
{
   /////////////////////////////////////////////
   DLIO_PROFILER_C_INIT(NULL, NULL, NULL);


   int       debug, noAreas, i;
   int       tableDriven, haveStatus;
   int       icntr, ifname, cntr;
   int       ncols, istat;
   int       ia, ib, ic, id;

   double    A, B, C;

   char      input_file [MAXSTR];
   char      output_file[MAXSTR];
   char      tblfile    [MAXSTR];
   char      corrfile   [MAXSTR];
   char      file       [MAXSTR];

   char     *end;

   struct mBackgroundReturn *returnStruct;

   FILE *montage_status;


   /***************************************/
   /* Process the command-line parameters */
   /***************************************/

   debug       = 0;
   tableDriven = 0;
   noAreas     = 0;
   haveStatus  = 0;

   montage_status = stdout;

   for(i=0; i<argc; ++i)
   {
      if(strcmp(argv[i], "-s") == 0)
      {
         haveStatus = 1;

         if(i+1 >= argc)
         {
            printf("[struct stat=\"ERROR\", msg=\"No status file name given\"]\n");
            /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
            exit(1);
         }

         if((montage_status = fopen(argv[i+1], "w+")) == (FILE *)NULL)
         {
            printf ("[struct stat=\"ERROR\", msg=\"Cannot open status file: %s\"]\n",
               argv[i+1]);
               /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
            exit(1);
         }

         ++i;
      }

      else if(strcmp(argv[i], "-n") == 0)
         noAreas = 1;

      else if(strcmp(argv[i], "-t") == 0)
         tableDriven = 1;

      else if(strcmp(argv[i], "-d") == 0)
      {
         if(i+1 >= argc)
         {
            printf("[struct stat=\"ERROR\", msg=\"No debug level given\"]\n");
            exit(1);
         }

         debug = strtol(argv[i+1], &end, 0);

         if(end - argv[i+1] < strlen(argv[i+1]))
         {
            printf("[struct stat=\"ERROR\", msg=\"Debug level string is invalid: '%s'\"]\n", argv[i+1]);
            /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
            exit(1);
         }

         if(debug < 0)
         {
            printf("[struct stat=\"ERROR\", msg=\"Debug level value cannot be negative\"]\n");
            /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
            exit(1);
         }

         ++i;
      }
   }

   if(haveStatus)
   {
      argv += 2;
      argc -= 2;;
   }
   
   if(debug)
   {
      argv += 2;
      argc -= 2;;
   }
   
   if(noAreas)
   {
      ++argv;
      --argc;
   }
   
   if(tableDriven)
   {
      ++argv;
      --argc;
   }
   
   if (argc < 5) 
   {
      printf ("[struct stat=\"ERROR\", msg=\"Usage: mBackground [-d level] [-n(o-areas)] [-s statusfile] in.fits out.fits A B C | mBackground [-t(able-mode)] [-d level] [-n(o-areas)] [-s statusfile] in.fits out.fits images.tbl corrfile.tbl\"]\n");
      /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
      exit(1);
   }

   strcpy(input_file,  argv[1]);

   if(input_file[0] == '-')
   {
      printf ("[struct stat=\"ERROR\", msg=\"Invalid input file '%s'\"]\n", input_file);
      /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
      exit(1);
   }

   strcpy(output_file, argv[2]);

   if(output_file[0] == '-')
   {
      printf ("[struct stat=\"ERROR\", msg=\"Invalid output file '%s'\"]\n", output_file);
      /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
      exit(1);
   }

   A = 0.;
   B = 0.;
   C = 0.;

   if(!tableDriven)
   {
      if (argc != 6) 
      {
         printf ("[struct stat=\"ERROR\", msg=\"Usage: mBackground [-d level] [-n(o-areas)] [-s statusfile] in.fits out.fits A B C | mBackground [-t](able-mode) [-d level] [-n(o-areas)] [-s statusfile] in.fits out.fits images.tbl corrfile.tbl\"]\n");
         /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
         exit(1);
      }

      A = strtod(argv[3], &end);

      if(end < argv[3] + strlen(argv[3]))
      {
         printf ("[struct stat=\"ERROR\", msg=\"A coefficient string is not a number\"]\n");
         /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
         exit(1);
      }

      B = strtod(argv[4], &end);

      if(end < argv[4] + strlen(argv[4]))
      {
         printf ("[struct stat=\"ERROR\", msg=\"B coefficient string is not a number\"]\n");
         /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
         exit(1);
      }

      C = strtod(argv[5], &end);

      if(end < argv[5] + strlen(argv[5]))
      {
         printf ("[struct stat=\"ERROR\", msg=\"C coefficient string is not a number\"]\n");
         /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
         exit(1);
      }
   }
   else
   {
      /* Look up the file cntr in the images.tbl file */
      /* and then the correction coefficients in the  */
      /* corrections table generated by mBgModel      */

      if (argc != 5) 
      {
         printf ("[struct stat=\"ERROR\", msg=\"Usage: mBackground [-d level] [-n(o-areas)] [-s statusfile] in.fits out.fits A B C | mBackground [-t](able-mode) [-d level] [-n(o-areas)] [-s statusfile] in.fits out.fits images.tbl corrfile.tbl\"]\n");
         exit(1);
      }

      strcpy(tblfile,  argv[3]);
      strcpy(corrfile, argv[4]);


      /* Open the image list table file */

      ncols = topen(tblfile);

      if(ncols <= 0)
      {
         fprintf(montage_status, "[struct stat=\"ERROR\", msg=\"Invalid image metadata file: %s\"]\n",
            tblfile);
            /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
         exit(1);
      }

      icntr  = tcol( "cntr");
      ifname = tcol( "fname");

      if(ifname < 0)
         ifname = tcol( "file");

      if(icntr  < 0
      || ifname < 0)
      {
         fprintf(montage_status, "[struct stat=\"ERROR\", msg=\"Image table needs columns cntr and fname\"]\n");
         /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();
         exit(1);
      }


      /* Read the records and find the cntr for our file name */

      while(1)
      {
         istat = tread();

         if(istat < 0)
         {
            fprintf(montage_status, "[struct stat=\"ERROR\", msg=\"Hit end of image table without finding file name\"]\n");
            /////////////////////////////////////////////////////////////////////////
            DLIO_PROFILER_C_FINI();
            exit(1);
         }

         cntr = atoi(tval(icntr));

         strcpy(file, tval(ifname));

         if(strcmp(file, input_file) == 0)
            break;
      }

      tclose();


      ncols = topen(corrfile);

      icntr    = tcol( "id");
      ia       = tcol( "a");
      ib       = tcol( "b");
      ic       = tcol( "c");

      if(icntr    < 0
      || ia       < 0
      || ib       < 0
      || ic       < 0)
      {
         fprintf(montage_status, "[struct stat=\"ERROR\", msg=\"Need columns: id,a,b,c in corrections file\"]\n");
         /////////////////////////////////////////////////////////////////////////
         DLIO_PROFILER_C_FINI();
         exit(1);
      }


      /* Read the records and find the correction coefficients */

      while(1)
      {
         istat = tread();

         if(istat < 0)
         {
            A = 0.;
            B = 0.;
            C = 0.;

            break;
         }

         id = atoi(tval(icntr));

         if(id != cntr)
            continue;

         A = atof(tval(ia));
         B = atof(tval(ib));
         C = atof(tval(ic));

         break;
      }

      tclose();
   }

   returnStruct = mBackground(input_file, output_file, A, B, C, noAreas, debug);

   /////////////////////////////////////////////////////////////////////////
   DLIO_PROFILER_C_FINI();

   if(returnStruct->status == 1)
   {
       fprintf(montage_status, "[struct stat=\"ERROR\", msg=\"%s\"]\n", returnStruct->msg);
       exit(1);
   }
   else
   {
       fprintf(montage_status, "[struct stat=\"OK\", module=\"mBackground\", %s]\n", returnStruct->msg);
       exit(0);
   }
}
