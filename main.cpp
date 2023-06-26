#include <iostream>
#include <fstream>
#include <unistd.h>
#include <conio.h>
#include <sstream>
using namespace std;

void sudahAkun();
void buatAkun();
void hapusAkun();
int main();

void sudahAkun()
{
    int option;
    char c;
    string NIM, namaPengguna, kataSandi;
    ifstream databaseAkun("Kelas_B.txt");
    system("cls");

    cout << "==========================\n";
    cout << "========== Masuk =========\n";
    cout << "==========================\n";
    cout << "Nama dan Sandi Tidak Mengandung Spasi!\n";
    cout << "Masukan NIM Pengguna: ";
    cin >> NIM;
    cout << "Masukan Nama Pengguna: ";
    cin >> namaPengguna;
    cout << "Masukan Kode Akses: ";
    do
    {
        c = getch();
        switch (c)
        {
        case 0:
            getch();
            break;
        case 13:
            cout << endl;
            break;
        case 8:
            if (kataSandi.length() > 0)
            {
                kataSandi.erase(kataSandi.end() - 1);
                cout << c << ' ' << c;
            }
            break;
        default:
            kataSandi += c;
            cout << '*';
            break;
        }
    } while (c != 13);

    for (int i = 0; i < namaPengguna.length(); i++)
    {
        namaPengguna[i] = tolower(namaPengguna[i]);
    }

    bool tersedia = false;
    string data;
    while (getline(databaseAkun, data))
    {
        string dataNIM, dataNamaPengguna, dataKataSandi;
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == ';')
            {
                data[i] = ' ';
            }
        }
        stringstream ss(data);
        ss >> dataNIM >> dataNamaPengguna >> dataKataSandi;

        if ('#' + NIM == dataNIM && namaPengguna == dataNamaPengguna && kataSandi == dataKataSandi)
        {
            tersedia = true;
            databaseAkun.close();
            cout << "\nLogin Telah Berhasil!";
            sleep(5);
        }
    }

    if (tersedia == false)
    {
        databaseAkun.close();
        cout << "\nSilahkan Masukan Nama Pengguna dan Kata Sandi yang Sesuai!";
        sleep(5);
        system("cls");
        cout << "==========================\n";
        cout << "========== Masuk =========\n";
        cout << "==========================\n";
        cout << "[1] Lanjut Masuk\n";
        cout << "[2] Buat Akun\n";
        cout << "[3] Kembali ke Halaman Login\n";
        cout << "Masukan Pilihan: ";
        cin >> option;
        if (option == 1)
        {
            sudahAkun();
            return;
        }
        else if (option == 2)
        {
            buatAkun();
            return;
        }
        else if (option == 3)
        {
            main();
            return;
        }
    }
};

