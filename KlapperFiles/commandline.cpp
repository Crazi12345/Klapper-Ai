#include "commandline.h"
using namespace std;
CommandLine::CommandLine()
{
    cout << "Welcome to the Klapper AI CLI\n" <<
            "If you need any help just type help in the CLI" << endl;
    Menu();

}


void CommandLine::Menu(){
  cout << "Options:\n\t"<<
       "1:Train\n\t"<<
          "2:TestTrain\n\t" <<
            "3:PrintNetwork\n\t" << endl;
  cout << endl;
  cout << ">> ";
  string command;
  cin >> command;
  CommandHandler(command);



}
void CommandLine::CommandHandler(string c){
    if(c == "Train" || c == "train" || c =="1"){
        NetworkHandler nh(500,5,10);
        nh.generateNodes();
        TrainingHandler trainer(nh);
        trainer.GenerateInputNodes();
        trainer.Train();
    }
    else if (c == "Test" || c == "TestTrain" ||
             c =="2"||c == "testtrain" || c == "test" || c =="ttrain"){

         NetworkHandler nh(500,5,10);
         srand((unsigned) time(0));
         nh.generateRandomWeightNodes();
         TrainingHandler trainer(nh);
         trainer.GenerateInputNodes();
         trainer.Train();
    }
    else if (c == "print" || c == "PrintNetwork" ||
             c =="3"||c == "pn" || c == "printnetwork" || c =="printN"){
          NetworkHandler nh(500,5,10);
          nh.generateNodes();
          nh.PrettyPrint();


    }
    else if(c == "help"|| c =="Help"){
        Help();
    }
    else if(c=="exit"||c=="Exit"){
        Exit();
    }
    else{
        cout << "I do not understand please try again" << endl;
        cout << endl;

    }

    Menu();
}
void CommandLine::Clear(){

}

void CommandLine::Exit(){
    cout << endl;
     cout << "Press the X in the corner" << endl;
}

void CommandLine::Help(){
    cout << "Come on man, do you really need help,\n"
            " or do you just want to see if i bothered program it\n "
            "because i didnt\n"<<endl;
}
