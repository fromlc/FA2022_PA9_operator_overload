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
    // manage bike info
    //--------------------------------------------------------------------------
    int getID() const { return m_id; }

    //--------------------------------------------------------------------------
    void setDescription(const string& desc) { m_description = desc;  }
    string& getDescription() { return m_description; }

    //--------------------------------------------------------------------------
    int getFrameHeight() const { return m_frameHeight; }

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
    bool isAvailable() const { return m_available; }

    //--------------------------------------------------------------------------
    void setRenterName(const string& renterName) { m_renterName = renterName; }
    const string& getRenterName() const { return m_renterName; }

    //--------------------------------------------------------------------------
    // return bike
    //--------------------------------------------------------------------------
    //void returnBike() { m_available = false; }    // nobody found this bug!
    void returnBike() { m_available = true; }

    //--------------------------------------------------------------------------
    // return rental fee 
    //--------------------------------------------------------------------------
    float getRentalFee(float hours) { return ((float) ms_hourlyRate) * hours; }

    //--------------------------------------------------------------------------
    // overload comparison operator ==
    // 
    // returns true/false result of (this bike == compareBike)
    //--------------------------------------------------------------------------
    bool operator==(CommunityBike& compareBike) const {
        return (this->m_frameHeight == compareBike.m_frameHeight &&
                !this->m_color.compare(compareBike.m_color));
    }

    //--------------------------------------------------------------------------
    // overload comparison operator != 
    // 
    // returns true/false result of (this bike != compareBike)
    //--------------------------------------------------------------------------
    bool operator!=(CommunityBike& compareBike) const {
        return (this->m_frameHeight != compareBike.m_frameHeight ||
                this->m_color.compare(compareBike.m_color));
    }

    //--------------------------------------------------------------------------
    // overload comparison operator <=
    // 
    // returns true/false result of (this bike <= compareBike)
    //--------------------------------------------------------------------------
    bool operator<=(CommunityBike& compareBike) const {
        return (this->m_frameHeight <= compareBike.m_frameHeight);
    }

};

//------------------------------------------------------------------------------
// overload stream insertion operator << with a static function
// 
// static keyword generates one copy of this function for all compilation units
//------------------------------------------------------------------------------
static ostream& operator<<(ostream& os, CommunityBike* pBike) {
    os << pBike->m_color << ' ' << pBike->m_frameHeight << "\" frame";
    return os;
}
#endif // COMMUNITYBIKE_H