void buatAkun()
{
    int option;
    char c, cekPW;
    string NIM, namaPengguna, kataSandi, arrayData[10];
    fstream databaseAkun;
    databaseAkun.open("Kelas_B.txt", ios::in);
    system("cls");

    cout << "==========================\n";
    cout << "======== Buat Akun =======\n";
    cout << "==========================\n";
    cout << "Nama dan Sandi Tidak Mengandung Spasi!\n";
    cout << "Masukan NIM Pengguna: ";
    cin >> NIM;

    if (NIM.length() > 10)
    {
        cout << "\nNIM Tidak Boleh Lebih dari 10 Karakter";
        sleep(3);
        buatAkun();
        return;
    }

    cout << "Masukan Nama Pengguna: ";
    cin >> namaPengguna;

    if (namaPengguna.length() > 20)
    {
        cout << "\nNama Pengguna Tidak Boleh Lebih dari 20 Karakter";
        sleep(3);
        buatAkun();
        return;
    }

    cout << "Masukan Kode Akses: ";
    cin >> kataSandi;

    if (kataSandi.substr(0, 2) != "KD" || kataSandi.substr(2, 11) != NIM)
    {
        cout << "\n2 Karakter Pertama Berisi 'KD' dan Dilanjutkan NIM\n";
        sleep(5);
        buatAkun;
        return;
    }

    for (int i = 0; i < namaPengguna.length(); i++)
    {
        namaPengguna[i] = tolower(namaPengguna[i]);
    }

    int counter = 0;
    string data;
    while (getline(databaseAkun, data))
    {
        if (data == "")
        {
            break;
        }
        arrayData[counter] = data;
        counter++;
    }

    databaseAkun.close();
    databaseAkun.open("Kelas_B.txt", ios::in);

    while (getline(databaseAkun, data))
    {
        string dataNIM, dataNamaPengguna, dataKataSandi;
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == ';')
            {
                data[i] = ' ';
            }
        }
        stringstream ss(data);
        ss >> dataNIM >> dataNamaPengguna >> dataKataSandi;

        if (namaPengguna == dataNamaPengguna || NIM == dataNIM)
        {
            databaseAkun.close();
            cout << "\nAkun Telah Terdaftar, Coba Lagi!";
            sleep(5);
            system("cls");
            cout << "==============================\n";
            cout << "========== Buat Akun =========\n";
            cout << "==============================\n";
            cout << "[1] Lanjut Buat Akun\n";
            cout << "[2] Sudah Punya Akun\n";
            cout << "[3] Kembali ke Halaman Login\n";
            cout << "Masukan Pilihan: ";
            cin >> option;
            if (option == 1)
            {
                buatAkun();
                return;
            }
            else if (option == 2)
            {
                sudahAkun();
                return;
            }
            else if (option == 3)
            {
                main();
                return;
            }
        }

        if (kataSandi == dataKataSandi)
        {
            cout << "\nKata Sandi Lemah!";
            cout << "\nIngin Menggunakan Kata Sandi? (Y/N): ";
            cin >> cekPW;

            if (cekPW == 'n' || cekPW == 'N')
            {
                databaseAkun.close();
                system("cls");
                cout << "==========================\n";
                cout << "======== Buat Akun =======\n";
                cout << "==========================\n";
                cout << "[1] Buat Akun Kembali\n";
                cout << "[2] Kembali ke Halaman Login\n";
                cout << "Masukan Pilihan: ";
                cin >> option;
                if (option == 1)
                {
                    buatAkun();
                    return;
                }
                else if (option == 2)
                {
                    main();
                    return;
                }
            }
            break;
        }
    }

    databaseAkun.close();
    databaseAkun.open("Kelas_B.txt", ios::out);

    arrayData[counter] = "#" + NIM + ";" + namaPengguna + ";" + kataSandi + ";";
    int loop = 0;
    for (int i = 0; i < 10; i++)
    {
        databaseAkun << arrayData[loop++] << endl;
    }

    databaseAkun.close();
    cout << "\nAkun Telah Selesai Dibuat";
    sleep(5);
};

void printAkun()
{
    fstream databaseAkun;
    databaseAkun.open("Kelas_B.txt", ios::in);
    system("cls");

    int loop = 0;
    string data;
    while (getline(databaseAkun, data))
    {
        string dataNIM, dataNamaPengguna, dataKataSandi;
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == ';' || data[i] == '#')
            {
                data[i] = ' ';
            }
        }
        stringstream ss(data);
        ss >> dataNIM >> dataNamaPengguna >> dataKataSandi;

        if (dataNIM == "")
        {
            break;
        }

        if (loop == 0)
        {
            cout << "========================\n";
            cout << "===== Akun Pengguna ====\n";
            cout << "========================\n";
            cout << "NIM\t: " << dataNIM << "\n";
            cout << "Nama\t: " << dataNamaPengguna << "\n";
            cout << "Kode\t: " << dataKataSandi << "\n";
            cout << "========================\n";
            loop++;
        }
        else
        {
            cout << "NIM\t: " << dataNIM << "\n";
            cout << "Nama\t: " << dataNamaPengguna << "\n";
            cout << "Kode\t: " << dataKataSandi << "\n";
            cout << "========================\n";
        }
    }
    databaseAkun.close();
    getch();
}

