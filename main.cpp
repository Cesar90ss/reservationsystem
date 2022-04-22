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
    string paxnam;
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
    string returnvalue = "";
    switch (Month)
    {
        case 1:
        returnvalue = "Jan";
        break;
        case 2:
        returnvalue = "Feb";
        break;
        case 3:
        returnvalue = "March";
        break;  
        case 4:
        returnvalue = "April";
        break;
        case 5:
        returnvalue = "May";
        break;
        case 6:
        returnvalue = "June"; 
        break; 
        case 7:
        returnvalue = "July";
        break;
        case 8:
        returnvalue = "August";
        break;
        case 9:
        returnvalue = "September"; 
        break;
        case 10:
        returnvalue = "October";
        break;
        case 11:
        returnvalue = "November";
        break;
        case 12:
        returnvalue = "December";
        break;         
    }

    return returnvalue;
    
}
void displayBooking ()
{
    for(int i=0 ; i<bookingStructure.size(); i++)
    {
        cout<<bookingStructure[i].paxnam<<"  "<<getMonth(bookingStructure[i].bookingtime.month);
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
            else //Same Year
            {
                if(bookingStructure[i].bookingtime.month<=givenTime.month) // Compare month
                {
                    if(bookingStructure[i].bookingtime.month<givenTime.month) // Previous month , add to vector
                    {
                        selectedbookings.push_back(bookingStructure[i]);
                        continue;
                    }
                    else // same month
                    {   
                        if(bookingStructure[i].bookingtime.day<=givenTime.day) // Compare day
                        {
                            if(bookingStructure[i].bookingtime.day<givenTime.day) // Previous day , add to vector
                            {
                                selectedbookings.push_back(bookingStructure[i]);
                                continue;
                            }
                            else //same day
                            {
                                if(bookingStructure[i].bookingtime.hour<=givenTime.hour) // Compare hour
                                {
                                    if(bookingStructure[i].bookingtime.hour<givenTime.hour) // Previous hour , add to vector
                                    {
                                        selectedbookings.push_back(bookingStructure[i]);
                                        continue;
                                    }
                                    else // same hour
                                    {
                                        if(bookingStructure[i].bookingtime.minute<=givenTime.minute) // Compare hour
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
        }
    }


    return selectedbookings;

}




vector<booking> selectSpecificItineary (vector<string> itineary)
{
        vector<booking> selectedBookings;
        bool matchIT ;


        for (int i = 0 ; i<bookingStructure.size();i++)
        {
            booking currentbooking = bookingStructure[i];
            matchIT = false;
            // Element to be searched
            string ser = itineary[0];
            
            // std::find function call
            auto it  = find (currentbooking.itinerary.begin(), currentbooking.itinerary.end(), ser);

            if(it != currentbooking.itinerary.end())
            {
                int index = it - currentbooking.itinerary.begin();
                matchIT = equal(itineary.begin(), itineary.end(), currentbooking.itinerary.begin() + index);
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

//Booking 1:

    test.paxnam="Mina";
    test.itinerary.push_back("AMS");
    test.itinerary.push_back("CAI"); 
    test.itinerary.push_back("FRA"); 

    test.bookingtime.year=2022;
    test.bookingtime.month=04;
    test.bookingtime.day=01;

    test.bookingtime.hour= 7;
    test.bookingtime.minute = 29;

    addBooking(test);
    
    
//Booking 2:

    booking test2;

    test2.paxnam="Ahmed";
    test2.itinerary.push_back("AMS");
    test2.itinerary.push_back("CAI"); 
    test2.itinerary.push_back("FRA"); 
    test2.itinerary.push_back("GER");


    test2.bookingtime.year=2022;
    test2.bookingtime.month=04;
    test2.bookingtime.day=01;

    test2.bookingtime.hour= 7;
    test2.bookingtime.minute = 30;

    addBooking(test2);
    
    
    displayBooking();



    // test select specific Itineary

    vector<string> itineary;
    itineary.push_back("FRA");
    itineary.push_back("GER");

     
    auto outputselectSpecificItineary = selectSpecificItineary(itineary);

    cout<<"outputSize:"<< outputselectSpecificItineary.size()<<endl;

    for(int i =0 ; i<outputselectSpecificItineary.size() ; i++)
    {
        cout<<outputselectSpecificItineary[i].paxnam<<endl;
    }
    cout<<"*******************"<<endl;
    // test selectBookingBeforeSpecificTime

    struct time t;
    t.year = 2022;
    t.month = 4;
    t.day = 1;
    t.hour = 7;
    t.minute = 28;

    auto outputselectSpecificTime = selectBookingBeforeSpecificTime(t);

    cout<<"outputSize:"<< outputselectSpecificTime.size()<<endl;

    for(int i =0 ; i<outputselectSpecificTime.size() ; i++)
    {
        cout<<outputselectSpecificTime[i].paxnam<<endl;
    }

 
    return 0;
}