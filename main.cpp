#include <iostream>

using namespace std;

int length = 5;

int reading[5] = {1, 2, 3, 4, 5};

int incrementReading(int *nextReadingArray, int index){
    nextReadingArray[index--] += 1;
    for(; index >=0; index--){
        nextReadingArray[index] = nextReadingArray[index+1] + 1;
    }
}

int *getNextReading(int *currentReading){

    for(int i=0; i < length; i++){
        cout << currentReading[i] << " ";
    }
    cout << endl;

    int i=0;
    for(int i=0; i<length/2; i++){
        int swapper = currentReading[i];
        currentReading[i] = currentReading[length-1-i];
        currentReading[length-1- i] = swapper;
    }
    //int readingCopy = currentReading;
    /*
    int nextReadingArray[5] = {0};

    for(int i=0; i < length; i++){
        nextReadingArray[i] = readingCopy % 10;
        readingCopy /= 10;
    }

    */
    for(int i=0; i < length; i++){
        cout << currentReading[i] << " ";
    }
    cout << endl;


    //int nextReadingValue;

    int index;
    for(index=0; index< length; index++){

        bool incrementable = currentReading[index] < (9- index);

        if(incrementable){
            incrementReading(currentReading, index);
            break;
        }
    }

    for(int i=0; i < length; i++){
        cout << currentReading[i] << " ";
    }
    cout << endl;

    for(int i=0; i<length/2; i++){
        int swapper = currentReading[i];
        currentReading[i] = currentReading[length-1-i];
        currentReading[length-1- i] = swapper;
    }

    if(index == length){
        //Call constructor
        //reset();
        cout << "reset" << endl;
    }
    return currentReading;
}

int main()
{
    int input[5] = {1, 2, 3, 4, 7};
    int *array = getNextReading(input);
    for(int i=0; i < length; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
