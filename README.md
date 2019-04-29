This assignment 4 is focused on creating an image cointaner and a specialised Image iterator.
The assignment also focuses on the concept of overloading operators such as ("=","%","+","-","*").

The files that are extensively used are as follows:
    Image.h which is the header file of the image. This file cointains also the iterator class.
    Image.cpp which is the file that cointains the image operations and specifications.
    Array.h is a class that cointains the filtering data in an N*N float array
    The catch.cpp file is used to enable the unit testing of the methods and classes.

    The makeFile is used for automating the process of testing the program. After compiling the programs;
    an executable called Imageops(Image operations) is produced.


 The images that are supported here are of type .pgm which are grayscale images with a max of 255 pixels.

To invoke/Test the code; follow the following procedures.

 1. To add two images;
     ./Imageops -a Image1 Image2 Addresult.pgm  //Result is saved in addresult.pgm file.

 2. To substract two images;
    ./Imageops -s Image1 Image2 subresult.pgm  //Result is saved in subresult.pgm file.


 3. To INVERT one images;
     ./Imageops -i Image1  invertresult.pgm  //Result is saved in invertresult.pgm file.


 4. To mask one image with another;
      ./Imageops -l Image1 MaskImage  mask_result.pgm  //Result is saved in mask_result.pgm file.

 5. To threshold one image with an integer;
      ./Imageops -t Image1 int f threshold_result.pgm  //Result is saved in threshold_result.pgm file.

 6. To threshold filter image with a filter;
    ./Imageops -f Image1 filter filter_result.pgm  //Result is saved in filter_result.pgm file.



These operations have been supported by overloading the operators(+,-,*,%,/,!)

The Test.cpp class is used to unit test the code. Run it to see if the code passes all the tests. 
