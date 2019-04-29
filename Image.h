
#ifndef IMAGE_H
#define IMAGE_H
#include <memory>
#include <iostream>
#include <string>
#include "Array.h"

namespace MCHWIL006{
    class Image
    {
    private: // private members
        int width, height; // width and height of image stack
        std::unique_ptr<unsigned char []>data; // data for each slice, in order
    public: // public members
        //IO OVERLOADS

        friend std::ostream & operator <<(std::ostream & outline,const Image& other);
        friend std::istream & operator >>(std::istream & inlin,Image& other);

        //BIG 6 FOR THE IMAGE class

        Image(int width,int height,unsigned char* array); // default constructor - define in .cpp
        Image();
        ~Image(); // destructor - define in .cpp file
        // populate the object with images in stack and
        //set member variables define in .cpp

        //constructors of the Image class
        Image (const Image & other); //copy constructer
        Image (Image && other); //move constructer
        Image& operator=(const Image & other); //Copy Assignment Operators
        Image& operator=(Image && other); //Move Assignment Operators
        Image load(std::string filename);
        int reflect(int M, int x);
        // compute difference map and write out; define in .cpp
        void save(std::string filename);
        // extract slice sliceId and write to output - define in .cpp

        //Image operators
        Image & operator+(const Image & rhs);
        Image & operator-(const Image & rhs);
        Image & operator!();
        Image & operator/(const Image & rhs);
        Image & operator*(int f);
        Image operator%(Matrix h);

        class Iterator{

        private:
            unsigned char *ptr;
            Iterator(u_char *p) : ptr(p) {}
        public:
          //Iterator(unsigned char* p):ptr(p) {}
         friend class Image;

        Iterator & operator=(Iterator & other){
              if(this!=&other){
                ptr = other.ptr;
              }
              return *this;
            }
            Iterator & operator++(){

                ptr++;
                return *this;
            }

            Iterator & operator--(){
                --ptr;
                return *this;
            }
            unsigned char& operator*(){

                return *ptr;
            }

            bool operator!=(const Iterator& other){
                return (ptr!=other.ptr);
            }

        };
        Iterator begin(void) const{
          return (data.get());
        }
        Iterator end(void) const{
          return (data.get()+(width*height));
        }
    };
}
#endif
