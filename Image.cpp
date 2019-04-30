//
//  Image.cpp
//  ImageProcessing
//
//  Created by Willie Macharia on 2019/04/18.
//  Copyright © 2019 Willie Macharia. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Image.h"
#include "Array.h"
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

namespace MCHWIL006{

    Image::Image(int wid,int hei,unsigned char* arrayz):width(wid),height(hei){
        data.reset(arrayz); //Here the unique pointer is reassigned

    }

    Image::Image(){
      data=move(nullptr);width=height=0;
      //this=&load(inputfile);
    }

    Image::~Image(){
     //cout<<"This is a destructor called"<<endl;
      data=nullptr;width=height=0;}


    Image Image::load(std::string inputfile){
      ifstream stream(inputfile , ios::in | ios::binary);
      //Image img;
      stream>>*this;
      return *this;
    }

    //Copying the constructor things
    Image::Image(const Image &other):width(other.width),height(other.height){

        unsigned char* space=new unsigned char[width*height];
        int spe=width*height;
        for(int m=0;m<spe;m++){
            space[m]=other.data[m];
        }

        data.reset(space);


    }
    //Move constructor
    Image::Image(Image && other):width(other.width),height(other.height){

        data=move(other.data);
        other.width=other.height=0;
    }

    //Copy Assignment Operator

    Image& Image::operator=(const Image & other){

        if(this==&other){return *this;}

        if(data!=nullptr){data=nullptr;}

        width=other.width;
        height=other.height;

        unsigned char* space=new unsigned char[width*height];
        int spe=width*height;
        for(int m=0;m<spe;m++){
            space[m]=other.data[m];
        }

        data.reset(space);

        return *this;

    }
    //Move assignment operator
    Image& Image::operator=(Image && other){

        if(this==&other){return *this;}

        if(data!=nullptr){data=nullptr;}

        width=other.width;
        height=other.height;
        data=move(other.data);
        other.width=other.height=0;

        return *this;

    }

    void Image::save(std::string out){
      ofstream stream(out, ios::out | ios::binary | ios::app);
      stream << (*this);
      cout<<"Your result image have been saved at "<<out<<endl;
  }




    Image& Image::operator+(const Image & rhs){
      cout<<"Adding"<<endl;
        if(rhs.height==height && rhs.width==width){
            Image::Iterator beg=this->begin();
            Image::Iterator end=this->end();
            Image::Iterator in=rhs.begin(),inend=rhs.end();
          //cout<<*this<<endl;
        //  cout<<rhs<<endl;
            while(beg !=end){
              int sum=*beg+*in;


                if(sum>255){
                    *beg=255;
                }
                else{*beg=sum;}
                ++beg;
                ++in;
            }
        }
  cout<<"Addingttttttt"<<endl;
    //cout<<*this<<endl;
    //std::cout << "buda mjamaa" << '\n';
        return *this;
    }

    Image& Image::operator-(const Image & rhs){
        if(rhs.height==height && rhs.width==width){
            Image::Iterator beg = this->begin();
            Image::Iterator end = this->end();
            Image::Iterator in=rhs.begin(),inend=rhs.end();

            while(beg !=end){
              int diff=*beg-*in;


                if(diff<0){
                    *beg=0;
                }
                else{*beg=diff;}
                ++beg;
                ++in;
            }
        }
        return *this;

    }

    Image& Image::operator!(){


            Image::Iterator beg=this->begin();
            Image::Iterator end=this->end();
        while(beg !=end){

            *beg=255-*beg;
            ++beg;
        }


        return *this;
    }

    Image& Image::operator*(int f){
        Image::Iterator beg=this->begin();
        Image::Iterator end=this->end();
        while(beg !=end){

            if(*beg >f){*beg=255;}

            else{*beg=0;}
            ++beg;
        }


        return *this;
    }

