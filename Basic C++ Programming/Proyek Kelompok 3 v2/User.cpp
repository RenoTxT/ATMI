#include "User.h"
#include <ctime>
string user::addLeadingZero(int number) //menambahkan "0" di depannya jika angka tersebut kurang dari 10.
{
    return (number < 10) ? "0" + to_string(number) : to_string(number);
    //Jika nilai number kurang dari 10, kita ingin menambahkan "0" di depannya agar memiliki dua digit. Oleh karena itu, kita menggunakan operator + untuk menggabungkan string "0" dengan string yang merupakan representasi angka number.
    //Jika nilai number lebih dari atau sama dengan 10, kita hanya memerlukan representasi string dari number tanpa menambahkan "0" di depannya.
}
string user::generateUniqueCode() //menghasilkan kode pemesanan unik berdasarkan waktu saat ini (tahun, bulan, hari, jam, menit, detik)
{
    time_t now = time(0);// time_t adalah tipe data yang digunakan untuk menyimpan waktu dalam representasi detik
    //time(0) = mendapatkan waktu saat ini dan disimpan dalam variabel now
    tm ltm;//tm adalah struktur data yang menyimpan informasi waktu terstruktur seperti tahun, bulan, hari, jam, dan sebagainya. 
    //Variabel ltm digunakan untuk menyimpan informasi waktu

    localtime_s(&ltm, &now);//mengonversi waktu dalam format time_t ke dalam struktur data tm. Hasilnya disimpan dalam variabel ltm.

    int year = 1900 + ltm.tm_year;// mulai dari 1900
    int month = 1 + ltm.tm_mon;// karena bulan pada sistem dimulai dari 0 maka kita tambah +1 untuk sesuai dengan kalender
    int day = ltm.tm_mday;
    int hour = ltm.tm_hour;
    int minute = ltm.tm_min;
    int second = ltm.tm_sec;

    // Format kode: TAHUNBULANHARIMENITDETIK
    return to_string(year) + addLeadingZero(month) + addLeadingZero(day) +
        addLeadingZero(hour) + addLeadingZero(minute) + addLeadingZero(second);
}