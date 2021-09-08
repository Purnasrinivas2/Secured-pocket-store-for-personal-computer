#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int main()
{
    srand(time(0));
    printf("Developed by PURNA\n");
    printf("Runs on 64 bit windows only \n");
    printf("supports only text files only\n");
    printf("to prevent data loss use same file names \n");
    FILE *fp;
    char a[500000],ts,fname[30];
    int aa,bb,otp,ps=0,loop1=0,sum1=0,otpc=0,ots=0,otcc,ss,sum2,fs=0,loop2=0,tsa=0,cc;
    printf(" enter 1 for manual password protection \n enter 2 for one time password protection \n enter 3 for dynamic round protection \n\n");
    scanf("%d",&aa);
    if(aa==1)
    {
     printf("enter your numeric password size\n");
     scanf("%d",&ps);
     char pass[ps];
     printf("Enter your numeric password\n");
     for(loop1=0;loop1<ps;loop1++)
     {
         scanf("%s",&pass[loop1]);
        ts=pass[loop1];
        ss=(int)ts;
         sum1=sum1+ss;
     }
     while(sum1>0)
     {
         ss=sum1%10;
         sum2=sum2+ss;
         sum1=sum1/10;
     }
     fs=sum2;
    }
    if(aa==2)
    {
        otp=rand();
        while(otp>0)
        {
           ots=otp%10;
           otpc=otpc+ots;
           otp=otp/10;
        }
         printf("single layer Otp to unlock your credentials is ====%d \n",otpc);
        fs=otpc;
    }
    if(aa==3)
    {
        otp=rand();
        otcc=otp;
       printf("Round 1 Otp to unlock your credentials is   ====%d \n",otp);
       while(otcc>0)
       {
        while(otp>0)
        {
           ots=otp%10;
           otpc=otpc+ots;
           otp=otp/10;
        }
        otp=otpc;
        otpc=0;
        otcc=otcc-1;
       }
       printf("Dual round otp is ========%d\n",otp);
       fs=otp;
    }
    printf(" enter 1 to create file in command prompt (click on enter key to confirm your credentials) \n enter 2 to load the previously created text file \n enter 3 to decrypt ");
    scanf("%d",&bb);
    switch(bb)
    {
        case 1:
        printf("enter your credentials you want to store in this wallet \n");
        while(ts!= (char)13)
        {
            ts=getch();
            printf("%c",ts);
            a[loop2]=ts;
            cc=(int)a[loop2];
            tsa=fs+cc;
            a[loop2]=(char)tsa;
              loop2++;
        }
        printf("Enter your filename you wish to save the file by .");
        scanf("%s",fname);
         fp = fopen(fname, "w");
           for(loop1=0;loop1<loop2;loop1++)
           {
               fprintf(fp,"%c",a[loop1]);
           }
           fclose(fp);
        break;
        case 2:
         printf("enter filename \n");
        scanf("%s",fname);
         fp = fopen(fname, "r");
        while((ts = fgetc(fp)) != EOF)
        {
            a[loop2]=ts;
            cc=(int)a[loop2];
            tsa=cc+fs;
            a[loop2]=(char)tsa;
              loop2++;
        }
        fclose(fp);
        printf("Enter your filename you wish to save the file by .");
        scanf("%s",fname);
         fp = fopen(fname, "w");
           for(loop1=0;loop1<loop2;loop1++)
           {
               fprintf(fp,"%c",a[loop1]);
           }
           fclose(fp);
        break;
        case 3:
        if(aa==2||aa==3)
        {
            printf("enter the otp \n");
            scanf("%d",&fs);
        }
        printf("enter filename \n");
        scanf("%s",fname);
         fp = fopen(fname, "r");
        while((ts = fgetc(fp)) != EOF)
        {
            a[loop2]=ts;
            cc=(int)a[loop2];
            tsa=cc-fs;
            a[loop2]=(char)tsa;
              loop2++;
        }
        fclose(fp);
        printf("Enter your filename you wish to save the file by .");
        scanf("%s",fname);
         fp = fopen(fname, "w");
           for(loop1=0;loop1<loop2;loop1++)
           {
               fprintf(fp,"%c",a[loop1]);
           }
           fclose(fp);
        break;
        default:
        printf("invalid\n");
        break;
    }
}
