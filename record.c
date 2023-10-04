// PROGRAM FOR HOSPITAL MANAGEMENT

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#pragma pack(1)
#define SIZE 1000

int temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,i,j ;
int add_more ;

struct patient_details
    {
        char first_name[20] ;
        char last_name[20] ;
        char age[2] ;
        char gender ;
        char mob_no[11] ;
        char aadhar_no[15] ;
        char email[30] ;
        char father_name[20] ;
        char mother_name[20] ;
        char marital_status ;
        char insurance ;
        char door_no[6] ;
        char street_name[20] ;
        char area[20] ;
        char district[20] ;
        char pincode[7] ;
        char state[20] ;
        char nationality[20] ;
        int date ;
        int month ;
        int year ;
        char first_nameemer[20] ;
        char last_nameemer[20] ;
        char mobile_no[11] ;

    }w[SIZE] ;



//  FUNCTION DECLARATIONS
void login_page(void) ;
void options(void) ;
void add(void) ;
void edit(void) ;
void del(struct patient_details w[]) ;
void list(void) ;
void search(struct patient_details []) ;
void ex_it(void) ;

int main() // FUNCTION MAIN BEGINS

{
    login_page() ; // FUNCTION CALL
}

// TITLE DEFINITION

void title() // FUNCTION TITLE BEGINS

{
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n") ;
    printf("\t\t\t\t\t\t\t\tPATIENT RECORD\n\n") ;
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n") ;

}

// LOGIN PAGE DEFINITION

void login_page() // FUNCTION LOGIN PAGE BEGINS

{
    char username[50],password[5],c,orgName[50]="admin",orgPwd[5]="21pw" ;
    int i=0 ;

    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n") ;
    printf("\t\t\t\t\t\t\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM\n\n") ;
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n") ;

    printf("\t\t\t\t\t\t\t\tUSERNAME : ") ;
    scanf("%s",& username) ;

    printf("\n\t\t\t\t\t\t\t\tPASSWORD : ") ;
    while((c=getch())!='\t',i<4)
	     {
		     password[i++] = c ;
		     printf("*") ;
	     }
	password[i] = '\0' ;

    printf("\n\n") ;

	if(strcmp(username,orgName)==0 && strcmp(password,orgPwd)==0)
       {
           printf("\t\t\t\t\t\t\t\t\t LOGIN SUCCESSFULL !\n") ;
           options() ;
       }

    else
        {
           printf("\t\t\t\t\t\t\t\t\t LOGIN UNSUCCESSFULL !\n\n") ;
           login_page() ;
        }



}


// OPTIONS DEFINITION

void options() // FUNCTION OPTIONS BEGINS

{
    system("cls") ;
    int opt ;

    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n") ;
    printf("\t\t\t\t\t\t\t HOSPITAL MANAGEMENT OPTIONS\n\n") ;
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n") ;

    printf("\t\t\t\t\t\t\t 1. ADD NEW RECORD\n\n") ;
    printf("\t\t\t\t\t\t\t 2. EDIT RECORD\n\n") ;
    printf("\t\t\t\t\t\t\t 3. DELETE RECORD\n\n") ;
    printf("\t\t\t\t\t\t\t 4. LIST RECORD\n\n") ;
    printf("\t\t\t\t\t\t\t 5. SEARCH RECORD\n\n") ;
    printf("\t\t\t\t\t\t\t 6. EXIT RECORD\n\n") ;

    printf("\t\t\t\t\t\t\t ENTER YOUR REQUIRED OPTION : ") ;
    scanf("%d",& opt) ;

    switch(opt)
               {
                      case 1 :
                              {
                                  add() ;
                                  break ;
                              }

                 /*     case 2 :
                              {
                                  edit() ;
                                  break ;
                              } */

                      case 3 :
                              {
                                  del(w) ;
                                  break ;
                              }

                      case 4 :
                              {
                                  list() ;
                                  break ;
                              }

                     case 5 :
                              {
                                  search(w) ;
                                  break ;
                              }

                      case 6 :
                              {
                                  ex_it() ;
                                  break ;
                              }

                      default :
                                printf("\t\t\t\t\t\t\t INVALID OPTION !\n\n") ;

               }
          getch() ;
}

// ADD DEFINITION

void add() // FUNCTION ADD BEGINS

