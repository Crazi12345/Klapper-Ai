#include "traininghandler.h"
#include "persistence.h"
TrainingHandler::TrainingHandler()
{

}

TrainingHandler::TrainingHandler(NetworkHandler nh){
    this->nh = nh;
}
void TrainingHandler::GenerateInputNodes(){
    for(int i = 0; i < 500; i++){

        input_nn1.push_back(10);
        input_nn2.push_back(0);
    }
}

void TrainingHandler::Train(){
    Persistence per;
    int debug_num = 0;

    for(int fails = 0; fails < max_fails; fails++){

        std::cout << std::endl;

        std::cout << "START OF TRAINING: " << std::endl;


        //First phase training
        for(int train_cycles = 0; train_cycles < train_count + 1; train_cycles++){


            input1 = nh.CalculateOutput(input_nn1);
            nh.BackProp(input1, 1);



            input2 = nh.CalculateOutput(input_nn2);
            nh.BackProp(input2, 0);



            if(train_cycles%(train_count/10) == 0){
                float val = train_cycles*100;
                float val2 = train_count;
                std::cout << "LOADING: " << (val/val2) << "%" << std::endl;

                std::cout << "Input 1: "<< input1 << " Input2: "<< input2 << std::endl;
                nh.UpdateNeuralNetwork(); 

            }
        }


                std::cout << "Input 1: "<< input1 << " Input2: "<< input2 << std::endl;
      /*  input1 = nh.CalculateOutput(input_nn1);
        input2 = nh.CalculateOutput(input_nn2);
*/

        if ( (input1 < (1 + precision) && input1 > (1 - precision)) && (input2 < (precision) && input1 > ( -precision))){
            fails = max_fails;
            std::cout << "TRAINING SECOND PHASE:" << std::endl;
            std::cout << "TARGET: " << input1 << std::endl;
            std::cout << "NOISE: " << input2 << std::endl;


            int phase_2_train_count = train_count*10;

            for(int train_cycles = 0; train_cycles < phase_2_train_count + 1; train_cycles++){
                input1 = nh.CalculateOutput(input_nn1);
                nh.BackProp(input1, 1);
                input2 = nh.CalculateOutput(input_nn2);


                nh.BackProp(input2, 0);
                if(train_cycles%(phase_2_train_count/10) == 0){
                    float val = train_cycles*100;
                    float val2 = phase_2_train_count;
                    std::cout << "LOADING: " << (val/val2) << "%" << std::endl;
                }
            }

            std::cout << "TARGET: " << input1 << std::endl;
            std::cout << "NOISE: " << input2 << std::endl;

                 //per.saveNodes(nh.getNodes());
        }else{
            std::cout << "NETWORK FAILED: RETRY" << std::endl;
            std::cout << "TARGET: " << input1 << std::endl;
            std::cout << "NOISE: " << input2 << std::endl;

            srand((unsigned) time(0));
            nh.generateRandomWeightNodes();
           /* nh = NetworkHandler(500,3,5);
            nh.generateNodes();

*/
        }
}
}
