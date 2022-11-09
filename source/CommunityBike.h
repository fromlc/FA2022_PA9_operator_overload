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
// CommunityBike
//------------------------------------------------------------------------------
class CommunityBike {
private:
    static int ms_bikeCount;    // number of bike instances created
    static int ms_hourlyRate;   // all bikes cost the same to rent per hour

    int m_id;                   // this bike's unique instance number
    int m_frameHeight;          // frame height in inches
    bool m_available;           // true if available for rent, false otherwise

    string m_color;             // predominant frame color
    string m_description;       // more info on this bike

    string m_renterName;        // person who rented this bike

    // allow operator<< function access to private data
    friend ostream& operator<<(ostream& os, CommunityBike* pB);

public:
    //--------------------------------------------------------------------------
    // constructor
    //--------------------------------------------------------------------------
    CommunityBike(const string& color, int frameHeight, int hourlyRate = 5) {

        m_id = ++ms_bikeCount;          // first bike m_id is 1
        m_color = color;                // predominant frame color
        m_frameHeight = frameHeight;    // frame height in inches
        m_available = true;             // initially available to rent
        hourlyRate = ms_hourlyRate;     // all bikes cost the same to rent
    }

    //--------------------------------------------------------------------------
    // manage description
    //--------------------------------------------------------------------------
    void setDescription(const string& desc) { m_description = desc;  }
    string& getDescription() { return m_description;  }

    //--------------------------------------------------------------------------
    // manage bike rental
    //--------------------------------------------------------------------------
    bool rentBike(const string& renterName) {
        if (!m_available)
            return false;

        m_renterName = renterName;
        m_available = false;
        return true;
    }

    //--------------------------------------------------------------------------
    const string& getRenterName() const { return m_renterName; }

    //--------------------------------------------------------------------------
    // return bike
    //--------------------------------------------------------------------------
    void returnBike() { m_available = false; }

    //--------------------------------------------------------------------------
    // return rental fee 
    //--------------------------------------------------------------------------
    float getRentalFee(float hours) { return ((float) ms_hourlyRate) * hours; }

    //--------------------------------------------------------------------------
    // overload comparison operator ==
    //--------------------------------------------------------------------------
    bool operator==(CommunityBike& compareBike) const {
        return (this->m_frameHeight == compareBike.m_frameHeight &&
                !this->m_color.compare(compareBike.m_color));
    }

    //--------------------------------------------------------------------------
    // overload comparison operator != 
    //--------------------------------------------------------------------------
    bool operator!=(CommunityBike& compareBike) const {
        return (this->m_frameHeight != compareBike.m_frameHeight ||
                this->m_color.compare(compareBike.m_color));
    }
};

//------------------------------------------------------------------------------
// overload stream insertion operator <<
// 
// static keyword generates one copy of this function for all compilation units
//------------------------------------------------------------------------------
static ostream& operator<<(ostream& os, CommunityBike* pB) {
    os << pB->m_color << ' ' << pB->m_frameHeight << "\" frame ";
    return os;
}
#endif // COMMUNITYBIKE_H