{
    system("cls") ;
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n") ;
    printf("\t\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n\n") ;
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n") ;


    printf("\t\t\t\t\t\t\t HOW MANY RECORDS TO ADD ?") ;
    fflush(stdin) ;
    scanf("%d",& add_more) ;

    system("cls") ;
    title() ;

    FILE *fp ;
    fp = fopen("Record","a") ;

    if(fp == NULL)
      {
          printf("\t\t\t\t\t\t\t CAN NOT OPEN FILE !\n\n") ;
          exit(1) ;
      }


    for(j=0;j<add_more;j++)
       {

    system("cls") ;
    title() ;

    printf("\t\t\t\t\t\t\t\t -----ADD RECORD----- \n\n") ;

    //  FIRST NAME

    A :

    printf("\t\t\t\t\t\t\t FIRST NAME : ") ;
    scanf("%s",& w[j].first_name) ;

    w[j].first_name[0] = toupper(w[j].first_name[0]) ;

    if(strlen(w[j].first_name)>20 || strlen(w[j].first_name)<2)
      {
          printf("\n\n\t\t\t\t\t\t\t INVALID !\n\n") ;
          goto A ;
      }

    else
       {
           for(temp1=0 ; temp1<strlen(w[j].first_name) ; temp1++)
              {
                 if(isalpha(w[j].first_name[temp1]))
                    temp2 = 1 ;
                 else
                     {
                        temp2 = 0 ;
                        break ;
                     }
              }
           if(!temp2)
             {
                printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                goto A ;
             }
       }

    //  LAST NAME

    B :

    printf("\n\t\t\t\t\t\t\t LAST NAME : ") ;
    scanf("%s",& w[j].last_name) ;

    w[j].last_name[0] = toupper(w[j].last_name[0]) ;

    if(strlen(w[j].last_name)>20 || strlen(w[j].last_name)<1)
      {
          printf("\t\t\t\t\t\t\t INVALID : \n\n") ;
          goto B ;
      }

    else
        {
           for(temp1=0 ; temp1<strlen(w[j].last_name) ; temp1++)
              {
                 if(isalpha(w[j].last_name[temp1]))
                    temp2 = 1 ;
                 else
                     {
                         temp2 = 0 ;
                         break ;
                     }
              }
           if(!temp2)
             {
                printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                goto B ;
             }
        }


    //  AGE

    Z:
        printf("\n\t\t\t\t\t\t\t AGE : ");
        scanf("%s",&w[j].age);
         if(strlen(w[j].age)>2 || strlen(w[j].age)<0)
      {
        printf("\t\t\t\t\t\t\t INVALID CHARACTER ! \n\n") ;
        goto Z ;
      }

    else
    {
        for(temp1=0 ; temp1<strlen(w[j].age) ; temp1++)
        {
            if(!isalpha(w[j].age[temp1]) && w[j].age[0]!= '0')
               temp2 = 1 ;
            else
            {
                temp2 = 0 ;
                break ;
            }
        }
        if(!temp2)
        {
            printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
            goto Z ;
        }
    }

    //  GENDER

    do
      {
        printf("\n\t\t\t\t\t\t\t GENDER [M/F] : ") ;
        scanf("%s",& w[j].gender) ;

        if(w[j].gender == 'M' || w[j].gender == 'm' || w[j].gender == 'F' || w[j].gender == 'f')
           temp3 = 1 ;
        else
            temp3 = 0 ;
      }while(!temp3) ;


    //  MOBILE

    L:

    printf("\n\t\t\t\t\t\t\t MOBILE NUMBER : ") ;
    scanf("%s",& w[j].mob_no) ;

    if(strlen(w[j].mob_no)>10 || strlen(w[j].mob_no)!=10)
      {
         printf("\t\t\t\t\t\t\t INVALID CHARACTER ! \n\n") ;
         goto L ;
      }

    else
        {
            for(temp1=0 ; temp1<strlen(w[j].mob_no) ; temp1++)
               {
                   if(!isalpha(w[j].mob_no[temp1]) && w[j].mob_no[0]>='6' && w[j].mob_no[0]<='9')
                      temp2 = 1 ;
                   else
                       {
                           temp2 = 0 ;
                           break ;
                       }
               }
            if(!temp2)
              {
                  printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                  goto L ;
              }
        }


   //  AADHAR NUMBER

   R:

   printf("\n\t\t\t\t\t\t\t AADHAAR NUMBER : ") ;
   scanf("%s",& w[j].aadhar_no) ;

   if(strlen(w[j].aadhar_no)>12 || strlen(w[j].aadhar_no)!=12)
      {
         printf("\t\t\t\t\t\t\t INVALID CHARACTER ! \n\n") ;
         goto R ;
      }

   else
       {
           for(temp1=0 ; temp1<strlen(w[j].aadhar_no) ; temp1++)
              {
                 if(!isalpha(w[j].aadhar_no[temp1]) && w[j].aadhar_no[0]!= '0')
                    temp2 = 1 ;
                 else
                     {
                          temp2 = 0 ;
                          break ;
                     }
               }
           if(!temp2)
             {
                printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                goto R ;
             }
        }

   //  EMAIL

   do
     {
         printf("\n\t\t\t\t\t\t\t EMAIL : ") ;
         scanf("%s",w[j].email);

         if(strlen(w[j].email)>30 || strlen(w[j].email)<8)
            printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;

     }while(strlen(w[j].email)>30 || strlen(w[j].email)<8) ;


   //  FATHER NAME

   C :

   printf("\n\t\t\t\t\t\t\t FATHER NAME : ") ;
   scanf("%s",& w[j].father_name) ;

   w[j].father_name[0] = toupper(w[j].father_name[0]) ;

   if(strlen(w[j].father_name)>20 || strlen(w[j].father_name)<2)
     {
        printf("\t\t\t\t\t\t\t INVALID ! \n\n") ;
        goto C ;
     }

   else
       {
           for(temp1=0 ; temp1<strlen(w[j].father_name) ; temp1++)
              {
                  if(isalpha(w[j].father_name[temp1]))
                     temp2 = 1 ;
                  else
                      {
                          temp2 = 0 ;
                          break ;
                      }
              }
           if(!temp2)
             {
                printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                goto C ;
             }
       }

   //  MOTHER NAME

   D :

   printf("\n\t\t\t\t\t\t\t MOTHER NAME : ") ;
   scanf("%s",& w[j].mother_name) ;

   w[j].mother_name[0] = toupper(w[j].mother_name[0]) ;

   if(strlen(w[j].mother_name)>20 || strlen(w[j].mother_name)<2)
      {
         printf("\t\t\t\t\t\t\t INVALID ! \n\n") ;
         goto D ;
      }

   else
       {
           for(temp1=0 ; temp1<strlen(w[j].mother_name) ; temp1++)
              {
                   if(isalpha(w[j].mother_name[temp1]))
                      temp2 = 1 ;
                   else
                       {
                          temp2 = 0 ;
                          break ;
                       }
              }
           if(!temp2)
             {
                 printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                 goto D ;
             }
       }

    //  MARITAL STATUS

    do
      {
          printf("\n\t\t\t\t\t\t\t MARITAL STATUS [Y/N] : ") ;
          scanf("%s",& w[j].marital_status) ;

          if(toupper(w[j].marital_status) == 'Y' || toupper(w[j].marital_status) == 'N')
             temp1 = 1 ;
          else
               temp1 = 0 ;

          if(!temp1)
             printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;

       }while(!temp1) ;

   //  INSURANCE

   do
     {
         printf("\n\t\t\t\t\t\t\t INSURANCE [Y/N] : ") ;
         scanf("%s",& w[j].insurance) ;

         if(toupper(w[j].insurance) == 'Y' || toupper(w[j].insurance) == 'N')
            temp1 = 1 ;
         else
             temp1 = 0 ;

         if(!temp1)
            printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;

    }while(!temp1) ;


   //  ADDRESS

   //  DOOR NO

   X :
         printf("\n\t\t\t\t\t\t\t DOOR NUMBER : ") ;
         scanf("%s",&w[j].door_no) ;

         if(strlen(w[j].door_no)>6 || strlen(w[j].door_no)<0)
      {
        printf("\t\t\t\t\t\t\t INVALID CHARACTER ! \n\n") ;
        goto X ;
      }





   //  STREET NAME

   E:
   {
      printf("\n\t\t\t\t\t\t\t STREET NAME : ");
      fflush(stdin);
      fgets(w[j].street_name,20,stdin);
      w[j].street_name[0] = toupper(w[j].street_name[0]) ;

      if(strlen(w[j].street_name)>20 || strlen(w[j].street_name)<3)
        {
           printf("\t\t\t\t\t\t\t INVALID CHARACTER !") ;
           goto E ;
        }

      else
          {
             for(temp5=0 ; temp5<strlen(w[j].street_name) ; temp5++)
                {
                    if(isalpha(w[j].street_name[temp1]))
                       temp6= 1 ;
                    else
                        {
                            temp6 = 0 ;
                            break ;
                        }
                }
             if(!temp6)
               {
                   printf("\t\t\t\t\t\t\t INVALID CHARACTER !") ;
                   goto E ;
               }
         }
   }

   //  AREA

   F:
   {
       printf("\n\t\t\t\t\t\t\t AREA : ") ;
       fflush(stdin) ;
       fgets(w[j].area,20,stdin) ;

       w[j].area[0] = toupper(w[j].area[0]) ;

       if(strlen(w[j].area)>20 || strlen(w[j].area)<3 )
         {
             printf("\t\t\t\t\t\t\t INVALID CHARACTER ! ") ;
             goto F ;
         }

       else
           {
               for(temp5 = 0 ; temp5<strlen(w[j].area) ; temp5++)
                   {
                       if(isalpha(w[j].area[temp1]))
                          temp6 = 1 ;
                       else
                           {
                               temp6 = 0 ;
                               break ;
                           }
                   }
               if(!temp6)
                 {
                     printf("\t\t\t\t\t\t\t INVALID CHARACTER !") ;
                     goto F ;
                 }
           }

   }

   //  DISTRICT

   G:
   {
       printf("\n\t\t\t\t\t\t\t DISTRICT : ") ;
       fflush(stdin) ;
       fgets(w[j].district,20,stdin) ;

       w[j].district[0] = toupper(w[j].district[0]) ;

       if(strlen(w[j].district)>20 || strlen(w[j].district)<3 )
         {
            printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
            goto G ;
         }

       else
           {
               for(temp5=0 ; temp5<strlen(w[j].district) ; temp5++)
                  {
                      if(isalpha(w[j].district[temp1]))
                         temp6 = 1 ;
                      else
                          {
                               temp6 = 0 ;
                               break ;
                          }
                 }
               if(!temp6)
                  {
                      printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                      goto G ;
                  }
           }

   }

   //  PINCODE

        y :

        printf("\n\t\t\t\t\t\t\t PINCODE : ") ;
        scanf("%s",&w[j].pincode) ;
        if(strlen(w[j].pincode)>6 || strlen(w[j].pincode)!=6)
      {
         printf("\t\t\t\t\t\t\t INVALID CHARACTER ! \n\n") ;
         goto y ;
      }

   else
       {
           for(temp1=0 ; temp1<strlen(w[j].pincode) ; temp1++)
              {
                 if(!isalpha(w[j].pincode[temp1]) && w[j].pincode[0]!= '0')
                    temp2 = 1 ;
                 else
                     {
                          temp2 = 0 ;
                          break ;
                     }
               }
           if(!temp2)
             {
                printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                goto y ;
             }
        }


   //  STATE

   H:
   {
      printf("\n\t\t\t\t\t\t\t STATE : ") ;
      fflush(stdin) ;
      fgets(w[j].state,20,stdin) ;

      w[j].state[0] = toupper(w[j].state[0]) ;

      if(strlen(w[j].state)>20 || strlen(w[j].state)<3 )
        {
           printf("\t\t\t\t\t\t\t INVALID CHARACTER ! \n\n") ;
           goto H ;
        }

      else
         {
             for(temp5=0 ; temp5<strlen(w[j].state) ; temp5++)
                {
                    if(isalpha(w[j].state[temp1]))
                       temp6 = 1 ;
                    else
                        {
                            temp6 = 0 ;
                            break ;
                        }
               }
             if(!temp6)
               {
                   printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
                   goto H ;
              }
         }

   }

   //  NATIONALITY

   I:

      printf("\n\t\t\t\t\t\t\t NATIONALITY : ") ;
      fflush(stdin) ;
      fgets(w[j].nationality,20,stdin) ;

    w[j].nationality[0] = toupper(w[j].nationality[0]) ;

    if(strlen(w[j].nationality)>20 || strlen(w[j].nationality)<3 )
      {
        printf("\t\t\t\t\t\t\t INVALID CHARACTER ! \n\n") ;
        goto I ;
      }

    else
    {
        for(temp5=0 ; temp5<strlen(w[j].nationality) ; temp5++)
        {
            if(isalpha(w[j].nationality[temp1]))
               temp6 = 1 ;
            else
            {
                temp6 = 0 ;
                break ;
            }
        }
        if(!temp6)
        {
            printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
            goto I ;
        }
    }


     do
      {
          printf("\n\t\t\t\t\t\t\t DATE OF BIRTH (DD/MM/YYYY format) : ") ;
          scanf("%d/%d/%d",& w[j].date,& w[j].month,& w[j].year) ;

          temp1 =1 ;

          // CHECKS YEAR
          if(w[j].year >= 1900 && w[j].year <= 2022)
            {
                // CHECKS MONTH
                if(w[j].month >= 1 && w[j].month <= 12)
                  {
                       // CHECKS DATE
                       if((w[j].date >= 1 && w[j].date <= 30) && (w[j].month == 4 || w[j].month == 6 || w[j].month == 9 || w[j].month == 11))
                          printf("\t\t\t\t\t\t\t VALID DATE\n\n") ;

                          else if((w[j].date >= 1 && w[j].date <= 31) && (w[j].month == 1 || w[j].month == 3 || w[j].month == 5 || w[j].month == 7 || w[j].month == 8 || w[j].month == 10 || w[j].month == 12))
                                  printf("\t\t\t\t\t\t\t VALID DATE\n\n") ;

                               else if((w[j].date >= 1 && w[j].date <= 28) && (w[j].month == 2))
                                       printf("\t\t\t\t\t\t\t VALID DATE\n\n") ;

                                    else if((w[j].date == 29 && w[j].month == 2) && (w[j].year % 400 == 0 ||(w[j].year %4 == 0 && w[j].year % 100 !=0 )))
                                            printf("\t\t\t\t\t\t\t VALID DATE\n\n") ;

                                         else
                                         {
                                              printf("\t\t\t\t\t\t\t INVALID DATE !\n\n") ;
                                              temp1 = 0 ;
                                         }

                  }
              else
                  {
                      printf("\t\t\t\t\t\t\t INVALID MONTH !\n\n");
                      temp1 = 0 ;
                  }
            }
          else
              {
                  printf("\t\t\t\t\t\t\t INVALID YEAR !\n\n");
                  temp1 = 0 ;
              }

      }while(!temp1) ;


 printf("\n\t\t\t\t\t\t\t EMERGENCY CONTACT : ") ;

   J :
   printf("\n\t\t\t\t\t\t\t FIRST NAME : ") ;
    scanf("%s",& w[j].first_nameemer) ;

    w[j].first_nameemer[0] = toupper(w[j].first_nameemer[0]) ;

    if(strlen(w[j].first_nameemer)>20 || strlen(w[j].first_nameemer)<2)
      {
        printf("\n\n\t\t\t\t\t\t\t INVALID !\n\n") ;
        goto J ;
      }

    else
    {
        for(temp1=0 ; temp1<strlen(w[j].first_nameemer) ; temp1++)
        {
            if(isalpha(w[j].first_nameemer[temp1]))
               temp2 = 1 ;
            else
            {
                temp2 = 0 ;
                break ;
            }
        }
        if(!temp2)
        {
            printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
            goto J ;
        }
    }


   K :

    printf("\n\t\t\t\t\t\t\t LAST NAME : ") ;
    scanf("%s",& w[j].last_nameemer) ;

    w[j].last_nameemer[0] = toupper(w[j].last_nameemer[0]) ;

    if(strlen(w[j].last_nameemer)>20 || strlen(w[j].last_nameemer)<1)
      {
        printf("\t\t\t\t\t\t\t INVALID : \n\n") ;
        goto K ;
      }

    else
    {
        for(temp1=0 ; temp1<strlen(w[j].last_nameemer) ; temp1++)
        {
            if(isalpha(w[j].last_nameemer[temp1]))
               temp2 = 1 ;
            else
            {
                temp2 = 0 ;
                break ;
            }
        }
        if(!temp2)
        {
            printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
            goto K ;
        }
    }

    //MOBILE NUMBER

S:

    printf("\n\t\t\t\t\t\t\t MOBILE NUMBER : ") ;
    scanf("%s",& w[j].mobile_no) ;

    if(strlen(w[j].mobile_no)>10 || strlen(w[j].mobile_no)!=10)
      {
        printf("\t\t\t\t\t\t\t INVALID CHARACTER ! \n\n") ;
        goto S ;
      }

    else
    {
        for(temp1=0 ; temp1<strlen(w[j].mobile_no) ; temp1++)
        {
            if(!isalpha(w[j].mobile_no[temp1]) && w[j].mobile_no[0]>='6' && w[j].mobile_no[0]<='9')
               temp2 = 1 ;
            else
            {
                temp2 = 0 ;
                break ;
            }
        }
        if(!temp2)
        {
            printf("\t\t\t\t\t\t\t INVALID CHARACTER !\n\n") ;
            goto S ;
        }
    }


       fprintf(fp,"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n") ;
       fprintf(fp,"\t\t\t\t\t\t\t\tPATIENT RECORDS\n\n") ;
       fprintf(fp,"\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n") ;


       fprintf(fp,"\t\t\t\t\t\t\tFIRST NAME : %s\n",w[j].first_name) ;
       fprintf(fp,"\t\t\t\t\t\t\tLAST NAME : %s\n",w[j].last_name) ;
       fprintf(fp,"\t\t\t\t\t\t\tAGE : ") ;
       for(i=0;i<2;i++)
           fprintf(fp,"%c",w[j].age[i]) ;
       fprintf(fp,"\n") ;
       fprintf(fp,"\t\t\t\t\t\t\tGENDER : %c\n",w[j].gender) ;
       fprintf(fp,"\t\t\t\t\t\t\tMOBILE NO : ") ;
       for(i=0;i<11;i++)
           fprintf(fp,"%c",w[j].mob_no[i]) ;
       fprintf(fp,"\n") ;
       fprintf(fp,"\t\t\t\t\t\t\tAADHAR NO : ") ;
       for(i=0;i<12;i++)
           fprintf(fp,"%c",w[j].aadhar_no[i]) ;
       fprintf(fp,"\n") ;
       fprintf(fp,"\t\t\t\t\t\t\tEMAIL : %s\n",w[j].email) ;
       fprintf(fp,"\t\t\t\t\t\t\tFATHER NAME : %s\n",w[j].father_name) ;
       fprintf(fp,"\t\t\t\t\t\t\tMOTHER NAME : %s\n",w[j].mother_name) ;
       fprintf(fp,"\t\t\t\t\t\t\tMARITAL STATUS : %c\n",w[j].marital_status) ;
       fprintf(fp,"\t\t\t\t\t\t\tINSURANCE : %c\n",w[j].insurance) ;
       fprintf(fp,"\t\t\t\t\t\t\tADDRESS : \n\t\t\t\t\t\t\t\t") ;
       for(i=0;i<6;i++)
           fprintf(fp,"%c",w[j].door_no[i]) ;
       fprintf(fp,"\n") ;
       fprintf(fp,"\t\t\t\t\t\t\t\t%s\n",w[j].street_name) ;
       fprintf(fp,"\t\t\t\t\t\t\t\t%s\n",w[j].area) ;
       fprintf(fp,"\t\t\t\t\t\t\t\t%s\n",w[j].district) ;
       fprintf(fp,"\t\t\t\t\t\t\t\t") ;
       for(i=0;i<6;i++)
           fprintf(fp,"%c",w[j].pincode[i]) ;
       fprintf(fp,"\n") ;
       fprintf(fp,"\t\t\t\t\t\t\t\t%s\n",w[j].state) ;
       fprintf(fp,"\t\t\t\t\t\t\t\t%s\n",w[j].nationality) ;
       fprintf(fp,"\t\t\t\t\t\t\tDATE OF BIRTH : %d/",w[j].date) ;
       fprintf(fp,"%d/",w[j].month) ;
       fprintf(fp,"%d\n",w[j].year) ;
       fprintf(fp,"\t\t\t\t\t\t\tEMERGENCY CONTACT :\n") ;
       fprintf(fp,"\t\t\t\t\t\t\t\tFIRST NAME : %s\n",w[j].first_nameemer) ;
       fprintf(fp,"\t\t\t\t\t\t\t\tLAST NAME : %s\n",w[j].last_nameemer) ;
       fprintf(fp,"\t\t\t\t\t\t\t\tMOBILE NO : ") ;
       for(i=0;i<11;i++)
           fprintf(fp,"%c",w[j].mobile_no[i]) ;
       fprintf(fp,"\n\n\n\n\n") ;

       printf("\n\t\t\t\t\t\t\t INFORMATION OF THE PATIENT IS SUCCESSFULLY RECORDED !\n\n") ;


       }



      fclose(fp) ;
      options() ;


}



