#include <unordered_map>
#include "Image.h"
#include "Array.h"
#include <stdlib.h>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace MCHWIL006;

/*Testing is neccessary for programmer to test their uses cases.
• We need to tests the six member functions of the image and see if they are doing okay
. This has been done via creating image and checking if they are equals to each other.
• All the operators need to be checked and see if they are working properly.
• Addition,subtraction,inverting,filtering,thresholding and masking
• The testing procedure is as follows*/

/* *
1. Created Three images namely M1, U1 and U3. This was done by inserting dummy data of the images.
2. create an image mask M1 (via thresholding)
2. create an inverted mask of M1 called M2 (by inverting M1)
3. use M1 and an Image U1 to create a masked image
4. use M2 and an Image U2 to create a second masked image
5. add the two masked images together to create a new image with pieces
of both U1 and U2!

by checking using the REQUIRE from CATCH_CONFIG_MAIN then we will fully understand that our methods
works fine if these methods here passes all the tests.

*/
/////////TASK 1 FOR TESTING COPY CONSTRUCTOR AND THRESHOLD OPERATOR//////
TEST_CASE( "Testing the image methods copy constructor+default+invert+Threshold operator") {
   //generate a random image data -usigned array of characters
   //size = width*height
   unsigned char* Imagedata = new unsigned char[60];
   //unsigned char* Imagedata2 = new unsigned char[60];
   for(int i = 0; i< 30; i++){
        Imagedata[i] = 70;
       //this will be zero when threshold with an f of 80
   }
   for(int i = 0; i< 30; i++){
       Imagedata[i] =90 ;

      //this should be 255 when we threshold with an f of 80
   }
    Image m(10,6,Imagedata);

   //Let us test both Assignment operator and threshold operator
    Image m4 = m*80; //in this image we know that any value below 80 is zero and any value above is 255
 //Image m4 is an image mask now via thresholding by 80

 //Create an image mask M2 by creating an invert of m4



    unsigned char* Imagedata2 = new unsigned char[60];
    for(int i = 0; i< 30; i++){
         Imagedata2[i] = 90;
        //this will be zero when threshold with an f of 80
    }
    for(int i = 0; i< 30; i++){
        Imagedata2[i] =70 ;

       //this should be 255 when we threshold with an f of 80
    }

     Image m3(10,6,Imagedata2);

    Image m9 = m3*80;

    REQUIRE(m4== (!m9)); //
}

///Task 2 for testing image methods adding+mask operators....
TEST_CASE( "Testing the image methods adding+mask operators") {
   //generate a random image data -usigned array of characters
   //size = width*height
   unsigned char* Imagedata = new unsigned char[60];
   //unsigned char* Imagedata2 = new unsigned char[60];
   for(int i = 0; i< 30; i++){
        Imagedata[i] = 70;
       //this will be zero when threshold with an f of 80
   }
   for(int i = 0; i< 30; i++){
       Imagedata[i] =90 ;

      //this should be 255 when we threshold with an f of 80
   }
    Image m(10,6,Imagedata);

   //Let us test both Assignment operator and threshold operator
    Image m4 = m*80; //in this image we know that any value below 80 is zero and any value above is 255
 //Image m4 is an image mask now via thresholding by 80

 //Create an image mask M2 by creating an invert of m4



    unsigned char* Imagedata2 = new unsigned char[60];
    for(int i = 0; i< 30; i++){
         Imagedata2[i] = 90;
        //this will be zero when threshold with an f of 80
    }
    for(int i = 0; i< 30; i++){
        Imagedata2[i] =70 ;

       //this should be 255 when we threshold with an f of 80
    }

     Image m3(10,6,Imagedata2);

    Image m9 = m3*80;

    REQUIRE(m4== (!m9)); //

// We have two images where one is the invert of the other.

//Create two images now and use each of the invert and mask them.

unsigned char* ImagedataU1 = new unsigned char[60];
for(int i = 0; i< 30; i++){
     ImagedataU1[i] =30;

}
for(int i = 0; i< 30; i++){
    ImagedataU1[i] =70 ;


}

Image U1(10,6,ImagedataU1);
Image p3=m/U1;

unsigned char* ImagedataU2 = new unsigned char[60];
for(int i = 0; i< 30; i++){
     ImagedataU2[i] =30;

}
for(int i = 0; i< 30; i++){
    ImagedataU2[i] =70 ;


}

Image U2(10,6,ImagedataU2);

Image p=m3/U2;

Image added=p3+p;// When these two are added they should give ma the original image i had before.

REQUIRE(added==(m));


}


/////////TASK 3 FOR TESTING move Assignment+Move constructor+substract operator//////
TEST_CASE( "Testing the image methods move Assignment+Move constructor+substract operator") {
   //generate a random image data -usigned array of characters
   //size = width*height
   unsigned char* Imagedatasubstract1 = new unsigned char[60];
   //unsigned char* Imagedata2 = new unsigned char[60];
   for(int i = 0; i< 60; i++){
        Imagedatasubstract1[i] = 1;
       //this will be zero when threshold with an f of 80
   }


    unsigned char* Imagedatasubstract2 = new unsigned char[60];
    for(int i = 0; i< 60; i++){
         Imagedatasubstract2[i] = 0;
        //this will be zero when threshold with an f of 80
    }

  //meaning if we minus Image with Imagedatasubstract1 with Imagedatasubstract2 we will get Imagedatasubstract1
   Image tree(10,6,Imagedatasubstract1);
    REQUIRE(tree==tree-Image(10,6,Imagedatasubstract2)); //This method call the move constructor+Move assignment
}
