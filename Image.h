
#ifndef IMAGE_H
#define IMAGE_H
#include <memory>
#include <iostream>
#include <string>
using namespace std;
namespace MCHWIL006{
    class Image
    {
    private: // private members
        int width, height; // width and height of image stack
        std::unique_ptr<unsigned char []>data; // data for each slice, in order
    public: // public members
        //IO OVERLOADS

        friend ostream& operator<<(ostream& outline,const Image& other);
        friend istream& operator >>(istream& inlin,Image& other);

        //BIG 6 FOR THE IMAGE class

        Image(int width,int height,unsigned char* array); // default constructor - define in .cpp
        Image(std::string pgdmfile);
        ~Image(); // destructor - define in .cpp file
        // populate the object with images in stack and
        //set member variables define in .cpp

        //constructors of the Image class
        Image (const Image & other); //copy constructer
        Image (Image && other); //move constructer
        Image& operator=(const Image & other); //Copy Assignment Operators
        Image& operator=(Image && other); //Move Assignment Operators

        void load(std::string filename);
        // compute difference map and write out; define in .cpp
        void save(std::string filename);
        // extract slice sliceId and write to output - define in .cpp

        //Image operators
        Image & operator+(const Image & rhs);
        Image & operator-(const Image & rhs);
        Image & operator!();
        Image & operator/(const Image & rhs);
        Image & operator*(int f);

        class Iterator{
        private:
            unsigned char *ptr;
            friend class Image;
            Iterator(u_char *p);
        public:

            Iterator(const Iterator &rhs);
            ~Iterator();

            Iterator (Iterator && other); //move constructer
            Iterator & operator=(const Iterator& other); //Copy Assignment Operators
            Iterator & operator=(Iterator && other); //Move Assignment Operators


            Iterator& operator++();
            Iterator& operator--();
            unsigned char& operator*();
            bool operator!=(const Iterator& other);

        };

        Image::Iterator begin(void) const;
        Image::Iterator end(void) const;

    };
}
#endif