void list()
{

    system("cls") ;
    FILE *fp ;
    fp = fopen("Record","r") ;

    if(fp == NULL)
      {
          printf("\t\t\t\t\t\t\t CAN NOT OPEN FILE !\n\n") ;
          exit(1) ;
      }

    char s ;
    system("cls") ;
    fp=fopen("Record","r") ;

    for(j=0;j<SIZE;j++)
    {

    while((s=fgetc(fp))!=EOF)
         {
            printf("%c",s) ;
         }

    }
    fclose(fp) ;

    getch() ;
    options() ;

}
/*


void edit()

{
    system("cls") ;
    char name[20] ;

    FILE *fp ;
    fp = fopen("Record","r+") ;

    if(fp == NULL)
      {
          printf("\t\t\t\t\t\t\t CAN NOT OPEN FILE !\n\n") ;
          exit(1) ;
      }

    printf("\t\t\t\t\t\t\t\t -----EDIT RECORD----- \n\n") ;
    printf("\n\t\t\t\t\t\t\t\t ENTER PATIENT NAME TO BE EDITED :") ;
    scanf("%s",& name) ;
    fflush(stdin) ;

    name[0] = toupper(name[0]) ;

    rewind(fp) ;
    system("cls") ;
    while(fread(&w,sizeof(w),1,fp) == 1)
         {
            if(strcmp(name,w.first_name) != NULL)
            {
                printf("\n\t\t\t\t\t\t\tENTER MODIFIED DETAILS") ;
                fseek(fp,-sizeof(w),SEEK_CUR);
                        fwrite(&fp,sizeof(w),1,fp);

                break ;
            }
            fclose(fp) ;

         }
}
*/