void hapusAkun()
{
    int option;
    char c, cekPW;
    string NIM, namaPengguna, kataSandi, arrayData[11];
    fstream databaseAkun;
    databaseAkun.open("Kelas_B.txt", ios::in);
    system("cls");

    cout << "==========================\n";
    cout << "========== Delete ========\n";
    cout << "==========================\n";
    cout << "Nama dan Sandi Tidak Mengandung Spasi!\n";
    cout << "Masukan NIM Pengguna: ";
    cin >> NIM;
    cout << "Masukan Nama Pengguna: ";
    cin >> namaPengguna;
    cout << "Masukan Kata Sandi: ";
    do
    {
        c = getch();
        switch (c)
        {
        case 0:
            getch();
            break;
        case 13:
            cout << endl;
            break;
        case 8:
            if (kataSandi.length() > 0)
            {
                kataSandi.erase(kataSandi.end() - 1);
                cout << c << ' ' << c;
            }
            break;
        default:
            kataSandi += c;
            cout << '*';
            break;
        }
    } while (c != 13);

    for (int i = 0; i < namaPengguna.length(); i++)
    {
        namaPengguna[i] = tolower(namaPengguna[i]);
    }

    int counter = 0;
    string data;
    while (getline(databaseAkun, data))
    {
        if (data == "")
        {
            break;
        }
        arrayData[counter] = data;
        counter++;
    }

    databaseAkun.close();
    databaseAkun.open("Kelas_B.txt", ios::in);

    bool tersedia = false;
    int loop = 0;
    while (getline(databaseAkun, data))
    {
        string dataNIM, dataNamaPengguna, dataKataSandi;
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == ';')
            {
                data[i] = ' ';
            }
        }
        stringstream ss(data);
        ss >> dataNIM >> dataNamaPengguna >> dataKataSandi;

        if ('#' + NIM == dataNIM && namaPengguna == dataNamaPengguna && kataSandi == dataKataSandi)
        {
            tersedia = true;

            int index = loop;
            for (int i = loop; i < 11; i++)
            {
                arrayData[i] = arrayData[++loop];
            }

            databaseAkun.close();
            databaseAkun.open("Kelas_B.txt", ios::out);

            for (int i = 0; i < 10; i++)
            {
                databaseAkun << arrayData[i] << endl;
            }

            databaseAkun.close();
            cout << "\nAkun Telah di Hapus!";
            sleep(5);
        }
        loop++;
    }

    if (tersedia == false)
    {
        databaseAkun.close();
        cout << "\nSilahkan Masukan Nama Pengguna dan Kata Sandi yang Sesuai!";
        sleep(5);
        system("cls");
        cout << "==========================\n";
        cout << "========= Delete =========\n";
        cout << "==========================\n";
        cout << "[1] Lanjut Hapus\n";
        cout << "[2] Buat Akun\n";
        cout << "[3] Kembali ke Halaman Login\n";
        cout << "Masukan Pilihan: ";
        cin >> option;
        if (option == 1)
        {
            hapusAkun();
            return;
        }
        else if (option == 2)
        {
            buatAkun();
            return;
        }
        else if (option == 3)
        {
            main();
            return;
        }
    }
};

int main()
{
    int option;
    do
    {
        system("cls");
        cout << "==========================\n";
        cout << "======= LOGIN MENU =======\n";
        cout << "==========================\n";
        cout << "[1] Login\n";
        cout << "[2] Create Account\n";
        cout << "[3] Display Account\n";
        cout << "[4] Delete Account\n";
        cout << "[5] Exit\n";
        cout << "Masukan Pilihan: ";
        cin >> option;
        switch (option)
        {
        case 1:
            sudahAkun();
            break;
        case 2:
            buatAkun();
            break;
        case 3:
            printAkun();
            break;
        case 4:
            hapusAkun();
            break;
        case 5:
            exit(1);
        default:
            cout << "\nPilihan Tidak Tersedia!\n";
            sleep(5);
        }
    } while (option != 5);
    return 0;
}
