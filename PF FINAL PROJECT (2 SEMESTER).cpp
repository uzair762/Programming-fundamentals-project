#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
struct tourist 
{
    int touristID;
    char name[100];
    int age; 
    char gender[10];  
    char passportNumber[20];      
    char address[100];        
    int contactDetails;
    char nationality[100];
    char preferredDestination[100];
    int emergencyContact;   
};
struct package 
{
    int packageID;
    char packageName[100];
    char destination[100];
    float price; 
    char startDate[20];          
    char endDate[20]; 
    char includedServices[100];
    int availableSeats;             
    char departureDates[100];     
    char destinationCountry[100]; 
};
struct booking 
{
    int bookingID;
    int touristID;
    int packageID;
    char bookingDate[100];
    char paymentStatus[100];
    char travelDates[100];
    float totalAmount;             
    float amountPaid;    
	int numberOfTravelers;         
    float balanceAmount;                                   
};
struct tourist t;
struct package p;
struct booking b;
	FILE *f;
/////////////////////////////////////////////functions///////////////////////////////////
	
void header(const char *title);
void footer();
void touristinput();
void printtourist();
void packageinput();
void printpacKage();
void bookinginput();
void printbooking();
void addtourist();
void addpackage();
void addbooking();
void deletetourist();
void deletepackage();
void deletebooking();
void updatetourist();
void updatepackage();
void updatebooking();
void searchtourist();
void searchpackage();
void searchbooking();
void touristsbynationality();
void sortBookingsByDate();
///////////////////////////////////////////functions////////////////////////////////////////////
int main()
 {
 	
 	int num;
	 while(1)
	 {
printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	    header("\n================= Tourism Management System =================\n");
        printf("1. input Tourist Information\n");
        printf("2. print tourist information\n");
        printf("3. input Package Information\n");
        printf("4. print package information\n");
        printf("5. input Booking Information\n");
        printf("6. print booking information\n");
        printf("7. Add Tourist\n");
        printf("8. Add Package\n");
        printf("9. Add Booking\n");
        printf("10. Delete Tourist\n");
        printf("11. Delete Package\n");
        printf("12. Delete Booking\n");
        printf("13. Update Tourist\n");
        printf("14. Update Package\n");
        printf("15. Update Booking\n");
        printf("16. Search Tourist\n");
        printf("17. Search Package\n");
        printf("18. Search Booking\n");
        printf("19. Tourists by Nationality\n");
        printf("20. Sort Bookings by Date\n");
        printf("21. Exit\n");
        
printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

        
        printf("Enter your choice:--------- ");
    
        scanf("%d",&num);

        switch (num)
		 {
            case 1:
                touristinput();
                break;
            case 2:
                printtourist();
                break;
            case 3:
                packageinput();
                break;
            case 4:
                printpacKage();
                break;
            case 5:
                bookinginput();
                break;
            case 6:
                printbooking();
                break;
            case 7:
                addtourist();
                break;
            case 8:
                addpackage();
                break;
            case 9:
                addbooking();
                break;
            case 10:
                deletetourist();
                break;
            case 11:
                deletepackage();
                break;
            case 12:
                deletebooking();
                break;
            case 13:
                updatetourist();
                break;
            case 14:
                updatepackage();
                break;
            case 15:
                updatebooking();
                break;
            case 16:
                searchtourist();
                break;
            case 17:
                searchpackage();
                break;
            case 18:
                searchbooking();
                break;
            case 19:
                touristsbynationality();
                break;
            case 20:
                sortBookingsByDate();
                break;
            case 21:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        footer();
    }
    return 0;
}
///////////////////////header////////////////////////////////////


void header(const char *title)
{
	printf("\n=================================================\n");
    printf("%33s\n", title);
    printf("=================================================\n");
}


///////////////////////footer////////////////////////////////////
void footer()
{
	printf("-------------------------------------------------\n");
}


/////////////////////tourist  info  input//////////////////////////////
void touristinput()
	{
			f=fopen("tourist.txt","w");
				if(f == NULL)
				{
					printf("EMPTY");
					return ;
				}
				printf("Enter Tourist Information:\n");

				 printf("ENTER total tourists:");
				 int tour;
				 scanf("%d",&tour);
				 fflush(stdin);
		for(int i=0;i<tour;i++)
	{
		
        printf("\nEnter details for tourists %d:\n", i + 1);
		 
		
	   printf("Enter Tourist ID:...\n ");
       scanf("%d", &t.touristID);
       fflush(stdin);

       printf("Enter Name: \n");
       gets(t.name);

       printf("Enter Age: \n");
       scanf("%d", &t.age);
       fflush(stdin);

       printf("Enter Gender: \n");
       gets(t.gender);

       printf("Enter Passport Number: \n");
       gets(t.passportNumber);

       printf("Enter Address: \n");
       gets(t.address);

       printf("Enter Contact Details: \n");
       scanf("%d",&t.contactDetails);

       printf("Enter Nationality: \n");
       gets(t.nationality);

       printf("Enter Preferred Destination: \n");
       gets(t.preferredDestination);

       printf("Enter Emergency Contact: \n");
       scanf("%d",&t.emergencyContact);
       fwrite(&t,sizeof(t),1,f);
   }
	  fclose(f);
}


//////////////////////////////print tourist info////////////////////////////


void printtourist()
 {
 
       f = fopen("tourist.txt", "r");
    if (f == NULL)
	 {
        printf("Error opening file for reading.\n");
        return ;
     }
	

 
       printf("tourist details:\n");
       while (fread(&t, sizeof(t), 1, f))
	   {
        printf("Tourist ID: %d\n",t.touristID);
        printf("Name: %s\n",t.name);
        printf("Age: %d\n",t.age);
        printf("Gender:%s\n",t.gender);
        printf("address:%s\n",t.address);
        printf("Passport: %s\n",t.passportNumber);
        printf("Conatct details:%d\n",t.contactDetails);
        printf("Nationality:%s\n",t.nationality);
        printf("Emergency contact:%d\n",t.emergencyContact);
        printf("Destination:%s\n",t.preferredDestination);
	   	}
	fclose(f);
 }
 
 
////////////////////////////////// package info input ///////////////////////////////////////////////// 

void packageinput()
	{
			f=fopen("package.txt","w");
				if(f == NULL)
				{
					printf("EMPTY");
					return ;
				}
				printf("Enter package Information:\n");

				 printf("ENTER total packages:");
				 int pack;
				 scanf("%d",&pack);
				 fflush(stdin);
		for(int i=0;i<pack;i++)
	{
		
                 printf("\nEnter details for packages %d:\n", i + 1);
		 
	             printf("Enter package ID: \n");
                 scanf("%d", &p.packageID);
                 fflush(stdin); 

                 printf("Enter package name: \n");
                 gets(p.packageName); 

                 printf("Enter destination: \n");
                 gets(p.destination);

                 printf("Enter price: \n");
                 scanf("%f", &p.price);
                 fflush(stdin);

                 printf("Enter start date: \n");
                 gets(p.startDate);

                 printf("Enter end date: \n");
                 gets(p.endDate);

                 printf("Enter included services: \n");
                 gets(p.includedServices);

                 printf("Enter available seats: \n");
                 scanf("%d", &p.availableSeats);
                 fflush(stdin);

                 printf("Enter departure dates: \n");
                 gets(p.departureDates);

                 printf("Enter destination country: \n");
                 gets(p.destinationCountry);
	  
                 fwrite(&p,sizeof(p),1,f);
   }
	             fclose(f);
}

/////////////////////////////////print package info/////////////////////////////

void printpacKage()
 {
 
       f = fopen("package.txt", "r");
    if (f == NULL)
	 {
        printf("Error opening file for reading.\n");
        return ;
     }
	

 
       printf("package details:\n");
       while (fread(&p, sizeof(p), 1, f))
	   {
        printf("package ID: %d\n",p.packageID);
        printf("package name: %s\n",p.packageName);
        printf("destination: %s\n",p.destination);
        printf("price:%f\n",p.price);
        printf("Start date:%s\n",p.startDate);
        printf("End date: %s\n",p.endDate);
        printf("Services:%d\n",p.includedServices);
        printf("Seats:%d\n",p.availableSeats);
        printf("Deoarture dates:%d\n",p.departureDates);
        printf("Sestination country:%s\n",p.destinationCountry);
	   	}
	fclose(f);
 }
/////////////////////////////////////booking  info   input///////////////////////////////

void bookinginput()
	{
		f=fopen("booking.txt","w");
			if(f == NULL)
			{
				printf("EMPTY");
				return ;
			}
			printf("Enter booking Information:\n");

			printf("ENTER total bookings:");
			int book;
		    scanf("%d",&book);
		    fflush(stdin);
		    for(int i=0;i<book;i++)
	          {
		
                 printf("\nEnter details for bookings %d:\n", i + 1);
		 
	             printf("Enter booking ID: \n");
                 scanf("%d", &b.bookingID);
                 fflush(stdin);

    
                 printf("Enter tourist ID: \n");
                 scanf("%d", &b.touristID);
                 fflush(stdin);

    
                 printf("Enter package ID: \n");
                 scanf("%d", &b.packageID);
                 fflush(stdin);

    
                 printf("Enter booking date: \n");
                 gets(b.bookingDate); 


                 printf("Enter payment status: \n");
                 gets(b.paymentStatus);
    
    
                 printf("Enter travel dates: \n");
                 gets(b.travelDates);
    
                 printf("Enter total amount: \n");
                 scanf("%f", &b.totalAmount);
                 fflush(stdin);
                 
                 printf("enter paid amoint:...\n");
                 scanf("%f", &b.amountPaid);
                 fflush(stdin);


                 printf("Enter number of travelers: \n");
                 scanf("%d", &b.numberOfTravelers);
                 fflush(stdin);
    
                 printf("Enter balance amount: \n");
                 scanf("%f", &b.balanceAmount);
                 fflush(stdin);

	  
                    fwrite(&b,sizeof(b),1,f);
        }
	     fclose(f);
}


/////////////////////////////////////print package info/////////////////////////////////
 
void printbooking()
 {
 
       f = fopen("booking.txt", "r");
    if (f == NULL)
	 {
        printf("Error opening file for reading.\n");
        return ;
     }
	

 
       printf("bookings details:\n");
       while (fread(&b, sizeof(b), 1, f))
	   {
        printf("booking  ID: %d\n",b.bookingID);
        printf("tourist name: %d\n",b.touristID);
        printf("package: %d\n",b.packageID);
        printf("booking date:%s\n",b.bookingDate);
        printf("payment status:%s\n",b.paymentStatus);
        printf("travel dates: %s\n",b.travelDates);
        printf("total amount:%f\n",b.totalAmount);
        printf("amount paid:%f\n",b.amountPaid);
        printf("number of travelers:%d\n",b.numberOfTravelers);
        printf("balance amount:%f\n",b.balanceAmount);
	   	}
	fclose(f);
 }
/////////////////////////////////////////add tourist////////////////////////////////////////

void addtourist()
{ 
     printf("Add the new tourist....\n");
	
	
	system("cls");
	
	printf("Enter the  Data");

	
    tourist t;
	printf("Enter Tourist ID: \n");
       scanf("%d", &t.touristID);
       fflush(stdin);

       printf("Enter Name: \n");
       gets(t.name);

       printf("Enter Age: \n");
       scanf("%d", &t.age);
       fflush(stdin);

       printf("Enter Gender: \n");
       gets(t.gender);

       printf("Enter Passport Number: \n");
       gets(t.passportNumber);

       printf("Enter Address: \n");
       gets(t.address);

       printf("Enter Contact Details: \n");
       scanf("%d",&t.contactDetails);

       printf("Enter Nationality: \n");
       gets(t.nationality);

       printf("Enter Preferred Destination: \n");
       gets(t.preferredDestination);

       printf("Enter Emergency Contact: \n");
       scanf("%d",&t.emergencyContact);
	
	f=fopen("tourist.txt","w");
	if(f==NULL)
	{
		printf("Unable To Open File\n");
		return;
	}
	fwrite(&t,sizeof(t),1,f);
	fclose(f);
	printf("tourist  Added");
}
///////////////////////////////////////////////pakkage added//////////////////////////////////////

void addpackage()
{ 
    printf("Add the new package....\n");
	
	
	system("cls");
	
	printf("Enter the  Data");


    package p;
     printf("Enter package ID: \n");
                 scanf("%d", &p.packageID);
                 fflush(stdin); 

                 printf("Enter package name: \n");
                 gets(p.packageName); 

                 printf("Enter destination: \n");
                 gets(p.destination);

                 printf("Enter price: \n");
                 scanf("%f", &p.price);
                 fflush(stdin);

                 printf("Enter start date: \n");
                 gets(p.startDate);

                 printf("Enter end date: \n");
                 gets(p.endDate);

                 printf("Enter included services: \n");
                 gets(p.includedServices);

                 printf("Enter available seats: \n");
                 scanf("%d", &p.availableSeats);
                 fflush(stdin);

                 printf("Enter departure dates: \n");
                 gets(p.departureDates);

                 printf("Enter destination country: \n");
                 gets(p.destinationCountry);
	
	
	f=fopen("tourist.txt","w");
	if(f==NULL)
	{
		printf("Unable To Open File\n");
		return;
	}
	fwrite(&p,sizeof(p),1,f);
	fclose(f);
	printf("package   Added");
}
/////////////////////////////////////////////////////bookings add//////////////////////////////////////////////

void addbooking()
{ 
    printf("Add the new bookings....\n");
	
	
	system("cls");
	
	printf("Enter the  Data");


    booking b;
    printf("Enter booking ID: \n");
                 scanf("%d", &b.bookingID);
                 fflush(stdin);

    
                 printf("Enter tourist ID: \n");
                 scanf("%d", &b.touristID);
                 fflush(stdin);

    
                 printf("Enter package ID: \n");
                 scanf("%d", &b.packageID);
                 fflush(stdin);

    
                 printf("Enter booking date: \n");
                 gets(b.bookingDate); 


                 printf("Enter payment status: \n");
                 gets(b.paymentStatus);
    
    
                 printf("Enter travel dates: \n");
                 gets(b.travelDates);
    
                 printf("Enter total amount: \n");
                 scanf("%f", &b.totalAmount);
                 fflush(stdin);

    
                 printf("Enter amount paid: \n");
                 scanf("%f", &b.amountPaid);
                 fflush(stdin);


                 printf("Enter number of travelers: \n");
                 scanf("%d", &b.numberOfTravelers);
                 fflush(stdin);
    
                 printf("Enter balance amount: \n");
                 scanf("%f", &b.balanceAmount);
                 fflush(stdin);
     
	
	f=fopen("booking.txt","w");
	if(f==NULL)
	{
		printf("Unable To Open File\n");
		return;
	}
	fwrite(&b,sizeof(b),1,f);
	fclose(f);
	printf("booking  Added");
}
///////////////////////////////////////////////////delete tourist//////////////////////////////////////

void deletetourist()
{
    int id;
    printf("Enter the tourist ID to delete: ");
    scanf("%d", &id);
      f= fopen("tourist.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct tourist t;
    while (fread(&t, sizeof(t), 1, f))
	 {
        if (t.touristID != id)
		 {
            fwrite(&t, sizeof(t), 1, temp);
         }
     }
    fclose(f);
    fclose(temp);
    remove("tourist.txt");
    rename("temp.txt", "tourist.txt");
    printf("Tourist deleted successfully!\n");
}
//////////////////////////////////////////delete packages////////////////////////////////////////////////

void deletepackage()
 {
    int id;
    printf("Enter the package ID to delete: ");
    scanf("%d", &id);
     f= fopen("package.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct package p;
    while (fread(&p, sizeof(p), 1, f))
	 {
        if (p.packageID != id)
		 {
            fwrite(&p, sizeof(p), 1, temp);
        }
    }
    fclose(f);
    fclose(temp);
    remove("package.txt");
    rename("temp.txt", "package.txt");
    printf("Package deleted successfully!\n");
}
/////////////////////////////////////////////booking delete//////////////////////////////////////////////////////////////
void deletebooking()
 {
    int id;
    printf("Enter the booking ID to delete: ");
    scanf("%d", &id);
    f= fopen("booking.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct booking b;
    while (fread(&b, sizeof(b), 1, f))
	 {
        if (b.bookingID != id)
		 {
            fwrite(&b, sizeof(b), 1, temp);
         }
     }
    fclose(f);
    fclose(temp);
    remove("booking.txt");
    rename("temp.txt", "booking.txt");
    printf("Booking deleted successfully!\n");
}
//////////////////////////////////////////////////update tourist//////////////////////////////////////////////////////////////////////

void updatetourist()
 {
    int id;
    printf("Enter the tourist ID to update: ");
    scanf("%d", &id);
    f= fopen("tourist.txt", "r");
    struct tourist t;
    while (fread(&t, sizeof(t), 1, f))
	 {
        if (t.touristID == id)
		 {
            printf("Enter new name: \n");
            gets(t.name);
            printf("Enter new age: \n");
            scanf("%d", &t.age);
            printf("Enter new gender: \n");
            gets(t.gender);
            printf("Enter new passport number:\n ");
            gets(t.passportNumber);
            printf("Enter new address: ");
            gets(t.address);
            printf("Enter new contact details: \n");
            scanf("%d", &t.contactDetails);
            printf("Enter new nationality: \n");
            gets(t.nationality);
            printf("Enter new preferred destination: \n");
            gets(t.preferredDestination);
            printf("Enter new emergency contact: \n");
            scanf("%d", &t.emergencyContact);
            fwrite(&t, sizeof(t), 1, f);
            fclose(f);
            printf("Tourist updated successfully!\n");
            return;
        }
    }
    fclose(f);
    printf("Tourist not found!\n");
}
//////////////////////////////////////////////////////update package/////////////////////////////////////////////////////////

void updatepackage()
 {
    int id;
    printf("Enter the package ID to update: ");
    scanf("%d", &id);
    f= fopen("package.txt", "r");
    struct package p;
    while (fread(&p, sizeof(p), 1, f))
	 {
        if (p.packageID == id)
		 {
            printf("Enter new package name: \n");
            gets(p.packageName);
            printf("Enter new destination: \n");
            gets(p.destination);
            printf("Enter new price: \n");
            scanf("%f", &p.price);
            printf("Enter new start date: \n");
            gets(p.startDate);
            printf("Enter new end date: \n");
            gets(p.endDate);
            printf("Enter new included services: \n");
            gets(p.includedServices);
            printf("Enter new available seats: \n");
            scanf("%d", &p.availableSeats);
            printf("Enter new departure dates: \n");
            gets(p.departureDates);
            printf("Enter new destination country: \n");
            gets(p.destinationCountry);
            fwrite(&p, sizeof(p), 1, f);
            fclose(f);
            printf("Package updated successfully!\n");
            return;
        }
    }
    fclose(f);
    printf("Package not found!\n");
}
////////////////////////////////////////////////////booking update////////////////////////////////////////////////

void updatebooking()
{
    int id;
    printf("Enter the booking ID to update: ");
    scanf("%d", &id);
     f= fopen("booking.txt", "r");
    struct booking b;
    while (fread(&b, sizeof(b), 1, f))
	 {
        if (b.bookingID == id)
		 {
            printf("Enter new booking date: \n");
            gets(b.bookingDate);
            printf("Enter new payment status: \n");
            gets(b.paymentStatus);
            printf("Enter new travel dates: \n");
            gets(b.travelDates);
            printf("Enter new total amount: \n");
            scanf("%f", &b.totalAmount);
            printf("Enter new amount paid: \n");
            scanf("%f", &b.amountPaid);
            printf("Enter new number of travelers: \n");
            scanf("%d", &b.numberOfTravelers);
            printf("Enter new balance amount: \n");
            scanf("%f", &b.balanceAmount);
            fwrite(&b, sizeof(b), 1, f);
            fclose(f);
            printf("Booking updated successfully!\n");
            return;
        }
    }
    fclose(f);
    printf("Booking not found!\n");
}
/////////////////////////////////////////////////////////////search tourist//////////////////////////////////////////////////////////////

void searchtourist()
 {
    int id;
    printf("Enter the tourist ID to search: ");
    scanf("%d", &id);
    f= fopen("tourist.txt", "r");
    struct tourist t;
    while (fread(&t, sizeof(t), 1, f))
	 {
        if (t.touristID == id)
		 {
            printf("Tourist found!\n");
            printf("Name: %s\n", t.name);
            printf("Age: %d\n", t.age);
            printf("Gender: %s\n", t.gender);
            printf("Passport Number: %s\n", t.passportNumber);
            printf("Address: %s\n", t.address);
            printf("Contact Details: %d\n", t.contactDetails);
            printf("Nationality: %s\n", t.nationality);
            printf("Preferred Destination: %s\n", t.preferredDestination);
            printf("Emergency Contact: %d\n", t.emergencyContact);
            fclose(f);
            return;
        }
    }
    fclose(f);
    printf("Tourist not found!\n");
}
//////////////////////////////////////////////////////////search package//////////////////////////////////////////////

void searchpackage()
 {
    int id;
    printf("Enter the package ID to search: ");
    scanf("%d", &id);
    f= fopen("package.txt", "r");
    struct package p;
    while (fread(&p, sizeof(p), 1, f))
	 {
        if (p.packageID == id)
		 {
            printf("Package found!\n");
            printf("Package Name: %s\n", p.packageName);
            printf("Destination: %s\n", p.destination);
            printf("Price: %f\n", p.price);
            printf("Start Date: %s\n", p.startDate);
            printf("End Date: %s\n", p.endDate);
            printf("Included Services: %s\n", p.includedServices);
            printf("Available Seats: %d\n", p.availableSeats);
            printf("Departure Dates: %s\n", p.departureDates);
            printf("Destination Country: %s\n", p.destinationCountry);
            fclose(f);
            return;
        }
    }
    fclose(f);
    printf("Package not found!\n");
}
/////////////////////////////////////////////////////search bookings/////////////////////////////////////

void searchbooking()
 {
    int id;
    printf("Enter the booking ID to search: ");
    scanf("%d", &id);
    f= fopen("booking.txt", "r");
    struct booking b;
    while (fread(&b, sizeof(b), 1, f))
	 {
        if (b.bookingID == id)
		 {
            printf("Booking found!\n");
            printf("Booking Date: %s\n", b.bookingDate);
            printf("Payment Status: %s\n", b.paymentStatus);
            printf("Travel Dates: %s\n", b.travelDates);
            printf("Total Amount: %f\n", b.totalAmount);
            printf("Amount Paid: %f\n", b.amountPaid);
            printf("Number of Travelers: %d\n", b.numberOfTravelers);
            printf("Balance Amount: %f\n", b.balanceAmount);
            fclose(f);
            return;
        }
    }
    fclose(f);
    printf("Booking not found!\n");
}
/////////////////////////////////////////////tourists by nationality/////////////////////////////////////////////

void touristsbynationality()
 {
    char nationality[100];
    printf("Enter nationality to filter: ");
    fflush(stdin);
    gets(nationality);

    FILE *f = fopen("tourist.txt", "r");
    if (f == NULL)
	 {
        printf("Error opening file for reading.\n");
        return;
    }

    struct tourist t;
    printf("Tourists with nationality %s:\n", nationality);
    while (fread(&t, sizeof(t), 1, f)) 
	{
        if (strcmp(t.nationality, nationality) == 0)
		 {
            printf("Tourist ID: %d, Name: %s, Age: %d\n", t.touristID, t.name, t.age);
        }
    }
    fclose(f);
}
//////////////////////////////////////////////////sort bookings by date///////////////////////////////////////////////////

void sortBookingsByDate()
{
    struct booking b[100];
    int n, i, j;
    f = fopen("booking.txt", "r");
    n = 0;
    while (fread(&b[n], sizeof(b[n]), 1, f))
    {
        n++;
    }
    fclose(f);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(b[i].bookingDate, b[j].bookingDate) > 0)
            {
                struct booking temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    f = fopen("booking.txt", "w");
    for (i = 0; i < n; i++)
    {
        fwrite(&b[i], sizeof(b[i]), 1, f);
    }
    fclose(f);
    printf("Bookings sorted by date successfully!\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
