            #include <iostream>
            #include <iomanip>
            #include <fstream>
            #include <Windows.h>
            #include <stdio.h>

            using namespace std;

            int selectMenu;
            int count;
            char returnMenu;

            struct borrower {
                string studentName, studentNumber;
                string bookId, bookTitle, bookWriter, bookCategory;
            };

            int loginMenu(fstream & file) {
                borrower sortingData;
                string studentNumberTemp;
                int newLine = 0, line;

                file.open("assets/data.txt");
                do {
            studentNumberTemp = sortingData.studentNumber;
                    line = newLine;

                    getline(file, sortingData.studentName);
                    getline(file, sortingData.studentNumber);
                    getline(file, sortingData.bookId);
                    getline(file, sortingData.bookTitle);
                    getline(file, sortingData.bookWriter);
                    getline(file, sortingData.bookCategory);

                    if (sortingData.studentNumber != studentNumberTemp)
                        newLine++;
                }
                while (newLine != line);
                file.close();
                return newLine;
            }

            void adminMenu() {
                system("CLS");
                cout << ".+ ========================================== +.\n";
                cout << " Selamat Datang di Sistem Perpustakaan, Admin!\n";
                cout << ".+ ========================================== +.\n";
                cout << "[1] Daftar Buku\n";
                cout << "[2] Daftar Peminjam\n";
                cout << "[3] Cari Data Peminjam\n";
                cout << "[4] Hapus Data Peminjam\n";
                cout << "[5] Keluar\n";
                cout << ".+ ========================================== +.\n";
                cout << "[+] Silahkan Masukan Pilihan : ";
                cin >> selectMenu;
                system("CLS");
            }

            void userMenu() {
                system("CLS");
                cout << ".+ ========================================== +.\n";
                cout << " Selamat Datang di Sistem Perpustakaan, User!\n";
                cout << ".+ ========================================== +.\n";
                cout << "[1] Pinjam Buku\n";
                cout << "[2] Daftar Buku\n";
                cout << "[3] Keluar\n";
                cout << ".+ ========================================== +.\n";
                cout << "[+] Silahkan Masukan Pilihan : ";
                cin >> selectMenu;
                system("CLS");
            }

            void umumCategory() {
                cout << "[+] Kategori Umum\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " No |  ID  | Judul                            | Penulis            |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 1. | UMU1 | Seni Berbicara                   | Larry King         |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 2. | UMU2 | Strategi Pengembangan Diri       | Jen A. Hans        |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 3. | UMU3 | Membaca Emosi Orang              | Paul Ekman         |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 4. | UMU4 | Teknik Persuasi yang Efektif     | Robert Camus       |\n";
                cout << "--------------------------------------------------------------------\n\n";
            }

            void sainsCategory() {
                cout << "[+] Kategori Sains\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " No |  ID  | Judul                            | Penulis            |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 1. | SAI1 | Cosmos                           | Carl Sagan         |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 2. | SAI2 | The Selfish Gene                 | Richard Dawkins    |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 3. | SAI3 | On the Origin of Species         | Charles Darwin     |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 4. | SAI4 | A Brief History of Time          | Stephen Hawking    |\n";
                cout << "--------------------------------------------------------------------\n\n";
            }

            void sosialCategory() {
                cout << "[+] Kategori Sosial\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " No |  ID  | Judul                            | Penulis            |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 1. | SOS1 | Demokratisasi Birokrasi Edisi 2  | Bambang Istianto   |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 2. | SOS2 | Komunikasi Dan Gerakan Perubahan | Eko Harry Susanto  |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 3. | SOS3 | Jokowi & Kedaulatan Pangan       | Tulus T.H Tambunan |\n";
                cout << "--------------------------------------------------------------------\n";
                cout << " 4. | SOS4 | Ilmu Kenegaraan                  | Albert Camus       |\n";
                cout << "--------------------------------------------------------------------\n\n";
            }

            void getBooks() {
                cout << ".+ =====================[ Daftar Judul Buku ]===================== +.\n\n";
                umumCategory();
                sainsCategory();
                sosialCategory();

                cout << "[+] Kembali Ke Menu Utama (Y/N) : ";
                cin >> returnMenu;

                if (returnMenu == 'Y' || returnMenu == 'y') {
                    return;
                } else exit(0);
            }

            void postInvoice(fstream & file, string cstudentName, string cstudentNumber, string cbookId, string cbookTitle, string cbookWriter, string cbookCategory) {
                ofstream invoice;
                invoice.open("assets/invoice.txt");
                time_t now = time(0);
                char * dt = ctime( & now);
                int postInvoice, y = 1;

                string studentName;
                while (y == 1) {
                    system("CLS"); {
                        y = 0;
                    }
                cout << ".+ =============[ Invoice ]============= +.\n";
                cout << "         " << dt;
                cout << ".+ ========[ Detail Peminjaman ]======== +.\n";
                cout << "Nama     : " << cstudentName << endl;
                cout << "NIM      : " << cstudentNumber << endl;
                cout << "Kode     : " << cbookId << endl;
                cout << "Judul    : " << cbookTitle << endl;
                cout << "Penulis  : " << cbookWriter << endl;
                cout << "Kategori : " << cbookCategory << endl;
                cout << ".+ ========[ Detail Peminjaman ]======== +.\n";
                cout << endl;

                invoice << ".+ =============[ Invoice ]============= +.\n";
                invoice << "             Detail Peminjaman   \n";
                invoice << "         " << dt;
                invoice << ".+ ========[ Detail Peminjaman ]======== +.\n";
                invoice << "Nama     : " << cstudentName << endl;
                invoice << "NIM      : " << cstudentNumber << endl;
                invoice << "Kode     : " << cbookId << endl;
                invoice << "Judul    : " << cbookTitle << endl;
                invoice << "Penulis  : " << cbookWriter << endl;
                invoice << "Kategori : " << cbookCategory << endl;
                invoice << ".+ ========[ Detail Peminjaman ]======== +.\n";
                invoice << endl;
                }

                invoice.close();
            }

            void postData(fstream & file, int count) {
                borrower postData[100];
                string cstudentName, cstudentNumber, cbookId, cbookTitle, cbookWriter, cbookCategory;
                int total, bookCategory;
                int nbookTitle, bookWriter = 0;
                cout << ".+ ======[ Pinjam Buku ]====== +.\n";
                cout << "[1] Umum\n";
                cout << "[2] Sains\n";
                cout << "[3] Sosial\n";
                cout << "[+] Pilih Kategori Buku : ";
                cin >> bookCategory;
                system("CLS");
                switch (bookCategory) {
                case 1:
                    umumCategory();
                    break;
                case 2:
                    sainsCategory();
                    break;
                case 3:
                    sosialCategory();
                    break;
                }

                cout << "Jumlah Transaksi : ";
                cin >> total;
                cout << endl;

                for (int i = 0; i < total; i++) {
                    cin.ignore();
                cout << "[+] Transaksi Ke     : " << i + 1 << endl;
                cout << "[+] Nama Peminjam    : ";
                    getline(cin, postData[i].studentName);
                cout << "[+] NIM Peminjam     : ";
                    getline(cin, postData[i].studentNumber);
                cout << "[+] Judul Buku (1-4) : ";
                    cin >> nbookTitle;

                    if (bookCategory == 1) {
                        if (nbookTitle == 1) {
                            postData[i].bookId = "UMU1";
                            postData[i].bookTitle = "Seni Berbicara";
                            postData[i].bookWriter = "Larry King";
                            postData[i].bookCategory = "Umum";
                        } else if (nbookTitle == 2) {
                            postData[i].bookId = "UMU2";
                            postData[i].bookTitle = "Strategi Pengembangan Diri";
                            postData[i].bookWriter = "Jen A.Hans";
                            postData[i].bookCategory = "Umum";
                        } else if (nbookTitle == 3) {
                            postData[i].bookId = "UMU3";
                            postData[i].bookTitle = "Membaca Emosi Orang";
                            postData[i].bookWriter = "Paul Ekman";
                            postData[i].bookCategory = "Umum";
                        } else if (nbookTitle == 4) {
                            postData[i].bookId = "UMU4";
                            postData[i].bookTitle = "Teknik Persuasi yang Efektif";
                            postData[i].bookWriter = "Robert";
                            postData[i].bookCategory = "Umum";
                        }
                    } else if (bookCategory == 2) {
                        if (nbookTitle == 1) {
                            postData[i].bookId = "SAI1";
                            postData[i].bookTitle = "Cosmos";
                            postData[i].bookWriter = "Carl Sagan";
                            postData[i].bookCategory = "Sains";
                        } else if (nbookTitle == 2) {
                            postData[i].bookId = "SAI2";
                            postData[i].bookTitle = "The Selfish Gene";
                            postData[i].bookWriter = "Richard Dawkins";
                            postData[i].bookCategory = "Sains";
                        } else if (nbookTitle == 3) {
                            postData[i].bookId = "SAI3";
                            postData[i].bookTitle = "On the Origin of Species";
                            postData[i].bookWriter = "Charles Darwin";
                            postData[i].bookCategory = "Sains";
                        } else if (nbookTitle == 4) {
                            postData[i].bookId = "SAI4";
                            postData[i].bookTitle = "A Brief History of Time";
                            postData[i].bookWriter = "Stephen Hawking";
                            postData[i].bookCategory = "Sains";
                        }
                    } else if (bookCategory == 3) {
                        if (nbookTitle == 1) {
                            postData[i].bookId = "SOS1";
                            postData[i].bookTitle = "Demokratisasi Birokrasi Edisi 2";
                            postData[i].bookWriter = "Bambang Istianto";
                            postData[i].bookCategory = "Sosial";
                        } else if (nbookTitle == 2) {
                            postData[i].bookId = "SOS2";
                            postData[i].bookTitle = "Komunikasi Dan Gerakan Perubahan";
                            postData[i].bookCategory = "Sosial";
                            postData[i].bookWriter = "Eko Harry Susanto";
                            postData[i].bookCategory = "Sosial";
                        } else if (nbookTitle == 3) {
                            postData[i].bookId = "SOS3";
                            postData[i].bookTitle = "Jokowi & Kedaulatan Pangan";
                            postData[i].bookCategory = "Sosial";
                            postData[i].bookWriter = "Tulus T.H Tambunan";
                            postData[i].bookCategory = "Sosial";
                        } else if (nbookTitle == 4) {
                            postData[i].bookId = "SOS4";
                            postData[i].bookTitle = "Ilmu Kenegaraan";
                            postData[i].bookCategory = "Sosial";
                            postData[i].bookWriter = "Albert Camus";
                            postData[i].bookCategory = "Sosial";
                        }
                    } else exit(0);

                    cstudentName = postData[i].studentName;
                    cstudentNumber = postData[i].studentNumber;
                    cbookId = postData[i].bookId;
                    cbookTitle = postData[i].bookTitle;
                    cbookWriter = postData[i].bookWriter;
                    cbookCategory = postData[i].bookCategory;

                cout << endl;
                }

                postInvoice(file, cstudentName, cstudentNumber, cbookId, cbookTitle, cbookWriter, cbookCategory);

                file.open("assets/data.txt", ios::app | ios::out);
                for (int i = 0; i < total; i++) {
                    file << postData[i].studentName << endl;
                    file << postData[i].studentNumber << endl;
                    file << postData[i].bookId << endl;
                    file << postData[i].bookTitle << endl;
                    file << postData[i].bookWriter << endl;
                    file << postData[i].bookCategory << endl;
                }
                file.close();

                file.open("assets/log.txt", ios::app | ios::out);
                time_t now = time(0);
                char * dt = ctime( & now);
                for (int i = 0; i < total; i++) {
                    file << ".+ =======[ Log Peminjam ] ======= +.\n";
                    file << "Tanggal  : " << dt;
                    file << "Nama     : " << postData[i].studentName << endl;
                    file << "NIM      : " << postData[i].studentNumber << endl;
                    file << "Kode     : " << postData[i].bookId << endl;
                    file << "Judul    : " << postData[i].bookTitle << endl;
                    file << "Penulis  : " << postData[i].bookWriter << endl;
                    file << "Kategori : " << postData[i].bookCategory << endl;
                }
                file.close();

                cout << "[+] Kembali Ke Menu Utama (Y/N) ";
                cin >> returnMenu;

                if (returnMenu == 'Y' || returnMenu == 'y') {
                    return;
                } else exit(0);
            }


            void readData(fstream & file, int count) {
                borrower readData[count], temp;
                file.open("assets/data.txt");
                for (int i = 0; i < count; i++) {
                    getline(file, readData[i].studentName);
                    getline(file, readData[i].studentNumber);
                    getline(file, readData[i].bookId);
                    getline(file, readData[i].bookTitle);
                    getline(file, readData[i].bookWriter);
                    getline(file, readData[i].bookCategory);


        }        file.close();
                for (int i = 0; i < count; i++) {
                    for (int j = i + 1; j < count; j++) {
                        if (readData[i].studentName > readData[j].studentName) {
                            temp = readData[i];
                            readData[i] = readData[j];
                            readData[j] = temp;
                        }
                    }
                }
                cout << ".+ ==============================================[ Daftar Data Peminjam ]============================================== +.\n\n";
                cout << "[+] Jumlah Peminjam : " << count << endl;
                cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
                cout << "             Nama              |    NIM     | Kode |               Judul               |      Penulis       | Kategori | \n";
                cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
                for (int i = 0; i < count; i++) {
                cout << setiosflags(ios::left) << setw(30) << readData[i].studentName << " | ";
                cout << setiosflags(ios::left) << setw(10) << readData[i].studentNumber << " | ";
                cout << setiosflags(ios::left) << setw(4) << readData[i].bookId << " | ";
                cout << setiosflags(ios::left) << setw(33) << readData[i].bookTitle << " | ";
                cout << setiosflags(ios::left) << setw(18) << readData[i].bookWriter << " | ";
                cout << setiosflags(ios::left) << setw(8) << readData[i].bookCategory << " | " << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
                }
            }

            void getData(fstream & file, int count) {
                borrower getData[count], temp;
                readData(file, count);
                cout << "\n[+] Kembali Ke Menu Utama (Y/N) : ";
                cin >> returnMenu;

                if (returnMenu == 'Y' || returnMenu == 'y') {
                    return;
                } else exit(0);
            }

            void getDataByStudentNumber(fstream & file, int count) {
                borrower getDataByStudentNumber[count], temp;
                string cari;
                bool p = false;
                cout << ".+ =========[ Cari Data Peminjam ] ========= +.\n\n";
                cout << "[+] Jumlah Peminjam      : " << count << endl;
                cout << "\n[+] Masukan NIM Peminjam : ";
                cin.ignore();
                cin >> cari;

                file.open("assets/data.txt", ios::in);
                for (int i = 0; i < count; i++) {
                    getline(file, getDataByStudentNumber[i].studentName);
                    getline(file, getDataByStudentNumber[i].studentNumber);
                    getline(file, getDataByStudentNumber[i].bookId);
                    getline(file, getDataByStudentNumber[i].bookTitle);
                    getline(file, getDataByStudentNumber[i].bookWriter);
                    getline(file, getDataByStudentNumber[i].bookCategory);
                }
                file.close();
                cout << endl;
                cout << ".+ =======[ Informasi Data Peminjam ] ======= +.\n";
                for (int i = 0; i < count; i++) {
                    if (cari == getDataByStudentNumber[i].studentNumber) {
                        p = true;
                    cout << "Nama     : " << getDataByStudentNumber[i].studentName << endl;
                    cout << "NIM      : " << getDataByStudentNumber[i].studentNumber << endl;
                    cout << "Kode     : " << getDataByStudentNumber[i].bookId << endl;
                    cout << "Judul    : " << getDataByStudentNumber[i].bookTitle << endl;
                    cout << "Penulis  : " << getDataByStudentNumber[i].bookWriter << endl;
                    cout << "Kategori : " << getDataByStudentNumber[i].bookCategory << endl;
                    cout << ".+ =======[ Informasi Data Peminjam ] ======= +.\n";
                    }
                }
                if (p == false) {
                cout << "[!] Data tidak ditemukan!\n";
                }
                cout << endl;
                cout << "[+] Kembali Ke Menu Utama (Y/N) ";
                cin >> returnMenu;
                if (returnMenu == 'Y' || returnMenu == 'y') {
                    return;
                } else exit(0);
            }

            void deleteDataByStudentNumber(fstream & file, int count) {
                borrower deleteDataByStudentNumber[count];
                string nimm;
                bool y = false;
                cout << ".+ =========[ Hapus Data Peminjam ] ========= +.\n\n";
                cout << "[+] Jumlah Peminjam      : " << count << endl;

                file.open("assets/data.txt");
                for (int i = 0; i < count; i++) {
                    getline(file, deleteDataByStudentNumber[i].studentName);
                    getline(file, deleteDataByStudentNumber[i].studentNumber);
                    getline(file, deleteDataByStudentNumber[i].bookId);
                    getline(file, deleteDataByStudentNumber[i].bookTitle);
                    getline(file, deleteDataByStudentNumber[i].bookWriter);
                    getline(file, deleteDataByStudentNumber[i].bookCategory);
                }
                file.close();
                cout << "\n[+] Masukan NIM Peminjam : ";
                cin.ignore();
                getline(cin, nimm);
                for (int i = 0; i < count; i++) {
                    if (nimm == deleteDataByStudentNumber[i].studentNumber) {
                        for (int j = i; j < count - 1; j++) {
                            deleteDataByStudentNumber[j].studentName = deleteDataByStudentNumber[j + 1].studentName;
                            deleteDataByStudentNumber[j].studentNumber = deleteDataByStudentNumber[j + 1].studentNumber;
                            deleteDataByStudentNumber[j].bookId = deleteDataByStudentNumber[j + 1].bookId;
                            deleteDataByStudentNumber[j].bookTitle = deleteDataByStudentNumber[j + 1].bookTitle;
                            deleteDataByStudentNumber[j].bookWriter = deleteDataByStudentNumber[j + 1].bookWriter;
                            deleteDataByStudentNumber[j].bookCategory = deleteDataByStudentNumber[j + 1].bookCategory;
                        }
                        count--;
                        y = true;
                        break;
                    }
                }
                if (y == true) {
                cout << "\n[!] Data Berhasil Dihapus! \n\n";
                    file.open("assets/data.txt", ios::trunc | ios::out);
                    for (int i = 0; i < count; i++) {
                        file << deleteDataByStudentNumber[i].studentName << endl;
                        file << deleteDataByStudentNumber[i].studentNumber << endl;
                        file << deleteDataByStudentNumber[i].bookId << endl;
                        file << deleteDataByStudentNumber[i].bookTitle << endl;
                        file << deleteDataByStudentNumber[i].bookWriter << endl;
                        file << deleteDataByStudentNumber[i].bookCategory << endl;
                    }

                    file.close();

                    file.open("assets/data.txt");
                cout << ".+ ==============================================[ Daftar Data Peminjam ]============================================== +.\n\n";
                cout << "[+] Jumlah Peminjam : " << count << endl;
                cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
                cout << "             Nama              |    NIM     | Kode |               Judul               |      Penulis       | Kategori | \n";
                cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
                    for (int i = 0; i < count; i++) {
                    cout << setiosflags(ios::left) << setw(30) << deleteDataByStudentNumber[i].studentName << " | ";
                    cout << setiosflags(ios::left) << setw(10) << deleteDataByStudentNumber[i].studentNumber << " | ";
                    cout << setiosflags(ios::left) << setw(4) << deleteDataByStudentNumber[i].bookId << " | ";
                    cout << setiosflags(ios::left) << setw(33) << deleteDataByStudentNumber[i].bookTitle << " | ";
                    cout << setiosflags(ios::left) << setw(18) << deleteDataByStudentNumber[i].bookWriter << " | ";
                    cout << setiosflags(ios::left) << setw(8) << deleteDataByStudentNumber[i].bookCategory << " | " << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
                    }
                    file.close();

                } else cout << "\n[!] Data tidak ditemukan!\n\n";
                cout << "[+] Kembali Ke Menu Utama (Y/N) ";
                cin >> returnMenu;
                if (returnMenu == 'Y' || returnMenu == 'y') {
                    return;
                } else exit(0);
            }

            int main() {
                fstream file;
                system("CLS");
                printf("\e[?25l");
                SetConsoleCP(437);
                SetConsoleOutputCP(437);
                int bar1 = 177, bar2 = 219;
                int selectLogin;

                cout << "\n\n\n\t\t\t\t";

                for (int i = 0; i < 25; i++)
                cout << (char) bar1;

                cout << "\r";
                cout << "\t\t\t\t";
                for (int i = 0; i < 25; i++) {
                cout << (char) bar2;
                    Sleep(1);
                }

                cout << "\n\t\t\t\t" << "";
                system("pause");
                system("CLS");

                cout << ".+ =========================== +.\n";
                cout << " Sistem Informasi Perpustakaan!\n";
                cout << ".+ =========================== +.\n";
                cout << "[1] Login as Admin" << endl;
                cout << "[2] Login as User" << endl;
                cout << ".+ =========================== +.\n";
                cout << "[+] Silahkan Masukan Pilihan : ";
                cin >> selectLogin;

                switch (selectLogin) {
                case 1:
                    do {
                        count = loginMenu(file);
                        adminMenu();

                        switch (selectMenu) {
                        case 1:
                            getBooks();
                            break;
                        case 2:
                            getData(file, count);
                            break;
                        case 3:
                            getDataByStudentNumber(file, count);
                            break;
                        case 4:
                            deleteDataByStudentNumber(file, count);
                            break;
                        case 5:
                            exit(0);
                        }

                    } while (true);
                    break;
                case 2:
                    do {
                        count = loginMenu(file);
                        userMenu();

                        switch (selectMenu) {
                        case 1:
                            postData(file, count);
                            break;
                        case 2:
                            getBooks();
                            break;
                        case 3:
                            exit(0);
                        }

                    } while (true);
                    break;

                }

            }
