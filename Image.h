
#ifndef IMAGE_H
#define IMAGE_H
#include <memory>
#include <iostream>
#include <string>

namespace MCHWIL006{
    class Image
    {
    private: // private members
        int width, height; // width and height of image stack
        std::unique_ptr<unsigned char []>data; // data for each slice, in order
    public: // public members

    //BIG 6 FOR THE IMAGE class

        Image(); // default constructor - define in .cpp
        ~Image(); // destructor - define in .cpp file
        // populate the object with images in stack and
        //set member variables define in .cpp

        //constructors of the Image class
        Image (const Image & other); //copy constructer
        Image (image && other); //move constructer
        Image & operator=(const image & other); //Copy Assignment Operators
        Image & operator=(image && other); //Move Assignment Operators

        bool load(std::string filename);
        // compute difference map and write out; define in .cpp
        void save(std::string filename);
        // extract slice sliceId and write to output - define in .cpp

//Image operators
       Image & operator+(const Image & rhs);
       Image & operator-(const Image & rhs);
       Image & operator!();
       Image & operator/(const Image & rhs);
       Image & operator*(int f);

        class iterator{
        private:
          unsigned char *ptr;
           friend class Image;
          iterator(u_char *p);
        public:
          iterator(const iterator &rhs);
          ~iterator();
          iterator & operator=(const iterator & rhs);
          iterator & operator++(const iterator & rhs);
          iterator & operator--(const iterator & rhs);
          iterator & operator*(const iterator & rhs);

        };

        Image::iterator begin(void) const;
        Image::iterator end(void) const;

    };
}
#endif
