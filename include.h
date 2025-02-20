#pragma once
#include <Windows.h>
#pragma comment(lib,"Winmm.lib")
#include <wingdi.h>
#include <cmath>
#include <ctime>
int XOR_RAND() {
    time_t now;
    time(&now);
    int v = 1;
    v ^= rand() % SHRT_MAX;
    v |= 1;
    for (int i = 0; i < 128; i++) {
        v ^= (rand() % USHRT_MAX) % 0xFFFFFFFF;
    }
    return v ^ (now % SHRT_MAX) ^ 8191;
}
const float PI = acos(0) * 2;
const float TAU = PI * 2;
const float M_PI = PI;
#pragma comment(lib, "Advapi32.lib")
#pragma comment(lib, "msimg32.lib")
#define THREAD(t) CreateThread(0,0,t,0,0,0)
#define TERMINATE(t) TerminateThread(t,0)
#define MAKEHDC() GetDC(0)
#define X GetSystemMetrics(SM_CXSCREEN)
#define Y GetSystemMetrics(SM_CYSCREEN)
const int _BYTEBEAT_SECS = 20;
#define RANDRGB(v) RGB(XOR_RAND() % v, XOR_RAND() % v, XOR_RAND() % v)
#define MAKEDC() MAKEHDC()
DWORD WINAPI clearscreen(LPVOID lpvd) {
    InvalidateRect(0, 0, true);
    return 0;
}
#define CLEARSCREEN() THREAD(clearscreen)
int aproxf(int x, int y) {
    return round(x / y) * y;
}
VOID WINAPI poly(int sides, int radius, int x, int y, DWORD dwRop, int ang, int sexp) {
    POINT rahh[16];
    for (int i = 0; i < 16; i++) {
        rahh[i] = { (long)(x + sin(M_PI * 2 / sides * i * sexp + M_PI / 180 * ang) * radius),(long)(y + cos(M_PI * 2 / sides * sexp * i + M_PI / 180 * ang) * radius) };
    }
    HRGN hrgn = CreatePolygonRgn(rahh, sizeof(rahh) / 8, WINDING);
    HDC hdc = GetDC(0);
    SelectClipRgn(hdc, hrgn);
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);
    BitBlt(hdc, x - radius, y - radius, w, h, hdc, x - radius, y - radius, dwRop);
    DeleteObject(hrgn);
}