void ex_it()
{
    system("cls");
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n") ;
    printf("\t\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n\n") ;
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n") ;
    printf("\n\t\t\t\t\t\t\t\t THANK YOU !");

}


void search(struct patient_details w[])
{
    system("cls");
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n") ;
    printf("\t\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n\n") ;
    printf("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n") ;

    char name[20],l;
    int found = 0;
    long int n ;

	FILE *fp ;
	fp = fopen("Record","r");

	if(fp == NULL)
      {
          printf("\t\t\t\t\t\t\t CAN NOT OPEN FILE !\n\n") ;
          exit(1) ;
      }

    printf("\n\n\t\t\t\t\t\t\t SEARCH RECORD\n");
    printf("\n\n\t\t\t\t\t\t\t ENTER THE NAME TO BE SEARCHED : ");
    scanf("%s",&name);

    system("cls");

    for(j=0;j<SIZE;j++)
    {
		if(strstr(w[j].first_name,name) == 0)

            {
                found=1;
                title();
               printf("\t\t\t\t\t\t\tFOUND\n\n") ;

         break ;
            }



	}

	if(!found)
    {
        title();
        printf("\t\t\t\t\t\t\tNOT FOUND\n\n") ;
    }


	fclose(fp);

	getch() ;
    options() ;

}



