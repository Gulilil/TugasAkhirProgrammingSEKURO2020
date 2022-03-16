#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int main () {
    // Buat papan dan inisiasi posisi robot dan mecha
    char papan[8][8] ;
    srand(time(0));
    int xmecha = rand() % 7;
    int ymecha = rand() % 7;
    while (xmecha == 0 && ymecha == 0){ //posisi awal mecha kurama akan dirandom lagi bila berada pada posisi (0,0)
        int xmecha = rand() % 7;
        int ymecha = rand() % 7;
    }

    // Inisiasi posisi robot dan mecha
    for (int i = 0 ; i < 8 ; i++){
        for (int j = 0; j < 8; j++){
            if (i == 7 && j == 0) {
                papan[i][j] = 'R';
            } else if (i == ymecha && j == xmecha ){
                papan[i][j] = 'M';
            } else {
                papan[i][j] = '0';
            }
        }
    }
    
    // Loop permainan
    bool game = true; // Bila bersifat true, game akan terus berlanjut, sebaliknya bila false
    int yrobot = 7;
    int xrobot = 0;
    string action; // variabel untuk tindakan robot
    string direction; // variabel untuk arah gerak robot atau arah serangan robot
    int hprobot = 100;
    int hpkurama = 100;
    int amount = 0; // Jumlah killcount bunshin mechakurama yang telah dihancurkan
    int attackkurama;
    int xdistance; //jarak horizontal mechakurama dari robot
    int ydistance; //jarak vertikal mechakurama dari robot

    while (game == true){
        // Status robot yang perlu ditampilkan setiap round
        cout << "==============================================================" << endl;
        cout << "Program akan dibatasi pada area 8x8 pada kuadran positif." << endl;
        cout << "Posisi robot sekarang ada pada koordinat ("<< xrobot << ", "<< (7-yrobot)<< ")." << endl;
        cout << "HP Robot : " << hprobot << " || HP Kurama : " << hpkurama << endl;

        // Melakukan print peta
        for (int i = 0; i < 8; i++){
            for (int j =0; j < 8; j++){
                if ( j == 7) {
                    cout << papan [i][j] << endl;
                }else {
                    cout << papan[i][j] << "|" ;
                }
            }
        }

        cout << "Tindakan apa yang ingin dilakukan robot? (tuliskan dalam KAPITAL) " << endl;
        cout << "Pilihan tindakan yang bisa dipilih: 'MOVE', 'ATTACK', 'DISTANCE', 'FINISH'" << endl;
        cin >> action;

        // Program bila action yang dipilih adalah "MOVE"
        if (action == "MOVE"){
            cout << "Ke arah manakah robot akan bergerak?" << endl;
            cout << "Pilihan arah yang bisa dipilih: 'FORWARD', 'BACKWARD', 'LEFT', 'RIGHT' " << endl;
            cin >> direction;
            if (direction == "FORWARD" ){
                if (papan[yrobot-1][xrobot] == 'M' or yrobot-1 < 0){
                    cout << "Gerakan tersebut tidak bisa dilakukan" << endl;
                } else {
                    papan[yrobot][xrobot] = '0';
                    papan[yrobot-1][xrobot] = 'R';
                    yrobot -=1;
                }
            }
            else if (direction == "BACKWARD"){
                if (papan[yrobot+1][xrobot] == 'M' or yrobot+1 > 7){
                    cout << "Gerakan tersebut tidak bisa dilakukan" << endl;
                } else {
                    papan[yrobot][xrobot] = '0';
                    papan[yrobot+1][xrobot] = 'R';
                    yrobot +=1;
                }
            }
            else if (direction == "LEFT"){
                if (papan[yrobot][xrobot-1] == 'M' or xrobot-1 < 0){
                    cout << "Gerakan tersebut tidak bisa dilakukan" << endl;
                } else {
                    papan[yrobot][xrobot] = '0';
                    papan[yrobot][xrobot-1] = 'R';
                    xrobot -=1;
                }
            }
            else if (direction == "RIGHT"){
                if (papan[yrobot][xrobot+1] == 'M' or xrobot+1 > 7){
                    cout << "Gerakan tersebut tidak bisa dilakukan" <<endl;
                } else {
                    papan[yrobot][xrobot] = '0';
                    papan[yrobot][xrobot+1] = 'R';
                    xrobot +=1;
                }
            }
            else {
                cout << "Gerakan tersebut tidak valid" << endl;
            }
        } 
        // Bila action yang dipilih adalah "ATTACK"
        else if (action == "ATTACK") {
            string initiate;
            string direction;
            cout << "Serangan hanya bisa dilakukan kepada petak di sebelah depan, belakang, kiri, dan kanan robot" << endl;
            cout << "Bila robot melakukan serangan, Mecha-Kurama juga akan melakukan serangan pada robot" << endl;
            cout << "Yakin akan melakukan serangan pada Mecha-Kurama? ('YA' atau 'TIDAK')" << endl;
            cin >> initiate;
            if (initiate == "YA"){
                cout << "Ke arah manakah serangan akan dilancarkan?" << endl;
                cout << "Pilihan arah yang bisa dipilih: 'FORWARD', 'BACKWARD', 'LEFT', 'RIGHT' " << endl;
                cin >> direction;
                if (direction == "FORWARD" ){
                    if (papan[yrobot-1][xrobot] == 'M'){
                        cout << "Mecha-Kurama terkena serangan" << endl;
                        hpkurama -= 40;
                        cout << "HP Mecha-kurama sekarang adalah " << hpkurama << endl;
                    } else {
                        cout << "Serangan tidak mengenai Mecha-Kurama" << endl;
                    }
                }
                else if (direction == "BACKWARD"){
                    if (papan[yrobot+1][xrobot] == 'M' ){
                        cout << "Mecha-Kurama terkena serangan" << endl;
                        hpkurama -= 40;
                        cout << "HP Mecha-kurama sekarang adalah " << hpkurama << endl;
                    } else {
                        cout << "Serangan tidak mengenai Mecha-Kurama" << endl;
                    }
                }
                else if (direction == "LEFT"){
                    if (papan[yrobot][xrobot-1] == 'M' or xrobot-1 < 0){
                        cout << "Mecha-Kurama terkena serangan" << endl;
                        hpkurama -= 40;
                        cout << "HP Mecha-kurama sekarang adalah " << hpkurama << endl;
                    } else {
                        cout << "Serangan tidak mengenai Mecha-Kurama" << endl;
                    }
                }
                else if (direction == "RIGHT"){
                    if (papan[yrobot][xrobot+1] == 'M' or xrobot+1 > 7){
                        cout << "Mecha-Kurama terkena serangan" << endl;
                        hpkurama -= 40;
                        cout << "HP Mecha-kurama sekarang adalah " << hpkurama << endl;
                    } else {
                        cout << "Serangan tidak mengenai Mecha-Kurama" << endl;
                    }
                }
                else {
                    cout << "Gerakan tersebut tidak valid" << endl;
                }

            attackkurama = rand() % 20;
            hprobot -= attackkurama; // mengurangi hp robot sesuai dengan serangan mecha kurama
            if (attackkurama >=15){
                cout << "CRITICAL HIT! Serangan kurama mengurangi HP robot sebesar "<< attackkurama << endl;
            } else {
                cout << "Serangan kurama mengurangi HP robot sebesar " << attackkurama << endl;
            }
            }
        }
        // Bila action yang dipilih adalah "DISTANCE"
        else if (action == "DISTANCE"){
            if (ymecha > yrobot){
                ydistance = ymecha - yrobot;
                cout << "Mecha berada pada " << ydistance << " petak di belakang robot." << endl;
            }else{
                ydistance = yrobot - ymecha;
                cout << "Mecha berada pada " << ydistance << " petak di depan robot." << endl;
            }
            if (xmecha > xrobot){
                xdistance = xmecha - xrobot;
                cout << "Mecha berada pada " << xdistance << " petak di kanan robot." << endl;
            } else {
                xdistance = xrobot - xmecha;
                cout << "Mecha berada pada " << xdistance << " petak di kiri robot." << endl;
            }
        }
        // Bila action yang dipilih adalah "FINISH"
        else if ( action == "FINISH" ){
            string end;
            cout << "Apakah anda yakin ingin mengakhiri program? ('YA' atau 'TIDAK)" << endl;
            cin >> end;
            if (end == "YA"){
                game = false;
            } else {
                cout << "Program tetap dilanjutkan." << endl;
            }
        }
        else {
            cout << "Action input invalid."<< endl;
        }

        // Program apabila HP robot telah habis
        if (hprobot < 0){
            if (hpkurama < 0){ //jika HP robot habis bertepatan dengan hancurnya mecha kurama, maka killcount ditambah 1
                amount +=1;
            }
            cout << "HP Robot telah habis. Robot telah dihancurkan oleh Mecha-Kurama" << endl;
            game = false;
        }

        // Program apabila HP kurama telah habis tetapi robot pemain masih hidup
        if (hpkurama < 0 && hprobot > 0){
            amount +=1; 
            string end;
            cout << "Bunshin Mecha-Kurama telah dihancurkan. Apakah ingin mengakhiri permainan? ('YA' atau 'TIDAK')" << endl;
            cin >> end;
            if (end == "YA") {
                game = false;
            } else { // melakukan reset pada program
                papan[ymecha][xmecha] = '0';
                xmecha = rand() % 7;
                ymecha = rand() % 7;
                while (xmecha == xrobot && ymecha == yrobot){ // melakukan tindakan preventif agar mecha tidak berada pada petak yang sama dengan robot
                    xmecha = rand() % 7;
                    ymecha = rand() % 7;
                }
                papan[ymecha][xmecha] = 'M'; //melakukan spawn ulang mecha pada peta
                hpkurama = 100; //melakukan reset ulang HP mecha kurama
            }

        }

    }

    cout << "Program telah selesai dilaksanakan" << endl;
    cout << "Jumlah Mecha-Kurama yang telah dikalahkan adalah " << amount << " bunshin." << endl;
}


