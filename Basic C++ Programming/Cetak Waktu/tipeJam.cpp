#include "tipeJam.h"
#include <iostream>

using namespace std;

void tipeJam::setWaktu(int jam, int menit, int detik) {
    jm = jam;
    mnt = menit;
    dtk = detik;
}

void tipeJam::dapatkanWaktu(int& jam, int& menit, int& detik) const {
    jam = jm;
    menit = mnt;
    detik = dtk;
}

void tipeJam::cetakWaktu() const {
    cout << jm << ":" << mnt << ":" << dtk << std::endl;
}

void tipeJam::incrementDetik() {
    dtk++;
    if (dtk == 60) {
        dtk = 0;
        incrementMenit();
    }
}

void tipeJam::incrementMenit() {
    mnt++;
    if (mnt == 60) {
        mnt = 0;
        incrementJam();
    }
}

void tipeJam::incrementJam() {
    jm++;
    if (jm == 24) {
        jm = 0;
    }
}

bool tipeJam::equalWaktu(const tipeJam& other) const {
    return (jm == other.jm && mnt == other.mnt && dtk == other.dtk);
}

tipeJam::tipeJam(int jam, int menit, int detik) : jm(jam), mnt(menit), dtk(detik) {}

tipeJam::tipeJam() : jm(0), mnt(0), dtk(0) {}