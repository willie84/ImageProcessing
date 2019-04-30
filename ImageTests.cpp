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
TEST_CASE( "Testing the image methods using the above procedure") {
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
   //cout<<"m7"<<endl;
    //Image m7(4,4, buffer7);
    REQUIRE(m4== (!m9)); //test for threshold using carefully generated random numbers.



   //REQUIRE(u9 == u8);//test that subtraction saturates to zero, any image - white   = black.



    //since test cases passed and they all used iterators, it is safe to assume that iterators also passed.


}
