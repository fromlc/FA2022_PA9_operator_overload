//------------------------------------------------------------------------------
// CommunityBike.h : class declaration and definition file
//------------------------------------------------------------------------------
#ifndef COMMUNITYBIKE_H
#define COMMUNITYBIKE_H

#include <iostream>
#include <string>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;
using std::ostream;
using std::string;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// CommunityBike
//------------------------------------------------------------------------------
class CommunityBike {
private:
    static int m_bikeCount;     // how many bikes in community pool
    static int m_hourlyRate;    // all bikes cost the same to rent

    int m_id;                   // this bike's unique instance number
    int m_frameHeight;          // frame height in inches
    bool m_available;           // true if available for rent, false otherwise
    string m_color;             // predominant frame color
    string m_description;       // more info on this bike

public:
    //--------------------------------------------------------------------------
    // constructor
    //      uses const string&& (move semantics) to avoid string copy
    //--------------------------------------------------------------------------
    CommunityBike(const string&& color, int frameHeight) {

        m_id = ++m_bikeCount;           // static instance # is unique id
        m_color = color;                // predominant frame color
        m_frameHeight = frameHeight;    // frame height in inches
        m_available = true;             // initially available to rent
    }

    //--------------------------------------------------------------------------
    // manage description
    //--------------------------------------------------------------------------
    void setDescription(const string&& desc) { m_description = desc;  }

    //--------------------------------------------------------------------------
    // display bike info #TODO repolace this function with << operator overload
    //--------------------------------------------------------------------------
    void print() {
        cout << m_color << ' ' << m_frameHeight << "\" frame, "
            << m_description << '\n';
    }

    //--------------------------------------------------------------------------
    // rent bike
    //--------------------------------------------------------------------------
    bool rentBike() {
        if (!m_available)
            return false;

        m_available = false;
        return true;
    }

    //--------------------------------------------------------------------------
    // return bike
    //--------------------------------------------------------------------------
    void returnBike() { m_available = false; }

    //--------------------------------------------------------------------------
    // return rental fee 
    //--------------------------------------------------------------------------
    float getRentalFee(int hours) { return (float) m_hourlyRate * hours; }

    // overload comparison operator != 
    bool operator!=(CommunityBike& compareBike) const {
        return (this->m_frameHeight && this->m_color.compare(compareBike.m_color));
    }

    friend ostream& operator<<(ostream& os, CommunityBike* pB);

};

// overload strream insertion operator <<
ostream& operator<<(ostream& os, CommunityBike* pB) {
    os << pB->m_color << ' ' << pB->m_frameHeight << "\" frame\n";
    return os;
}

//--------------------------------------------------------------------------
// allocate memory for and initialize static member vars outside the class
//--------------------------------------------------------------------------
int CommunityBike::m_bikeCount = 0;     // uniquely identifies a bike
int CommunityBike::m_hourlyRate = 5;    // cost to rent any bike for 1 hour

#endif // COMMUNITYBIKE_H