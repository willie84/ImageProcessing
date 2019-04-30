#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Image.h"


#include "Array.h"
//#include "Matrix.h"



using namespace std;
using namespace MCHWIL006;
//method used to extract initial string.
void warning(void);

int main(int argc, char**  argv) {


    if(argc<3){
      //error handling.
		   warning();
         //return 1;
	}else if(argc == 4){

      if(string(argv[1]).compare("-i")==0){
        cout<<"Inverting operator invoked"<<endl;
         string str = string(argv[2]) ;
         Image i;
          i.load(str);
         Image b=!i;
          string output = string(argv[3]);
         b.save(output);
         //return 0;
      }else{
         warning();
         //return 1;
      }

   }else {
       if(string(argv[1]).compare("-a")==0){
         cout<<"Adding operator invoked"<<endl;
         string stra= string(argv[2]);
         string strb = string(argv[3]);
          string output = string(argv[4]);
         cout<<"Creating first image"<<endl;
         Image a;
         a.load(stra);

         cout<<"Creating second image"<<endl;
         cout<<strb<<endl;
         Image b;
         b.load(strb);
         Image sum = a + b;
         cout<<"Done"<<endl;
         sum.save(output);
        // return 0;
      }else if(string(argv[1]).compare("-s")==0){
        cout<<"Subtracting operator invoked"<<endl;
         string stra= string(argv[2]);
         string strb = string(argv[3]);
         //string output = string(argv[4]);

         Image a;
         a.load(stra);
         Image b;
         b.load(strb);
         Image diff = a - b;
       string save = string(argv[4]);
         diff.save(save);
        // return 0;
      }else if(string(argv[1]).compare("-l")==0){
        cout<<"Masking operator invoked"<<endl;
         string stra= string(argv[2]);
         string strb = string(argv[3]);
         Image a;
         a.load(stra);
         Image b;
         b.load(strb);
         Image mask = a / b;

         string save = string(argv[4]);
          mask.save(save);
         //return 0;
      } else if(string(argv[1]).compare("-t")==0){

        cout<<"Threshold operator invoked"<<endl;
         string stra= string(argv[2]);
         //threshold
         int f ;
         std::stringstream str(argv[3]);

         str >> f;

         Image a;
          a.load(stra);
         //b.load(strb);

         Image t = a*f;

         string save = string(argv[4]);
           t.save(save);
         //return 0;
      }

      else if(string(argv[1]).compare("-f")==0){
        cout<<"filtering operator invoked"<<endl;
         string stra= string(argv[2]);
         Image a;
         a.load(stra);
         //threshold
        int p;
        Textdata g;
         string strb=  string(argv[3]);
         ifstream file(strb, ios::in);
         if(file.is_open()){

               file>>p;
               g.N = p;
               int n;
               vector<vector<float> > vec(p,vector<float>(p));

               for(int i = 0; i< p; i++){
                //  file>>i;
                  //g.vec.push_back(i);
                  for(int j = 0; j< p; j++){
                    float ik;
                     file>>ik;
                     g.data[i][j]=ik;
                     //meret.push_back(ik);

                  }

               }



         }else{
            cout<<"File does not exist"<<endl;
         }




         Image f = a%g;
        string save=  string(argv[4]);
         f.save(save);

      }

      else{
        warning();
         //return 1;
      }

   }


return 0;


}

void warning(void){
  cout<<"Enter correct format of commands"<<endl;
  cout<<"imageops -a l1 l2 ADDoutputfile"<<endl;
  cout<<"imageops -s l1 l2 SUBTRACToutputfile"<<endl;
  cout<<"imageops -i l1 INVERToutputfile"<<endl;
  cout<<"imageops -l l1 l2 MASKoutputfile"<<endl;
  cout<<"imageops -t l1 f THRESHODLoutputfile"<<endl;
   cout<<"imageops -f l1 g FILTERoutputfile"<<endl;
}
