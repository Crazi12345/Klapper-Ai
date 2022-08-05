#include "commandline.h"

using namespace std;

CommandLine::CommandLine() {
	cout << "Welcome to the Klapper AI CLI\n" <<
		 "If you need any help just type help in the CLI" << endl;
	Menu();

}


void CommandLine::Menu() {
	cout << "Options:\n\t" <<
		 "1:Train\n\t" <<
		 "2:TestTrain\n\t" <<
		 "3:PrintNetwork\n\t"
		 "4:Override Network\n\t"
		 "5:Move trained data to untrained data\n\t" << endl;
	cout << endl;
	cout << ">> ";
	string command;
	cin >> command;
	CommandHandler(command);


}

void CommandLine::CommandHandler(string c) {
	if(c == "Train" || c == "train" || c == "1"){
		NetworkHandler nh(500, 5, 10);
		nh.generateNodes();
		TrainingHandler trainer(nh);
		trainer.GenerateInputNodes();
		trainer.Train();
	} else if(c == "Test" || c == "TestTrain" ||
			  c == "2" || c == "testtrain" || c == "test" || c == "ttrain"){

		NetworkHandler nh(500, 5, 10);
		srand((unsigned) time(0));
		nh.generateRandomWeightNodes();
		TrainingHandler trainer(nh);
		trainer.GenerateInputNodes();
		trainer.Train();
	} else if(c == "print" || c == "PrintNetwork" ||
			  c == "3" || c == "pn" || c == "printnetwork" || c == "printN"){
		NetworkHandler nh(500, 5, 10);
		nh.generateNodes();
		nh.PrettyPrint();


	} else if(c == "override" || c == "NEW" || c == "4" || c == "OVERRIDE" || c == "Override"){
		string s;
		cout << "WARNING!!! WARNING!!! WARNING!!!\n "
				"This will override all progress made and make all the weights random and save it to the database\n"
				"Are You COMPLETELY SURE, you will do this then type \'OVERRIDE\' else this will abort" << endl;
		cin >> s;
		if(s == "OVERRIDE"){
			NetworkHandler nh(500, 5, 10);
			srand((unsigned) time(0));
			nh.generateRandomWeightNodes();
			TrainingHandler trainer(nh);
			trainer.GenerateInputNodes();
			trainer.Train();
			Persistence p;
			p.saveNodes(nh.getNodes());
		}
	} else if(c == "5" || c == "moveData" || c == "MoveData" || c == "mv" || c == "movedata"){
		Persistence per;
		per.moveTrainedDataBack();
	} else if(c == "help" || c == "Help"){
		Help();
	} else if(c == "exit" || c == "Exit"){
		Exit();
	} else {
		cout << "I do not understand please try again" << endl;
		cout << endl;

	}

	Menu();
}

void CommandLine::Clear() {

}

void CommandLine::Exit() {
	cout << endl;
	cout << "Press the X in the corner" << endl;
}

void CommandLine::Help() {
	cout << "Come on man, do you really need help,\n"
			" or do you just want to see if i bothered program it\n "
			"because i didnt\n" << endl;
}
