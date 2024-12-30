#include "Fraction.h"

Fraction::Fraction( long numerator, long denominator)
{

    //throw an exception if denominator = 0

    if(denominator == 0)
    {
        throw std::logic_error("Denominator can not be equal to zero!");
    }

    this->numerator= numerator;
    this->denominator = denominator;

    this->reduce();
}


/*
 * The reduce method reduces the fraction and simplifies
 * the sign of the fraction resulting in only the numerator
 * being positive or negative.
 */
void Fraction::reduce() {
    // store if the fraction is positive or negative.
    bool isNegative;
    if ((denominator < 0 && numerator < 0) || (denominator > 0 && numerator > 0)) {
        isNegative = false;
    } else {
        isNegative = true;
    }

    // reset the numerator and denominator to positive
    numerator = abs(numerator);
    denominator = abs(denominator);

    // get the greatest common denominator
    long greatest_common_denominator = gcd(numerator, denominator);

    // reduce the fraction
    numerator = numerator / greatest_common_denominator;
    denominator = denominator / greatest_common_denominator;

    // set the numerator to negative if the fraction was negative.
    if (isNegative) numerator = numerator * -1;

}

/*
 * The gcd method returns the greatest common denominator of two numbers.
 * The method uses a beautiful, compact, little recursive algorithm that
 * we'll discuss more when we get to recursion.
 */
long Fraction::gcd(long a, long b) {
    if (a == 0) {return b;}
    return gcd(b % a, a);
}



//setters
void Fraction:: setNumerator(long numerator){

    this->numerator = numerator;

    this->reduce();

}
void Fraction:: setDenominator(long denominator){

    if(denominator == 0)
    {
        throw std::logic_error("Denominator can not be equal to zero!");
    }

    this->denominator = denominator;

    this->reduce();


}


//getters
long Fraction:: getNumerator() const{

    return numerator;

}
long Fraction:: getDenominator() const{
    return denominator;
}


bool Fraction::operator==(Fraction const &rhs) const{
    return ((this->numerator*rhs.denominator) == (this->denominator*rhs.numerator));

}

bool Fraction::operator<(Fraction const &rhs) const{
    return ((this->numerator*rhs.denominator) < (this->denominator*rhs.numerator));
}


bool Fraction::operator!=(Fraction const &rhs) const{
    return !((this->numerator*rhs.denominator) == (this->denominator*rhs.numerator));
}


bool Fraction::operator>(Fraction const &rhs) const{
    return ((this->numerator*rhs.denominator) > (this->denominator*rhs.numerator));
}

bool Fraction::operator>=(Fraction const &rhs) const{
    return (((this->numerator*rhs.denominator) > (this->denominator*rhs.numerator))||
    (this->numerator*rhs.denominator) == (this->denominator*rhs.numerator)) ;

}
bool Fraction::operator<=(Fraction const &rhs) const{
    return (((this->numerator*rhs.denominator) < (this->denominator*rhs.numerator))||
            (this->numerator*rhs.denominator) == (this->denominator*rhs.numerator)) ;
}

const Fraction Fraction::operator=(Fraction const &rhs) {

    if (this != &rhs)
    {
       numerator = rhs.numerator;
       denominator = rhs.denominator;
    }
    return *this;

}


Fraction Fraction::operator++(){

    numerator++;
    return *this;

}
Fraction Fraction:: operator++(int dummy){
    Fraction temp(numerator, denominator);

    numerator++;

    return temp;

}


Fraction Fraction:: operator--(){
    numerator--;

    return *this;
}
Fraction Fraction::operator--(int dummy){
    Fraction temp(numerator, denominator);
    numerator--;

    return temp;
}


Fraction Fraction::operator*(int number){

    numerator*= number;

    reduce();

    return (Fraction(numerator, denominator));
}

Fraction Fraction::operator*(Fraction const &rhs){

    return (Fraction(numerator*rhs.numerator, denominator*rhs.denominator));
}

Fraction Fraction::operator/(int number){
   denominator*= number;

    return (Fraction(numerator, denominator));
}

Fraction Fraction::operator/(Fraction const &rhs){
    numerator*= rhs.denominator;

    denominator*= rhs.numerator;
    reduce();

    return (Fraction(numerator, denominator));

}



//Addition and Subtraction
Fraction Fraction:: operator+(long const & number){

    int newNumerator = (this->numerator)+(number* this->denominator);

    int newDenominator= this->denominator;


    Fraction temp(newNumerator, newDenominator);

    temp.reduce();

    return temp;
}

Fraction Fraction:: operator-(long const & number){
    int newNumerator = (this->numerator)-(number* this->denominator);

    int newDenominator= this->denominator;


    Fraction temp(newNumerator, newDenominator);

    temp.reduce();


    return temp;
}

//Addition and Subtraction with another fraction

Fraction Fraction::operator+(Fraction const &rhs){
    int newNumerator = (this->numerator*rhs.denominator)+(this->denominator*rhs.numerator);

    int newDenominator= this->denominator*rhs.denominator;


    Fraction temp(newNumerator, newDenominator);

    temp.reduce();


    return temp;

}

Fraction Fraction::operator-(Fraction const &rhs){
    int newNumerator = (this->numerator*rhs.denominator)-(this->denominator*rhs.numerator);

    int newDenominator= this->denominator*rhs.denominator;


    Fraction temp(newNumerator, newDenominator);

    temp.reduce();


    return temp;
}

std::string Fraction:: toString() const {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}
// Overloading << for Fraction object
std::ostream& operator<<(std::ostream & out, const Fraction& fraction) {

    out << fraction.toString();
    return out;
}

// Overloading << for Fraction pointer
std::ostream& operator<<(std::ostream& out, const Fraction* fractionPtr) {
    if (fractionPtr) {
        out << fractionPtr->toString();
    }

    return out;
}
