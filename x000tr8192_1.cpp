// x000tr8192_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "include.h"
#include <iostream>
//  icons or circles in payload 2
int ICONS_OR_CIRCLES_IN_PAYLOAD_2 = 0; // circles = odd number (eg. 1), icons = even number (eg. 0)
DWORD WINAPI bytebeat1(LPVOID lpvd)
{
    const int SampleRATE = 38250;
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, SampleRATE, 8000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[SampleRATE * _BYTEBEAT_SECS];
    for (DWORD t = 0; t < sizeof(buffer); t++) {
        buffer[t] = static_cast<char>(((t * (t & (1 << 5) + 3) >> 7) + t * 2) ^ (int)(sin(t & t >> 12) / 1000.f * (t * 7 / 4 << 1)));
    }
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
    Sleep(-1);
    return 0;
}
DWORD WINAPI bytebeat2(LPVOID lpvd) {
    const int SampleRATE = 35000;
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, SampleRATE, 8000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[SampleRATE * _BYTEBEAT_SECS];
    for (DWORD t = 0; t < sizeof(buffer); t++) {
        buffer[t] = static_cast<char>((t ^ 224) * (t >> 12) / 8);
    }
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
    Sleep(-1);
    return 0;
}
//(t*(t>>12&t)>>8)+t
DWORD WINAPI bytebeat3(LPVOID lpvd) {
    const int SampleRATE = 48000;
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, SampleRATE, 8000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[SampleRATE * _BYTEBEAT_SECS];
    for (DWORD t = 0; t < sizeof(buffer); t++) {
        buffer[t] = static_cast<char>((t * (t >> 12 & t) >> 8) + t);
    }
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
    Sleep(-1);
    return 0;
}
//(t*5/2%151&191)*(t/8192*15)
DWORD WINAPI bytebeat4(LPVOID lpvd) {
    const int SampleRATE = 23000;
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, SampleRATE, 80000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[SampleRATE * _BYTEBEAT_SECS];
    for (DWORD t = 0; t < sizeof(buffer); t++) {
        buffer[t] = static_cast<char>(((int)(t * 1 / 4.f) % 151 & 191) * (t / 8192.f * 6) / 4);
    }
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
    Sleep(-1);
    return 0;
}
//(((t>>3^t)&t>>5|t>>3)^((t>>(t>>12)%4)+t*(1+(1+(t>>16)%6)*(t>>10)*(t>>11)%8)))/((t>>(t>>12)%4)+t*(1+(1+(t>>16)%6)*(t>>10)*(t>>11)%8))*t
DWORD WINAPI bytebeat5(LPVOID lpvd) {
    const int SampleRATE = 42300;
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, SampleRATE, 80000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[SampleRATE * _BYTEBEAT_SECS];
    for (DWORD t = 1; t < (sizeof(buffer) + 1); t++) {
        buffer[t - 1] = static_cast<char>((((t >> 3 ^ t) & t >> 5 | t >> 3) ^ ((t >> (t >> 12) % 4) + t * (1 + (1 + (t >> 16) % 6) * (t >> 10) * (t >> 11) % 8))) / (float)((t >> (t >> 12) % 4) + t * (1 + (1 + (t >> 16) % 6) * (t >> 10) * (t >> 11) % 8)) * t);
    }
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
    Sleep(-1);
    return 0;
}
DWORD WINAPI bytebeat6(LPVOID lpvd) {
    const int SampleRATE = 37000;
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, SampleRATE, 80000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[SampleRATE * _BYTEBEAT_SECS];
    for (DWORD t = 1; t < (sizeof(buffer) + 1); t++) {
        buffer[t - 1] = static_cast<char>(sin(t | 267 ^ t / 8192) * (t << 1) / 1000);
    }
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
    Sleep(-1);
    return 0;
}
DWORD WINAPI bytebeat7(LPVOID lpvd) {
    const int SampleRATE = 25600;
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, SampleRATE, 80000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[SampleRATE * _BYTEBEAT_SECS];
    int r = XOR_RAND() % 15;
    for (DWORD t = 0; t < sizeof(buffer); t++) {
        buffer[t] = static_cast<char>(t * 3 ^ t / (t & 15 ? r : r = (XOR_RAND() % 15) + 1));
    }
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
    Sleep(-1);
    return 0;
}
//t*((t>>7)+t>>2)>>3 %(t | 1) * (t / 256)
DWORD WINAPI bytebeat8(LPVOID lpvd) {
    const int SampleRATE = 11600;
    HWAVEOUT hwo = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, SampleRATE, 80000, 1, 8, 0 };
    waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[SampleRATE * _BYTEBEAT_SECS];
    int r = XOR_RAND() % 15;
    for (DWORD t = 0; t < sizeof(buffer); t++) {
        buffer[t] = static_cast<char>((t * ((t >> 7) + t >> 2) >> 3 ^ (t | 1) )* (t / 256));
    }
    WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
    waveOutClose(hwo);
    Sleep(-1);
    return 0;
}
DWORD WINAPI possibleclearing(LPVOID lpvd) {
    while (1) {
        if ((XOR_RAND() % 64) > 60) {
            CLEARSCREEN();
        }
        Sleep(10);
    }
}
DWORD WINAPI drawcursors(LPVOID lpvd) {
    CURSORINFO ci;
    ci.cbSize = sizeof(CURSORINFO);
    GetCursorInfo(&ci);
    int w = X, h = Y;
    HDC hdc = MAKEDC();
    while (1) {
        int vX = rand() % w, vY = rand() % h;
        int signX = rand() % 2, signY = rand() % 2;
        int dX, dY;
        if (signX == 0) {
            dX = -1;
        }
        else {
            dX = 1;
        }
        if (signY == 0) {
            dY = -1;
        }
        else {
            dY = 1;
        }
        int inc = 3;
        int sX, sY;
        sX = vX;
        sY = vY;
        for (int I = 0; I < 100; I++) {
            DrawIcon(hdc, sX, sY, ci.hCursor);
            sX += inc, sY += inc;
            if (sX > w) {
                I = 101;
            }
            else {
                if (sX < 0) {
                    I = 101;
                }
            }
            if (sY > h) {
                I = 101;
            }
            else {
                if (sY < 0) {
                    I = 101;
                }
            }
            Sleep(10);
        }
    }
}
DWORD WINAPI errorsines(LPVOID lpvd) {
    int w = X, h = Y;
    HDC hdc = MAKEDC();
    HICON error = LoadIcon(0,IDI_ERROR);
    while (1) {
        int vX = XOR_RAND() % w, vY = XOR_RAND() % h;
        int signX = XOR_RAND() % 2, signY = XOR_RAND() % 2;
        int dX, dY;
        if (signX == 0) {
            dX = -1;
        }
        else {
            dX = 1;
        }
        if (signY == 0) {
            dY = -1;
        }
        else {
            dY = 1;
        }
        int inc = 10;
        int sX, sY;
        sX = vX + inc;
        sY = vY + cosf(inc * PI / 16.f) * 512.f;
        for (int I = 0; I < 100; I++) {
            DrawIcon(hdc, sX, sY, error);
            sX += inc, sY = (cosf(PI / 16.f * I) * 64.f) + vY;
            if (sX > w) {
                I = 101;
            }
            else {
                if (sX < 0) {
                    I = 101;
                }
            }
            if (sY > h) {
                I = 101;
            }
            else {
                if (sY < 0) {
                    I = 101;
                }
            }
            Sleep(20);
        }
    }
}
DWORD WINAPI gdi1(LPVOID lpvd) {
    int x = X, y = Y;
    HDC hdc = MAKEHDC();
    while (1) {
        HBRUSH brush = CreateSolidBrush(RANDRGB(256));
        SelectObject(hdc, brush);
        StretchBlt(hdc, 0, y, x, -y, hdc, 0, 0, x, y, PATINVERT);
        StretchBlt(hdc, 0, y, x, -y, hdc, 0, 0, x, y, SRCAND);
        StretchBlt(hdc, -10, -10, x + 20, y + 20, hdc, 0, 0, x, y, MERGEPAINT);
        StretchBlt(hdc, x, 0, -x, y, hdc, 0, 0, x, y, PATINVERT);
        StretchBlt(hdc, x, 0, -x, y, hdc, 0, 0, x, y, SRCAND);
        if ((XOR_RAND() % 16) == 3) {
            CLEARSCREEN();
        }
        DeleteObject(brush);
    }
}
DWORD WINAPI gdi2(LPVOID lpvd) {
    int x = X, y = Y;
    int signX = 0;
    int signY = 0;
    int inc = 100;
    int dirX = 1;
    int dirY = 1;
    int size = x * y;
    int r = 0;
    HDC hdc = MAKEHDC();
    while (1) {
        r++;
        int w = X, h = Y;
        int x = w, y = h;
        signX += inc * dirX;
        signY += inc * dirY;
        if (signX > w) {
            dirX = -1;
        }
        else {
            if (signX < 0) {
                dirX = 1;
            }
        }
        if (signY > h) {
            dirY = -1;
        }
        else {
            if (signY < 0) {
                dirY = 1;
            }
        }
        HDC hdc = MAKEHDC();
        HDC c = MAKEHDC();
        HICON warning = LoadIcon(0, IDI_WARNING);
        HICON error = LoadIcon(0, IDI_ERROR);
        HICON info = LoadIcon(0, IDI_INFORMATION);
        HICON app = LoadIcon(0, IDI_APPLICATION);
        HICON shield = LoadIcon(0, IDI_SHIELD);
        for (int i = 0; i < 2500; i += 200) {
            HBRUSH brush = CreateSolidBrush(RANDRGB(128));
            SelectObject(hdc, brush);
            HRGN hrgn = CreateEllipticRgn(w / 2 - i / 2, h / 2 - i / 2, w / 2 + i / 2, h / 2 + i / 2);
            SelectObject(hdc, hrgn);
            BitBlt(hdc, w / 2 - i / 2, h / 2 - i / 2, i, i, hdc, w / 2 - i / 2, h / 2 - i / 2, PATINVERT);
            DeleteObject(brush);
            DeleteObject(hrgn);
        }
        for (int ñ = 0; ñ < 32; ñ++) {
            int _x = sin(ñ * TAU / 7 * 3 + r) * ñ * 8.5f;
            int _y = cos(ñ * TAU / 7 * 3 + r) * ñ * 8.5f;
            int X_ = signX + _x, Y_ = signY + _y;
            int X_2 = signX - _y, Y_2 = signY - _x;
            if ((ICONS_OR_CIRCLES_IN_PAYLOAD_2 & 1) == 0) {
                DrawIcon(c, X_, Y_, info);
                DrawIcon(c, X_2, Y_2, shield);
            }
            else {
                HBRUSH CIBRUSH = CreateSolidBrush(RANDRGB(255));
                SelectObject(hdc, CIBRUSH);
                Ellipse(hdc, X_ - 16, Y_ - 16, X_ + 16, Y_ + 16);
                Ellipse(hdc, X_2 - 16, Y_2 - 16, X_2 + 16, Y_2 + 16);
                DeleteObject(CIBRUSH);
            }
            BitBlt(c, X_ - _x / 2, Y_ - _y / 2, 32, 32, c, X_ - _x / 2, Y_ - _y / 2, NOTSRCCOPY);
        }
        CLEARSCREEN();
    }
}
DWORD WINAPI gdi3(LPVOID lpvd) {
    HDC hdc = MAKEDC();
    int w = X, h = Y,x=w,y=h;
    int size = w * h;
    int z = 0;
    int intv = 60;
    while (1) {
        if (1) {
            z+=w+1;
            //Prepare the pixels
            PRGBTRIPLE rgb;
            HDC hdc = GetDC(0);
            HDC mdc = CreateCompatibleDC(hdc);
            BITMAPINFO bmi = { 40, x, y, 1, 24 };
            HBITMAP bitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&rgb, 0, 0);

            //Read the pixels
            SelectObject(mdc, bitmap);
            BitBlt(mdc, 0, 0, x, y, hdc, 0, 0, SRCCOPY);
            //Write the pixels
            for (int i = 0; i < size; i++) {
                int t = i;
                rgb[(i + z) % size].rgbtGreen = t * 16 / 15;
                rgb[(i + z) % size].rgbtBlue = t / w * 16 / 15;
            }

            BitBlt(hdc, 0, 0, x, y, mdc, 0, 0, SRCCOPY);
            //Delete objects so the program won't use more and more memory
            ReleaseDC(0, hdc);
            DeleteObject(bitmap);
            DeleteObject(rgb);
            DeleteDC(hdc);
            DeleteDC(mdc);
        }
        for (int i = 0; i < 2500 + ((z / (w + 1) % 200)); i += 200 + (z / (w + 1) % 200)) {
            HBRUSH brush = CreateSolidBrush(RANDRGB(128));
            SelectObject(hdc, brush);
            HRGN hrgn = CreateEllipticRgn(w / 2 - i / 2, h / 2 - i / 2, w / 2 + i / 2, h / 2 + i / 2);
            SelectObject(hdc, hrgn);
            BitBlt(hdc, w / 2 - i / 2, h / 2 - i / 2, i, i, hdc, w / 2 - i / 2, h / 2 - i / 2, PATINVERT);
            DeleteObject(brush);
            DeleteObject(hrgn);
        }
    }
}
DWORD WINAPI gdi4(LPVOID lpvd) {
    HDC hdc = MAKEDC();
    int w = X, h = Y, x = w, y = h;
    INT z = 0;
    while (1) {
        z++;
        int size = x * y;
        DWORD* pixels = (DWORD*)VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (1) {
            //Prepare the pixels
            PRGBTRIPLE rgb;
            HDC hdc = GetDC(0);
            HDC mdc = CreateCompatibleDC(hdc);
            BITMAPINFO bmi = { 40, x, y, 1, 24 };
            HBITMAP bitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&rgb, 0, 0);

            //Read the pixels
            SelectObject(mdc, bitmap);
            BitBlt(mdc, 0, 0, x, y, hdc, 0, 0, SRCCOPY);

            //Write the pixels
            for (int i = 0; i < size; i++) {
                int t = i;
                rgb[i].rgbtGreen = (t ^ t >> 12) + z;
                rgb[i].rgbtBlue = (t | t >> 12) + z;
                rgb[i].rgbtRed |= (t & t >> 12) + z;
            }

            BitBlt(hdc, 0, 0, x, y, mdc, 0, 0, SRCCOPY);

            //Delete objects so the program won't use more and more memory
            ReleaseDC(0, hdc);
            DeleteObject(bitmap);
            DeleteObject(rgb);
            DeleteDC(hdc);
            DeleteDC(mdc);
            hdc = MAKEDC();
        }
    }
}
DWORD WINAPI gdi5(LPVOID lpvd) {
    HDC hdc = MAKEDC();
    int w = X, h = Y, x = w, y = h;
    INT z = 0;
    while (1) {
        z++;
        int size = x * y;
        DWORD* pixels = (DWORD*)VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (1) {
            //Prepare the pixels
            PRGBTRIPLE rgb;
            HDC hdc = GetDC(0);
            HDC mdc = CreateCompatibleDC(hdc);
            BITMAPINFO bmi = { 40, x, y, 1, 24 };
            HBITMAP bitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&rgb, 0, 0);

            //Read the pixels
            SelectObject(mdc, bitmap);
            BitBlt(mdc, 0, 0, x, y, hdc, 0, 0, SRCCOPY);

            //Write the pixels
            for (int i = 0; i < size; i++) {
                int t = i;
                rgb[(i | z) % size].rgbtRed |= rgb[i & (z % size)].rgbtRed;
                rgb[(i | z) % size].rgbtGreen |= rgb[i & (z % size)].rgbtGreen;
                rgb[(i | z) % size].rgbtBlue |= rgb[i & (z % size)].rgbtBlue;
                rgb[(i | z) % size].rgbtRed %= rgb[i & (z % size)].rgbtRed | 1;
                rgb[(i | z) % size].rgbtGreen %= rgb[i & (z % size)].rgbtGreen | 1;
                rgb[(i | z) % size].rgbtBlue %= rgb[i & (z % size)].rgbtBlue | 1;
                rgb[i].rgbtBlue += (int)((i ^ i >> 12) % 256 / 128.f * z);
                rgb[i].rgbtGreen += (int)((i ^ i >> 12) % 256 / 256.f * z);
                rgb[i].rgbtRed ^= (int)((i ^ i >> 12) % 256 / 512.f * z);
            }

            BitBlt(hdc, 0, 0, x, y, mdc, 0, 0, SRCCOPY);

            //Delete objects so the program won't use more and more memory
            ReleaseDC(0, hdc);
            DeleteObject(bitmap);
            DeleteObject(rgb);
            DeleteDC(hdc);
            DeleteDC(mdc);
            hdc = MAKEDC();
            if ((XOR_RAND() % 16) == 3) {
                CLEARSCREEN();
            }
        }
    }
}
DWORD WINAPI gdi6(LPVOID lpvd) {
    LPCWSTR text = L"x000tr8192";
    int vX = 72;
    int vY = 16;
    int w = X, h = Y;
    HDC hdc = MAKEDC();
    int z = 0;
    int signX = 0;
    int signY = 0;
    int inc = 10;
    int dirX = 1;
    int dirY = 1;
    while (1) {
        signX += inc * dirX;
        signY += inc * dirY;
        if (signX > w) {
            dirX = -1;
        }
        else {
            if (signX < 0) {
                dirX = 1;
            }
        }
        if (signY > h) {
            dirY = -1;
        }
        else {
            if (signY < 0) {
                dirY = 1;
            }
        }
        HBRUSH b = CreateSolidBrush(RANDRGB(XOR_RAND() % 255));
        SelectObject(hdc, b);
        poly(7, 100, signX, signY, PATINVERT, z, 3);
        DeleteObject(b);
        SetBkColor(hdc, RGB(0, 0, 0));
        SetTextColor(hdc, RANDRGB(256));
        for (int x = 0; x < (w / vX + 1); x++) {
            for (int y = 0; y < (h / vY + 1); y++) {
                TextOutW(hdc, x * vX, y * vY, text, wcslen(text));
            }
        }
        z += dirX * dirY;
        POINT curPOS;
        GetCursorPos(&curPOS);
        POINT p = { signX + (inc * dirX), signY + (inc * dirY)};
        POINT lin[2] = { curPOS, p };
        HPEN brush = CreatePen(PS_SOLID, 5, RANDRGB(XOR_RAND() % 255));
        SelectObject(hdc, brush);
        Polygon(hdc, lin, 2);
        DeleteObject(brush);
    }
}
DWORD WINAPI gdi7(LPVOID lpvd) {
    LPCWSTR text1 = L"Windows could not start because the following file is missing or corrupt:";
    LPCWSTR text2 = L"<Windows Root>\\System32\\x000tr8192.sys";
    LPCWSTR text3 = L"Please reinstall a copy of the above file.";
    LPCWSTR text4 = L"?" + (XOR_RAND() % 512);
    LPCWSTR text5 = L"5" + (XOR_RAND() % 512);
    LPCWSTR text6 = L"G" + (XOR_RAND() % 512);
    LPCWSTR text7 = L"V" + (XOR_RAND() % 512);
    int vX = 14;
    int vY = 32;
    int w = X, h = Y;
    HDC hdc = MAKEDC();
    int z = 0;
    while (1) {
        text4 = L"G" + (XOR_RAND() % (rand() | 1) & 127);
        text5 = L"5" + (XOR_RAND() % ((rand() ^ vX) | 1) & 127);
        text6 = L"G" + (XOR_RAND() % ((rand() ^ vY) | 1) & 127);
        text7 = L"V" + (XOR_RAND() % ((rand() ^ XOR_RAND() % 512) | 1) & 127);
        LPCWSTR texts[] = { text1,text2,text3,text4,text5,text6,text7, L""};
        SetBkColor(hdc, RGB(0, 0, 0));
        SetTextColor(hdc, RGB(255,255,255));
        for (int y = 0; y < (h / vY + 1); y++) {
            int i = y;
            if (i > 7) {
                i = 7;
            }
            LPCWSTR text = texts[i];
            LOGFONTW lFont = { 0 };

            //Setup our font style
            lFont.lfWidth = vX;
            lFont.lfHeight = vY;
            lFont.lfOrientation = 0;
            lFont.lfWeight = 400;
            lFont.lfUnderline = FALSE;
            lFont.lfQuality = DRAFT_QUALITY;
            lFont.lfPitchAndFamily = DEFAULT_PITCH | FF_ROMAN;

            lstrcpy(lFont.lfFaceName, L"Tahoma");
            HFONT font = CreateFontIndirectW(&lFont);
            SelectObject(hdc, font);
            TextOutW(hdc, 0, y * vY, text, wcslen(text));
            DeleteObject(font);
        }
        BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, BLACKNESS);
        for (int y = 0; y < (h / vY + 1); y++) {
            int i = y;
            if (i > 7) {
                i = 7;
            }
            LPCWSTR text = texts[min(i,7)];
            LOGFONTW lFont = { 0 };

            //Setup our font style
            lFont.lfWidth = vX;
            lFont.lfHeight = vY;
            lFont.lfOrientation = 0;
            lFont.lfWeight = 400;
            lFont.lfUnderline = FALSE;
            lFont.lfQuality = DRAFT_QUALITY;
            lFont.lfPitchAndFamily = DEFAULT_PITCH | FF_ROMAN;

            lstrcpy(lFont.lfFaceName, L"Tahoma");
            HFONT font = CreateFontIndirectW(&lFont);
            SelectObject(hdc, font);
            TextOutW(hdc, 0, y * vY, text, wcslen(text));
            DeleteObject(font);
        }
    }
}
DWORD WINAPI gdi8(LPVOID lpvd) {
    HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
    int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
    BITMAPINFO bmi = { 40, sw, sh, 1, 24 };
    PRGBTRIPLE rgbtriple;
    while (true) {
        if (true) {
            desk = GetDC(0);
            HDC deskMem = CreateCompatibleDC(desk);
            HBITMAP scr = CreateDIBSection(desk, &bmi, 0, (void**)&rgbtriple, 0, 0);
            SelectObject(deskMem, scr);
            BitBlt(deskMem, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);
            for (int i = 0; i < sw * sh; i++) {
                rgbtriple[i].rgbtGreen ^= rand() % 255;
                rgbtriple[i].rgbtBlue ^= rand() % 255;
                rgbtriple[i].rgbtRed ^= rand() % 255;
                rgbtriple[i].rgbtBlue ^= rgbtriple[i].rgbtGreen;
                rgbtriple[i].rgbtGreen ^= rgbtriple[i].rgbtRed;
            }
            BitBlt(desk, 0, 0, sw, sh, deskMem, 0, 0, SRCCOPY);
            ReleaseDC(wnd, desk);
            DeleteDC(desk); DeleteDC(deskMem); DeleteObject(scr); DeleteObject(wnd); DeleteObject(rgbtriple); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&bmi);
        }
    }
}
DWORD WINAPI countdown(LPVOID lpvd) {
    int secondspass = 0;
    while (1) {
        HDC hdc = MAKEDC();
        LPCWSTR texts[] = {L"10",L"9",L"8",L"7",L"6",L"5",L"4",L"3",L"2",L"1",L"0"};
        for (int i = 0; i < 5; i++) {
            TextOutW(hdc, X / 2, 500, texts[secondspass], wcslen(texts[secondspass]));
            Sleep(200);
        }
        secondspass++;
        CLEARSCREEN();
        if (secondspass > 9) {
            secondspass = 9;
        }
    }
}
DWORD WINAPI errors(LPVOID lpvd) {
    while (1) {
        int message3 = MessageBoxW(NULL,L"you have 10 seconds to close this program. click cancel to close this program, and click retry to ignore this last warning.",L"x000tr8192", MB_RETRYCANCEL | MB_ICONERROR);
        switch (message3)

        {
        case IDCANCEL:
        {
            exit(0);
        }
        }
    }
}
bool _countdown_enable = true;
int main()
{
    INT argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(),&argc);
    if (argc > 1) {
        if (!lstrcmpW(argv[1], L"/nocountdown")) {
            _countdown_enable = false;
        }
    }
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);
    int message = MessageBoxW(NULL, L"YOUR FIRST WARNING. This is x000tr8192 VAR 1. It is a GDI malware that has loud noises and flashing lights! If you have epilepsy, or hate loud noises and flashing lights, JUST DON'T RUN THIS, OR DO NOT LOOK AT IT!! ChrisRM380 will NOT be responsible of any damage, it's YOUR responsibility.", L"WARNING!", MB_YESNO | MB_ICONWARNING);
    switch (message)

    {
    case IDNO:
    {
        exit(0);
    }
    }
    int message2 = MessageBoxW(NULL, L"!>!: SECOND WARNING :!<! This is your second chance to refrain from running this program. It may HARM THE COMPUTER YOU ARE IN, OR MAKE YOU HAVE EPILEPSY ATTACKS AND/OR TINNITUS IF IN HIGH VOLUME!!! If you click 'yes', you have let a malware attack the computer.", L"& !! SECOND WARNING !! &", MB_YESNO | MB_ICONWARNING);
    switch (message2)

    {
    case IDNO:
    {
        exit(0);
    }
    }
    int message3 = MessageBoxW(NULL,L"LAST WARNING!!! YOUR LAST CHANCE TO REFRAIN FROM RUNNING THIS PROGRAM!! YOU MIGHT GET EPILEPSY ATTACKS AND/OR TINNITUS!! I am NOT responsible for the damages. -ChrisRM_380",L"x000tr8192_1",MB_YESNO | MB_ICONERROR);
    switch (message3)

    {
    case IDNO:
    {
        exit(0);
    }
    }
    if (_countdown_enable) {
        HANDLE cf = THREAD(countdown);
        HANDLE vv = THREAD(errors);
        Sleep(10000);
        TERMINATE(cf);
        TERMINATE(vv);
    }
    HANDLE /*c,*/b, g;
    HANDLE C = THREAD(drawcursors);
    HANDLE E = THREAD(errorsines);
    Sleep(_BYTEBEAT_SECS * 100);
    //c = THREAD(possibleclearing);
    b = THREAD(bytebeat1);
    g = THREAD(gdi1);
    Sleep(_BYTEBEAT_SECS * 1000);
    TERMINATE(g);
    b = THREAD(bytebeat2);
    g = THREAD(gdi2);
    Sleep(_BYTEBEAT_SECS * 1000);
    TERMINATE(g);
    b = THREAD(bytebeat3);
    g = THREAD(gdi3);
    Sleep(_BYTEBEAT_SECS * 1000);
    TERMINATE(g);
    b = THREAD(bytebeat4);
    g = THREAD(gdi4);
    Sleep(_BYTEBEAT_SECS * 1000);
    TERMINATE(g);
    b = THREAD(bytebeat5);
    g = THREAD(gdi5);
    Sleep(_BYTEBEAT_SECS * 1000);
    TERMINATE(g);
    b = THREAD(bytebeat6);
    g = THREAD(gdi6);
    Sleep(_BYTEBEAT_SECS * 1000);
    TERMINATE(g);
    b = THREAD(bytebeat7);
    g = THREAD(gdi7);
    Sleep(_BYTEBEAT_SECS * 1000);
    TERMINATE(g);
    b = THREAD(bytebeat8);
    g = THREAD(gdi8);
    Sleep(_BYTEBEAT_SECS * 1000);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
