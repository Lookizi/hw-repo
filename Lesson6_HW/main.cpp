#include <iostream>
#include <fstream>
#include <string>




using namespace std;

int main(int argc, char *argv[]) {
    // 1st task

    char symbol;
    int file1_SIZE, file2_SIZE, SIZE;
    char *buff;

ofstream file1("file1.txt");
ofstream file2("file2.txt");
ofstream file3("file3.txt");
file1 << "Ground Control to Major Tom\nGround Control to Major Tom\nTake your protein pills and put your helmet on\n";

file2 << "Ground Control to Major Tom (ten, nine, eight, seven, six)\nCommencing countdown, engines on (five, four, three)\nCheck ignition and may God's love be with you (two, one, liftoff)\n";

file1.close();
file2.close();


//2nd task

ifstream File1("file1.txt");
ifstream File2("file2.txt");



File1.seekg(0,std::__1::ios_base::end);
file1_SIZE = File1.tellg();
File2.seekg(0,std::__1::ios_base::end);
file2_SIZE = File2.tellg();
SIZE = file1_SIZE + file2_SIZE;
buff = new char[SIZE];



    File1.clear();
    File1.seekg(0);
    File2.clear();
    File2.seekg(0);




    if (!File1.is_open() && !File2.is_open()){

        cout << "Error, file is not open" << endl;
    }

    else {

        for (int i = 0; i < SIZE; i++) {

            if (i <= file1_SIZE) {
                File1.get(symbol);
                buff[i] = symbol;
            }
            else{
                    File2.get(symbol);
                    buff[i] = symbol;
                }

            }
        }



    for (int i = 0; i < SIZE; ++i) {
        file3 << buff[i];
    }

    // 3d task

    if (argc != 3) {
        printf("Correct call to app: %s file_name keyword: \n", argv[0]);
        return 0xDEAD;
    }
        char *file_name, *keyword;
    file_name = argv[1];
    keyword = argv[2];


File1.close();
File2.close();
file3.close();
delete []buff;





}