void del(struct patient_details w[])

{
    system("cls") ;
    char name[20] ;

    FILE *fp ,*ft;
    fp = fopen("Record","r") ;

    if(fp == NULL)
      {
          printf("\t\t\t\t\t\t\t CAN NOT OPEN FILE !\n\n") ;
          exit(1) ;
      }


    ft = fopen("Record","w") ;

    if(ft == NULL)
      {
          printf("\t\t\t\t\t\t\t CAN NOT OPEN FILE !\n\n") ;
          exit(1) ;
      }

    printf("\t\t\t\t\t\t\t\t -----DELETE RECORD----- \n\n") ;
    printf("\n\t\t\t\t\t\t\t\t ENTER PATIENT NAME TO BE DELETED :") ;
    scanf("%s",& name) ;
    fflush(stdin) ;

    name[0] = toupper(name[0]) ;

    rewind(fp) ;
    system("cls") ;

    for(j=0;j<SIZE;j++)
        {
    while(fread(&w,sizeof(w[j]),1,fp))
	{
		if(strcmpi(name,w[j].first_name) != 0)
		   fwrite(&w,sizeof(w[j]),1,ft);
	}
	fclose(fp);
	fclose(ft);
    remove("Record");
    rename("Temp","Record");

        }
        options() ;

}
