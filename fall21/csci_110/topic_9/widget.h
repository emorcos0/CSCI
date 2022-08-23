#include <string>
#include <cstddef>
#include <ostream>

#ifndef WIDGET_H
#define WIDGET_H

struct Widget
{
    friend std::ostream& operator<<(std::ostream&, const Widget&);

    /** Constructor
     * Calls specialized constructor with serial = 0 and lot = ""
    */
    Widget() : Widget(0, "") {}

    /** Constructor
     * @param serialNumber: a non-negative integer valie tat represents the unique ID of the part
     * @param lotNumber: a string that represents the manufacturing "lot" of the part
    */
    Widget(size_t serialNumber, std::string lotNumber) : serialNumber{serialNumber}, lotNumber{lotNumber} {}

    /** Assignment operator overload
     * @param other:  the instance to be copied
    */
    void operator=(const Widget& other) { serialNumber = other.serialNumber; lotNumber = other.lotNumber; }

    /** Equality operator overload
     * @param other  the instance to be compared
     * @return: returns true if the serial number in lot number in both widgets are equal (composite keys)
     *          returns false otherwise
    */
    bool operator==(const Widget& other) const { return serialNumber == other.serialNumber && lotNumber == other.lotNumber; }

    /** Inequality operator overload
     * @return: returns true if the serial number in lot number in both widgets are not equal (composite keys)
     *          returns false otherwise
    */
    bool operator!=(const Widget& other) const { return !(*this == other); }


    bool operator>(const Widget& other) const { return serialNumber > other.serialNumber; }
    bool operator<(const Widget& other) const { return serialNumber < other.serialNumber; }
    bool operator>=(const Widget& other) const { return serialNumber >= other.serialNumber; }
    bool operator<=(const Widget& other) const { return serialNumber <= other.serialNumber; }

    size_t serialNumber;
    std::string lotNumber;
};


/** stream insertion friend function
 * @param out: The stream object into which to insert a formated representation of a Widget instance
 * @param w: A Widget instance
 * @return: The ostream object, out. 
*/ 
std::ostream& operator<<(std::ostream& out, const Widget& w)
{
    return (out << "Serial#: " << w.serialNumber << " - Lot#: " << w.lotNumber); 
}

#endif