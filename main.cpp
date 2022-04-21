#include <iostream> 
#include <set>
#include <string>
#include<list>
#include <vector>
using namespace std;

struct time
{
    unsigned int year;
    unsigned int  month;
    unsigned int day;

    unsigned int hour;
    unsigned int minute;
};

struct booking
{
    string name;
    vector<string> itinerary;

    struct time bookingtime;

};

vector<booking> bookingStructure;

void addBooking(booking b)
{
    bookingStructure.push_back(b);

}

string getMonth (int Month)
{
    switch (Month)
    {
        case 1:
        return "Jan";
        case 2:
        return "Feb";
        case 3:
        return "March";  
        case 4:
        return "April";
        case 5:
        return "May";
        case 6:
        return "June";  
        case 7:
        return "July";
        case 8:
        return "August";
        case 9:
        return "September"; 
        case 10:
        return "October";
        case 11:
        return "November";
        case 12:
        return "December";         
    }

    return "-1";
    
}
void displayBooking ()
{
    for(int i=0 ; i<bookingStructure.size(); i++)
    {
        cout<<bookingStructure[i].name<<"  "<<getMonth(bookingStructure[i].bookingtime.month);
        cout<<":"<<bookingStructure[i].bookingtime.day<<"  ";
        cout<<bookingStructure[i].bookingtime.hour<<":"<<bookingStructure[i].bookingtime.minute<<"  ";
        cout<<bookingStructure[i].bookingtime.year<<"  ";
        

        for ( unsigned int it =  0 ; it < bookingStructure[i].itinerary.size(); it++)
        {

             cout<<bookingStructure[i].itinerary[it];

             if(it<bookingStructure[i].itinerary.size()-1)
             {
                 cout<<"->";
             }
        }  
        cout<<endl;     
    }
}


vector<booking> selectBookingBeforeSpecificTime (struct time givenTime)
{
    vector<booking> selectedbookings;

    for(int i=0 ; i<bookingStructure.size();i++)
    {
        if(bookingStructure[i].bookingtime.year<=givenTime.year) // Compare Year
        {
            if(bookingStructure[i].bookingtime.year<givenTime.year) // Previous year , add to vector
            {
                selectedbookings.push_back(bookingStructure[i]);
                continue;
            }
            else  //Same year
            {
                if(bookingStructure[i].bookingtime.month<=givenTime.month) // Compare month
                {
                    if(bookingStructure[i].bookingtime.month<givenTime.month) // Previous month , add to vector
                    {
                        selectedbookings.push_back(bookingStructure[i]);
                        continue;
                    }
                } 
                else //Same month
                {
                    if(bookingStructure[i].bookingtime.day<=givenTime.day) // Compare day
                    {
                        if(bookingStructure[i].bookingtime.day<givenTime.day) // Previous day , add to vector
                        {
                            selectedbookings.push_back(bookingStructure[i]);
                            continue;
                        }
                    } 
                    else // Same Day
                    {

                        if(bookingStructure[i].bookingtime.hour<=givenTime.hour) // Compare hour
                        {
                            if(bookingStructure[i].bookingtime.hour<givenTime.hour) // Previous hour , add to vector
                            {
                                selectedbookings.push_back(bookingStructure[i]);
                                continue;
                            }
                        }
                        else 
                        {
                            if(bookingStructure[i].bookingtime.minute<=givenTime.minute) // Compare hour
                            {
                                if(bookingStructure[i].bookingtime.minute<givenTime.minute) // Previous minute , add to vector
                                {
                                    selectedbookings.push_back(bookingStructure[i]);
                                    continue;
                                }
                            }  
                        }

                    }
                    
                }
            }
        }
    }


    return selectedbookings;

}

/*
 struct booking
{
    string name;
    vector<string> itinerary;

    struct time bookingtime;

};*/


vector<booking> selectSpecificItineary (vector<string> itineary)
{
        vector<booking> selectedBookings;
        bool matchIT ;

        for (int i = 0 ; i<bookingStructure.size();i++)
        {
            struct  booking currentbooking = selectedBookings[i];
            matchIT = false;
            // Element to be searched
            string ser = itineary[0];
            
            // std::find function call
            std::vector<string>::iterator it  = std::find (currentbooking.itinerary.begin(), currentbooking.itinerary.end(), ser);

            if(it != currentbooking.itinerary.end())
            {
                int index = it - currentbooking.itinerary.begin();
                matchIT = std::equal(itineary.begin(), itineary.end(), currentbooking.itinerary.begin() + index);
            }

            if(matchIT)
            {
                selectedBookings.push_back(currentbooking);
            }

        }

        return selectedBookings;
}


int main()
{

    booking test;

    test.name="Mina";
    test.itinerary.push_back("AMS");
    test.itinerary.push_back("CAI"); 

    test.bookingtime.year=2022;
    test.bookingtime.month=04;
    test.bookingtime.day=01;

    test.bookingtime.hour= 7;
    test.bookingtime.minute = 30;

    addBooking(test);
    displayBooking();

    cout<<"Test ss"<<endl;

    return 0;
}