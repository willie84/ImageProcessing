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
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

namespace MCHWIL006{

    Image::Image(int wid,int hei,unsigned char* arrayz):width(wid),height(hei){
        data.reset(arrayz); //Here the unique pointer is reassigned

    }

    Image::Image(std::string rete){
        load(rete);
    }

    Image::~Image(){
     cout<<"This is a destructor called"<<endl;
      data=nullptr;width=height=0;}
    void Image::load(std::string sede){
        int wede,hete;

        ifstream pgdm(sede,ios::in |ios::binary);
        string toRead;

        if(pgdm.is_open()){
        getline(pgdm, toRead);

        cout <<"Reading the first few lines to get the height,width and the highest number";

        while(toRead.compare("255")!=0){
            if(toRead[0]!='#'){
                if(toRead.compare("P5")!=0){
                    cout<<toRead<<endl;
                    istringstream stream (toRead);

                    stream>>hete;
                    stream>>wede;

                    width=wede;
                    height=hete;
                }
            }

            getline(pgdm, toRead);

            cout<<toRead<<endl;
        }

        cout<<"Height "<<height<<" The width is "<<width<<endl;
        int64_t arraysize=height*width;

        cout<<arraysize;

        data.reset(new unsigned char[arraysize]);
        skipws(pgdm);

        pgdm.read((char*)&data[0], arraysize);

        pgdm.close();
        }

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


    void Image::save(std::string sede){

        string dataFile = sede + ".pgm";
        cout<<"A file called "<<dataFile<<"Created";
        ofstream pgdm(sede,ios::in |ios::binary);
        string toRead;

        if(pgdm.is_open()){
            pgdm<<"P5"<<endl;
            pgdm<<"# CREATOR: GIMP PNM Filter Version 1.1"<<endl;
            pgdm<<height<<" "<<width <<endl;

            for(int p=0;p<height*width;p+=width){

                for (int a=0;a<width;a++){
                    pgdm<<data[p];
                    p+=1;
                }

                pgdm.close();
            }


                cout<<toRead<<endl;
            }

    }

    Image::Iterator Image::begin(void) const{
        return Iterator(&(data.get()[0]));
    }

    Image::Iterator Image::end(void) const{
        int m=width*height;
        return Iterator(&(data.get()[m]));
    }

    Image& Image::operator+(const Image & rhs){

        if(rhs.height==width && rhs.height==height){
            Image::Iterator beg=this->begin();
            Image::Iterator end=this->end();
            Image::Iterator in=rhs.begin(),inend=rhs.end();

            while(beg !=end){
                int sum=*beg+*in;

                if(sum>255){
                    sum=255;
                }
                *beg=sum;
                ++beg;
                ++in;
            }
        }
        return *this;
    }

    Image& Image::operator-(const Image & rhs){
        if(rhs.height==width && rhs.height==height){
            Image::Iterator beg=this->begin();
            Image::Iterator end=this->end();
            Image::Iterator in=rhs.begin(),inend=rhs.end();

            while(beg !=end){
                int diff=*beg-*in;

                if(diff<0){
                    diff=0;
                }
                *beg=diff;
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
        if(rhs.height==width && rhs.height==height){
            Image::Iterator beg=this->begin();
            Image::Iterator end=this->end();
            Image::Iterator in=rhs.begin(),inend=rhs.end();

            while(beg !=end){

                if(*in==255){*in=*beg;}
                else{*in=0;}

                ++beg;
                ++in;
            }
        }
        return *this;
    }



    ostream& operator<<(ostream& pgdm,const Image& other){


        if(pgdm){
            pgdm<<"P5"<<endl;
            pgdm<<"# CREATOR: GIMP PNM Filter Version 1.1"<<endl;
            pgdm<<other.height<<" "<<other.width <<endl;

            for(int p=0;p<other.height*other.width;p+=other.width){

                for (int a=0;a<other.width;a++){
                    pgdm<<other.data[p];
                    p+=1;
                }


            }



        }
        return pgdm;
    }

    istream& operator >>(istream& pgdm,Image& other){
        int wede,hete;


        string toRead;

        if(pgdm){
            getline(pgdm, toRead);

            cout <<"Reading the first few lines to get the height,width and the highest number";

            while(toRead.compare("255")!=0){
                if(toRead[0]!='#'){
                    if(toRead.compare("P5")!=0){
                        cout<<toRead<<endl;
                        istringstream stream (toRead);

                        stream>>hete;
                        stream>>wede;

                        other.width=wede;
                        other.height=hete;
                    }
                }

                getline(pgdm, toRead);

                cout<<toRead<<endl;
            }

            cout<<"Height "<<other.height<<" The width is "<<other.width<<endl;
            int64_t arraysize=other.height*other.width;

            cout<<arraysize;

            other.data.reset(new unsigned char[arraysize]);
            skipws(pgdm);

            pgdm.read((char*)&other.data[0], arraysize);


        }
        return pgdm;
    }

    Image::Iterator::Iterator(const Iterator &rhs){
        ptr=rhs.ptr;

    }

    Image::Iterator::Iterator(unsigned char* p):ptr(p){}

    Image::Iterator::Iterator(Iterator && other){
        ptr=other.ptr;
        other.ptr=nullptr;
    }

    Image::Iterator::~Iterator(){ptr=nullptr;}

    Image::Iterator & Image::Iterator::operator=(const Iterator& other){

        if(this==&other){return *this;}

        ptr=other.ptr;

        return *this;

    }

    Image::Iterator & Image::Iterator::operator=(Iterator&& other){



        ptr=other.ptr;

        other.ptr=nullptr;
        return *this;

    }

    Image::Iterator & Image::Iterator::operator++(){

        ptr++;
        return *this;

    }

    Image::Iterator & Image::Iterator::operator--(){
        ptr--;
        return *this;

    }
    unsigned char& Image::Iterator::operator*(){

        return *ptr;

    }

    bool Image::Iterator::operator!=(const Iterator& other){
        return (ptr ==other.ptr);
    }
}
