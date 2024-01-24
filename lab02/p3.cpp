    //Will Pitkin       265052
    //Lab02   Part 3    18Jan2024
    //This code is going to take 3 bit numbers and turn them into binary to
    //interpret them as permissions.

    #include <iostream>
    #include <cmath>
    using namespace std;

    int main ()
    {
        char user, group, other;

            //user inputs 3 digit number (9 bits total, digits 0-7)
            //they are interpreted as characters so that they are read one by one
            //"user" represents first char, "group" second, "other" third

        cout << "Permissions: ";
        cin  >> user >> group >> other;

            //each char is broken into a read, write, and execute permission bit

        int readu, readg, reado;          //bits for the read character u = user
        int writeu, writeg, writeo;       //bits for write,  g = group
        int executeu, executeg, executeo; //bits for execute, o = other

        readu    = (user - '0') / 4;
        writeu   = (user - '0' - readu *4) / 2;
        executeu = (user - '0' - readu *4 - writeu *2) / 1;

        readg    = (group - '0') / 4;
        writeg   = (group - '0' - readg *4) / 2;
        executeg = (group - '0' - readg *4 - writeg *2) / 1;

        reado    = (other - '0') / 4;
        writeo   = (other - '0' - reado *4) / 2;
        executeo = (other - '0' - reado *4 - writeo *2) / 1;

            //output the resuts organized into user, group, and other since each
            //character has one element of each for each of its bits

        cout << endl;
        cout << "User:" << endl;
        cout << "read    " << readu << endl;
        cout << "write   " << writeu << endl;
        cout << "execute " << executeu << endl << endl;

        cout << "Group:" << endl;
        cout << "read    " << readg << endl;
        cout << "write   " << writeg << endl;
        cout << "execute " << executeg << endl << endl;

        cout << "Other:" << endl;
        cout << "read    " << reado << endl;
        cout << "write   " << writeo << endl;
        cout << "execute " << executeo << endl << endl;

        return 0;

    }