    Image& Image::operator/(const Image & rhs){
        if(rhs.width==width && rhs.height==height){
            Image::Iterator beg=this->begin();
            Image::Iterator end=this->end();
            Image::Iterator in=rhs.begin(),inend=rhs.end();

            while(beg !=end){

                if(*in==255){
                  *beg=*beg; }
                  else{
                    *beg=0; }

                ++beg;
                ++in;
            }
        }
        return *this;
    }


ostream &operator << (ostream& pgdm, const Image& other){

    if(!pgdm){
      cout<<"unable to open file"<<endl;
    }
 else{
            pgdm<<"P5"<<endl;
            pgdm<<"# CREATOR: GIMP PNM Filter Version 1.1"<<endl;
            pgdm<<other.height<<" "<<other.width <<endl;
            pgdm<<255<<endl;
            //int64_t arraysize=other.height*other.width;
            //other.data.reset(new unsigned char[arraysize]);
            //other.data.reset(new unsigned char*(other.width*other.height));
            pgdm.write((char*)other.data.get(),(other.height*other.width));
          cout<<"saved"<<endl;
    }
return pgdm;
}
istream & operator >>(istream& pgdm,Image& other){
        int wede,hete;
        string toRead;

        if(!pgdm){
          cout<<"unable to open file"<<endl;
        }
        if(pgdm){
            getline(pgdm, toRead);
            cout <<"Reading the first few lines to get the height,width and the highest number"<<endl;
            while(toRead.compare("255")!=0){
                if(toRead[0]!='#'){
                    if(toRead.compare("P5")!=0){
                        //cout<<toRead<<endl;
                        istringstream stream (toRead);
                        stream>>hete;
                        stream>>wede;
                        other.width=wede;
                        other.height=hete;
                    }
                }

                getline(pgdm, toRead);
                //cout<<toRead<<endl;
            }
            cout<<"Height "<<other.height<<" The width is "<<other.width<<endl;
            int64_t arraysize=other.height*other.width;
            //cout<<arraysize<<endl;
            other.data.reset(new unsigned char[arraysize]);
            //skipws(pgdm);

            pgdm.read((char*)other.data.get(),arraysize);

        }
        return pgdm;
    }

Image Image::operator%(Textdata h){

  Image::Iterator beg=this->begin();
  Image::Iterator end=this->end();

  Image::Iterator beg2=this->begin();
  Image::Iterator end2=this->end();
  float yeret[height][width];

  for(int m0=0;m0<height;m0++){
    for(int m1=0;m1<width;m1++){
      yeret[m0][m1]=(float)*beg2;
      //scout<<yeret[m0][m1]<<endl;
      ++beg2;
    }
  }
  //std::cout<<"Height is "<<height<<endl;
  for(int p=0;p<height;p++){
    for(int x=0;x<width;x++){
     int xcentre=x;//put the image at the centre
     //std::cout<<"ycentre"<<xcentre<<endl;

     int ycentre=p;//put the image at the centre
     //std::cout<<"ycentre"<<ycentre<<endl;

     int ret=h.N/2;
     //std::cout<<"ycentre"<<ycentre<<endl;

     int were=0;
     int were1=0;

     float jutre[50][50];

     for(int a=ycentre+ret;a>=ycentre-ret;a--){
       //std::cout<<"Height is were1"<<height<<endl;

       //cout<<a<<endl;
       //cout<<"Am here"<<endl;

       for(int b=xcentre-ret;b<=xcentre+ret;b++){

         //cout<<b<<endl;


        //if(a<0 || a>height){
        int we=0; int er=0;
         we=reflect(height,a);
         //cout<<a<<endl;
      // }

       //if(b<0 || b>width){
         er=reflect(width,b);
       jutre[were][were1]=yeret[we][er];
       //cout<<"a "<<a<<"b "<<b<<endl;
       //cout<<jutre[were][were1]<<endl;
       were1+=1;
       }
       //cout<<were<<endl;
       were+=1;
     }
     float weightedsum=0.0;
    for(int b=0;b<h.N;b++){
      for(int b1=0;b1<h.N;b1++){
        //cout<<jutre[b][b1]<<" "<<h.data[b][b1]<<endl;
        weightedsum+=jutre[b][b1]*h.data[b][b1];
      }
    }
    //cout<<p<<endl;
    if(weightedsum>255){
    *beg=255;}

    else{*beg=weightedsum;}
    //cout<<sum<<endl;
    ++beg;
    //cout<<"sumqawaqawe"<<endl;
  }

}
//std::cout<<"Am here"<<endl;
 //h.data[h.data.size()/2][h.data.size()/2]

 return *this;

}

int Image::reflect(int M, int x) //This mehod is for reflecting values of pixel off the grid
{
    if(x<0)
    {
        return ((x)*-1)- 1;
    }
    if(x >=M)
    {
        return (2*M )- (x)- 1;
    }
   return x;
}
bool Image::operator==(const Image & other) //This mehod is for reflecting values of pixel off the grid
{
    if(height==other.height && width==other.width)
    {    int k=1;
        for(int y=0;y<width*height;y++){
          if(this->data[y]!=other.data[y]){
            k*=0;
            break;
          }

        }
        if(k==1){return true;}
        else{return false;}
    }
  return false;
}


}
